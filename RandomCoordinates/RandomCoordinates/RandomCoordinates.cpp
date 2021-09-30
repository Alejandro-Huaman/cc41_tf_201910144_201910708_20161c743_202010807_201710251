#include <iostream>
#include <time.h>
#include <stdio.h>
#include <fstream>  

using std::string;
using std::cout;
using std::cin;
using std::ofstream;

long random_d(int max)
{
    return (rand() % max) + 1;
}

void genCSVFile(string name, char separation, int num, int xcoord, int ycoord) {
    ofstream outfile(name + ".csv");

    for (int n = 0; n < num; ++n)
    {
        outfile << random_d(xcoord) << separation << random_d(ycoord) << "\n";
    }

    outfile.close();

}

int main()
{
    srand(time(NULL));

    int num = 0, xcoord = 0, ycoord = 0;
    string fileName = "";
    char separation = ',';

    cout << "Cuantas coordenadas generar? ";
    cin >> num;

    cout << "Coordenadas en X: ";
    cin >> xcoord;
    if (xcoord < 1) xcoord = 1;

    cout << "Coordenadas en Y: ";
    cin >> ycoord;
    if (ycoord < 1) ycoord = 1;

    cout << "Ingrese el nombre del dataset a generar (No agregar .csv): ";
    cin >> fileName;

    cout << "Ingrese el signo con el que separar coordenada X y Y (Ejemplo: ',' o ';'): ";
    cin >> separation;

    genCSVFile(fileName,separation, num, xcoord, ycoord);

    cout << "\nTu archivo se ha generado correctamente!\n";
}