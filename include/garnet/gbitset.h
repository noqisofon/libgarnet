/**
 * \file gbitset.h
 * \since 2010-11-02T09:16:51+0900
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

    $Id gbitset.h %timestamp% noqisofon $
 */
#ifndef garnet_gbitset_h
#define garnet_gbitset_h

#ifndef GARNET_DEFINED_GARNET_API
#   define      GARNET_API                  __stdcall
#   define      GARNET_DEFINED_GARNET_API
#endif  /* ndef GARNET_DEFINED_GARNET_API */

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

#ifndef GARNET_DEFINED_BITSET_T
typedef     unsigned int    bitset_t;
#define     GARNET_DEFINED_BITSET_T
#endif  /* ndef GARNET_DEFINED_BITSET_T */


/**
 * self �� other_bitset ���܂܂�Ă�����^��Ԃ��܂��B
 */
gboolean GARNET_API g_bitset_is_include(bitset_t self, bitset_t other_bitset);


/**
 * �w�肳�ꂽ�r�b�g�Z�b�g�𔽓]�������̂�Ԃ��܂��B
 */
bitset_t GARNET_API g_bitset_inversion(bitset_t self);



/**
 * self ���� other ����菜�������̂�Ԃ��܂��B
 * \since 2010-09-24T14:13:12+0900
 */
bitset_t GARNET_API g_bitset_difference(bitset_t self, bitset_t other);


#endif  /* garnet_gbitset_h */
// Local Variables:
//   coding: shift_jis
// End:
// gbitset.h ends here
