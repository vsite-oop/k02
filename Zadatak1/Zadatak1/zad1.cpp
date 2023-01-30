#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include<ostream>



template <typename T, int size> class collection {
private:
	T* ptr;
	T val;

	std::iterator begin() {
		return; //na pravi element liste
	}
	std::iterator end() {
		return; //poslije zadnjeg elementa liste
	}
public:
	collection(T v) : val(v);
	T& operator[](T i) {

	}

};

int main() {
	collection<double, 16> c(2.5); //type, size
	c[0] = c[15] = 3.5;
	std::copy(c.begin(), c.end(), std::ostream_iterator<double>(cout, " "));
}