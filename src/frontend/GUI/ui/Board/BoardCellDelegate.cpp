#include "BoardCellDelegate.h"

#include <QPainter>
#include <QDebug>

namespace frontend::gui
{
    BoardCellDelegate::BoardCellDelegate()
    {
        mWhiteChecker = std::make_shared<QPixmap>(":/ui/Board/Nikita_Gobulev_white.png");
        mBlackChecker = std::make_shared<QPixmap>(":/ui/Board/Nikita_Gobulev_brown.png");
        /*TODO: unit-test pixmaps validity */
    }

    void BoardCellDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        auto    lCheckerColor  { index.data( Qt::DisplayRole ) };
        QBrush  lCellBrush     ;
        bool    lIsWhiteCell   { ( index.row() + index.column() ) % 2 == 0 };

        // paint the background
        if( lIsWhiteCell )
            lCellBrush = QBrush( Qt::lightGray );
        else
            lCellBrush = QBrush( Qt::darkBlue );

        if( ( option.state & QStyle::State_Selected ) && lIsWhiteCell )
        {
            lCellBrush.setColor( lCellBrush.color().lighter() );
        }

        painter->fillRect( option.rect, lCellBrush );

        // paint the checker, if any is present.
        if( lCheckerColor.isValid() )
        {
            auto lColor = lCheckerColor.toInt();

            /* TODO:: unit test cast of QVariant to QColor --> pbbly Viewmodel*/

            if( Qt::white == lColor )
                painter->drawPixmap( option.rect, *mWhiteChecker );
            if( Qt::black == lColor )
                painter->drawPixmap( option.rect, *mBlackChecker );
        }
    }

    QSize BoardCellDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        return QSize( 64, 64 );
    }
}
