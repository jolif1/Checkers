#pragma once

#include <QAbstractTableModel>
#include <QItemSelectionModel>
#include <domain/Checker.h>
#include <map>

namespace frontend::gui
{
    class ViewModel : public QAbstractTableModel
    {
        Q_OBJECT

    public:
        /**
         * @brief setSelectionModel
         * @param pSelectionModel
         */
        ///@{
        void setSelectionModel( QItemSelectionModel* pSelectionModel );
        ///@}

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

    signals:
        void requestMove( const domain::CheckerPtr& pChecker, const domain::Position& pNewPos );
        void requestPossibleMoves( const domain::Position& pCheckerPos );

    private:
        domain::IndexedCheckers mCheckers;
        QItemSelectionModel*    mSelectionModel;

        void onItemSelectionChanged( const QModelIndex& current, const QModelIndex& previous );
    };
}
