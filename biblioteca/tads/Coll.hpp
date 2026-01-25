#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../funciones/strings.hpp"
#include "../funciones/files.hpp"

using namespace std;

//cout<<c.s; para ver la coll
//declaro coll y sus campos
template<typename T>
struct Coll
{
   string s;
   char sep;
   int i;
};

template<typename T>
Coll<T> coll(char sep)
{
   //por si quiero cambiar el sep
   Coll<T> c;
   c.s="";
   c.sep='|';
   c.i=0;
   return c;
}

template<typename T>
Coll<T> coll()
{
   //como inicia la coll
   Coll<T> c;
   c.s="";
   c.sep='|';
   c.i=0;
   return c;
}

template<typename T>
int collSize(Coll<T> c)
{
   //cuenta elems del coll
   return tokenCount(c.s,c.sep);
}

template<typename T>
void collRemoveAll(Coll<T>& c)
{
   //vacia la coll
   c.s="";
}

template<typename T>
void collRemoveAt(Coll<T>& c, int p)
{
   //remueve 1 elem de coll
   removeTokenAt(c.s,c.sep,p);
}

template<typename T>
int collAdd(Coll<T>& c,T t,string tToString(T))
{
   //agrega elem a coll
   //si quiero agregar algo a un coll, debe ser como string
   //T t es lo q voy a agregar
   string g=tToString(t);
   addToken(c.s,c.sep,g);
   return tokenCount(c.s,c.sep);
}

template <typename T>
void collSetAt(Coll<T>& c,T t,int p,string tToString(T))
{
   //reemplaza x el elem t lo q se encuentra en pos p
   string g=tToString(t);
   setTokenAt(c.s,c.sep,g,p);
}

template <typename T>
T collGetAt(Coll<T> c,int p,T tFromString(string))
{
   //retorna 1 elem de la coll en pos p
   string e=getTokenAt(c.s,c.sep,p);
   T t= tFromString(e);
   return t;
}

template <typename T, typename K>
int cmpTK(T t, K id)
{
// corresponde a la version 2 del ejercicio de calificaciones (borrado)
//borre lo hecho de la nota anterior, esto es de una prueba del find
      return t.id-id;
}

template <typename T, typename K>
int collFind(Coll<T> c,K k,int cmpTK(T,K),T tFromString(string))
{
   //encuentra un tipo de dato no definido como T de coll
   for(int i=0;i<collSize<T>(c);i++)
   {
      T t=collGetAt<T>(c,i,tFromString);
      if(cmpTK(t,k)==0)
      {
         return i;
      }
   }

   return -1;
}

template <typename T>
void collSwap(Coll<T>& c,int p1,int p2)
{
   //permuta 2 elem de coll
   string t1=getTokenAt(c.s,c.sep,p1);
   setTokenAt(c.s,c.sep,getTokenAt(c.s,c.sep,p2),p1);
   setTokenAt(c.s,c.sep,t1,p2);
}

template <typename T>
int cmpTT(T t1, T t2)
{
   return t1-t2;
}

template <typename T>
void collSort(Coll<T>& c,int cmpTT(T,T),T tFromstring(string),string tToString(T))
{
   //ordena elems alfabeticamente de un coll string
   //ordena de mayor a menor los int
   bool ordenado=false;
   while(!ordenado)
   {
      ordenado=true;
      int i=0;
      while(i<collSize<T>(c)-1)
      {
         if(cmpTT(collGetAt<T>(c,i,tFromstring),collGetAt<T>(c,i+1,tFromstring))<0)//a<b
         {
            collSwap<T>(c,i,i+1);
            ordenado=false;
         }
         i++;
      }
   }
}

template<typename T>
bool collHasNext(Coll<T> c)
{
   //determ si hay elems para retornar del coll
   bool r=false;
   //r=falso, si en c todavia hay elems para retornar es true
   if(c.i<collSize(c))
   {
      r=true;
   }

   return r;
}

template<typename T>
T collNext(Coll<T>& c,T tFromString(string))
{
   //retorna el elem del coll en base a collHasNext
   T e;
   e=collGetAt<T>(c,c.i,tFromString);
   c.i++;
   return e;
}

template<typename T>
T collNext(Coll<T>& c,bool& eoc,T tFromString(string))
{
   //para usar sin collHasNext
   T t;
   eoc=(c.i!=collSize(c));
   if(eoc)
   {
      string f=getTokenAt(c.s,c.sep,c.i);
      t=tFromString(f);
      c.i++;
   }
   return t;
}

template<typename T>
void collReset(Coll<T>& c)
{
   //vacia la iteracion del c.i luego de haber usado los 2 coll anteriores
   c.i=0;
}

template<typename T>
string collToString(Coll<T> c)
{
   return c.sep+c.s;
}

template<typename T>
Coll<T> collFromString(string s)
{
   Coll<T> c;
   c.sep=s[0];
   c.s=substring(s,1);
   return c;
}


#endif

