//
// Created by Giancarlos on 2/11/22.
//

#include "Coordenada.h"

Coordenada::Coordenada(int _x, int _y):x(_x),y(_y){}

int Coordenada::get_x() {return x;}

int Coordenada::get_y() {return y;}

void Coordenada::set_x(int _x) {x = _x;}

void Coordenada::set_y(int _y) {y = _y;}