cmake_minimum_required(VERSION 3.10)
project(TheDeadWoods VERSION 1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include(FindPkgConfig REQUIRED)
pkg_search_module(GLEW REQUIRED glew)

include_directories(include)
include_directories(extern)
include_directories(extern/glm)
include_directories(extern/glfw/include)

add_subdirectory(test)
add_subdirectory(extern/glfw)
add_subdirectory(extern/glm/)

find_file(ASSIMP libassimp.so ${CMAKE_SOURCE_DIR}/libs/)
if (NOT ASSIMP)
    message(SEND_ERROR "assimp not found")
endif ()

set(ENGINE_CODES
        src/engine/camera.cpp
        include/engine/graphics/camera.hpp

        src/engine/shader.cpp
        include/engine/graphics/shader.hpp

        src/engine/texture.cpp
        include/engine/graphics/texture.hpp

        src/engine/model.cpp
        include/engine/graphics/model.hpp

        src/engine/vertex.cpp
        include/engine/vertex.hpp

        src/engine/vector3.cpp
        include/engine/vector3.hpp

        src/engine/vector2.cpp
        include/engine/vector2.hpp

        src/engine/mesh.cpp
        include/engine/graphics/mesh.hpp

        src/engine/sewindow.cpp
        include/engine/graphics/sewindow.hpp

        src/engine/materials/material.cpp

        include/engine/materials/material.hpp
        include/engine/config.hpp

        include/engine/util/glslparser/parser.cpp
        include/engine/util/glslparser/parser.hpp

        src/engine/materials/sunmaterial.cpp
        include/engine/materials/sunmaterial.hpp

        src/engine/materials/flashmaterial.cpp
        include/engine/materials/flashmaterial.hpp

        src/engine/materials/areamaterial.cpp
        include/engine/materials/areamaterial.hpp
        
        include/engine/materials.hpp
        include/engine.hpp
        
        include/engine/transform.hpp
        
        include/engine/util/Logger/logger.cpp 
        include/engine/util/Logger/logger.hpp include/util.hpp)

set(RESOURCES "${CMAKE_SOURCE_DIR}/resources")

configure_file(${CMAKE_SOURCE_DIR}/include/config.hpp.in ${CMAKE_SOURCE_DIR}/include/engine/config.hpp)


add_library(Engine SHARED ${ENGINE_CODES})
target_link_libraries(Engine PUBLIC ${GLEW_LIBRARIES} glfw ${ASSIMP})


add_executable(TheDeadWoods app/main.cpp)
target_link_libraries(TheDeadWoods PRIVATE Engine)


