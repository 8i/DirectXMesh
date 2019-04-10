cmake_minimum_required (VERSION 3.13.1)

project(DirectXMesh)

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
