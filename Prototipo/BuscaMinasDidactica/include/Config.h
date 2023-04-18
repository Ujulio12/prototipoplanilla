//Librerías usadas:
#ifndef CONFIG_H
#define CONFIG_H
//Libreria que guarda los procesos y las configuraciones de los metodos utilizados para el funcionamiento de las celdas y columnas.
//Fecha: 17 marzo 2023

class Config
{
    public:
        //inicia indicando los valores que tendran utilidad en el juego.
        Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero);
        // Manda a llamar a los espacios entre filas y columnas del tablero para ubicar las minas y lugares seguros.
        int getfilasTablero();
        int setfilasTablero(int filasTablero);
        int getcolumnasTablero();
        int setcolumnasTablero(int columnasTablero);
        int getminasTablero();
        int setminasTablero(int minasTablero);
        // Hace entrar a el modo desarrolador.
        bool getmodoDesarrolladorTablero();
        bool setmodoDesarrolladorTablero(bool modoDesarrolladorTablero);
        // Establece las vidas de la partida en un solo tablero.
        int getvidasTablero();
        int setvidasTablero(int vidasTablero);
        // Abre el menu de configuraciones.
        void menuConfiguracion();
    protected:

    private:
        // Bariables de accion del tablero.
        int filasTablero;
        int columnasTablero;
        int minasTablero;
        // Entrada al modo desarrollador.
        bool modoDesarrolladorTablero;
        int vidasTablero;
};

#endif // CONFIG_H
