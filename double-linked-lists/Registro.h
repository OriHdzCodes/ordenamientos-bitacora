#include <iostream>
#include "Fecha.h"
#include "Reloj.h"
#include "IP.h"
using namespace std;

class Registro{

public:
    Registro(Fecha fecha, Reloj reloj, IP ip, string mensaje);
    Fecha getFecha() const;
    Reloj getReloj() const;
    IP getIP()const;
    string getMensaje()const;
    void imprimir() const;
    bool comparacion(const Registro& otro) const;

private:
    Fecha fecha;
    Reloj reloj;
    IP ip;
    string mensaje; 
};