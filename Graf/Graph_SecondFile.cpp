#include <ctime>
#include <algorithm>
#include "Graph_SecondFile.h"

using namespace std;


Graf::Graf(int edges_c, int Vertices_c, int starting_vertex_c) //funkcja tworząca graf
{
    this->vertices = Vertices_c;
    this->edges = edges_c;
    this->starting_vertex = starting_vertex_c;
    matrix = new int*[Vertices_c];
    for (int i = 0; i < Vertices_c; i++)
        matrix[i] = new int[Vertices_c]; // tworzy macierz
    for (int i = 0; i < Vertices_c; i++)
        for (int j = 0; j < Vertices_c; j++)
            matrix[i][j] = 0;

    list = new Element*[Vertices_c]; // tworzy listę

    for (int i = 0; i < Vertices_c; i++)
        list[i] = NULL;



}


int Graf::minimum(Data * array) { // funckja znajdująca minimum
    int min = -1;
    int mindist = INT_MAX;
    for (int i = 0; i < vertices; i++) {
        if (!array[i].visited && array[i].cost < mindist) { // jeśli nie odwiedzone i mniejsze od mindist
            min = i;
            mindist = array[i].cost; // znajduje minimum
        }
    }
    return min; // zwraca minimum
}


Data* Graf::dijkstra_list() { //funkcja tworząca algorytm listy sąsiedztwa

    Data* array = new Data[vertices];
    path = new int[vertices];
    Element *tmp;
    for (int i = 0; i < vertices; i++) {
        if (i == starting_vertex)
        {
            array[i].cost = 0; // koszt dla samego siebie musi być równy 0
        }
        else
        {
            array[i].cost = INT_MAX;
        }
        array[i].visited = false;
        path[i] = -1;
    }

    int min = minimum(array);

    while (min != -1) {
        array[min].visited = true;

        for (tmp = list[min]; tmp; tmp = tmp->next1)
        {
            if (array[min].cost + tmp->weight < array[tmp->node].cost) {
                array[tmp->node].cost = array[min].cost + tmp->weight;
                path[tmp->node] = min;
            }

        }
        cout << endl;
        min = minimum(array);

    }
    return array;
}


Data* Graf::dijkstra_matrix() { //funkcja tworząca algorytm macierzy sąsiedztwa

    path = new int[vertices];
    Data* array = new Data[vertices];
    for (int i = 0; i < vertices; i++) {
        if (i == starting_vertex)
        {
            array[i].cost = 0; // koszt dla samego siebie musi być równy 0
        }
        else
        {
            array[i].cost = INT_MAX;
        }
        array[i].visited = false;
        path[i] = -1;
    }

    int min = minimum(array);
    while (min != -1) {
        array[min].visited = true;
        for (int i = 0; i < vertices; i++) {
            if (matrix[min][i] > 0 && array[min].cost + matrix[min][i] < array[i].cost) {
                array[i].cost = array[min].cost + matrix[min][i];
                path[i] = min;
            }
        }
        cout << endl;
        min = minimum(array);
    }

    return array;
}


int Graf::add_edge(int first, int second, int weight) // funckja dodająca krawędzie
{

    element = new Element;
    element->next1 = list[first];
    element->node = second;
    element->weight = weight;
    list[first] = element;

    return matrix[first][second] = weight;



}


void Graf::list_display() // funckja wyświetlająca listę sąsiedztwa
{
    Element *tmp;
    for (int i = 0; i < vertices; i++)
    {
        tmp = list[i];
        cout << i << "->";
        while (tmp)
        {
            cout << tmp->node << " waga:" << tmp->weight << "|| ";
            tmp = tmp->next1;
        }
        cout << endl;
    }
}


void Graf::matrix_display() // funkcja wyświetlająca macierz sąsiedztwa
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}


void Graf::save(Data * array)  // funckja zapisująca graf do pliku
{
    int counter = 0; // licznik
    int *path_array = new int[vertices];
    ofstream file1;
    file1.open("Plik_koncowy.txt");
    for (int i = 0; i < vertices; i++)
    {
        file1 << i << ":";
        for (int j = i; j > -1; j = path[j]) {
            path_array[counter] = j;
            counter++;
        }
        while (counter) {
            counter--;
            file1 << path_array[counter] << "->";
        }
        file1 << "Koszt: " << array[i].cost <<  endl;

    }
    file1.close();
}
