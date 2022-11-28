//
// Created by Giancarlos on 2/11/22.
//

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
    cout <<"entro"<< endl;
    figura->set_id(auto_increment());
    figuras.push_back(figura);
    cout <<"salio"<<endl;
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
void pintar_linea(vector<Coordenada*> _c){
    int y_inicial = _c[0]->get_y();
    int y_final = _c[_c.size()-1]->get_y();
    int x_inicial = _c[0]->get_x();
    int x_final = _c[_c.size()-1]->get_x();

    int x1 = x_inicial;
    int y1 = y_inicial;
    int iteraciones = 0;
    bool is_h_or_v = false;
    if(x_inicial == x_final){
        iteraciones = (y_final-y_inicial+1);
        is_h_or_v = true;
    }else if(y_inicial == y_final){
        iteraciones = (x_final-x_inicial+1);
        is_h_or_v = true;
    }else{
        //si es simetrico
        if(x_inicial == y_final && y_final == x_final){
            iteraciones = x_inicial > x_final ? x_inicial : x_final;
        }else{
            int a = abs(x_inicial-x_final)+1;
            int b = abs(y_inicial-y_final)+1;
            iteraciones = a>b ? a :b;
        }
    }
    cout << iteraciones << endl;

    for(int i=0; i<iteraciones; i++){

        matriz[y1][x1] = "  *";
        if(is_h_or_v){
            x1 += 1;
        }else{
            if(x_inicial>x_final){
                x1 -= 1;
            }else{
                x1 += 1;
            }
            if(y_inicial>y_final){
                y1 -= 1;
            }else{
                y1 += 1;
            }
        }
    }
}
void Pizarra::pintar_pizarra(vector<Coordenada*> _c,int _numero) {
    if(_numero==1){
       pintar_linea(_c);
    }else if(_numero==2){


    }else if(_numero==3){
        //circulo

    }else if(_numero==4){
        //triangulo
        vector<Coordenada*> linea1;
        linea1.push_back(_c[0]);
        linea1.push_back(_c[1]);
        pintar_linea(linea1);
        vector<Coordenada*> linea2;
        linea2.push_back(_c[0]);
        linea2.push_back(_c[2]);
        pintar_linea(linea2);
        vector<Coordenada*> linea3;
        linea3.push_back(_c[1]);
        linea3.push_back(_c[2]);
        pintar_linea(linea3);
    }
}

