#ifndef GAME
#define GAME
const int NumberOfRegions=43;
#include <iostream>
#include <string>
#include <vector>
#include "../compile/stdafx.h"

using namespace nlohmann;
class Game {
public:
	//setters getters with Capital letters first
	void SetToken(std::string token);
	void SetHostsPort(int port);
	void SetHost(std::string host);
	//requests with ordinary naming
	int getNumberOfTroopsToPut();
	bool testServer();
	std::map<int, std::vector <int>> getAdj();
	std::map<int, int> getOwners();
	std::map<int, int> getTroopsCount();
	int getState();
	int getTurnNumber();
	bool nextState();
	int getPlayerID();
	std::vector<std::pair<int, int>> getStrategicNodes();
	bool putOneTroop(int node);
	bool putTroop(int node, int number_of_troops);
	bool attack(int origin_node, int target_node, float fraction);
	bool moveTroops(int origin_node, int dest_node, float number_of_troops);
	int getPlayerNumber();
	bool getReachable(int node);


	

	
	


private:
	std::string host;
	int port;
	std::string token;
	json get(std::string url, std::string api, int port = 12345);
	json post(std::string url, std::string api, httplib::MultipartFormDataItems items, int port = 12345);

};
#endif
