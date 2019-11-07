cmake_minimum_required(VERSION 3.13.1)

project(DirectXMesh)

#These compiler settings are set for all targets that are added for included in this file.
if (WIN32)

    ### KV: Disabling windows compilation through cmake since we are not worrying about supporting this for now

    message(FATAL_ERROR "Windows currently no supported for this library")

    #Configure compile flags to match VS sln
    #set(CXX_COMMON_FLAGS "/MP /fp:fast /sdl /permissive- /Zc:__cplusplus")
    #set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${CXX_COMMON_FLAGS}")
    #set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} ${CXX_COMMON_FLAGS}")
    #set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${CXX_COMMON_FLAGS}")
endif ()

set(DX_MESH_SRC
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

add_library(${PROJECT_NAME} STATIC ${DX_MESH_SRC})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
    )

target_compile_definitions(${PROJECT_NAME}
    PUBLIC
    $<$<CONFIG:Debug>:_DEBUG>
    $<$<PLATFORM_ID:Linux>:__LINUX__>
    UNICODE
    _UNICODE
    )

set_target_properties(DirectXMesh PROPERTIES
    COMPILE_PDB_NAME "DirectXMesh"
    COMPILE_PDB_NAME_DEBUG "DirectXMesh${CMAKE_DEBUG_POSTFIX}"
    POSITION_INDEPENDENT_CODE ON
    )
