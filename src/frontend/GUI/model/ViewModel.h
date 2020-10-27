#pragma once

#include <QAbstractTableModel>
#include <QItemSelectionModel>
#include <domain/Checker.h>
#include <map>

namespace frontend::gui
{
    typedef std::shared_ptr<QItemSelectionModel> SelectionModelPtr;

    class ViewModel : public QAbstractTableModel
    {
    public:
        ViewModel( const SelectionModelPtr& pSelectionModel );

        /**
         * @brief Game related functionnality
         */
        ///@{
        void addChecker( const domain::CheckerPtr& pPtr );
        ///@}

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

        domain::IndexedCheckers mCheckers;
        SelectionModelPtr       mSelectionModel;
    };
}
