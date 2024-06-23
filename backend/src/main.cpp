#include "Crow_Routes.h"
#include "Json_Serializer.h"

#include <crow.h>
#include <string>
#include <nlohmann/json.hpp>

int main() {
    crow::SimpleApp app;

    setup_routes(app);

    app.port(3000).multithreaded().run();
}