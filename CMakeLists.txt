cmake_minimum_required (VERSION 3.13.1)

set(CMAKE_DEBUG_POSTFIX d)

if (WIN32)
#Configure compile flags to match VS sln
set(CXX_COMMON_FLAGS "/MP /fp:fast /sdl /permissive- /Zc:__cplusplus")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${CXX_COMMON_FLAGS}")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} ${CXX_COMMON_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${CXX_COMMON_FLAGS}")

add_definitions(-D_UNICODE -DUNICODE)
endif()

if(WIN32)
    add_subdirectory(DirectXMesh)
endif()
