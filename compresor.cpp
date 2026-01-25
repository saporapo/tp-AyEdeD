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
         HuffmanTreeInfo* r1=listRemoveFirstP<HuffmanTreeInfo>(hTI);
         HuffmanTreeInfo* r2=listRemoveFirstP<HuffmanTreeInfo>(hTI);

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
            char b=s[a];
            write<char>(g,b);
         }
         p++;
      }
   }

   seek<char>(g,0);
   write<char>(g,p);

   int pos = fileSize<char>(g);
   seek<char>(g,pos);
   write<char>(g,'\n');

      FILE* f=fopen(nomArchOri.c_str(),"r+b");

      unsigned char l=read<unsigned char>(f);
      while(!feof(f))
      {
         string s=arr[(int)l].cod;
         for(int z=0;s[z]!='\0';z++)
         {
            char c=s[z];
            int v=charToInt(c);
            bitWriterWrite(bw,v);
         }

         l=read<unsigned char>(f);
      }

      bitWriterFlush(bw);


      fclose(g);
      fclose(f);
}