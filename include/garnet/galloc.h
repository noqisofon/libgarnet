#ifndef garnet_galloc_h
#define garnet_galloc_h

#include "_garnet.h"


/**
 * size バイトを割り当て、割り当てられたメモリに対するポインタを返します。
 */
VALUE g_malloc(size_t size);


/**
 * size * n バイトを割り当て、割り当てられたメモリに対するポインタを返します。
 * @see g_malloc
 */
VALUE g_malloc2(size_t n, size_t size);


/**
 * size バイト n 個を割り当て、割り当てられたメモリに対するポインタを返します。
 */
VALUE g_calloc(size_t n, size_t size);


/**
 * ptr のメモリブロックのサイズを変更し、size バイトにします。
 */
VALUE g_realloc(VALUE ptr, size_t size);


/**
 * ptr が指すメモリ空間を開放します。
 */
void g_free(VALUE ptr);


/**
 * @def g_new
 */
#define     g_new(_type_, n)                    (_type_ *)g_malloc2( n, sizeof(_type_) )


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
