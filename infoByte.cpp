#include "infoByte.hpp"

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