#ifndef garnet_gstring_h
#define garnet_gstring_h

#include "_garnet.h"


#if 0
/**
 * 指定された文字列の長さを返します。
 */
size_t g_strlen(const gchar* self);
#else
#   define     g_strlen        strlen
#endif
#define     g_strcpy        strcpy
#define     g_strncpy       strncpy
#define     g_strcat        strcat
#define     g_strncat       strncat
#define     g_strcmp        strcmp


/**
 * 指定された文字列の複製を返します。
 */
gchar* g_strdup(const gchar* self);


/**
 * 指定された文字列の n byte 目までの複製を返します。
 */
gchar* g_strndup(const gchar* self, size_t _N);


/**
 * 指定された文字を n 文字で構成された文字列を返します。
 */
gchar* g_strnfill(size_t _N, gchar filled_ch);


/**
 * self に other を割り当てます。
 */
gchar* g_str_assign(gchar* self, const gchar* other);


/**
 *
 */
const gchar* g_str_find(const gchar* self, size_t n, gchar found_ch);


/**
 *
 */
const gchar* g_str_rfind(const gchar* self, size_t _N, gchar found_ch);


/**
 * left と right が同じ内容かどうか判別します。
 */
gboolean g_str_equal(const gchar* left, const gchar* right);
/**
 * left と right が同じ内容かどうか判別します。
 */
gboolean g_str_equal_len(const gchar* left, size_t left_len, const gchar* right, size_t right_len);


/**
 *
 */
gboolean g_str_startswith(const gchar* self, const gchar* prefix);


/**
 * self に appendee を付け足します。
 */
gchar* g_str_append(gchar* self, const gchar* appendee);


/**
 * self に appendee を付け足します。
 */
gchar* g_str_appendch(gchar* self, gchar appendee);


/**
 * self と right を結合した新しい文字列を返します。
 */
gchar* g_str_concat(const gchar* self, const gchar* right);


/**
 * self の n 文字目を返します。
 */
int32_t g_str_slice(const gchar* self, int32_t n);


/**
 * self に含まれる sub_string を replacement で置換した後の新しい文字列を返しま
 * す。
 */
gchar* g_str_replace( const gchar*  self,
                      const gchar*  sub_string,
                      const gchar*  replacement
                      );


/**
 * self に含まれる sub_string を replacement ですべて置換した後の新しい文字列を
 * 返します。
 */
gchar* g_str_replace_all( const gchar*  self,
                          const gchar*  sub_string,
                          const gchar*  replacement
                          );


#endif  /* garnet_gstring_h */
