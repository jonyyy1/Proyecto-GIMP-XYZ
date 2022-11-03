cmake_minimum_required(VERSION 3.23)
project(ProyectoGIMP)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProyectoGIMP main.cpp clases/CFiguraGeometrica.cpp clases/CFiguraGeometrica.h clases/CLinea.cpp clases/CLinea.h clases/Coordenada.cpp clases/Coordenada.h constantes/Matriz.h clases/Pizarra.cpp clases/Pizarra.h)
