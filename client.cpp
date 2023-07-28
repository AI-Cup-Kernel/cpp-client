#include <iostream>

#include <string>
#include <map>
#include <winsock2.h>
#include <sstream>
#include <chrono>
#include "requests.h"
#include "MainProgram.h"
#pragma comment(lib, "ws2_32.lib")

const int PORT = 8080;//set the port here
const std::string response = "salam daaaaash";//set this to the response you want to give if the request reaches your-turn
std::string handleGetRequest(const std::string& url) {
    if (url == "/your-turn") {
        YourTurn();
        return response;
    }
    else {
        return "404 Not Found";
    }
}

int main() {
    // Initialize Winsock
    std::cout<<request("https://google.com");
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed." << std::endl;
        return 1;
    }

    // Create a socket
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Socket creation failed." << std::endl;
        WSACleanup();
        return 1;
    }

    // Prepare the sockaddr_in structure
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    // Bind the socket to the specified port
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        std::cerr << "Socket bind failed." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Listen failed." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Server started. Listening on port " << PORT << std::endl;

    while (true) {
        // Accept a client connection
        struct sockaddr_in clientAddress;
        int clientAddressSize = sizeof(clientAddress);
        SOCKET clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressSize);
        if (clientSocket == INVALID_SOCKET) {
            std::cerr << "Accept failed." << std::endl;
            closesocket(serverSocket);
            WSACleanup();
            return 1;
        }

        // Receive the HTTP request from the client
        char buffer[4096];
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);

        if (bytesReceived > 0) {
            buffer[bytesReceived] = '\0';

            // Parse the HTTP request to extract the requested URL
            std::istringstream iss(buffer);
            std::string requestMethod, requestUrl;
            iss >> requestMethod >> requestUrl;

            // Check if the request is a GET request
            if (requestMethod == "GET") {
                std::string response = handleGetRequest(requestUrl);

                // Send the HTTP response back to the client
                std::ostringstream oss;
                oss << "HTTP/1.1 200 OK\r\n"
                    << "Content-Type: text/plain\r\n"
                    << "Content-Length: " << response.length() << "\r\n\r\n"
                    << response;

                std::string httpResponse = oss.str();
                send(clientSocket, httpResponse.c_str(), httpResponse.length(), 0);
            }
            else {
                // For other HTTP methods, return a 405 Method Not Allowed response
                std::string notAllowedResponse = "405 Method Not Allowed";
                std::ostringstream oss;
                oss << "HTTP/1.1 405 Method Not Allowed\r\n"
                    << "Content-Type: text/plain\r\n"
                    << "Content-Length: " << notAllowedResponse.length() << "\r\n\r\n"
                    << notAllowedResponse;

                std::string httpResponse = oss.str();
                send(clientSocket, httpResponse.c_str(), httpResponse.length(), 0);
            }
        }

        // Close the client socket
        closesocket(clientSocket);
    }

    // Close the server socket and cleanup Winsock
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
