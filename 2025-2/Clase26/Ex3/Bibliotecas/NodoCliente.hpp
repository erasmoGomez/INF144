//
// Created by Erasmo on 20/11/25.
//

#ifndef EX3_NODOCLIENTE_HPP
#define EX3_NODOCLIENTE_HPP
#include "Cliente.hpp"
struct NodoCliente{
    struct Cliente dato;
    struct NodoCliente* siguiente; //Autoreferencia
};
#endif //EX3_NODOCLIENTE_HPP
