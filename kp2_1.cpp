
#include <algorithm>
#include <iostream>

using namespace std;



template <typename T, int E>
class collection {
   T a[E];
   public:
     collection(T v) { fill(begin(), end(), v); }
     T& operator[](int i) { return a[i]; }
     T* begin() { return a; }
     T* end() { return a + E; }
};


