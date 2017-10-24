#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include "Texto.h"
#include "Diccionario.h"


void menu(){
    printf("Estructuras de Datos y Algoritmos - Obligatorio 1\n");
    printf("PROCESADOR DE TEXTOS\n\n");
    printf("Lista de operaciones disponibles:\n");
    printf("1)  InsertarLinea\n");
    printf("2)  InsertarLineaEnPosicion\n");
    printf("3)  BorrarLinea\n");
    printf("4)  BorrarTodo\n");
    printf("5)  BorrarOcurrenciasPalabraEnTexto\n");
    printf("6)  ImprimirTexto\n");
    printf("7)  ComprimirTexto\n");
    printf("8)  InsertarPalabra\n");
    printf("9)  BorrarPalabra\n");
    printf("10) BorrarOcurrenciasPalabraEnLinea\n");
    printf("11) ImprimirLinea\n");
    printf("12) IngresarPalabraDiccionario\n");
    printf("13) BorrarPalabraDiccionario\n");
    printf("14) ImprimirDiccionario\n");
    printf("15) ImprimirTextoIncorrecto\n");
    printf("16) ImprimirUltimasPalabras\n");
    printf("17) Salir\n\n");
    printf("Ingrese el numero de la operacion a realizar: ");
}
void imprimirResultado(int retorno) {
     switch(retorno){
        case 0:
             printf("Resultado: OK \n");
             break;
        case 1:
             printf("Resultado: ERROR \n");
             break;
        case 2:
             printf("Resultado: NO_IMPLEMENTADA \n");
             break;
     }
}





int main()
{

    Texto texto = CrearTexto();
    Diccionario D = CrearDiccionario();
    Palabras palabra = CrearPalabras();
    int numOper = 0;
    bool salir = false;
    TipoRetorno retorno = NO_IMPLEMENTADA;
    Posicion posicionLinea = 0;
    Posicion posicionPalabra = 0;
    char opcion = 'n';
    Cadena palabraAux = NULL;
    do {
        menu();
        scanf("%d",&numOper);
        switch (numOper){
            case 1:
                  retorno = InsertarLinea(texto);
                 // imprimirResultado(retorno);
                  break;
           case 2:
                  printf("Ingrese la posicion de la nueva linea (debe ser >= 1 y <= cant lineas + 1): \n");
                  //fflush(stdin);
                  scanf("%d",&posicionLinea);
                  //fflush(stdin);
                  retorno = InsertarLineaEnPosicion(texto,posicionLinea);
                  //imprimirResultado(retorno);
                  break;
           case 3:
                  printf("Ingrese la posicion de la linea a borrar (debe ser >= 1 y <= cant lineas): \n");
                 // fflush(stdin);

                  scanf("%d",&posicionLinea);
                  retorno = BorrarLinea(texto,posicionLinea);
                  //imprimirResultado(retorno);
                  break;
           case 4:
                  printf("Esta seguro de que desea borrar todas las lineas del texto (s/n)?: \n");
                 // fflush(stdin);
                  scanf("%c",&opcion);
                  if (opcion == 's' || opcion == 'S'){
                     retorno = BorrarTodo(texto);
                     imprimirResultado(retorno);
                  }
                  break;
           case 5:
                  printf("Ingrese la palabra que desea borrar: \n");
                  palabraAux = new char [MAX_LARGO_PALABRA];
                 // fflush(stdin);
                  scanf("%c",&palabraAux);
                  retorno = BorrarOcurrenciasPalabraEnTexto(texto, palabraAux);
                  imprimirResultado(retorno);
                  delete palabraAux;
                  break;
           case 6:
                  retorno = ImprimirTexto(texto);
                  imprimirResultado(retorno);
                  break;
           case 7:
                  retorno = ComprimirTexto(texto);
                  imprimirResultado(retorno);
                  break;
           case 8:
                  printf("Ingrese la palabra que desea agregar: \n");
                  palabraAux = new char [MAX_LARGO_PALABRA];
                  fflush(stdin);
                  gets(palabraAux);
                  printf("Ingrese la posicion de la linea donde la va a agregar (debe ser >= 1 y <= cant lineas): \n");
                  fflush(stdin);
                  scanf(" %d",&posicionLinea);
                  printf("Ingrese la posicion que debe tener la palabra dentro de las palabras de la linea (debe ser >= 1 y <= cant palabaras en la linea + 1): \n");
                  fflush(stdin);
                  scanf(" %d",&posicionPalabra);
                  retorno = InsertarPalabraEnLinea(texto, posicionLinea, posicionPalabra, palabraAux);
                  imprimirResultado(retorno);
                  //delete palabraAux;
                  break;
           case 9:
                  printf("Ingrese la posicion de la linea donde se encuentra la palabra a borrar (debe ser >= 1 y <= cant lineas): \n");
                  fflush(stdin);
                  scanf("%d",&posicionLinea);
                  printf("Ingrese la posicion de la palabra a borrar (debe ser >= 1 y <= cant palabaras en la linea): \n");
                  fflush(stdin);
                  scanf("%d",&posicionPalabra);
                  retorno = BorrarPalabraEnLinea(texto,posicionLinea,posicionPalabra);
                  imprimirResultado(retorno);
                  break;
           case 10:
                  printf("Ingrese la palabra que desea borrar: \n");
                  palabraAux = new char [MAX_LARGO_PALABRA];
                 // fflush(stdin);
                  scanf("%c",&palabraAux);
                  printf("Ingrese la posicion de la linea donde se debe borrar la palabra (debe ser >= 1 y <= cant lineas): \n");
                 // fflush(stdin);
                  scanf("%d",&posicionLinea);
                  retorno =  BorrarOcurrenciasPalabraEnLinea(texto,posicionLinea,palabraAux);
                  imprimirResultado(retorno);
                  delete palabraAux;
                  break;
           case 11:
                  printf("Ingrese la posicion de la linea que desea imprimir (debe ser >= 1 y <= cant lineas): \n");
                  //fflush(stdin);
                  posicionLinea = 0;
                  scanf("%d",&posicionLinea);
                  retorno =  ImprimirLinea(texto, posicionLinea);
                  imprimirResultado(retorno);
                  break;
           case 12:
                  printf("Ingrese la palabra que desea agregar al diccionario: \n");
                  palabraAux = new char [MAX_LARGO_PALABRA];
                 // fflush(stdin);
                  scanf("%c",&palabraAux);
                  retorno = IngresarPalabraDiccionario(D,palabraAux);
                  imprimirResultado(retorno);
                  // delete palabraAux;
                  break;
           case 13:
                  printf("Ingrese la palabra que desea borrar del diccionario: \n");
                  palabraAux = new char [MAX_LARGO_PALABRA];
               //   fflush(stdin);
                  scanf("%c",&palabraAux);
                  retorno = BorrarPalabraDiccionario(D, palabraAux);
                  imprimirResultado(retorno);
                  delete palabraAux;
                  break;
           case 14:
                  retorno =  ImprimirDiccionario(D);
                  imprimirResultado(retorno);
                  break;
           case 15:
                  //retorno = ImprimirTextoIncorrecto(texto, D);
                  //imprimirResultado(retorno);
                  break;
           case 16:
                  //retorno =  ImprimirUltimasPalabras(texto);
                  //imprimirResultado(retorno);
                  break;
           case 17:
                  printf("Esta seguro de que desea salir (s/n)?: \n");
                  scanf("%c",&opcion);
                  if (opcion == 's' || opcion == 'S'){
                     printf("Saliendo...\n");
                     salir = true;
                  }
                  break;
           default:
                   printf("No ingreso una opcion valida, vuelva a intentarlo...\n");
                   getchar();
        }
        printf("\n");
        printf("Presione Enter Para continuar");
        getchar();
       // system("clear");
    } while (!salir);
    return 0;
}


