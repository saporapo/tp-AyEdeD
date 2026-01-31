#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

inline int tokenCount(string s,char sep)//te dice cuantos tokens hay en base al numero de separadores
{
   int a=0;
   int i=0;
   while(s[i]!='\0')
   {
      if(s[i]=='|')
      {
         a++;
      }
      i++;
   }
   return a+1;
}

inline void addToken(string& s,char sep,string t)//añade un token nuevecito al final del string
{
   if(s=="")
   {
      s=s+t;
   }
   else
   {
      s=s+'|'+t;
   }
}

inline string getTokenAt(string s,char sep, int i)
{
   string r="";
   int pos=indexOfN(s,sep,i--);
   while(s[pos]!='\0' and s[pos]!='|')
   {
      r=r+s[pos];
      pos++;
   }
   return r;
}

inline void removeTokenAt(string& s,char sep, int i)
{
   string r="";
   int a=0;
   int b=0;
   if(i!=1)
{
   while(s[b]!='\0' and a!=i-1)
   {
      if(s[b]=='|')
      {
         a++;
      }
      r=r+s[b];
      b++;
   }
}
   while(s[b]!='\0' and s[b]!='|')
   {
      b++;
   }
   if(s[b]=='|')
   {
      while(s[b]!='\0')
      {
         r=r+s[b];
         b++;
      }
      s=r;
   }
else
{
   if(s[b]=='\0')
   {
      s=r;
   }
}

}

inline void setTokenAt(string& s,char sep,string t,int i)
{
   string r="";
   int a=0;
   int b=0;
   if(i!=1)
   {
      while(s[b]!='\0' and a!=i-1)
      {
         if(s[b]=='|')
         {
            a++;
         }
         r=r+s[b];
         b++;
      }
      r=r+t;
      if(s[b]=='\0')
      {
         s=r;
      }
      else
      {
         while(s[b]!='\0')
         {
            r=r+s[b];
            b++;
            s=r;
         }
      }
   }
   else
   {
      t=t+sep;
      while(s[b]!='\0')
      {
         t=t+s[b];
         b++;
      }
      s=t;
   }
}

inline int findToken(string s,char sep, string t)
{
//devuelve num de token
//con pos-- tengo el sep
   int pos=indexOf(s,t);
   string g=substring(s,0,pos);
   return pos=tokenCount(g,sep);
}

#endif
