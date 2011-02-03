/* -*- encoding: utf-8; -*- */
/**
 * @file    galloc.h
 * @brief   メモリ割り当て関数モジュール。
 * @since   2010-08-25T13:37:43
 */
/*

    Copyright (c) %year% %full-author% %author-email%

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

    $Id galloc.h %timestamp% %author% $
 */
#ifndef garnet_galloc_h
#define garnet_galloc_h

#include <stdint.h>

#ifndef GARNET_DEFINE_GARNET_API
#   define     GARNET_API      __stdcall
#endif  /* ndef GARNET_DEFINE_GARNET_API */

/**
 * size バイトを割り当て、割り当てられたメモリに対するポインタを返します。
 */
VALUE g_malloc(size_t size);

#ifndef GARNET_DEFINE_VALUE
typedef     void*       VALUE;
#   define      GARNET_DEFINE_VALUE
#endif  /* GARNET_DEFINE_VALUE */


/**
 * size * n バイトを割り当て、割り当てられたメモリに対するポインタを返します。
 * @see g_malloc
 */
VALUE GARNET_API g_malloc2(size_t n, size_t size);


/**
 * size バイトを割り当て、割り当てられたメモリに対するポインタを返します。
 */
VALUE GARNET_API g_malloc(size_t size);


/**
 * size バイト n 個を割り当て、割り当てられたメモリに対するポインタを返します。
 */
VALUE GARNET_API g_calloc(size_t n, size_t size);


/**
 * ptr のメモリブロックのサイズを変更し、size バイトにします。
 */
VALUE GARNET_API g_realloc(VALUE ptr, size_t size);


/**
 * ptr が指すメモリ空間を開放します。
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
