#include <iostream>
using namespace std;

class Fecha{
    
public:
    Fecha(string mes, int dia);
    string getMes() const;
    int getDia() const;
    int getMesAsInt() const; 
    void setMes(string);
    void setDia(int);
    void imprimir() const;
    bool operator>(Fecha& otra);
    bool operator==(Fecha& otra);

private:
    string mes;
    int dia;
    int convertirMesANumero(string mes) const;  
};