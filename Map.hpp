
#ifndef _TMAP_TAD_
#define _TMAP_TAD_

#include <iostream>
#include "Array.hpp"

using namespace std;

template<typename K,typename V>
struct Map
{
   Array<K> cod;
   Array<V> elem;
   int i;
};

template<typename K,typename V>
Map<K,V> map()
{
   Map<K,V> m;
   m.cod=array<K>();
   m.elem=array<V>();
   m.i=0;
   return m;
}

template<typename K,typename V>
V* mapGet(Map<K,V> m,K k)
{
   //tengo q buscar k en map para retornar el v en esa pos
   int i=0;
   while(i<m.cod.len)
   {
       if(m.cod.arr[i]==k)
      {
         return arrayGet<V>(m.elem,i); //devuelve la direc de memoria de forma q puedo modificar el contenido
      }
      i++;
   }
     return NULL;
}

template<typename K,typename V>
V* mapPut(Map<K,V>& m,K k,V v)
{
   //agrega v con clave k a m, si habia un v en k, lo reemplaza

   V* t=mapGet<K,V>(m,k); //direc de memo con contenido modificable
   if(t==NULL)
   {
      arrayAdd<K>(m.cod,k);
      arrayAdd<V>(m.elem,v);
   }
   else
   {
      *t=v;
   }

   return mapGet<K,V>(m,k);
}

template<typename K,typename V>
bool mapContains(Map<K,V> m,K k)
{
   bool r=false;
   V* t=mapGet<K,V>(m,k);
   if(t==NULL)
   {
      return r;
   }

   r=true;

   return r;
}

template<typename K,typename V>
V mapRemove(Map<K,V>& m,K k)
{
   //remueve la entrada de k en m y devuelve el v q antes contenia
      V v;
      int i=0;
      while(i<arraySize<K>(m.cod))
      {
          if(m.cod.arr[i]==k)
        {
           arrayRemove<K>(m.cod,i);
           v=arrayRemove<V>(m.elem,i);
        }

         i++;
      }
         return v;
}

template<typename K,typename V>
void mapRemoveAll(Map<K,V>& m)
{
   arrayRemoveAll<K>(m.cod);
   arrayRemoveAll<V>(m.elem);
}

template<typename K,typename V>
int mapSize(Map<K,V> m)
{
   return arraySize<K>(m.cod);
}

template<typename K,typename V>
bool mapHasNext(Map<K,V> m)
{
   bool r=false;
   if(m.i<mapSize<K,V>(m))
   {
      r=true;
   }
   return r;
}

template<typename K,typename V>
K mapNextKey(Map<K,V>& m)
{
   K* k=arrayGet<K>(m.cod,m.i);
   m.i++;
   return *k; //devuelvo el contenido
}

template<typename K,typename V>
V* mapNextValue(Map<K,V>& m)
{
   V* v=arrayGet<V>(m.elem,m.i);
   m.i++;
   return v; //devuelvo direc memo
}

template<typename K,typename V>
void mapReset(Map<K,V>& m)
{
   m.i=0;
}

template <typename K>
int cmpKK(K t1, K t2)
{
   return t1-t2;
}

template <typename V>
int cmpVV(V t1, V t2)
{
   return t1-t2;
}

template<typename K,typename V>
void mapSortByKeys(Map<K,V>& m,int cmpKK(K,K))
{
   //tengo q ordenar ambos array en base a K

   bool ordenado=false;
   while(!ordenado)
   {
      ordenado=true;
      int i=0;
      while(i<m.cod.len)
      {
         if(cmpKK(m.cod.arr[i],m.cod.arr[i+1])>0)//a>b
         {
            K a=m.cod.arr[i];
            V b=m.elem.arr[i];
            m.cod.arr[i]=m.cod.arr[i+1];
            m.cod.arr[i+1]=a;
            m.elem.arr[i]=m.elem.arr[i+1];
            m.elem.arr[i+1]=b;
            ordenado=false;
         }
         i++;
      }
   }

}

template<typename K,typename V>
void mapSortByValues(Map<K,V>& m,int cmpVV(V,V))
{

   bool ordenado=false;
   while(!ordenado)
   {
      ordenado=true;
      int i=0;
      while(i<m.elem.len)
      {
         if(cmpKK(m.elem.arr[i],m.elem.arr[i+1])>0)//a>b
         {
            K a=m.cod.arr[i];
            V b=m.elem.arr[i];
            m.cod.arr[i]=m.cod.arr[i+1];
            m.cod.arr[i+1]=a;
            m.elem.arr[i]=m.elem.arr[i+1];
            m.elem.arr[i+1]=b;
            ordenado=false;
         }
         i++;
      }
   }
}


#endif
