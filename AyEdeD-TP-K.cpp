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
 
      // comprimo o descomprimo
      if( endsWith(nomArch,".huf") )
      {
         descomprimir(nomArch);
      }
      else
      {
         comprimir(nomArch);
      }


   return 0;
}


#endif
