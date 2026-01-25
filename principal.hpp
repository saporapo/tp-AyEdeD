#ifndef _TPRINCIPAL_T_
#define _TPRINCIPAL_T_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compresor.hpp"
#include "descompresor.hpp"

struct InfoByte
{
   unsigned int n; // cuantas veces aparece el byte
   string cod;
};

void inicInfoByte(InfoByte arr[]);
void comprimir(string nomArchOri);
void descomprimir(string nomArchCompr);


#endif