#include <iostream>
#include "clases/CFiguraGeometrica.h"
#include "clases/CLinea.h"
#include "clases/Coordenada.h"
#include <vector>

using namespace std;
int id = 0;
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
    //REPORTE
    imprimir(f);

}
int main() {
    simulation_GIMP();
    simulation_GIMP();
    return 0;
}
