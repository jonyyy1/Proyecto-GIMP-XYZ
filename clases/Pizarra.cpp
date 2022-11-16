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
vector<CFiguraGeometrica *> Pizarra::get_figuras() {return figuras;}
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

void Pizarra::mostrar() {
    for(int i=0; i<12; i++){
        for(int j=0; j<12; j++){
            cout << matriz[i][j]<<" ";
        }
        cout << endl;
    }
}
vector<Coordenada*> get_puntos(vector<Coordenada *> c,int numero){
    vector<Coordenada*> out;
    if(numero==1){
        //(2,3) (3,2) (4,1)
        //for(int i=0; i<)
    }else if(numero==2){

    }else if(numero==3){

    }

    return out
}
void Pizarra::pintar_pizarra(vector<Coordenada *> c,int _numero) {
    vector<Coordenada*> puntos = get_puntos(c,_numero);
    for(auto i: puntos){
        matriz[i->get_x()][i->get_y()]="  *";
    }
    mostrar();
}

