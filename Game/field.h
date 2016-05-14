#ifndef FIELD_H
#define FIELD_H
#include "game_global.h"

class GAMESHARED_EXPORT Field : public QObject
{
    Q_OBJECT
public:
    // field types
    enum Cell{Empty = 0, Miss = 1, Ship = 2, HitShip = 3};
public:

    Field(QObject* parent = 0);
    Field(const Field& field);
    inline void setCell(int row, int col, Cell cell) { m_cells[row][col] = cell; }
    inline Cell getCell(int row, int col) const { return m_cells[row][col]; }
    void clear();
    void operator=(const Field& field);
private:
    Cell m_cells[10][10];
};

#endif // FIELD_H
