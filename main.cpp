#include <iostream>
#include "Game.h"

using namespace std;

string leer(string dato);

int main()
{
    int pos_y, opc, opc2;
    char pos_x;

    Game unJuego;
    do {
        cout << "\n¿Qué pieza desea mover? \n1 - Reina blanca \n2 - Reina negra \n0 - Salir\n";
        opc = stoi(leer("Digite una opcion: "));

        if (opc == 1 || opc == 2) {
            string col = leer("Digite la letra de la columna (A-H): ");
            pos_x = toupper(col[0]);  //
            pos_y = stoi(leer("Digite el numero de fila (1-8): "));

            unJuego.queen_attack(opc, pos_x, pos_y);
        } else if (opc != 0) {
            cout << "Opción invalida.\n";
        }

    } while (opc != 0);
    return 0;
}
