//
// Created by Gonzalo on 28/11/2022.
//

#ifndef MAIN_CPP_FUNCIONES_H
#define MAIN_CPP_FUNCIONES_H

#endif //MAIN_CPP_FUNCIONES_H


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
    if(pizarra->get_figuras().empty()){
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
    condition = numero == 3 ? 1 : condition;
    for(int i=0;i<condition;i++){
        cout << "ingrese el x: "<< endl;
        cin>> x;
        cout << "ingrese el y: "<< endl;
        cin>> y;
        if (x < 0 || y < 0){
            cout << "No se permiten valores negativos" << endl;
            i--;
        }else if (x > 20 || y > 20){
            cout << "No se permiten valores mayores a 20" << endl;
            i--;
        }else {
            c.push_back(new Coordenada(x, y));
        }
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
        int r;
        cout << "Ingrese el radio: "<< endl;
        cin >> r;
        if (r < 0){
            cout << "No se permiten valores negativos" << endl;}
        else if (r > 10){
            cout << "No se permiten valores mayores a 10" << endl;}
        else if(c[0]->get_x() + r > 19 || c[0]->get_y() + r > 19 || c[0]->get_x() - r < 1 || c[0]->get_y() - r < 1){
            cout << "El circulo ingresado no cabe en el lienzo." << endl;}
        else{
            pizarra->set_figura(new Circulo(c, r));
        }
    } else {
        //PARA EL TRIANGULO
        pizarra->set_figura(new Triangulo(c));
    }
    // imprimir_tabla();
}

int eliminar_figura(){
    int id;
    imprimir_tabla();
    cout << "Que figura desea eliminar?" << endl;
    cin >> id;
    pizarra->eliminar_figura(id);
    return id;
}

void redimensionar_figura() {
    int id;
    int mult;
    imprimir_tabla();
    if (pizarra->get_figuras().empty()) {
        cout << "No hay figuras para redimensionar" << endl;
        return;
    }

    cout << "Que figura desea redimensionar?" << endl;
    cin >> id;
    if (pizarra->get_figuras()[id-1] == nullptr) {
        cout << "No existe la figura" << endl;
        return;
    }
    if (pizarra->get_figuras()[id-1]->get_nombre_figura() != "Circulo" || pizarra->get_figuras()[id-1]->get_nombre_figura() != "Rectangulo") {
        cout << "Solo se pueden redimensionar figuras con doble simetria (circulos y rectangulos)." << endl;
        return;
    }
    cout << "Ingrese el multiplicador de tamaño: " << endl;
    cin >> mult;
    if (pizarra->get_figuras()[id - 1]->get_nombre_figura() == "Circulo") {
        int radio_actual = pizarra->get_figuras()[id - 1]->get_coordenadas()[0]->get_y() -
                           pizarra->get_figuras()[id - 1]->coordenadas_centro[0]->get_y();
        int radio_nuevo = radio_actual * mult;
        bool valido = true;
        if (pizarra->get_figuras()[id - 1]->coordenadas_centro[0]->get_x() - radio_nuevo < 0 ||
            pizarra->get_figuras()[id - 1]->coordenadas_centro[0]->get_x() + radio_nuevo > 20 ||
            pizarra->get_figuras()[id - 1]->coordenadas_centro[0]->get_y() - radio_nuevo < 0 ||
            pizarra->get_figuras()[id - 1]->coordenadas_centro[0]->get_y() + radio_nuevo > 20) {
            cout << "No se puede redimensionar la figura, se sale del area de trabajo." << endl;
            valido = false;
        }
        if (valido) {
            pizarra->set_figura(new Circulo(pizarra->get_figuras()[id - 1]->coordenadas_centro, radio_nuevo));
            pizarra->eliminar_figura(id);
        }
    } else if (pizarra->get_figuras()[id - 1]->get_nombre_figura() == "Rectangulo") {
        vector<Coordenada *> coordenadas_nuevas;
        int tamanoX = abs(pizarra->get_figuras()[id - 1]->get_coordenadas()[2]->get_x() -
                          pizarra->get_figuras()[id - 1]->get_coordenadas()[0]->get_x());
        cout << "tamanoX: " << tamanoX << endl;
        int tamanoY = abs(pizarra->get_figuras()[id - 1]->get_coordenadas()[2]->get_y() -
                          pizarra->get_figuras()[id - 1]->get_coordenadas()[0]->get_y());
        cout << "tamanoY: " << tamanoY << endl;
        coordenadas_nuevas.push_back(
                new Coordenada(pizarra->get_figuras()[id - 1]->get_coordenadas()[0]->get_x() - tamanoX * mult / 4,
                               pizarra->get_figuras()[id - 1]->get_coordenadas()[0]->get_y() - tamanoY * mult / 4));
        coordenadas_nuevas.push_back(
                new Coordenada(pizarra->get_figuras()[id - 1]->get_coordenadas()[2]->get_x() + tamanoX * mult / 4,
                               pizarra->get_figuras()[id - 1]->get_coordenadas()[2]->get_y() + tamanoY * mult / 4));
        bool valido = true;
        for (auto coordenada: coordenadas_nuevas) {
            if (coordenada->get_x() < 1 || coordenada->get_y() < 1 || coordenada->get_x() > 20 ||
                coordenada->get_y() > 20) {
                cout << "No se puede redimensionar la figura, se sale del area de trabajo." << endl;
                valido = false;
            }
        }
        if (valido) {
            pizarra->set_figura(new CRectangulo(coordenadas_nuevas));
            pizarra->eliminar_figura(id);
        }

    }
}
