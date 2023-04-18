//Usa las librería que creamos junto con las que usaremos.
#include "Tablero.h"
#include "Config.h"
#include <sstream>
#include <iostream>
using namespace std;

Tablero::Tablero()
{
}
Tablero::Tablero(int alturaTablero, int anchoTablero, bool modoDesarrollador)
{
    //Usa los punteros para usar las variables.
    this->alturaTablero = alturaTablero;
    this->anchoTablero = anchoTablero;
    this->modoDesarrollador = modoDesarrollador;
    int x, y;
    //Se crea un ciclo para llenar las celdas.
    for (y=0; y < this->alturaTablero; y++)
    {
        vector<Celda> fila;
        for (x=0; x < this->anchoTablero; x++)
        {
            fila.push_back((Celda(x, y, false)));
        }
        this->contenidoTablero.push_back(fila);
    }
}
//Obtiene la altura del tablero
int Tablero::getAlturaTablero()
{
    return this->alturaTablero;
}
//Establece la altura del tablero
int Tablero::setAlturaTablero(int alturaTablero)
{
    this->alturaTablero = alturaTablero;
}
//Obtiene el valor del ancho del tablero
int Tablero::getAnchoTablero()
{
    return this->anchoTablero;
}
//Establece el valor del ancho del tablero
int Tablero::setAnchoTablero(int anchoTablero)
{
    this->anchoTablero = anchoTablero;
}
//Obtiene el valor del modo desarrollador
bool Tablero::getModoDesarrollador()
{
    return this->modoDesarrollador;
}
//Establece el valor del modo desarrollador
bool Tablero::setModoDesarrollador(bool modoDesarrollador)
{
    this->modoDesarrollador = modoDesarrollador;
}
//Coloca la mina o un signo de interrogación
string Tablero::getRepresentacionMina(int coordenadaX, int coordenadaY)
{
    Celda celdaTemporal = this->contenidoTablero.at(coordenadaY).at(coordenadaX);
    //muestra el tablero con la celda temporal
    if (celdaTemporal.getMinaDescubierta() || this->modoDesarrollador)
    {
        if (celdaTemporal.getMina())
        {
            //Representa la figura de la mina.
            return "*";
        }
        else
        {
            int cantidadCelda=this->minasCercanas(coordenadaY,coordenadaX);
            string cantidadCeldaString = " ";
            //Se declara ss y da la cantidad de celdas.
            stringstream ss;
            ss << cantidadCelda;
            ss >> cantidadCeldaString;
            return cantidadCeldaString;
        }
    }
    else
    {
        //da un signo de interrogación porque la celda no ha sido descubierta.
        return "?";
        //return ".";
    }
}
//Se crea el tablero.
int Tablero::minasCercanas(int filaTablero, int columnaTablero)
{
        //Define que número tendrán las celdas si es que tienen una mina cerca.
        int contadorTablero = 0;
        int filaInicioTablero, filaFinTablero, columnaInicioTablero, columnaFinTablero;
        if (filaTablero <= 0)
		{
			filaInicioTablero = 0;
		}
		else
		{
			filaInicioTablero = filaTablero - 1;
		}

		if (filaTablero + 1 >= this->alturaTablero)
		{
			filaFinTablero = this->alturaTablero - 1;
		}
		else
		{
			filaFinTablero = filaTablero + 1;
		}

		if (columnaTablero <= 0)
		{
			columnaInicioTablero = 0;
		}
		else
		{
			columnaInicioTablero = columnaTablero - 1;
		}
		if (columnaTablero + 1 >= this->anchoTablero)
		{
			columnaFinTablero = this->anchoTablero - 1;
		}
		else
		{
			columnaFinTablero = columnaTablero + 1;
		}
		int m;
		for (m = filaInicioTablero; m <= filaFinTablero; m++)
		{
			int l;
			for (l = columnaInicioTablero; l <= columnaFinTablero; l++)
			{
				if (this->contenidoTablero.at(m).at(l).getMina())
				{
					contadorTablero++;
				}
			}
		}
		return contadorTablero;
}
//Imprime el separador entre el encabezado y las filas del tablero
void Tablero::imprimirSeparadorEncabezado()
	{
		int m;
		for (m = 0; m <= this->anchoTablero; m++)
		{
			cout << "----";
			if (m + 2 == this->anchoTablero)
			{
				cout << "-";
			}
		}
		cout << "\n";
	}
    //Después de cada fila agrega un separador.
	void Tablero::imprimirSeparadorFilas()
	{
		int m;
		for (m = 0; m <= this->anchoTablero; m++)
		{
			if (m <= 1)
			{
				cout << "|---";
			}
			else
			{
			    //Se usa para separar las columnas.
				cout << "+---";
			}
			if (m == this->anchoTablero)
			{
			    //Cierra la columna para continuar con la siguiente fila.
				cout << "+";
			}
		}
		cout << "\n";
	}
    //Imprime el emcabezado.
	void Tablero::imprimirEncabezado()
	{
		this->imprimirSeparadorEncabezado();
		//deja un espacio para poder colocar el número que corresponde)
		cout << "|   ";
		int l;
		for (l = 0; l < this->anchoTablero; l++)
		{
			cout << "| " << l + 1 << " ";
			if (l + 1 == this->anchoTablero)
			{
			    //Deja un separador.
				cout << "|";
			}
		}
		cout << "\n";
	}
    //Ayuda a imprimir el tablero, con su encabezado (Número de filas y columnas)
	void Tablero::imprimir()
	{
		this->imprimirEncabezado();
		this->imprimirSeparadorEncabezado();
		int x, y;
		for (y = 0; y < this->alturaTablero; y++)
		{
			cout << "| " << y + 1 << " ";
			for (x = 0; x < this->anchoTablero; x++)
			{
			    //Agrega el separador
				cout << "| " << this->getRepresentacionMina(x, y) << " ";
				if (x + 1 == this->anchoTablero)
				{
				    //Agrega el separador
					cout << "|";
				}
			}
			//cambia de fila para seguir con el tablero
			cout << "\n";
			this->imprimirSeparadorFilas();
		}
	}
	// Coloca una mina en el tablero.
    bool Tablero::colocarMina(int x, int y)
	{
		return this->contenidoTablero.at(y).at(x).setMina(true);
	}
	//Si se llega a obtener una mina, se acaba el juego, si no se obtiene este continua.
    bool Tablero::descubrirMina(int x, int y)
	{
		this->contenidoTablero.at(y).at(x).setMinaDescubierta(true);
		Celda celda = this->contenidoTablero.at(y).at(x);
		if (celda.getMina())
		{
			return false;
		}
		return true;
	}
	int Tablero::vidasRestantes()
	{
	    int vidasRestantes =0;
	    this-> getAnchoTablero();
        vidasRestantes = Config.setvidasTablero();
        this-> Config.setminasTablero(vidasRestantes);
        return vidasRestantes;
	}
	int Tablero::contarCeldasSinMinasYSinDescubrir();
	{
		int x, y, contador = 0;
		//usa las filas
		for (y = 0; y < this->alturaTablero; y++)
		{
		    //usa las columnas
			for (x = 0; x < this->anchoTablero; x++)
			{
			    //usa las celdas temporales para saber si está descubierta la celda.
				Celda celdaTemporal = this->contenidoTablero.at(y).at(x);
				if (!celdaTemporal.getMinaDescubierta() && !celdaTemporal.getMina())
				{
				    //Aumenta el número de minas descubiertas.
					contador++;
				}
			}
		}
		return contador;
	}
