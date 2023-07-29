#include <iostream>

#include <string>
#include <map>
#include <winsock2.h>
#include <sstream>
#include <chrono>
#include "requests.h"
#include "MainProgram.h"
#pragma comment(lib, "ws2_32.lib")

const int PORT = 8080;//set the port here
const std::string response = "salam daaaaash";//set this to the response you want to give if the request reaches your-turn


void handleYourTurn(const httplib::Request& req, httplib::Response& res) {
    YourTurn();
    res.set_content("Hello, API!", "text/plain");

}int main() {
    runServer("127.0.0.1", 8080, {{ "/hello",handleYourTurn }});
   
}
