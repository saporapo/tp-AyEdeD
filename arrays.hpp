#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

template <typename T>
int add(T arr[],int& len,T e)
{
   arr[len]=e;
   len++;
   return len--;
}

template <typename T>
void insert(T arr[],int& len,T e,int p)
{
   int i=0;
   len++;
   for(i=len;i>=p;i--)
   {
      arr[i]=arr[i-1];
   }
   arr[p-1]=e;
}

template <typename T>
T remove(T arr[],int& len,int p)
{
   T t=arr[p];
   for(int i=p;i<len;i++)
   {
      arr[i]=arr[i+1];
   }
   len--;
   return t;
}

template <typename T, typename K>
int find(T arr[],int len,K k,int cmpTK(T,K))
{
   int i=0;
   while(i<len and cmpTK(arr[i],k)!=0)
   {
      i++;
   }
   if(i<len and cmpTK(arr[i],k)==0)
   {
      return i;
   }
   return -1;
}

template <typename T>
int orderedInsert(T arr[],int& len,T e,int cmpTT(T,T))
{
   int pos;
   int i=0;
   T a=arr[i];
   if(e<arr[i])
   {
      insert <T>(arr,len,e,i++);
      pos=i;
      return pos;
   }
   while(i<len)
   {
      if(cmpTT(a,e)>0)
      {
         insert <T>(arr,len,e,i);
         pos=i;
         return pos;
      }
      i++;
   }
   return add<T>(arr,len,e);

}


template <typename T>
void sort(T arr[],int len,int cmpTT(T,T))
{
   //ordena elems alfabeticamente de un coll string
   //ordena de mayor a menor los int
   bool ordenado=false;
   while(!ordenado)
   {
      ordenado=true;
      int i=0;
      while(i<len)
      {
         if(cmpTT(arr[i],arr[i+1])>0)//a<b
         {
            T a=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=a;
            ordenado=false;
         }
         i++;
      }
   }
}



#endif
