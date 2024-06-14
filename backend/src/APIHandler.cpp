#include "API_Handler.h"

#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

#define BASE_OVERFAST_API_URL "https://overfast-api.tekrop.fr/players/"
#define MIN_PLAYTIME_REQUIRED 3600

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

int test_call(){
    std::string url = std::string(BASE_OVERFAST_API_URL) + R"(da47b981e13cc9f8b0a0%7C9ce73afb3dc641f023475ff233d0a876/stats?gamemode=competitive&platform=pc)";

    //std::cout << url <<std::endl;
    
    cpr::Response r = cpr::Get(cpr::Url{url});

    json j = json::parse(r.text);
    for (const auto& category : j["cassidy"]) {
        if (category["category"] == "average") {
            for (const auto& stat : category["stats"]) {
                if (stat["key"] == "deaths_avg_per_10_min" || stat["key"] == "final_blows_avg_per_10_min" || stat["key"] == "solo_kills_avg_per_10_min" || stat["key"] == "hero_damage_done_avg_per_10_min") {
                     std::cout << stat["key"] << ": " << stat["value"] << std::endl;
                }
            }
        }
        else if(category["category"] == "game") {
            for(const auto& stat : category["stats"]){
                if(stat["key"] == "time_played"){
                    std::cout << stat["key"] << ": " << stat["value"] << std::endl;
                }
            }
        }
    }

    std::cout << url << std::endl;

    return 0;
}