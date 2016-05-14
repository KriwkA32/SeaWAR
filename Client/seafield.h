#ifndef SEAFIELD_H
#define SEAFIELD_H
#include "field.h"
#include <QTableWidget>
#include <map>

class SeaField : public QTableWidget
{
    Q_OBJECT
public:
    SeaField(QWidget* parent = 0);
    inline void setField(const Field& field) { m_field = field; }
    inline Field getField() const { return m_field; }

public slots:
    void setCell(int row, int col, Field::Cell cell);
    void setShipVisible(bool);
    void setEnableUpdates(bool);

private:
    Field m_field;
    std::map<Field::Cell, QString> styleSheets;

    bool b_isEnableUpdate;
    void update();

    bool b_shipsVisible;

public:
    inline Field::Cell getCell(int row, int col) const { return m_field.getCell(row, col); }

signals:
    void cellChanged(int, int);
};

#endif // SEAFIELD_H
