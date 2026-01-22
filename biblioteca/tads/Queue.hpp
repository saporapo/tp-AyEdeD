#ifndef _TQUEUE_TAD_
#define _TQUEUE_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Queue
{
   Node<T>* p;
   Node<T>* q;
};

template<typename T>
Queue<T> queue()
{
   Queue<T> q;
   q.p=NULL;
   q.q=NULL;
   return q;
}

template<typename T>
Node<T>* queueEnqueue(Queue<T>& q,T e)
{
   return enqueue<T>(q.p,q.q,e);
}

template<typename T>
T queueDequeue(Queue<T>& q)
{
   T t=dequeue<T>(q.p,q.q);
   return t;
}

template<typename T>
bool queueIsEmpty(Queue<T> q)
{
   return isEmpty<T>(q.p);
}

template<typename T>
int queueSize(Queue<T> q)
{
   int i=0;
         while(q.p!=NULL)
         {
            q.p=q.p->sig;
            i++;
         }
         return i;
}

#endif
