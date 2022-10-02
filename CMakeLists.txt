cmake_minimum_required(VERSION 3.20)

project("SimpleTex")

list(APPEND CMAKE_PREFIX_PATH "~/Qt/6.4.0/macos")

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui PrintSupport Pdf PdfWidgets)
qt_standard_project_setup()

add_subdirectory(deps/QScintilla-cmake)
add_subdirectory(deps/pdftex-cmake)

file(GLOB SOURCES src/*.cpp src/*.hpp)
add_executable(${PROJECT_NAME} ${SOURCES})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
target_link_libraries(${PROJECT_NAME} PUBLIC QScintilla Qt6::Pdf Qt6::PdfWidgets)

set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
