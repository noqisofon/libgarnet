/**
 * @file _crt.h
 * @since %create-timestamp%
 * 
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

    $Id _crt.h %timestamp% %author% $
 */
#ifndef garnet_crt__crt_h
#define garnet_crt__crt_h


//#ifdef GARNET_CRT_HAS_ERRNO_T_H
#   include <crt/errno_t.h>
//#endif  /* def GARNET_CRT_HAS_ERRNO_T_H */


#define     eos(str, index)         str[index] = '\0'
#define     str_truncate(str)       eos(str, 0)

#define     crt_max(x, y)           (x > y? x: y)
#define     crt_min(x, y)           (x < y? x: y)


#include "_guard_snip.h"


#endif  /* garnet_crt__crt_h */
// Local Variables:
//   coding: shift_jis
// End:
// _crt.h ends here
