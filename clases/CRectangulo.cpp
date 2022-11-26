//
// Created by Giancarlos on 15/11/22.
//

#include "CRectangulo.h"
CRectangulo::CRectangulo(vector<Coordenada *> _c): CFiguraGeometrica("Rectangulo",_c){
    // Agregar coordenadas faltantes
    int x1 = _c[0]->get_x();
    int y1 = _c[0]->get_y();
    int x2 = _c[1]->get_x();
    int y2 = _c[1]->get_y();
    coordenadas.emplace(coordenadas.begin()+1, new Coordenada(x1, y2));
    coordenadas.push_back(new Coordenada(x2,y1));
}