#include "Texto.h"
#include <stdlib.h>
#include <stdio.h>

Texto CrearTexto(){
  Texto t = NULL;
  return t;
}

/*-------- Primitivas -------------*/

void InsertarPrincipio(Texto &texto){
    Texto aux = new _texto;
        aux->sig = texto;
        texto = aux;
}

void InsertarFinal(Texto &texto){
    Texto Final = texto;
    Texto aux = new _texto;
    while (Final->sig !=NULL){
        Final= Final->sig;
    }
    aux->sig = NULL;
    Final->sig=aux;
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
        texto = texto->sig;
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
        aux = aux->sig;
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
                        nuevo ->sig = aux->sig;
                        aux->sig = nuevo;
                        return OK;
                    }
                aux = aux->sig;
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

        printf("Cantidad %d\n", cantidad);

        if((posicionLinea >= 1) && (posicionLinea <= cantidad)){
            Texto ante = NULL;
            Texto nodo = texto;
            for(int i=0; i<=posicionLinea-1; i++){
                ante = nodo;
                nodo = nodo->sig;
                //printf("%d\n", i);
            }
            ante->sig = nodo->sig;
            free(ante);
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

TipoRetorno ImprimirTexto(Texto texto) { return NO_IMPLEMENTADA; }

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

TipoRetorno ImprimirLinea(Texto texto, Posicion posicionLinea) {
  return NO_IMPLEMENTADA;
}


