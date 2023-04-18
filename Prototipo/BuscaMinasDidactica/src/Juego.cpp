//Librería usada:
#include "Juego.h"
#include "Config.h"
// Invoca la libreria para usas sus funciones

// Permite un rango de numeros al elegir de una fila o columna, dependiendo del tamano de esta.
int Juego::aleatorio_en_rango(int minimo, int maximo)
	{
		return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
	}

// Permite ingresar un numero para posicionarlo en un lugar de la fila
	int Juego::filaAleatoria()
	{
		return this->aleatorio_en_rango(0, this->tablero.getAlturaTablero() - 1);
	}

// Permite ingresar un numero para posicionarlo en un lugar de la columna
	int Juego::columnaAleatoria()
	{
		return this->aleatorio_en_rango(0, this->tablero.getAnchoTablero() - 1);
	}

// Permite un numero de minas en posiciones al azar del tablero, dependiendo del tamano de este.
	Juego::Juego(Tablero tablero, int cantidadMinas)
	{
		this->tablero = tablero;
		this->cantidadMinas = cantidadMinas;
		this->colocarMinasAleatoriamente();
	}

// Posiciona un numero de minas en posiciones al azar dentro del tablero, indicando de izquierda a derecha y de arriba a abajo, reiniciando el metodo con un ciclo.
	void Juego::colocarMinasAleatoriamente()
	{
		int x, y, minasColocadas = 0;

		while (minasColocadas < this->cantidadMinas)
		{
			x = this->columnaAleatoria();
			y = this->filaAleatoria();
			if (this->tablero.colocarMina(x, y))
			{
				minasColocadas++;
			}
		}
	}

// Permite que el usuario digite un numero de fila para posicionarse
	int Juego::solicitarFilaUsuario()
	{
		int fila = 0;
		cout << "Ingresa la FILA en la que desea jugar: ";
		cin >> fila;
		return fila - 1;
	}

// Permite que el usuario digite un numero de columna para posicionarse
	int Juego::solicitarColumnaUsuario()
	{
		int columna = 0;
		cout << "Ingresa la COLUMNA en la que desea jugar: ";
		cin >> columna;
		return columna - 1;
	}

// Muestra un mensaje cuando el jugador gana la partida, o muestra un mensaje cuando el jugador no gana la partida
	bool Juego::jugadorGana()
	{
		int conteo = this->tablero.contarCeldasSinMinasYSinDescubrir();
		if (conteo == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

// Permite que el juego y sus funciones se ejecuten
	void Juego::iniciar()
	{
		int fila, columna,vidaRestante;
		while (true)
		{
		    // Muestra el tablero y sus funciones
			this->tablero.imprimir();
			// Muestra el mensaje para que el jugador digite el numero de filas que desea posicionarse
			fila = this->solicitarFilaUsuario();
            // Muestra el mensaje para que el jugador digite el numero de columnas que desea posicionarse
			columna = this->solicitarColumnaUsuario();
			// Muestra si la casilla tiene una mina o no, permitiendo seguir con el juego o acabar con el proceso
			bool respuestaAUsuario = this->tablero.descubrirMina(columna, fila);
			if (!respuestaAUsuario)
			{
			    vidaRestante= this -> tablero.vidasRestantes();
			    if (vidaRestante ==0)
                {
                    cout << "Perdiste el Juego\n";
                    this->tablero.setModoDesarrollador(true);
                }
				this->tablero.imprimir();
				break;
			}
			if (this->jugadorGana())
			{
				cout << "Ganaste el Juego\n";
				this->tablero.setModoDesarrollador(true);
				this->tablero.imprimir();
				break;
			}
		}
	}
