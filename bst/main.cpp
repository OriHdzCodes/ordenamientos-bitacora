/* Oriana Isabella Cañizales Hernández: A01738027
Bum Soo Jang: A01665654
Ximena Ortiz Gómez: A01735100
*/

#include <fstream>
#include <string>
#include <iomanip>
#include <iostream>
#include "Registro.h"
using namespace std;

Fecha::Fecha(string mesv, int diav):mes(mesv), dia(diav){}//Complejidad O(1) pues inicializa a los miembros de la clase //Complejidad O(1) pues inicializa a los miembros de la clase

string Fecha:: getMes() const{//Complejidad O(1) pues es acceso directo a un miembro de la clase Fecha //Complejidad O(1) pues es acceso directo a un miembro de la clase Fecha
    return mes;
}

int Fecha:: getDia() const{//Complejidad O(1) pues es acceso directo a un miembro de la clase Fecha//Complejidad O(1) pues es acceso directo a un miembro de la clase Fecha
    return dia;
}

void Fecha::setMes(string mesv){//Complejidad O(1) pues es acceso directo a un miembro de la clase Fecha//Complejidad O(1) pues es acceso directo a un miembro de la clase Fecha
    mes=mesv;
} 
void Fecha::setDia(int diav) {//Complejidad O(1) pues es acceso directo a un miembro de la clase Fecha
    dia = diav;
}

int Fecha::convertirMesANumero(string mes) const { //complejidad: O(1) dado que la comparacion de meses es constante (12 en total)
    if (mes == "Jan") return 1;
    if (mes == "Feb") return 2;
    if (mes == "Mar") return 3;
    if (mes == "Apr") return 4;
    if (mes == "May") return 5;
    if (mes == "Jun") return 6;
    if (mes == "Jul") return 7;
    if (mes == "Aug") return 8;
    if (mes == "Sep") return 9;
    if (mes == "Oct") return 10;
    if (mes == "Nov") return 11;
    if (mes == "Dec") return 12;
    return 0;
}

int Fecha::getMesAsInt() const { //Complejidad O(1) dado que manda a llamar a una funcion de complejidad O(1)
    return convertirMesANumero(mes);
}

void Fecha::imprimir() const { //Complejidad O(1) pues imprime en tiempo constante
    cout << mes << " " << setfill('0') << setw(2) << dia << " ";
}


Reloj::Reloj(int horav, int minutosv, int segundosv) : hora(horav), minutos(minutosv), segundos(segundosv) {}

int Reloj::getHora() const { //complejidad O(1) dado que es un acceso directo
    return hora;
}

int Reloj::getMinutos() const {//complejidad O(1) dado que es un acceso directo
    return minutos;
}

int Reloj::getSegundos() const {//complejidad O(1) dado que es un acceso directo
    return segundos;
}

void Reloj::setHora(int horav) {//complejidad O(1) dado que es una asignacion directa
    hora = horav;
}

void Reloj::setMinutos(int minutosv) {//complejidad O(1) dado que es una asignacion directa
    minutos = minutosv;
}

void Reloj::setSegundos(int segundosv) {//complejidad O(1) dado que es una asignacion directa
    segundos = segundosv;
}

void Reloj::imprimir() const {//Complejidad O(1) pues imprime en tiempo constante
    cout << setfill('0') << setw(2) << hora << ":" << setfill('0') << setw(2) << minutos << ":" << setfill('0') << setw(2) << segundos << " ";
}

IP::IP(int num_1, int num_2, int num_3, int num_4, int num_5): num1(num_1), num2(num_2), num3(num_3), num4(num_4), num5(num_5){}

int IP::getNum1() const {//complejidad O(1) dado que es un acceso directo
    return num1;
}

int IP::getNum2() const {//complejidad O(1) dado que es un acceso directo
    return num2;
}

int IP::getNum3() const {//complejidad O(1) dado que es un acceso directo
    return num3;
}

int IP::getNum4() const {//complejidad O(1) dado que es un acceso directo
    return num4;
}

int IP::getNum5() const {//complejidad O(1) dado que es un acceso directo
    return num5;
}

void IP::setNum1(int num) {//complejidad O(1) dado que es una asignacion directa
    num1 = num; 
}

void IP::setNum2(int num) {//complejidad O(1) dado que es una asignacion directa
    num2 = num; 
}

void IP::setNum3(int num) {//complejidad O(1) dado que es una asignacion directa
    num3 = num; 
}

void IP::setNum4(int num) {//complejidad O(1) dado que es una asignacion directa
    num4 = num; 
}

void IP::setNum5(int num_5){ //complejidad O(1) dado que es una asignacion directa
    num5 = num_5; 
}

void IP::imprimir() const{//Complejidad O(1) pues imprime en tiempo constante
    cout << num1 << "." << num2 << "." << num3<< "." << num4 << ":" << num5;
}

bool IP::operator==(const IP& other) const { //Complejidad O(1) ya que compara en tiempo constante
    return (num1 == other.num1 && num2 == other.num2 && num3 == other.num3 && num4 == other.num4);
}

Registro::Registro(Fecha fecha_ren, Reloj reloj_ren, IP ip_ren, string mensaje_ren): //Complejidad O(1) ya que es una funcion que da acceso a los miembros de la clase
fecha(fecha_ren), reloj(reloj_ren), ip(ip_ren), mensaje(mensaje_ren){}

Fecha Registro::getFecha() const{
    return fecha;
}

Reloj Registro:: getReloj()const{
    return reloj;
}

IP Registro::getIP() const{
    return ip;
}

std::string Registro::getMensaje() const {
    return mensaje;
}

void Registro::imprimir()const{ //Complejidad O(1) ya que llama a metodos que son de complejidad O(1)
    fecha.imprimir();
    cout << " ";
    reloj.imprimir();
    cout << " ";
    ip.imprimir();
    cout<<mensaje << endl;
}

//Complejidad O(1) ya que cada comparacion de atributos es de manera secuencial
bool Registro::comparacion(const Registro& otro) const {
    if (ip.getNum1() != otro.getIP().getNum1()) {
        return ip.getNum1() < otro.getIP().getNum1();
    } else if (ip.getNum2() != otro.getIP().getNum2()) {
        return ip.getNum2() < otro.getIP().getNum2();
    } else if (ip.getNum3() != otro.getIP().getNum3()) {
        return ip.getNum3() < otro.getIP().getNum3();
    } else if (ip.getNum4() != otro.getIP().getNum4()) {
        return ip.getNum4() < otro.getIP().getNum4();
    } else if (ip.getNum5() != otro.getIP().getNum5()) {
        return ip.getNum5() < otro.getIP().getNum5();
    } else if (fecha.getMesAsInt() != otro.getFecha().getMesAsInt()) {
        return fecha.getMesAsInt() < otro.getFecha().getMesAsInt();
    } else if (fecha.getDia() != otro.getFecha().getDia()) {
        return fecha.getDia() < otro.getFecha().getDia();
    } else if (reloj.getHora() != otro.getReloj().getHora()) {
        return reloj.getHora() < otro.getReloj().getHora();
    } else if (reloj.getMinutos() != otro.getReloj().getMinutos()) {
        return reloj.getMinutos() < otro.getReloj().getMinutos();
    } else if (reloj.getSegundos() != otro.getReloj().getSegundos()) {
        return reloj.getSegundos() < otro.getReloj().getSegundos();
    } else {
        return mensaje < otro.getMensaje();
    }
        
}

struct Nodo {
    Registro dato;
    Nodo *right, *left;
    Nodo (Registro reg) : dato(reg), right(NULL), left(NULL){} 
};

void agregarNodo(Nodo **Padre, Registro nuevo_reg) {
    if (*Padre == NULL) {
        Nodo *nuevoNodo = new Nodo(nuevo_reg);
        *Padre = nuevoNodo;
        return;
    } else {
        Nodo *PunteroPadre = *Padre;
        if (nuevo_reg.comparacion(PunteroPadre -> dato)) { //comapara si es menor
            if (PunteroPadre -> left == nullptr) {
                Nodo *nuevoNodo = new Nodo(nuevo_reg);
                PunteroPadre -> left = nuevoNodo;
                return;
            } else {
                agregarNodo(&(PunteroPadre -> left), nuevo_reg);
            }
        } else if (PunteroPadre -> dato.comparacion(nuevo_reg)) { //compara si es mayor
            if (PunteroPadre -> right == nullptr) {
                Nodo *nuevoNodo = new Nodo(nuevo_reg);
                PunteroPadre -> right = nuevoNodo;
                return;
            } else {
                agregarNodo(&(PunteroPadre -> right), nuevo_reg);
            }
        } else {
            return;
        }
    }
}

Nodo* leerArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        return nullptr; // O maneja el error de otra manera
    }
    
    string mes, mensaje;
    int dia, hora, minuto, segundo;
    int ip1, ip2, ip3, ip4, ip5;
    char delim;
    
    Nodo* Root = NULL;

    while (archivo >> mes >> dia >> hora >> delim >> minuto >> delim >> segundo >> ip1 >> delim >> ip2 >> delim >> ip3 >> delim >> ip4 >> delim >> ip5) {
        getline(archivo, mensaje);

        Fecha fecha(mes, dia);
        Reloj reloj(hora, minuto, segundo);
        IP ip(ip1, ip2, ip3, ip4, ip5);
        Registro registro(fecha, reloj, ip, mensaje);

        agregarNodo(&Root, registro);
        
    }


    archivo.close();
    return Root;

}

void inOrdenConvexo_5(Nodo* arbol, int &contador){ //se utiliza ampersant para que el valor cambie en las llamadas recursivas
    if (arbol == NULL || contador >= 5){
        return;
    }
    else{
        inOrdenConvexo_5(arbol -> right, contador);
        if (contador < 5) {
            arbol -> dato.imprimir();
            contador++;
        }
        inOrdenConvexo_5(arbol -> left, contador);
    }
}

int main(){
    Nodo* bitacora = leerArchivo("bitacora.txt");
    int contador = 0;
    inOrdenConvexo_5(bitacora, contador);
}