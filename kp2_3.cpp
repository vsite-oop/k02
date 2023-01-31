#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <chrono>
#include <numeric>
#include <random>
#include <math.h>
#include <iostream>

using namespace std;

struct patient {
    string name;
    int age;
    double height,weight;
};

istream& operator>>(istream& is, patient& s) { return is >> s.name >> s.age>> s.height>> s.weight; }

ostream& operator<<(ostream& os, const patient& s) {


return os << s.name << " (" <<s.age<<") "<<"= "<<s.height<<" ft,"<<s.weight<<" lb";

}

int main() {
vector<patient> v;
ifstream f("patients_list.txt");
copy(istream_iterator<patient>(f),istream_iterator<patient>(), back_inserter(v));
v.erase(remove_if(v.begin(),v.end(),[](patient& a) {return a.age<0||a.weight<0||a.height<0;}),v.end());
transform(v.begin(),v.end(),v.begin(),[](patient& a){ a.height*=0.304; a.weight*=0.454; return a;});
sort(v.begin(), v.end(), [](const patient& a, const patient& b) {
return a.age>b.age;});
auto total_age = accumulate(v.begin(),v.end(),0,[](int sum,const patient& p){return sum+=p.age;});

copy(v.begin(),v.end(), ostream_iterator<patient>(cout, "\n"));

cout<<endl<<"prosjek: "<<total_age/v.size()<<" godina";

}