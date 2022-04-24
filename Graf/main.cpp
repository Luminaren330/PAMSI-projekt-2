#include "Graph_SecondFile.h"
#include "Firstfile.h"

int main()
{
    clock_t timeStart;
    clock_t timeEnd;
    int choice;
    Graf *_Graf = NULL;
    Data* array;
    cout.precision(6);
    while (1)
    {
        float time = 0;
        cout << "Powiedz co chcesz zrobic:" << endl
         << "1. - Stworz graf" << endl
         << "2. - Wczytaj z pliku " << endl
         << "3. - Wytworz liste" << endl
         << "4. - Wytworz macierz" << endl
         << "5. - Wyswietl macierz i liste" << endl
         << "6. - Zakoncz program" << endl;
        cin >> choice;

        switch (choice)
        {
            case 1:
                generate();
                break;

            case 2:
                load(_Graf);
                break;

            case 3:
            {

                for (int i = 0; i < 100; i++)
                {
                    timeStart = clock();
                    array = _Graf->dijkstra_list();
                    timeEnd = clock();
                    time += timeEnd - timeStart;

                }
                cout << " Czas dzialania programu: " << time/CLOCKS_PER_SEC << "s" << endl; // wyświetla czas działania algorytmu
                _Graf->save(array);
            }
                break;

            case 4:
            {

                for (int i = 0; i < 100; i++)
                {
                    timeStart = clock();
                    array = _Graf->dijkstra_matrix();
                    timeEnd = clock();
                    time += timeEnd - timeStart;

                }

                cout << " Czas dzialania programu: " << time/CLOCKS_PER_SEC <<  "s" << endl; // wyświetla czas działania algorytmu
                _Graf->save(array);
            }
                break;

            case 5:
                cout << "Macierz:" << endl;
                _Graf->matrix_display();
                cout << "------------------------" << endl;
                cout << endl << "Lista:" << endl;
                _Graf->list_display();
                cout << "------------------------" << endl;
                break;

            case 6:
                return 0;
            default:
                cout << "Zly wybor. Sprobuj ponownie" << endl;
                break;


        }
    }
}