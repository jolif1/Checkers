set( SRCS
     "${CMAKE_CURRENT_SOURCE_DIR}/IFrontend.h"
     "${CMAKE_CURRENT_SOURCE_DIR}/IFrontend.cpp" )

target_sources( Checkers PUBLIC ${SRCS} )
target_sources( ${UNIT_TESTS_EXECUTABLE} PRIVATE ${SRCS} )

add_subdirectory(adapters)
add_subdirectory(GUI)
