#ifndef _TCOMPRESOR_T_
#define _TCOMPRESOR_T_

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

void paso1(string nomArchOri,InfoByte arr[]);
List<HuffmanTreeInfo> paso2(InfoByte arr[]);
HuffmanTreeInfo* paso3(List<HuffmanTreeInfo>& hTI);
void paso4(InfoByte arr[],HuffmanTreeInfo* raiz);
void paso5(string nomArchOri,InfoByte arr[]);


#endif
