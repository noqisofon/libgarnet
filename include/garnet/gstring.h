/**
 * \file    gstring.h
 * \since   2010-07-27T08:41:24
 * \brief   ������p�֐����W���[���B
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

    $Id gstring.h %timestamp% noqisofon $
 */
#ifndef garnet_gstring_h
#define garnet_gstring_h

#ifndef GARNET_DEFINED_GARNET_API
#   define      GARNET_API                  __stdcall
#   define      GARNET_DEFINED_GARNET_API
#endif  /* ndef GARNET_DEFINED_GARNET_API */

#ifndef GARNET_DEFINED_GCHAR
typedef     char        gchar;
#   define      GARNET_DEFINED_GCHAR
#endif  /* ndef GARNET_DEFINED_GCHAR */

#ifndef GARNET_DEFINED_GINT
typedef     int32_t       gint;
#   define      GARNET_DEFINED_GINT
#endif  /* GARNET_DEFINED_GUINT */

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
 * �w�肳�ꂽ������̒�����Ԃ��܂��B
 */
size_t GARNET_API g_strlen(const gchar* self);
#else
/**
 * @def g_strlen
 * �w�肳�ꂽ������̒�����Ԃ��܂��B
 */
#   define     g_strlen        strlen
#endif

#define     g_strcpy        strcpy
///**
// * s1 �� s2 ���R�s�[���܂��B
// */
//gchar* GARNET_API g_strcpy(gchar* s1, const gchar* s2);
#define     g_strncpy       strncpy
#define     g_strcat        strcat
#define     g_strncat       strncat
#define     g_strcmp        strcmp


/**
 * �w�肳�ꂽ������̕�����Ԃ��܂��B
 *  @param [in] self    �������镶����B
 *
 *  @return �������ꂽ������B
 *
 *  @note �������ꂽ������͎g���I������� g_free �֐��ŊJ�����Ă��������B
 */
gchar* GARNET_API g_strdup(const gchar* self);


/**
 * �w�肳�ꂽ������� n �����ڂ܂ł̕�����Ԃ��܂��B
 *  @param [in] self    �������镶����B
 *  @param [in] n       �������镶�����B
 *
 *  @return �������ꂽ������B
 *
 *  @note �������ꂽ������͎g���I������� g_free �֐��ŊJ�����Ă��������B
 */
gchar* GARNET_API g_strndup(const gchar* self, size_t n);


/**
 * �w�肳�ꂽ������ n �����ō\�����ꂽ�������Ԃ��܂��B
 *  @param [in] n           ������̒����B
 *  @param [in] filled_ch   �\�����镶����B
 *
 *  @return �w�肵�������� n �����ō\�����ꂽ������
 *
 * @note
 *      �Ԃ��ꂽ������͎g���I������� g_free �֐��ŊJ�����Ă��������B
 */
gchar* GARNET_API g_strnfill(size_t n, gchar filled_ch);


/**
 * self �� other �����蓖�Ă܂��B
 *  @param [in,out] self    ���蓖�Ă���������B
 *  @param [in]     other   ���蓖�Ă镶����B
 *
 *  @return ���蓖�Ă�ꂽ���Ƃ� self�B
 *
 *  @note
 *      other �� self ��蒷���ꍇ�A�Ԃ��ꂽ self �������A�h���X�ł͂���܂���B
 */
gchar* GARNET_API g_str_assign(gchar* self, const gchar* other);


/**
 * �w�肳�ꂽ�����񂩂當�����������A���̈ʒu���|�C���^�ŕԂ��܂��B
 *  @param [in] self        �������镶����B
 *  @param [in] n           �������镶����̒����B
 *  @param [in] found_ch    ���������������B
 *
 *  @return self ���̃|�C���^�B
 */
const gchar* GARNET_API g_strchr(const gchar* self, size_t n, gchar found_ch);


/**
 * �w�肳�ꂽ�����񂩂當�����t�������猟�����A���̈ʒu���|�C���^�ŕԂ��܂��B
 *  @param [in] self        �������镶����B
 *  @param [in] n           �������镶����̒����B
 *  @param [in] found_ch    ���������������B
 *
 *  @return self ���̃|�C���^�B
 */
const gchar* GARNET_API g_strrchr(const gchar* self, size_t n, gchar found_ch);


/**
 * �w�肳�ꂽ������� search_text ���܂܂�Ă����炻�̍ŏ��̈ʒu���|�C���^�ŕԂ��܂��B
 *  @param [in] self        �������镶����B
 *  @param [in] search_text ����������������B
 *
 *  @return self ���̃|�C���^�B
 */
const gchar* GARNET_API g_str_find(const gchar* self, const gchar* search_text);


/**
 * �w�肳�ꂽ������� search_text ���܂܂�Ă����炻�̍Ō�̈ʒu���|�C���^�ŕԂ��܂��B
 *  @param [in] self        �������镶����B
 *  @param [in] search_text ����������������B
 *
 *  @return self ���̃|�C���^�B
 */
const gchar* GARNET_API g_str_find_last_of(const gchar* self, const gchar* search_text);


/**
 * �w�肳�ꂽ������� search_text ���܂܂�Ă����炻�̍ŏ��̈ʒu��Ԃ��܂��B
 *  @param [in] self        �������镶����B
 *  @param [in] search_text ����������������B
 *
 *  @return self ���̈ʒu�B
 */
gint GARNET_API g_str_index_of(const gchar* self, const gchar* search_text);


/**
 * �w�肳�ꂽ������� search_text ���܂܂�Ă����炻�̍Ō�̈ʒu��Ԃ��܂��B
 *  @param [in] self        �������镶����B
 *  @param [in] search_text ����������������B
 *
 *  @return self ���̈ʒu�B
 */
gint GARNET_API g_str_last_index_of(const gchar* self, const gchar* search_text);


/**
 * left �� right ���������e���ǂ������ʂ��܂��B
 *  @param [in] left    ���ʂ��镶���񍶕ӁB
 *  @param [in] right   ���ʂ��镶����E�ӁB
 *
 *  @return �����Ȃ�^�B
 */
gboolean GARNET_API g_str_equal(const gchar* left, const gchar* right);
/**
 * left �� right ���������e���ǂ������ʂ��܂��B
 *  @param [in] left        ���ʂ��镶���񍶕ӁB
 *  @param [in] left_len    left �̕�����̒����B
 *  @param [in] right       ���ʂ��镶����E�ӁB
 *  @param [in] right_len   right �̕�����̒����B
 *
 *  @return �����Ȃ�^�B
 */
gboolean GARNET_API g_str_equal_len(const gchar* left, size_t left_len, const gchar* right, size_t right_len);


/**
 * �w�肳�ꂽ������̐擪�� prefix ���܂܂�Ă�����ǂ����𔻕ʂ��܂��B
 *  @param [in] self    ���ʂ��镶����B
 *  @param [in] prefix  ���ׂ镶����B
 *
 *  @return �܂܂�Ă�����^�B
 */
gboolean GARNET_API g_str_startswith(const gchar* self, const gchar* prefix);


/**
 * self �� appendee ��t�������܂��B
 *  @param  [in,out]    self     �t��������镶����B
 *  @param  [in]        appendee �t������������B
 *
 *  @return �t�������ꂽ���Ƃ� self�B
 *
 *  @note
 *      ���蓖�Ă�ꂽ�o�b�t�@��蒷���Ȃ�ꍇ�A�o�b�t�@��L�΂����Ƃ͂���Ă��܂���B
 */
gchar* GARNET_API g_str_append(gchar* self, const gchar* appendee);


/**
 * self �� appendee ��t�������܂��B
 *  @param  [in,out]    self     �t��������镶����B
 *  @param  [in]        appendee �t�����������B
 *
 *  @return �t�������ꂽ���Ƃ� self�B
 *
 *  @note
 *      ���蓖�Ă�ꂽ�o�b�t�@��蒷���Ȃ�ꍇ�A�o�b�t�@��L�΂����Ƃ͂���Ă��܂���B
 */
gchar* GARNET_API g_str_appendch(gchar* self, gchar appendee);


/**
 * self �� right �����������V�����������Ԃ��܂��B
 *  @param  [in]    self    �������镶���񍶕ӁB
 *  @param  [in]    right   �������镶����E�ӁB
 *
 *  @return self �� right �����������V����������B
 */
gchar* GARNET_API g_str_concat(const gchar* self, const gchar* right);


/**
 * self �� n �����ڂ�Ԃ��܂��B
 */
gint GARNET_API g_str_char_at(const gchar* self, gint n);


/**
 * self �� n �����ڂ��� m �����ڂ܂ł�Ԃ��܂��B
 */
gchar* GARNET_API g_str_slice(const gchar* self, gint n, gint m);


/**
 * self �� n �����ڂ��疖���܂ł�Ԃ��܂��B
 */
gchar* GARNET_API g_str_slice_last(const gchar* self, gint n);


/**
 * self �Ɋ܂܂�� sub_string �� replacement �Œu��������̐V�����������Ԃ���
 * ���B
 */
gchar* GARNET_API g_str_replace( const gchar*  self,
                                 const gchar*  sub_string,
                                 const gchar*  replacement
                                 );


/**
 * self �Ɋ܂܂�� sub_string �� replacement �ł��ׂĒu��������̐V�����������
 * �Ԃ��܂��B
 */
gchar* GARNET_API g_str_replace_all( const gchar*  self,
                                     const gchar*  sub_string,
                                     const gchar*  replacement
                                     );


#endif  /* garnet_gstring_h */
// Local Variables:
//   coding: shift_jis
// End:
// gstring.h ends here
