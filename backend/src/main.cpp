#include "API_Handler.h"
#include "Database_Operations.h"
#include "Heroes.h"
#include "JsonSerializer.h"

#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <string>
#include <map>
#include <variant>

using json = nlohmann::json;

int main(int argc, char** argv) {
    //test_call();
    //std::cout << get_name_from_blizzard_ID("c14ea584b47089e0b8a126a7d5%7Cb10cc510931ea354796176e1bc6f966c") << "\n";
    //load_players_into_playersDatabase(); 
    //loop_over_blizzard_ID();

    nlohmann::json j = serialize_player_input("Hydron-11348");
    std::cout << j << "\n";
}