#ifndef REQUESTS
#define REQUESTS
#include "httplib.h"
#include <functional>
#include <vector>
#include <utility>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


std::string request(std::string url, std::string api, int port);
std::string request(std::string url, std::string api);
void runServer(const char* host, const int PORT, std::vector < std::pair<std::string, std::function<void(const httplib::Request& req, httplib::Response& res)>>> urls);

#endif // !REQUESTS

