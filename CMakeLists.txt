cmake_minimum_required (VERSION 3.13.1)

project(DirectXMesh)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

set(CMAKE_DEBUG_POSTFIX d)

if (WIN32)
    #Configure compile flags to match VS sln
    set(CXX_COMMON_FLAGS "/MP /fp:fast /sdl /permissive- /Zc:__cplusplus")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${CXX_COMMON_FLAGS}")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} ${CXX_COMMON_FLAGS}")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${CXX_COMMON_FLAGS}")
elseif(UNIX)
    set(CXX_COMMON_FLAGS "-std=c++11 -fPIC")
    set(CMAKE_CXX_FLAGS_DEBUG "-g -D_DEBUG ${CXX_COMMON_FLAGS}" CACHE STRING "Debug options" FORCE)
    set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG ${CXX_COMMON_FLAGS}" CACHE STRING "Release options" FORCE)
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELEASE} -g" CACHE STRING "Relwithdebinfo options" FORCE)
    set(CMAKE_C_FLAGS_DEBUG "-g -D_DEBUG" CACHE STRING "Debug options" FORCE)
    set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG" CACHE STRING "Release options" FORCE)
    set(CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELEASE} -g" CACHE STRING "Relwithdebinfo" FORCE)

    add_definitions(-D__LINUX__)
endif()

add_definitions(-D_UNICODE -DUNICODE)

add_subdirectory(DirectXMesh)
