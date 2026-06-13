//
// Created by erasmo on 6/12/26.
//

#ifndef POKE261_MOVIMIENTO_HPP
#define POKE261_MOVIMIENTO_HPP
//1,Pound,Normal,Physical,Tough,35,40,100,1
struct Movimiento {
    int id;
    char* nombre;
    char* tipo;
    char* categoria;
    int poder;
    int precision;
    int pp;
    int generacion;
};
#endif //POKE261_MOVIMIENTO_HPP