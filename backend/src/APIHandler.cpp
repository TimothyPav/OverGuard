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
    std::string url = std::string(BASE_OVERFAST_API_URL) + R"(da47b981e13cc9f8b0a0%7C9ce73afb3dc641f023475ff233d0a876/stats/summary?gamemode=competitive&platform=pc)";

    std::cout << url <<std::endl;
    
    cpr::Response r = cpr::Get(cpr::Url{url});

    json j = json::parse(r.text);

    double deaths_per_10 = j["heroes"]["cassidy"]["average"]["deaths"];

    std::cout << deaths_per_10 << std::endl;

    return 0;
}