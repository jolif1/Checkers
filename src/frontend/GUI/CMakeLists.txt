target_sources( Checkers PUBLIC
                "${CMAKE_CURRENT_SOURCE_DIR}/Controller.h"
                "${CMAKE_CURRENT_SOURCE_DIR}/Controller.cpp"
                "${CMAKE_CURRENT_SOURCE_DIR}/GUIFrontendFactory.h"
                "${CMAKE_CURRENT_SOURCE_DIR}/GUIFrontendFactory.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/GuiResources.qrc" )

add_subdirectory( model )
add_subdirectory( ui )
