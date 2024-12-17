#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Registro.h"
using namespace std;

Fecha::Fecha(string mesv, int diav) : mes(mesv), dia(diav) {}

string Fecha::getMes() const {
    return mes;
}

int Fecha::getDia() const {
    return dia;
}

void Fecha::setMes(string mesv) {
    mes = mesv;
}

void Fecha::setDia(int diav) {
    dia = diav;
}

int Fecha::convertirMesANumero(string mes) const {
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

int Fecha::getMesAsInt() const {
    return convertirMesANumero(mes);
}

void Fecha::imprimir() const {
    cout << mes << " " << dia << " ";
}

Reloj::Reloj(int horav, int minutosv, int segundosv)
    : hora(horav), minutos(minutosv), segundos(segundosv) {}

int Reloj::getHora() const {
    return hora;
}

int Reloj::getMinutos() const {
    return minutos;
}

int Reloj::getSegundos() const {
    return segundos;
}

void Reloj::setHora(int horav) {
    hora = horav;
}

void Reloj::setMinutos(int minutosv) {
    minutos = minutosv;
}

void Reloj::setSegundos(int segundosv) {
    segundos = segundosv;
}

void Reloj::imprimir() const {
    cout << hora << ":" << minutos << ":" << segundos << " ";
}

IP::IP(int num_1, int num_2, int num_3, int num_4, int num_5): num1(num_1), num2(num_2), num3(num_3), num4(num_4), num5(num_5){}

int IP::getNum1() const{
    return num1;
}

int IP::getNum2() const{
    return num2;
}

int IP::getNum3() const{
    return num3;
}

int IP::getNum4() const{
    return num4;
}

int IP::getNum5() const{
    return num5;
}

void IP::setNum1(int num_1){
    num1 = num_1; 
}

void IP::setNum2(int num_2){
    num2 = num_2; 
}

void IP::setNum3(int num_3){
    num3 = num_3; 
}

void IP::setNum4(int num_4){
    num4 = num_4; 
}

void IP::setNum5(int num_5){
    num5 = num_5; 
}

void IP::imprimir() const{
    cout << num1 << "." << num2 << "." << num3<< "." << num4 << "." << num5 << " ";
}

Registro::Registro(Fecha fecha_ren, Reloj reloj_ren, IP ip_ren, string mensaje_ren): 
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

void Registro::imprimir()const{
    fecha.imprimir();
    reloj.imprimir();
    ip.imprimir();
    cout<<mensaje<<endl;
}

bool Registro::comparacion(const Registro& otro) const{
    if (fecha.getMesAsInt()<otro.getFecha().getMesAsInt()) {
        return true;
    }  
    else if (fecha.getMesAsInt()>otro.getFecha().getMesAsInt()) {
        return false;
    }
    else {
        if(fecha.getDia()<otro.getFecha().getDia()) {
            return true;
        }
        else if (fecha.getDia()>otro.getFecha().getDia()) {
            return false;
        }
        else {
            if (reloj.getHora() < otro.getReloj().getHora()) {
                return true;
            }
            else if (reloj.getHora() > otro.getReloj().getHora()) {
                return false;
            }
            else {
                if(reloj.getMinutos()<otro.getReloj().getMinutos()) {
                    return true;
                }
                else if (reloj.getMinutos()>otro.getReloj().getMinutos()) {
                    return false;
                }
                else {
                    if (reloj.getSegundos() < otro.getReloj().getSegundos()) {
                        return true;
                    }
                    else if (reloj.getSegundos() > otro.getReloj().getSegundos()) {
                        return false;
                    }
                    else {
                        if (ip.getNum1() < otro.getIP().getNum1()) {
                            return true;
                        }
                        else if (ip.getNum1() > otro.getIP().getNum1()) {
                            return false;
                        }
                        else {
                            if (ip.getNum2() < otro.getIP().getNum2()) {
                                return true;
                            }
                            else if (ip.getNum2() > otro.getIP().getNum2()) {
                                return false;
                            }
                            else {
                                if (ip.getNum3() < otro.getIP().getNum3()) {
                                    return true;
                                }
                                else if (ip.getNum3() > otro.getIP().getNum3()) {
                                    return false;
                                }
                                else {
                                    if (ip.getNum4() < otro.getIP().getNum4()) {
                                        return true;
                                    }
                                    else if (ip.getNum4() > otro.getIP().getNum4()) {
                                        return false;
                                    }
                                    else {
                                        if (ip.getNum5() < otro.getIP().getNum5()) {
                                            return true;
                                        }
                                        else if (ip.getNum5() > otro.getIP().getNum5()) {
                                            return false;
                                        }
                                    }  
                                }
                            }

                        }

                    }
                }

            }
        }
    }
    return false;
}

void solicitarFechas(int& mesInicio, int& diaInicio, int& mesFin, int& diaFin) {
    cout << "Introduce mes de inicio (1-12): ";
    cin >> mesInicio;
    cout << "Introduce dia de inicio: ";
    cin >> diaInicio;
    cout << "Introduce mes de fin (1-12): ";
    cin >> mesFin;
    cout << "Introduce dia de fin: ";
    cin >> diaFin;
};


vector<Registro> leerArchivo(const string &nombreArchivo) {
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo: " << nombreArchivo << endl;
        exit(1);
    }

    vector<Registro> registros;

    string mes, mensaje;
    int dia, hora, minuto, segundo;
    int ip1, ip2, ip3, ip4, ip5;
    char delim;

    while (archivo >> mes >> dia >> hora >> delim >> minuto >> delim >> segundo >> ip1 >> delim >> ip2 >> delim >> ip3 >> delim >> ip4 >> delim >> ip5) {
        getline(archivo, mensaje);

        Fecha fecha(mes, dia);
        Reloj reloj(hora, minuto, segundo);
        IP ip(ip1, ip2, ip3, ip4, ip5);
        Registro registro(fecha, reloj, ip, mensaje);
        registros.push_back(registro);
    }

    archivo.close();
    return registros;
}

int partition(vector <Registro>& bitacora_a_ordenar, int inicio, int fin) {
    Registro elempivote = bitacora_a_ordenar[fin];
    int i = inicio - 1;
    for (int j = inicio; j <= fin - 1; j++) {
        if (bitacora_a_ordenar[j].comparacion(elempivote)){
            i++;
            Registro temp = bitacora_a_ordenar[i];
            bitacora_a_ordenar[i] = bitacora_a_ordenar[j];
            bitacora_a_ordenar[j] = temp;
        }
    }
    i++;
    Registro temp = bitacora_a_ordenar[i];
    bitacora_a_ordenar[i] = bitacora_a_ordenar[fin];
    bitacora_a_ordenar[fin] = temp;
    return i;
};

void quickSort(vector <Registro>& bitacora_a_ordenar, int inicio, int fin) {
    if (fin <= inicio) {
        return;
    }
    int pivote = partition(bitacora_a_ordenar, inicio, fin);
    quickSort(bitacora_a_ordenar, inicio, pivote - 1);
    quickSort(bitacora_a_ordenar, pivote + 1, fin);
};

int busquedaBinPimer(vector <Registro>& bitacora_a_buscar, int mes_a_buscar, int dia_a_buscar) {
    int inicio = 0;
    int fin = bitacora_a_buscar.size() - 1;
    int resultado = -1;

    while (inicio <= fin) {
        int mitad = inicio + (fin - inicio) / 2;
        Registro registro_mitad = bitacora_a_buscar[mitad];
        Fecha fecha_mitad = registro_mitad.getFecha();
        int mes_mitad = fecha_mitad.getMesAsInt();
        int dia_mitad = fecha_mitad.getDia();

       if (mes_mitad == mes_a_buscar){
        if (dia_mitad == dia_a_buscar) {
            resultado = mitad;
            fin = mitad -1;
        }
        else if (dia_mitad < dia_a_buscar) {
            inicio = mitad + 1;
        }
        else {
            fin = mitad - 1;
        }
       }
       else if (mes_mitad < mes_a_buscar) {
        inicio = mitad + 1;
       }
       else {
        fin = mitad - 1;
       }
       
    }
    return resultado;
}

int busquedaBinUltm(vector <Registro>& bitacora_a_buscar, int mes_a_buscar, int dia_a_buscar){
    int inicio = 0;
    int fin = bitacora_a_buscar.size() - 1;
    int resultado = -1;

    while (inicio <= fin) {
        int mitad = inicio + (fin - inicio) / 2;
        Registro registro_mitad = bitacora_a_buscar[mitad];
        Fecha fecha_mitad = registro_mitad.getFecha();
        int mes_mitad = fecha_mitad.getMesAsInt();
        int dia_mitad = fecha_mitad.getDia();

       if (mes_mitad == mes_a_buscar){
        if (dia_mitad == dia_a_buscar) {
            resultado = mitad;
            inicio = mitad +1;
        }
        else if (dia_mitad < dia_a_buscar) {
            inicio = mitad + 1;
        }
        else {
            fin = mitad - 1;
        }
       }
       else if (mes_mitad < mes_a_buscar) {
        inicio = mitad + 1;
       }
       else {
        fin = mitad - 1;
       }
       
    }
    return resultado;
};

void imprimeFechas(vector <Registro>& bitacora_ordenada, int mes_i, int dia_i, int mes_f, int dia_f) {
    int indx_inicio = busquedaBinPimer(bitacora_ordenada, mes_i, dia_i);
    int indx_fin = busquedaBinUltm(bitacora_ordenada, mes_f, dia_f);
    for (int i = indx_inicio; i <= indx_fin; i++) {
        bitacora_ordenada[i].imprimir();
    }
};

void guardarArchivo(const vector<Registro>& registros, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cerr << "Error: No se pudo crear el archivo " << nombreArchivo << endl;
        return;
    }

    for (const Registro& registro : registros) {
        const Fecha& fecha = registro.getFecha();
        const Reloj& reloj = registro.getReloj();
        const IP& ip = registro.getIP();
        const string& mensaje = registro.getMensaje();

        archivo << fecha.getMes() << " " << fecha.getDia() << " "<< reloj.getHora() << ":" << reloj.getMinutos() << ":" << reloj.getSegundos() << " "
        << ip.getNum1() << "." << ip.getNum2() << "." << ip.getNum3() << "." << ip.getNum4() << ":" << ip.getNum5() << " "<< mensaje << endl;
    }

    archivo.close();
    cout << "Archivo '" << nombreArchivo << "' guardado correctamente" << endl;
}

int main(){ 
    // Leer archivo de bitácora
    vector<Registro> bitacora = leerArchivo("bitacora.txt");
    
    //Orrdenar bitacora
    int indice_final = bitacora.size() -1 ;
    quickSort(bitacora, 0, indice_final);

    //Imprimir rango de fechas
    int mesInicio, diaInicio,  mesFin, diaFin;
    solicitarFechas(mesInicio, diaInicio,  mesFin, diaFin);
    imprimeFechas(bitacora, mesInicio, diaInicio, mesFin, diaFin);

    //guardar bitacora en sorted.txt
    guardarArchivo(bitacora, "sorted.txt");

    return 0;
};