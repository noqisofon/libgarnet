/**
 * \file    galloc.h
 * \brief   ���������蓖�Ċ֐����W���[���B
 * \since   2010-08-25T13:37:43
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

    $Id galloc.h %timestamp% noqisofon $
 */
#ifndef garnet_galloc_h
#define garnet_galloc_h

#ifndef GARNET_DEFINED_GARNET_API
#   define      GARNET_API                  __stdcall
#   define      GARNET_DEFINED_GARNET_API
#endif  /* ndef GARNET_DEFINED_GARNET_API */

#ifndef GARNET_DEFINED_VALUE
typedef     void*       VALUE;
#   define      GARNET_DEFINED_VALUE
#endif  /* GARNET_DEFINED_VALUE */


/**
 * size * n �o�C�g�����蓖�āA���蓖�Ă�ꂽ�������ɑ΂���|�C���^��Ԃ��܂��B
 * @see g_malloc
 */
VALUE GARNET_API g_malloc2(size_t n, size_t size);


/**
 * size �o�C�g�����蓖�āA���蓖�Ă�ꂽ�������ɑ΂���|�C���^��Ԃ��܂��B
 */
VALUE GARNET_API g_malloc(size_t size);


/**
 * size �o�C�g n �����蓖�āA���蓖�Ă�ꂽ�������ɑ΂���|�C���^��Ԃ��܂��B
 */
VALUE GARNET_API g_calloc(size_t n, size_t size);


/**
 * ptr �̃������u���b�N�̃T�C�Y��ύX���Asize �o�C�g�ɂ��܂��B
 */
VALUE GARNET_API g_realloc(VALUE ptr, size_t size);


/**
 * ptr ���w����������Ԃ��J�����܂��B
 */
void GARNET_API g_free(VALUE ptr);


/**
 * @def g_new
 */
#define     g_new(_type_, n)                    (_type_ *)g_malloc2( n, sizeof(_type_) )


#define     g_delete(p)                         g_free( p )
/**
 * @def ALLOC
 */
#define     ALLOC(_type_)                       (_type_ *)g_malloc( sizeof(_type_) )


/**
 * @def ALLOC_N
 */
#define     ALLOC_N(_type_, n)                  (_type_ *)g_malloc( sizeof(_type_) * n )


/**
 * @def REALLOC
 */
#define     REALLOC(_type_, ptr, resize)        (_type_ *)g_realloc( ptr, resize * sizeof(_type_) )


#endif  /* garnet_galloc_h */

// Local Variables:
//   coding: shift_jis
// End:
// galloc.h ends here
