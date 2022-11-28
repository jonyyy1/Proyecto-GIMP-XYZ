//
// Created by Giancarlos on 2/11/22.
//
#include <cmath>
#include "Pizarra.h"
string matriz[22][22] = {{"   ","  1","  2","  3","  4","  5","  6","  7","  8","  9"," 10"," 11"," 12"," 13"," 14"," 15"," 16"," 17"," 18"," 19"," 20","   "},
                         {"  1","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","    ","  1"},
                         {"  2","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","    ","  2"},
                         {"  3","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","    ","  3"},
                         {"  4","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","    ","  4"},
                         {"  5","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","    ","  5"},
                         {"  6","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","    ","  6"},
                         {"  7","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","    ","  7"},
                         {"  8","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","    ","  8"},
                         {"  9","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","    ","  9"},
                         {" 10","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","    "," 10"},
                         {" 11","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","    "," 11"},
                         {" 12","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","    "," 12"},
                         {" 13","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","    "," 13"},
                         {" 14","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","    "," 14"},
                         {" 15","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","    "," 15"},
                         {" 16","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","    "," 16"},
                         {" 17","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","    "," 17"},
                         {" 18","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","    "," 18"},
                         {" 19","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","    "," 19"},
                         {" 20","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","    "," 20"},
                         {"   ","  1","  2","  3","  4","  5","  6","  7","  8","  9"," 10"," 11"," 12"," 13"," 14"," 15"," 16"," 17"," 18"," 19"," 20","   "}};


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
    pintar_pizarra(this->get_figuras());
    for(int i=0; i<22; i++){
        for(int j=0; j<22; j++){
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
        string caracter_de_impresion;
        caracter_de_impresion = x1 >= 10 ? "  *" : "  *";
        matriz[y1][x1] = caracter_de_impresion;
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

vector<CLinea *> Pizarra::convertir_a_lineas(vector<CFiguraGeometrica *> figuras_a_convertir){
    vector<CLinea *> lineas;
    vector<Coordenada*> coords_actuales;
    for (auto figura_actual : figuras_a_convertir) {
        // Inicializando el dibujo con la línea que conecta el ultimo y el primer punto
        coords_actuales.push_back(figura_actual->get_coordenadas()[0]);
        coords_actuales.push_back(figura_actual->get_coordenadas()[figura_actual->get_coordenadas().size()-1]);
        lineas.push_back(new CLinea(coords_actuales));
        coords_actuales.clear();

        // Dibujando las lineas que conectan los puntos intermedios
        coords_actuales.push_back(figura_actual->get_coordenadas()[0]);
        for (int i = 1; i < figura_actual->get_coordenadas().size(); i++) {
            coords_actuales.push_back(figura_actual->get_coordenadas()[i]);
            lineas.push_back(new CLinea(coords_actuales));
            coords_actuales.clear();
            coords_actuales.push_back(figura_actual->get_coordenadas()[i]);
        }
    }

    // Eliminar este for loop en la versión final, es para debug la visualizacion se lineas modulares
    return lineas;
}



void Pizarra::pintar_pizarra(vector<CFiguraGeometrica *> figuras_a_pintar) {
    for (int i = 1; i < 21; i++) {
        for (int j = 1; j < 21; j++) {
            matriz[i][j] = "   ";
        }
    }
    cout << "Pintando pizarra" << endl;
    cout << "Figuras a pintar: " << figuras_a_pintar.size() << endl;
    for(auto i: figuras_a_pintar){
        if(i->get_coordenadas().size() > 2) {
            for (auto x: convertir_a_lineas(figuras_a_pintar)) {
                pintar_linea(x->get_coordenadas());
            }
        }
        else {
            pintar_linea(i->get_coordenadas());
        }
    }
}