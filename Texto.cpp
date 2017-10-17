#include "Texto.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Palabras.h"

Texto CrearTexto(){
  Texto t = NULL;
  return t;
}

/*-------- Primitivas -------------*/

void InsertarPrincipio(Texto &texto){
    Texto aux = new _texto;
    aux->ptrTexto = texto;
    texto = aux;
    aux->ptrPalabra = NULL;
}

void InsertarFinal(Texto &texto){
    Texto Final = texto;
    Texto aux = new _texto;
    while (Final->ptrTexto !=NULL){
        Final= Final->ptrTexto;
    }
    aux->ptrTexto = NULL;
    Final->ptrTexto=aux;
    aux->ptrPalabra = NULL;
}

bool TextoEsVacio(Texto texto){
    if (texto = NULL){
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
    int cant = contarLineas(texto);
    Texto aux = texto;
    if (cant==0){
        printf("La lista es vacia.. \n");
        return ERROR;
    }
    //printf("Numero de lineas: %d\n", cant);
    if((posicionLinea >= 1) && (posicionLinea <= cant)){
            aux = texto;
            for (int i=1; aux!=NULL; i++){
                    if(i=posicionLinea){
                        Texto nuevo = new _texto;
                        nuevo ->ptrTexto = aux->ptrTexto;
                        aux->ptrTexto = nuevo;
                        nuevo->ptrPalabra =NULL;
                        return OK;
                    }
                aux = aux->ptrTexto;
            }

                }if(posicionLinea == cant+1){
                InsertarFinal(texto);
                //printf("agregar una linea al final...");
                int e = 0;
                e = contarLineas(texto);
                printf("Numero de lineas: %d\n", e);
                return OK;

            }
        //printf("Coincide con el numero de lineas del texto... \n");

        else{
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

        if((posicionLinea >= 1) && (posicionLinea < cantidad)){
            Texto ante = NULL;
            Texto nodo = texto;
            for(int i=0; i<=posicionLinea-1; i++){
                ante = nodo;
                nodo = nodo->ptrTexto;
                //printf("%d\n", i);
            }
            ante->ptrTexto = nodo->ptrTexto;
            free(ante);
                nodo = nodo->ptrTexto;
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

TipoRetorno InsertarPalabraEnLinea(Texto texto, Posicion posicionLinea,Posicion posicionPalabra, Cadena palabraAIngresar)
{
    //if (texto==NULL){
    //printf("Texto vacío, ingrese una linea... \n");
    //return ERROR;

//}
  //  else {
    printf("POR ACÁ PASÉ");
    int cantidad = contarLineas(texto);
    //if (cantidad == 0){
    //    printf("EL TEXTO ES VACIO...");
    //return ERROR;
    //}

    //else {
    Texto aux = new _texto;
    if ((posicionLinea >=1)&&(posicionLinea <= cantidad)){
            for (int i=0; i <= posicionLinea; i++){
                aux = texto->ptrTexto;
            }
            printf("POR ACÁ TAMBIÉN PASÉ");
            InsertarPalabra(texto->ptrPalabra, posicionPalabra, palabraAIngresar);
    }
    printf("Linea ingresada no válida ...\n");
    return ERROR;

//return OK;

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
