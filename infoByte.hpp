#ifndef INFOBYTE_HPP
#define INFOBYTE_HPP

#include <string>
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
