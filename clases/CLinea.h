//
// Created by Jonathan on 2/11/22.
//

#ifndef PROYECTOGIMP_CLINEA_H
#define PROYECTOGIMP_CLINEA_H
#include "CFiguraGeometrica.h"

class CLinea : public CFiguraGeometrica{
public :
    CLinea();
    CLinea(vector<Coordenada *> c);
};


#endif //PROYECTOGIMP_CLINEA_H
