//Librerías usadas solamente iostream y utilizaremos nuestra libreria "Celda.h"
#include "Celda.h"
#include <iostream>
//Libreria que guarda los atributos y los prototipos de los metodos utilizados para crear y administrar las celdas de juego y la libreria iostream.
//Fecha: 17 marzo 2023
using namespace std;
Celda::Celda()
{
}
Celda::Celda(int coordenadaX, int coordenadaY, bool estadoMina)
{   //Usaremos los punteros para colocar las variables.
    this->coordenadaX = coordenadaX;
    this->coordenadaY = coordenadaY;
    this->mina = estadoMina;
    this->minaDescubierta = false;

//con esto lograremos ubicarnos en nuestro tablero gracias a los ejes x, y que hemos declarado anteriormente en "Celda.h"
}
int Celda::setCoordenadaX(int coordenadaX)
{
    this->coordenadaX = coordenadaX;
}//agregando valores
int Celda::getCoordenadaX()
{
    return this->coordenadaX;
}//aca podremos ver en donde estan posicionadas las minas dentro del tablero de juego, (se examina en una fila en una columna
int Celda::setCoordenadaY(int coordenadaY)
{
    this->coordenadaY = coordenadaY;
}
int Celda::getCoordenadaY()
{
    return this->coordenadaY;
}//configurando el estado de la mina
bool Celda::setMina(bool estadoMina)
{
    if (this->getMina())
    {
        return false;
    }
    else{
        this->mina = estadoMina;
        return true;
    }
}//aca obtendremos la mina
bool Celda::getMina()
{
    return this->mina;
}//esto nos ayudara a examinar donde se encuentran las minas dentro del submenu de configuracion del juego
bool Celda::setMinaDescubierta(bool minaDescubierta)
{
    this->minaDescubierta = minaDescubierta;
}
bool Celda::getMinaDescubierta()
{
    return this->minaDescubierta;
}//este nos ayuda a ver la mina en la que hemos caido
void Celda::imprimirCelda()
{ //mostrando "Celda en" y " con mina? " para ver si donde estamos hay una mina
    cout << "Celda en " << this->coordenadaX << ", " << this->coordenadaY << " con mina? " << this->mina << "\n";
}
