#ifndef DATABASE_OPERATIONS_H
#define DATABASE_OPERATIONS_H

#include "Heroes.h"

#include <string>

int create_table();
int load_players_into_playersDatabase();
int insert_stats_into_asheDatabase(std::string blizzard_ID, Heroes& ashe);
int insert_hero_into_database(std::string blizzard_ID, Heroes& hero);

#endif