#pragma once

#include <QAbstractItemDelegate>

namespace frontend::gui
{
    class BoardCellDelegate : public QAbstractItemDelegate
    {
    public:
        BoardCellDelegate();
        ~BoardCellDelegate() = default;

        void    paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
        QSize   sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    private:
        std::shared_ptr<QPixmap> mWhiteChecker;
        std::shared_ptr<QPixmap> mBlackChecker;
    };
}
