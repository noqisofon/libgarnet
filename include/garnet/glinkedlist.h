/**
 * \file    glinkedlist.h
 * \since   2010-10-13T09:31:23+0900
 * \brief   �o���������N���X�g�B
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

    $Id glinkedlist.h %timestamp% noqisofon $
 */
#ifndef garnet_glinkedlist_h
#define garnet_glinkedlist_h

#include <stdint.h>

#ifndef GARNET_DEFINED_GARNET_API
#   define      GARNET_API                  __stdcall
#   define      GARNET_DEFINED_GARNET_API
#endif  /* ndef GARNET_DEFINED_GARNET_API */

#ifndef GARNET_DEFINED_VALUE
typedef     void*       VALUE;
#   define      GARNET_DEFINED_VALUE
#endif  /* GARNET_DEFINED_VALUE */

#ifndef GARNET_DEFINED_GINT
typedef     int32_t       gint;
#   define      GARNET_DEFINED_GINT
#endif  /* GARNET_DEFINED_GINT */


/**
 * �����N���X�g�̃m�[�h�ł��B
 */
typedef struct g_linkedlist_t {
    struct g_linkedlist_t*      head;
    VALUE                       value;
    struct g_linkedlist_t*      tail;
} GList;


/**
 * ���X�g�̖����� item ����ꂽ�m�[�h��ǉ����܂��B
 */
GList* GARNET_API  g_list_add(GList* self, VALUE item);


/**
 * ���X�g�̐擪�� item ��ǉ����܂��B
 */
GList* GARNET_API  g_list_add_front(GList* self, VALUE item);


/**
 * ���X�g�� position �Ԗڂ� item ��}�����܂��B
 */
GList* GARNET_API  g_list_insert(GList* self, VALUE item, gint position);


/**
 * �w�肳�ꂽ���X�g�̐擪�̃m�[�h��Ԃ��܂��B
 */
GList* GARNET_API  g_list_front(GList* self);


/**
 * �w�肳�ꂽ���X�g�̖����̃m�[�h��Ԃ��܂��B
 */
GList* GARNET_API  g_list_behind(GList* self);


/**
 * �w�肳�ꂽ���X�g�̃T�C�Y��Ԃ��܂��B
 */
size_t GARNET_API  g_list_length(GList* self);


/**
 * ���X�g�� position �Ԗڂ̃m�[�h��Ԃ��܂��B
 */
GList* GARNET_API  g_list_advance(GList* self, gint distance);


/**
 * ���X�g����w�肳�ꂽ�l�������Ă���m�[�h���������܂��B
 */
GList* GARNET_API  g_list_find(GList* self, VALUE found);


/**
 * �w�肳�ꂽ���X�g���g���Ă��郁������S�ĊJ�����܂��B
 */
void GARNET_API    g_list_free(GList* self);


#endif  /* garnet_glinkedlist_h */
// Local Variables:
//   coding: shift_jis
// End:
// glinkedlist.h ends here
