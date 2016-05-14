#include "shipplacement.h"
#include "ui_shipplacement.h"

ShipPlacement::ShipPlacement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShipPlacement)
{
    ui->setupUi(this);
    ui->ship->setStyleSheet("background: url(:/Resource/seabg.png)");
    ui->ship->horizontalHeader()->setHidden(true);
    ui->ship->verticalHeader()->setHidden(true);
    ui->ship->setMinimumSize(102, 102);
    ui->ship->setMaximumSize(102, 102);

    ui->ship->setRowCount(4);
    ui->ship->setColumnCount(1);
    for(int i = 0; i < 4; ++i)
        ui->ship->setRowHeight(i, 25);
    ui->ship->setColumnWidth(0, 100);

    m_selectedShip = None;
    m_rotation = Horizontal;

    ui->field->setShipVisible(true);

    ui->ship->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);

    connect(ui->ship, SIGNAL(cellClicked(int,int)),
            this, SLOT(on_shipSelected(int,int)));

    connect(ui->field, SIGNAL(cellClicked(int,int)),
            this, SLOT(on_fieldCellCliced(int,int)));

    connect(ui->rotate, SIGNAL(clicked(bool)),
            this, SLOT(on_switchRotatation()));

}

ShipPlacement::~ShipPlacement()
{
    delete ui;
}

void ShipPlacement::on_shipSelected(int row, int col)
{
    switch(row)
    {
    case 0: m_selectedShip = Single; break;
    case 1: m_selectedShip = Double; break;
    case 2: m_selectedShip = Triple; break;
    case 3: m_selectedShip = Quad; break;
    }
}

#define MAX(a, b) ((a > b) ? (a) : (b))
#define MIN(a, b) ((a < b) ? (a) : (b))

void ShipPlacement::on_fieldCellCliced(int row, int col)
{
    if(m_selectedShip == None)
        return;

    // check entry field
    if(m_rotation == Horizontal && col + int(m_selectedShip) > 10 ||
       m_rotation == Vertical && row + int(m_selectedShip) > 10)
        return;

    // end point (begin - [row][col])
    int endShipRow = m_rotation == Vertical ? row + int(m_selectedShip) - 1 : row;
    int endShipCol = m_rotation == Horizontal ? col + int(m_selectedShip) - 1 : col;

    // check free space
    for(int i = MAX(0, row - 1); i <= MIN(9, endShipRow + 1); ++i)
        for(int j = MAX(0, col - 1); j <= MIN(9, endShipCol + 1); ++j)
            if(ui->field->getCell(i, j) != Field::Empty)
                return;

    // switch off update cells while ship isn`t install
    ui->field->setEnableUpdates(false);

    for(int i = row; i <= endShipRow; ++i)
        for(int j = col; j <= endShipCol; ++j)
            ui->field->setCell(i, j, Field::Ship);

    // switch on update cells
    ui->field->setEnableUpdates(true);
}

#undef MAX
#undef MIN

void ShipPlacement::on_switchRotatation()
{
    m_rotation = m_rotation == Horizontal ? Vertical : Horizontal;
}
