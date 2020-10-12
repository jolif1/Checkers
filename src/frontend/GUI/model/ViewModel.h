#pragma once

#include <QAbstractTableModel>
#include <domain/Checker.h>
#include <map>

namespace frontend::gui
{
    class ViewModel : public QAbstractTableModel
    {
    public:

        void addChecker( const domain::CheckerPtr& pPtr );

        /**
         * @brief QAbstractTableModel functionnality
         */
        ///@{
        int         rowCount( const QModelIndex &parent = QModelIndex() )                               const override;
        int         columnCount( const QModelIndex &parent = QModelIndex() )                            const override;
        QVariant    data( const QModelIndex &index, int role = Qt::DisplayRole )                        const override;
        QVariant    headerData( int section, Qt::Orientation orientation, int role = Qt::DisplayRole )  const override;
        ///@}

    private:
        typedef std::map<domain::Position, domain::CheckerPtr> IndexedCheckers;

        static constexpr int    kRowCount { 10 };
        static constexpr int    kColCount { 10 };

        IndexedCheckers         mCheckers;
    };
}
