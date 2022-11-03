//
// Created by Jonathan on 2/11/22.
//

#ifndef PROYECTOGIMP_CFIGURAGEOMETRICA_H
#define PROYECTOGIMP_CFIGURAGEOMETRICA_H
#include <iostream>
#include <string>
#include <vector>
#include "Coordenada.h"
using namespace std;

class CFiguraGeometrica {
protected:
    string nombre_figura;
    vector<Coordenada*> coordenadas;
public:
    CFiguraGeometrica(string _nombre_figura,const vector<Coordenada*> c){
        nombre_figura=_nombre_figura;
        for(auto co : c){
            coordenadas.push_back(co);
        }

    };

    virtual string get_nombre_figura(){return "";};
    vector<Coordenada*> get_coordenadas(){
        return coordenadas;
    }
    virtual ~CFiguraGeometrica(){}
};


#endif //PROYECTOGIMP_CFIGURAGEOMETRICA_H
