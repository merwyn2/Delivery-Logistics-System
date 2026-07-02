#pragma once

#include <string>

#include "Order.h"

std::string statusToString(Status status);

Status stringToStatus(const std::string& status);