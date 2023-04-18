//Librerías
#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>
#include <vector>
//El celda.h para poder crear cada celda del tablero
#include "Celda.h"

using namespace std;

//Se crea la clase tablero
class Tablero
{
    public:
        //crea los parámetros del tablero.
        Tablero();
        Tablero(int alturaTablero, int anchoTablero, bool modoDesarrollador);
        //usa las variables privadas
        int getAlturaTablero();
        int setAlturaTablero(int alturaTablero);
        int getAnchoTablero();
        int setAnchoTablero(int anchoTablero);
        bool getModoDesarrollador();
        bool setModoDesarrollador(bool modoDesarrollador);
        //Agrega procesos para darle espacio a las celdas.
        void imprimirSeparadorEncabezado();
        void imprimirSeparadorFilas();
        void imprimirEncabezado();
        void imprimir();
        //Coloca la mina en el tablero
        bool colocarMina(int x, int y);
        //Indica si la celda está descubierta.
        bool descubrirMina(int x, int y);
        int contarCeldasSinMinasYSinDescubrir();
        int vidasRestantes();

    protected:
//variables privadas
    private:
        //Se usará el tamaño de filas y columnas como un ancho y una altura
        int alturaTablero, anchoTablero;
        //Se declara el modo desarrollador
        bool modoDesarrollador;
        //Se usa el vector para llenar las celdas en el tablero.
        vector<vector<Celda> > contenidoTablero;
        //
        string getRepresentacionMina(int x, int y);
        //Se utiliza para que el jugador sepa cuantas minas hay cerca de esa celda.
        int minasCercanas(int fila, int columna);
};

#endif // TABLERO_H
