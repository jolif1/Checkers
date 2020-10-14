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
message("---- Adding local application target")
add_library( domain )
add_executable( Checkers main.cpp )
set( Checkers_libs "PUBLIC" "domain" "PRIVATE" "Qt${QT_VERSION_MAJOR}::Widgets" )
target_link_libraries(Checkers ${Checkers_libs})

message("---- Adding unit test target")
#This is somewhat really GTest-like but its nice not to have to include all sources in test/ folder CMakeLists
#Note that defining the target here & adding/linking sources in subfolders only works with cmake 3.13 & higher
set( UNIT_TESTS_EXECUTABLE "UnitTests" )

add_executable( ${UNIT_TESTS_EXECUTABLE} )
target_link_libraries( ${UNIT_TESTS_EXECUTABLE} PUBLIC ${Checkers_libs})

message("--- Processing subdirectories.")
#sources are added to the target in the subfolders
add_subdirectory( application )
add_subdirectory( communication )
add_subdirectory( domain )
add_subdirectory( frontend )
add_subdirectory( test )




