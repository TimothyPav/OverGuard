#include "API_Handler.h"
#include "Heroes.h"

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

void get_stats(const std::string& blizzard_ID){
    std::string url = std::string(BASE_OVERFAST_API_URL) + blizzard_ID + "/stats?gamemode=competitive&platform=pc";

    //std::cout << url <<std::endl;
    
    cpr::Response r = cpr::Get(cpr::Url{url});

    std::map<std::string, std::variant<int, double>> hero_stats;
    json j = json::parse(r.text);
    Heroes heroes[7];
    heroes[0] = Ashe();
    heroes[0] = Cassidy();
    heroes[0] = Hanzo();
    heroes[0] = Sojourn();
    heroes[0] = Soldier76();
    heroes[0] = Tracer();
    heroes[0] = Widowmaker();

    for(Heroes hero : heroes){

        for (const auto& category : j["widowmaker"]) {

            if(category["category"] == "hero_specific"){
                for(const auto& stat: category["stats"]){
                    if (stat["value"].is_number_float()) {
                        hero.set_hero_specific_stats(stat["key"], (float) stat["value"]);
                    } else if (stat["value"].is_number_integer()) {
                        widowmaker.set_hero_specific_stats(stat["key"], (int) stat["value"]);
                    }
                    //std::cout << stat["key"] << ": " << stat["value"] << std::endl;
                }
            }
            else if (category["category"] == "average") {
                for (const auto& stat : category["stats"]) {
                    if (stat["key"] == "deaths_avg_per_10_min") widowmaker.set_deaths_per_10_mins((double) stat["value"]);
                    else if (stat["key"] == "final_blows_avg_per_10_min") widowmaker.set_final_blows_per_10_mins((double) stat["value"]);
                    else if (stat["key"] == "solo_kills_avg_per_10_min") widowmaker.set_solo_kills_per_10_mins((double) stat["value"]);
                    else if (stat["key"] == "hero_damage_done_avg_per_10_min") widowmaker.set_hero_damage_done_per_10_mins((double) stat["value"]);
                }
            }
            else if(category["category"] == "game") {
                for(const auto& stat : category["stats"]){
                    if(stat["key"] == "time_played"){
                        std::cout << stat["key"] << ": " << stat["value"] << std::endl;
                        if(stat["value"] >= MIN_PLAYTIME_REQUIRED){
                            //return hero_stats;
                        }
                    }
                }
            }
        }
    }

    //std::cout << widowmaker.get_deaths_per_10_mins() << " " << widowmaker.get_final_blows_per_10_mins() << " " << widowmaker.get_hero_damage_done_per_10_mins() << " " << widowmaker.get_solo_kills_per_10_mins() << std::endl;
    std::cout << url << std::endl;
    std::map<std::string, std::variant<int, double>> empty;
}