#pragma once

namespace domain {

    enum CellColor
    {
        White,
        Black
    };

    class Board
    {
    public:
        static constexpr int kNumberOfRows { 8 };
        static constexpr int kNumberOfColumns { 8 };
        static constexpr int kTopLeftCellColor { CellColor::White };
    };
}
