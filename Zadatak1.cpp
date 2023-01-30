//Napišite klasu collection(ima C - ovsko polje kao privatni član) tako da 
// sljedeći program ispisuje sve elemente kolekcije.U konstruktoru se svi elementi postavljaju na zadanu vrijednost.
//
#include <algorithm>
#include <iostream>




template <typename T, int N>
class collection {
	T arr[N];
public:
	collection(double value) { std::fill(begin(), end(), value); }
	T& operator[](int i) { return arr[i]; }
	T* begin() { return arr; }
	T* end() { return arr + N; }
};

template<typename T, int N>
std::ostream& operator<<(std::ostream& os, const collection<T,N>& obj) {
	return os << obj.m_value;
}





//int main() {
//	collection<double, 16> c(2.5);
//	c[0] = c[15] = 3.5;
//	std::copy(c.begin(), c.end(), std::ostream_iterator<double>(std::cout, " "));
//}