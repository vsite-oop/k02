#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

struct person {
    std::string name;
    int age;
    double height;
    double weight;
};

std::istream& operator>>(std::istream& is, person& p) {
    return is >> p.name >> p.age >> p.height >> p.weight;
}

std::ostream& operator<<(std::ostream& os, const person& p) {
    return os << p.name << " (" << p.age << ") = "
        << std::ceil(p.height * 100.0) / 100.0<< " ft, "
        << std::ceil(p.weight * 100.0) / 100.0<< " lb";
}

bool is_valid(person p) {
    if (p.age <= 0 || p.height <= 0 || p.weight <= 0)return true;
    return false;
}

int main() {
    std::ifstream file("Zadatak3.txt");
    std::vector<person> people;
    std::ostream_iterator< person > output(std::cout, " \n");
    std::copy(std::istream_iterator<person>(file), std::istream_iterator<person>(), std::back_inserter(people));
    std::sort(people.begin(), people.end(), [](const person& a, const person& b) {return a.age > b.age;});
    std::transform(people.begin(), people.end(), people.begin(), [](person& p) {p.height *= 0.0328; p.weight *= 2.20462; return p; });
    people.erase(std::remove_if(people.begin(), people.end(), is_valid), people.end());
    std::copy(people.begin(), people.end(), output);
    double avg = (std::accumulate(people.begin(), people.end(), 0., [](double acc, const person& p) {return acc+=p.age; })) / people.size();
    std::cout << "prosjek: " << std::ceil(avg * 100.0) / 100.0 << " godina";
    return 0;
}