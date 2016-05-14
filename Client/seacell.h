#ifndef SEACELL_H
#define SEACELL_H
#include <QWidget>

class SeaCell : public QWidget
{
    Q_OBJECT
public:
    SeaCell(QWidget* parent = 0);
    enum State{Empty = 0, Miss = 1, Hit = 2};
public slots:

    void setCellState(State);

};

#endif // SEACELL_H
