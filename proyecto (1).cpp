
#ifndef _MAIN
#define _MAIN

#include <stdlib.h>
#include <stdio.h>
#include <string.h>// strcat
#include <iostream>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/arrays.hpp"
#include "biblioteca/funciones/lists.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/Array.hpp"
#include "biblioteca/tads/Map.hpp"
#include "biblioteca/tads/List.hpp"
#include "biblioteca/tads/Stack.hpp"
#include "biblioteca/tads/Queue.hpp"
#include "biblioteca/tads/Coll.hpp"
#include "biblioteca/tads/huffman/HuffmanSetup.hpp"
#include "biblioteca/tads/huffman/BitReader.hpp"
#include "principal.hpp"
using namespace std;

//   Node<int>* p = NULL;
//   add<int>(p,2);
//   add<int>(p,1);
//   add<int>(p,3); // p->{2,1,3}
//     Node<int>* q = NULL;
//     enqueue<int>(q,1); // p->{1}<-q
//     enqueue<int>(q,2); // p->{1,2}<-q
//     enqueue<int>(q,3); // p->{1,2,3}<-q
//     enqueue<int>(q,4);
//   sort<int>(p,cmpTT); // p->{1,2,3}
//   while(q!=NULL)
//   {
//      cout<<q->info<<endl;
//      q=q->sig;
//   }
//   if( !isEmpty<int>(p) )
//   {
//    cout << "la lista tiene elementos" << endl;
//   }
//   else
//   {
//      cout << "la lista no tiene elementos" << endl;
//   }
//   Node<int>* q = NULL;
//      add<int>(q,2);
//      add<int>(q,3);
//      add<int>(q,5);
//      orderedInsert<int>(q,1,cmpTT);
//      orderedInsert<int>(q,4,cmpTT);
//      orderedInsert<int>(q,6,cmpTT);
//         while(q!=NULL)
//         {
//            cout<<q->info<<endl; //2
//            q=q->sig;
//         }


struct Proyecto
{
 int idProyecto;
 char descripcion[100];
 int fechaInicio;
 int horasAsignadas;
 int horasImputadas;
};

struct Hora
{
 int idEmpleado;
 int idProyecto;
 int fecha;
 int horas;
 char tareas[200];
};

struct Empleado
{
 int idEmpleado;
 char nombre[50];
};

//struct REmpleado
//{
//   Empleado e;
//   char tareas[200];
//};

struct RProyecto
{
   Empleado e;
   char tareas[200];
   Proyecto p;
};

RProyecto rProyecto(Empleado e,string tareas,Proyecto p)
{
    RProyecto rProyectoVar;
    rProyectoVar.e=e;
    strcpy(rProyectoVar.tareas,tareas.c_str());
    rProyectoVar.p=p;
    return rProyectoVar;
}

Proyecto proyecto(int idProyecto,string descripcion,int fechaInicio,int horasAsignadas,int horasImputadas)
{
   Proyecto proyectoVar;
   proyectoVar.idProyecto=idProyecto;
   strcpy(proyectoVar.descripcion,descripcion.c_str());
   proyectoVar.fechaInicio=fechaInicio;
   proyectoVar.horasAsignadas=horasAsignadas;
   proyectoVar.horasImputadas=horasImputadas;
   return proyectoVar;
}

// hora - funcion de inicializacion para: Hora
Hora hora(int idEmpleado,int idProyecto,int fecha,int horas,string tareas)
{
   Hora horaVar;
   horaVar.idEmpleado=idEmpleado;
   horaVar.idProyecto=idProyecto;
   horaVar.fecha=fecha;
   horaVar.horas=horas;
   strcpy(horaVar.tareas,tareas.c_str());
   return horaVar;
}

// empleado - funcion de inicializacion para: Empleado
Empleado empleado(int idEmpleado,string nombre)
{
   Empleado empleadoVar;
   empleadoVar.idEmpleado=idEmpleado;
   strcpy(empleadoVar.nombre,nombre.c_str());
   return empleadoVar;
}

Array<Proyecto> subirProyectos()
{
   Array<Proyecto> arr = array<Proyecto>();

   FILE* f=fopen("PROYECTOS.dat","r+b");

   Proyecto p=read<Proyecto>(f);
   while(!feof(f))
   {
      arrayAdd<Proyecto>(arr,p);
      p = read<Proyecto>(f);
   }

   fclose(f);

   return arr;
}

Array<Empleado> subirEmpleados()
{
   Array<Empleado> arr = array<Empleado>();

   FILE* f=fopen("EMPLEADOS.dat","r+b");

   Empleado p=read<Empleado>(f);
   while(!feof(f))
   {
      arrayAdd<Empleado>(arr,p);
      p = read<Empleado>(f);
   }

   fclose(f);

   return arr;
}

int cmpIDemp(Empleado a,int b)
{
   return a.idEmpleado-b;
}

int cmpIDproy(Proyecto a,int b)
{
   return a.idProyecto-b;
}

void procesarPunto1(Hora h,Array<Proyecto> proy,Array<Empleado> emp,List<RProyecto> rProy)
{
   int pos=arrayFind<Empleado,int>(emp,h.idEmpleado,cmpIDemp);
   int id=emp.arr[pos].idEmpleado;
   string nom=emp.arr[pos].nombre;
   Empleado e=empleado(id,nom);
   pos=arrayFind<Proyecto,int>(proy,h.idProyecto,cmpIDproy);
   Proyecto p=proyecto(proy.arr[pos].idProyecto,proy.arr[pos].descripcion,proy.arr[pos].fechaInicio,proy.arr[pos].horasAsignadas,proy.arr[pos].horasImputadas);

   RProyecto rp=rProyecto(e,h.tareas,p);

   listAdd<RProyecto>(rProy,rp);

}

int main()
{
   //Emitir un listado indicando, para cada proyecto, qué
   //empleados trabajaron; y por cada uno, qué tareas
   //desarrolló. Ordenado por proyecto, luego por empleado, y
   //finalmente por fecha descendente.

   Array<Proyecto> proy=subirProyectos();
   Array<Empleado> emp=subirEmpleados();
   List<RProyecto> rProy=list<RProyecto>();

   FILE* f=fopen("HORAS.dat","r+b");

   Hora h=read<Hora>(f);
   while(!feof(f))
   {
      procesarPunto1(h,proy,emp,rProy);
      h=read<Hora>(f);
   }

   return 0;
}


#endif
