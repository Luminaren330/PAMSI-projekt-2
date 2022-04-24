#include "Firstfile.h"

using namespace std;


void generate() // funkcja tworząca graf i zapisujący go do pliku
{
    int edges; //ilość krawędzi
    int vertices; // ilość wierzchołków
    int starting_vertex = 0; // wierzchołek startowy
    int counter=0; // licznik
    double density = 0; // gęstość
    string file_name; // nazwa pliku
    ofstream file1;
    int weight; // waga
    random_device rd;
    mt19937 gen(rd()); // generator losowych liczb
    uniform_int_distribution<> distr(1, 50); // przedział

    cout << "Podaj nazwe pliku:" << endl;
    cin >> file_name;

    file1.open(file_name.c_str());
    cout << "Podaj liczbe wierzcholkow i gestosc (0-1)  " << endl;
    cin >> vertices >> density;
    edges = ((vertices * (vertices - 1)) / 2) * density;

    file1 << edges << " " << vertices << " " << starting_vertex << endl; // wczytuje ilość krawędzi, wierzchołków i wierzchołek początkowy do pliku

    for (int i = 0; i < vertices; i++)
        for (int j = i; j < vertices; j++)
        {

            if (i != j && counter < edges) // zapewnia kolejne połączenia wierzchołków
            {
                weight = distr(gen);
                file1 << i << " " << j << " " << weight << endl;
                file1 << j << " " << i << " " << weight << endl;
                counter++;
            }
        }
        


    file1.close();

}


void load(Graf *&_Graf) // funckja zczytująca graf z pliku
{
    int edges; //ilość krawędzi
    int vertices; // ilość wierzchołków
    int starting_vertex; // wierzchołek startowy
    int first; // wierzchołek pierwszy
    int second; // wierzchołek drugi
    int weight; // waga
    string file_name; //plik

    ifstream file1;
    cout << "Podaj nazwe pliku " << endl;
    cin >> file_name;


    file1.open(file_name.c_str());

    if (file1.good()) //odczytywanie ilości krawędzi, wierzchołków i wierzchołka początkującego
    {
        file1 >> edges;
        file1 >> vertices;
        file1 >> starting_vertex;
        _Graf = new Graf(edges, vertices, starting_vertex); // powstanie nowego grafu
        while (!file1.eof())
        {
            file1 >> first; // odczytuje pierwszy wierzchołek
            file1 >> second; // odczytuje drugi wierzchołek
            file1 >> weight; // // odczytuje wagę

            _Graf->add_edge(first, second, weight);
        }

    }
    else
    {
        cout << "Niepoprawna nazwa pliku";
    }
    file1.close();


}