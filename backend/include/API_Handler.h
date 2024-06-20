#ifndef API_HANDLER_H
#define API_HANDLER_H

#include "Heroes.h"

#include <iostream>
#include <string>
#include <map>
#include <variant>

using StatsMap = std::map<std::string, std::variant<int, double>>;

void get_stats(const std::string& blizzard_ID);
std::string get_name_from_blizzard_ID(const std::string& blizzard_ID);
std::string get_blizzard_ID_from_name(const std::string name);

#endif