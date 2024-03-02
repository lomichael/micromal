#include "../utils/log.h"

void log_message(LogLevel level, const char *message)
{
    switch (level)
    {
    case LOG_DEBUG:
        printf("[DEBUG] %s\n", message);
        break;
    case LOG_INFO:
        printf("[INFO] %s\n", message);
        break;
    case LOG_WARNING:
        printf("[WARNING] %s\n", message);
        break;
    case LOG_ERROR:
        printf("[ERROR] %s\n", message);
        break;
    }
}