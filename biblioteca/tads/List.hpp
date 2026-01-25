#ifndef _TLIST_TAD_
#define _TLIST_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct List
{
   Node<T>* p;
   int len;
};

template<typename T>
List<T> list()
{
   List<T> lst;
   lst.p=NULL;
   lst.len=0;
   return lst;
}

template<typename T>
Node<T>* listAdd(List<T>& lst,T e)
{
   return add<T>(lst.p,e);
}

template<typename T>
Node<T>* listAddFirst(List<T>& lst,T e)
{
   return addFirst<T>(lst.p,e);
}

template<typename T,typename K>
T listRemove(List<T>& lst,K k,int cmpTK(T,K))
{
   T t=remove<T,K>(lst.p,k,cmpTK);
   return t;
}

template<typename T>
Node<T>* listRemoveFirst(List<T>& lst)
{
   Node<T>* t=removeFirst<T>(lst.p);
   return t;
}

template<typename T>
T* listRemoveFirstH(List<T>& lst)
{
   Node<T>* n = listRemoveFirst<T>(lst);
   T* value = &n->info;
   return value;
}

template<typename T,typename K>
Node<T>* listFind(List<T> lst,K k,int cmpTK(T,K))
{
   return find<T,K>(lst.p,k,cmpTK);
}

template<typename T>
bool listIsEmpty(List<T> lst)
{
   return isEmpty<T>(lst.p);
}

template<typename T>
int listSize(List<T> lst)
{
   int i=0;
   while(lst.p!=NULL)
   {
      lst.p=lst.p->sig;
      i++;
   }
   return i;
}

template<typename T>
void listFree(List<T>& lst)
{
   free<T>(lst.p);
}

template<typename T>
Node<T>* listOrderedInsert(List<T>& lst,T t,int cmpTT(T,T))
{
   return orderedInsert<T>(lst.p,t,cmpTT);
}

template<typename T>
void listSort(List<T>& lst,int cmpTT(T,T))
{
   sort<T>(lst.p,cmpTT);
}

template<typename T>
void listReset(List<T>& lst)
{
   lst.len=0;
}

template<typename T>
bool listHasNext(List<T> lst)
{
   bool res=false;
   if(lst.len<listSize(lst))
   {
      res=true;
   }
   return res;
}

template<typename T>
Node<T>* listNext(List<T>& lst)
{
   Node<T>* aux=lst.p->sig;
   lst.len++;
   return aux;
}

template<typename T>
Node<T>* listNext(List<T>& lst,bool& endOfList)
{
   Node<T>* t=NULL;
   endOfList=(lst.len<listSize(lst));
      if(endOfList)
      {
         t=listNext(lst);
         lst.len++;
      }
   return t;
}

#endif
