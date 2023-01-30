#include <fstream>
#include <iostream>
#include <map>
#include <format>

using namespace std;

int main(const int argc, const char* argv[]){
	map<string, int> d;
	ifstream f(argv[1]);
	string s; 
	char c;
	int h, m;
	while (f >> s >> h >> c >> m)
		d[s] += h*60 + m;
	for (const auto& [name, time] : d)
		cout << format("{} = {}:{:02}\n", name, time / 60, time % 60);
}
