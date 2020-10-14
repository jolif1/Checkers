target_sources( ${UNIT_TESTS_EXECUTABLE} PUBLIC
                IFrontendMock.h )

add_subdirectory(adapters)
add_subdirectory(GUI)
