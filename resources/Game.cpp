#include "Game.h"
#include <map>
const bool DEBUGMODE = true;
json Game::request(std::string url, std::string api, int port) {
	httplib::Headers headers;
	headers.emplace("x-access-token", this->token);
	httplib::Client client(url, port);

	auto res = client.Get(api, headers);

	json result;
	if (res) {

		if (res->status == 200) {

			if (DEBUGMODE)
				std::cout << "request sent to " << api << "successfully" << std::endl;
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
std::map<int, int> Game::getOwners() {
	std::map<int, int> owners;
	json result = request(this->host, "\get_owners");
	
	for (const auto& i : result.items()) {
	
		result[stoi(i.key())] = i.value().get<int>();
	}

	return owners;

}