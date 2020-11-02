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

    void Board::resizeEvent(QResizeEvent* pEvent)
    {
        auto lMinParam = std::min( pEvent->size().width(), pEvent->size().height() );

        this->resize( lMinParam, lMinParam );
        QTableView::resizeEvent( pEvent ); //necessary to properly resize columns
    }
}
