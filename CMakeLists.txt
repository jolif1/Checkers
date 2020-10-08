cmake_minimum_required(VERSION 3.5)

project(Checkers LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message("--- Configuring Qt.") #TODO: move this out of main cmakelists ? -> frontend/gui
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

message("--- Adding targets.")
add_library( domain )
add_executable( Checkers main.cpp )
target_link_libraries(Checkers PUBLIC domain PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

message("--- Processing subdirectories.")
#sources are added to the target in the subfolders
add_subdirectory( frontend )
add_subdirectory( domain )
add_subdirectory( application )


