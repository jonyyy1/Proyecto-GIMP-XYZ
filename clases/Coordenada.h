//
// Created by Giancarlos on 2/11/22.
//

#ifndef PROYECTOGIMP_COORDENADA_H
#define PROYECTOGIMP_COORDENADA_H
#define PROYECTOGIMP_COORDENADA_H


class Coordenada {
private :
    int x,y;
public:
    Coordenada(int _x, int _y);
    void set_x(int _x);
    void set_y(int _y);
    int get_x();
    int get_y();
};


#endif //PROYECTOGIMP_COORDENADA_H
