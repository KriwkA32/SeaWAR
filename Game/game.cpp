#include "game.h"
#include "field.h"
#include <cstring>

Game::Game(QObject* parent)
    :QObject(parent)
{

}

Game::Game(Field* fstPlayer, Field* secPlayer, QObject* parent)
    :   QObject(parent),
        m_fstPlayerField(fstPlayer),
        m_secPlayerField(secPlayer)
{
    m_currentPlayer = Player(rand() % 2 + 1);

    b_isGameOver = false;

    m_fstPlayerShipCellCount = 0;
    m_secPlayerShipCellCount = 0;

    for(int i = 0; i < 10; ++i)
        for(int j = 0; j < 10; ++j)
        {
            if(fstPlayer->getCell(i, j) == Field::Ship)
                m_fstPlayerShipCellCount++;
            if(secPlayer->getCell(i, j) == Field::Ship)
                m_secPlayerShipCellCount++;
        }
}

Game::TurnResult Game::turn(int row, int col)
{
    if(b_isGameOver)
        return Game::Error;

    Field* currentPlayerField = m_currentPlayer == First ? m_fstPlayerField : m_secPlayerField;
    Field::Cell cell = currentPlayerField->getCell(row, col);

    if(cell == Field::Ship)
    {
        currentPlayerField->setCell(row, col, Field::HitShip);
        return Game::Hit;
    }

    if(cell != Field::Empty)
        return Game::CellWasAtacked;

    currentPlayerField->setCell(row, col, Field::Miss);
    return Game::Miss;
}
