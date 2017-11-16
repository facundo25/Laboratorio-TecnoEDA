#include "Diccionario.h"
#include <stdlib.h>
#include <stdio.h>

Diccionario CrearDiccionario() {
    Diccionario D = NULL;
  return D;
}

TipoRetorno IngresarPalabraDiccionario(Diccionario &D, Cadena palabraAIngresar) {
        if (D != NULL){
            int N = strcmp(palabraAIngresar, D->pald);
            if (0 > N){
                IngresarPalabraDiccionario(D->izq, palabraAIngresar);
            }else if(0 < N){
                IngresarPalabraDiccionario(D->der, palabraAIngresar);
            }else{
                printf("La palabra ya existe en el diccionario... \n");
                return ERROR;
            }
    }else{
        Diccionario nuevo = new _diccionario;
        nuevo->pald = palabraAIngresar;
        nuevo->izq = NULL;
        nuevo->der = NULL;
        D = nuevo;
        return OK;
    }

}

void RemplazarPalabraDiccionario(Diccionario &D, Diccionario &aux) {
    if (D->der == NULL)
        {
            aux->pald = D->pald;
            aux = D;
            D = D->izq;
        }
    else
    RemplazarPalabraDiccionario(D->der, aux);

}


TipoRetorno BorrarPalabraDiccionario(Diccionario &D, Cadena palabraABorrar) {
  Diccionario aux;
        if (D==NULL){
            printf("La palabra no existe o el diccionario es vacio..\n");
            return ERROR;
        }else{
            int N = strcmp(palabraABorrar, D->pald);
            if (0 > N){
                BorrarPalabraDiccionario(D->izq, palabraABorrar);
            }else if (0 < N){
                BorrarPalabraDiccionario(D->der, palabraABorrar);
            }else if (0 == N){
                aux = D;
                if (D->izq == NULL)
                D = D->der;
                else if (D->der == NULL)
                D = D->izq;
                else
                RemplazarPalabraDiccionario(D->izq, aux);
                free(aux);
                return OK;
            }
        }
}

bool PerteneceDiccionario(Diccionario D, Cadena palabra) {
  return false;
}

TipoRetorno ImprimirDiccionario(Diccionario D) {
    if(D){
        printf("%s\n", D->pald);
            if(D->izq){
                    printf("izq <-\n");
                    ImprimirDiccionario(D->izq);
            }
            if(D->der){
                    printf("der ->\n");
                    ImprimirDiccionario(D->der);
            }
    }else{
    printf("Diccionario vacio..\n");
    return ERROR;
    }
}
