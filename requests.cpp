#include "requests.h"




void handle_greet(const httplib::Request& req, httplib::Response& res) {
    std::string name = req.matches[1]; // Extracts the name from the URL
    res.set_content("Hello, " + name + "!", "text/plain");
}

std::string request(std::string url,std::string api,int port) {
    httplib::Client client(url, port);

    auto res = client.Get(api);


    if (res) {
        if (res->status == 200) {
            // Print the response body
            std::cout << "Response data:\n" << res->body << std::endl;
        }
        else {
            std::cerr << "Request failed. Status code: " << res->status << std::endl;
        }
    }
    else {
        std::cerr << "Failed to connect to the server." << std::endl;
    }

    return "";


}
std::string request(std::string url, std::string api) {
    httplib::Client client(url);

    auto res = client.Get(api);


    if (res) {
        if (res->status == 200) {
            // Print the response body
            std::cout << "Response data:\n" << res->body << std::endl;
        }
        else {
            std::cerr << "Request failed. Status code: " << res->status << std::endl;
        }
    }
    else {
        std::cerr << "Failed to connect to the server." << std::endl;
    }

    return "";


}
void runServer(const char* host,const int PORT,std::vector<std::pair<std::string, std::function<void(const httplib::Request& req, httplib::Response& res)>>> urls){
    httplib::Server server;
    for(auto itr:urls)
        server.Get(itr.first,itr.second);
    //server.Get("/hi", handle_hello);

    server.listen(host, PORT);
}
