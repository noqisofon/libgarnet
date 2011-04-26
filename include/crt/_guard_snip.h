/**
 * @file _guard_snip.h
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

    $Id _guard_snip.h %timestamp% %author% $
 */
#ifndef garnet_crt__err_handle_h
#define garnet_crt__err_handle_h

#include <assert.h>


#if defined(_DEBUG) || defined(DEBUG)
#   define  GARNET_ASSERT_ERROR(expr)       assert(expr)
#else
#   define  GARNET_ASSERT_ERROR(expr)
#endif  /* defined(_DEBUG) || defined(DEBUG) */

#define     GARNET_INVALID_PARAMETER(expr)


/**
 * @def GARNET_VALIDATE_STRTRUNCATE_RETURN_ERRCODE
 * GARNET_VALIDATE_RETURN_ERRCODE �̕�����؂�̂ăo�[�W�����ł��B
 * @par ������؂�̂ăo�[�W�������āH
 * <p>���镶���񑀍�֐��ł́A�G���[���� str_truncate ���s�����̂�����܂��B<br />
 * ���̏ꍇ�Ɏg�p����܂��B</p>
 */


/**
 * @def GARNET_VALIDATE_RETURN_ERRCODE
 * expr ���L�����ǂ����𔻕ʂ��A�^�Ȃ� err ��Ԃ��}�N���X�j�y�b�g�ł��B
 */
#define     GARNET_VALIDATE_RETURN_ERRCODE(expr, err)                   \
    {                                                                   \
        GARNET_ASSERT_ERROR( (expr) );                                  \
        if ( (expr) ) {                                                 \
            errno   =   err;                                            \
            GARNET_INVALID_PARAMETER( (expr) );                         \
            return err;                                                 \
        }                                                               \
    }



#define     GARNET_VALIDATE_STRTRUNCATE_RETURN_ERRCODE(expr, err, str)  \
    {                                                                   \
        GARNET_ASSERT_ERROR( (expr) );                                  \
        if ( (expr) ) {                                                 \
            errno   =   err;                                            \
            str_truncate(str);                                          \
            GARNET_INVALID_PARAMETER( (expr) );                         \
            return err;                                                 \
        }                                                               \
    }


#endif  /* garnet_crt__err_handle_h */
// Local Variables:
//   coding: shift_jis-dos
// End:
// _guard_snip.h ends here
