#include "ViewModel.h"

#include <domain/Board.h>
#include <QBrush>

namespace frontend::gui
{
    using domain::Board;
    using domain::Checker;
    using domain::CheckerPtr;

    ViewModel::ViewModel( const SelectionModelPtr& pSelectionModel ) :
        mSelectionModel( pSelectionModel )
    {

    }

    void ViewModel::addChecker( const CheckerPtr& pPtr )
    {
        beginResetModel();
        mCheckers.insert( { pPtr->getPosition(), pPtr } );
        endResetModel();
    }

    int ViewModel::rowCount( [[maybe_unused]] const QModelIndex &parent ) const
    {
        return Board::kNumberOfRows;
    }

    int ViewModel::columnCount( [[maybe_unused]] const QModelIndex &parent ) const
    {
        return Board::kNumberOfColumns;
    }

    QVariant ViewModel::data( const QModelIndex &index, int role ) const
    {
        QVariant lRet;

        if( index.isValid() )
        {
            int lRow { index.row() };
            int lCol { index.column() };

            if( Qt::DisplayRole == role )
            {
                auto it = mCheckers.find( { lRow, lCol } );

                if( mCheckers.end() != it )
                {
                    if( mCheckers.at( { lRow, lCol } )->getTeam() == Checker::Team::White )
                        lRet = QVariant( QColor( Qt::white ) );
                    else
                        lRet = QVariant::fromValue<int>( Qt::black );
                }
            }
        }

        return lRet;
    }

    QVariant ViewModel::headerData( [[maybe_unused]] int section,[[maybe_unused]] Qt::Orientation orientation, [[maybe_unused]] int role ) const
    {
        return QVariant();
    }

}
