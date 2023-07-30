#ifndef GAMEHANDELER
#define GAMEHANDELER
#include <iostream>
#include <string>
#include <thread>
#include <shared_mutex>
#include <mutex>
#include <string>
#include <functional>
#include <vector>
#include <utility>
#include <fstream>
#include <sstream>
#include "json.hpp"
#include "MainProgram.h"
#include "httplib.h"
using namespace nlohmann;



void handleYourTurn(const httplib::Request& req, httplib::Response& res);

//there should just be one GamHandeler
class GameHandeler {
public:
	GameHandeler(std::string host);
	GameHandeler();
	bool begin();
	int GetPort();
	std::string ready();
	~GameHandeler();
	json request(std::string url, std::string api, int port = 12345);
	json requestWithToken(std::string url, std::string api, int port = 12345);
	void join();

private:

	std::string host;
	std::string token;
	std::string public_key;
	int id;
	int port;
	std::thread* server_thread;
	httplib::Server* runServer(const char* host, const int PORT, std::vector<std::pair<std::string, std::function<void(const httplib::Request& req, httplib::Response& res)>>> urls);
	
	

};



#endif // !GAMEHANDELER;
