#ifndef BITWRITER
#define BITWRITER

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


struct BitWriter
{
   FILE* f;
   unsigned char buffer;
   int nbits; // number of bits currently in buffer (0..7)
};

inline BitWriter bitWriter(FILE* f)
{
    BitWriter bw;
    bw.f = f;
    bw.buffer = 0;
    bw.nbits = 0;
    return bw;
}

inline void bitWriterWrite(BitWriter& bw, int bit)
{
   // write bits MSB first: the first written bit becomes the most significant in the full byte
   bw.buffer = (unsigned char)((bw.buffer << 1) | (bit & 1));
   bw.nbits++;
   if(bw.nbits == 8)
   {
      unsigned char c = bw.buffer;
      write<unsigned char>(bw.f, c);
      bw.buffer = 0;
      bw.nbits = 0;
   }
}

inline void bitWriterFlush(BitWriter& bw)
{
   if(bw.nbits > 0)
   {
      // shift the remaining bits to the MSB positions
      bw.buffer = (unsigned char)(bw.buffer << (8 - bw.nbits));
      write<unsigned char>(bw.f, bw.buffer);
      bw.buffer = 0;
      bw.nbits = 0;
   }
}

#endif
