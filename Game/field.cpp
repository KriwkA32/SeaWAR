#include "field.h"
#include <cstring>

Field::Field(QObject* parent)
    : QObject(parent)
{
    memset(m_cells, 0, sizeof(m_cells));
}

Field::Field(const Field &field)
    : QObject(field.parent())
{
    for(int i = 0; i < 10; ++i)
        for(int j = 0; j < 10; ++j)
            m_cells[i][j] = field.m_cells[i][j];
}

void Field::clear()
{
    memset(m_cells, 0, sizeof(m_cells));
}

void Field::operator=(const Field &field)
{
    this->setParent(field.parent());
    for(int i = 0; i < 10; ++i)
        for(int j = 0; j < 10; ++j)
            m_cells[i][j] = field.m_cells[i][j];
}
