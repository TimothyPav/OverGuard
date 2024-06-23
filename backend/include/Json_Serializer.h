#ifndef JSON_SERIALIZER_H
#define JSON_SERIALIZER_H

#include "Heroes.h"
#include "API_Handler.h"

#include <nlohmann/json.hpp>
#include <vector>

nlohmann::json serialize_player_input(std::string player_id);
nlohmann::json serialize_specific_hero_stat(std::string hero_name, std::string column);

#endif