//Librerías usadas:
#ifndef JUEGO_H
#define JUEGO_H
#include "Tablero.h"
//Libreria que permite las diferentes funciones del juego, asimismo, invocando la libreria de tablero para ejecutar el juego con ello.
//Fecha: 17 marzo 2023

class Juego
{
private:
    // Llama a tablero y sus funciones
	Tablero tablero;
	// Permite ingresar la cantidad de minas en el tablero
	int cantidadMinas;

    // Permite colocar aleatoriamente las minas en el tablero, guiandose en la cantidad minima y maxima que el usuario haya elegido.
	int aleatorio_en_rango(int minimo, int maximo);
    // Permite colocar aleatoriamente las minas en un numero de fila indicado.
	int filaAleatoria();
    // Permite colocar aleatoriamente las minas en un numero de columna indicado.
	int columnaAleatoria();
public:
	Juego(Tablero tablero, int cantidadMinas);
	// Permite colocar las minas en el tablero de forma aleatoria
	void colocarMinasAleatoriamente();
    // Solicita un numero de fila que el usuario elija
	int solicitarFilaUsuario();
    // Solicita un numero de columna que el usuario elija
	int solicitarColumnaUsuario();
	// Se muestra un men saje si el jugador gana la partida
	bool jugadorGana();
	//Ejecuta el juego
	void iniciar();
};

#endif // JUEGO_H
