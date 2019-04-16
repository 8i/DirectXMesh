cmake_minimum_required (VERSION 3.13.1)

project(DirectXMesh)

set(CMAKE_DEBUG_POSTFIX d)
add_definitions(-D_UNICODE -DUNICODE)

#These compiler settings are set for all targets that are added for included in this file.
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

include_directories(${CMAKE_CURRENT_LIST_DIR})

set (DX_MESH_SRC
    ${CMAKE_CURRENT_LIST_DIR}/DirectXMeshWeldVertices.cpp
    ${CMAKE_CURRENT_LIST_DIR}/DirectXMeshAdjacency.cpp
    ${CMAKE_CURRENT_LIST_DIR}/DirectXMeshClean.cpp
    ${CMAKE_CURRENT_LIST_DIR}/DirectXMeshGSAdjacency.cpp
    ${CMAKE_CURRENT_LIST_DIR}/DirectXMeshNormals.cpp
    ${CMAKE_CURRENT_LIST_DIR}/DirectXMeshOptimize.cpp
    ${CMAKE_CURRENT_LIST_DIR}/DirectXMeshOptimizeLRU.cpp
    ${CMAKE_CURRENT_LIST_DIR}/DirectXMeshOptimizeTVC.cpp
    ${CMAKE_CURRENT_LIST_DIR}/DirectXMeshRemap.cpp
    ${CMAKE_CURRENT_LIST_DIR}/DirectXMeshTangentFrame.cpp
    ${CMAKE_CURRENT_LIST_DIR}/DirectXMeshUtil.cpp
    ${CMAKE_CURRENT_LIST_DIR}/DirectXMeshValidate.cpp
    )
	
set (DX_MESH_HDR
    ${CMAKE_CURRENT_LIST_DIR}/JntLinuxTypes.h
    ${CMAKE_CURRENT_LIST_DIR}/DirectXMesh.h
    ${CMAKE_CURRENT_LIST_DIR}/DirectXMeshP.h
    ${CMAKE_CURRENT_LIST_DIR}/DirectXMesh.inl
    ${CMAKE_CURRENT_LIST_DIR}/scoped.h
    )

add_library(DirectXMesh STATIC ${DX_MESH_SRC} ${DX_MESH_HDR})
set_target_properties(DirectXMesh PROPERTIES
                      COMPILE_PDB_NAME "DirectXMesh"
                      COMPILE_PDB_NAME_DEBUG "DirectXMesh${CMAKE_DEBUG_POSTFIX}"
                      )
