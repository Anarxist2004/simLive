#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(WIDGETS_LIB)
#  define WIDGETS_EXPORT Q_DECL_EXPORT
# else
#  define WIDGETS_EXPORT Q_DECL_IMPORT
# endif
#else
# define WIDGETS_EXPORT
#endif
