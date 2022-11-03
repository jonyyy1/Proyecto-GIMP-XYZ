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
    int id;
    string nombre_figura;
    vector<Coordenada*> coordenadas;
    vector<CFiguraGeometrica*> figuras;
public:
    CFiguraGeometrica(int _id, string _nombre_figura,const vector<Coordenada*> c){
        id = _id;
        nombre_figura=_nombre_figura;
        for(auto co : c){
            coordenadas.push_back(co);
        }
    };

    virtual string get_nombre_figura(){return nombre_figura;};
    virtual int get_id(){return id;};
    vector<Coordenada*> get_coordenadas(){
        return coordenadas;
    }
    virtual ~CFiguraGeometrica(){}
};


#endif //PROYECTOGIMP_CFIGURAGEOMETRICA_H
