#ifndef DATABASE_OPERATIONS_H
#define DATABASE_OPERATIONS_H

#include "Heroes.h"

#include <string>
#include <map>
#include <variant>

/**
 * @brief Creates a new .db file
 * 
 * Creates a .db file with a hardcoded schema
 * 
 * @param 
 * 
 * @return int/status code for sql 
*/
int create_table();

/**
 * @brief fills the players.db
 * 
 * Uses a blizzard ID to get the respective name of the ID and puts both values inside the database
 * 
 * @param blizzard_ID blizzard ID assocoiated with the player THIS IS NOT THE BATTLE TAG!!
 * 
 * @return int/status code for sql
*/
int load_players_into_playersDatabase(std::string blizzard_ID);

/**
 * @brief gets one stat of a specified hero
 * 
 * Looks through the associated hero database and looks for a column then returns a map with keys=player names and values=stats
 * 
 * @param hero_name string of 1 of 7 heroes this program supports
 * @param column the name of the stat inside the databases
 * 
 * @return unordered_map filled with key=player value=stat/column_of_player
*/
std::unordered_map<std::string, std::variant<int, double>> get_column(const std::string hero_name, const std::string column);

/**
 * @brief fills hero tables with stats from the players table
 * 
 * Loops over the players.db table and uses a seperate function defined in API_Handler.h (get_stats) to populate all hero tables. 1 player can have stats for multiple heroes
 * 
 * @param
 * 
 * @return int/status code for sql 
*/
int loop_over_blizzard_ID();

/**
 * @brief a poorly written function that calls the appropriate function depending on what kind of object was passed in from the parameters
 * 
 * Uses the hero.get_name() method to decide which function to call insert into the appropriate database
 * 
 * @param blizzard_ID ID of player
 * @param hero hero sublass guaranteed to be one of the seven heroes defined in Heroes.h
 * 
 * @return 0
*/
int insert_hero_into_database(std::string blizzard_ID, Heroes& hero);

/**
 * @brief return the name with the associated blizzard ID
 * 
 * Look into players.db to try to find a name in the same row as the blizzard_ID
 * 
 * @param blizzard_ID ID to look for in players.db
 * 
 * @return 
*/
std::string select_name_from_blizzard_ID_from_database(std::string blizzard_ID);

/**
 * @brief insert associated stats one of the heroes tables
 * 
 * insert stats into associated db but every hero has hero specific stats so it is important to call the right one
 * 
 * @param blizzard_ID used as a foreign key to players.db
 * @param hero any type of hero but insert_hero_into_database ensures the correct sub class of hero
 * 
 * @return int/status of sql
*/
int insert_stats_into_asheDatabase(std::string blizzard_ID, Heroes& ashe);
int insert_stats_into_cassidyDatabase(std::string blizzard_ID, Heroes& cassidy);
int insert_stats_into_hanzoDatabase(std::string blizzard_ID, Heroes& hanzo);
int insert_stats_into_sojournDatabase(std::string blizzard_ID, Heroes& sojourn);
int insert_stats_into_soldier76Database(std::string blizzard_ID, Heroes& soldier76);
int insert_stats_into_tracerDatabase(std::string blizzard_ID, Heroes& tracer);
int insert_stats_into_widowmakerDatabase(std::string blizzard_ID, Heroes& widowmaker);

#endif