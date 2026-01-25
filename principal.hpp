#ifndef _TPRINCIPAL_T_
#define _TPRINCIPAL_T_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compresor.hpp"
#include "descompresor.hpp"

using namespace std;

struct InfoByte
{
   unsigned int n; // cuantas veces aparece el byte
   string cod;
};

// Inicializa el arreglo de InfoByte
void inicInfoByte(InfoByte arr[]);
// Comprime el archivo original y genera un .huf
void comprimir(string nomArchOri);
// Descomprime un archivo .huf y reconstruye el original
void descomprimir(string nomArchCompr);


#endif