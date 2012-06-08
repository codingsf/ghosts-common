#ifndef GHOSTSCOMMON_GLOBAL_H
#define GHOSTSCOMMON_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GHOSTSCOMMON_LIBRARY)
#  define GHOSTSCOMMONSHARED_EXPORT Q_DECL_EXPORT
#else
#  define GHOSTSCOMMONSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // GHOSTSCOMMON_GLOBAL_H