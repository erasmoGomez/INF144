/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaCliente.hpp
 * Author: hecto
 *
 * Created on June 27, 2025, 6:11 PM
 */

#ifndef LISTACLIENTE_HPP
#define LISTACLIENTE_HPP
#include "NodoCliente.hpp"
struct ListaCliente{
    struct NodoCliente* inicio;
    struct NodoCliente* fin;
    int cantidad_pares;
    int cantidad_impares;
    int cantidad_clientes;
};

#endif /* LISTACLIENTE_HPP */

