/**
 * @file    galloc.h
 * @brief   ���������蓖�Ċ֐����W���[���B
 * @since   2010-08-25T13:37:43
 */
#ifndef garnet_galloc_h
#define garnet_galloc_h

#include <stdint.h>

#ifndef GARNET_DEFINE_GARNET_API
#   define     GARNET_API      __stdcall
#endif  /* ndef GARNET_DEFINE_GARNET_API */


#ifndef GARNET_DEFINE_VALUE
typedef     void*       VALUE;
#   define      GARNET_DEFINE_VALUE
#endif  /* GARNET_DEFINE_VALUE */


/**
 * size �o�C�g�����蓖�āA���蓖�Ă�ꂽ�������ɑ΂���|�C���^��Ԃ��܂��B
 */
VALUE GARNET_API g_malloc(size_t size);


/**
 * size * n �o�C�g�����蓖�āA���蓖�Ă�ꂽ�������ɑ΂���|�C���^��Ԃ��܂��B
 * @see g_malloc
 */
VALUE GARNET_API g_malloc2(size_t n, size_t size);


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
