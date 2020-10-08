#include "BoardCellDelegate.h"

#include <QPainter>
#include <QDebug>

namespace frontend::gui
{
    BoardCellDelegate::BoardCellDelegate()
    {
        mWhiteChecker = std::make_shared<QPixmap>(":/frontend/GUI/ui/CheckerDelegate/Nikita_Gobulev_white.png");
        mBlackChecker = std::make_shared<QPixmap>(":/frontend/GUI/ui/CheckerDelegate/Nikita_Gobulev_brown.png");
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
            auto lColor = lCheckerColor.value<QColor>();

            if( Qt::white == lColor.value() )
                painter->drawPixmap( option.rect, *mWhiteChecker );
            if( Qt::black == lColor.value() )
                painter->drawPixmap( option.rect, *mBlackChecker );
        }
    }

    QSize BoardCellDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        return QSize( 64, 64 );
    }
}
