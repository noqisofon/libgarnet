#include <stdafx.h>

#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <tchar.h>

#include <garnet/glogger.h>


const gchar*            g_log_domain_garnet         = "garnet";
const gchar*            g_log_domain_garnet_module  = "garnet.module";


static g_log_functor    local_log_func              = g_log_default_handler;


void g_log( const gchar*    log_domain,
            LogLevelFlags   log_level,
            const gchar*    format,
            ...
            )
{
    va_list     arguments;
    va_start( arguments, format );

    g_logv( log_domain, log_level, format, arguments );

    va_end( arguments );
}


#define     MESSAGE_BUFFER_LENGTH       1024 * 2
void g_logv( const gchar*    log_domain,
             LogLevelFlags   log_level,
             const gchar*    format,
             va_list         arguments
             )
{
    gchar        message_buffer[MESSAGE_BUFFER_LENGTH];

    _vstprintf( message_buffer, format, arguments );

    local_log_func( log_domain, log_level, message_buffer, NULL );
}


#if !defined(_STDC_VERSION) && !defined(_MSC_VER)
void g_message(const gchar* format, ...)
{
    va_list     arguments;
    va_start( arguments, format );

    g_logv( GARNET_LOG_DOMAIN, LOG_FLAG_MESSAGE, format, arguments );

    va_end( arguments );
}


void g_warning(const gchar* format, ...)
{
    va_list     arguments;
    va_start( arguments, format );

    g_logv( GARNET_LOG_DOMAIN, LOG_FLAG_WARNING, format, arguments );

    va_end( arguments );
}


void g_critical(const gchar* format, ...)
{
    va_list     arguments;
    va_start( arguments, format );

    g_logv( GARNET_LOG_DOMAIN, LOG_FLAG_CRITICAL, format, arguments );

    va_end( arguments );
}


void g_error(const gchar* format, ...)
{
    va_list     arguments;
    va_start( arguments, format );

    g_logv( GARNET_LOG_DOMAIN, LOG_FLAG_ERROR, format, arguments );

    va_end( arguments );
}


void g_info(const gchar* format, ...)
{
    va_list     arguments;
    va_start( arguments, format );

    g_logv( GARNET_LOG_DOMAIN, LOG_FLAG_INFO, format, arguments );

    va_end( arguments );
}
#endif  /* !defined(_STDC_VERSION) && !defined(_MSC_VER) */


guint g_log_set_handler( const gchar*    log_domain,
                            LogLevelFlags   log_levels,
                            g_log_functor   log_func,
                            VALUE           useg_data
                            )
{
    return 0;
}


void g_log_remove_handler( const gchar*     log_domain,
                           guint         hundleg_id
                           )
{
}


/**
 * @since 2010-09-14
 */
static const char* log_level_filter(LogLevelFlags log_level)
{
    switch ( log_level ) {
     case LOG_FLAG_FATAL:
        return "FATAL";

     case LOG_FLAG_ERROR:
        return "ERROR";

     case LOG_FLAG_CRITICAL:
        return "CRITICAL";

     case LOG_FLAG_WARNING:
        return "WARNING";

     case LOG_FLAG_MESSAGE:
        return "MESSAGE";

     case LOG_FLAG_INFO:
        return "INFO";

     case LOG_FLAG_DEBUG:
        return "DEBUG";

     default:
        return "";
    }
}


void g_log_default_handler( const gchar*    log_domain,
                            LogLevelFlags   log_level,
                            const gchar*    message,
                            VALUE           useg_data
                            )
{
    FILE*           output;
    time_t          timer;
#ifndef _MSC_VER
    struct tm*      timestamp;
#else
    struct tm       timestamp;
#endif  /* ndef _MSC_VER */
    char            timestamp_buffer[26];
#ifndef _MSC_VER
    output  = _tfopen( "stdout.txt", "a" );
#else
    _tfopen_s( &output, "stdout.txt", "a" );
#endif  /* def _MSC_VER */

    if ( output != NULL ) {
        timer       = time( NULL );
#ifndef _MSC_VER
        timestamp   = localtime( &timer );
        _tcsftime( timestamp_buffer, 26, _T("%Y-%m-%dT%H:%M:%S"), timestamp );
#else
        localtime_s( &timestamp, &timer );
        _tcsftime( timestamp_buffer, 26, _T("%Y-%m-%dT%H:%M:%S"), &timestamp );
#endif  /* ndef _MSC_VER */

        fprintf( output,
                 "%s [%s] %s\n",
                 timestamp_buffer,
                 log_level_filter( log_level ),
                 message
                 );

        fclose( output );
    }
}
