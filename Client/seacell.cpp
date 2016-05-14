#include "seacell.h"

SeaCell::SeaCell(QWidget* parent)
    :QWidget(parent)
{
    //setStyleSheet("background: url(:/Resource/emptyCell.png)");


}


void SeaCell::setCellState(State state)
{
    switch(state)
    {
    case Empty: setStyleSheet("background: url(:/Resource/emptyCell.png)"); break;
    case Miss: setStyleSheet("background: url(:/Resource/missCell.png)"); break;
    case Hit: setStyleSheet("background: url(:/Resource/hitCell.png)"); break;
    }
}
