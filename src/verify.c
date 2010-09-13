#include <stdio.h>
#include <stdarg.h>

#include "verify.h"


const char*     g_verify_domain_garnet          = "garnet";
const char*     g_verify_domain_garnet_module   = "garnet_module";


static      verify_log_func     local_log_func  = verify_default_handler;


void verify_log( const _TCHAR*  log_domain,
                 LogLevelFlags  log_level,
                 const _TCHAR*  format,
                 ...
                 )
{
    va_list     arguments;
    va_start( arguments, format );
    verify_log( log_domain, log_level, format, arguments );
    va_end( arguments );
}
void verify_log( const _TCHAR*  log_domain,
                 LogLevelFlags  log_level,
                 const _TCHAR*  format,
                 va_list        arguments
                 )
{
    _TCHAR        message_buffer[1024 * 2];
    _vstprintf( message_buffer, format, arguments );

    local_log_func( log_domain, log_level, message_buffer, NULL );
}


#ifndef __C99
void verify_message(const _TCHAR* format, ...)
{
    va_list     arguments;
    va_start( arguments, format );

    verify_log( VERIFY_LOG_DOMAIN, LOG_FLAG_MESSAGE, format, arguments );

    va_end( arguments );
}


void verify_warning(const _TCHAR* format, ...)
{
    va_list     arguments;
    va_start( arguments, format );

    verify_log( VERIFY_LOG_DOMAIN, LOG_FLAG_WARNING, format, arguments );

    va_end( arguments );
}


void verify_critical(const _TCHAR* format, ...)
{
    va_list     arguments;
    va_start( arguments, format );

    verify_log( VERIFY_LOG_DOMAIN, LOG_FLAG_CRITICAL, format, arguments );

    va_end( arguments );
}


void verify_error(const _TCHAR* format, ...)
{
    va_list     arguments;
    va_start( arguments, format );

    verify_log( VERIFY_LOG_DOMAIN, LOG_FLAG_ERROR, format, arguments );

    va_end( arguments );
}


void verify_info(const _TCHAR* format, ...)
{
    va_list     arguments;
    va_start( arguments, format );

    verify_log( VERIFY_LOG_DOMAIN, LOG_FLAG_INFO, format, arguments );

    va_end( arguments );
}
#endif  /* def __C99 */


void verify_default_handler( const _TCHAR*   log_domain,
                             LogLevelFlags   log_level,
                             const _TCHAR*   message,
                             variant_t       user_data
                             )
{
    fprintf( stderr, " %s\n", message );
}
