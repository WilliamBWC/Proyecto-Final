// Proyecto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
using namespace std;

//Se usará una libreria visual
//Realizará compras y les guardará un registro
//Permitirá consultar ventas previas

//cada registro tendrá:
// Número de venta, (primary key)
// Nombre del cliente
// Los artículos con su precio (articulo.nombre, articulo.precio)
// Total e impuestos (IVA)
// Determinar si el pago será con efectivo o tarjeta
// Si el pago es en efectivo, mostrar la cantidad ingresada y su cambio
// Fecha y hora de compra (libreria ctime)


#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define maxprod 100
#define maxcli 200
#define maxfact 200
 
typedef struct
{
    int dia;
    char mes[10];
    int anio;
}tipofecha;
 
typedef struct
{
	char codigo[5];
	char nombre[20];
	char descripcion[100];
	float precio;
	int cantidad;
	float valor_general;
	tipofecha vencimiento;
}tipoproducto;
 
typedef struct
{
	char codigo[5];
	char nombre[40];
	char direccion[40];
	char ciudad[40];
	char telefono[10];
	tipofecha ingreso;
}tipocliente;
 
typedef struct
{
	char codigo[5];
	char codigo_cliente[5];
	tipoproducto venta[10];
	//float cantidad;
	float total;
	tipofecha generacion;
}tipofactura;
 
void menu();
void registrarprod(tipoproducto *vector, tipoproducto productox, int pos);
void registrarcli(tipocliente *vector, tipocliente clienteN, int pos);
void buscarprod(tipoproducto *vector, char nombrebuscar[30], int tamanio);
void buscarcli(tipocliente *vector, char nombrebuscar[30], int tamanio);
void registrarfact(tipofactura *vector, tipofactura facturaf, int pos);
void buscarfact(tipofactura *vector, char codigobuscar[5], int tamanio, int auxprod);
 
int main()
{
    tipoproducto vectorproductos[maxprod];
    tipocliente vectorclientes[maxcli];
    tipofactura vectorfacturas[maxfact];
    int tamanio1=0, tamanio2=0, tamanio3=0, opcion, aux;
 
    do
    {
     system("CLS");
     menu();
     printf("\n\n Opcion : ");
     scanf("%d", &opcion);
     printf("\n");
     tipoproducto productox;
     tipocliente clienteN;
     tipofactura facturaf;
     system("CLS");
     switch(opcion)
     {
                  case 1:
                         if(tamanio1<maxprod)
                         {
                          printf("digite el codigo: ");
                          fflush(stdin);
                          gets(productox.codigo);
                          printf("digite el nombre: ");
                          fflush(stdin);
                          gets(productox.nombre);
                          printf("digite descripcion: ");
                          fflush(stdin);
                          gets(productox.descripcion);
                          printf("digite el precio: ");
                          scanf("%f", &productox.precio);
                           printf("digite fecha de vencimiento:");
                           printf("\n-dia: ");
                           scanf("%d", &productox.vencimiento.dia);
                           printf("-mes: ");
                           fflush(stdin);
                           gets(productox.vencimiento.mes);
                           printf("-anio: ");
                           scanf("%d", &productox.vencimiento.anio);
 
 
                          registrarprod(vectorproductos, productox, tamanio1);
                          tamanio1++;
 
                         }
                         else
                         printf("no hay espacio");
 
                  break;
 
                  case 2:
                         if(tamanio2<maxcli)
                         {
                          printf("digite el codigo: ");
                          fflush(stdin);
                          gets(clienteN.codigo);
                          printf("digite el nombre: ");
                          fflush(stdin);
                          gets(clienteN.nombre);
                          printf("digite direccion de residencia: ");
                          fflush(stdin);
                          gets(clienteN.direccion);
                          printf("digite ciudad de residencia: ");
                          fflush(stdin);
                          gets(clienteN.ciudad);
                          printf("digite telefono: ");
                          fflush(stdin);
                          gets(clienteN.telefono);
                          printf("digite fecha de ingreso: ");
                          printf("\n-dia: ");
                          scanf("%d", &clienteN.ingreso.dia);
                          printf("-mes: ");
                          fflush(stdin);
                          gets(clienteN.ingreso.mes);
                          printf("-anio: ");
                          scanf("%d", &clienteN.ingreso.anio);
                          registrarcli(vectorclientes, clienteN, tamanio2);
                          tamanio2++;
                         }
                         else
                         printf("no hay espacio");
                  break;
 
                  case 3:
                         printf("digite el nombre del producto a buscar: ");
                         fflush(stdin);
                         gets(productox.nombre);
                         buscarprod(vectorproductos, productox.nombre, tamanio1);
                         system("PAUSE");
                  break;
 
                  case 4:
                         printf("digite el nombre del cliente a buscar: ");
                         fflush(stdin);
                         gets(clienteN.nombre);
                         buscarcli(vectorclientes, clienteN.nombre, tamanio2);
                         system("PAUSE");
                  break;
 
                  case 5:
                         if(tamanio3<maxfact)
                         {
						  int contc, contp, cont;
                          float cantidad;
                          char seguir[5];
                          facturaf.total=0;
                          printf("digite el codigo de la factura: ");
                          fflush(stdin);
                          gets(facturaf.codigo);
                          for(contc=0; contc<tamanio2; contc++);
                          {
                                       printf("digite el codigo del cliente: ");
                                       fflush(stdin);
                                       gets(facturaf.codigo_cliente);
                                       if(strcmp(facturaf.codigo_cliente, vectorproductos[contc].codigo)==0)
                                       continue;
 
                          }
                         printf("tipo de productos a comprar: ");
                         scanf("%d", &aux);
                         for(cont=0; cont<aux; cont++)
                         {
                         	for(contp=0; contp<tamanio1; contp++);
                          {
                                       printf("digite el codigo del producto: ");
                                       fflush(stdin);
                                       gets(facturaf.venta[aux].codigo);
                                       if(strcmp(facturaf.venta[aux].codigo, vectorproductos[contp].codigo)==0)
                                       {
                                       	strcpy(facturaf.venta[aux].nombre, vectorproductos[contp].nombre);
									   	facturaf.venta[aux].precio=vectorproductos[contp].precio;
									   	printf("digite cantidad llevada del producto: ");
									   	scanf("%d", facturaf.venta[aux].cantidad);
									   	facturaf.venta[aux].valor_general=facturaf.venta[aux].precio*facturaf.venta[aux].cantidad;
									   	facturaf.total+=facturaf.venta[aux].valor_general;
									   	continue;
									   }
						 }
					}
 
 
                          printf("digite fecha de generacion: ");
                          printf("\n-dia: ");
                          scanf("%d", &facturaf.generacion.dia);
                          printf("-mes: ");
                          fflush(stdin);
                          gets(facturaf.generacion.mes);
                          printf("-anio: ");
                          scanf("%d", &facturaf.generacion.anio);
                          registrarfact(vectorfacturas, facturaf, tamanio3);
 
                          tamanio3++;
 
						 }
 
						 else
                         printf("no hay espacio");
                  break;
 
                  case 6:
                         printf("digite codigo del recibo a buscar: ");
                         fflush(stdin);
                         gets(facturaf.codigo);
                         buscarfact(vectorfacturas, facturaf.codigo, tamanio3, aux);
 
 
                         system("PAUSE");
 
                  break;
 
                  case 7:
                         printf("Hasta luego");
                  break;
 
                  deafult:
                          printf("ERROR, opcion no encontrada");
                  break;
     }
    }while(opcion!=7);
 
    getch();
    return 0;
}
 
void menu()
{
     printf("\n\t   Tienda anonimos           ");
     printf("\n######################################");
     printf("\n\n 1.- ingresar nuevo producto");
     printf("\n\n 2.- ingresar nuevo cliente");
     printf("\n\n 3.- buscar producto");
     printf("\n\n 4.- buscar cliente");
     printf("\n\n 5.- generar factura de venta");
     printf("\n\n 6.- buscar factura de una venta");
     printf("\n\n 7.- Salir");
 
}
void registrarprod(tipoproducto *vector, tipoproducto productox, int pos)
{
     vector[pos]=productox;
}
 
void registrarcli(tipocliente *vector, tipocliente clienteN, int pos)
{
     vector[pos]=clienteN;
}
 
void buscarprod(tipoproducto *vector, char nombrebuscar[30], int tamanio)
{
     int pos, aux=0;
     for(pos=0; pos<tamanio; pos++)
     {
      if(strcmp(vector[pos].nombre, nombrebuscar)==0)
      {
        aux=1;
        printf("codigo: ");
        puts(vector[pos].codigo);
        printf("\nnombre: ");
        puts(vector[pos].nombre);
        printf("descripcion: ");
        puts(vector[pos].descripcion);
        printf("precio: %.1f", vector[pos].precio);
        printf("\nfecha de vencimiento: ");
        printf("\n-dia: %d", vector[pos].vencimiento.dia);
        printf("\n-mes: ");
        puts(vector[pos].vencimiento.mes);
        printf("-anio: %d", vector[pos].vencimiento.anio);
        printf("\n");
      }
     }
     if(aux==0)
     printf("producto no se encontro");
}
 
void buscarcli(tipocliente *vector, char nombrebuscar[30], int tamanio)
{
     int pos, aux=0;
     for(pos=0; pos<tamanio; pos++)
     {
      if(strcmp(vector[pos].nombre, nombrebuscar)==0)
      {
        aux=1;
        printf("codigo: ");
        puts(vector[pos].codigo);
        printf("nombre: ");
        puts(vector[pos].nombre);
        printf("direccion: ");
        puts(vector[pos].direccion);
        printf("ciudad: ");
        puts(vector[pos].ciudad);
        printf("\nfecha de ingreso: ");
        printf("\n-dia: %d", vector[pos].ingreso.dia);
        printf("-mes: ");
        puts(vector[pos].ingreso.mes);
        printf("-anio: %d", vector[pos].ingreso.anio);
        printf("\n");
      }
     }
     if(aux==0)
     printf("cliente no se encontro");
}
 
 
void registrarfact(tipofactura *vector, tipofactura facturaf, int pos)
{
     vector[pos]=facturaf;
}
 
void buscarfact(tipofactura *vector, char codigobuscar[5], int tamanio, int auxprod)
{
     int pos, aux=0, cont;
     for(pos=0; pos<tamanio; pos++)
     {
      if(strcmp(vector[pos].codigo, codigobuscar)==0)
      {
        aux=1;
        printf("codigo factura: ");
        puts(vector[pos].codigo);
        printf("codigo cliente: ");
        puts(vector[pos].codigo_cliente);
        for(cont=0; cont<auxprod; cont++)
        {
        printf("codigo producto: ");
        puts(vector[pos].venta[cont].codigo);
        printf("nombre: ");
        puts(vector[pos].venta[cont].nombre);
        printf("precio: %.1f", vector[pos].venta[cont].precio);
        printf("\ncantidad : %1.f", vector[pos].venta[cont].cantidad);
    	}
        printf("\nsaldo de venta realizada: %.1f", vector[pos].total);
        printf("\nfecha de generacion: ");
        printf("\n-dia: %d", vector[pos].generacion.dia);
        printf("\n-mes: ");
        puts(vector[pos].generacion.mes);
        printf("-anio: %d", vector[pos].generacion.anio);
        printf("\n");
      }
     }
     if(aux==0)
     printf("factura no se encontro");
}

