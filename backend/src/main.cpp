#include "APIHandler.h"

#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::json;

int main(int argc, char** argv) {
    cpr::Response r = cpr::Get(cpr::Url{"https://overfast-api.tekrop.fr/players/Cash-11893/stats?gamemode=competitive&platform=pc&hero=widowmaker"});
    json j = json::parse(r.text);

    int scoped_critical_hit_accuracy = j["widowmaker"][0]["stats"][13]["value"];

    std::cout << "Scoped Critical Hit Accuracy: " << scoped_critical_hit_accuracy << std::endl;

    return 0;
}