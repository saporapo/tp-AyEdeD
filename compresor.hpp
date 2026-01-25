#ifndef _TCOMPRESOR_T_
#define _TCOMPRESOR_T_

#include "infoByte.hpp"

using namespace std;

void paso1(string nomArchOri,InfoByte arr[]);
List<HuffmanTreeInfo> paso2(InfoByte arr[]);
HuffmanTreeInfo* paso3(List<HuffmanTreeInfo>& hTI);
void paso4(InfoByte arr[],HuffmanTreeInfo* raiz);
void paso5(string nomArchOri,InfoByte arr[]);


#endif
