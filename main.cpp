#include "funciones.h"

int main() {
    int numero_a_elegir = 0;
    cout <<"BIENVENIDO A GIMP"<<endl;
    cout <<"MENU"<< endl;
    while(true) {
        cout <<"1.-AGREGAR"<< endl;
        cout <<"2.-ELIMINAR"<< endl;
        cout <<"3.-GIRAR"<< endl;
        cout <<"4.-REDIMENSIONAR"<<endl;
        cout << "5.-MOSTRAR TABLA"<<endl;
        cout << "6.-MOSTRAR MATRIZ"<<endl;
        cout <<"7.-SALIR"<<endl;
        cin >> numero_a_elegir;
        switch (numero_a_elegir) {
            case 1:
                agregar_figura();
                break;
            case 2:
                eliminar_figura();
                break;
            case 3:
                // girar()
                break;
            case 4:
                redimensionar_figura();
                break;
            case 5:
                imprimir_tabla();
                break;
            case 6:
                pizarra->mostrar();
                break;
            case 7:
                return 0;
            default:
                cout << "Ingrese un numero valido" << endl;
                break;
        }
    }
}
