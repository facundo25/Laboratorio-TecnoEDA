#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED
#include <string.h>
#include "Constantes.h"

typedef struct _diccionario {
    Cadena pald;
    _diccionario *izq;
    _diccionario *der;
}*Diccionario;

    /* Agrega una palabra al diccionario */
Diccionario CrearDiccionario();
    /* Ingresa una palabra al diccionario si ésta no se encuentra en el mismo */
TipoRetorno IngresarPalabraDiccionario(Diccionario &, Cadena);
    /* Borra una palabra del diccionario si se encuentra en el mismo. */
TipoRetorno BorrarPalabraDiccionario(Diccionario &, Cadena);
    /* Devuelve true si y sólo si la palabra pertenece al diccionario */
bool PerteneceDiccionario(Diccionario, Cadena);
    /* Muestra las palabras del diccionario odenadas alfabéticamente, de menor a mayor
       Cuando el diccionario no tiene palabras debe mostrarse el mensaje "Diccionario vacio" */
TipoRetorno ImprimirDiccionario(Diccionario D);

void RemplazarPalabraDiccionario(Diccionario &, Diccionario &); /*Prototipo de la funcion ''reemplazar''*/
#endif // DICCIONARIO_H_INCLUDED
