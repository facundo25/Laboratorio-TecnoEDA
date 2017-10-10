#ifndef TEXTO_H_INCLUDED
#define TEXTO_H_INCLUDED

#include "Constantes.h"
#include "Palabras.h"
#include "Diccionario.h"



typedef struct _texto {
    //int info;
    _texto * ptrTexto;
    _palabra * ptrPalabra;
} * Texto;

void InsertarPrincipio(Texto &);
void InsertarFinal(Texto &);
int contarLineas(Texto);
bool TextoEsVacio(Texto texto);

    /* Crea un texto vacío */
Texto CrearTexto();
    /* Inserta una nueva línea vacía al final del texto */
TipoRetorno InsertarLinea(Texto &);
    /* Inserta una nueva línea vacía en la posición indicada */
TipoRetorno InsertarLineaEnPosicion(Texto &, Posicion);
    /* Borra la línea en la posición indicada */
TipoRetorno BorrarLinea(Texto &, Posicion);
    /* Borra todas las líneas del texto */
TipoRetorno BorrarTodo(Texto &);
    /* Borra todas las ocurrencias de una palabra en el texto */
TipoRetorno BorrarOcurrenciasPalabraEnTexto(Texto, Cadena);
    /* Imprime el texto por pantalla */
TipoRetorno ImprimirTexto(Texto);
    /* Comprime las líneas */
TipoRetorno ComprimirTexto(Texto);
    /* Inserta una palabra en una línea en la posicion dada */
TipoRetorno InsertarPalabraEnLinea(Texto, Posicion, Posicion, Cadena);
    /* Borra la palabra de una linea que se encuentra en la posición dada */
TipoRetorno BorrarPalabraEnLinea(Texto, Posicion, Posicion);
    /* Borra todas las ocurrencias de una palabra en la línea indicada */
TipoRetorno BorrarOcurrenciasPalabraEnLinea(Texto, Posicion, Cadena);
    /* Imprime la línea por pantalla */
TipoRetorno ImprimirLinea(Texto, Posicion);

/**------------------Para Parte 2------------------------**/
// Muestra todas las líneas del texto, pero exhibiendo solamente las palabras
// que no se encuentran en el dicionario.
// Se debe imprimir el número de línea. Cuando el texto no tiene líneas se debe
// mostrar el mensaje "Texto vacio".
TipoRetorno ImprimirTextoIncorrecto(Texto, Diccionario);
//------------------Para Parte 2------------------------
// Imprime las últimas palabras ingresadas. Esta operación debe realizarse
// eficientemente, sin implicar además una sobrecarga, más que en un valor
// constante, sobre el tiempo de ejecución de la operación 7.
// Imprime las últimas MAX_CANT_ULTIMAS_PALABRAS, a lo sumo, palabras ingresadas
// al texto (no al diccionario), aún cuando estas palabras pudieran haber sido
// luego eliminadas.
// MAX_CANT_ULTIMAS_PALABRAS es una constante del sistema.
// El orden en el que se muestran las palabras debe ser el siguiente: primero la
// última palabra ingresada, luego la penúltima, y así sucesivamente.
// Si nunca se ingresaron palabras se debe mostrar "No se ingresaron palabras".
TipoRetorno ImprimirUltimasPalabras(Texto);

#endif // TEXTO_H_INCLUDED
