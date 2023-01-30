# VSITE OOP 2. kolokvij

### 1. zadatak (10 bodova)

Napišite klasu `collection` (ima C-ovsko polje kao privatni član) tako da sljedeći program ispisuje sve elemente kolekcije. 
U konstruktoru se svi elementi postavljaju na zadanu vrijednost.


```
#include <algorithm>

int main(){
	collection<double, 16> c(2.5);
	c[0] = c[15] = 3.5;
	std::copy(c.begin(), c.end(), std::ostream_iterator<double>(cout, " "));
}
```

### 2. zadatak (15 bodova)

Napišite program za analizu podataka o gledanju TV programa.

Podatke učitajte iz datoteke u formatu: korisnik (jedna riječ), vrijeme (sati:minute).

Primjer ulaznih podataka:

```
Ivan 0:45
Nika 0:35
Nika 0:35
Fran 1:40
Luka 0:30
Mia 0:25
Luka 0:30
Luka 0:05
Mia 0:40
Nika 0:35
Lucija 0:50
Lucija 0:43
Ivan 2:20
Ivan 0:45
```

Rezultate (ukupno vrijeme gledanja po korisniku) ispišite sortirano po imenu korisnika u obliku:

```
Fran = 1:40
Ivan = 3:50
Lucija = 1:33
Luka = 1:05
Mia = 1:05
Nika = 1:45
```

Uputstva: koristite `std::map`.

### 3. zadatak (25 bodova)

Napišite program za obradu zdravstvenih podataka pacijenata.

Podatke učitajte iz datoteke u formatu: pacijent (jedna riječ), 
starost (godine), visina (cm), težina (kg).

Primjer ulaznih podataka:

```
Lovro 24 185 68
Nikola 33 171 77
Leo 56 177 88
Laura 22 165 61
Marija 48 170 58
Petra 28 177 65
Hana -54 166 55
```

Izbacite sve invalidne podatke (negativne vrijednosti), 
promijenite centimetre u stope i kilograme u funte, 
ispišite podatke sortirane po starosti (i prosjek starosti) u obliku: 

```
Leo (56) = 5.81 ft, 194.04 lb
Marija (48) = 5.58 ft, 127.89 lb
Nikola (33) = 5.61 ft, 169.78 lb
Petra (28) = 5.81 ft, 143.33 lb
Lovro (24) = 6.07 ft, 149.94 lb
Laura (22) = 5.41 ft, 134.50 lb

prosjek: 35.17 godina
```

Uputstva: koristite `std::vector` i samo standardne algoritme: `copy`, `remove_if`, `transform`, `sort`, `accumulate`.
