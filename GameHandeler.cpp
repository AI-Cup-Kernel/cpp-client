#include "GameHandeler.h"
#include "requests.h"
httplib::Server* server; 
void handleYourTurn(const httplib::Request& req, httplib::Response& res) {
	YourTurn();
	res.set_content("Hello, API!", "text/plain");

}
GameHandeler::GameHandeler() {
	this->token = "";
	this->public_key = "";
	this->id = -1;
	this->port = -1;
	this->host = "127.0.0.1";
	this->server_thread = nullptr;
}
GameHandeler::GameHandeler(std::string host) {
	this->token = "";
	this->public_key = "";
	this->id = -1;
	this->port = -1;
	this->host = host;
	this->server_thread = nullptr;
}
bool GameHandeler::begin() {

	json response = this->request(host.c_str(), "/login", 12345);
	if (response["status"] ) {
		if (response.find("player_id") == response.end()) {

			return false;
		}
		else {
			this->port = 0;
			this->port = response["port"].get<int>();
			this->token = response["token"];
			this->public_key = response["public_key"];
			this->id = response["player_id"];
			this->ready();
			return true;
		}
	}
}
std::string GameHandeler::ready() {
	//we could use shared mutex but I didnt want to get in trouble because of c++ various versions
	std::string message;
	

	server=this->runServer("127.0.0.1", this->port, {{"/hello",handleYourTurn}});
	//waits untill server is running
	while (!server->is_running()) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));

	}

	
	json response = this->requestWithToken(this->host, "/ready", 12345);
	
	if (response["status"]) {

		message = response["message"];

	}
	else {
		message = "request failed";
	}
	std::cout << message;
	return message;

}
int GameHandeler::GetPort() { return this->port; }

httplib::Server* GameHandeler::runServer(const char* host, const int PORT, std::vector<std::pair<std::string, std::function<void(const httplib::Request& req, httplib::Response& res)>>> urls) {
	server = new httplib::Server();
	for (auto itr : urls)
		server->Get(itr.first, itr.second);

	server_thread=new std::thread([this,host,PORT]() {
		server->listen(host, PORT);
		});
	

	
	
	return server;
}
json GameHandeler::request(std::string url, std::string api, int port  ) {
	httplib::Client client(url, port);

	auto res = client.Get(api);
	json result;

	if (res) {
		if (res->status == 200) {

			std::cout << res->body;
			result = json::parse(res->body);
			std::cout << result["port"];
			result.push_back({ "status",true });
			std::cout << result["port"];
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
json GameHandeler::requestWithToken(std::string url, std::string api ,int port ) {
	httplib::Headers headers;
	headers.emplace("x-access-token", this->token);
	httplib::Client client(url,port);

	auto res = client.Get(api,headers);
	json result;

	if (res) {
		
		if (res->status == 200) {
			// Print the response body
			result = json::parse(res->body);
			result.push_back({ "status",true });
			return result;
		}
		else {
			std::cout << res->body;
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
void GameHandeler::join() {
	if (server_thread != nullptr) {
		server->stop();
		server_thread->join();
	}
}
GameHandeler::~GameHandeler() {
	

}