message("--- Configuring Google Test")
#include(GoogleTest) #Not sure this is actually usefull
find_package(GTest REQUIRED)
message("---- Found Google Test in folder ${GTEST_ROOT}")
message("---- Found Google Test includes in folder ${GTEST_INCLUDE_DIRS}")
target_include_directories( ${UNIT_TESTS_EXECUTABLE} PRIVATE ${GTEST_INCLUDE_DIRS} )

#somehow GTest doesn't include link targets for GMock yet. I don't want to pull the code from CMake either.
target_sources( ${UNIT_TESTS_EXECUTABLE} PUBLIC unit_test_main.cpp )
target_link_directories( ${UNIT_TESTS_EXECUTABLE} PUBLIC "${GTEST_ROOT}/lib" )
target_link_libraries( ${UNIT_TESTS_EXECUTABLE} PUBLIC gtest gtest_main gmock gmock_main pthread)

message("--- Iterating frontend tests")
add_subdirectory(frontend)
message("--- Iterating domain tests")
add_subdirectory(domain)
message("--- Iterating application tests")
add_subdirectory(application)

