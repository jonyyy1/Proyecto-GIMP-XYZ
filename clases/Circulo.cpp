//
// Created by Giancarlos on 15/11/22.
//

#include "Circulo.h"
#include <cmath>

Circulo::Circulo(vector<Coordenada*> c, int radioInit):CFiguraGeometrica("Circulo",c){
    int radio = radioInit;
    Coordenada * coordenada_central = c[0];
    coordenadas_centro.push_back(coordenada_central);
    this->coordenadas.clear();
    //superior_izquierda =
    coordenadas.push_back(new Coordenada((coordenada_central->get_x()-floor(radio/2)), (coordenada_central->get_y())+radio));
    //superior_derecha =
    coordenadas.push_back(new Coordenada((coordenada_central->get_x()+floor(radio/2)), (coordenada_central->get_y())+radio));
    // pared superior derecha =
    coordenadas.push_back(new Coordenada((coordenada_central->get_x()+radio), (coordenada_central->get_y())+floor(radio/2)));
    // pared inferior derecha =
    coordenadas.push_back(new Coordenada((coordenada_central->get_x()+radio), (coordenada_central->get_y())-floor(radio/2)));
    // inferior derecha =
    coordenadas.push_back(new Coordenada((coordenada_central->get_x()+floor(radio/2)), (coordenada_central->get_y())-radio));
    // inferior izquierda =
    coordenadas.push_back(new Coordenada((coordenada_central->get_x()-floor(radio/2)), (coordenada_central->get_y())-radio));
    // pared inferior izquierda =
    coordenadas.push_back(new Coordenada((coordenada_central->get_x()-radio), (coordenada_central->get_y())-floor(radio/2)));
    // pared superior izquierda =
    coordenadas.push_back(new Coordenada((coordenada_central->get_x()-radio), (coordenada_central->get_y())+floor(radio/2)));

}