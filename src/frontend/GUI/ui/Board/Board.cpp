#include "Board.h"

#include <QResizeEvent>
#include <QHeaderView>

namespace frontend::gui
{
    Board::Board( QWidget* pParent ) :
        QTableView      { pParent },
        mCellDelegate   { std::make_shared<BoardCellDelegate>() }
    {
        this->setItemDelegate( mCellDelegate.get() );

        // Have the rows & columns fill the available space equally
        this->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );
        this->verticalHeader()->setSectionResizeMode( QHeaderView::Stretch );
    }
}
