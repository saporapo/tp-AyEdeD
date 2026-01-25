#include "principal.hpp"


InfoByte arr[256];


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

void comprimir(string nomArchOri)
{
   inicInfoByte(arr);

   // paso 1 - contar cuantas veces aparece cada byte
   paso1(nomArchOri,arr);

   // paso 2 - crear la lista y ordenarla
   List<HuffmanTreeInfo> hTI = paso2(arr);

   // paso 3 - convertir la lista en arbol
   HuffmanTreeInfo* raiz = paso3(hTI);

   // paso 4 - recorrer el arbol y guardar los codigos en el array
   paso4(arr,raiz);

   // paso 5 - recorrer el archivo original y grabar bit x bit el archivo comprimido
   paso5(nomArchOri,arr);
}

void descomprimir(string nomArchCompr)
{
   inicInfoByte(arr);

   int pos=0; //para guardar pos en archivo y no recorrer arbol de nuevo

   //conseguir arbol
   paso1Desc(nomArchCompr,arr,pos);

   //recorrer resto del archivo para descomprimir
   paso2Desc(nomArchCompr,arr,pos);
}