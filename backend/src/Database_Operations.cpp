#include "Database_Operations.h"
#include "API_Handler.h"
#include "Heroes.h"

#include <iostream>
#include <sqlite3.h>
#include <string>
#include <chrono>
#include <thread>
#include <fstream>

bool sql_open_check(int return_code, sqlite3 *db);
bool sql_prepare_check(int return_code, sqlite3 *db);
bool sql_step_check(int return_code, sqlite3 *db);

int load_players_into_playersDatabase()
{
    std::ifstream inputFile("../databases/player_ids.txt");

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening the file!" << std::endl;
        return 1;
    }

    sqlite3 *players_db;
    char *error_message = 0;
    sqlite3_stmt *stmt;

    int return_code = sqlite3_open("../databases/players.db", &players_db);
    if (!sql_open_check(return_code, players_db))
        return 1;

    // sql command
    const char *sql_insert = "INSERT INTO players (Name, Blizzard_ID) VALUES (?, ?);";
    return_code = sqlite3_prepare_v2(players_db, sql_insert, -1, &stmt, NULL);
    if (!sql_prepare_check(return_code, players_db))
        return 1;

    std::string line; // variable to store each line
    while (getline(inputFile, line))
    {
        std::string name = get_name_from_blizzard_ID(line);
        if (name.size() > 0)
        {
            sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 2, line.c_str(), -1, SQLITE_TRANSIENT);

            return_code = sqlite3_step(stmt);
            sql_step_check(return_code, players_db);
        }

        sqlite3_reset(stmt);
    }

    // Close the file
    inputFile.close();
    sqlite3_finalize(stmt);
    sqlite3_close(players_db);
    return 0;
}

std::string select_name_from_blizzard_ID_from_database(std::string blizzard_ID)
{
    sqlite3 *players_db;
    char *error_message = 0;
    sqlite3_stmt *stmt;

    int return_code = sqlite3_open("../databases/players.db", &players_db);
    if (!sql_open_check(return_code, players_db))
        return "";

    const char *sql_select = "SELECT Name FROM players WHERE Blizzard_ID = ?;";

    return_code = sqlite3_prepare_v2(players_db, sql_select, -1, &stmt, nullptr);
    sql_prepare_check(return_code, players_db);

    sqlite3_bind_text(stmt, 1, blizzard_ID.c_str(), -1, SQLITE_TRANSIENT);
    return_code = sqlite3_step(stmt);
    sql_step_check(return_code, players_db);
    std::string player_name = "";
    if (return_code == SQLITE_ROW)
    {
        const unsigned char *name = sqlite3_column_text(stmt, 0);
        if (name)
        {
            player_name = reinterpret_cast<const char *>(name);
        }
    }
    else
    {
        std::cerr << "Player not found." << std::endl;
    }

    sqlite3_finalize(stmt);
    return player_name;
}

int insert_hero_into_database(std::string blizzard_ID, Heroes &hero)
{
    if (hero.get_hero_name() == "ashe")
        insert_stats_into_asheDatabase(blizzard_ID, hero);
    else if (hero.get_hero_name() == "cassidy")
        insert_stats_into_cassidyDatabase(blizzard_ID, hero);
    else if (hero.get_hero_name() == "hanzo")
        insert_stats_into_hanzoDatabase(blizzard_ID, hero);
    else if (hero.get_hero_name() == "sojourn")
        insert_stats_into_sojournDatabase(blizzard_ID, hero);
    else if (hero.get_hero_name() == "soldier-76")
        insert_stats_into_soldier76Database(blizzard_ID, hero);
    else if (hero.get_hero_name() == "tracer")
        insert_stats_into_tracerDatabase(blizzard_ID, hero);
    else if (hero.get_hero_name() == "widowmaker")
        insert_stats_into_widowmakerDatabase(blizzard_ID, hero);
    return 0;
}

int insert_stats_into_asheDatabase(std::string blizzard_ID, Heroes &ashe)
{
    sqlite3 *ashe_db;
    char *error_message = 0;
    sqlite3_stmt *stmt;

    int return_code = sqlite3_open("../databases/ashe.db", &ashe_db);
    if (return_code)
    {
        std::cerr << "Error opening database: " << sqlite3_errmsg(ashe_db) << std::endl;
        return 1;
    }
    // sql command
    const char *sql_insert = "INSERT INTO ashe (Blizzard_ID, Name, Deaths per 10 mins, Final Blows per 10 mins, Hero Damage Done per 10 mins, Scoped Accuracy, Scoped Crit Hits per 10 mins, Scoped Crit Kills per 10 mins) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?);";
    return_code = sqlite3_prepare_v2(ashe_db, sql_insert, -1, &stmt, NULL);
    if (return_code != SQLITE_OK)
    {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(ashe_db) << std::endl;
        sqlite3_close(ashe_db);
        return 1;
    }

    // bind blizzard_ID, name, and all stats to be inserted into the database

    return 0;
}

int insert_stats_into_cassidyDatabase(std::string blizzard_ID, Heroes &cassidy)
{
    cassidy.printStats();
    return 0;
}

int insert_stats_into_hanzoDatabase(std::string blizzard_ID, Heroes &hanzo)
{
    hanzo.printStats();
    return 0;
}

int insert_stats_into_sojournDatabase(std::string blizzard_ID, Heroes &sojourn)
{
    sojourn.printStats();
    return 0;
}

int insert_stats_into_soldier76Database(std::string blizzard_ID, Heroes &soldier76)
{
    soldier76.printStats();
    return 0;
}

int insert_stats_into_tracerDatabase(std::string blizzard_ID, Heroes &tracer)
{
    tracer.printStats();
    return 0;
}

int insert_stats_into_widowmakerDatabase(std::string blizzard_ID, Heroes &widowmaker)
{
    widowmaker.printStats();
    return 0;
}

int create_table()
{
    sqlite3 *DB;
    int exit = 0;

    exit = sqlite3_open("../databases/tracer.db", &DB);

    if (exit)
    {
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
        return (-1);
    }
    else
        std::cout << "Opened Database Successfully!" << std::endl;

    const char *sqlCreateTable = R"(
    CREATE TABLE IF NOT EXISTS "tracer" (
        "Entry" INTEGER NOT NULL UNIQUE,
        "Blizzard_ID"   TEXT NOT NULL,
        "Name"  TEXT NOT NULL,
        "Deaths per 10 mins"    REAL NOT NULL,
        "Final Blows per 10 mins"       REAL NOT NULL,
        "Solo Kills per 10 mins"        REAL NOT NULL,
        "Hero Damage Done per 10 mins"  REAL NOT NULL,
        "Critical Hits per 10 mins"     REAL,
        FOREIGN KEY("Blizzard_ID") REFERENCES "players"("Blizzard_ID"),
        FOREIGN KEY("Name") REFERENCES "players"("Name"),
        PRIMARY KEY("Entry" AUTOINCREMENT)
);)";

    char *errMsg;
    exit = sqlite3_exec(DB, sqlCreateTable, 0, 0, &errMsg);
    if (exit != SQLITE_OK)
    {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    sqlite3_close(DB);
    return (0);
}

bool sql_open_check(int return_code, sqlite3 *db)
{
    if (return_code)
    {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    return true;
}

bool sql_prepare_check(int return_code, sqlite3 *db)
{
    if (return_code != SQLITE_OK)
    {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    return true;
}

bool sql_step_check(int return_code, sqlite3 *db) {
    if (return_code != SQLITE_ROW && return_code != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    return true;
}
