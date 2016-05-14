#include "seafield.h"
#include <QHeaderView>
#include <cstring>

SeaField::SeaField(QWidget* parent)
    :QTableWidget(parent)
{
    setRowCount(10);
    setColumnCount(10);
    int cellSize = 25;

    setMinimumSize(cellSize * 10 + 2, cellSize * 10 + 2);
    setMaximumSize(cellSize * 10 + 2, cellSize * 10 + 2);
    horizontalHeader()->setHidden(true);
    verticalHeader()->setHidden(true);
    this->setSelectionMode(SelectionMode::NoSelection);

    setStyleSheet("background: url(:/Resource/seabg.png)");
    for(int i = 0; i < 10; ++i)
    {
        setRowHeight(i, cellSize);
        setColumnWidth(i, cellSize);
        for(int j = 0; j < 10; ++j)
            setCellWidget(i, j, new QWidget(this));
    }

    b_isEnableUpdate = true;
    b_shipsVisible = false;

    styleSheets[Field::Empty] = "background: none";
    styleSheets[Field::Miss] = "background: url(:/Resource/missCell.png)";
    styleSheets[Field::Ship] = "background: url(:/Resource/ship.png)";
    styleSheets[Field::HitShip] = "background: url(:/Resource/hitShip.png)";
}


void SeaField::setCell(int row, int col, Field::Cell ship)
{
    m_field.setCell(row, col, ship);
    update();
}

void SeaField::setShipVisible(bool visible)
{
    if(visible == b_shipsVisible)
        return;
    b_shipsVisible = visible;
    update();
}

void SeaField::setEnableUpdates(bool flag)
{
    bool oldFlag = b_isEnableUpdate;
    b_isEnableUpdate = flag;
    if(flag && !oldFlag)
        update();
}

void SeaField::update()
{
    if(!b_isEnableUpdate)
        return;
    for(int i = 0; i < 10; ++i)
        for(int j = 0; j < 10; ++j)
        {
            if(m_field.getCell(i, j) != Field::Ship)
                cellWidget(i, j)->setStyleSheet(styleSheets[ m_field.getCell(i, j) ]);
            else
            {
                if (b_shipsVisible == true)
                    cellWidget(i, j)->setStyleSheet(styleSheets[Field::Ship]);
                else
                    cellWidget(i, j)->setStyleSheet(styleSheets[Field::Empty]);
            }
        }
}
