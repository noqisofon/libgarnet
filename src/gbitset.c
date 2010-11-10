/**
 * @file gbitset.c
 */
#include <stdafx.h>
#include <garnet/gbitset.h>


gboolean GARNET_API g_bitset_is_include(bitset_t self, bitset_t other_bitset)
{
    return (self & other_bitset) == other_bitset;
}


bitset_t GARNET_API g_bitset_inversion(bitset_t self)
{
    return self ^ ~0;
}


bitset_t GARNET_API g_bitset_difference(bitset_t self, bitset_t other)
{
    return self ^ (self & other);
}
