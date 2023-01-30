#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <format>
#include <numeric>

using namespace std;

struct person {
	string name;
	int age;
	double height;
	double weight;
	friend istream& operator>>(istream& is, person& p) {
		return is >> p.name >> p.age >> p.height >> p.weight;
	}
	friend ostream& operator<<(ostream& os, const person& p) {
		return os << format("{} ({}) = {:.2f} ft, {:.2f} lb", p.name, p.age, p.height, p.weight);
	}
};

int main(const int argc, const char* argv[]) {
	vector<person> v;
	ifstream f(argv[1]);
	istream_iterator<person> is(f), es;
	copy(is, es, back_inserter(v));
	v.erase(remove_if(begin(v), end(v), [](const person& p) { 
		return p.age < 0 || p.height < 0 || p.weight < 0; }), end(v));
	transform(begin(v), end(v), begin(v), [](person p) {
		p.height /= 30.48; p.weight *= 2.205; return p; });
	sort(begin(v), end(v), [](const person& a, const person& b) { 
		return a.age > b.age; });
	copy(cbegin(v), cend(v), ostream_iterator<person>(cout, "\n"));
	const auto sum = accumulate(begin(v), end(v), 0., [](auto n, const person& p) {
		return n + p.age; });
	cout << format("\nprosjek: {:.2f} godina", sum / v.size());
}
