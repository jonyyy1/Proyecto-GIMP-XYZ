//
// Created by Giancarlos on 15/11/22.
//

#ifndef PROYECTOGIMP_CIRCULO_H
#define PROYECTOGIMP_CIRCULO_H
#include "CFiguraGeometrica.h"

class Circulo:public CFiguraGeometrica {
public:
    Circulo(vector<Coordenada*> c, int radio);
    Coordenada * coordenada_central;
};


#endif //PROYECTOGIMP_CIRCULO_H
