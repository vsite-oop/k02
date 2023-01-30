#include <algorithm>

#include <iostream>
#include <fstream>
#include <map>

class vrijeme {
private:
	int sati;
	int minute;
public:
	vrijeme(int sat, int min) : sati(sat), minute(min) {};
};

int main() {
	std::ifstream file("/file.txt");
    std::string key;
    std::string val;
	std::map<std::string, vrijeme> mapa;


	while (file >> key >> val) {
		mapa[key] = val;
	}
}