//
// Created by Giancarlos on 2/11/22.
//

#ifndef PROYECTOGIMP_COORDENADA_H
#define PROYECTOGIMP_COORDENADA_H


class Coordenada {
private :
    int x,y;
public:
    Coordenada(int _x, int _y):x(_x),y(_y){}

    int get_x(){
        return x;
    }
    int get_y(){
        return y;
    }
};


#endif //PROYECTOGIMP_COORDENADA_H
