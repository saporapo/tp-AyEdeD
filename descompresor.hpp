#ifndef _TDESCOMPRESOR_T_
#define _TDESCOMPRESOR_T_

#include <iostream>
#include <stdio.h>
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
#include "principal.hpp"

void paso1Desc(string nomArchCompr,InfoByte arr[],int& pos);
void paso2Desc(string nomArchCompr,InfoByte arr[],int pos);


#endif
