#ifndef garnet__garnet_h
#define garnet__garnet_h

//#ifndef _MSC_VER
#   include <stdint.h>
#   include <limits.h>
//#endif  /* ndef _MSC_VER */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#ifdef GARNET_HAS_GTYPES_H
#   include <garnet/gtypes.h>
#endif  /* def GARNET_HAS_GTYPES_H */


#ifndef GARNET_DEFINE_VALUE
typedef     void*       VALUE;
#   define      GARNET_DEFINE_VALUE
#endif  /* GARNET_DEFINE_VALUE */

#ifndef GARNET_DEFINE_GINT
typedef     int32_t       gint;
#   define      GARNET_DEFINE_GINT
#endif  /* GARNET_DEFINE_GINT */

#ifndef GARNET_DEFINE_GUINT
typedef     uint32_t       guint;
#   define      GARNET_DEFINE_GUINT
#endif  /* GARNET_DEFINE_GUINT */

#ifndef GARNET_DEFINED_GCHAR
#   if defined(_UNICODE) || defined(UNICODE)
typedef     wchar_t     gchar;
#else
typedef     char        gchar;
#endif  /* defined(_UNICODE) || defined(UNICODE) */
#   define      GARNET_DEFINED_GCHAR
#endif  /* ndef GARNET_DEFINED_GCHAR */

#ifndef GARNET_DEFINED_GBOOLEAN
#   ifndef __cplusplus
typedef enum tag_boolean {
    false   = 0,
    true    = 1
} gboolean;
#   else
typedef     bool        gboolean;
#   endif  /* ndef __cplusplus */
#   define      GARNET_DEFINED_GBOOLEAN
#endif  /* def GARNET_DEFINED_GBOOLEAN */


#endif  /* garnet__garnet_h */
