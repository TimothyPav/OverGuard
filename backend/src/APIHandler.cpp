#include "API_Handler.h"

#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <string>
#include <map>
#include <variant>

using json = nlohmann::json;
using StatsMap = std::map<std::string, std::variant<int, double>>;

#define BASE_OVERFAST_API_URL "https://overfast-api.tekrop.fr/players/"
#define MIN_PLAYTIME_REQUIRED 3600
#define HEROES_COUNT 8

std::string get_name_from_blizzard_ID(const std::string& blizzard_ID){
    std::string player_summary_url = BASE_OVERFAST_API_URL + blizzard_ID + "/summary";
    cpr::Response response = cpr::Get(cpr::Url{player_summary_url});
    if(response.status_code == 200){
        json j = json::parse(response.text);
        std::string name = j["username"];
        return name;
    } else {
        std::cout << response.status_code << std::endl;
    }

    return "";
}

StatsMap get_stats(){
    std::string url = std::string(BASE_OVERFAST_API_URL) + R"(d057bf85bd3ccafcb1a221%7C583439938be7d340c52bd09cb043d79e/stats?gamemode=competitive&platform=pc)";

    //std::cout << url <<std::endl;
    
    cpr::Response r = cpr::Get(cpr::Url{url});

    std::map<std::string, std::variant<int, double>> hero_stats;
    json j = json::parse(r.text);
    for (const auto& category : j["ana"]) {
        if (category["category"] == "average") {
            for (const auto& stat : category["stats"]) {
                if (stat["key"] == "deaths_avg_per_10_min" || stat["key"] == "final_blows_avg_per_10_min" || stat["key"] == "solo_kills_avg_per_10_min" || stat["key"] == "hero_damage_done_avg_per_10_min") {
                    if (stat["value"].is_number_float()) {
                        hero_stats[stat["key"]] = stat["value"].get<double>();
                    } else if (stat["value"].is_number_integer()) {
                        hero_stats[stat["key"]] = stat["value"].get<int>();
                    }
                    //std::cout << stat["key"] << ": " << stat["value"] << std::endl;
                }
            }
        }
        else if(category["category"] == "game") {
            for(const auto& stat : category["stats"]){
                if(stat["key"] == "time_played"){
                    std::cout << stat["key"] << ": " << stat["value"] << std::endl;
                    if(stat["value"] >= MIN_PLAYTIME_REQUIRED){
                        return hero_stats;
                    }
                }
            }
        }
    }

    std::cout << url << std::endl;
    std::map<std::string, std::variant<int, double>> empty;
    return empty;
}