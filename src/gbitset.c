/* -*- encoding: utf-8; -*- */
/**
 * @file gbitset.c
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

    $Id gbitset.c %timestamp% %author% $
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
