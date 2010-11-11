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
 * GARNET_VALIDATE_RETURN_ERRCODE の文字列切り捨てバージョンです。
 * @par 文字列切り捨てバージョンって？
 * <p>ある文字列操作関数では、エラー時に str_truncate を行うものがあります。<br />
 * その場合に使用されます。</p>
 */


/**
 * @def GARNET_VALIDATE_RETURN_ERRCODE
 * expr が有効化どうかを判別し、真なら err を返すマクロスニペットです。
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
