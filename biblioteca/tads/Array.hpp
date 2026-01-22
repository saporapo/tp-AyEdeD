#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../funciones/arrays.hpp"

using namespace std;

template <typename T>
struct Array
{
    T* arr;
    int len;
    int cap;
};

template <typename T>
Array<T> array(int cap)
{
    Array<T> a;
    a.arr = new T[cap];
    a.len = 0;
    a.cap = cap;

    return a;
}

template <typename T>
Array<T> array()
{
    Array<T> a;
    a = array<T>(100);

    return a;
}

template <typename T>
int arrayAdd(Array<T>& a, T t)
{
    if( a.cap==a.len )
    {
        T* b = new T[a.cap+1];
        for( int i = 0; i<a.len; i++ )
        {
            b[i] = a.arr[i];
        }
        delete a.arr;
        a.arr = b;
    }
    return add<T>(a.arr,a.len,t);
}

template <typename T>
T* arrayGet(Array<T> a, int p)
{
// ingreso de 1 a len
    return &a.arr[p]; //direc memo del arr en p
}

template <typename T>
void arraySet(Array<T>& a, int p, T t)
{
    a.arr[p]=t;
}

template <typename T>
void arrayInsert(Array<T>& a, T t, int p)
{
    insert<T>(a.arr, a.len, t, p);
}

template <typename T>
int arraySize(Array<T> a)
{
    return a.len;
}

template <typename T>
T arrayRemove(Array<T>& a, int p)
{
    T t = remove<T>(a.arr, a.len, p);
    return t;
}

template <typename T>
void arrayRemoveAll(Array<T>& a)
{
   delete a.arr; //liberamos la memoria
   a.arr=new T[a.cap]; //le doy un nuevo array
   a.len=0; //el len se reinicia
}

template <typename T, typename K>
int arrayFind(Array<T> a, K k, int cmpTK(T, K))
{
   return find<T>(a.arr, a.len, cmpTK);
}

template <typename T>
int arrayOrderedInsert(Array<T>& a, T t, int cmpTT(T, T))
{
   return orderedInsert<T>(a.arr, a.len, t, cmpTT);
}

template <typename T>
void arraySort(Array<T>& a, int cmpTT(T, T))
{
   sort<T>(a.arr,a.len,cmpTT);
}

#endif
