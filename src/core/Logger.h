#pragma once

#include "implementations/Logger/LoggerImpl.h"

extern LoggerImpl *g_logger;

inline LoggerImpl &Log(LogType type) {
    return *g_logger;
}

#define Log(type) if (g_logger != nullptr) g_logger->log(type, __PRETTY_FUNCTION__)



