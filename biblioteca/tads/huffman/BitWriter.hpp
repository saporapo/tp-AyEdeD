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
   string b;
};

BitWriter bitWriter(FILE* f)
{
    return {f,""};
}

void bitWriterWrite(BitWriter& bw, int bit)
{
   bw.b+=intToString(bit);
   if(length(bw.b)==8)
   {
      unsigned char c=stringToInt(bw.b);
      write<char>(bw.f,c);
      bw.b="";
   }
}

void bitWriterFlush(BitWriter& bw)
{
   if(length(bw.b) > 0)
   {
      while(length(bw.b) < 8)
      {
         bw.b+="0";
      }
      unsigned char c=stringToInt(bw.b);
      write<char>(bw.f,c);
      bw.b="";
   }
}

#endif
