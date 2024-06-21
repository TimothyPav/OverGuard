#include "API_Handler.h"
#include "Heroes.h"
#include "JsonSerializer.h"

#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <array>
#include <memory>
#include <optional>

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
        if (hero->get_deaths_per_10_mins() != 0)
        player_data[hero->get_hero_name()]["deaths_per_10_mins"] = hero->get_deaths_per_10_mins();
        if (hero->get_final_blows_per_10_mins() != 0)
            player_data[hero->get_hero_name()]["final_blows_avg_per_10_min"] = hero->get_final_blows_per_10_mins();
        if (hero->get_solo_kills_per_10_mins() != 0)
            player_data[hero->get_hero_name()]["solo_kills_avg_per_10_min"] = hero->get_solo_kills_per_10_mins();
        if (hero->get_hero_damage_done_per_10_mins() != 0)
            player_data[hero->get_hero_name()]["hero_damage_done_avg_per_10_min"] = hero->get_hero_damage_done_per_10_mins();
        if (hero->get_scoped_accuracy() != 0)
            player_data[hero->get_hero_name()]["scoped_accuracy"] = hero->get_scoped_accuracy();
        if (hero->get_scoped_crit_accuracy() != 0)
            player_data[hero->get_hero_name()]["scoped_critical_hit_accuracy"] = hero->get_scoped_crit_accuracy();
        if (hero->get_scoped_crit_hits_per_10_mins() != 0)
            player_data[hero->get_hero_name()]["scoped_critical_hits_avg_per_10_min"] = hero->get_scoped_crit_hits_per_10_mins();
        if (hero->get_scoped_crit_kills_per_10_mins() != 0)
            player_data[hero->get_hero_name()]["scoped_critical_hit_kills_avg_per_10_min"] = hero->get_scoped_crit_kills_per_10_mins();
        if (hero->get_critical_hit_accuracy() != 0)
            player_data[hero->get_hero_name()]["critical_hit_accuracy"] = hero->get_critical_hit_accuracy();
        if (hero->get_critical_hits_per_10_mins() != 0)
            player_data[hero->get_hero_name()]["critical_hits_avg_per_10_min"] = hero->get_critical_hits_per_10_mins();
        if (hero->get_critical_hit_kills_per_10_mins() != 0)
            player_data[hero->get_hero_name()]["critical_hit_kills_avg_per_10_min"] = hero->get_critical_hit_kills_per_10_mins();
        if (hero->get_charged_shot_accuracy() != 0)
            player_data[hero->get_hero_name()]["charged_shot_accuracy"] = hero->get_charged_shot_accuracy();
        if (hero->get_charged_shot_crit_accuracy() != 0)
            player_data[hero->get_hero_name()]["charged_shot_critical_accuracy"] = hero->get_charged_shot_crit_accuracy();
        if (hero->get_charged_shot_kills_per_10_mins() != 0)
            player_data[hero->get_hero_name()]["charged_shot_kills_avg_per_10_min"] = hero->get_charged_shot_kills_per_10_mins();
    }

    return player_data;
}