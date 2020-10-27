#include "BoardCellDelegate.h"

#include <domain/Board.h>
#include <QPainter>
#include <QDebug>

namespace frontend::gui
{
    BoardCellDelegate::BoardCellDelegate()
    {
        mWhiteChecker = std::make_shared<QPixmap>(":/ui/Board/Nikita_Gobulev_white.png");
        mBlackChecker = std::make_shared<QPixmap>(":/ui/Board/Nikita_Gobulev_brown.png");
        /*TODO: unit-test pixmaps validity */

        if( domain::Board::kTopLeftCellColor == domain::CellColor::White )
        {
            mPairCellBrush = QBrush( Qt::lightGray );
            mOddCellBrush = QBrush( Qt::darkBlue );
        }
        else
        {
            mPairCellBrush = QBrush( Qt::darkBlue );
            mOddCellBrush = QBrush( Qt::lightGray );
        }
    }

    void BoardCellDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        auto    lCheckerColor  { index.data( Qt::DisplayRole ) };
        bool    lCellIndexPair { ( index.row() + index.column() ) % 2 == 0 }; /* 0 means top-left aligned cell */
        QBrush  lCellBrush     { lCellIndexPair ? mPairCellBrush : mOddCellBrush };


        // paint the background
        if( ( option.state & QStyle::State_Selected ) && !lCellIndexPair )
        {
            lCellBrush.setColor( lCellBrush.color().lighter() );
        }

        painter->fillRect( option.rect, lCellBrush );

        // paint the checker, if any is present.
        if( lCheckerColor.isValid() )
        {
            auto    lColor      { lCheckerColor.toInt() };
            QPixmap lImageToDraw;

            /* TODO:: unit test cast of QVariant to QColor --> pbbly Viewmodel */
            if( Qt::white == lColor )
                lImageToDraw = mWhiteChecker->scaled(50, 50);
            if( Qt::black == lColor )
                lImageToDraw = mBlackChecker->scaled(50, 50);

            painter->drawPixmap( option.rect, lImageToDraw );
        }
    }

    QSize BoardCellDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        return QSize( 50, 50 );
    }
}
