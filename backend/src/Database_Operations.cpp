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

    exit = sqlite3_open("../databases/tracer.db", &DB); 
  
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 

    const char* sqlCreateTable = R"(
    CREATE TABLE "tracer" (
	"Entry"	INTEGER NOT NULL UNIQUE,
	"Blizzard_ID"	TEXT NOT NULL,
	"Name"	TEXT NOT NULL,
	"Deaths per 10 mins"	REAL NOT NULL,
	"Final Blows per 10 mins"	REAL NOT NULL,
	"Solo Kills per 10 mins"	REAL NOT NULL,
	"Hero Damage Done per 10 mins"	REAL NOT NULL,
	"Critical Hits per 10 mins"	REAL,
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


