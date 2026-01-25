#ifndef INFOBYTE_HPP
#define INFOBYTE_HPP

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

using namespace std;

struct InfoByte
{
   unsigned int n; // cuantas veces aparece el byte
   string cod;
};

InfoByte infoByte()
{
   return {0,""};
}

void inicInfoByte(InfoByte a[])
{
   for(int i=0; i<256; i++)
   {
      a[i]=infoByte();
   }
}

#endif
