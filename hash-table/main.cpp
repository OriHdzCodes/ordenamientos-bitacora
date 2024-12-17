/*Actividad Act 5.2: Actividad Integral sobre el uso de códigos hash (Evidencia Competencia)
Integrantes: 
Oriana Isabella Cañizales Hernandez | A01738027
Ximena Ortiz Gómez | A01735100
Bum Soo Jang | A01665654*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct IP {
    int ip1;
    int ip2;
    int ip3;
    int ip4;

    int getip1() const {return ip1;};
    int getip2() const {return ip2;};
    int getip3() const {return ip3;};
    int getip4() const {return ip4;};
    
    IP(int ip1, int ip2, int ip3, int ip4) : ip1(ip1), ip2(ip2), ip3(ip3), ip4(ip4) {};
    IP() : ip1(0), ip2(0), ip3(0), ip4(0) {};

    bool compararIPs(IP otra) const { 
        if (ip1 <otra.getip1()) {
            return true;
        } else if (ip1 > otra.getip1()) {
            return false;
        } else {
            if (ip2 < otra.getip2()) {
                return true;
            } else if (ip2 > otra.getip2()) {
                return false;
            } else {
                if (ip3<otra.getip3()) {
                    return true;
                } else if (ip3 >otra.getip3()) {
                    return false;
                } else {
                    if (ip4 < otra.getip4()) {
                        return true;
                    } else if (ip4 >otra.getip4()) {
                        return false;
                    }
                }
            }
        }
        return false;
    }

    void imprimirIP() {
        cout << ip1 << "." << ip2 << "." << ip3 << "." << ip4;
    };
};

struct Resumen {
    IP ipSelec;
    int numAccesos;
    int numConexiones;
    bool celdaOcupada = false;
    vector <IP> vecIPs;

    Resumen(IP ipSelec, int numA, int numC) : ipSelec(ipSelec), numAccesos(numA), numConexiones(numC) {};
    Resumen() : ipSelec(IP()), numAccesos(0), numConexiones(0), celdaOcupada(false) {};

    void setConexiones(int nuevasConexiones) {
        numConexiones = nuevasConexiones;
    }
    void sumarAcceso () {
        numAccesos = numAccesos + 1;
    }

    void setCelda(){
        celdaOcupada = true;
    }

    bool getCelda() const {
        return celdaOcupada;
    }

    void imprimirResumen() {
        cout << ipSelec.getip1() << "." << ipSelec.getip2() << endl; 
        cout << numAccesos << endl; 
        cout << numConexiones << endl;
        for (int i = 0; i < vecIPs.size(); i++) {
            vecIPs[i].imprimirIP();
            cout<<endl;
        }
    }
};

const int tamanioTabla = 65521;
Resumen tabla[tamanioTabla];

/*funHash: Complejidad O(1) ya que solo realiza una suma y un modulo
*/
unsigned long long funHash (int ip1, int ip2) {
    return (ip1+ip2)%tamanioTabla;
}

/*Complejidad  O(n) dado que recorre toda la tabla si está llena
*/
int disponible(int indice) {
    int inicio = indice;

    do {
        if (tabla[indice].getCelda() == false) {
            return indice;
        } 
        else if (indice == tamanioTabla - 1) {
            indice = 0; 
        } else {
            indice = indice + 1; 
        }
    } while (indice != inicio);
    return -1;
}

/*Funcion insertar: complejidad O(n) dado que recorre la tabla y si esta llena la recorre toda pra poder insertar el valor
*/
void insertar(Resumen nuevo) {
    int ip1 = nuevo.ipSelec.getip1();
    int ip2 = nuevo.ipSelec.getip2();
    int key = funHash(ip1, ip2);

    int indice_final = disponible(key);
    if (indice_final == -1) {
        cout << "tabla llena, imposible insertar" << endl;
            return;
    }

    tabla[indice_final] = nuevo;
    tabla[indice_final].setCelda();
    return;

}

/*Funcion crearAccesosyConexiones: Complejidad (nlogn) dado que recorrer la tabla toma  y ordena vecIPs 
*/
void crearAccesosyConexiones(Resumen& current) {
    int ip1 = current.ipSelec.getip1();
    int ip2 = current.ipSelec.getip2();
    for (int j = 0; j < tamanioTabla; j++) {
        if (tabla[j].getCelda() && tabla[j].ipSelec.getip1() == ip1 && tabla[j].ipSelec.getip2() == ip2) {
            current.sumarAcceso();
            bool existe = false;
            for (const auto& ip : current.vecIPs) {
                if (tabla[j].ipSelec.getip3() == ip.getip3() && tabla[j].ipSelec.getip4() == ip.getip4()) {
                    existe = true;
                    break;
                }
            }
            if (!existe) {
                current.vecIPs.push_back(tabla[j].ipSelec);
            }
        }
    }
    sort(current.vecIPs.begin(), current.vecIPs.end(), [](const IP& a, const IP& b) {
        if (a.getip1() != b.getip1()) return a.getip1() < b.getip1();
        if (a.getip2() != b.getip2()) return a.getip2() < b.getip2();
        if (a.getip3() != b.getip3()) return a.getip3() < b.getip3();
        return a.getip4() < b.getip4();
    });
    int conexiones = current.vecIPs.size();
    current.setConexiones(conexiones);
}

/*leerArchivo: complejidad O(n) dado que  lee cada linea del archivo, extrae los datos relevantes, 
crea un objeto Resumen para cada línea y luego insertar este objeto en la tabla hash (tabla) usando la función insertar. */
void leerArchivo(const string &nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        exit(1);
    }

    string linea;
    while(getline(archivo, linea)) {
        stringstream ss(linea);
        string mes, dia, reloj, puerto, mensaje;
        int ip1, ip2, ip3, ip4;
        char delim;
        ss >> mes >> dia >> reloj >> ip1 >> delim >> ip2 >> delim >> ip3 >> delim >> ip4 >> delim >> puerto;
        getline (ss, mensaje);

        Resumen nuevo = Resumen(IP(ip1, ip2, ip3, ip4), 0, 1);
        nuevo.vecIPs.push_back(IP{ip1, ip2, ip3, ip4});

        insertar(nuevo);
    }
    archivo.close();
}

int main(){
    leerArchivo("bitacora.txt");
    for (int i = 0; i < tamanioTabla; i++) {
        Resumen& actual = tabla[i];
        crearAccesosyConexiones(actual);
    }

    int N;
    cin>>N;

    for (int i = 0; i < N; i++) {
        string dominio;
        cin>>dominio;
        
        stringstream ss(dominio);
        int ip1, ip2;
        char dot;
        ss >> ip1 >> dot >> ip2;

        int indice = funHash(ip1, ip2);

        for (int j = 0; j < tamanioTabla; j++) {
            Resumen curent = tabla[j];
            if (tabla[j].getCelda() && tabla[j].ipSelec.getip1() == ip1 && tabla[j].ipSelec.getip2() == ip2) {
                tabla[j].imprimirResumen();
                break;
            }
        }
    }

    return 0;
}