#ifndef JSON_SERIALIZER_H
#define JSON_SERIALIZER_H

#include "Heroes.h"
#include "API_Handler.h"

#include <nlohmann/json.hpp>
#include <vector>

/**
 * @brief uses get_stats in API_Handler to get the stats of a player
 * 
 * uses get_stats in API_Handler to look for the stats of the player and turns into organized json to be passed to the frontend
 * 
 * @param player_id battletag of the player
 * 
 * @return json organized data of the player input
*/
nlohmann::json serialize_player_input(std::string player_id);


/**
 * @brief gets one column of one hero
 * 
 * Calls the get_column in Database_Operations.h and transforms that output into json which can be read by the frontend
 * 
 * @param hero_name name of hero database that will be looked into
 * @param column name of column that stats will be returned from
 * 
 * @return json organized data of a specific hero and keys of player names and values of stats from the column
*/
nlohmann::json serialize_specific_hero_stat(std::string hero_name, std::string column);

#endif