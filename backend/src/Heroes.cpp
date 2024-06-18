#include "Heroes.h"

#include <string>
#include <variant>

// setters
void Heroes::set_deaths_per_10_mins(double deaths){ deaths_per_10_mins = deaths; }
void Heroes::set_final_blows_per_10_mins(double final_blows){ final_blows_per_10_mins = final_blows; }
void Heroes::set_solo_kills_per_10_mins(double solo_kills){ solo_kills_per_10_mins = solo_kills; }
void Heroes::set_hero_damage_done_per_10_mins(double damage){ hero_damage_done_per_10_mins = damage; }
void Heroes::set_is_enough_playtime(bool val){ is_enough_playtime = val; }
void Heroes::set_hero_specific_stats(const std::string& key, std::variant<int, double> value) {}
// getters
double Heroes::get_deaths_per_10_mins(){ return this->deaths_per_10_mins; }
double Heroes::get_final_blows_per_10_mins(){ return this->final_blows_per_10_mins; }
double Heroes::get_solo_kills_per_10_mins(){ return this->solo_kills_per_10_mins; }
double Heroes::get_hero_damage_done_per_10_mins(){ return this->hero_damage_done_per_10_mins; }
bool Heroes::get_is_enough_playtime(){ return this->is_enough_playtime; }
std::string Heroes::get_hero_name()const { return "hero_name"; }
// hero stats to be overriden...
 int Heroes::get_scoped_accuracy()const { return 0; }
 int Heroes::get_scoped_crit_accuracy()const { return 0; }
 double Heroes::get_scoped_crit_hits_per_10_mins()const { return 0; }
 double Heroes::get_scoped_crit_kills_per_10_mins()const { return 0; }
 int Heroes::get_critical_hit_accuracy()const { return 0; }
 double Heroes::get_critical_hits_per_10_mins()const { return 0; }
 double Heroes::get_critical_hit_kills_per_10_mins()const { return 0; }
 int Heroes::get_charged_shot_accuracy()const { return 0; }
 int Heroes::get_charged_shot_crit_accuracy()const { return 0; }
 double Heroes::get_charged_shot_kills_per_10_mins()const { return 0; }


// setters
void Widowmaker::set_scoped_accuracy(int scoped_acc){ scoped_accuracy = scoped_acc; }
void Widowmaker::set_scoped_crit_accuracy(int scoped_crit_acc){ scoped_crit_accuracy = scoped_crit_acc; }
void Widowmaker::set_scoped_crit_hits_per_10_mins(double scoped_crit_hits){ scoped_crit_hits_per_10_mins = scoped_crit_hits; }
void Widowmaker::set_scoped_crit_kills_per_10_mins(double scoped_crit_kills){ scoped_crit_kills_per_10_mins = scoped_crit_kills; }
// getters
int Widowmaker::get_scoped_accuracy(){ return scoped_accuracy; }
int Widowmaker::get_scoped_crit_accuracy(){ return scoped_crit_accuracy; }
double Widowmaker::get_scoped_crit_hits_per_10_mins(){ return scoped_crit_hits_per_10_mins; }
double Widowmaker::get_scoped_crit_kills_per_10_mins(){ return scoped_crit_kills_per_10_mins; }
std::string Widowmaker::get_hero_name()const { return "widowmaker"; }
// methods
void Widowmaker::set_hero_specific_stats(const std::string& key, std::variant<int, double> value) {
    auto it = setter_map.find(key);
    if (it != setter_map.end()) {
        it->second(this, value);  // Execute the found setter function
    }
}

// setters
void Ashe::set_scoped_accuracy(int scoped_acc){ scoped_accuracy = scoped_acc; }
void Ashe::set_scoped_crit_accuracy(int scoped_crit_acc){ scoped_crit_accuracy = scoped_crit_acc; }
void Ashe::set_scoped_crit_hits_per_10_mins(double scoped_crit_hits){ scoped_crit_hits_per_10_mins = scoped_crit_hits; }
void Ashe::set_scoped_crit_kills_per_10_mins(double scoped_crit_kills){ scoped_crit_kills_per_10_mins = scoped_crit_kills; }
// getters
int Ashe::get_scoped_accuracy(){ return scoped_accuracy; }
int Ashe::get_scoped_crit_accuracy(){ return scoped_crit_accuracy; }
double Ashe::get_scoped_crit_hits_per_10_mins(){ return scoped_crit_hits_per_10_mins; }
double Ashe::get_scoped_crit_kills_per_10_mins(){ return scoped_crit_kills_per_10_mins; }
std::string Ashe::get_hero_name()const { return "ashe"; }
// methods
void Ashe::set_hero_specific_stats(const std::string& key, std::variant<int, double> value) {
    auto it = setter_map.find(key);
    if (it != setter_map.end()) {
        it->second(this, value);  // Execute the found setter function
    }
}


// setters
void Cassidy::set_critical_hit_accuracy(int crit_acc){ critical_hit_accuracy = crit_acc; }
void Cassidy::set_critical_hits_per_10_mins(double hits_per_10){ critical_hits_per_10_mins = hits_per_10; }
void Cassidy::set_critical_hit_kills_per_10_mins(double kills_per_10){ critical_hit_kills_per_10_mins = kills_per_10; }
// getters
int Cassidy::get_critical_hit_accuracy(){ return critical_hit_accuracy; }
double Cassidy::get_critical_hits_per_10_mins(){ return critical_hits_per_10_mins; }
double Cassidy::get_critical_hit_kills_per_10_mins(){ return critical_hit_kills_per_10_mins; }
std::string Cassidy::get_hero_name()const { return "cassidy"; }
void Cassidy::set_hero_specific_stats(const std::string& key, std::variant<int, double> value) {
    auto it = setter_map.find(key);
    if (it != setter_map.end()) {
        it->second(this, value);  // Execute the found setter function
    }
}

// setters
void Hanzo::set_critical_hit_accuracy(int crit_acc){ critical_hit_accuracy = crit_acc; }
void Hanzo::set_critical_hits_per_10_mins(double hits_per_10){ critical_hits_per_10_mins = hits_per_10; }
void Hanzo::set_critical_hit_kills_per_10_mins(double kills_per_10){ critical_hit_kills_per_10_mins = kills_per_10; }
// getters
int Hanzo::get_critical_hit_accuracy(){ return critical_hit_accuracy; }
double Hanzo::get_critical_hits_per_10_mins(){ return critical_hits_per_10_mins; }
double Hanzo::get_critical_hit_kills_per_10_mins(){ return critical_hit_kills_per_10_mins; }
std::string Hanzo::get_hero_name()const { return "hanzo"; }
void Hanzo::set_hero_specific_stats(const std::string& key, std::variant<int, double> value) {
    auto it = setter_map.find(key);
    if (it != setter_map.end()) {
        it->second(this, value);  // Execute the found setter function
    }
}

// setters
void Sojourn::set_charged_shot_accuracy(int charged_shot_acc){ charged_shot_accuracy = charged_shot_acc; }
void Sojourn::set_charged_shot_crit_accuracy(int charged_shot_crit_acc){ charged_shot_crit_accuracy = charged_shot_crit_acc; }
void Sojourn::set_charged_shot_kills_per_10_mins(double charged_shot_per_10){ charged_shot_kills_per_10_mins = charged_shot_per_10; }
// getters
int Sojourn::get_charged_shot_accuracy(){ return charged_shot_accuracy; }
int Sojourn::get_charged_shot_crit_accuracy(){ return charged_shot_crit_accuracy; }
double Sojourn::get_charged_shot_kills_per_10_mins(){ return charged_shot_kills_per_10_mins; }
std::string Sojourn::get_hero_name()const { return "sojourn"; }
void Sojourn::set_hero_specific_stats(const std::string& key, std::variant<int, double> value) {
    auto it = setter_map.find(key);
    if (it != setter_map.end()) {
        it->second(this, value);  // Execute the found setter function
    }
}

// setters
void Soldier76::set_critical_hit_accuracy(int crit_acc){ critical_hit_accuracy = crit_acc; }
void Soldier76::set_critical_hits_per_10_mins(double hits_per_10){ critical_hits_per_10_mins = hits_per_10; }
// getters
int Soldier76::get_critical_hit_accuracy(){ return critical_hit_accuracy; }
double Soldier76::get_critical_hits_per_10_mins(){ return critical_hits_per_10_mins; }
std::string Soldier76::get_hero_name()const { return "soldier-76"; }
void Soldier76::set_hero_specific_stats(const std::string& key, std::variant<int, double> value) {
    auto it = setter_map.find(key);
    if (it != setter_map.end()) {
        it->second(this, value);  // Execute the found setter function
    }
}

// setters
void Tracer::set_critical_hits_per_10_mins(double hits_per_10){ critical_hits_per_10_mins = hits_per_10; }
// getters
double Tracer::get_critical_hits_per_10_mins(){ return critical_hits_per_10_mins; }
std::string Tracer::get_hero_name()const { return "tracer"; }
void Tracer::set_hero_specific_stats(const std::string& key, std::variant<int, double> value) {
    auto it = setter_map.find(key);
    if (it != setter_map.end()) {
        it->second(this, value);  // Execute the found setter function
    }
}