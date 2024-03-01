#ifndef LOG_H
#define LOG_H

#include <stdio.h>

typedef enum
{
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
} LogLevel;

void log_message(LogLevel level, const char *message);

#endif // LOG_H