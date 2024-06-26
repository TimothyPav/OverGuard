#ifndef DATABASE_OPERATIONS_H
#define DATABASE_OPERATIONS_H

#include "Heroes.h"

#include <string>
#include <map>
#include <variant>

int create_table();
int load_players_into_playersDatabase(std::string blizzard_ID);

std::unordered_map<std::string, std::variant<int, double>> get_column(const std::string hero_name, const std::string column);

int loop_over_blizzard_ID();
int insert_hero_into_database(std::string blizzard_ID, Heroes& hero);
std::string select_name_from_blizzard_ID_from_database(std::string blizzard_ID);

int insert_stats_into_asheDatabase(std::string blizzard_ID, Heroes& ashe);
int insert_stats_into_cassidyDatabase(std::string blizzard_ID, Heroes& ashe);
int insert_stats_into_hanzoDatabase(std::string blizzard_ID, Heroes& hanzo);
int insert_stats_into_sojournDatabase(std::string blizzard_ID, Heroes& sojourn);
int insert_stats_into_soldier76Database(std::string blizzard_ID, Heroes& soldier76);
int insert_stats_into_tracerDatabase(std::string blizzard_ID, Heroes& tracer);
int insert_stats_into_widowmakerDatabase(std::string blizzard_ID, Heroes& widowmaker);

#endif