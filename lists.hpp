#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>

template <typename T>
struct Node
{
    T info;
    Node<T>* sig;
};

template <typename T>
Node<T>* add(Node<T>*& p,T e)
{
   Node<T>* nuevo=new Node<T>();
   nuevo->info=e;
   nuevo->sig=NULL;

   if(p!=NULL)
   {
      Node<T>* aux=p;
      while(aux->sig!=NULL)
      {
          aux=aux->sig; //le estoy dando el nodo sig xq sig es un nodo
      }
      aux->sig=nuevo;
      return aux;
   }
   else
   {
      p=nuevo;
   }

   return p;
}

template <typename T>
Node<T>* addFirst(Node<T>*& p,T e)
{
   Node<T>* nuevo=new Node<T>();
   nuevo->info=e;
   nuevo->sig=p; //le asigna direc del sig nodo p
   p=nuevo;
   return p;
}

template <typename T, typename K>
T remove(Node<T>*& p,K k,int cmpTK(T,K))
{
   //remueve k
   T t;
   Node<T>* sig=p;
   Node<T>* ant=NULL;
      while(cmpTK(sig->info,k)!=0)
      {
          ant=sig;
          sig=sig->sig;
      }

   t = sig->info;
   ant->sig = sig->sig;
   delete sig;

   return t;
}

template <typename T>
Node<T>* removeFirst(Node<T>*& p)
{
   Node<T>* t=new Node<T>();
   Node<T>* sig=p->sig;
   //Node<T>* sig=new Node<T>();
     t->info=p->info;
     t->sig=NULL;
   delete p;
   p=sig;
   return t;
}

template <typename T, typename K>
Node<T>* find(Node<T>* p,K k,int cmpTK(T,K))
{
   Node<T>* sig = p;
   while( cmpTK(sig->info,k)!=0 and sig->sig!=NULL )
   {
      sig = sig->sig;
   }

   return cmpTK(sig->infO,k)==0?sig:NULL;
}

template <typename T>
Node<T>* orderedInsert(Node<T>*& p,T e,int cmpTT(T,T))
{
  Node<T>* aux=p;
  Node<T>* ant=NULL;
  Node<T>* nuevo= new Node<T>();

  if(p==NULL)
  {
     return add<T>(p,e);
  }

 if(cmpTT(aux->info,e)>0)
 {
    return addFirst<T>(p,e);
 }
 while(aux!=NULL)
 {
    if(cmpTT(aux->info,e)>0)
    {
       nuevo->info=e;
       nuevo->sig=aux;
       ant->sig=nuevo;
       return ant; //ant contiene direcc del nodo insertado
    }
    ant=aux;
    aux=aux->sig;
 }

  return add<T>(p,e);
}

template <typename T>
Node<T>* searchAndInsert(Node<T>*& p,T e,bool& enc,int cmpTT(T,T))
{
//   Busca en p la primera ocurrencia de e, y retorna el nodo que lo contiene.
//   Si e no existe en p lo insertar en orden, según cmpTT, y retorna el nodo insertado.
//   Asigna true o false a enc según e fue encontrado o insertado.

   enc=true;
   if(p==NULL)
   {
      enc=false;
      return orderedInsert<T>(p,e,cmpTT);
   }
   Node<T>* r=find<T,T>(p,e,cmpTT);
   if(r==NULL)
   {
      enc=false;
      return orderedInsert<T>(p,e,cmpTT);
   }

   return r;
}

template <typename T>
void sort(Node<T>*& p,int cmpTT(T,T))
{
   Node<T>* aux=p;
   Node<T>* siguiente=aux->sig;
   bool ordenado=false;
      while(!ordenado)
      {
         ordenado=true;
         while(aux!=NULL and siguiente!=NULL)
         {
            if(cmpTT(aux->info,siguiente->info)>0)
            {
               T nuevo=siguiente->info;
               siguiente->info=aux->info;
               aux->info=nuevo;
               ordenado=false;
            }
            aux=aux->sig;
            siguiente=siguiente->sig;
         }
      }

}

template <typename T>
bool isEmpty(Node<T>* p)
{
   return p==NULL?true:false;
}

template <typename T>
void free(Node<T>*& p)
{
   Node<T>* aux = p;
      while(p!=NULL)
      {
         aux=p->sig;
         delete p;
         p=aux;
      }
}

template <typename T>
Node<T>* push(Node<T>*& p,T e)
{
   return addFirst<T>(p,e);
}

template <typename T> T pop(Node<T>*& p)
{
   Node<T>* t=removeFirst<T>(p);
   return t->info;
}

template <typename T>
Node<T>* enqueue(Node<T>*& p,Node<T>*& q,T e)
{
   //p es el 1er nodo, q es el ultimo nodo, e es lo q insertare al final

   Node<T>* nuevo=new Node<T>();
      nuevo->info=e;
      nuevo->sig=NULL;

      if(p!=NULL)
      {
         Node<T>* aux=p;
         while(aux->sig!=NULL)
         {
             aux=aux->sig; //le estoy dando el nodo sig xq sig es un nodo
         }
         aux->sig=q=nuevo;
         return aux;
      }
      else
      {
         p=nuevo;
         q=nuevo;
      }

   return p;
}

template <typename T>
Node<T>* enqueue(Node<T>*& q,T e)
{
   Node<T>* aux=q;
   Node<T>* nuevo=new Node<T>();
         nuevo->info=e;
         nuevo->sig=NULL;

         if(q==NULL)
         {
            q=nuevo;
            aux=q;
            q->sig=aux;
         }
         else
         {
              aux=q->sig;
              Node<T>* antq=aux;
              while(antq!=q)
              {
                 antq=antq->sig;
              }
              antq->sig=nuevo;
              q=nuevo;
              q->sig=aux;
              return aux;
         }

      return q;
}

template <typename T>
T dequeue(Node<T>*& p, Node<T>*& q)
{
   T t=removeFirst<T>(p);
   return t;
}

template <typename T>
T dequeue(Node<T>*& q)
{
      Node<T>* nuevoU=q->sig;
      q->sig=nuevoU->sig;
      T t=nuevoU->info;

      if(nuevoU==q)
      {
         q=NULL;
      }

      delete nuevoU;

      return t;
}


#endif
