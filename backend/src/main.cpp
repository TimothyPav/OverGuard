#include "Json_Serializer.h"
#include "crow/middlewares/cors.h"

#include <crow.h>
#include <string>
#include <nlohmann/json.hpp>

int main() {
    crow::App<crow::CORSHandler> app;

    auto& cors = app.get_middleware<crow::CORSHandler>();

    cors
      .global()
        .headers("X-Custom-Header", "Upgrade-Insecure-Requests")
        .methods("POST"_method, "GET"_method)
      .prefix("/")
        .origin("http://localhost:1234")
      .prefix("/nocors")
        .ignore();




    CROW_ROUTE(app, "/api/player")
    ([](const crow::request& req)
    {
        std::string battletag = req.url_params.get("battletag");
        std::cout << battletag << std::endl;
        nlohmann::json j = serialize_player_input(battletag);
        if(j.is_null()) return crow::response(404);
        return crow::response{j.dump()};
    });

    CROW_ROUTE(app, "/api/hero_stat")
    ([](const crow::request& req)
    {
        std::cout << "IS THIS RUNNING???? \n";
        std::string hero_name = req.url_params.get("hero_name");
        std::string column = req.url_params.get("column");
        std::cout << "hero_name --> " << hero_name << "column --> " << column << std::endl;
        nlohmann::json j = serialize_specific_hero_stat(hero_name, column);
        if(j.is_null()) return crow::response(404);
        return crow::response{j.dump()};
    });

    app.port(3000).run();
}