//
// Created by Tin Rupcic on 30.01.2023..
//
//2. zadatak (15 bodova)
//Napišite program za analizu podataka o gledanju TV programa.
//
//Podatke učitajte iz datoteke u formatu: korisnik (jedna riječ), vrijeme (sati:minute).
//
//Primjer ulaznih podataka:
//
//Ivan 0:45
//Nika 0:35
//Nika 0:35
//Fran 1:40
//Luka 0:30
//Mia 0:25
//Luka 0:30
//Luka 0:05
//Mia 0:40
//Nika 0:35
//Lucija 0:50
//Lucija 0:43
//Ivan 2:20
//Ivan 0:45
//Rezultate (ukupno vrijeme gledanja po korisniku) ispišite sortirano po imenu korisnika u obliku:
//
//Fran = 1:40
//Ivan = 3:50
//Lucija = 1:33
//Luka = 1:05
//Mia = 1:05
//Nika = 1:45
//Uputstva: koristite std::map.

#include <iostream>
#include <fstream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> usrMap;
    std::ifstream file("/Users/tinrupcic/Desktop/drugi.txt");
    std::string usrName;
    int h = 0;
    int min = 0;
    char line;

    while (file >> usrName >> h >> line >> min) {
        if (usrMap.count(usrName))
            usrMap[usrName] += h * 60 + min;
        else
            usrMap[usrName] = h * 60 + min;

    }

    for (const auto &[name, time]: usrMap) {
        std::cout << name << " " << time / 60 << ":" << time % 60 << std::endl;
    }

    return 0;
}



