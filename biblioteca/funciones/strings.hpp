#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

inline int length(string s)
{
   //cuenta los caracteres de s.
   int i=0;
   while(s[i]!='\0')
   {
      i++;
   }
  return i;
}

inline int charCount(string s,char c)
{
   //cuenta las veces q aparece c en s.
   int a=0;
   int i=0;
      while(s[i]!='\0')
      {
         if(s[i]==c)
         {
            a++;
         }
         i++;
      }
     return a;
}

inline string substring(string s,int d,int h)
{
   //retorna s entre d(include) y h (no include)
   string g="";
   int i=d;
   while(i<h)
   {
      g=g+s[i];
      i++;
   }
   return g;
}

inline string substring(string s,int d) // ok
{
   //retorna s desde d(include).
   string g="";
      int i=d;
      while(s[i]!='\0')
      {
         g=g+s[i];
         i++;
      }
   return g;
}

inline int indexOf(string s,char c) // ok
{
   //retorna posicion de la 1ra ocurrencia de c en s.
      int i=0;
         while(s[i]!=c and s[i]!='\0')
         {
            i++;
         }
         if(s[i]!=c and s[i]=='\0')
         {
            return -1;
         }
   return i;
}

inline int indexOf(string s,char c,int offSet) // ok
{
   //busca c en s desde offset
   int i=offSet;
   while(s[i]!=c and s[i]!='\0')
   {
      i++;
   }
   if(s[i]!=c and s[i]=='\0')
   {
      return -1;
   }
   return i;
}

inline int indexOf(string s,string toSearch) // ok
{
   //retorna la 1ra posicion de la cadena toSearch si s la contiene
   int i=0, a=0;
   while(s[i]!='\0')
   {
      if(s[i]==toSearch[a])
      {
         string h="";
         while(s[i]==toSearch[a] and s[i]!='\0' and toSearch[a]!='\0')
         {
            h=h+s[i];
            i++, a++;
         }
         if(h==toSearch)
         {
            return i-=a;
         }
         a=0;
      }
      i++;
   }
   return -1;
}

inline void permutaInt(int& a, int& b)
{
   int aux=a;
   a=b;
   b=aux;
}

inline void permutaStr(string& a, string& b)
{
   string aux=a;
   a=b;
   b=aux;
}

inline int indexOf(string s,string toSearch,int offset) // ok
{
   //retorna la 1ra posicion de la cadena toSearch desde offset si s la contiene
   int i=offset;
   string t=substring(s,i);
   int pos=indexOf(t,toSearch);
   int a=length(s);
   int b=length(t);
   if(pos>=0)
   {
      i=a-b+pos;
      return i;
   }
   return -1;
}

inline int lastIndexOf(string s,char c)
{
   //retorna la ultima aparicion de c en s.
   int i=length(s)-1;
    while(s[i]!=c and i>0)
    {
       i--;
    }
    if(s[i]!=c and i<=0)
    {
       return -1;
    }
   return i;
}

inline int indexOfN(string s,char c,int n)
{
   //retorna la posicion de la aparicion num n de c en s.
   int i=0;
   int a=0;
   while(a<n and s[i]!='\0')
   {
            while(s[i]!=c and s[i]!='\0')
            {
               i++;
            }
            if(s[i]==c and s[i]!='\0')
            {
               a++;
               i++;
            }
   }
   if(a<n and s[i]=='\0')
   {
      return -1;
   }

   return i;
}

inline int charToInt(char c)
{
   //pasa un char a int.
   int i=0;
   int a=48;
   while((char)a!=c)
   {
     a++;
     i++;
   }

   return i;
}

inline char intToChar(int i)
{
   //convierte un int(entre 0-9 o 65-90) en un char.
   char b=48;
   int a=0;
   if(i>=65)
   {
      a=48;
   }
   while(a<i)
   {
      a++;
      b++;
   }

   return b;
}

inline int getDigit(int n,int i)
{
   //retorna el digito en la posicion i de n
   int a;
   int b=0;
   if(n<0)
   {
      n=n*-1;
   }
   a=n%10;
   while(b<i)
   {
      n=n/10;
      a=n%10;
      b++;
   }

   return a;
}

inline int digitCount(int n)
{
   //retorna la cantidad de digitos de n.
   int i=0;
   if(n<0)
   {
      n=n*(-1);
   }
   while(n>0)
   {
      n=n/10;
      i++;
   }
   return i;
}

inline string intToString(int i)
{
   //pasa un int a string
   string h="";
   string g="";
   int n;
      if(i<0)
      {
         i=i*(-1);
         h=h+(char)45;
      }
      while(i>0)
      {
         n=i%10;
         char c=intToChar(n);
         g=g+c;
         i=i/10;
      }
      int d=length(g)-1;
      while(d>=0)
      {
         h=h+g[d];
         d--;
      }
   return h;
}

inline int stringToInt(string s,int b) // ok
{
   //pasa un string a int multiplicando cada posicion x b elevado a la vez n iterado
   int r=0;
   int d=1;
   for(int i=length(s)-1;i>=0;i--)
   {
      if(s[i]==(char)45)
      {
         r=r*-1;
         return r;
      }
      char a=s[i];
      int c=charToInt(a);
      c=c*d;
      r=r+c;
      d=d*b;
   }

   return r;
}

inline int stringToInt(string s) // ok
{
   //retorna el s como int multiplicandolo x10 elevado a las veces iterado
   return stringToInt(s,10);
}

inline string charToString(char c)
{
   //pasa el char a un string de longitud 1
   string g="";
   g=g+c;
   return g;
}

inline char stringToChar(string s)
{
   //pasa un string de length 1 a char
   char c=s[0];
   return c;
}

inline string stringToString(string s)
{
   //pasa un string a string
   string g="";
   for(int i=0;s[i]!='\0';i++)
   {
      g=g+s[i];
   }
   return g;
}

inline string doubleToString(double d)
{
   //pasa un double a string
   string s="";
   if(d<0)
   {
      s=s+(char)45;
      d=d*-1;
   }
   string g=intToString(d);
   s=s+g+(char)46;
   d=d-(int)d;
   d=d*10000;
   string e=intToString(d);
   s=s+e;
   return s;
}

inline double stringToDouble(string s)
{
   //pasa un string a double
   double d=0;
   int i=0;
   if(s[i]=='-')
   {
      i++;
   }
   string g="";
   while(s[i]!='\0' and s[i]!='.')
   {
      g=g+s[i];
      i++;
   }
   int p=0;
   while(s[i]!='\0')
   {
      i++;
      g=g+s[i];
      p++;
   }
   p--;
   int a=stringToInt(g,10);
   d=d+a;
   d=d/pow(10,p);//lo divido x los ceros q se ha movido.
   if(charCount(s,'-')==1)
   {
      d=d*-1;
   }

   return d;
}

inline bool isEmpty(string s)
{
   //verifica si el string es o no vacio
   bool r=false;
   if(s=="")
   {
      r=true;
   }
   return r;
}

inline bool startsWith(string s,string x)
{
   //verifica si s comienza con x
   bool r=false;
   string h=substring(s,0,length(x));
   if(x==h)
   {
      r=true;
   }
   return r;
}

inline bool endsWith(string s,string x)
{
   // verifica si s termina con x (implementacion segura usando longitudes)
   int ls = length(s);
   int lx = length(x);
   if(lx > ls) return false;
   string tail = substring(s, ls - lx, ls);
   return tail == x;
}

inline bool contains(string s,char c)
{
   //determ si s contiene a c
   bool r=false;
   if(charCount(s,c)==1)
   {
      r=true;
   }
   return r;
}

inline string replace(string s,char oldC,char newC)
{
   //reemplaza en s el oC c nC
   string g="";
   int i=0;
   while(s[i]!='\0' and s[i]!=oldC)
   {
      g=g+s[i];
      i++;
   }
   if(s[i]!='\0' and s[i]==oldC)
   {
      g=g+newC;
      i++;
   }
   while(s[i]!='\0')
      {
         g=g+s[i];
         i++;
      }
   return g;
}

inline string insertAt(string s,int pos,char c)
{
   //agrega c en s en la posicion pos
   string g="";
      int i=0;
      while(s[i]!='\0' and i<pos)
      {
         g=g+s[i];
         i++;
      }
      if(s[i]!='\0' and i==pos)
      {
         g=g+c;
      }
      while(s[i]!='\0')
         {
            g=g+s[i];
            i++;
         }
   return g;
}

inline string removeAt(string s,int pos)
{
   //remueve el caracter de s en la posicion pos
   string g="";
   int i=0;
   while(s[i]!='\0' and i<pos)
   {
      g=g+s[i];
      i++;
   }
   if(s[i]!='\0' and i==pos)
   {
      i++;
   }
   while(s[i]!='\0')
     {
        g=g+s[i];
        i++;
     }
   return g;
}

inline string ltrim(string s)
{
   //remueve los espacios a la izq de s
   string g="";
   int i=0;
   while(s[i]==(char)32 and s[i]!='\0')
   {
      i++;
   }
   while(s[i]!='\0')
   {
      g=g+s[i];
      i++;
   }

   return g;
}

inline string rtrim(string s)
{
   //remueve los espacios a la der de s
   string g="";
      int i=length(s)-1;
      while(s[i]==(char)32 and i>0)
      {
         i--;
      }
      g=substring(s,0,i+1);
   return g;
}

inline string trim(string s)
{
   //remueve los espacios de izq y der de s
   string h;
   string e=ltrim(s);
   h=rtrim(e);
   return h;
}

inline string replicate(char c,int n)
{
   //genera un string con n veces c
   string g="";
   int i=0;
   while(i<n)
   {
      g=g+c;
      i++;
   }
   return g;
}

inline string spaces(int n)
{
   //genera un string con n cant de espacios
   string g="";
      int i=0;
      while(i<n)
      {
         g=g+' ';
         i++;
      }
   return g;
}

inline string lpad(string s,int n,char c)
{
   //retorna s en la longitud n rellenando con c a la izq en caso de ser n mayor
   string g="";
   int i=0;
   if(n>length(s))
   {
      while(n>length(s))
      {
         g=g+c;
         n--;
      }
   }
   while(s[i]!='\0')
         {
            g=g+s[i];
            i++;
         }

   return g;
}

inline string rpad(string s,int n,char c)
{
   //retorna s en la longitud n rellenando con c a la der en caso de ser n mayor
   string g="";
      int i=0;
      while(i<n and s[i]!='\0')
      {
         g=g+s[i];
         i++;
      }
      if(n>length(s))
      {
         while(i<n)
         {
            g=g+c;
            i++;
         }
      }
      return g;
}

inline string cpad(string s,int n,char c)
{
   return "";
}
//es igual a lpad
inline bool isDigit(char c)
{
   //determ si c es un numero
   bool r=false;
   if(c>='0' and c<='9')
   {
      r=true;
   }
   return r;
}

inline bool isLetter(char c)
{
   //determ si c es una letra
   bool r=false;
      if((c>='A' and c<='Z') or (c>='a' and c<='z'))
      {
         r=true;
      }
   return r;
}

inline bool isUpperCase(char c)
{
   //determ si c es letra mayus
   bool r=false;
        if(c>='A' and c<='Z')
        {
           r=true;
        }
   return r;
}

inline bool isLowerCase(char c)
{
   //determ si c es letra minus
   bool r=false;
        if(c>='a' and c<='z')
        {
           r=true;
        }
   return r;
}

inline char toUpperCase(char c)
{
   //pasa c, letra minus, a mayus
   char a;
   int r=(int)c;
   if(c>='a' and c<='z')
   {
      r=r-32;
      a=(char)r;
   }
   return a;
}

inline char toLowerCase(char c)
{
   //pasa c, letra mayus, a minus
   char a;
      int r=(int)c;
      if(c>='A' and c<='Z')
      {
         r=r+32;
         a=(char)r;
      }
   return a;
}

inline string toUpperCase(string s)
{
   string g="";
   int i=0;
   while(s[i]!='\0')
   {
      char c=s[i];
      char a=toUpperCase(c);
      g=g+a;
      i++;
   }
   return g;
}

inline string toLowerCase(string s)
{
   string g="";
      int i=0;
      while(s[i]!='\0')
      {
         char c=s[i];
         char a=toLowerCase(c);
         g=g+a;
         i++;
      }
   return g;
}

inline int cmpInt(int t,int k) //creado
{
   //compara ints de coll
   return t-k;
}

inline int cmpStr(string t1, string t2)
{
   //compara strings de coll
   return t1<t2?-1:t1>t2?1:0;
}

inline int cmpDouble(double t,double k) //creado
{
   //compara ints de coll
   return t-k;
}

#endif
