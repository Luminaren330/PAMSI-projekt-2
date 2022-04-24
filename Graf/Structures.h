#ifndef GRAFY2_STRUCTURES_H
#define GRAFY2_STRUCTURES_H

#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

struct Data {
    int cost; // koszt
    bool visited; //odwiedzony
};
// struktury zawwierające potrzebne elementy do działania algorytmu
struct Element {
    int node; // węzeł
    Element * next1; // następny
    int weight; // waga
};
#endif //GRAFY2_STRUCTURES_H
