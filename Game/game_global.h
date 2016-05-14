#ifndef GAME_GLOBAL_H
#define GAME_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QObject>

#if defined(GAME_LIBRARY)
#  define GAMESHARED_EXPORT Q_DECL_EXPORT
#else
#  define GAMESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // GAME_GLOBAL_H
