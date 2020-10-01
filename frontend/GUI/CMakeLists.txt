target_sources( Checkers PUBLIC
                "${CMAKE_CURRENT_SOURCE_DIR}/Controller.h"
                "${CMAKE_CURRENT_SOURCE_DIR}/Controller.cpp"
                "${CMAKE_CURRENT_SOURCE_DIR}/GUIViewFactory.h"
                "${CMAKE_CURRENT_SOURCE_DIR}/GUIViewFactory.cpp" )

add_subdirectory( model )
add_subdirectory( ui )
