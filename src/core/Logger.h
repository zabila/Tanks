#pragma once

#include "implementations/Logger/LoggerImpl.h"

#define Log(type) if (g_logger != nullptr) g_logger->log(type, __PRETTY_FUNCTION__)



