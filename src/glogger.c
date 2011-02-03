/* -*- encoding: utf-8; -*- */
/**
 * @file glogger.c
 * @since %create-timestamp%
 * 
 */
/*
    Copyright (c) %year% %full-author% %author-email%

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

    $Id glogger.c %timestamp% %author% $
 */
#include <stdafx.h>

#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <tchar.h>

#include <garnet/glogger.h>


const gchar*            g_log_domain_garnet         = "garnet";
const gchar*            g_log_domain_garnet_module  = "garnet.module";


static const char* log_level_filter(LogLevelFlags log_level);


static g_log_functor    local_log_func              = g_log_default_handler;


void GARNET_API g_log( const gchar*    log_domain,
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
void GARNET_API g_logv( const gchar*    log_domain,
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
void GARNET_API g_message(const gchar* format, ...)
{
    va_list     arguments;
    va_start( arguments, format );

    g_logv( GARNET_LOG_DOMAIN, LOG_FLAG_MESSAGE, format, arguments );

    va_end( arguments );
}


void GARNET_API g_warning(const gchar* format, ...)
{
    va_list     arguments;
    va_start( arguments, format );

    g_logv( GARNET_LOG_DOMAIN, LOG_FLAG_WARNING, format, arguments );

    va_end( arguments );
}


void GARNET_API g_critical(const gchar* format, ...)
{
    va_list     arguments;
    va_start( arguments, format );

    g_logv( GARNET_LOG_DOMAIN, LOG_FLAG_CRITICAL, format, arguments );

    va_end( arguments );
}


void GARNET_API g_error(const gchar* format, ...)
{
    va_list     arguments;
    va_start( arguments, format );

    g_logv( GARNET_LOG_DOMAIN, LOG_FLAG_ERROR, format, arguments );

    va_end( arguments );
}


void GARNET_API g_info(const gchar* format, ...)
{
    va_list     arguments;
    va_start( arguments, format );

    g_logv( GARNET_LOG_DOMAIN, LOG_FLAG_INFO, format, arguments );

    va_end( arguments );
}
#endif  /* !defined(_STDC_VERSION) && !defined(_MSC_VER) */


guint GARNET_API g_log_set_handler( const gchar*    log_domain,
                                    LogLevelFlags   log_levels,
                                    g_log_functor   log_func,
                                    VALUE           useg_data
                                    )
{
    return 0;
}


void GARNET_API g_log_remove_handler( const gchar*     log_domain,
                                      guint         hundleg_id
                                      )
{
}


void GARNET_API g_log_default_handler( const gchar*    log_domain,
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
