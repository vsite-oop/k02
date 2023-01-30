//
// Created by Tin Rupcic on 30.01.2023..
//
//1. zadatak (10 bodova)
//Napišite klasu collection (ima C-ovsko polje kao privatni član) tako da sljedeći program ispisuje sve elemente kolekcije. U konstruktoru se svi elementi postavljaju na zadanu vrijednost.
//
//#include <algorithm>
//
//int main(){
//    collection<double, 16> t(2.5);
//    t[0] = t[15] = 3.5;
//    std::copy(t.begin(), t.end(), std::ostream_iterator<double>(cout, " "));
//}
#include <iostream>
#include <array>

template<typename T, std::size_t size>
class collection {
private:
    std::array <T, size> array;
public:
    collection(const T &t) {
        std::fill(array.begin(), array.end(), t);
    }
    T &operator[](std::size_t size1) {
        return array[size1];
    }
    auto end() {
        return array.end();
    }
    auto begin() {
        return array.begin();
    }

};
int main() {
    collection<double, 16> c(2.5);
    c[0] = c[15] = 3.5;
    std::copy(c.begin(), c.end(), std::ostream_iterator<double>(std::cout, " "));
    return 0;
}