#ifndef garnet_gtypes_h
#define garnet_gtypes_h

#include <stdint.h>


#ifndef GARNET_DEFINE_VALUE
typedef     void*       VALUE;
#   define      GARNET_DEFINE_VALUE
#endif  /* ndef GARNET_DEFINE_VALUE */

#ifndef GARNET_DEFINE_GINT
typedef     int32_t       gint;
#   define      GARNET_DEFINE_GINT
#endif  /* GARNET_DEFINE_GUINT */

#ifndef GARNET_DEFINE_GUINT
typedef     uint32_t       guint;
#   define      GARNET_DEFINE_GUINT
#endif  /* GARNET_DEFINE_GUINT */

#ifndef GARNET_DEFINED_GCHAR
typedef     char        gchar;
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


#endif  /* garnet_gtypes_h */
