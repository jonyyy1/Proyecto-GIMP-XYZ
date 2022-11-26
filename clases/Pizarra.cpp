//
// Created by Giancarlos on 2/11/22.
//
#include <cmath>
#include "Pizarra.h"
string matriz[12][12] = {{"   ","  1","  2","  3","  4","  5","  6","  7","  8","  9","  10","   "},
                         {"  1","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","  1"},
                         {"  2","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","  2"},
                         {"  3","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","  3"},
                         {"  4","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","  4"},
                         {"  5","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","  5"},
                         {"  6","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","  6"},
                         {"  7","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","  7"},
                         {"  8","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","  8"},
                         {"  9","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","  9"},
                         {" 10","   ","   ","   ","   ","   ","   ","   ","   ","   ","   "," 10"},
                         {"   ","  1","  2","  3","  4","  5","  6","  7","  8","  9","  10","   "}};
    Pizarra::Pizarra() {}
vector<CFiguraGeometrica*> figuras;
vector<CFiguraGeometrica*> Pizarra::get_figuras() {return figuras;}
int ga = 0;
int Pizarra::auto_increment() {
    ga = ga + 1;
    return ga;
}
void Pizarra::set_figura(CFiguraGeometrica*figura) {
    figura->set_id(auto_increment());
    figuras.push_back(figura);
}

void Pizarra::eliminar_figura(int id) {
    figuras.erase(figuras.begin() + id-1);
}
void Pizarra::mostrar() {
    for(int i=0; i<12; i++){
        for(int j=0; j<12; j++){
            cout << matriz[i][j]<<" ";
        }
        cout << endl;
    }
}
void pintar_linea(vector<Coordenada*> _c) {
    int y1 = _c[0]->get_y();
    int y2 = _c[_c.size() - 1]->get_y();
    int x1 = _c[0]->get_x();
    int x2 = _c[_c.size() - 1]->get_x();

    int iteraciones = abs(x2 - x1) > abs(y2 - y1) ? abs(x2 - x1) : abs(y2 - y1);
    char basado_en = abs(x2 - x1) > abs(y2 - y1) ? 'x' : 'y';

    int paso_x = x2 > x1 ? 1 : -1;
    int paso_y = y2 > y1 ? 1 : -1;

    int pasos_para_cambiar, pasos_actuales;
    if (basado_en == 'x') {
        pasos_para_cambiar = ceil(iteraciones / (abs(y2 - y1) + 1));
    } else {
        pasos_para_cambiar = ceil(iteraciones / (abs(x2 - x1) + 1));
    }
    pasos_actuales = pasos_para_cambiar;

    for (int i = 0; i <= iteraciones; i++) {
        matriz[y1][x1] = "  *";
        if (basado_en == 'x') {
            x1 += paso_x;
            if (pasos_actuales < 1 && y1 != y2) {
                y1 += paso_y;
                pasos_actuales = pasos_para_cambiar+1;
            }
        } else {
            y1 += paso_y;
            if (pasos_actuales < 1 && x1 != x2) {
                x1 += paso_x;
                pasos_actuales = pasos_para_cambiar+1;
            }
        }
        pasos_actuales -= 1;
    }
}

    void Pizarra::pintar_pizarra(vector<Coordenada *> _c, int _tipo_de_figura) {
        if (_tipo_de_figura == 1) {
            pintar_linea(_c);
        } else if (_tipo_de_figura == 2) {


        } else if (_tipo_de_figura == 3) {
            //circulo

        } else if (_tipo_de_figura == 4) {
            //triangulo
            vector<Coordenada *> linea1;
            linea1.push_back(_c[0]);
            linea1.push_back(_c[1]);
            pintar_linea(linea1);
            vector<Coordenada *> linea2;
            linea2.push_back(_c[0]);
            linea2.push_back(_c[2]);
            pintar_linea(linea2);
            vector<Coordenada *> linea3;
            linea3.push_back(_c[1]);
            linea3.push_back(_c[2]);
            pintar_linea(linea3);
        }
    }
