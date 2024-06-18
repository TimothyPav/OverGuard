#ifndef HEROES_H
#define HEROES_H

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
        bool is_enough_playtime;

    public:
        Heroes() {}

        // setters
        void set_deaths_per_10_mins(double deaths);
        void set_final_blows_per_10_mins(double final_blows);
        void set_solo_kills_per_10_mins(double solo_kills);
        void set_hero_damage_done_per_10_mins(double damage);
        void set_is_enough_playtime(bool val);
        virtual void set_hero_specific_stats(const std::string& key, std::variant<int, double> value);

        // getters
        double get_deaths_per_10_mins();
        double get_final_blows_per_10_mins();
        double get_solo_kills_per_10_mins();
        double get_hero_damage_done_per_10_mins();
        bool get_is_enough_playtime();
        virtual std::string get_hero_name() const;

        // hero stats to be overriden...
        virtual int get_scoped_accuracy() const;
        virtual int get_scoped_crit_accuracy() const;
        virtual double get_scoped_crit_hits_per_10_mins() const;
        virtual double get_scoped_crit_kills_per_10_mins() const;
        virtual int get_critical_hit_accuracy() const;
        virtual double get_critical_hits_per_10_mins() const;
        virtual double get_critical_hit_kills_per_10_mins() const;
        virtual int get_charged_shot_accuracy() const;
        virtual int get_charged_shot_crit_accuracy() const;
        virtual double get_charged_shot_kills_per_10_mins() const;
};

class Widowmaker : public Heroes {
    private:
        int scoped_accuracy;
        int scoped_crit_accuracy;
        double scoped_crit_hits_per_10_mins;
        double scoped_crit_kills_per_10_mins;
        std::map<std::string, std::function<void(Widowmaker*, std::variant<int, double>)>> setter_map;

    public:
        Widowmaker() {
            setter_map["scoped_accuracy"] = [](Widowmaker* obj, std::variant<int, double> value) {
                std::visit([&](auto&& arg){ obj->set_scoped_accuracy(arg); }, value);
            };
            setter_map["scoped_critical_hit_accuracy"] = [](Widowmaker* obj, std::variant<int, double> value) {
                std::visit([&](auto&& arg){ obj->set_scoped_crit_accuracy(arg); }, value);
            };
            setter_map["scoped_critical_hits_avg_per_10_min"] = [](Widowmaker* obj, std::variant<int, double> value) {
                std::visit([&](auto&& arg){ obj->set_scoped_crit_hits_per_10_mins(arg); }, value);
            };
            setter_map["scoped_critical_hit_kills_avg_per_10_min"] = [](Widowmaker* obj, std::variant<int, double> value) {
                std::visit([&](auto&& arg){ obj->set_scoped_crit_kills_per_10_mins(arg); }, value);
            };
        }

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
        std::string get_hero_name()const override;

        // methods
        void set_hero_specific_stats(const std::string& key, std::variant<int, double> value) override;
};

class Ashe: public Heroes {
    private:
        int scoped_accuracy;
        int scoped_crit_accuracy;
        double scoped_crit_hits_per_10_mins;
        double scoped_crit_kills_per_10_mins;
        std::map<std::string, std::function<void(Ashe*, std::variant<int, double>)>> setter_map;

    public:
        Ashe() {
            setter_map["scoped_accuracy"] = [](Ashe* obj, std::variant<int, double> value) {
                std::visit([&](auto&& arg){ obj->set_scoped_accuracy(arg); }, value);
            };
            setter_map["scoped_critical_hit_accuracy"] = [](Ashe* obj, std::variant<int, double> value) {
                std::visit([&](auto&& arg){ obj->set_scoped_crit_accuracy(arg); }, value);
            };
            setter_map["scoped_critical_hits_avg_per_10_min"] = [](Ashe* obj, std::variant<int, double> value) {
                std::visit([&](auto&& arg){ obj->set_scoped_crit_hits_per_10_mins(arg); }, value);
            };
            setter_map["scoped_critical_hit_kills_avg_per_10_min"] = [](Ashe* obj, std::variant<int, double> value) {
                std::visit([&](auto&& arg){ obj->set_scoped_crit_kills_per_10_mins(arg); }, value);
            };
        }

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
        std::string get_hero_name() const override;

        // methods
        void set_hero_specific_stats(const std::string& key, std::variant<int, double> value) override;
};

class Cassidy: public Heroes {
    private:
        int critical_hit_accuracy;
        double critical_hits_per_10_mins;
        double critical_hit_kills_per_10_mins;
        std::map<std::string, std::function<void(Cassidy*, std::variant<int, double>)>> setter_map;

    public:
        Cassidy() {
            setter_map["critical_hit_accuracy"] = [](Cassidy* obj, std::variant<int, double> value) {
                std::visit([&](auto&& arg){ obj->set_critical_hit_accuracy(arg); }, value);
            };
            setter_map["critical_hits_avg_per_10_min"] = [](Cassidy* obj, std::variant<int, double> value) {
                std::visit([&](auto&& arg){ obj->set_critical_hits_per_10_mins(arg); }, value);
            };
            setter_map["critical_hit_kills_avg_per_10_min"] = [](Cassidy* obj, std::variant<int, double> value) {
                std::visit([&](auto&& arg){ obj->set_critical_hit_kills_per_10_mins(arg); }, value);
            };
        }

        // setters
        void set_critical_hit_accuracy(int crit_acc);
        void set_critical_hits_per_10_mins(double hits_per_10);
        void set_critical_hit_kills_per_10_mins(double kills_per_10);

        // getters
        int get_critical_hit_accuracy();
        double get_critical_hits_per_10_mins();
        double get_critical_hit_kills_per_10_mins();
        std::string get_hero_name() const override;

        // methods
        void set_hero_specific_stats(const std::string& key, std::variant<int, double> value) override;
};

class Hanzo: public Heroes {
    private:
        int critical_hit_accuracy;
        double critical_hits_per_10_mins;
        double critical_hit_kills_per_10_mins;
        std::map<std::string, std::function<void(Hanzo*, std::variant<int, double>)>> setter_map;

    public:
        Hanzo() {
            setter_map["critical_hit_accuracy"] = [](Hanzo* obj, std::variant<int, double> value) {
                std::visit([&](auto&& arg){ obj->set_critical_hit_accuracy(arg); }, value);
            };
            setter_map["critical_hits_avg_per_10_min"] = [](Hanzo* obj, std::variant<int, double> value) {
                std::visit([&](auto&& arg){ obj->set_critical_hits_per_10_mins(arg); }, value);
            };
            setter_map["critical_hit_kills_avg_per_10_min"] = [](Hanzo* obj, std::variant<int, double> value) {
                std::visit([&](auto&& arg){ obj->set_critical_hit_kills_per_10_mins(arg); }, value);
            };
        }

        // setters
        void set_critical_hit_accuracy(int crit_acc);
        void set_critical_hits_per_10_mins(double hits_per_10);
        void set_critical_hit_kills_per_10_mins(double kills_per_10);

        // getters
        int get_critical_hit_accuracy();
        double get_critical_hits_per_10_mins();
        double get_critical_hit_kills_per_10_mins();
        std::string get_hero_name() const override;

        // methods
        void set_hero_specific_stats(const std::string& key, std::variant<int, double> value) override;
};

class Sojourn: public Heroes {
    private:
        int charged_shot_accuracy;
        int charged_shot_crit_accuracy;
        double charged_shot_kills_per_10_mins;
        std::map<std::string, std::function<void(Sojourn*, std::variant<int, double>)>> setter_map;

    public:
        Sojourn() {
            setter_map["charged_shot_accuracy"] = [](Sojourn* obj, std::variant<int, double> value) {
                std::visit([&](auto&& arg){ obj->set_charged_shot_accuracy(arg); }, value);
            };
            setter_map["charged_shot_critical_accuracy"] = [](Sojourn* obj, std::variant<int, double> value) {
                std::visit([&](auto&& arg){ obj->set_charged_shot_crit_accuracy(arg); }, value);
            };
            setter_map["charged_shot_kills_avg_per_10_min"] = [](Sojourn* obj, std::variant<int, double> value) {
                std::visit([&](auto&& arg){ obj->set_charged_shot_kills_per_10_mins(arg); }, value);
            };
        }

        // setters
        void set_charged_shot_accuracy(int charged_shot_acc);
        void set_charged_shot_crit_accuracy(int charged_shot_crit_acc);
        void set_charged_shot_kills_per_10_mins(double charged_shot_per_10);

        // getters
        int get_charged_shot_accuracy();
        int get_charged_shot_crit_accuracy();
        double get_charged_shot_kills_per_10_mins();
        std::string get_hero_name() const override;

        // methods
        void set_hero_specific_stats(const std::string& key, std::variant<int, double> value) override;
};

class Soldier76: public Heroes {
    private:
        int critical_hit_accuracy;
        double critical_hits_per_10_mins;
        std::map<std::string, std::function<void(Soldier76*, std::variant<int, double>)>> setter_map;

    public:
        Soldier76() {
            setter_map["critical_hit_accuracy"] = [](Soldier76* obj, std::variant<int, double> value) {
                std::visit([&](auto&& arg){ obj->set_critical_hit_accuracy(arg); }, value);
            };
            setter_map["critical_hits_avg_per_10_min"] = [](Soldier76* obj, std::variant<int, double> value) {
                std::visit([&](auto&& arg){ obj->set_critical_hits_per_10_mins(arg); }, value);
            };
        }

        // setters
        void set_critical_hit_accuracy(int crit_acc);
        void set_critical_hits_per_10_mins(double hits_per_10);

        // getters
        int get_critical_hit_accuracy();
        double get_critical_hits_per_10_mins();
        std::string get_hero_name() const override;

        // methods
        void set_hero_specific_stats(const std::string& key, std::variant<int, double> value) override;
};

class Tracer: public Heroes {
    private:
        double critical_hits_per_10_mins;
        std::map<std::string, std::function<void(Tracer*, std::variant<int, double>)>> setter_map;

    public:
        Tracer() {
            setter_map["critical_hits_avg_per_10_min"] = [](Tracer* obj, std::variant<int, double> value) {
                std::visit([&](auto&& arg){ obj->set_critical_hits_per_10_mins(arg); }, value);
            };
        }

        // setters
        void set_critical_hits_per_10_mins(double hits_per_10);

        // getters
        double get_critical_hits_per_10_mins();
        std::string get_hero_name() const override;

        // methods
        void set_hero_specific_stats(const std::string& key, std::variant<int, double> value) override;
};


#endif