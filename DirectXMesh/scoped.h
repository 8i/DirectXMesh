//-------------------------------------------------------------------------------------
// scoped.h
//  
// Utility header with helper classes for exception-safe handling of resources
//
// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//-------------------------------------------------------------------------------------

#pragma once

#include <assert.h>
#include <memory>
#include <malloc.h>

#ifndef WIN32
#include <stdlib.h>
#define _aligned_free(ptr) free(ptr)
#define _aligned_malloc(size, alignment) aligned_alloc(alignment, size)
#endif
//---------------------------------------------------------------------------------
struct aligned_deleter { void operator()(void* p) { _aligned_free(p); } };

typedef std::unique_ptr<float[], aligned_deleter> ScopedAlignedArrayFloat;

typedef std::unique_ptr<DirectX::XMVECTOR[], aligned_deleter> ScopedAlignedArrayXMVECTOR;

//---------------------------------------------------------------------------------
#ifdef WIN32
struct handle_closer { void operator()(HANDLE h) { assert(h != INVALID_HANDLE_VALUE); if (h) CloseHandle(h); } };
#else
//TODO[KV]:Think about this more
struct handle_closer { void operator()(HANDLE h) { assert(h != INVALID_HANDLE_VALUE); } };
#endif
typedef std::unique_ptr<void, handle_closer> ScopedHandle;

inline HANDLE safe_handle(HANDLE h) { return (h == INVALID_HANDLE_VALUE) ? nullptr : h; }
