//
// Created by Giancarlos on 2/11/22.
//

#ifndef PROYECTOGIMP_PIZARRA_H
#define PROYECTOGIMP_PIZARRA_H
#include <vector>
#include "CFiguraGeometrica.h"
#include "../pantalla/Matriz.h"
#include "CLinea.h"

class Pizarra {

public:
    //
// Created by Giancarlos on 2/11/22.
//


    Pizarra();
    void agregar(CFiguraGeometrica* f);
    void eliminar(int id);
    vector<CFiguraGeometrica*>get_figuras();
    void set_figura(CFiguraGeometrica* figura);
    void girar(){

    }
    int auto_increment();
    void redimensionar();
    void mostrar();
    void pintar_pizarra(vector<Coordenada *> c,int _numero);



/**/
};


#endif //PROYECTOGIMP_PIZARRA_H
