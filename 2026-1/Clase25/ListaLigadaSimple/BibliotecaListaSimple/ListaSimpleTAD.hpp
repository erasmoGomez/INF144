//
// Created by erasmo on 6/19/26.
//

#ifndef LISTALIGADASIMPLE_LISTASIMPLETAD_HPP
#define LISTALIGADASIMPLE_LISTASIMPLETAD_HPP
#include "NodoListaSImple.hpp"
struct ListaTAD {
    //Minimo Necesario
    struct NodoListaSimple *inicio;
    //Adicional
    int cantidad_nodos;
    struct NodoListaSimple *ultimo;
};
#endif //LISTALIGADASIMPLE_LISTASIMPLETAD_HPP