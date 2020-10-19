project(Checkers LANGUAGES CXX)

#########################################################################
#                          CMake & STL specifics                        #
#########################################################################
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#########################################################################
#                             Dependencies.                             #
#########################################################################
message("--- Configuring Qt.")
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

#########################################################################
#                               Targets.                                #
#########################################################################
set( UNIT_TESTS_EXECUTABLE "UnitTests" )
set( MAIN_EXECUTABLE "Checkers" )
set( ${MAIN_EXECUTABLE}_PUBLIC_LIBS "domain" "Qt${QT_VERSION_MAJOR}::Widgets" ) #having a dynamic object name is kinda useless...

message("--- Adding targets.")
add_executable( ${MAIN_EXECUTABLE} main.cpp )
add_executable( ${UNIT_TESTS_EXECUTABLE} )
add_library( domain )

target_link_libraries( ${MAIN_EXECUTABLE} PUBLIC ${${MAIN_EXECUTABLE}_PUBLIC_LIBS} )
target_link_libraries( ${UNIT_TESTS_EXECUTABLE} PUBLIC ${${MAIN_EXECUTABLE}_PUBLIC_LIBS} )


#########################################################################
#                               Sources.                                #
#########################################################################
message("--- Processing subdirectories.")
#sources are added to the target in the subfolders
add_subdirectory( application )
add_subdirectory( communication )
add_subdirectory( domain )
add_subdirectory( frontend )

message("---- Adding unit test target")
#TODO: get rid of the GTest-specific stuff. --> move it to the test subdirectory
include(CTest)
include(GoogleTest)
add_subdirectory( test )
gtest_discover_tests( ${UNIT_TESTS_EXECUTABLE} )
message("d: unit test targets is ${${UNIT_TESTS_EXECUTABLE}_targets}")

