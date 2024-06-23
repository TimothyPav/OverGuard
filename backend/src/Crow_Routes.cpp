#include "Crow_Routes.h"
#include "Json_Serializer.h"

#include <iostream>
#include <crow.h>
#include <string>
#include <nlohmann/json.hpp>
#include <regex>

std::string removeSingleQuotes(const std::string& input) {
    // Define a regex to find single quotes
    std::regex quoteRegex("'");

    // Replace all single quotes with an empty string
    std::string output = std::regex_replace(input, quoteRegex, "");

    return output;
}

void setup_routes(crow::SimpleApp& app){

    CROW_ROUTE(app, "/api/player")
    ([](const crow::request& req)
    {
        std::string battletag = req.url_params.get("battletag");
        battletag = removeSingleQuotes(battletag);
        std::cout << battletag << std::endl;
        nlohmann::json j = serialize_player_input(battletag);
        if(j.is_null()) return crow::response(404);
        return crow::response{j.dump()};
    });

    CROW_ROUTE(app, "/api/hero_stat")
    ([](const crow::request& req)
    {
        std::string hero_name = req.url_params.get("hero_name");
        std::string column = req.url_params.get("column");
        hero_name = removeSingleQuotes(hero_name);
        column = removeSingleQuotes(column);
        std::cout << "hero_name --> " << hero_name << "column --> " << column << std::endl;
        nlohmann::json j = serialize_specific_hero_stat(hero_name, column);
        if(j.is_null()) return crow::response(404);
        return crow::response{j.dump()};
    });
}