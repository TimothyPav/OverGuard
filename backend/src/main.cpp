#include "API_Handler.h"
#include "Database_Operations.h"
#include "Heroes.h"

#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <string>
#include <map>
#include <variant>

using json = nlohmann::json;

int main(int argc, char** argv) {
    //test_call();
    //get_name_from_blizzard_ID(R"(da47b981e13cc9f8b0a0%257C9ce73afb3dc641f023475ff233d0a876)");
    //load_players_into_playersDatabase();
    //std::map<std::string, std::variant<int, double>> hero_stats;

    //get_stats("d356feafa93cc9f8b9a8%7C2db9e2736a06ff6ba782e0fcd0a17c40");

    // std::string player_name = select_name_from_blizzard_ID_from_database("d356feafa93cc9f8b9a8%7C2db9e2736a06ff6ba782e0fcd0a17c40");
    // std::cout << "Player Name: --> " << player_name << "\n";

    std::ifstream inputFile("../databases/player_ids.txt");

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening the file!" << std::endl;
        return 1;
    }
    std::string line; // variable to store each line
    while (getline(inputFile, line))
    {
        std::string player_name = select_name_from_blizzard_ID_from_database(line);
        std::cout << "Player Name: --> " << player_name << "\n";
    }
}