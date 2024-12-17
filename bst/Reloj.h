#include <iostream>
using namespace std;

class Reloj {
public:
    Reloj(int hora, int minutos, int segundos);
    int getHora() const;
    int getMinutos() const;
    int getSegundos() const;
    void setHora(int);
    void setMinutos(int);
    void setSegundos(int);
    void imprimir() const;

private:
    int hora;
    int minutos;
    int segundos;
};