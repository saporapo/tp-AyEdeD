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

   int p=indexOf(nomArchCompr,".huf");

   string newName = substring(nomArchCompr,0,p) + ".desc";

   FILE* g=fopen(newName.c_str(),"w+b");

   string e="";

      for(int i=0;i<r*8;i++)
      {
         int bit=bitReaderRead(br);

         e+=intToChar(bit);

         for(int z=0;z<256;z++)
         {
            if(e==arr[z].cod)
            {
               write<char>(g,z);
               e="";
               break;
            }
         }
      }

   fclose(g);
   fclose(f);
}