#include <iostream>
#include "clases/CFiguraGeometrica.h"
#include "clases/CLinea.h"
#include "clases/Coordenada.h"
#include <vector>
#include "clases/Pizarra.h"
using namespace std;
int id = 0;
vector<CFiguraGeometrica*> figuras;
template<typename T>
void imprimir(T d){
    cout << "id : "<<d->get_id()<<endl;
    cout <<"Figura : "<<d->get_nombre_figura()<<endl;
    for(auto i : d->get_coordenadas()){cout <<"("<<i->get_x()<<","<<i->get_y()<<")"<<endl;}
}


int autoincrement_id(){
    return id+=1;
}
vector<Coordenada*> obtener_coordenadas(int numero){
    vector<Coordenada*> c;
    int x=0;
    int y=0;
    int condition=0;
    condition = numero == 4 ? 3 : 2;
    for(int i=0;i<condition;i++){
        cout << "ingrese el x: "<< endl;
        cin>> x;
        cout << "ingrese el y: "<< endl;
        cin>> y;
        c.push_back(new Coordenada(x,y));
    }
    return c;
}
int pedir_numero(){
    int numero=0;
    cout << "Ingrese una Figura"<< endl;
    cout << "1.-Linea"<< endl;
    cout << "2.-Rectangulo"<< endl;
    cout << "3.-Ciruclo"<< endl;
    cout <<"4.-Triangulo"<< endl;
    cin >> numero;
    return numero;
}
void simulation_GIMP(){
    int numero = pedir_numero();
    vector<Coordenada*> c = obtener_coordenadas(numero);
    CFiguraGeometrica* f;
    if(numero == 1){
        cout <<"se creo una linea"<<endl;
        f = new CLinea(autoincrement_id(),c);
    }else if(numero == 2){
        //PARA EL RECTANGULO
    }else if(numero == 3){
        //PARA EL CIRCULO
    }else{
        //PARA EL TRIANGULO
    }
    //AGREGAR A LA PIZARRA
    figuras.push_back(f);
    //REPORTE
    imprimir(f);

}
int main() {
    int numero_a_elegir = 0;
    int continuar = 0;
    cout <<"BIENVENIDO A GIMP"<<endl;
    cout <<"MENU"<< endl;
    Pizarra* pizarra;
    while(true) {
        cout <<"1.-AGREGAR"<< endl;
        cout <<"2.-ELIMINAR"<< endl;
        cout <<"3.-GIRAR"<< endl;
        cout <<"4.-REDIMENSIONAR"<<endl;
        cout << "5.-MOSTRAR"<<endl;
        cout <<"6.-SALIR"<<endl;
        cin >> numero_a_elegir;
        if (numero_a_elegir==1){
            pizarra->mostrar();
        }else if(numero_a_elegir==2){
            //eliminar();
        }else if(numero_a_elegir==3){
            //girar();
        }else if(numero_a_elegir==4){
            //redimensionar();
        }else if(numero_a_elegir==5){
            //mostrar();
        }else if(numero_a_elegir==6){
            break;
        }else{
            cout <<"opcion incorrecta, vuelva a elegir otro numero"<< endl;
        }
    }
    return 0;
}
