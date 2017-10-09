#ifndef PALABRAS_H_INCLUDED
#define PALABRAS_H_INCLUDED

#include "Constantes.h"
#include "Diccionario.h"

//struct _palabra;
typedef struct _palabra {
    _palabra * sig;
    Cadena pal;
}*Palabras;

    /* Crea un conjunto de palabras vacio */
Palabras CrearPalabras();
    /* Inserta una palabra en la posicion dada */
TipoRetorno InsertarPalabra(Palabras &, Posicion, Cadena);
    /* Borra la palabra que se encuentra en la posición dada */
TipoRetorno BorrarPalabra(Palabras &, Posicion);
    /* Borra todas las ocurrencias de una palabra */
TipoRetorno BorrarOcurrenciasPalabra(Palabras &, Cadena);
    /* Borrar todo */
void BorrarTodoPalabras(Palabras &);
    /* Imprime la línea en pantalla */
void ImprimirPalabras(Palabras);
    /* Devuelve la cantidad de palabras */
unsigned int CantidadPalabras(Palabras);
    /* Devuelve en palabra una copia de la palabra que se encuentra en la posición dada */
TipoRetorno PalabraEnPosicion(Palabras, Posicion, Cadena &);

/** ------------------Para Parte 2------------------------ **/
// Muestra solamente las palabras que no se encuentran en el dicionario.
TipoRetorno ImprimirPalabrasIncorrectas(Palabras, Diccionario);

#endif // PALABRAS_H_INCLUDED
