#ifndef GRAFY2_GRAPH_SECONDFILE_H
#define GRAFY2_GRAPH_SECONDFILE_H

#include "Structures.h"

using namespace std;

class Graf // klasa zawierająca obiekty i funkcje potrzebne do stworzenia i działania grafu
{
private:
    int **matrix; // macierz
    Element **list; // lista
    Element *element;
    int vertices; // wierzchołki
    int edges; // krawędzie
    int starting_vertex; // wierzchołek początkowy
    int *path; // droga
public:
    Graf() {};
    Graf(int edges_c , int Vertices_c, int starting_vertex_c);
    int minimum(Data* array);
    Data* dijkstra_list();
    Data* dijkstra_matrix();
    int add_edge(int first, int second, int weight);
    void list_display();
    void matrix_display();
    void save(Data *array);
    ~Graf() {}; //dekonstruktor
};


#endif //GRAFY2_GRAPH_SECONDFILE_H
