////============================================================================
//// Name        : main.cpp
//// Author      :
//// Version     :
//// Copyright   : Your copyright notice
//// Description : Hello World in C++, Ansi-style
////============================================================================

#ifndef _MAIN
#define _MAIN

#include "principal.hpp"
using namespace std;


int main(int argc,char** argv)
{
    string nomArch = argv[1];
    InfoByte arr[256];

    inicInfoByte(arr);
 
      // comprimo o descomprimo
      if( endsWith(nomArch,".huf") )
      {
         descomprimir(nomArch, arr);
      }
      else
      {
         comprimir(nomArch, arr);
      }


   return 0;
}


#endif
