#include "Palabras.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

/* ---- FUNCIONES PRIMITIVAS --- */

Palabras CrearPalabras(){
  Palabras p = NULL;
  return p;
}

void insertarPalabraPrincipio(Palabras &palabra, Cadena cadenaPalabra){
    Palabras aux = new _palabra;
    aux->pal = cadenaPalabra;
    aux->ptrPalabras = palabra;
    palabra = aux;
    puts(aux->pal);
}

void insertarPalabraFinal(Palabras &palabra){
    Palabras Final = palabra;
    Palabras aux = new _palabra;
    while (Final->ptrPalabras !=NULL){
        Final= Final->ptrPalabras;
    }
    aux->ptrPalabras = NULL;
    Final->ptrPalabras=aux;
}


bool palabraEsVacia(Palabras palabra){

    if (palabra==NULL){
    return true;
    }
return false;
}

TipoRetorno InsertarPalabra(Palabras &palabra, Posicion posicionPalabra, Cadena palabraAIngresar) {


    Palabras aux = palabra;
    int contar = 0;

    while(palabra != NULL){
        printf("\n ENTRE AL WHILE DE SI LA PALABRA ES VACIA");
        palabra = palabra->ptrPalabras;
        contar++ ;
        printf("CANTIDAD DE PALABRAS: %d", contar);
    }

    if (palabra==NULL){
        insertarPalabraPrincipio(palabra, palabraAIngresar);

        printf("PALABRA INGRESADA CORRECTAMENTE.. \n");
        ImprimirPalabras(palabra);
        return OK;
    } else{

    if((posicionPalabra >= 1) && (posicionPalabra <= contar)){
            aux = palabra;
            for (int i=0; aux!=NULL; i++){
                    while(i=posicionPalabra){
                        Palabras nueva = new _palabra;
                        nueva ->ptrPalabras = aux->ptrPalabras;
                        aux->ptrPalabras = nueva;
                        return OK;
                    }
                aux = aux->ptrPalabras;
            }
                return OK;
    }else{
        printf("Mas de la cantidad de palabras, cero o menos... \n");
        return ERROR;
    }
  return OK;
}

}
TipoRetorno BorrarPalabra(Palabras &palabras, Posicion posicionPalabra) {
  return NO_IMPLEMENTADA;
}

TipoRetorno BorrarOcurrenciasPalabra(Palabras &palabras, Cadena palabraABorrar) {
  return NO_IMPLEMENTADA;
}

void BorrarTodoPalabras(Palabras &palabras) {

}

void ImprimirPalabras(Palabras palabras) {
    while (palabras !=NULL){
                puts(palabras->pal);
                palabras = palabras->ptrPalabras;
            }

        }


unsigned int CantidadPalabras(Palabras palabras) {
  return 0;
}

TipoRetorno PalabraEnPosicion(Palabras palabras, Posicion posicionPalabra, Cadena &palabra) {
  return NO_IMPLEMENTADA;
}

/** -----------------Para Parte 2----------------------**/

TipoRetorno ImprimirPalabrasIncorrectas(Palabras palabras, Diccionario D) {
  return NO_IMPLEMENTADA;
}

