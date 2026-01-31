#include "descompresor.hpp"

void paso1Desc(string nomArchCompr,InfoByte arr[],int& pos)
{
   FILE* f=fopen(nomArchCompr.c_str(),"r+b");

   unsigned char l=read<unsigned char>(f);

   //el 1er char representa los caracteres distintos en el archivo
   int len=(int)l;

   int cont=0;
   while(cont<len)
   {
      l=read<unsigned char>(f);
      int q=(int)l;
      arr[q].n++;
      l=read<unsigned char>(f);
      string cod="";
      int r=(int)l;
      for(int i=0;i<r;i++)
      {
         l=read<unsigned char>(f);
         cod+=l;
      }
      arr[q].cod=cod;
      cont++;
   }
   pos=filePos<char>(f);

   fclose(f);
}

void paso2Desc(string nomArchCompr,InfoByte arr[],int pos)
{
   FILE* f=fopen(nomArchCompr.c_str(),"r+b");
   BitReader br=bitReader(f);
   int r=fileSize<char>(f)-pos;
   seek<char>(f,pos);

   // Skip the newline separator and read the valid-bits info byte
   // (the compressor writes a '\n' then a byte with number of valid bits in last payload byte)
   if(r <= 0)
   {
      fclose(f);
      return;
   }

   // consume the newline
   read<char>(f);
   // read valid bits (1..8)
   unsigned char validBits = read<unsigned char>(f);

   // read original size (number of bytes in original file)
   unsigned long long originalSize = read<unsigned long long>(f);

   // Remaining payload length in bytes (after newline, validBits and originalSize)
   int payloadBytes = r - 2 - (int)sizeof(unsigned long long);

   int p=indexOf(nomArchCompr,".huf");

   string newName = substring(nomArchCompr,0,p) + ".desc";

   FILE* g=fopen(newName.c_str(),"w+b");

   // If the file had only one distinct symbol, recreate it directly without reading bits
   int distinctCount = 0;
   int onlySymbol = -1;
   for(int z=0; z<256; z++)
   {
      if(arr[z].n > 0){ distinctCount++; onlySymbol = z; }
   }

   if(distinctCount == 1)
   {
      for(unsigned long long i=0;i<originalSize;i++) write<char>(g,(char)onlySymbol);
      fclose(g);
      fclose(f);
      return;
   }

   string e="";

   // decode until we've written originalSize bytes (ignore potential padding bits)
   unsigned long long written = 0;
   while(written < originalSize)
   {
      int bit = bitReaderRead(br);
      e += intToChar(bit);

      for(int z=0; z<256; z++)
      {
         if(e == arr[z].cod)
         {
            write<char>(g, z);
            e = "";
            written++;
            break;
         }
      }
   }

   fclose(g);
   fclose(f);
}