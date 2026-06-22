#include "logger.h"

static void Log(
    loglevel level,
    const char *fmt,
    va_list args)
{
    time_t t = time(NULL);
    struct tm *local_time = localtime(&t);

    char message[BUFFER_SIZE];

    vsnprintf(message, sizeof(message), fmt, args);

    char time_header[TIME_HEADER_SIZE];

    sprintf(
        time_header,
        "%04d/%02d/%02d %02d:%02d:%02d: - ",
        local_time->tm_year + 1900,
        local_time->tm_mon + 1,
        local_time->tm_mday,
        local_time->tm_hour,
        local_time->tm_min,
        local_time->tm_sec);

    switch (level)
    {
    case DEBUG:
        printf("%s[%sDBG%s]: %s\n", time_header, CYAN_COLOR, WHITE_COLOR, message);
        break;

    case INFO:
        printf("%s[%sINF%s]: %s\n", time_header, GREEN_COLOR, WHITE_COLOR, message);
        break;

    case WARN:
        printf("%s[%sWRN%s]: %s\n", time_header, YELLOW_COLOR, WHITE_COLOR, message);
        break;

    case ERROR:
        printf("%s[%sERR%s]: %s\n", time_header, RED_COLOR, WHITE_COLOR, message);
        break;

    default:
        printf("%s\n", time_header);
        break;
    }
}

void err(
    const char *fmt,
    ...)
{
    va_list args;
    va_start(args, fmt);
    Log(ERROR, fmt, args);
    va_end(args);
}

void debug(
    const char *fmt,
    ...)
{
    va_list args;
    va_start(args, fmt);
    Log(DEBUG, fmt, args);
    va_end(args);
}

void warn(
    const char *fmt,
    ...)
{
    va_list args;
    va_start(args, fmt);
    Log(WARN, fmt, args);
    va_end(args);
}

void info(
    const char *fmt,
    ...)
{
    va_list args;
    va_start(args, fmt);
    Log(INFO, fmt, args);
    va_end(args);
}
