/**
 * @file gbitset.h
 * @since 2010-11-02T09:16:51+0900
 */
#ifndef garnet_gbitset_h
#define garnet_gbitset_h

#ifndef GARNET_DEFINE_GARNET_API
#   define     GARNET_API      __stdcall
#endif  /* ndef GARNET_DEFINE_GARNET_API */

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
 * @since 2010-09-24T14:13:12+0900
 */
bitset_t GARNET_API g_bitset_difference(bitset_t self, bitset_t other);


#endif  /* garnet_gbitset_h */
