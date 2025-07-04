/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NodoCliente.hpp
 * Author: hecto
 *
 * Created on June 27, 2025, 6:10 PM
 */

#ifndef NODOCLIENTE_HPP
#define NODOCLIENTE_HPP
#include "Cliente.hpp"
struct NodoCliente{
    struct Cliente dato;
    struct NodoCliente* siguiente;
};

#endif /* NODOCLIENTE_HPP */

