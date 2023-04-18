//Libreria iostream
#include <iostream>
//Librerias de configuracion de configuraciones y unidades.
#include <unistd.h>
#include "Config.h"
using namespace std;
//Area de configuracion de las areas accionables en el tablero.
Config::Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero)
{
    //Indicador de igualdad entre comandos de accion.
    this->filasTablero = filasTablero;
    this->columnasTablero = columnasTablero;
    this->minasTablero = minasTablero;
    this->modoDesarrolladorTablero = modoDesarrolladorTablero;
    this->vidasTablero = vidasTablero;
}
// Accionador de la configuracion del menu principal.
void Config::menuConfiguracion()
{
    // Datos de accion como ppciones y valores utilizados.
    int opciones;
    int valorIngresado;
    // Indicador de una accion bool a repetir de forma verdadera.
    bool repetir = true;
    //Accion de menu y seleccion de opciones multiples.
    do
    {
        //Sistema y menu de seleccion de opciones multiples.
        system("cls");
        cout << "\n\n\t\tCONFIGURACION ACTUAL -Menu-" << endl;
        cout << "\t\t-------------------"<< endl;
        cout << "\t\t1. Filas del Tablero ----> " << this->getfilasTablero() << endl;
        cout << "\t\t2. Columnas del Tablero -> " << this->getcolumnasTablero() << endl;
        cout << "\t\t3. Minas del Tablero ----> " << this->getminasTablero() << endl;
        cout << "\t\t4. Modo del Juego -------> " << this->getmodoDesarrolladorTablero() << endl;
        cout << "\t\t5. Vidas del Jugador ----> " << this->getvidasTablero() << endl;
        cout << "\t\t6. Regresar al menu general" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;
        //Condicional de accion con respecto a las opciones.
        if (opciones!=6)
        {
            cout << "\n\tIngrese el valor que desea cambiar: ";
            cin >> valorIngresado;
        }
        //Cambio de opciones entre casos predeterminados.
        switch (opciones)
        {
            //Establecimiento de pasos y acciones a realizar en caso de usar dicho caso.
        case 1:
            {
                this->setfilasTablero(valorIngresado);
                cout << "Filas del Tablero actualizadas" << endl;
                break;
            }
        case 2:
            {
                this->setcolumnasTablero(valorIngresado);
                cout << "Columnas del Tablero actualizadas" << endl;
                break;
            }
        case 3:
            {
                this->setminasTablero(valorIngresado);
                cout << "Minas del Tablero actualizadas" << endl;
                break;
            }
        case 4:
            {
                this->setmodoDesarrolladorTablero(valorIngresado);
                cout << "Modo del Juego actualizado" << endl;
                break;
            }
        case 5:
            {
                if (valorIngresado<= this->minasTablero)
                {
                    this->setvidasTablero(valorIngresado);
                    cout << "Vidas del Juego actualizadas" << endl;
                }
                else{
                cout << "Valor ingresado no aceptado" << endl;
                }
                break;
            }
        case 6: repetir = false;
                break;
        }
        //Indicador de una pausa del sistema.
        system("pause");
        //INDICADOR DE accion de repeticion mientras se realiza otra accion.
    } while (repetir);
}
//Configuracion del tablero dividiendo sus partes accionables.
int Config::getfilasTablero()
{
    return this->filasTablero;
}
//Configuracion del tablero dividiendo sus partes accionables.
int Config::setfilasTablero(int filasTablero)
{
    this->filasTablero=filasTablero;
}
//Configuracion del tablero dividiendo sus partes accionables.
int Config::getcolumnasTablero()
{
    return this->columnasTablero;
}
//Configuracion del tablero dividiendo sus partes accionables.
int Config::setcolumnasTablero(int columnasTablero)
{
    this->columnasTablero=columnasTablero;
}
//Configuracion del tablero dividiendo sus partes accionables.
int Config::getminasTablero()
{
    return this->minasTablero;
}
//Configuracion del tablero dividiendo sus partes accionables.
int Config::setminasTablero(int minasTablero)
{
    this->minasTablero=minasTablero;
}
// Proceso de entrada a modo desarrollador y establecimiento de configuracion.
bool Config::getmodoDesarrolladorTablero()
{
    return this->modoDesarrolladorTablero;
}
// Proceso de entrada a modo desarrollador y establecimiento de configuracion.
bool Config::setmodoDesarrolladorTablero(bool modoDesarrolladorTablero)
{
    this->modoDesarrolladorTablero=modoDesarrolladorTablero;
}
//Configuracion y sistema predeterminado de vidas del jugador.
int Config::getvidasTablero()
{
    return this->vidasTablero;
}
//Configuracion y sistema predeterminado de vidas del jugador.
int Config::setvidasTablero(int vidasTablero)
{
    this->vidasTablero=vidasTablero;
}
