#include <iostream>
#include "clases/CFiguraGeometrica.h"
#include "clases/CLinea.h"
#include "clases/Coordenada.h"
#include "clases/CRectangulo.h"
#include "clases/Circulo.h"
#include "clases/Triangulo.h"
#include <vector>
#include "clases/Pizarra.h"
#include "helpers/TextTable.h"
#include <cmath>
using namespace std;

Pizarra* pizarra;

void imprimir_tabla(){
    TextTable t( '-', '|', '+' );
    t.add( "Nro" );
    t.add( "Tpo de figura" );
    t.add( "Datos" );
    t.endOfRow();
    cout <<"tamaño"<< pizarra->get_figuras().size()<< endl;
    if(pizarra->get_figuras().size()==0){
        t.add("No hay figuras");
        t.endOfRow();
    }else{
        for(auto d: pizarra->get_figuras()){
            t.add(to_string(d->get_id()));
            t.add(d->get_nombre_figura());
            for(auto i : d->get_coordenadas()){
                t.add("("+to_string(i->get_x())+","+to_string(i->get_y())+")");
            }
            t.endOfRow();
        }
    }
    t.setAlignment( 2, TextTable::Alignment::RIGHT );
    std::cout << t;
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

void agregar_figura() {
    int numero = pedir_numero();
    vector<Coordenada *> c = obtener_coordenadas(numero);
    if (numero == 1) {
        //LINEA
        pizarra->set_figura(new CLinea(c));
    } else if (numero == 2) {
        //PARA EL RECTANGULO
        pizarra->set_figura(new CRectangulo(c));
    } else if (numero == 3) {
        //PARA EL CIRCULO
        pizarra->set_figura(new Circulo(c));
    } else {
        //PARA EL TRIANGULO
        pizarra->set_figura(new Triangulo(c));
    }
    imprimir_tabla();
    pizarra->pintar_pizarra(c,numero);
}
int eliminar_figura(){
    int id;
    imprimir_tabla();
    cout << "Que figura desea eliminar?" << endl;
    cin >> id;
    pizarra->eliminar_figura(id);
    return id;
}

int main() {
    int numero_a_elegir = 0;
    cout <<"BIENVENIDO A GIMP"<<endl;
    cout <<"MENU"<< endl;
    while(true) {
        cout <<"1.-AGREGAR"<< endl;
        cout <<"2.-ELIMINAR"<< endl;
        cout <<"3.-GIRAR"<< endl;
        cout <<"4.-REDIMENSIONAR"<<endl;
        cout << "5.-MOSTRAR TABLA"<<endl;
        cout << "6.-MOSTRAR MATRIZ"<<endl;
        cout <<"7.-SALIR"<<endl;
        cin >> numero_a_elegir;
        if (numero_a_elegir==1){
            agregar_figura();
        }else if(numero_a_elegir==2){
            eliminar_figura();
        }else if(numero_a_elegir==3){
            //girar();
        }else if(numero_a_elegir==4){
            //redimensionar();
        }else if(numero_a_elegir==5){
            imprimir_tabla();
        }else if(numero_a_elegir==6) {
            pizarra->mostrar();
        }
        else if(numero_a_elegir==7){
            break;
        }else{
            cout <<"opcion incorrecta, vuelva a elegir otro numero"<< endl;
        }
    }
    return 0;
}
