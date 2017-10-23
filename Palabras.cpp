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

void insertarPalabraFinal(Palabras &palabra, Cadena cadenaPalabra){
    Palabras Final = palabra;
    Palabras aux = new _palabra;
    aux->pal = cadenaPalabra;
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

    while(aux != NULL){
        printf("\n ENTRE AL WHILE DE SI LA PALABRA ES VACIA \n");
        aux = aux->ptrPalabras;
        contar++ ;
        printf("CANTIDAD DE PALABRAS: %d\n", contar);
    }

    if (contar==0){
        insertarPalabraPrincipio(palabra, palabraAIngresar);

        printf("PALABRA INGRESADA CORRECTAMENTE al principio era vacio.. \n");
        ImprimirPalabras(palabra);
        return OK;
    }if(posicionPalabra==1){
        insertarPalabraPrincipio(palabra, palabraAIngresar);
        printf("PALABRA INGRESADA CORRECTAMENTE al principio.. \n");
        return OK;
    }if((posicionPalabra > 1) && (posicionPalabra <= contar)){
            Palabras aux1 = palabra;
            int cont = 1;
            while(aux1 != NULL){
                    printf("\n%d:%d\n",posicionPalabra, contar);
                    if(cont+1 == posicionPalabra){
                        printf("\n%d:%d:%d\n ", posicionPalabra, contar, cont);
                        Palabras nueva = new _palabra;
                        nueva->pal = palabraAIngresar;
                        nueva->ptrPalabras = aux1->ptrPalabras;
                        aux1->ptrPalabras = nueva;
                        return OK;
                    }
                aux1 = aux1->ptrPalabras;
                cont++;
            }}if(posicionPalabra == contar+1){
                insertarPalabraFinal(palabra, palabraAIngresar);
            }else{
        printf("Mas de la cantidad de palabras, cero o menos... \n");
        return ERROR;
    }
}



TipoRetorno BorrarPalabra(Palabras &palabras, Posicion posicionPalabra) {
    //if((posicionPalabra >= 1) && (posicionPalabra < cantidad)){
            Palabras ante = NULL;
            Palabras nodo = palabras;
            for(int i=0; i<=posicionPalabra-1; i++){
                ante = nodo;
                nodo = nodo->ptrPalabras;
            }
            ante->ptrPalabras = nodo->ptrPalabras;
            free(ante);
                nodo = nodo->ptrPalabras;
            return OK;
  }

TipoRetorno BorrarOcurrenciasPalabra(Palabras &palabras, Cadena palabraABorrar) {
  return NO_IMPLEMENTADA;
}

void BorrarTodoPalabras(Palabras &palabras) {

}

void ImprimirPalabras(Palabras palabras) {
    while (palabras != NULL){
                printf("%s ", palabras->pal);
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

