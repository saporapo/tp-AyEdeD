#ifndef BITREADER
#define BITREADER

#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../../tads/Stack.hpp"
#include "../../tads/Array.hpp"
#include "../../tads/Coll.hpp"
#include "../../tads/List.hpp"
#include "../../tads/Map.hpp"
#include "../../tads/Queue.hpp"
#include "HuffmanSetup.hpp"
#include "../../funciones/strings.hpp"
#include "../../funciones/files.hpp"
#include "../../funciones/arrays.hpp"
#include "../../funciones/lists.hpp"
#include "../../funciones/tokens.hpp"


using namespace std;


//como pasa un byte a char cuando lo escribo en el archivo?
//en el archivo estoy escribiendo un caracter q asemeja al codigo binario(byte)
//o estoy escribiendo directamente los 0 y 1?

// los caracteres no existen, los bytes son numeros enteros del 0 al 255 representados
// x 8 bits (0 y 1), q en ASCII (char) tienen una representacion al "caracter".
//cuando leo en el archivo, leo 1 byte, pero debo leer 1 bit.

struct BitReader
{
   FILE* f;
   unsigned int bL;
   int contB;
};

BitReader bitReader(FILE* f)
{
    return {f,0,0};
}

int bitReaderRead(BitReader& br)
{
   //leer byte, pasar de char a int, de int a string y sacar el s[0] [contB], pasarlo a int
   // sumar 1 al contador y retornar
   //no debo leer el siguiente byte, hasta q haya retornado s[8] y contB debe volver a 0
   if(br.contB==0)
   {
      br.bL=read<unsigned char>(br.f);
   }

   int i=charToInt(br.bL);
   string s=intToString(i);

   // Asegurar 8 bits
   while(length(s) < 8)
   {
      s = "0" + s;
   }

   int bit = charToInt(s[br.contB]);

   br.contB++;
   if(br.contB == 8)
   {
      br.contB = 0;
   }

   return bit;
}


#endif

