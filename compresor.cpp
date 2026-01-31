#include "compresor.hpp"

// paso 1 - contar cuantas veces aparece cada byte
void paso1(string nomArchOri,InfoByte arr[])
{
   FILE* f = fopen(nomArchOri.c_str(),"r+b");
   char c = read<char>(f);
   while(!feof(f))
   {
      arr[(int)c].n++;//agregamos una instancia encontrada
      c = read<char>(f);//leemos una nueva instancia
   }
   fclose(f);
}

int cmpHH(HuffmanTreeInfo t,HuffmanTreeInfo k)  
{
   int a=t.n-k.n;
   if(a==0)
   {
      a=t.c-k.c;
   }
   return a;
}

// paso 2 - crear la lista y ordenarla
List<HuffmanTreeInfo> paso2(InfoByte arr[])
{
   List<HuffmanTreeInfo> lista = list<HuffmanTreeInfo>();//se inicializa
   for (int i=0; i<256; i++)//recorremos el array
   {
      if( arr[i].n!=0 )
      {
         //las hojas tiene la parte int del char correspondiente, lo q seria c de hti
         HuffmanTreeInfo* h = huffmanTreeInfo(i,arr[i].n,NULL,NULL);//se genera una hoja de Huffman
         listOrderedInsert<HuffmanTreeInfo>(lista,*h,cmpHH);
      }
   }
   return lista;
}

// paso 3 - convertir la lista en arbol
HuffmanTreeInfo* paso3(List<HuffmanTreeInfo>& hTI)
{
   HuffmanTreeInfo* centralHTI;//se crea un puntero semilla

   for( int a=0; listSize<HuffmanTreeInfo>(hTI)>1 ; a++ )//se vacia la lista
      {//se usa una funcion que remueve un puntero
         HuffmanTreeInfo* r1=listRemoveFirstH<HuffmanTreeInfo>(hTI);
         HuffmanTreeInfo* r2=listRemoveFirstH<HuffmanTreeInfo>(hTI);

         int r=r1->n+r2->n;

         HuffmanTreeInfo* rama = huffmanTreeInfo(a,r,r2,r1);

         listOrderedInsert<HuffmanTreeInfo>(hTI,*rama,cmpHH);

         centralHTI=rama;
      }
   return centralHTI;
}

// paso 4 - recorrer el arbol y guardar los codigos en el array
void paso4(InfoByte arr[],HuffmanTreeInfo* raiz)
{
   HuffmanTree ht=huffmanTree(raiz);
   string cod;

   while( huffmanTreeHasNext(ht) )
   {
      //retorna el cod y 1 hoja
      HuffmanTreeInfo* hti=huffmanTreeNext(ht,cod);//el C de las hojas va entre 0-256 dependiendo la letra

      arr[hti->c].cod = cod;
   }

}

// paso 5 - recorrer el archivo original, grabar arbol y bit x bit el archivo comprimido
void paso5(string nomArchOri,InfoByte arr[])
{
   string newName = nomArchOri + ".huf";
   FILE* g=fopen(newName.c_str(),"w+b");
   BitWriter bw=bitWriter(g);

   int p=0;

   //reservo posicion donde cambiare la cant de chars del archivo
   write<char>(g,0);

   for(int i=0;i<256;i++)
   {
      if(arr[i].n>0)
      {
         char c=i;
         write<char>(g,c);

         string s=arr[i].cod; 

         write<char>(g,length(s));

         for(int a=0;s[a]!='\0';a++)
         {
            write<char>(g,s[a]);
         }
         p++;
      }
   }

   seek<char>(g,0);
   write<char>(g,p);

   int pos = fileSize<char>(g);
      seek<char>(g,pos);
      write<char>(g,'\n');
      // Reserve one byte to store number of valid bits in the last payload byte
   int padInfoPos = fileSize<char>(g);
   write<char>(g,0);

   // Open input file to compute original size and prepare for payload reading
   FILE* f=fopen(nomArchOri.c_str(),"r+b");
   unsigned long long originalSize = fileSize<char>(f);
   // reset input file to start
   seek<char>(f,0);

   // write original size (8 bytes) so decompressor knows exact number of bytes to recreate
   write<unsigned long long>(g, originalSize);

   unsigned char l=read<unsigned char>(f);
      while(!feof(f))
      {
         string s=arr[(int)l].cod;
         for(int z=0;s[z]!='\0';z++)
         {
            int v=charToInt(s[z]);
            bitWriterWrite(bw,v);
         }

         l=read<unsigned char>(f);
      }

      // capture pending bits before flush
      int pendingBits = bw.nbits; // 0..7
      bitWriterFlush(bw);

      // Compute valid bits in last written byte: if pendingBits==0 then last byte was full (8 valid bits)
      int validBits = (pendingBits == 0) ? 8 : pendingBits;

   // (debug prints removed)

   // Write the validBits value into the reserved pad-info byte
   seek<char>(g,padInfoPos);
   write<char>(g,(char)validBits);

      fclose(g);
      fclose(f);
}