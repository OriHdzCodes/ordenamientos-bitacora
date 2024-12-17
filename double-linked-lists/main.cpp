/* Oriana Isabella Cañizales Hernández: 
Bum Soo Jang:
Ximena Ortiz Gómez: 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Registro.h"
using namespace std;

//Struct Node:complejidad O(1) dado que es una operacion constante y solo se inicializan tres miembros (data, next y prev)
struct Node{ 
    Registro data;
    Node* next;
    Node* prev;
    Node (Registro reg): data(reg), next(NULL), prev(NULL){}
};

//agregarNodo: Complejidad O(1) dado que el nodo se inserta cunado esta vacia la lista, al incio o al final o en el medio
void agregarNodo(Node ** head, Node **tail, Registro &data){
    Node *nuevoNodo = new Node(data);

    if (*head == nullptr) { //Si la lista esta vacía
        nuevoNodo -> next = nullptr; 
        nuevoNodo -> prev = nullptr;
        *head = nuevoNodo;
        *tail = nuevoNodo;
    }
    else { //el nodo hasta el final
        nuevoNodo -> next = nullptr;
        nuevoNodo -> prev = *tail;
        (*tail) -> next = nuevoNodo;
        *tail = nuevoNodo;
    }
}      
    


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
    if (ip.getNum1() < otro.getIP().getNum1()) {
        return true;
    } else if (ip.getNum1() > otro.getIP().getNum1()) {
        return false;
    } else {
        if (ip.getNum2() < otro.getIP().getNum2()) {
            return true;
        } else if (ip.getNum2() > otro.getIP().getNum2()) {
            return false;
        } else {
            if (ip.getNum3() < otro.getIP().getNum3()) {
                return true;
            } else if (ip.getNum3() > otro.getIP().getNum3()) {
                return false;
            } else {
                if (ip.getNum4() < otro.getIP().getNum4()) {
                    return true;
                } else if (ip.getNum4() > otro.getIP().getNum4()) {
                    return false;
                }
            }
        }
    }

    if (fecha.getMesAsInt() < otro.getFecha().getMesAsInt()) {
        return true;
    } else if (fecha.getMesAsInt() > otro.getFecha().getMesAsInt()) {
        return false;
    } else {
        if (fecha.getDia() < otro.getFecha().getDia()) {
            return true;
        } else if (fecha.getDia() > otro.getFecha().getDia()) {
            return false;
        } else {
            if (reloj.getHora() < otro.getReloj().getHora()) {
                return true;
            } else if (reloj.getHora() > otro.getReloj().getHora()) {
                return false;
            } else {
                if (reloj.getMinutos() < otro.getReloj().getMinutos()) {
                    return true;
                } else if (reloj.getMinutos() > otro.getReloj().getMinutos()) {
                    return false;
                } else {
                    if (reloj.getSegundos() < otro.getReloj().getSegundos()) {
                        return true;
                    } else if (reloj.getSegundos() > otro.getReloj().getSegundos()) {
                        return false;
                    }
                }
            }
        }
    }
    if (mensaje < otro.getMensaje()) {
        return true;
    } else if (mensaje > otro.getMensaje()) {
        return false;
    } else {
        return false; 
    }
}

//Swap: complejidad O(1) ya que intercambia los dos nodos en tiempo constan
void swap(Node *a, Node *b) {
    Registro temp = a -> data;
    a -> data = b -> data;
    b -> data = temp;
}

//getTail: complejidad O(n) pues recorre todos los nodos de cur hasta el final
Node* getTail(Node* cur){
    while(cur!= NULL && cur->next !=NULL)
        cur=cur->next;
    return cur;
}

//Particion: complejidad O(n) ya que recorre todos los nodos desde low hasta high 
Node* particion(Node* low, Node* high) {
    Registro pivot= high->data;
    Node *i= low->prev;

        
    for(Node* j=low; j != high; j = j->next){
        if(j-> data.comparacion(pivot)){
            i = (i == nullptr) ? low : i -> next;
            swap(i, j);
        }
    }
    i=(i==nullptr) ? low: i->next;
    swap(i, high);

    return i;
} 
//quickSort: Complejidad O(nlogn) ya que divide la lista en dos partes aproximadamente iguales en cada particion
void quickSort(Node *low, Node *high) {
    if (low != nullptr && high != nullptr && low != high && low != high -> next) {
        Node * pivot = particion(low, high);
        quickSort(low, pivot ->prev);
        quickSort(pivot -> next, high);
        }     
} 

/*LeerArchivo: Complejidad O(nlogn) dado que el archivo se recorre linea por linea, donde n es el
numero de lineas, para el ordenamiento se ocupa un insertionsort que en el peor de los casos tiene una
complejidad n^2, por lo que 
*/
Node* leerArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        return nullptr; // O maneja el error de otra manera
    }
    
    string mes, mensaje;
    int dia, hora, minuto, segundo;
    int ip1, ip2, ip3, ip4, ip5;
    char delim;
    
    Node* lista = NULL;
    Node *tail = nullptr;

    while (archivo >> mes >> dia >> hora >> delim >> minuto >> delim >> segundo >> ip1 >> delim >> ip2 >> delim >> ip3 >> delim >> ip4 >> delim >> ip5) {
        getline(archivo, mensaje);

        Fecha fecha(mes, dia);
        Reloj reloj(hora, minuto, segundo);
        IP ip(ip1, ip2, ip3, ip4, ip5);
        Registro registro(fecha, reloj, ip, mensaje);
        agregarNodo(&lista, &tail, registro);
        
    }
    if (lista!=NULL) {
        tail=getTail(lista);
        quickSort(lista, tail);
    }


    archivo.close();
    return lista;

}

//solicitar IP: Complejidad O(1) el procesamiento de la cadena de IP siempre es constante (ya que siempre es 4 numeros)
IP solicitarIP(string &Ipinpt) {
    char limitante = '.';
    int arr[4] = {0};
    int pos_ini = 0;
    int pos_fin = 0;
    
    for (int i = 0; i < 3; i++) {
        pos_fin = Ipinpt.find(limitante, pos_ini);
        string splitted = Ipinpt.substr(pos_ini, pos_fin - pos_ini);
        arr[i] = stoi(splitted);
        pos_ini = pos_fin + 1;

    }
    arr[3] = stoi(Ipinpt.substr(pos_ini));
    IP Ip_soli = IP(arr[0],arr[1],arr[2],arr[3], 0);
    return Ip_soli;

};

//busquedaSecPrm: Complejidad O(n) ya que recorre toda la lista
Node* busquedaSecPrm(Node* head, IP &Ip_buscada){
    Node* current = head;
    while (current){
        if (current -> data.getIP() == Ip_buscada) {
            return current;
        }

        if (current -> data.getIP().getNum1() > Ip_buscada.getNum1() || 
        (current -> data.getIP().getNum1() == Ip_buscada.getNum1() && current -> data.getIP().getNum2() > Ip_buscada.getNum2()) ||
        (current -> data.getIP().getNum1() == Ip_buscada.getNum1() && current -> data.getIP().getNum2() == Ip_buscada.getNum2() && current -> data.getIP().getNum3() > Ip_buscada.getNum3()) ||
        (current -> data.getIP().getNum1() == Ip_buscada.getNum1() && current -> data.getIP().getNum2() == Ip_buscada.getNum2() && current -> data.getIP().getNum3() == Ip_buscada.getNum3() && current -> data.getIP().getNum4() > Ip_buscada.getNum4())){
            return current;
        } 
        current = current->next;
    }
    return NULL;
};

//busquedaSecUltm: Complejidad O(n) ya que recorre toda la lista
Node* busquedaSecUltm(Node* tail, IP &Ip_buscada) {
    Node* current = tail;
    while (current){
        if (current->data.getIP() == Ip_buscada) {
            return current; 
        }
        if (current -> data.getIP().getNum1() < Ip_buscada.getNum1() || 
        (current -> data.getIP().getNum1() == Ip_buscada.getNum1() && current -> data.getIP().getNum2() < Ip_buscada.getNum2()) ||
        (current -> data.getIP().getNum1() == Ip_buscada.getNum1() && current -> data.getIP().getNum2() == Ip_buscada.getNum2() && current -> data.getIP().getNum3() < Ip_buscada.getNum3()) ||
        (current -> data.getIP().getNum1() == Ip_buscada.getNum1() && current -> data.getIP().getNum2() == Ip_buscada.getNum2() && current -> data.getIP().getNum3() == Ip_buscada.getNum3() && current -> data.getIP().getNum4() < Ip_buscada.getNum4())){
            return current;
        } 
        current = current->prev;
    }
    return NULL;
};

//imprimeIPs: complejidad O(n) donde n es el numero de nodos entre la IP inicial y final 
void imprimeIPs(Node* head, Node *tail, IP ip_inicial, IP ip_final) {
    Node *ultimo_elemento = busquedaSecUltm(tail, ip_final); 
    Node *primer_elemento = busquedaSecPrm(head, ip_inicial);

    if (primer_elemento == nullptr) {
        cout << "No encuentra ip_inicial";
        return;
    } else if (primer_elemento == nullptr) {
        cout << "No encuentra ip_inicial";
        return;
    }
    //ultimo_elemento ->data.imprimir();
    //primer_elemento ->data.imprimir();
    
    Node* elm_antr = primer_elemento ->prev;
    Node* temporal = ultimo_elemento;
    while (temporal != elm_antr) {
        temporal -> data.imprimir();
        temporal = temporal -> prev;
        if (temporal == nullptr) {
        break;
        }
    }
};

//guardarArchivo: Complejidad O(n),ya que guarda todos los nodos en la lista
void guardarArchivo(Node* registros, const string &nombreArchivo) {
    ofstream archivo(nombreArchivo);

    Node* current = registros;

    while (current) {
        const Registro &registro = current ->data;
        const Fecha &fecha = registro.getFecha();
        const Reloj &reloj = registro.getReloj();
        const IP &ip = registro.getIP();
        const string &mensaje = registro.getMensaje();
        
        archivo << fecha.getMes() << " "<< setw(2) << setfill('0') << fecha.getDia() << " " << setw(2) <<setfill('0') << reloj.getHora() << ":"
        << setw(2) << setfill('0') << reloj.getMinutos() << ":"<< setw(2) << setfill('0') << reloj.getSegundos() << " "
        << ip.getNum1() << "." << ip.getNum2() << "." << ip.getNum3() << "." << ip.getNum4() << ":" << ip.getNum5() << " " << mensaje << endl;
        current = current -> next;
    }

    archivo.close(); 
}


int main(){
    Node* bitacora = leerArchivo("bitacora.txt");

    string ip_ini, ip_fin;
    cin >> ip_ini;
    cin >> ip_fin;
    
    IP ip_inicial = solicitarIP(ip_ini);
    IP ip_final = solicitarIP(ip_fin);

    Node* tail = getTail(bitacora);

    imprimeIPs(bitacora, tail, ip_inicial, ip_final);
    guardarArchivo(bitacora, "SortedData.txt");

    return 0;
}