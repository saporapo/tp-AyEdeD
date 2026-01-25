#ifndef _TPRINCIPAL_T_
#define _TPRINCIPAL_T_

#include "compresor.hpp"
#include "descompresor.hpp"

using namespace std;


// Comprime el archivo original y genera un .huf
void comprimir(string nomArchOri, InfoByte arr[]);
// Descomprime un archivo .huf y reconstruye el original
void descomprimir(string nomArchCompr, InfoByte arr[]);


#endif