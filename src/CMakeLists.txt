project(Checkers LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message("--- Configuring Qt.")
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

message("--- Adding targets.")
add_library( domain )
add_executable( Checkers main.cpp )
set( Checkers_libs "Qt${QT_VERSION_MAJOR}::Widgets" )
target_link_libraries(Checkers PUBLIC domain PRIVATE ${Checkers_libs})

message("--- Configuring Google Test")
#include(GoogleTest) #Not sure this is actually usefull
find_package(GTest REQUIRED)
set( UNIT_TESTS_EXECUTABLE "UnitTests" )
include_directories( ${GTEST_INCLUDE_DIRS} )
add_executable( ${UNIT_TESTS_EXECUTABLE} unit_test_main.cpp)
target_link_libraries( ${UNIT_TESTS_EXECUTABLE} PRIVATE ${Checkers_libs} ${GTEST_BOTH_LIBRARIES})
#gtest_discover_tests()

message("--- Processing subdirectories.")
#sources are added to the target in the subfolders
add_subdirectory( application )
add_subdirectory( communication )
add_subdirectory( domain )
add_subdirectory( frontend )




