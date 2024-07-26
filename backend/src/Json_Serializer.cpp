#include "API_Handler.h"
#include "Heroes.h"
#include "Json_Serializer.h"

#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <array>
#include <memory>
#include <optional>
#include <variant>
#include <map>

nlohmann::json serialize_specific_hero_stat(std::string hero_name, std::string column)
{
    std::unordered_map<std::string, std::variant<int, double>> stat_map = get_column(hero_name, column);
    if (stat_map.empty())
        return {};

    nlohmann::json j;
    for (const auto& elem : stat_map) {
        double stat_double = 0.0;
        int stat_int = 0;        
        std::visit([&](const auto &value) {
            j[hero_name][column][elem.first] = value;
        }, elem.second);
    }

    std::cout << j.dump(4) << std::endl;
    return j;
}

nlohmann::json serialize_player_input(std::string player_id)
{
    std::optional result = get_stats(player_id, false);
    if (!result.has_value())
    {
        return {};
    }
    nlohmann::json player_data;
    std::array<std::unique_ptr<Heroes>, 7> &heroes = result.value();
    for (const auto &hero : heroes)
    {
        hero->initialize_getters();
        for (const auto &getter : hero->getters)
        {
            if (hero->get_is_enough_playtime())
            {
                std::variant<int, double> stat = getter.second();
                std::visit([&](const auto &value)
                           {
                if (value > 0) {
                    player_data[hero->get_hero_name()][getter.first] = value;  // Assign the actual value, not the variant
                } }, stat);
            }
        }
    }

    std::cout << player_data.dump(4) << std::endl;
    return player_data;
}
