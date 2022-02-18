# Apuntes lab

A diferencia de la compilación que se hacía en PRO1 usando directamente el 
comando ```p1++ main.cc -o main.x``` habrá que usar la compilación en dos pasos
con ```p2++ main.exe -c main.o``` seguido de ```p2++ main.x -o main.o```. Esto
se debe a que ahora se usará más de un archivo, de esta manera se obtienen los
archivos .o de todos y, en caso de cambiar un único archivo solo sería
necesario ejecutar el comando con la flag ```-c``` en el archivo modificado y
no con todos juntos. Eso sí, el comando con la flag ```-o``` sigue necesitando
añadir en el comando la totalidad de archivos .o.


## Funcionamiento de los módulos

Los archivos .hh permiten la creación de las cabeceras de las funciones que son
creadas en los .cc del mismo nombre. Llamar a este archivo con un 
```#include "archivo.hh"``` no hace que las definiciones de estas funciones 
sean añadidas, únicamente sus declaraciones. Debido a esto sigue siendo 
necesario compilar y linkear el archivo .cc con las definiciones de las
funciones.

En los archivos .hh se suele añadir lo siguiente:

```c++
#ifndef ARCHIVO_QUE_SE_IMPORTA
#define ARCHIVO_QUE_SE_IMPORTA

// declaraciones y todo eso

#endif
```

Esto funciona de la siguiente manera:

- Comprueba si se ha definido la constante "ARCHIVO_QUE_SE_IMPORTA". En caso
que no, la define y ejecuta todo hasta el "#endif". En caso contrario salta
hasta el "endif". De esta manera se evita que, en caso de que el archivo .hh
sea llamado varias veces sus funciones sean declaradas varias veces.
