/**
 * @file gbitset.h
 * @since 2010-11-02T09:16:51+0900
 */
#ifndef garnet_gbitset_h
#define garnet_gbitset_h


typedef     unsigned int    bitset_t;


/**
 * self に other_bitset が含まれていたら真を返します。
 */
gboolean g_bitset_is_include(bitset_t self, bitset_t other_bitset);


/**
 * 指定されたビットセットを反転したものを返します。
 */
bitset_t g_bitset_inversion(bitset_t self);



/**
 * self から other を取り除いたものを返します。
 * @since 2010-09-24T14:13:12+0900
 */
bitset_t g_bitset_difference(bitset_t self, bitset_t other);


#endif  /* garnet_gbitset_h */
