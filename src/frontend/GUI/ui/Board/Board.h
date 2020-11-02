#pragma once

#include <QTableView>
#include "BoardCellDelegate.h"

namespace frontend::gui
{
    class Board : public QTableView
    {
    public:
        Board( QWidget* pParent = nullptr );


        void resizeEvent(QResizeEvent* pEvent) override;

    private:
        std::shared_ptr<BoardCellDelegate> mCellDelegate;
    };
}
