//empezamos declarando las liberias que estaremos usando y agregaremos las que hemos creado
#include <iostream>
#include <unistd.h>
//liberia creada
#include "Juego.h"
//liberia creada
#include "Config.h"

//indispensable
using namespace std;

//vamos a empezar
int main()

{   //como prime paso empezamos poniendo nuestros valores constantes con su tipo de dato
    const int FILASTABLERO = 5;
    const int COLUMNASTABLERO = 5;
    const int MINASENTABLERO = 3;
    const bool MODODESARROLLADOR = true;
    const int VIDASTABLERO = 3;
    Config configuracionJuego(FILASTABLERO, COLUMNASTABLERO, MINASENTABLERO, MODODESARROLLADOR, VIDASTABLERO);

    srand(getpid());
    int opciones;
    bool repetir = true;
    do
    {   cout << "                       __                              " << endl;
        cout << "                      .'  '.                           " << endl;
        cout << "                 _.-'/  |  \                           " << endl;
        cout << "     ,        _.-'  ,|  /  0 `-.                       " << endl;
        cout << "     |\    .-"       "'-.__.'=====================-," << endl;
        cout << "     \ '-'`        .___.--._)=========================|" << endl;
        cout << "      \            .'      |                          |" << endl;
        cout << "       |     /,_.-'        |        EJEMPLOS          |" << endl;
        cout << "     _/   _.'(             |           DEL            |" << endl;
        cout << "    /  ,-' \  \            |        ARTE ASCII        |" << endl;
        cout << "    \  \    `-'            |                          |" << endl;
        cout << "     `-'                   '--------------------------'" << endl;
        //empezaremos a crear lo que aparecera al inicio de nuestro juego, que seran las indicaciones / intrucciones
        system("cls");
        cout << "\n\n\t\tBUSCA MINAS -Menu-" << endl;
        cout << "\t\t-------------------"<< endl;
        cout << "\t\t1. Configuracion del Juego" << endl;
        cout << "\t\t2. Iniciar el Juego" << endl;
        cout << "\t\t3. Salir del Juego" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;

        //ahora empezaremos a generar nuestras opciones, en este caso son 3 y llamamos a las clases que estan declaradas en "config.h"
        switch (opciones)
        {
            //instruccion 1
        case 1:
            {
                configuracionJuego.menuConfiguracion();
                break;
            }
            //instruccion 2
        case 2:
            {
                system("cls");
              	Juego juego(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero());
                juego.iniciar();
                system("pause");
                break;
            }
            //instruccion 3
        case 3: repetir = false;
                break;
        }
    //cerramos nuestro ciclo
    } while (repetir);
    return 0;
}
