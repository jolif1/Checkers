set( SRCS
        "${CMAKE_CURRENT_SOURCE_DIR}/LocalAdapter.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/LocalAdapter.cpp")

target_sources( Checkers PUBLIC ${SRCS} )
target_sources( ${UNIT_TESTS_EXECUTABLE} PRIVATE ${SRCS} )
