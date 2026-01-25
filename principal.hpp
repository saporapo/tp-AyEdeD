#ifndef _TPRINCIPAL_T_
#define _TPRINCIPAL_T_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/arrays.hpp"
#include "biblioteca/funciones/lists.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/Array.hpp"
#include "biblioteca/tads/Map.hpp"
#include "biblioteca/tads/List.hpp"
#include "biblioteca/tads/Stack.hpp"
#include "biblioteca/tads/Queue.hpp"
#include "biblioteca/tads/Coll.hpp"
#include "biblioteca/tads/huffman/HuffmanSetup.hpp"
#include "biblioteca/tads/huffman/BitReader.hpp"
#include "biblioteca/tads/huffman/BitWriter.hpp"
#include "infoByte.hpp"
#include "compresor.hpp"
#include "descompresor.hpp"

using namespace std;


// Comprime el archivo original y genera un .huf
void comprimir(string nomArchOri, InfoByte arr[]);
// Descomprime un archivo .huf y reconstruye el original
void descomprimir(string nomArchCompr, InfoByte arr[]);


#endif