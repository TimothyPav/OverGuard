#include "Database_Operations.h"
#include "API_Handler.h"
#include "Heroes.h"

#include <iostream>
#include <sqlite3.h>
#include <string>
#include <chrono>
#include <thread>
#include <fstream>
#include <map>
#include <utility>

bool sql_open_check(int return_code, sqlite3 *db);
bool sql_prepare_check(int return_code, sqlite3 *db);
bool sql_step_check(int return_code, sqlite3 *db);

std::unordered_map<std::string, std::variant<int, double>> get_column(const std::string hero_name, const std::string column)
{
    sqlite3 *hero_db;
    std::string db_path = std::string("../databases/" + hero_name + ".db");
    int return_code = sqlite3_open(db_path.c_str(), &hero_db);
    if (!sql_open_check(return_code, hero_db))
        return {};

    const std::string sql_select = "SELECT \"" + column + "\",Name FROM " + hero_name;
    // const std::string sql_select = "SELECT Solo Kills per 10 mins, Name FROM widowmaker";
    sqlite3_stmt *stmt;
    return_code = sqlite3_prepare_v2(hero_db, sql_select.c_str(), -1, &stmt, NULL);
    if (!sql_prepare_check(return_code, hero_db))
        return {};

    std::unordered_map<std::string, std::variant<int, double>> stat_map;
    std::variant<int, double> stat;
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int type = sqlite3_column_type(stmt, 0);
        if (type == SQLITE_INTEGER)
            stat = sqlite3_column_int(stmt, 0);
        else
            stat = sqlite3_column_double(stmt, 0);
        const char *name = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
        stat_map[column] = stat;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(hero_db);
    return stat_map;
}

int loop_over_blizzard_ID()
{
    sqlite3 *players_db;
    sqlite3_open("../databases/players.db", &players_db);

    const char *sql_select = "SELECT Blizzard_ID FROM players;";
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(players_db, sql_select, -1, &stmt, NULL);
    if (!sql_prepare_check)
        return 1;

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        std::string blizzard_ID = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
        std::string name = select_name_from_blizzard_ID_from_database(blizzard_ID);

        get_stats(blizzard_ID, true);
        std::cout << "INSERTED!!: " << name << " : " << blizzard_ID << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(players_db);
    return 0;
}

int load_players_into_playersDatabase(std::string blizzard_ID)
{
    sqlite3 *players_db;
    char *error_message = 0;
    sqlite3_stmt *stmt;

    int return_code = sqlite3_open("../databases/players.db", &players_db);
    if (!sql_open_check(return_code, players_db))
        return 1;

    // sql command
    const char *sql_insert = "INSERT INTO players (Name,Blizzard_ID) VALUES (?,?);";
    return_code = sqlite3_prepare_v2(players_db, sql_insert, -1, &stmt, NULL);
    if (!sql_prepare_check(return_code, players_db))
        return 1;

    std::string name = get_name_from_blizzard_ID(blizzard_ID);

    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, blizzard_ID.c_str(), -1, SQLITE_TRANSIENT);

    return_code = sqlite3_step(stmt);
    sql_step_check(return_code, players_db);

    // Close the file
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
    if (!sql_open_check(return_code, ashe_db))
        return 1;

    // delete old entry if new (updated) one is being insterted
    std::string sql_delete = "DELETE FROM ashe WHERE Blizzard_ID = ?";
    int delete_return_code = sqlite3_prepare_v2(ashe_db, sql_delete.c_str(), -1, &stmt, nullptr);
    if (!sql_prepare_check(delete_return_code, ashe_db))
        return 1;
    sqlite3_bind_text(stmt, 1, blizzard_ID.c_str(), -1, SQLITE_TRANSIENT);
    delete_return_code = sqlite3_step(stmt);
    sql_step_check(delete_return_code, ashe_db);
    sqlite3_reset(stmt);

    // sql command
    const char *sql_insert = "INSERT INTO ashe (\"Blizzard_ID\", \"Name\", \"Deaths per 10 mins\", \"Final Blows per 10 mins\", \"Solo Kills per 10 mins\", \"Hero Damage Done per 10 mins\", \"Scoped Accuracy\", \"Scoped Crit Accuracy\", \"Scoped Crit Hits per 10 mins\", \"Scoped Crit Kills per 10 mins\") VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?);";

    return_code = sqlite3_prepare_v2(ashe_db, sql_insert, -1, &stmt, nullptr);
    if (!sql_prepare_check(return_code, ashe_db))
        return 1;

    // loading statements
    sqlite3_bind_text(stmt, 1, blizzard_ID.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, select_name_from_blizzard_ID_from_database(blizzard_ID).c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt, 3, ashe.get_deaths_per_10_mins());
    sqlite3_bind_double(stmt, 4, ashe.get_final_blows_per_10_mins());
    sqlite3_bind_double(stmt, 5, ashe.get_solo_kills_per_10_mins());
    sqlite3_bind_double(stmt, 6, ashe.get_hero_damage_done_per_10_mins());
    sqlite3_bind_int(stmt, 7, ashe.get_scoped_accuracy());
    sqlite3_bind_int(stmt, 8, ashe.get_scoped_crit_accuracy());
    sqlite3_bind_double(stmt, 9, ashe.get_scoped_crit_hits_per_10_mins());
    sqlite3_bind_double(stmt, 10, ashe.get_scoped_crit_kills_per_10_mins());

    // execute statement
    return_code = sqlite3_step(stmt);
    sql_step_check(return_code, ashe_db);

    // finalize and close all related files
    sqlite3_finalize(stmt);
    sqlite3_close(ashe_db);
    return 0;
}

int insert_stats_into_cassidyDatabase(std::string blizzard_ID, Heroes &cassidy)
{
    sqlite3 *cassidy_db;
    char *error_message = 0;
    sqlite3_stmt *stmt;

    int return_code = sqlite3_open("../databases/cassidy.db", &cassidy_db);
    if (!sql_open_check(return_code, cassidy_db))
        return 1;

    // delete old entry if new (updated) one is being insterted
    std::string sql_delete = "DELETE FROM cassidy WHERE Blizzard_ID = ?";
    int delete_return_code = sqlite3_prepare_v2(cassidy_db, sql_delete.c_str(), -1, &stmt, nullptr);
    if (!sql_prepare_check(delete_return_code, cassidy_db))
        return 1;
    sqlite3_bind_text(stmt, 1, blizzard_ID.c_str(), -1, SQLITE_TRANSIENT);
    delete_return_code = sqlite3_step(stmt);
    sql_step_check(delete_return_code, cassidy_db);
    sqlite3_reset(stmt);

    // sql command
    const char *sql_insert = "INSERT INTO cassidy (\"Blizzard_ID\", \"Name\", \"Deaths per 10 mins\", \"Final Blows per 10 mins\", \"Solo Kills per 10 mins\", \"Hero Damage Done per 10 mins\", \"Critical Hit Accuracy\", \"Critical Hits per 10 mins\", \"Critical Hit kills per 10 mins\") VALUES (?,?,?,?,?,?,?,?,?);";
    return_code = sqlite3_prepare_v2(cassidy_db, sql_insert, -1, &stmt, nullptr);
    if (!sql_prepare_check(return_code, cassidy_db))
        return 1;

    // loading statements
    sqlite3_bind_text(stmt, 1, blizzard_ID.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, select_name_from_blizzard_ID_from_database(blizzard_ID).c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt, 3, cassidy.get_deaths_per_10_mins());
    sqlite3_bind_double(stmt, 4, cassidy.get_final_blows_per_10_mins());
    sqlite3_bind_double(stmt, 5, cassidy.get_solo_kills_per_10_mins());
    sqlite3_bind_double(stmt, 6, cassidy.get_hero_damage_done_per_10_mins());
    sqlite3_bind_int(stmt, 7, cassidy.get_critical_hit_accuracy());
    sqlite3_bind_double(stmt, 8, cassidy.get_critical_hits_per_10_mins());
    sqlite3_bind_double(stmt, 9, cassidy.get_critical_hit_kills_per_10_mins());

    // execute statement
    return_code = sqlite3_step(stmt);
    sql_step_check(return_code, cassidy_db);

    // finalize and close all related files
    sqlite3_finalize(stmt);
    sqlite3_close(cassidy_db);
    return 0;
}

int insert_stats_into_hanzoDatabase(std::string blizzard_ID, Heroes &hanzo)
{
    sqlite3 *hanzo_db;
    char *error_message = 0;
    sqlite3_stmt *stmt;

    int return_code = sqlite3_open("../databases/hanzo.db", &hanzo_db);
    if (!sql_open_check(return_code, hanzo_db))
        return 1;

    // delete old entry if new (updated) one is being insterted
    std::string sql_delete = "DELETE FROM hanzo WHERE Blizzard_ID = ?";
    int delete_return_code = sqlite3_prepare_v2(hanzo_db, sql_delete.c_str(), -1, &stmt, nullptr);
    if (!sql_prepare_check(delete_return_code, hanzo_db))
        return 1;
    sqlite3_bind_text(stmt, 1, blizzard_ID.c_str(), -1, SQLITE_TRANSIENT);
    delete_return_code = sqlite3_step(stmt);
    sql_step_check(delete_return_code, hanzo_db);
    sqlite3_reset(stmt);

    // sql command
    const char *sql_insert = "INSERT INTO hanzo (\"Blizzard_ID\", \"Name\", \"Deaths per 10 mins\", \"Final Blows per 10 mins\", \"Solo Kills per 10 mins\", \"Hero Damage Done per 10 mins\", \"Critical Hit Accuracy\", \"Critical Hits per 10 mins\", \"Critical Hit kills per 10 mins\") VALUES (?,?,?,?,?,?,?,?,?);";
    return_code = sqlite3_prepare_v2(hanzo_db, sql_insert, -1, &stmt, nullptr);
    if (!sql_prepare_check(return_code, hanzo_db))
        return 1;

    // loading statements
    sqlite3_bind_text(stmt, 1, blizzard_ID.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, select_name_from_blizzard_ID_from_database(blizzard_ID).c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt, 3, hanzo.get_deaths_per_10_mins());
    sqlite3_bind_double(stmt, 4, hanzo.get_final_blows_per_10_mins());
    sqlite3_bind_double(stmt, 5, hanzo.get_solo_kills_per_10_mins());
    sqlite3_bind_double(stmt, 6, hanzo.get_hero_damage_done_per_10_mins());
    sqlite3_bind_int(stmt, 7, hanzo.get_critical_hit_accuracy());
    sqlite3_bind_double(stmt, 8, hanzo.get_critical_hits_per_10_mins());
    sqlite3_bind_double(stmt, 9, hanzo.get_critical_hit_kills_per_10_mins());

    // execute statement
    return_code = sqlite3_step(stmt);
    sql_step_check(return_code, hanzo_db);

    // finalize and close all related files
    sqlite3_finalize(stmt);
    sqlite3_close(hanzo_db);
    return 0;
}

int insert_stats_into_sojournDatabase(std::string blizzard_ID, Heroes &sojourn)
{
    sqlite3 *sojourn_db;
    char *error_message = 0;
    sqlite3_stmt *stmt;

    int return_code = sqlite3_open("../databases/sojourn.db", &sojourn_db);
    if (!sql_open_check(return_code, sojourn_db))
        return 1;

    // delete old entry if new (updated) one is being insterted
    std::string sql_delete = "DELETE FROM sojourn WHERE Blizzard_ID = ?";
    int delete_return_code = sqlite3_prepare_v2(sojourn_db, sql_delete.c_str(), -1, &stmt, nullptr);
    if (!sql_prepare_check(delete_return_code, sojourn_db))
        return 1;
    sqlite3_bind_text(stmt, 1, blizzard_ID.c_str(), -1, SQLITE_TRANSIENT);
    delete_return_code = sqlite3_step(stmt);
    sql_step_check(delete_return_code, sojourn_db);
    sqlite3_reset(stmt);

    // sql command
    const char *sql_insert = "INSERT INTO sojourn (\"Blizzard_ID\", \"Name\", \"Deaths per 10 mins\", \"Final Blows per 10 mins\", \"Solo Kills per 10 mins\", \"Hero Damage Done per 10 mins\", \"Charged Shot Accuracy\", \"Charged Shot Crit Accuracy\", \"Charged Shot Kills per 10 mins\") VALUES (?,?,?,?,?,?,?,?,?);";
    return_code = sqlite3_prepare_v2(sojourn_db, sql_insert, -1, &stmt, nullptr);
    if (!sql_prepare_check(return_code, sojourn_db))
        return 1;

    // loading statements
    sqlite3_bind_text(stmt, 1, blizzard_ID.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, select_name_from_blizzard_ID_from_database(blizzard_ID).c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt, 3, sojourn.get_deaths_per_10_mins());
    sqlite3_bind_double(stmt, 4, sojourn.get_final_blows_per_10_mins());
    sqlite3_bind_double(stmt, 5, sojourn.get_solo_kills_per_10_mins());
    sqlite3_bind_double(stmt, 6, sojourn.get_hero_damage_done_per_10_mins());
    sqlite3_bind_int(stmt, 7, sojourn.get_charged_shot_accuracy());
    sqlite3_bind_int(stmt, 8, sojourn.get_charged_shot_crit_accuracy());
    sqlite3_bind_double(stmt, 9, sojourn.get_charged_shot_kills_per_10_mins());

    // execute statement
    return_code = sqlite3_step(stmt);
    sql_step_check(return_code, sojourn_db);

    // finalize and close all related files
    sqlite3_finalize(stmt);
    sqlite3_close(sojourn_db);
    return 0;
}

int insert_stats_into_soldier76Database(std::string blizzard_ID, Heroes &soldier76)
{
    sqlite3 *soldier76_db;
    char *error_message = 0;
    sqlite3_stmt *stmt;

    int return_code = sqlite3_open("../databases/soldier76.db", &soldier76_db);
    if (!sql_open_check(return_code, soldier76_db))
        return 1;

    // delete old entry if new (updated) one is being insterted
    std::string sql_delete = "DELETE FROM soldier76 WHERE Blizzard_ID = ?";
    int delete_return_code = sqlite3_prepare_v2(soldier76_db, sql_delete.c_str(), -1, &stmt, nullptr);
    if (!sql_prepare_check(delete_return_code, soldier76_db))
        return 1;
    sqlite3_bind_text(stmt, 1, blizzard_ID.c_str(), -1, SQLITE_TRANSIENT);
    delete_return_code = sqlite3_step(stmt);
    sql_step_check(delete_return_code, soldier76_db);
    sqlite3_reset(stmt);

    // sql command
    const char *sql_insert = "INSERT INTO soldier76 (\"Blizzard_ID\", \"Name\", \"Deaths per 10 mins\", \"Final Blows per 10 mins\", \"Solo Kills per 10 mins\", \"Hero Damage Done per 10 mins\", \"Critical Hit Accuracy\", \"Critical Hits per 10 mins\") VALUES (?,?,?,?,?,?,?,?);";
    return_code = sqlite3_prepare_v2(soldier76_db, sql_insert, -1, &stmt, nullptr);
    if (!sql_prepare_check(return_code, soldier76_db))
        return 1;

    // loading statements
    sqlite3_bind_text(stmt, 1, blizzard_ID.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, select_name_from_blizzard_ID_from_database(blizzard_ID).c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt, 3, soldier76.get_deaths_per_10_mins());
    sqlite3_bind_double(stmt, 4, soldier76.get_final_blows_per_10_mins());
    sqlite3_bind_double(stmt, 5, soldier76.get_solo_kills_per_10_mins());
    sqlite3_bind_double(stmt, 6, soldier76.get_hero_damage_done_per_10_mins());
    sqlite3_bind_int(stmt, 7, soldier76.get_critical_hit_accuracy());
    sqlite3_bind_double(stmt, 8, soldier76.get_critical_hits_per_10_mins());

    // execute statement
    return_code = sqlite3_step(stmt);
    sql_step_check(return_code, soldier76_db);

    // finalize and close all related files
    sqlite3_finalize(stmt);
    sqlite3_close(soldier76_db);
    return 0;
}

int insert_stats_into_tracerDatabase(std::string blizzard_ID, Heroes &tracer)
{
    sqlite3 *tracer_db;
    char *error_message = 0;
    sqlite3_stmt *stmt;

    int return_code = sqlite3_open("../databases/tracer.db", &tracer_db);
    if (!sql_open_check(return_code, tracer_db))
        return 1;

    // delete old entry if new (updated) one is being insterted
    std::string sql_delete = "DELETE FROM tracer WHERE Blizzard_ID = ?";
    int delete_return_code = sqlite3_prepare_v2(tracer_db, sql_delete.c_str(), -1, &stmt, nullptr);
    if (!sql_prepare_check(delete_return_code, tracer_db))
        return 1;
    sqlite3_bind_text(stmt, 1, blizzard_ID.c_str(), -1, SQLITE_TRANSIENT);
    delete_return_code = sqlite3_step(stmt);
    sql_step_check(delete_return_code, tracer_db);
    sqlite3_reset(stmt);

    // sql command
    const char *sql_insert = "INSERT INTO tracer (\"Blizzard_ID\", \"Name\", \"Deaths per 10 mins\", \"Final Blows per 10 mins\", \"Solo Kills per 10 mins\", \"Hero Damage Done per 10 mins\", \"Critical Hits per 10 mins\") VALUES (?,?,?,?,?,?,?);";
    return_code = sqlite3_prepare_v2(tracer_db, sql_insert, -1, &stmt, nullptr);
    if (!sql_prepare_check(return_code, tracer_db))
        return 1;

    // loading statements
    sqlite3_bind_text(stmt, 1, blizzard_ID.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, select_name_from_blizzard_ID_from_database(blizzard_ID).c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt, 3, tracer.get_deaths_per_10_mins());
    sqlite3_bind_double(stmt, 4, tracer.get_final_blows_per_10_mins());
    sqlite3_bind_double(stmt, 5, tracer.get_solo_kills_per_10_mins());
    sqlite3_bind_double(stmt, 6, tracer.get_hero_damage_done_per_10_mins());
    sqlite3_bind_double(stmt, 7, tracer.get_critical_hits_per_10_mins());

    // execute statement
    return_code = sqlite3_step(stmt);
    sql_step_check(return_code, tracer_db);

    // finalize and close all related files
    sqlite3_finalize(stmt);
    sqlite3_close(tracer_db);
    return 0;
}

int insert_stats_into_widowmakerDatabase(std::string blizzard_ID, Heroes &widowmaker)
{
    sqlite3 *widowmaker_db;
    char *error_message = 0;
    sqlite3_stmt *stmt;

    int return_code = sqlite3_open("../databases/widowmaker.db", &widowmaker_db);
    if (!sql_open_check(return_code, widowmaker_db))
        return 1;

    // delete old entry if new (updated) one is being insterted
    std::string sql_delete = "DELETE FROM widowmaker WHERE Blizzard_ID = ?";
    int delete_return_code = sqlite3_prepare_v2(widowmaker_db, sql_delete.c_str(), -1, &stmt, nullptr);
    if (!sql_prepare_check(delete_return_code, widowmaker_db))
        return 1;
    sqlite3_bind_text(stmt, 1, blizzard_ID.c_str(), -1, SQLITE_TRANSIENT);
    delete_return_code = sqlite3_step(stmt);
    sql_step_check(delete_return_code, widowmaker_db);
    sqlite3_reset(stmt);

    // sql command
    const char *sql_insert = "INSERT INTO widowmaker (\"Blizzard_ID\", \"Name\", \"Deaths per 10 mins\", \"Final Blows per 10 mins\", \"Solo Kills per 10 mins\", \"Hero Damage Done per 10 mins\", \"Scoped Accuracy\", \"Scoped Crit Accuracy\", \"Scoped Crit Hits per 10 mins\", \"Scoped Crit Kills per 10 mins\") VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?);";

    return_code = sqlite3_prepare_v2(widowmaker_db, sql_insert, -1, &stmt, nullptr);
    if (!sql_prepare_check(return_code, widowmaker_db))
        return 1;

    // loading statements
    sqlite3_bind_text(stmt, 1, blizzard_ID.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, select_name_from_blizzard_ID_from_database(blizzard_ID).c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt, 3, widowmaker.get_deaths_per_10_mins());
    sqlite3_bind_double(stmt, 4, widowmaker.get_final_blows_per_10_mins());
    sqlite3_bind_double(stmt, 5, widowmaker.get_solo_kills_per_10_mins());
    sqlite3_bind_double(stmt, 6, widowmaker.get_hero_damage_done_per_10_mins());
    sqlite3_bind_int(stmt, 7, widowmaker.get_scoped_accuracy());
    sqlite3_bind_int(stmt, 8, widowmaker.get_scoped_crit_accuracy());
    sqlite3_bind_double(stmt, 9, widowmaker.get_scoped_crit_hits_per_10_mins());
    sqlite3_bind_double(stmt, 10, widowmaker.get_scoped_crit_kills_per_10_mins());

    // execute statement
    return_code = sqlite3_step(stmt);
    sql_step_check(return_code, widowmaker_db);

    // finalize and close all related files
    sqlite3_finalize(stmt);
    sqlite3_close(widowmaker_db);
    return 0;
}

int create_table()
{
    sqlite3 *DB;
    int exit = 0;

    exit = sqlite3_open("../databases/widowmaker.db", &DB);

    if (exit)
    {
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
        return (-1);
    }
    else
        std::cout << "Opened Database Successfully!" << std::endl;

    const char *sqlCreateTable = R"(
    CREATE TABLE IF NOT EXISTS "widowmaker" (
    "Entry" INTEGER PRIMARY KEY AUTOINCREMENT,
    "Blizzard_ID"	TEXT NOT NULL,
	"Name"	TEXT NOT NULL,
	"Deaths per 10 mins"	REAL NOT NULL,
	"Final Blows per 10 mins"	REAL NOT NULL,
	"Solo Kills per 10 mins"	REAL NOT NULL,
	"Hero Damage Done per 10 mins"	REAL NOT NULL,
	"Scoped Accuracy"	INTEGER NOT NULL,
	"Scoped Crit Accuracy"	INTEGER NOT NULL,
	"Scoped Crit Hits per 10 mins"	REAL NOT NULL,
	"Scoped Crit Kills per 10 mins"	REAL NOT NULL,
	FOREIGN KEY("Blizzard_ID") REFERENCES "players"("Blizzard_ID"),
	FOREIGN KEY("Name") REFERENCES "players"("Name")
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

bool sql_step_check(int return_code, sqlite3 *db)
{
    if (return_code != SQLITE_ROW && return_code != SQLITE_DONE)
    {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    return true;
}
