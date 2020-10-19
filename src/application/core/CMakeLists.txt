set( SRCS
        "${CMAKE_CURRENT_SOURCE_DIR}/Game.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/Game.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/GameObserver.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/GameObserver.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/IGame.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/IGame.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/IPlayer.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/IPlayer.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Lobby.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/Lobby.cpp" )

target_sources( Checkers PUBLIC ${SRCS} )
target_sources( ${UNIT_TESTS_EXECUTABLE} PRIVATE ${SRCS} )
