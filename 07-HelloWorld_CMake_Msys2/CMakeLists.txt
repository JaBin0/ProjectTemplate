cmake_minimum_required(VERSION 3.5)
project(Project_Template_App
        VERSION 0.0.1
        DESCRIPTION "Project template"
        LANGUAGES CXX)

add_executable($ENV{PROJECT_NAME}
               src/main.cpp)

target_compile_features($ENV{PROJECT_NAME} PRIVATE cxx_std_20)

target_include_directories($ENV{PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)