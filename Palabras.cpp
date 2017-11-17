#include "Palabras.h"
#include "Texto.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
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

int contarPalabras(Palabras palabras){
    int count = 0;
    while(palabras!=NULL){
        count++;
        palabras = palabras->ptrPalabras;
    }
    return count;
}

TipoRetorno InsertarPalabra(Palabras &palabra, Posicion posicionPalabra, Cadena palabraAIngresar) {


    Palabras aux = palabra;
    int contar = 0;

    while(aux != NULL){

        aux = aux->ptrPalabras;
        contar++ ;
        }

    if (contar >= MAX_CANT_PALABRAS_X_LINEA){
        printf(" ERROR: La linea llegó el límite de palabras permitido... \n");

        return ERROR;
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
            int cantidad = contarPalabras(palabras);

            if (cantidad == 0){
                printf("Linea sin palabras");
                return ERROR;
            }else {

                if((posicionPalabra >= 1) && (posicionPalabra <= cantidad)){
                    Palabras ante = NULL;
                    Palabras nodo = palabras;
                    for(int i=1; i<posicionPalabra; i++){
                        ante = nodo;
                        nodo = nodo->ptrPalabras;
                    }   if (ante == NULL){
                            palabras=palabras->ptrPalabras;
                            free (ante);
                        } else{
                                ante->ptrPalabras = nodo->ptrPalabras;
                                free(ante);
                                nodo = nodo->ptrPalabras;

                            }
                }
            }
return OK;
}

TipoRetorno BorrarOcurrenciasPalabra(Palabras &palabras, Cadena palabraABorrar) {

        int contadorPalabra = 0;
        while ( palabras->ptrPalabras != NULL){
                palabras->ptrPalabras;
            contadorPalabra ++;
        if (strcmp(palabraABorrar, palabras->ptrPalabras->pal) == 0){
            BorrarPalabra(palabras->ptrPalabras, contadorPalabra);
            }

        }
        return OK;
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
            while (palabras != NULL){
                if (!PerteneceDiccionario(D, palabras->pal)){
                    printf("%s ", palabras->pal);
                }
                palabras = palabras->ptrPalabras;
            }
}

