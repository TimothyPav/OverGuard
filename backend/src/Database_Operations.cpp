#include <iostream> 
#include <sqlite3.h>
 
// CREATE TABLE "players" (
// 	"ID"	INTEGER NOT NULL UNIQUE,
// 	"Name"	TEXT NOT NULL,
// 	"BattleTag"	TEXT NOT NULL,
// 	"Tank"	TEXT NOT NULL,
// 	"Damage"	TEXT NOT NULL,
// 	"Support"	TEXT NOT NULL,
// 	PRIMARY KEY("ID" AUTOINCREMENT)
// );

int main(int argc, char** argv) 
{ 
    sqlite3* DB; 
    int exit = 0; 

    exit = sqlite3_open("../databases/players.db", &DB); 
  
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 

    const char* sqlCreateTable = R"(
    CREATE TABLE "players" (
    "ID"	INTEGER NOT NULL UNIQUE,
    "Name"	TEXT NOT NULL,
    "BattleTag"	TEXT NOT NULL,
    "Tank"	TEXT NOT NULL,
    "Damage"	TEXT NOT NULL,
    "Support"	TEXT NOT NULL,
    PRIMARY KEY("ID" AUTOINCREMENT)
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


