project(Game2)
cmake_minimum_required(VERSION 2.8)
add_definitions(-std=c++11)
include_directories(
        external/AntTweakBar-1.16/include/
        external/glfw-3.1.2/include/GLFW/
        external/glm-0.9.7.1/
        external/glew-1.13.0/include/
        external/assimp-3.0.1270/include/
        external/bullet-2.81-rev2613/src/

        ${Game2_SOURCE_DIR}/src
)

add_subdirectory(src)
add_subdirectory(external)
aux_source_directory(. SRC_LIST)

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        glfw
        GLEW_1130
)

add_definitions(
        -DTW_STATIC
        -DTW_NO_LIB_PRAGMA
        -DTW_NO_DIRECT3D
        -DGLEW_STATIC
        -D_CRT_SECURE_NO_WARNINGS
)


file(GLOB_RECURSE SRC_LIST
    "src/*.cpp"
    "src/*.h"
)

add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(${PROJECT_NAME}
        ${ALL_LIBS}
)
