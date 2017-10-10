#include "Texto.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Texto CrearTexto(){
  Texto t = NULL;
  return t;
}

/*-------- Primitivas -------------*/

void InsertarPrincipio(Texto &texto){
    Texto aux = new _texto;
    aux->ptrTexto = texto;
    texto = aux;
}

void InsertarFinal(Texto &texto){
    Texto Final = texto;
    Texto aux = new _texto;
    while (Final->ptrTexto !=NULL){
        Final= Final->ptrTexto;
    }
    aux->ptrTexto = NULL;
    Final->ptrTexto=aux;
}

bool TextoEsVacio(Texto texto){
    if (texto == NULL){
        return true;
    }
    return false;
}
int contarLineas(Texto texto){
    int count = 0;
    while(texto!=NULL){
        count++;
        texto = texto->ptrTexto;
    }
    return count;
}
/*-------- Primitivas -------------*/

TipoRetorno InsertarLinea(Texto &texto) {
    if (texto == NULL){
        InsertarPrincipio(texto);
    }else{
        InsertarFinal(texto);
    }
    int e = 0;
    e = contarLineas(texto);
    printf("%d",e);
  return OK;
}

TipoRetorno InsertarLineaEnPosicion(Texto &texto, Posicion posicionLinea) {
    int count = 0;
    Texto aux = texto;
    while(aux != NULL){
        aux = aux->ptrTexto;
        count++;
    }
    if (count==0){
        printf("La lista es vacia.. \n");
        return ERROR;
    }
    printf("Numero de lineas: %d\n", count);
    if((posicionLinea >= 1) && (posicionLinea <= count)){
            aux = texto;
            for (int i=1; aux!=NULL; i++){
                    if(i=posicionLinea){
                        Texto nuevo = new _texto;
                        nuevo ->ptrTexto = aux->ptrTexto;
                        aux->ptrTexto = nuevo;
                        return OK;
                    }
                aux = aux->ptrTexto;
            }
        //printf("Coincide con el numero de lineas del texto... \n");
        return OK;
    }else{
        printf("Mas de la cantidad de lineas, cero o menos... \n");
        return ERROR;
    }
}

TipoRetorno BorrarLinea(Texto &texto, Posicion posicionLinea) {
    if(TextoEsVacio(texto) == true){
        printf("Es vacio...");
        return ERROR;
    }else{
        int cantidad = contarLineas(texto);

        //printf("Cantidad %d", cantidad);

        if((posicionLinea >= 1) && (posicionLinea <= cantidad)){
            Texto ante = new _texto;
            Texto nodo = texto;
            for(int i=0; i=cantidad-1; i++){
                ante = nodo;
                nodo = nodo->ptrTexto;
            }
            ante->ptrTexto = nodo->ptrTexto;
            delete nodo;
            return OK;
        }else{
            printf("No existe la posicion... \n");
            return ERROR;
        }


    }
}

TipoRetorno BorrarTodo(Texto &texto) {
  return NO_IMPLEMENTADA;
}

TipoRetorno BorrarOcurrenciasPalabraEnTexto(Texto texto, Cadena palabraABorrar) {
  return NO_IMPLEMENTADA;
}

TipoRetorno ImprimirTexto(Texto texto){

    //Palabras palabra = CrearPalabras();
    Texto aux = texto;

    while(aux!=NULL){
        while(aux->ptrPalabra !=NULL){

            //Palabras p = texto->ptrPalabra;
            Cadena c = NULL;
            strcpy(c,aux->ptrTexto->ptrPalabra->pal);
        }


        aux = aux->ptrTexto;
    }

    /*
    int contador = 0;
    if (TextoEsVacio(texto)){
       printf("Texto vacío");
       return ERROR;
    } else
        while (texto!=NULL){
            texto = texto->sig;
            aux= texto->p;
            contador ++;
            //printf("%d :\n", contador);
            while (palabra!=NULL){
                printf("%d", contador);
                printf("%c", palabra->pal);
                palabra->sig;
            }
        }
*/
return OK;
}

TipoRetorno ComprimirTexto(Texto texto) {
  return NO_IMPLEMENTADA;
}

TipoRetorno InsertarPalabraEnLinea(Texto texto, Posicion posicionLinea,
                                   Posicion posicionPalabra, Cadena palabraAIngresar) {
  return NO_IMPLEMENTADA;
}

TipoRetorno BorrarPalabraEnLinea(Texto texto, Posicion posicionLinea, Posicion posicionPalabra) {
  return NO_IMPLEMENTADA;
}

TipoRetorno BorrarOcurrenciasPalabraEnLinea(Texto texto, Posicion posicionLinea, Cadena palabraABorrar) {
  return NO_IMPLEMENTADA;
}

/*
TipoRetorno ImprimirLinea(Texto texto, Posicion posicionLinea) {

    if (TextoEsVacio(texto)){
       printf("Texto vacío");
       return ERROR;
    } else
        for (int i=0; i<=posicionLinea; i++){
        //printf ("%c ", texto->p);
        texto=texto->sig;
        while (texto!=NULL){


        }
    }

return OK;

} */
