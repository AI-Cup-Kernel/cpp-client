#include "Game.h"
#include <map>
const bool DEBUGMODE = true;//set this to false to prevent extra information
json Game::get(std::string url, std::string api, int port) {
	
	//creating headers
	httplib::Headers headers;
	headers.emplace("x-access-token", this->token);
	
	httplib::Client client(url, port);
	//sending get request to server
	auto res = client.Get(api, headers);

	json result;
	//validating response
	if (res) {

		
		if (res->status == 200) {

			if (DEBUGMODE)
				std::cout << "request sent to " << api << " successfully" << std::endl;
			result = json::parse(res->body);
			result.push_back({ "status",true });
			return result;
		}
		else {
			result = json::parse(res->body);
			result.push_back({ "status",false });
			return result;
		}
	}
	else {
		result = json::parse("{}");
		result.push_back({ "status",false });
		return result;
	}

	//will not come to this
	return result;


}
json Game::post(std::string url, std::string api, httplib::MultipartFormDataItems items, int port) {
	//creating headers
	httplib::Headers headers;
	headers.emplace("x-access-token", this->token);

	httplib::Client client(url, port);
	//sending post request to server
	auto res = client.Post(api,headers, items);

	json result;
	//validating response
	if (res) {


		if (res->status == 200) {
			
			if (DEBUGMODE)
				std::cout << "request sent to " << api << " successfully" << std::endl;
			result = json::parse(res->body);
			result.push_back({ "status",true });
			return result;
		}
		else {
			result = json::parse(res->body);
			result.push_back({ "status",false });
			return result;
		}
	}
	else {
		result = json::parse("{}");
		result.push_back({ "status",false });
		return result;
	}

	//will not come to this
	return result;
}

void Game::SetToken(std::string token) { this->token = token; }
void Game::SetHostsPort(int port) { this->port = port; }
void Game::SetHost(std::string host) { this->host = host; }
int Game::getPlayerNumber() {
	json result = get(this->host, "/get_owners",this->port);
	if (result["status"]|| result.find("player_id") == result.end()) {
	
		return result["player_id"].get<int>();
	}
	else {
		std::cout << "unable to reach";
	}

}
int Game::getNumberOfTroopsToPut() {
	auto response = this->get(this->host, "/get_number_of_troops_to_put", this->port);

	if (response["status"]) {
		if (DEBUGMODE)
			std::cout <<"number of troops:" <<response["number_of_troops"]<<std::endl;
		return response["number_of_troops"].get<int>();


	}
	else {
		if(DEBUGMODE)
			std::cout << "something went wrog in getNumberOfTroopsToPut";


		return -1;
	}

}
bool Game::testServer() {

	auto response = this->get(this->host, "/", this->port);

	if (response["status"] && response.find("message")!=response.end()) {
		
		return true;


	}
	return false;

}
std::map<int, std::vector <int>> Game::getAdj() {
	auto response = this->get(this->host, "/get_adj", this->port);

	if (response["status"] ) {
		std::map<int, std::vector<int>> adjacent_matrix;
		
		for (const auto& item : response.items()) {
			if (item.key() != "status") {
				const int key = std::stoi(item.key());

				const std::vector<int>& value = item.value();
				adjacent_matrix[key] = value;
			}
		}

		// Print the map of vectors
		if (DEBUGMODE) {
			for (const auto& item : adjacent_matrix) {
				std::cout << "Key: " << item.first << " | Values: ";
				for (int val : item.second) {
					std::cout << val << " ";
				}
			}
			std::cout << std::endl;
		}

		return adjacent_matrix;


	}
	return {};
}
std::map<int, int> Game::getOwners() {
	auto response = this->get(this->host, "/get_owners",  this->port);

	if (response["status"]) {
		std::map<int, int> owners;

		for (const auto& item : response.items()) {
			if (item.key() != "status") {
				const int key = std::stoi(item.key());

				const int value = item.value().get<int>();
				owners[key] = value;
			}
		}

		// Print the map of vectors
		if (DEBUGMODE) {
			for (const auto& item : owners) {
				std::cout << item.first << ": " << item.second<<"     ";
			}
			std::cout << std::endl;
		}

		return owners;
	}

}
std::map<int, int> Game::getTroopsCount() {
	auto response = this->get(this->host, "/get_troops_count", this->port);

	if (response["status"]) {
		std::map<int, int> owners;

		for (const auto& item : response.items()) {
			if (item.key() != "status") {
				const int key = std::stoi(item.key());

				const int value = item.value().get<int>();
				owners[key] = value;
			}
		}

		// Print the map of vectors
		if (DEBUGMODE) {
			for (const auto& item : owners) {
				std::cout << item.first << ": " << item.second << "     ";
			}
			std::cout << std::endl;
		}

		return owners;
	}

}
int Game::getState() {
	auto response = this->get(this->host, "/get_state", this->port);

	if (response["status"] ) {
		if (DEBUGMODE)
			std::cout << response["state"] << std::endl;
		return response["state"].get<int>();


	}
	return -1;

}
int Game::getTurnNumber() {
	auto response = this->get(this->host, "/get_turn_number", this->port);

	if (response["status"]) {
		if (DEBUGMODE)
			std::cout << response["turn_number"] << std::endl;
		return response["turn_number"].get<int>();


	}
	return -1;

}
bool Game::nextState() {
	auto response = this->get(this->host, "/next_state", this->port);

	if (response["status"]&& response.find("message")!=response.end()) {
		if (DEBUGMODE)
			std::cout <<"next state:"<< response["message"] << std::endl;
		return true;


	}
	return false;

}
int Game::getPlayerID() {
	auto response = this->get(this->host, "/get_player_id", this->port);

	if (response["status"]) {
		if (DEBUGMODE)
			std::cout <<"playe id:"<< response["player_id"] << std::endl;
		return  response["player_id"];


	}
	return -1;

}
std::vector<std::pair<int,int>> Game::getStrategicNodes() {
	auto response = this->get(this->host, "/get_strategic_nodes", this->port);
	if (response["status"]) {
		const std::vector<int>& nodes= response["strategic_nodes"];
		const std::vector<int>& scores= response["score"];
		std::vector<std::pair<int, int>> result;
		for (int i = 0; i < nodes.size(); i++) {
			result.push_back({ nodes[i],scores[i] });
			if (DEBUGMODE)
				std::cout << nodes[i] <<":"<< scores[i]<<"   ";

		}

		return result;
	}
	return {};

	

}
bool Game::putOneTroop(int node) {
	//posting data to server
	auto response = post(this->host, "/put_one_troop", { {"node_id","1"}}, this->port);
	//seeing if the response is valid
	if (response["status"] && response.find("message") != response.end()) {
		if (DEBUGMODE)
			std::cout << "put on troop:" << response["message"] << std::endl;
		return true;


	}
	if(DEBUGMODE)
		std::cout << "put on troop:" << response["error"] << std::endl;
	return false;


}
bool Game::putTroop(int node, int number_of_troops) {
	//posting data to server
	auto response = post(this->host, "/put_troop", { {"node_id",std::to_string(node).c_str()},{"number_of_troops",std::to_string(number_of_troops).c_str()} }, this->port);
	//seeing if the response is valid
	if (response["status"] && response.find("message") != response.end()) {
		if (DEBUGMODE)
			std::cout << "put  troop:" << response["message"] << std::endl;
		return true;


	}
	if (DEBUGMODE)
		std::cout << "put  troop:" << response["error"] << std::endl;
	return false;
}
bool Game::attack(int origin_node, int target_node,float fraction) {
	//posting data to server
	auto response = post(this->host, "/attack", { {"attacking_id",std::to_string(origin_node).c_str()},
		{"target_id",std::to_string(target_node).c_str()},
		{"fraction",std::to_string(fraction).c_str()} }, this->port);
	//seeing if the response is valid
	if (response["status"] && response.find("message") != response.end()) {
		if (DEBUGMODE)
			std::cout << "attack:" << response["message"] << std::endl;
		return true;


	}
	if (DEBUGMODE)
		std::cout << "attack:" << response["error"] << std::endl;
	return false;
}
bool Game::moveTroops(int origin_node, int dest_node, float number_of_troops) {
	//posting data to server
	auto response = post(this->host, "/move_troop", { {"source",std::to_string(origin_node).c_str()},
		{"destination",std::to_string(dest_node).c_str()},
		{"troop_count",std::to_string(number_of_troops).c_str()} }, this->port);
	//seeing if the response is valid
	if (response["status"] && response.find("message") != response.end()) {
		if (DEBUGMODE)
			std::cout << "move troops:" << response["message"] << std::endl;
		return true;


	}
	if (DEBUGMODE)
		std::cout << "move troops:" << response["error"] << std::endl;
	return false;
}
std::vector<int> Game::getReachable(int node) {
	//posting data to server
	auto response = post(this->host, "/get_reachable", { {"node_id",std::to_string(node).c_str()},},  this->port);
	if (response["status"] ) {
		
		return response["reachable"];


	}
	if (DEBUGMODE)
		std::cout << "get reachable:" << response["error"] << std::endl;
	return {};


}