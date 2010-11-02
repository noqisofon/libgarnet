/**
 * @file gbitset.h
 * @since 2010-11-02T09:16:51+0900
 */
#ifndef garnet_gbitset_h
#define garnet_gbitset_h


typedef     unsigned int    bitset_t;


/**
 * self �� other_bitset ���܂܂�Ă�����^��Ԃ��܂��B
 */
gboolean g_bitset_is_include(bitset_t self, bitset_t other_bitset);


/**
 * �w�肳�ꂽ�r�b�g�Z�b�g�𔽓]�������̂�Ԃ��܂��B
 */
bitset_t g_bitset_inversion(bitset_t self);



/**
 * self ���� other ����菜�������̂�Ԃ��܂��B
 * @since 2010-09-24T14:13:12+0900
 */
bitset_t g_bitset_difference(bitset_t self, bitset_t other);


#endif  /* garnet_gbitset_h */
