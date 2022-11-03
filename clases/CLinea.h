//
// Created by Jonathan on 2/11/22.
//

#ifndef PROYECTOGIMP_CLINEA_H
#define PROYECTOGIMP_CLINEA_H
#include "CFiguraGeometrica.h"

class CLinea : public CFiguraGeometrica{
public :
    CLinea(string nombreFigura, const vector<Coordenada *> c) : CFiguraGeometrica(nombreFigura, c) {};
    string get_nombre_figura(){return nombre_figura;};
};


#endif //PROYECTOGIMP_CLINEA_H
