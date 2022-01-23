cmake_minimum_required(VERSION 3.10)

project(QTui)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5Widgets)

file(GLOB QTui_SRC CONFIGURE_DEPENDS "*.hpp" "*.cpp")

add_executable(QTui ${QTui_SRC})

target_include_directories(QTui PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}")
target_link_libraries(QTui Qt5::Widgets)