#include "ViewModel.h"

#include <domain/Board.h>
#include <QBrush>

namespace frontend::gui
{
    using domain::Board;
    using domain::Checker;
    using domain::CheckerPtr;
    using domain::Position;

    void ViewModel::setSelectionModel( QItemSelectionModel* pSelectionModel )
    {
        /* TODO: for some reason you can^t create your own SelectionModel & pass it to the board via setSelectionModel.
           --> looks like the board doesn't really change its selection model (currentChanged is never triggered on the new model */
        mSelectionModel = pSelectionModel;

        QObject::connect( mSelectionModel, &QItemSelectionModel::currentChanged, this, &ViewModel::onItemSelectionChanged );
    }

    void ViewModel::addChecker( const CheckerPtr& pPtr )
    {
        beginResetModel();
        mCheckers.insert( { pPtr->getPosition(), pPtr } );
        endResetModel();
    }

    void ViewModel::move( const domain::Position& pOldPos, const domain::Position& pNewPos )
    {
        beginResetModel();
        auto it = mCheckers.find( pOldPos );
        Q_ASSERT( mCheckers.end() != it );
        auto lNode = mCheckers.extract( it );
        lNode.key() = pNewPos;
        mCheckers.insert( std::move( lNode ) );
        endResetModel();
    }

    void ViewModel::remove( const domain::Position& pToRemove )
    {
        beginResetModel();
        mCheckers.erase( pToRemove );
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
                        lRet = QVariant::fromValue<int>( Qt::white );
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

    void ViewModel::onItemSelectionChanged( const QModelIndex& current, const QModelIndex& previous )
    {
        Position    lNewPos         { current.row(), current.column() };
        bool        lCheckerMoved   { false };

        if( previous.isValid() )
        {
            //Try to move the Checker, if one is present
            auto lCheckerIt { mCheckers.find( { previous.row(), previous.column() } ) };

            if( mCheckers.end() != lCheckerIt )
            {
                lCheckerMoved = true;
                emit requestMove( lCheckerIt->first, lNewPos );
            }
        }

        if( !lCheckerMoved )
        {
            // Show possible moves for currently selected tile
            auto lCheckerIt { mCheckers.find( lNewPos ) };

            if( mCheckers.end() != lCheckerIt )
            {
                emit requestPossibleMoves( lNewPos );
            }
        }
    }
}
