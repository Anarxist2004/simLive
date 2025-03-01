#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(ATOOLS_LIB)
#  define ATOOLS_EXPORT Q_DECL_EXPORT
# else
#  define ATOOLS_EXPORT Q_DECL_IMPORT
# endif
#else
# define ATOOLS_EXPORT
#endif
