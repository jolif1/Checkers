set( SRCS
     "${CMAKE_CURRENT_SOURCE_DIR}/ApplicationFactory.h"
     "${CMAKE_CURRENT_SOURCE_DIR}/ApplicationFactory.cpp")

target_sources( ${MAIN_EXECUTABLE} PUBLIC ${SRCS} )
target_sources( ${UNIT_TESTS_EXECUTABLE} PRIVATE ${SRCS} )

add_subdirectory( adapters )
add_subdirectory( core )
