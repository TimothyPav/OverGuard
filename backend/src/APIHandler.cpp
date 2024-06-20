#include "API_Handler.h"
#include "Heroes.h"
#include "Database_Operations.h"

#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <string>
#include <map>
#include <variant>
#include <cmath>

using json = nlohmann::json;
using StatsMap = std::map<std::string, std::variant<int, double>>;

#define BASE_OVERFAST_API_URL "https://overfast-api.tekrop.fr/players/"
#define MIN_PLAYTIME_REQUIRED 5400
#define HEROES_COUNT 8

std::string get_name_from_blizzard_ID(const std::string &blizzard_ID)
{
    std::string player_summary_url = BASE_OVERFAST_API_URL + blizzard_ID + "/summary";
    cpr::Response response = cpr::Get(cpr::Url{player_summary_url});
    if (response.status_code == 200)
    {
        json j = json::parse(response.text);
        std::string name = j["username"];
        return name;
    }
    else
    {
        std::cout << response.status_code << std::endl;
    }

    return "";
}

void get_stats(const std::string &blizzard_ID)
{
    std::string url = std::string(BASE_OVERFAST_API_URL) + blizzard_ID + "/stats?gamemode=competitive&platform=pc";

    cpr::Response r = cpr::Get(cpr::Url{url});

    if (r.status_code != 200){
        std::cout << "Error finding player. Status code: " << r.status_code << std::endl;
        return;
    }

    std::map<std::string, std::variant<int, double>> hero_stats;
    json j = json::parse(r.text);
    std::array<std::unique_ptr<Heroes>, 7> heroes;
    heroes[0] = std::make_unique<Ashe>();
    heroes[1] = std::make_unique<Cassidy>();
    heroes[2] = std::make_unique<Hanzo>();
    heroes[3] = std::make_unique<Sojourn>();
    heroes[4] = std::make_unique<Soldier76>();
    heroes[5] = std::make_unique<Tracer>();
    heroes[6] = std::make_unique<Widowmaker>();

    for (const auto &hero : heroes)
    {
        std::string hero_name = hero->get_hero_name();
        hero->set_is_enough_playtime(false);
        for (const auto &category : j[hero_name])
        {
            if (category["category"] == "hero_specific")
            {
                for (const auto &stat : category["stats"])
                {
                    if (stat["value"].is_number_float())
                    {
                        hero->set_hero_specific_stats(stat["key"], std::round(static_cast<double>(stat["value"]) * 100) / 100.0f);
                    }
                    else if (stat["value"].is_number_integer())
                    {
                        hero->set_hero_specific_stats(stat["key"], (int)stat["value"]);
                    }
                }
            }
            else if (category["category"] == "average")
            {
                for (const auto &stat : category["stats"])
                {
                    if (stat["key"] == "deaths_avg_per_10_min")
                        hero->set_deaths_per_10_mins(std::round(static_cast<double>(stat["value"]) * 100) / 100);
                    else if (stat["key"] == "final_blows_avg_per_10_min")
                        hero->set_final_blows_per_10_mins(std::round(static_cast<double>(stat["value"]) * 100) / 100);
                    else if (stat["key"] == "solo_kills_avg_per_10_min")
                        hero->set_solo_kills_per_10_mins(std::round(static_cast<double>(stat["value"]) * 100) / 100);
                    else if (stat["key"] == "hero_damage_done_avg_per_10_min")
                        hero->set_hero_damage_done_per_10_mins(std::round(static_cast<double>(stat["value"]) * 100) / 100);

                    if (stat["value"].is_number_float())
                    {
                        hero->set_hero_specific_stats(stat["key"], std::round(static_cast<double>(stat["value"]) * 100) / 100.0f);
                    }
                    else if (stat["value"].is_number_integer())
                    {
                        hero->set_hero_specific_stats(stat["key"], (int)stat["value"]);
                    }
                }
            }
            else if (category["category"] == "game")
            {
                for (const auto &stat : category["stats"])
                {
                    if (stat["key"] == "time_played")
                    {
                        if (stat["value"] >= MIN_PLAYTIME_REQUIRED)
                        {
                            hero->set_is_enough_playtime(true);
                        }
                        else
                            hero->set_is_enough_playtime(false);
                    }
                }
            }
            else if (category["category"] == "combat")
            {
                for (const auto &stat : category["stats"])
                {
                    if (stat["value"].is_number_float())
                    {
                        hero->set_hero_specific_stats(stat["key"], std::round(static_cast<double>(stat["value"]) * 100) / 100.0f);
                    }
                    else if (stat["value"].is_number_integer())
                    {
                        hero->set_hero_specific_stats(stat["key"], (int)stat["value"]);
                    }
                }
            }
        }
        if (hero->get_is_enough_playtime())
            insert_hero_into_database(blizzard_ID, *hero);
    }

    std::map<std::string, std::variant<int, double>> empty;
}