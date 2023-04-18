//Librerías usadas:
#ifndef CELDA_H
#define CELDA_H
//Libreria que guarda los atributos y los prototipos de los metodos utilizados para crear y administrar las celdas de juego
//Fecha: 17 marzo 2023

class Celda
{
    public:
        //Inicia con el proceso celda para tomar valores de cada casilla y saber que estado tiene la mina.
        Celda();
        Celda(int coordenadaX, int coordenadaY, bool estadoMina);
        //Indica las coordenadas x,y osea las filas y las columnas.
        int setCoordenadaX(int coordenadaX);
        int getCoordenadaX();
        int setCoordenadaY(int coordenadaY);
        int getCoordenadaY();
        //Determina si la celda tendrá una mina o no.
        bool setMina(bool estadoMina);
        //Obtiene el valor de la mina.
        bool getMina();
        //Permite saber si la mina fue descubierta por lo que termina el juego.
        bool setMinaDescubierta(bool minaDescubierta);
        bool getMinaDescubierta();
        //imprimi la celda que se ha seleccionado.
        void imprimirCelda();
    protected:
    //Variables privadas:
    private:
        int coordenadaX, coordenadaY;
        bool mina, minaDescubierta;
};

#endif // CELDA_H
