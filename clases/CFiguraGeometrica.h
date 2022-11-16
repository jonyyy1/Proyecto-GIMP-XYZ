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

public:
    CFiguraGeometrica();

    CFiguraGeometrica(string _nombre_figura, vector<Coordenada*> c);

    virtual string get_nombre_figura();
    virtual int get_id();
    void set_id(int _id);
    vector<Coordenada*> get_coordenadas();

};


#endif //PROYECTOGIMP_CFIGURAGEOMETRICA_H
