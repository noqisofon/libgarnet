#ifndef garnet_crt__err_handle_h
#define garnet_crt__err_handle_h

#include <assert.h>


#if defined(_DEBUG) || defined(DEBUG)
#   define  GARNET_ASSERT_ERROR(expr)       assert(expr)
#else
#   define  GARNET_ASSERT_ERROR(expr)
#endif  /* defined(_DEBUG) || defined(DEBUG) */


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
