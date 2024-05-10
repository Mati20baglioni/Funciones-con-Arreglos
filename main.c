#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
//LIBRERIA PARA EFECTUAR ASIGNACIONES DIRECTAS ENTRE CADENAS.
#include <string.h>
///PROTOTIPADOS:
//1
int CargarArreglo(int Uno[],int dimension);
//2
void MostrarArreglo(int ArregloCargado[],int Validos);
//3
int SumarArreglo(int ArregloCargado[],int Validos);
//4
void PasarArreglo_Pila(int ArregloCargado[], int Validos,Pila* A);
//5
int CargarArregloTipoFloat(float ArregloF[],int Dim);
void MostrarArregloFloat(float ArregloFcargado[],int validos);
float SumarArregloFloat(float ArregloFloat[],int validos);
//6
int CargarArregloTipoChar(char ArregloChar[],int Dimension);
void MostrarArregloChar(char ArregloC[],int validos);
char BuscarEnArregloC(char ArregloC[],int validos,char caracter);
//7
void IngresarCaracterEn_Arreglo(char abc[] ,int validos,char caracter);
//8
char CaracterMax(char ArregloC[],int Validos);
//9
void Capicua(int Arreglo[],int validos);
//10
void InvertirArreglo(int Arreglo[],int validos);
//11
int Encontrar_Menor(int Uno[],int validos);
void ordenamiento_seleccion(int a[],int validos);

///Trabajo Práctico N° 3: Arreglos
int main()
{
    /*INDICE DE LA CONSOLA*/
    printf("INDICE:\n");
    printf("(1)Cargar arreglo por teclado(Pasado por parametros):\n");
    printf("(2)Mostrar arreglo(Pasado por parametros):\n");
    printf("(3)Sumar elementos de un arreglo:\n");
    printf("(4)Pasar elementos de un arreglo a una pila:\n");
    printf("(5)Cargar y mostrar arreglo de tipo float y sumarlo:\n");
    printf("(6)Indique si un elemento dado se encuentra en un arreglo de caracteres\n");
    printf("(7)Realizar una funcion que inserte un caracter en un arreglo ordenado alfabeticamente,conservando el orden\n");
    printf("(8)Realizar una funcion que obtenga el maximo caracter de un arreglo dado\n");
    printf("(9)Realizar una funcion que determine si un arreglo es capicua\n");
    printf("(10)Realizar una funcion que invierta los elementos de un arreglo. (sin utilizar un arreglo auxiliar)\n");
    printf("(11)Ordenamiento por Seleccion\n");
    printf("(12)Ordenamiento por Insercion\n");
    printf("\n");
    printf("\n");
    /*
    printf("(13)Crear tercer arreglo con los elementos de los dos primeros intercalados de manera ordenada\n");
    printf("(14)Dado un vector escribir otro con la suma los anteriores\n");
    */

    //////////////////////////////////
    int op,Dimension,suma,PosMenor,Nuevo,PosMayor;
    int Opcion=0;
    float ValidosF,SumaF;
    char caracter,Caracter;

    int Uno[20];
    float Dos[100];
    char Tres[10];
    char abc[]={'a','e','i','o','u'};

    Pila A;
    inicpila(&A);

    int Inicio=0;
    int Validos=0;
    char control='s';
    //////////////////////////////////
    do
    {
        printf("\n");
        printf("INGRESE EL NUMERO DE LA OPERACION:\n");
        scanf("%i",&op);
        fflush(stdin);
        switch(op)
        {
        case 1:
            Validos=CargarArreglo(Uno,20);
            printf("LA CANTIDAD DE VALIDOS:%i\n",Validos);

            break;

        case 2:

            MostrarArreglo(Uno, Validos);

            break;

        case 3:

            suma=SumarArreglo(Uno,Validos);
            printf("LA SUMA DEL ARREGLO ES:%i\n",suma);

            break;

        case 4:

            PasarArreglo_Pila(Uno,Validos,&A);

            break;

        case 5:
            ValidosF=CargarArregloTipoFloat(Dos,100);
            MostrarArregloFloat(Dos,ValidosF);
            SumaF=SumarArregloFloat(Dos,ValidosF);
            printf("EL VALOR TOTAL DEL ARREGLO:%f\n",SumaF);
            break;

        case 6:
            Validos=CargarArregloTipoChar(Tres,10);
            MostrarArregloChar(Tres,Validos);
            printf("\n");
            printf("INGRESE EL CARACTER QUE DESEA BUSCAR EN EL ARREGLO:\n");
            scanf(" %c", &caracter);
            BuscarEnArregloC(Tres,Validos,caracter);
            break;

        case 7:
            printf("INGRESE UNA LETRA:\n");
            fflush(stdin);
            scanf("%c",&Caracter);
            Validos=5;
            IngresarCaracterEn_Arreglo(abc,Validos,Caracter);
            Validos++;
            MostrarArregloChar(abc,Validos);
            break;

        case 8:
             Validos=CargarArregloTipoChar(Tres,10);
             MostrarArregloChar(Tres,Validos);
             PosMayor=CaracterMax(Tres,Validos);
             printf("EL MAYOR CARACTER DEL ARREGLO ES:\n");
             printf("|%c|",PosMayor);
            break;

        case 9:
            Validos=CargarArreglo(Uno,20);
            printf("LA CANTIDAD DE VALIDOS:%i\n",Validos);
            MostrarArreglo(Uno, Validos);
            Capicua(Uno,Validos);
            break;

        case 10:
            InvertirArreglo(Uno,Validos);
            break;

        case 11:
             ordenamiento_seleccion(Uno,Validos);
            break;

        case 12:

            break;

        case 13:

            break;
        case 14:

            break;

        default:
            printf("OPCION NO VALIDA:\n");
            printf("INGRESE UN NUMERO DEL 1 AL 13:\n");
            scanf("%i",&op);
        }
        printf("\n");
        printf("DESEA VER OTROS CASOS PRESIONE s/n:\n");
        fflush(stdin);
        scanf("%c",&control);

    }
    while(control=='s');

    return 0;
}

/*FUNCION 1:
Hacer una función que reciba como parámetro un arreglo de números enteros y permita que
el usuario ingrese valores al mismo por teclado. La función debe retornar la cantidad de
elementos cargados en el arreglo (o pueden utilizar como puntero válidos).
*/

int CargarArreglo(int Uno[], int dimension)
{
    int validos = 0;
    char control = 's';
    while(control == 's' && validos < dimension)
    {
        printf("INGRESE UN NUMERO:\n");
        fflush(stdin);
        scanf("%i",&Uno[validos]);
        validos++;
        printf("DESEA CONTINUAR s/n;\n");
        fflush(stdin);
        scanf("%c",&control);
    }
    return validos;
}

/*FUNCION 2:
Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos)
cargados en él y los muestre por pantalla.*/

void MostrarArreglo(int ArregloCargado[],int Validos)
{
    if (Validos == 0)
    {
        printf("NO HAY ELEMENTOS VALIDOS EN EL ARREGLO:\n");
    }

    printf("ELEMENTOS DEL ARREGLO:\n");
    for (int i = 0; i < Validos; i++)
    {
        printf("|%i|", ArregloCargado[i]);
    }
    printf("\n");
}

/*FUNCION 3:
Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos)
cargados en él y calcule la suma de sus elementos.
*/
int SumarArreglo(int ArregloCargado[], int Validos)
{
    int i=0;
    int suma = 0;
    for( i=0 ; i<Validos ; i++)
    {
        suma += ArregloCargado[i];
    }

    return suma;

}

/*FUNCION 4:
Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos)
cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.
*/
void PasarArreglo_Pila(int ArregloCargado[], int Validos, Pila* A)
{
    int i;
    for( i=0 ; i<Validos ; i++)
    {
        apilar( A,ArregloCargado[i]);
    }
    mostrar(A);
}
/*
FUNCION 5:
Realizar una función que sume los elementos de un arreglo de números reales (float) de
dimensión 100. (se recomienda hacer una función para cargar y otra para mostrar para este
tipo de dato asociado al arreglo).
*/
int CargarArregloTipoFloat(float ArregloF[],int Dim)
{
    int validos = 0;
    char control = 's';
    printf("PARA INGRESAR DATOS DE TIPO FLOAT USAR EL .(PUNTO)\n");
    while((control == 's') && (validos < Dim ))
    {
        printf("CARGUE UN NUMERO:\n");
        scanf("%f",&ArregloF[validos]);
        validos++;
        printf("SEGUIR s/n;\n");
        fflush(stdin);
        scanf("%c",&control);
    }
    return validos;
}

void MostrarArregloFloat(float ArregloFcargado[],int validos)
{
    if (validos == 0)
    {
        printf("NO HAY ELEMENTOS VALIDOS EN EL ARREGLO:\n");
    }

    printf("ELEMENTOS DEL ARREGLO:\n");
    for (int i = 0; i < validos; i++)
    {
        printf("|%.1f|",ArregloFcargado[i]);
    }
    printf("\n");

}

float SumarArregloFloat(float ArregloFloat[],int validos)
{
    float resultado=0;

    for(int i=0;i<validos;i++)
    {
        resultado += ArregloFloat[i];
    }

 return resultado;
}

/*FUNCION 6:
Realizar una función que indique si un elemento dado se encuentra en un arreglo de
caracteres.
*/

int CargarArregloTipoChar(char ArregloChar[],int Dimension)
{
    char control='s';
    int validos=0;
    while(control=='s' && validos<Dimension)
        {
            printf("INGRESA UN CARACTER:\n");
            fflush(stdin);
            scanf("%c",&ArregloChar[validos]);
            validos++;
            printf("SEGUIR s/n \n");
            fflush(stdin);
            scanf("%c",&control);
        }
        return validos;
}

void MostrarArregloChar(char ArregloC[],int validos)
{
    if(validos==0)
        {
            printf("NO HAY ARREGLO PARA MOSTRAR:\n");
        }
        for(int i=0;i<validos;i++)
        {
            printf("|%c|",ArregloC[i]);
        }
        printf("\n");
}

char BuscarEnArregloC(char ArregloC[],int validos,char caracter)
{

    int encontrado = 0;
    for (int i = 0; i < validos; i++)
{
    if (ArregloC[i] == caracter)
    {
        encontrado = 1;
        break;
    }
}

if (encontrado)
{
    printf("EL CARACTER SE ENCUENTRA EN EL ARREGLO\n");
}
else
{
    printf("EL CARACTER NO SE ENCUENTRA EN EL ARREGLO\n");
}

}
/*FUNCION 7:
Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente,
conservando el orden.
*/
void IngresarCaracterEn_Arreglo(char abc[] ,int validos,char caracter)
{
    int i=0;
    while(i<validos && caracter>abc[i])
        {
            i++;
        }
    for(int p=validos;p>=i+1;p--)
    {
        abc[p]=abc[p-1];
    }

    abc[i]=caracter;



}

/*FUNCION 8:
Realizar una función que obtenga el máximo carácter de un arreglo dado.*/

char CaracterMax(char ArregloC[],int Validos)
{
    int i=1;
    char Mayor=ArregloC[0];
    while(i<Validos)
        {
            if(Mayor<ArregloC[i])
                {
                    Mayor=ArregloC[i];
                }
                i++;
        }
   return Mayor;

}
/*FUNCION 9:
Realizar una función que determine si un arreglo es capicúa.*/
void Capicua(int Arreglo[],int validos)
{
    int a=0;
    //le resto uno a los validos para empezar en la ultima posicion del arreglo.
    int z=validos-1;
    int flag=1;
    while( a<z && flag)
        {
            if(Arreglo[a]==Arreglo[z])
            {
                a++;
                z--;
            }
            else
                {
                flag=0;
                printf("EL ARREGLO NO ES CAPICUA\n");
                }
        }
        if(flag)
        {
          printf("EL ARREGLO ES CAPICUA\n");
        }

}
/*FUNCION 10:
Realizar una función que invierta los elementos de un arreglo. (sin utilizar un arreglo auxiliar)*/

void InvertirArreglo(int Arreglo[],int validos)
{
    int x=0;
    int z=validos-1;
    int intercambio;
    while(x<z)
        {
            intercambio=Arreglo[x];
            Arreglo[x]=Arreglo[z];
            Arreglo[z]=intercambio;
            x++;
            z--;
        }


}

/*FUNCION 11
 Ordenar un arreglo según los siguientes métodos:
a. Selección*/
///ORDENAMIENTO POR SELECCION:
int Encontrar_Menor(int Uno[],int validos)
{
    int inicio=0;
    int Menor=Uno[inicio];
    int PosicionMenor=inicio;
    int Aumento=PosicionMenor+1;

    while(Aumento<validos)
        {
            if(Menor>Uno[Aumento])
            {
                Menor=Uno[Aumento];
                PosicionMenor=Aumento;
            }
            Aumento++;
        }
    return PosicionMenor;
}
void ordenamiento_seleccion(int a[],int validos)
{
    int posmenor;
    int i=0;
    while (i < validos - 1)
        {
        posmenor = i;
        for (int j = i + 1; j < validos; j++)
        {
            if (a[j] < a[posmenor])
                {
                    posmenor = j;
                }
        int aux = a[posmenor];
        a[posmenor] = a[i];
        a[i] = aux;
        i++;
        }

        }
}
///ORDENAMIENTO POR INSERCION: HAY QUE HACERLO!!!!!!!!!!
void Insertar()
{


}
void Ordenamiento_Insercion()
{


}

void GUIA()///BASURAAAAA!!!!!
{
//GUIAS
/*
12. Dados dos arreglos ordenados alfabéticamente, crear un tercer arreglo con los elementos de
los dos primeros intercalados, de manera que quede un arreglo también ordenado
alfabéticamente.
13. Dado el vector {1,5,6,7,8} escribir un programa que genere otro vector con la suma del
contenido de todo los elementos anteriores al índice actual: {1,6,12,19,27}
*/
}
