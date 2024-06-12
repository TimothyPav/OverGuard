#include "APIHandler.h"

#include <iostream>
#include <cpr/cpr.h>

int main(int argc, char** argv) {
    cpr::Response r = cpr::Get(cpr::Url{"https://overfast-api.tekrop.fr/players/Cash-11893/stats?gamemode=competitive&platform=pc&hero=widowmaker"});
    r.status_code;                  // 200
    r.header["content-type"];       // application/json; charset=utf-8
    r.text;                     // JSON text string
    std::cout << r.status_code << std::endl;
    std::cout << r.header["content-type"] << std::endl;
    std::cout << r.text;
}