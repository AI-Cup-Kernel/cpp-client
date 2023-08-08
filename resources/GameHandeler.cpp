#include "GameHandeler.h"
httplib::Server* server;
std::string server_token;

const bool DEBUGMODE = true;
void handleYourTurn(const httplib::Request& req, httplib::Response& res) {

	for (auto i : req.headers)
		std::cout << i.first<<"    ";
	std::cout << std::endl << std::endl;
	
	if (req.headers.find(" x-access-tokens") != req.headers.end() 
		&& req.headers.find(" x-access-tokens")->second == server_token) {
		
		res.set_content("my turn!", "text/plain");
	}
	else {

	}

}
GameHandeler::GameHandeler() {
	this->token = "";
	this->id = -1;
	this->port = -1;
	this->host = "127.0.0.1";
	this->server_thread = nullptr;

	server_token = this->generateToken();
}
GameHandeler::GameHandeler(std::string host,int port) {
	this->token = "";
	this->id = -1;
	this->port = -1;
	this->host = host;
	this->port = port;
	this->server_thread = nullptr;
	server_token = this->generateToken();
}
bool GameHandeler::begin() {

	json response = this->SendloginRequest(this->host);
	if (response["status"]) {
		if (response.find("player_id") == response.end()) {

			return false;
		}
		else {
			this->port = response["port"].get<int>();
			this->token = response["token"];
			this->id = response["player_id"];
			if (DEBUGMODE)
				std::cout << this->token;
			this->ready();

			return true;
		}
	}
}
void GameHandeler::ready() {
	//we could use shared mutex but I didnt want to get in trouble because of c++ various versions
	std::string message;


	server = this->runServer("127.0.0.1", this->port, { {"/turn",handleYourTurn} });
	//waits untill server is running
	while (!server->is_running()) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));

	}


	json response = this->request(this->host, "/ready", 12345);

	if (response["status"]) {

		message = response["message"];

	}
	else {
		message = "request failed";
	}
	if (DEBUGMODE)
		std::cout << message << std::endl;
	

}


int GameHandeler::GetPort() { return this->port; }
std::string GameHandeler::GetToken() { return this->token; }

httplib::Server* GameHandeler::runServer(const char* host, const int PORT, std::vector<std::pair<std::string, std::function<void(const httplib::Request& req, httplib::Response& res)>>> urls) {
	server = new httplib::Server();
	for (auto itr : urls)
		server->Get(itr.first, itr.second);

	server_thread = new std::thread([this, host, PORT]() {
		server->listen(host, PORT);
		});




	return server;
}
json GameHandeler::SendloginRequest(std::string url, int port) {
	httplib::Client client(url, port);
	httplib::MultipartFormDataItems items = { {"token",generateToken()} };



	auto res = client.Post("/login", items);
	json result;

	if (res) {
		if (res->status == 200) {
			if (DEBUGMODE)
				std::cout << "login complete" << std::endl;



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

json GameHandeler::request(std::string url, std::string api, int port) {
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
void GameHandeler::join() {
	if (server_thread != nullptr) {
		server->stop();
		server_thread->join();
	}
}



std::string GameHandeler::generateToken() {
	const int otpLength = 32;
	const std::string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	std::string otp;
	std::mt19937 rng(std::time(0));
	std::uniform_int_distribution<int> dist(0, chars.size() - 1);

	for (int i = 0; i < otpLength; ++i) {
		otp += chars[dist(rng)];
	}
	if (DEBUGMODE)
		std::cout << "server token: " << otp << std::endl;
	return "salam";
	return otp;



}

GameHandeler::~GameHandeler() {


}


