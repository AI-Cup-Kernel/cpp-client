#include "requests.h"


std::string request(std::string url) {
	system((std::string("python request.py ")+url).c_str());
	std::ifstream file("result.txt");
	std::string line = "";
	std::string result = "";
	while (std::getline(file, line)) {
		result += line;
	}
	return result;


}