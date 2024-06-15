#ifndef HEROES_H
#define HEREOS_H

#include <string>
#include <iostream>
#include <vector>
#include <variant>
#include <map>
#include <functional>

class Heroes {
    private:
        double deaths_per_10_mins;
        double final_blows_per_10_mins;
        double solo_kills_per_10_mins;
        double hero_damage_done_per_10_mins;

    public:
        Heroes() {}

        // setters
        void set_deaths_per_10_mins(double deaths);
        void set_final_blows_per_10_mins(double final_blows);
        void set_solo_kills_per_10_mins(double solo_kills);
        void set_hero_damage_done_per_10_mins(double damage);

        // getters
        double get_deaths_per_10_mins();
        double get_final_blows_per_10_mins();
        double get_solo_kills_per_10_mins();
        double get_hero_damage_done_per_10_mins();
};

class Widowmaker : public Heroes {
    private:
        int scoped_accuracy;
        int scoped_crit_accuracy;
        double scoped_crit_hits_per_10_mins;
        double scoped_crit_kills_per_10_mins;
        std::map<std::string, std::function<void(Widowmaker*, std::variant<int, double>)>> setter_map;

    public:
        Widowmaker() {}

        // setters
        void set_scoped_accuracy(int scoped_acc);
        void set_scoped_crit_accuracy(int scoped_crit_acc);
        void set_scoped_crit_hits_per_10_mins(double scoped_crit_hits);
        void set_scoped_crit_kills_per_10_mins(double scoped_crit_kills);

        // getters
        int get_scoped_accuracy();
        int get_scoped_crit_accuracy();
        double get_scoped_crit_hits_per_10_mins();
        double get_scoped_crit_kills_per_10_mins();

        // methods
        void set_hero_specific_stats(const std::string& key, std::variant<int, double> value);
};

class Ashe: public Heroes {
    private:
        int scoped_accuracy;
        int scoped_crit_accuracy;
        double scoped_crit_hits_per_10_mins;
        double scoped_crit_kills_per_10_mins;
        std::map<std::string, std::function<void(Ashe*, std::variant<int, double>)>> setter_map;

    public:
        Ashe() {}

        // setters
        void set_scoped_accuracy(int scoped_acc);
        void set_scoped_crit_accuracy(int scoped_crit_acc);
        void set_scoped_crit_hits_per_10_mins(double scoped_crit_hits);
        void set_scoped_crit_kills_per_10_mins(double scoped_crit_kills);

        // getters
        int get_scoped_accuracy();
        int get_scoped_crit_accuracy();
        double get_scoped_crit_hits_per_10_mins();
        double get_scoped_crit_kills_per_10_mins();

        // methods
        void set_hero_specific_stats(const std::string& key, std::variant<int, double> value);
};

class Cassidy: public Heroes {
    private:
        int critical_hit_accuracy;
        double critical_hits_per_10_mins;
        double critical_hit_kills_per_10_mins;
        std::map<std::string, std::function<void(Widowmaker*, std::variant<int, double>)>> setter_map;

    public:
        Cassidy() {}

        // setters
        void set_critical_hit_accuracy(int crit_acc);
        void set_critical_hits_per_10_mins(double hits_per_10);
        void set_critical_hit_kills_per_10_mins(double kills_per_10);

        // getters
        int get_critical_hit_accuracy();
        double get_critical_hits_per_10_mins();
        double get_critical_hit_kills_per_10_mins();
};

class Hanzo: public Heroes {
    private:
        int critical_hit_accuracy;
        double critical_hits_per_10_mins;
        double critical_hit_kills_per_10_mins;
        std::map<std::string, std::function<void(Widowmaker*, std::variant<int, double>)>> setter_map;

    public:
        Hanzo() {}

        // setters
        void set_critical_hit_accuracy(int crit_acc);
        void set_critical_hits_per_10_mins(double hits_per_10);
        void set_critical_hit_kills_per_10_mins(double kills_per_10);

        // getters
        int get_critical_hit_accuracy();
        double get_critical_hits_per_10_mins();
        double get_critical_hit_kills_per_10_mins();
};

class Sojourn: public Heroes {
    private:
        int charged_shot_accuracy;
        int charged_shot_crit_accuracy;
        double charged_shot_kills_per_10_mins;
        std::map<std::string, std::function<void(Widowmaker*, std::variant<int, double>)>> setter_map;

    public:
        Sojourn() {}

        // setters
        void set_charged_shot_accuracy(int charged_shot_acc);
        void set_charged_shot_crit_accuracy(int charged_shot_crit_acc);
        void set_charged_shot_kills_per_10_mins(double charged_shot_per_10);

        // getters
        int get_charged_shot_accuracy();
        int get_charged_shot_crit_accuracy();
        double get_charged_shot_kills_per_10_mins();
};

class Soldier76: public Heroes {
    private:
        int critical_hit_accuracy;
        double critical_hits_per_10_mins;
        std::map<std::string, std::function<void(Widowmaker*, std::variant<int, double>)>> setter_map;

    public:
        Soldier76() {}

        // setters
        void set_critical_hit_accuracy(int crit_acc);
        void set_critical_hits_per_10_mins(double hits_per_10);

        // getters
        int get_critical_hit_accuracy();
        double get_critical_hits_per_10_mins();
};

class Tracer: public Heroes {
    private:
        double critical_hits_per_10_mins;
        std::map<std::string, std::function<void(Widowmaker*, std::variant<int, double>)>> setter_map;

    public:
        Tracer() {}

        // setters
        void set_critical_hits_per_10_mins(double hits_per_10);

        // getters
        double get_critical_hits_per_10_mins();
};


#endif