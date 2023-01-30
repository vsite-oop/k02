#include <algorithm>
#include <iterator>
#include <iostream>

template <typename T, int N>
class collection
{
    T c[N];
public:
    collection(T val) { std::fill(begin(), end(), val); }
    T& operator[](int i) { return c[i]; }
    T* begin() { return c; }
    T* end() { return c+N; }
};

int main(){
	collection<double, 16> c(2.5);
	c[0] = c[15] = 3.5;
	std::copy(c.begin(), c.end(), std::ostream_iterator<double>(std::cout, " "));
}
