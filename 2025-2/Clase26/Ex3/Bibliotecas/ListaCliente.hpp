//
// Created by Erasmo on 20/11/25.
//

#ifndef EX3_LISTACLIENTE_HPP
#define EX3_LISTACLIENTE_HPP
#include "NodoCliente.hpp"
struct ListaCliente{ //TAD
    struct NodoCliente* inicio;
    struct NodoCliente* limite;
    struct NodoCliente* fin;
    int cantidad_pares;
    int cantidad_impares;
    int cantidad_clientes;
};
#endif //EX3_LISTACLIENTE_HPP
