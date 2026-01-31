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
   unsigned char buffer;
   int nbits; // number of bits remaining in buffer (0..7)
};

inline BitReader bitReader(FILE* f)
{
    BitReader br;
    br.f = f;
    br.buffer = 0;
    br.nbits = 0;
    return br;
}

inline int bitReaderRead(BitReader& br)
{
   // If no bits buffered, read a new byte
   if(br.nbits == 0)
   {
      unsigned char c = read<unsigned char>(br.f);
      br.buffer = c;
      br.nbits = 8;
   }

   // return the next bit (MSB first)
   int bit = (br.buffer >> (br.nbits - 1)) & 1;
   br.nbits--;
   return bit;
}

#endif

