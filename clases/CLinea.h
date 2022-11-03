//
// Created by Jonathan on 2/11/22.
//

#ifndef PROYECTOGIMP_CLINEA_H
#define PROYECTOGIMP_CLINEA_H
#include "CFiguraGeometrica.h"

class CLinea : public CFiguraGeometrica{
public :
    CLinea(int id, const vector<Coordenada *> c) : CFiguraGeometrica(id,"Linea", c) {};
};


#endif //PROYECTOGIMP_CLINEA_H
