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
#include <random>
#include <functional>
#include <map>
#include "../externals/json.hpp"
#include "MainProgram.h"
#include "../externals/httplib.h"


using namespace nlohmann;



void handleYourTurn(const httplib::Request& req, httplib::Response& res);

//there should just be one GamHandeler
class GameHandeler {
public:
	GameHandeler(std::string host);
	GameHandeler();
	//initialization function
	bool begin();

	int GetPort();

	void join();

	//in game functions
	std::map<int, int> getTroopCount();
	int getTurn();
	int getState();
	int getPlayerNumber();
	bool isReachable(int node1, int node2);



	//---------------


	~GameHandeler();



private:
	void ready();
	std::string host;
	std::string token;
	int id;
	int port;
	std::thread* server_thread;
	httplib::Server* runServer(const char* host, const int PORT, std::vector<std::pair<std::string, std::function<void(const httplib::Request& req, httplib::Response& res)>>> urls);
	std::string generateToken();
	json request(std::string url, std::string api, int port = 12345);
	json SendloginRequest(std::string url, int port = 12345);





};



#endif // !GAMEHANDELER;
