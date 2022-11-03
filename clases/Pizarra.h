//
// Created by Giancarlos on 2/11/22.
//

#ifndef PROYECTOGIMP_PIZARRA_H
#define PROYECTOGIMP_PIZARRA_H
#include <vector>
#include "CFiguraGeometrica.h"
#include "../constantes/Matriz.h"


class Pizarra {
    vector<CFiguraGeometrica*> figuras;
public:
    Pizarra(){}
    void agregar(CFiguraGeometrica* f){
        figuras.push_back(f);
    }
    void eliminar(int id){
        for(auto i: figuras){
            if(i->get_id()==id){
                figuras.erase(figuras.begin() + id);
                cout <<"se elimino el id : "<< id<<endl;
            }
        }
    }
    void girar(){

    }
    void redimensionar(){

    }
    void mostrar(){
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                cout << matriz[i][j]<<" ";
            }
            cout << endl;
        }
    }
/**/
};


#endif //PROYECTOGIMP_PIZARRA_H
