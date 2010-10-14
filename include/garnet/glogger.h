#ifndef garnet_glogger_h
#define garnet_glogger_h

#include "_garnet.h"


#define     GARNET_LOG_DOMAIN       ((gchar* )0)


extern  const gchar*    g_log_domain_garnet;
extern  const gchar*    g_log_domain_garnet_module;


typedef enum {
    /* log flags */
    LOG_FLAG_RECURSION      = 1 << 0,
    LOG_FLAG_FATAL          = 1 << 1,

    /* log levels */
    LOG_FLAG_ERROR          = 1 << 2,
    LOG_FLAG_CRITICAL       = 1 << 3,
    LOG_FLAG_WARNING        = 1 << 4,
    LOG_FLAG_MESSAGE        = 1 << 5,
    LOG_FLAG_INFO           = 1 << 6,
    LOG_FLAG_DEBUG          = 1 << 7,

    LOG_FLAG_MASK           = ~(LOG_FLAG_RECURSION | LOG_FLAG_FATAL)
} LogLevelFlags;


typedef     void    (*g_log_functor)( const gchar*      lor_domain,
                                      LogLevelFlags     lor_level,
                                      const gchar*      message,
                                      VALUE             user_data
                                      );


/**
 * メッセージを表示します。
 * @since 2010-09-14T14:48:14+0900
 */
void g_log( const gchar*    lor_domain,
            LogLevelFlags   lor_level,
            const gchar*    format,
            ...
            );


/**
 * メッセージを表示します。
 * @since 2010-09-14T14:48:26+0900
 */
void g_logv( const gchar*   lor_domain,
             LogLevelFlags  lor_level,
             const gchar*   format,
             va_list        args
             );


#if defined(_DEBUG) || defined(DEBUG) || defined(GARNET_DEBUG_LEVEL)
#   if defined(_STDC_VERSION) || defined(_MSC_VER)
#       define     g_message(format, ...)       g_log( GARNET_LOG_DOMAIN, LOG_FLAG_MESSAGE, format, ##__VA_ARGS__ )
#       define     g_warning(format, ...)       g_log( GARNET_LOG_DOMAIN, LOG_FLAG_WARNING, format, ##__VA_ARGS__ )
#       define     g_critical(format, ...)      g_log( GARNET_LOG_DOMAIN, LOG_FLAG_CRITICAL, format, ##__VA_ARGS__ )
#       define     g_error(format, ...)         g_log( GARNET_LOG_DOMAIN, LOG_FLAG_ERROR, format, ##__VA_ARGS__ )
#       define     g_debug(format, ...)         g_log( GARNET_LOG_DOMAIN, LOG_FLAG_DEBUG, format, ##__VA_ARGS__ )
#       define     g_info(format, ...)          g_log( GARNET_LOG_DOMAIN, LOG_FLAG_INFO, format, ##__VA_ARGS__ )
#   else
void g_message(const gchar* format, ...);
void g_warning(const gchar* format, ...);
void g_critical(const gchar* format, ...);
void g_error(const gchar* format, ...);
void g_info(const gchar* format, ...);
#   endif  /* defined(_STDC_VERSION) || defined(_MSC_VER) */
#else
#   define     g_message(format, ...)
#   define     g_warning(format, ...)
#   define     g_critical(format, ...)
#   define     g_error(format, ...)
#   define     g_debug(format, ...)
#   define     g_info(format, ...)
#endif  /* defined(_DEBUG) || defined(DEBUG) || defined(GARNET_DEBUG_LEVEL) */


///**
// * ログ書き込みハンドラーを設定します。
// * @since 2010-09-14T14:45:31+0900
// */
//uint32_t g_log_set_handler( const gchar*    lor_domain,
//                            LogLevelFlags   lor_levels,
//                            g_log_functor   lor_func,
//                            VALUE       user_data
//                            );
//
//
///**
// * @since 2010-09-14T14:45:40+0900
// */
//void g_log_remove_handler( const gchar*     lor_domain,
//                           uint32_t         hundler_id
//                           );


/**
 * @since 2010-09-14T14:45:58+0900
 */
void g_log_default_handler( const gchar*    lor_domain,
                            LogLevelFlags   lor_level,
                            const gchar*    message,
                            VALUE           user_data
                            );


#endif  /* garnet_glogger_h */
