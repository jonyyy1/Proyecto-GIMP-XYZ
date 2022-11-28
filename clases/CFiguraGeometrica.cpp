//
// Created by Jonathan on 2/11/22.
//

#include "CFiguraGeometrica.h"
CFiguraGeometrica::CFiguraGeometrica() {}


CFiguraGeometrica::CFiguraGeometrica(string _nombre_figura, vector<Coordenada *> c) {
    nombre_figura=_nombre_figura;
    for(auto co : c){
        coordenadas.push_back(co);
    }
}

string CFiguraGeometrica::get_nombre_figura() {return nombre_figura;}

int CFiguraGeometrica::get_id() {return id;}

vector<Coordenada *> CFiguraGeometrica::get_coordenadas() {return coordenadas;}

void CFiguraGeometrica::set_id(int _id) {
    id = _id;
}