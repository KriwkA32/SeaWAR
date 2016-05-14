#ifndef SHIPPLACEMENT_H
#define SHIPPLACEMENT_H

#include <QDialog>
#include "seafield.h"

namespace Ui {
class ShipPlacement;
}

class ShipPlacement : public QDialog
{
    Q_OBJECT

public:
    enum Rotation{Horizontal = 0, Vertical = 1};
    enum Ship{None = 0, Single = 1, Double = 2, Triple = 3, Quad = 4};
    ShipPlacement(QWidget *parent = 0);
    ~ShipPlacement();
private slots:
    void on_shipSelected(int, int);
    void on_fieldCellCliced(int, int);
    void on_switchRotatation();
private:
    Ship m_selectedShip;
    Rotation m_rotation;
    Ui::ShipPlacement *ui;
};

#endif // SHIPPLACEMENT_H

