cmake_minimum_required(VERSION 3.23)
project(ProyectoGIMP)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProyectoGIMP main.cpp clases/CFiguraGeometrica.cpp clases/CFiguraGeometrica.h clases/CLinea.cpp clases/CLinea.h clases/Coordenada.cpp clases/Coordenada.h pantalla/Matriz.h clases/Pizarra.cpp clases/Pizarra.h helpers/TextTable.cpp helpers/TextTable.h clases/CRectangulo.cpp clases/CRectangulo.h clases/Circulo.cpp clases/Circulo.h clases/Triangulo.cpp clases/Triangulo.h)
