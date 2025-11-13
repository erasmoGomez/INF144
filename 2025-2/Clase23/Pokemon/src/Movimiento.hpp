//
// Created by Erasmo on 8/11/25.
//

#ifndef POKEMON_MOVIMIENTO_HPP
#define POKEMON_MOVIMIENTO_HPP
struct Movimiento{
    int id;
    char* nombre; // Se reserva en tiempo de Ejecucion
    char* tipo;
    //char nombre[20]; //Ya se reservo espacios
    char* categoria;
    int poder;
    int precision;
    int pp; //Punto de Poder
    int generacion;
};
#endif //POKEMON_MOVIMIENTO_HPP
