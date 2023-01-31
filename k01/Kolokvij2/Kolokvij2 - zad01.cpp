#include <iostream>
#include <algorithm>
#include <iterator>

/*
1. zadatak (10 bodova)

Napišite klasu collection (ima C-ovsko polje kao privatni član) tako da sljedeći program ispisuje sve elemente kolekcije. U konstruktoru se svi elementi postavljaju na zadanu vrijednost.

#include <algorithm>

int main(){
	collection<double, 16> c(2.5);
	c[0] = c[15] = 3.5;
	std::copy(c.begin(), c.end(), std::ostream_iterator<double>(cout, " "));
}
*/

template <typename T, int size = 0>
class collection {
	T* arr;
	int arrSize;
public:
	collection(const double& val)
		: arr{ new T[size] }
		, arrSize{ size }
	{
		std::fill(arr, arr + size, val);
	}
	~collection() {
		delete[] arr;
	}
	T& operator[](int i) {
		return arr[i];
	}
	T* begin() const {
		return arr;
	}
	T* end() const {
		return arr + arrSize;
	}
};
/*
int main() {
	using namespace std;

	collection<double, 16> c(2.5);
	c[0] = c[15] = 3.5;
	std::copy(c.begin(), c.end(), std::ostream_iterator<double>(cout, " "));
}*/