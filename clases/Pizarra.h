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
    void agregar_figura(CFiguraGeometrica* f);
    void eliminar_figura(int id);
    vector<CFiguraGeometrica*>get_figuras();
    void set_figura(CFiguraGeometrica* figura);
    void girar(){

    }
    int auto_increment();
    void redimensionar();
    void mostrar();

/**/
    vector<CLinea *> convertir_a_lineas(vector<CFiguraGeometrica *> figuras_a_convertir);
    void pintar_pizarra(vector<CFiguraGeometrica *> figuras_a_pintar);
};


#endif //PROYECTOGIMP_PIZARRA_H
