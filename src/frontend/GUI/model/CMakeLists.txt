set( SRCS
     "${CMAKE_CURRENT_SOURCE_DIR}/ViewModel.h"
     "${CMAKE_CURRENT_SOURCE_DIR}/ViewModel.cpp")

target_sources( ${MAIN_EXECUTABLE} PUBLIC ${SRCS} )
target_sources( ${UNIT_TESTS_EXECUTABLE} PRIVATE ${SRCS} )

