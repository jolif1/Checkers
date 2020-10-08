target_sources( Checkers PRIVATE
                "${CMAKE_CURRENT_SOURCE_DIR}/Board.h"
                "${CMAKE_CURRENT_SOURCE_DIR}/Board.cpp"
                "${CMAKE_CURRENT_SOURCE_DIR}/BoardCellDelegate.h"
                "${CMAKE_CURRENT_SOURCE_DIR}/BoardCellDelegate.cpp" )

#So that the UI file can directly include "Board.h" and not "frontend/GUI/ui/Board/Board.h"
target_include_directories( Checkers PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}" )
