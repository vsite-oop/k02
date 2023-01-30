////
//// Created by Tin Rupcic on 30.01.2023..
////
//3. zadatak (25 bodova)
//Napišite program za obradu zdravstvenih podataka pacijenata.
//
//Podatke učitajte iz datoteke u formatu: pacijent (jedna riječ), starost (godine), visina (cm), težina (kg).
//
//Primjer ulaznih podataka:
//
//Lovro 24 185 68
//Nikola 33 171 77
//Leo 56 177 88
//Laura 22 165 61
//Marija 48 170 58
//Petra 28 177 65
//Hana -54 166 55
//Izbacite sve invalidne podatke (negativne vrijednosti), promijenite centimetre u stope i kilograme u funte, ispišite podatke sortirane po starosti (i prosjek starosti) u obliku:
//
//Leo (56) = 5.81 ft, 194.04 lb
//        Marija (48) = 5.58 ft, 127.89 lb
//        Nikola (33) = 5.61 ft, 169.78 lb
//        Petra (28) = 5.81 ft, 143.33 lb
//        Lovro (24) = 6.07 ft, 149.94 lb
//        Laura (22) = 5.41 ft, 134.50 lb
//
//        prosjek: 35.17 godina
//        Uputstva: koristite std::vector i samo standardne algoritme: copy, remove_if, transform, sort, accumulate.