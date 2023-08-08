#ifndef GAME
#define GAME
const int NumberOfRegions=43;
#include <iostream>

#include <vector>
#include "../externals/httplib.h"
#include "../externals/json.hpp"
using namespace nlohmann;
class Game {
public:
	//setters getters with Capital letters first
	void SetToken(std::string token);
	void SetHostsPort(int port);
	void SetHost(std::string host);
	//requests with ordinary naming
	std::map<int, int> getTroopCount();
	std::map<int, int> getOwners();
	int getTurn();
	int getState();
	int getPlayerNumber();
	bool isReachable(int node1, int node2);


private:
	std::string host;
	int port;
	std::string token;
	json request(std::string url, std::string api, int port = 12345);

};
#endif
