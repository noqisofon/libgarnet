#ifndef VERIFY_H
#define VERIFY_H

#include <stdint.h>
#include <tchar.h>
#include <stdarg.h>

typedef     void*      variant_t;


#define     VERIFY_LOG_DOMAIN       ((char* )0)


extern  const char*     g_verify_domain_garnet;
extern  const char*     g_verify_domain_garnet_module;


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


typedef     void    (*verify_log_func)( const _TCHAR*   log_domain,
                                        LogLevelFlags   log_level,
                                        const _TCHAR*   message,
                                        variant_t       user_data
                                        );


/**
 * メッセージを表示して abort() します。
 */
void verify_log( const _TCHAR*  log_domain,
                 LogLevelFlags  log_level,
                 const _TCHAR*  format,
                 ...
                 );


void verify_logv( const _TCHAR*  log_domain,
                  LogLevelFlags  log_level,
                  const _TCHAR*  format,
                  va_list        args
                  );


#if defined(_DEBUG) || defined(DEBUG)
#   ifdef __C99
#       define     verify_message(format, ...)       verify_log( VERIFY_LOG_DOMAIN, LOG_FLAG_MESSAGE, format, ##__VA_ARGS__ )
#       define     verify_warning(format, ...)       verify_log( VERIFY_LOG_DOMAIN, LOG_FLAG_WARNING, format, ##__VA_ARGS__ )
#       define     verify_critical(format, ...)      verify_log( VERIFY_LOG_DOMAIN, LOG_FLAG_CRITICAL, format, ##__VA_ARGS__ )
#       define     verify_error(format, ...)         verify_log( VERIFY_LOG_DOMAIN, LOG_FLAG_ERROR, format, ##__VA_ARGS__ )
#       define     verify_debug(format, ...)         verify_log( VERIFY_LOG_DOMAIN, LOG_FLAG_DEBUG, format, ##__VA_ARGS__ )
#       define     verify_info(format, ...)          verify_log( VERIFY_LOG_DOMAIN, LOG_FLAG_INFO, format, ##__VA_ARGS__ )
#   else
void verify_message(const _TCHAR* format, ...);
void verify_warning(const _TCHAR* format, ...);
void verify_critical(const _TCHAR* format, ...);
void verify_error(const _TCHAR* format, ...);
void verify_info(const _TCHAR* format, ...);
#   endif  /* def __C99 */
#else
#   define     verify_message(format, ...)
#   define     verify_warning(format, ...)
#   define     verify_critical(format, ...)
#   define     verify_error(format, ...)
#   define     verify_debug(format, ...)
#   define     verify_info(format, ...)
#endif  /* defined(_DEBUG) || defined(DEBUG) */


uint32_t verify_set_handler( const _TCHAR*      log_domain,
                             LogLevelFlags      log_levels,
                             verify_log_func    log_func,
                             variant_t          user_data
                             );


void verify_remove_handler( const _TCHAR*       log_domain,
                            uint32_t            hundler_id
                            );


void verify_default_handler( const _TCHAR*   log_domain,
                             LogLevelFlags   log_level,
                             const _TCHAR*   message,
                             variant_t       user_data
                             );


#endif  /* VERIFY_H */
