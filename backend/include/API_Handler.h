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

/**
 * @brief calls the overfast api for a specific player
 * 
 * Calls the api for the associated blizzard_ID and parses the json and stores the results in an array of pointers to be used and stored in Database_Operations.h
 * 
 * @param blizzard_ID ID of player being called to the API
 * @param store_in_database a value to set whether a player will be stored in the db. Useful for the compare stats feature in the live version.
 * 
 * @return array of pointers all pointing to every single hero so 7 pointers in total
*/
std::optional<std::array<std::unique_ptr<Heroes>, 7>> get_stats(const std::string &blizzard_ID, const bool store_in_database);


/**
 * @brief calls the api to get a name of a player
 * 
 * Calls the api to check against a blizzard_ID to find the name of a player
 * 
 * @param blizzard_ID ID of player being called to the API
 * 
 * @return the name of the player if found
*/
std::string get_name_from_blizzard_ID(const std::string& blizzard_ID);


/**
 * @brief calls the overfast api for a battletag
 * 
 * Loops through all matches of a name to check for a player of high enough rank that matches the name passed in. Not perfect but useful for populating db with high rank players
 * 
 * @param name name of player you want to find
 * 
 * @return the battletag of the player if found
*/
std::string get_blizzard_ID_from_name(const std::string name);

#endif