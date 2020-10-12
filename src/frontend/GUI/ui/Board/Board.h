#pragma once

#include <QTableView>
#include "BoardCellDelegate.h"

namespace frontend::gui
{
    class Board : public QTableView
    {
    public:
        Board( QWidget* pParent = nullptr );

    private:
        std::shared_ptr<BoardCellDelegate> mCellDelegate;
    };
}
