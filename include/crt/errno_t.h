/**
 * @file errno_t.h
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

    $Id errno_t.h %timestamp% %author% $
 */
#ifndef garnet_crt_errno_h
#define garnet_crt_errno_h

#if !defined(_MSC_VER)
#   ifndef GARNET_CRT_DEFINE_ERRNO_T
typedef     int     errno_t;
#       define     GARNET_CRT_DEFINE_ERRNO_T
#   endif  /* ndef GARNET_CRT_DEFINE_ERRNO_T */
#endif  /* ndef GARNET_CRT_DEFINE_ERRNO_T */


#endif  /* garnet_crt_errno_h */
// Local Variables:
//   coding: shift_jis-dos
// End:
// _guard_snip.h ends here
