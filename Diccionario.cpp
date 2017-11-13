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

TipoRetorno BorrarPalabraDiccionario(Diccionario &D, Cadena palabraABorrar) {
  return NO_IMPLEMENTADA;
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
    }
}
