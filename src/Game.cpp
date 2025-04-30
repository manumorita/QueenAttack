#include "Game.h"
#include <iostream>
#include <cctype>
#include <cstdlib>

using namespace std;

Game::Game()
{
    pos_Reina_blanca = "D1";
    pos_Reina_negra = "E8";
}

string leer(string dato)
{
    string aux;
    do
    {
        cout<<dato<<endl;
        getline(cin,aux);
    }while(aux.empty());
    return aux;
}

bool Game::queen_attack(int p, char pos_x, int pos_y)
{
    pos_x = toupper(pos_x);

    if (pos_x < 'A' || pos_x > 'H' || pos_y < 1 || pos_y > 8) {
        cout << "Movimiento invalido, use letra A-H y numero 1-8." << endl;
        return false;
    }

    int nueva_col = pos_x - 'A';
    int nueva_fila = 8 - pos_y;

    int fila_otra, col_otra;

    if (p == 1) {
        col_otra = toupper(pos_Reina_negra[0]) - 'A';
        fila_otra = 8 - (pos_Reina_negra[1] - '0');

        if (nueva_col == col_otra || nueva_fila == fila_otra || abs(nueva_col - col_otra) == abs(nueva_fila - fila_otra)) {
            cout << "No se puede mover la reina blanca ahi, está en rango de ataque." << endl;
            return false;
        } else {
            pos_Reina_blanca = string(1, pos_x) + to_string(pos_y);
            return true;
        }
    }
    else if (p == 2) {
        col_otra = toupper(pos_Reina_blanca[0]) - 'A';
        fila_otra = 8 - (pos_Reina_blanca[1] - '0');

        if (nueva_col == col_otra || nueva_fila == fila_otra || abs(nueva_col - col_otra) == abs(nueva_fila - fila_otra)) {
            cout << "No se puede mover la reina negra ahi, está en rango de ataque." << endl;
            return false;
        } else {
            pos_Reina_negra = string(1, pos_x) + to_string(pos_y);
            return true;
        }
    }
    else {
        cout << "Movimiento de reina invalido, use 1 para blanca, 2 para negra." << endl;
        return false;
    }
}

Game::~Game()
{
    // Destructor vacío
}
