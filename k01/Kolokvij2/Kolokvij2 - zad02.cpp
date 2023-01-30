/*
2. zadatak (15 bodova)

Napišite program za analizu podataka o gledanju TV programa.

Podatke učitajte iz datoteke u formatu: korisnik (jedna riječ), vrijeme (sati:minute).

Primjer ulaznih podataka:

Ivan 0:45
Nika 0:35
Nika 0:35
Fran 1:40
Luka 0:30
Mia 0:25
Luka 0:30
Luka 0:05
Mia 0:40
Nika 0:35
Lucija 0:50
Lucija 0:43
Ivan 2:20
Ivan 0:45

Rezultate (ukupno vrijeme gledanja po korisniku) ispišite sortirano po imenu korisnika u obliku:

Fran = 1:40
Ivan = 3:50
Lucija = 1:33
Luka = 1:05
Mia = 1:05
Nika = 1:45

Uputstva: koristite std::map.
*/


#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <format>

struct userData {
    std::string name;
    std::string timeString;
};
/*
int main() {
    std::map<std::string, int> dataMap;

    std::ifstream f("zad02.txt");
    std::string line;

    if (f.is_open()) {
        userData user;
        while (f >> user.name >> user.timeString) {
            int minutes = 0;
            minutes += 60 * std::stoi(user.timeString.substr(0, 1));
            minutes += std::stoi(user.timeString.substr(2, 2));

            dataMap[user.name] += minutes;
        }
    }

    for (auto& it : dataMap) {
        std::cout << it.first << " = " << std::format("{}:{:0>2}", it.second / 60, it.second % 60) << std::endl;
    }
}
*/
