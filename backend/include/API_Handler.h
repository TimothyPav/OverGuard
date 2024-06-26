#ifndef API_HANDLER_H
#define API_HANDLER_H

#include "Heroes.h"
#include "Database_Operations.h"

#include <iostream>
#include <string>
#include <map>
#include <variant>
#include <array>
#include <memory>
#include <optional>

using StatsMap = std::map<std::string, std::variant<int, double>>;

std::optional<std::array<std::unique_ptr<Heroes>, 7>> get_stats(const std::string &blizzard_ID, const bool store_in_database);
std::string get_name_from_blizzard_ID(const std::string& blizzard_ID);
std::string get_blizzard_ID_from_name(const std::string name);

#endif