#ifndef GAME_H
#define GAME_H

#include "game_global.h"

class Field;

class GAMESHARED_EXPORT Game : public QObject
{
    Q_OBJECT

    // Game types
public:
    enum TurnResult{Miss, Hit, Error, CellWasAtacked};
    enum Player{First = 1, Second = 2};
    enum GameOverReason{FirstPlayerWin, SecondPlayerWin};

public:
    Game(QObject* parent = 0);
    Game(Field* fstPlayer, Field* secPlayer, QObject* parent = 0);

    inline Player whoseTurn() const { return m_currentPlayer; }
    TurnResult turn(int row, int col);

private:
    Field* m_fstPlayerField;
    Field* m_secPlayerField;
    int m_fstPlayerShipCellCount;
    int m_secPlayerShipCellCount;
    Player m_currentPlayer;

    bool b_isGameOver;

signals:

    void gameOver(GameOverReason);
    void gameStarted(bool);
};

#endif // GAME_H
