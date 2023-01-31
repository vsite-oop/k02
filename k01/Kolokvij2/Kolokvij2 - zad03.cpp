/*
3. zadatak (25 bodova)

Napišite program za obradu zdravstvenih podataka pacijenata.

Podatke učitajte iz datoteke u formatu: pacijent (jedna riječ), starost (godine), visina (cm), težina (kg).

Primjer ulaznih podataka:

Lovro 24 185 68
Nikola 33 171 77
Leo 56 177 88
Laura 22 165 61
Marija 48 170 58
Petra 28 177 65
Hana -54 166 55

Izbacite sve invalidne podatke (negativne vrijednosti), promijenite centimetre u stope i kilograme u funte, ispišite podatke sortirane po starosti (i prosjek starosti) u obliku:

Leo (56) = 5.81 ft, 194.04 lb
Marija (48) = 5.58 ft, 127.89 lb
Nikola (33) = 5.61 ft, 169.78 lb
Petra (28) = 5.81 ft, 143.33 lb
Lovro (24) = 6.07 ft, 149.94 lb
Laura (22) = 5.41 ft, 134.50 lb

prosjek: 35.17 godina

Uputstva: koristite std::vector i samo standardne algoritme: copy, remove_if, transform, sort, accumulate.
*/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <format>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>


struct patient {
    std::string name;
    int age;
    double height;
    double weight;

    patient& transform() {
        height /= 2.54;
        weight *= 2.205;

        return *this;
    };
};

std::istream& operator>>(std::istream& is, patient& p) {
    return is >> p.name >> p.age >> p.height >> p.weight;
}

std::ostream& operator<<(std::ostream& os, const patient& p) {
    return os << std::format("{} [{}] = {:.2f} ft, {:.2f} lb", p.name, p.age, p.height, p.weight);
}

int main() {
    std::vector<patient> patients;
    std::ifstream f("zad03.txt");


    if (f.is_open()) {
        std::copy(std::istream_iterator<patient>(f), {}, std::back_inserter(patients));
        patients.erase(std::remove_if(patients.begin(),
            patients.end(),
            [](const patient& p) 
            {return p.age < 0 && p.height < 0 && p.weight < 0; }), 
            patients.end());
        
    }
    std::transform(patients.begin(), patients.end(), patients.begin(), [](patient& p) mutable { p.height /= 2.54; p.weight *= 2.205; return p; });
    std::sort(patients.begin(), patients.end(), [](const patient& a, const patient& b) {return a.age > b.age; });
    std::copy(patients.begin(), patients.end(), std::ostream_iterator<patient>(std::cout, "\n"));

    std::cout << "Prosjek godina je: " << std::accumulate(patients.begin(), patients.end(), 0, [](int i, const patient& p2) {return p2.age + i; }) / static_cast<double>(patients.size());
}