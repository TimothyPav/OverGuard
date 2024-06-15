#ifndef API_HANDLER_H
#define API_HANDLER_H

#include <iostream>
#include <string>
#include <map>
#include <variant>

using StatsMap = std::map<std::string, std::variant<int, double>>;

StatsMap get_stats();

std::string get_name_from_blizzard_ID(const std::string& blizzard_ID);

#endif