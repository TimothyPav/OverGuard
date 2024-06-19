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
    std::map<std::string, std::variant<int, double>> hero_stats;

    get_stats("d356feafa93cc9f8b9a8%7C2db9e2736a06ff6ba782e0fcd0a17c40");
}