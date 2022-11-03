//
// Created by Giancarlos on 2/11/22.
//

#ifndef PROYECTOGIMP_PIZARRA_H
#define PROYECTOGIMP_PIZARRA_H
#include <vector>
#include "CFiguraGeometrica.h"

class Pizarra {
    vector<CFiguraGeometrica*> figuras;
public:
    Pizarra(){}
    void agregar_figura(CFiguraGeometrica* f){
        figuras.push_back(f);
    }
    void eliminar(int numero){
        for(auto i: figuras){

        }
    }
};


#endif //PROYECTOGIMP_PIZARRA_H
