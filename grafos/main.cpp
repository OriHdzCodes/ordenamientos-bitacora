/*
Actividad Integral de Grafos (Evidencia Competencia
Integrantes: 
Oriana Isabella Cañizales Hernandez | A01738027
Ximena Ortiz Gómez | A01735100
Bum Soo Jang | A01665654
*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


struct Dato {
    string fechaYHora;
    string puerto;
    string mensaje;
    Dato(string fechaYHora, string puerto, string mensaje) : fechaYHora(fechaYHora), puerto(puerto), mensaje(mensaje) {};
}; 

struct Host {
    int ip3;
    int ip4;
    int gradosSalida;
    vector <Dato*> vecDatos;
    Host(int ip3, int ip4) : ip3(ip3), ip4(ip4), gradosSalida(0) {};
    void imprimirHost(int ip1, int ip2) {
        cout << ip1 << "." << ip2 << "." << ip3 << "." << ip4 << endl;
    }
};


struct Red {
    int ip1;
    int ip2;
    int gradosSalida;
    vector <Host*> vecRedes;
    Red(int ip1, int ip2) : ip1(ip1), ip2(ip2), gradosSalida(0) {};
    void impimirRed() {
        cout << ip1 << "." << ip2 << ".";
    }
};

struct Nodo {
    vector <Red*> redes;
    Nodo() {}
};

//Funcion crearGrafo O(n^2) pues en el peor de los casos recorre todas las redes y todos los hosts
void crearGrafo(Nodo* root, vector<Red*>& redes, vector<Host*>& hosts, vector<Dato*>& datos) {
    Red* redEncontrada = NULL;
    Host* hostEncontrado = NULL;

    for (int i = 0; i < root->redes.size(); i++) { //buscar si red ya existe en nuestro nodo raíz
        if (root->redes[i]->ip1 == redes.back()->ip1 && root->redes[i]->ip2 == redes.back()->ip2) {
            redEncontrada = root->redes[i];
            break;
        }
    }
    //si la red no existe, la creo y agrego al nodo raíz y vector de redes
    if (!redEncontrada) {
        redEncontrada = redes.back();
        root->redes.push_back(redEncontrada);
    }

    for (int j = 0; j < redEncontrada->vecRedes.size(); j++) { //buscar si el host de la red ya existe
        if (redEncontrada->vecRedes[j]->ip3 == hosts.back()->ip3 && redEncontrada->vecRedes[j]->ip4 == hosts.back()->ip4) {
            hostEncontrado = redEncontrada->vecRedes[j];
            break;
        }
    }
    //si el host no existe entonces lo añado al vector hosts de la red
    if (!hostEncontrado) {
        hostEncontrado = hosts.back(); 
        redEncontrada->vecRedes.push_back(hostEncontrado);
    }

    Dato* nuevoDato = datos.back();
    hostEncontrado->vecDatos.push_back(nuevoDato);

    hostEncontrado->gradosSalida++;
    redEncontrada->gradosSalida++;
}

//LeerArchivo: Complejidad O(n^3) ya que cada linea del archivo llama a crearGrafo que es complejidad cuadrada
Nodo* leerArchivo(const string& nombreArchivo, vector<Red*>& redes, vector<Host*>& hosts, vector<Dato*>& datos) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        return nullptr;
    }
    
    string mensaje, fechaYHora, puerto;
    int ip1, ip2, ip3, ip4;
    char delim;
    
    Nodo* Root = new Nodo();

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string mes, dia, reloj;
        ss >> mes >> dia >> reloj >> ip1 >> delim >> ip2 >> delim >> ip3 >> delim >> ip4 >> delim >> puerto;
        getline (ss, mensaje);
        fechaYHora = mes + " " + dia + " " + reloj;
        
        Red* nuevaRed = new Red(ip1, ip2);
        Host* nuevoHost = new Host(ip3, ip4);
        Dato* nuevoDato = new Dato(fechaYHora, puerto, mensaje);

        redes.push_back(nuevaRed);
        hosts.push_back(nuevoHost);
        datos.push_back(nuevoDato);
        crearGrafo(Root, redes, hosts, datos);
    }

    archivo.close();
    return Root;
}

//funcion hostsMasRepetidos: complejidad O(n^2) dado que recorre todas las redes, los hosts para contar la cantidad de datos, dado que itera, su complejidad es cuadratica
void hostsMasRepetidos(vector<Red*>& redes) {
    int maxRepeticiones = 0;
    vector<pair<Red*, Host*>> hostsMaximos;

    for (int i = 0; i < redes.size(); i++) {
        Red* red = redes[i];
        for (int j = 0; j < red->vecRedes.size(); j++) {
            Host* host = red->vecRedes[j];
            int numDatos = host->vecDatos.size();
            if (numDatos > maxRepeticiones) {
                maxRepeticiones = numDatos;
                hostsMaximos.clear();
                hostsMaximos.push_back(make_pair(red, host));
            } else if (numDatos == maxRepeticiones) {
                hostsMaximos.push_back(make_pair(red, host));
            }
        }
    }

    // Imprime los hosts con la mayor cantidad de datos en el formato ip1.ip2.ip3.ip4
    for (int k = 0; k < hostsMaximos.size(); k++) {
        cout << hostsMaximos[k].first->ip1 << "." << hostsMaximos[k].first->ip2 << "."<< hostsMaximos[k].second->ip3 << "."
        << hostsMaximos[k].second->ip4 << endl;
    }
}

//Funcion resultadosGradoSalida: complejidad O(n^2) ya que recorre todas las redes y para cada red su host 
void resultadoGradoSalida(Nodo *root){
    for (Red* red : root -> redes){
        cout << red -> ip1 << "." << red -> ip2 << "." << red -> gradosSalida << endl;
        for (Host* host : red -> vecRedes){
            cout << red -> ip1 << "." << red -> ip2 << "." << host -> ip3 << "." << host -> ip4 << endl;
        }
    }
}

//Funcion redConMasGradosSalida: complejidad O(n) ya que la funcion recorre una vez el conjunto de redes
void redConMasGradosSalida(Nodo *root) {
    int maxGradoSalida = 0;
    vector<string> redesMaxGradoSalida;

    for (Red* red : root -> redes) {
        //cout << red -> ip1 << "." << red -> ip2 << red -> gradosSalida << endl;

        if (red -> gradosSalida > maxGradoSalida) {
            maxGradoSalida = red -> gradosSalida;
            redesMaxGradoSalida.clear();
            redesMaxGradoSalida.push_back(to_string(red -> ip1) + "." + to_string(red -> ip2));
        } else if (red->gradosSalida == maxGradoSalida) {
            redesMaxGradoSalida.push_back(to_string(red -> ip1) + "." + to_string(red -> ip2));
        }
    }

    //cout << maxGradoSalida << endl;
    for (const string& red : redesMaxGradoSalida) {
        cout << red << endl;
    }
}

int main(){
    vector<Red*> redes;
    vector<Host*> hosts;
    vector<Dato*> datos;

    Nodo* root = leerArchivo("bitacora.txt", redes, hosts, datos);

    if (root) {
        redConMasGradosSalida(root);
        cout << endl;
        hostsMasRepetidos(redes); 
    } else {
        cerr << "No se pudo cargar el grafo." << endl;
    }

    return 0;
}
