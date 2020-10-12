#include "Board.h"

namespace frontend::gui
{
    Board::Board( QWidget* pParent ) :
        QTableView      { pParent },
        mCellDelegate   { std::make_shared<BoardCellDelegate>() }
    {
        this->setItemDelegate( mCellDelegate.get() );
    }
}
