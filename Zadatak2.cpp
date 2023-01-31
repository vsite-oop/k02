//#include <fstream>
//#include <string>
//#include <map>
//#include <vector>
//#include <sstream>
//#include <iostream>
//
//struct korisnik {
//    std::string name;
//    int min;
//    int sec;
//};
//
//std::istream& operator>>(std::istream& is, korisnik& k) {
//    char c;
//    return is >> k.name >> k.min >> c >> k.sec;
//}
//
//std::ostream& operator<<(std::ostream& os, const korisnik& k) {
//    return os << k.name << " " << k.min << ":" << k.sec;
//}
//
//int main() {
//    std::ifstream file("Zadatak2.txt");
//
//    while (file >> key >> value) {
//        params[key] = value; // input them into the map 
//    }
//    std::map<std::string,int> people;
//    std::copy(std::istream_iterator<korisnik>(file), std::istream_iterator<korisnik>(), std::back_inserter(people));
//    std::sort(people.begin(), people.end(), [](const person& a, const person& b) {return a.age > b.age; });
//    std::transform(people.begin(), people.end(), people.begin(), [](person& p) {p.height *= 0.0328; p.weight *= 2.20462; return p; });
//    people.erase(std::remove_if(people.begin(), people.end(), is_valid), people.end());
//    std::copy(people.begin(), people.end(), output);
//    double avg = (std::accumulate(people.begin(), people.end(), 0., [](double acc, const person& p) {return acc += p.age; })) / people.size();
//    std::cout << "prosjek: " << std::ceil(avg * 100.0) / 100.0 << " godina";
//    return 0;
//}