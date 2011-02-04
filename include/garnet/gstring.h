/* -*- encoding: utf-8; -*- */
/**
 * @file    gstring.h
 * @since   2010-07-27T08:41:24
 * @brief   文字列用関数モジュール。
 */
/*
    Copyright (c) 2010-2011 %full-author% %author-email%

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by 
    the Free Software Foundation; either version 3 of the License,
    or (at your option) any later version.

    This program is distributed in the hope that it will be useful, 
    but WITHOUT ANY WARRANTY; without even the implied warranty
    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program. If not, see <http://www.gnu.org/licenses/>.

    $Id gstring.h %timestamp% %author% $
 */
#ifndef garnet_gstring_h
#define garnet_gstring_h

#ifndef GARNET_DEFINE_GARNET_API
#   define     GARNET_API      __stdcall
#endif  /* ndef GARNET_DEFINE_GARNET_API */

#ifndef GARNET_DEFINED_GCHAR
typedef     char        gchar;
#   define      GARNET_DEFINED_GCHAR
#endif  /* ndef GARNET_DEFINED_GCHAR */

#ifndef GARNET_DEFINE_GINT
typedef     int32_t       gint;
#   define      GARNET_DEFINE_GINT
#endif  /* GARNET_DEFINE_GUINT */

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


#if 0
/**
 * 指定された文字列の長さを返します。
 */
size_t GARNET_API g_strlen(const gchar* self);
#else
/**
 * @def g_strlen
 * 指定された文字列の長さを返します。
 */
#   define     g_strlen        strlen
#endif
#define     g_strcpy        strcpy
#define     g_strncpy       strncpy
#define     g_strcat        strcat
#define     g_strncat       strncat
#define     g_strcmp        strcmp


/**
 * 指定された文字列の複製を返します。
 *  @param [in] self    複製する文字列。
 *
 *  @return 複製された文字列。
 *
 *  @note 複製された文字列は使い終わったら g_free 関数で開放してください。
 */
gchar* GARNET_API g_strdup(const gchar* self);


/**
 * 指定された文字列の n 文字目までの複製を返します。
 *  @param [in] self    複製する文字列。
 *  @param [in] n       複製する文字数。
 *
 *  @retuen 複製された文字列。
 *
 *  @note 複製された文字列は使い終わったら g_free 関数で開放してください。
 */
gchar* GARNET_API g_strndup(const gchar* self, size_t n);


/**
 * 指定された文字を n 文字で構成された文字列を返します。
 *  @param [in] n           文字列の長さ。
 *  @param [in] filled_ch   構成する文字列。
 *
 *  @return 指定した文字を n 文字で構成された文字列
 *
 * @note
 *      返された文字列は使い終わったら g_free 関数で開放してください。
 */
gchar* GARNET_API g_strnfill(size_t n, gchar filled_ch);


/**
 * self に other を割り当てます。
 *  @param [in,out] self    割り当てたい文字列。
 *  @param [in]     other   割り当てる文字列。
 *
 *  @return 割り当てられたあとの self。
 *
 *  @note
 *      other が self より長い場合、返された self が同じアドレスではありません。
 */
gchar* GARNET_API g_str_assign(gchar* self, const gchar* other);


/**
 * 指定された文字列から文字を検索し、その位置をポインタで返します。
 *  @param [in] self        検索する文字列。
 *  @param [in] n           検索する文字列の長さ。
 *  @param [in] found_ch    検索したい文字。
 *
 *  @return self 内のポインタ。
 */
const gchar* GARNET_API g_strchr(const gchar* self, size_t n, gchar found_ch);


/**
 * 指定された文字列から文字を逆方向から検索し、その位置をポインタで返します。
 *  @param [in] self        検索する文字列。
 *  @param [in] n           検索する文字列の長さ。
 *  @param [in] found_ch    検索したい文字。
 *
 *  @return self 内のポインタ。
 */
const gchar* GARNET_API g_strrchr(const gchar* self, size_t n, gchar found_ch);


/**
 * 指定された文字列に search_text が含まれていたらその最初の位置をポインタで返します。
 *  @param [in] self        検索する文字列。
 *  @param [in] search_text 検索したい文字列。
 *
 *  @return self 内のポインタ。
 */
const gchar* GARNET_API g_str_find(const gchar* self, const gchar* search_text);


/**
 * 指定された文字列に search_text が含まれていたらその最後の位置をポインタで返します。
 *  @param [in] self        検索する文字列。
 *  @param [in] search_text 検索したい文字列。
 *
 *  @return self 内のポインタ。
 */
const gchar* GARNET_API g_str_find_last_of(const gchar* self, const gchar* search_text);


/**
 * 指定された文字列に search_text が含まれていたらその最初の位置を返します。
 *  @param [in] self        検索する文字列。
 *  @param [in] search_text 検索したい文字列。
 *
 *  @return self 内の位置。
 */
gint GARNET_API g_str_index_of(const gchar* self, const gchar* search_text);


/**
 * 指定された文字列に search_text が含まれていたらその最後の位置を返します。
 *  @param [in] self        検索する文字列。
 *  @param [in] search_text 検索したい文字列。
 *
 *  @return self 内の位置。
 */
gint GARNET_API g_str_last_index_of(const gchar* self, const gchar* search_text);


/**
 * left と right が同じ内容かどうか判別します。
 *  @param [in] left    判別する文字列左辺。
 *  @param [in] right   判別する文字列右辺。
 *
 *  @return 同じなら真。
 */
gboolean GARNET_API g_str_equal(const gchar* left, const gchar* right);
/**
 * left と right が同じ内容かどうか判別します。
 *  @param [in] left        判別する文字列左辺。
 *  @param [in] left_len    left の文字列の長さ。
 *  @param [in] right       判別する文字列右辺。
 *  @param [in] right_len   right の文字列の長さ。
 *
 *  @return 同じなら真。
 */
gboolean GARNET_API g_str_equal_len(const gchar* left, size_t left_len, const gchar* right, size_t right_len);


/**
 * 指定された文字列の先頭に prefix が含まれていたらどうかを判別します。
 *  @param [in] self    判別する文字列。
 *  @param [in] prefix  調べる文字列。
 *
 *  @return 含まれていたら真。
 */
gboolean GARNET_API g_str_startswith(const gchar* self, const gchar* prefix);


/**
 * self に appendee を付け足します。
 *  @param  [in,out]    self    付け足される文字列。
 *  @param  [in]        apendee 付け足し文字列。
 *
 *  @return 付け足されたあとの self。
 *
 *  @note
 *      割り当てられたバッファより長くなる場合、バッファを伸ばすことはやっていません。
 */
gchar* GARNET_API g_str_append(gchar* self, const gchar* appendee);


/**
 * self に appendee を付け足します。
 *  @param  [in,out]    self    付け足される文字列。
 *  @param  [in]        apendee 付け足し文字。
 *
 *  @return 付け足されたあとの self。
 *
 *  @note
 *      割り当てられたバッファより長くなる場合、バッファを伸ばすことはやっていません。
 */
gchar* GARNET_API g_str_appendch(gchar* self, gchar appendee);


/**
 * self と right を結合した新しい文字列を返します。
 *  @param  [in]    self    結合する文字列左辺。
 *  @param  [in]    right   結合する文字列右辺。
 *
 *  @return self と right を結合した新しい文字列。
 */
gchar* GARNET_API g_str_concat(const gchar* self, const gchar* right);


/**
 * self の n 文字目を返します。
 */
gint GARNET_API g_str_char_at(const gchar* self, gint n);


/**
 * self の n 文字目から m 文字目までを返します。
 */
gchar* GARNET_API g_str_slice(const gchar* self, gint n, gint m);


/**
 * self の n 文字目から末尾までを返します。
 */
gchar* GARNET_API g_str_slice_last(const gchar* self, gint n);


/**
 * self に含まれる sub_string を replacement で置換した後の新しい文字列を返しま
 * す。
 */
gchar* GARNET_API g_str_replace( const gchar*  self,
                                 const gchar*  sub_string,
                                 const gchar*  replacement
                                 );


/**
 * self に含まれる sub_string を replacement ですべて置換した後の新しい文字列を
 * 返します。
 */
gchar* GARNET_API g_str_replace_all( const gchar*  self,
                                     const gchar*  sub_string,
                                     const gchar*  replacement
                                     );


#endif  /* garnet_gstring_h */
