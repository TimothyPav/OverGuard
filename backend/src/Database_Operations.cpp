#include "Database_Operations.h"
#include "API_Handler.h"

#include <iostream> 
#include <sqlite3.h>
#include <string>
#include <chrono>
#include <thread>
#include <fstream> 

int load_players_into_playersDatabase(){
    std::ifstream inputFile("../databases/player_ids.txt"); 
  
    if (!inputFile.is_open()) { 
        std::cerr << "Error opening the file!" << std::endl; 
        return 1; 
    } 

    sqlite3* players_db;
    char* error_message = 0;
    sqlite3_stmt* stmt;

    int return_code = sqlite3_open("../databases/players.db", &players_db);
    if (return_code) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(players_db) << std::endl;
        return 1;
    }

    // sql command
    const char* sql_insert = "INSERT INTO players (Name, Blizzard_ID) VALUES (?, ?);";
    return_code = sqlite3_prepare_v2(players_db, sql_insert, -1, &stmt, NULL);
    if (return_code != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(players_db) << std::endl;
        sqlite3_close(players_db);
        return 1;
    }

    std::string line; // variable to store each line
    while (getline(inputFile, line)) { 
        std::string name = get_name_from_blizzard_ID(line);
        if(name.size() > 0){
            sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 2, line.c_str(), -1, SQLITE_TRANSIENT);

            return_code = sqlite3_step(stmt);
            if (return_code != SQLITE_DONE) {
            std::cerr << "Execution failed: " << sqlite3_errmsg(players_db) << std::endl;
            //sqlite3_finalize(stmt);
            //sqlite3_close(players_db);
            //return 1;
            } else {
                std::cout << "Successfully inserted: " << name << " : " << line << std::endl;
            }
        }

        sqlite3_reset(stmt);
    } 
  
    // Close the file 
    inputFile.close(); 
    sqlite3_finalize(stmt);
    sqlite3_close(players_db);
    return 0;
}

int create_table() 
{ 
    sqlite3* DB; 
    int exit = 0; 

    exit = sqlite3_open("../databases/tracer.db", &DB); 
  
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 

    const char* sqlCreateTable = R"(
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

    char* errMsg;
    exit = sqlite3_exec(DB, sqlCreateTable, 0, 0, &errMsg);
    if (exit != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    sqlite3_close(DB); 
    return (0); 
} 




