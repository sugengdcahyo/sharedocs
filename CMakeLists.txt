cmake_minimum_required(VERSION 3.21)

project(MarkdownStudio VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.11.1/mingw_64")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(MarkdownStudio
        src/main.cpp
)

target_link_libraries(MarkdownStudio PRIVATE
        Qt6::Widgets
)