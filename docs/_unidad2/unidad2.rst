Unidad 2. De lenguaje de alto nivel a código ejecutable 
============================================================

Introducción
--------------

En este punto del curso ya tienes una buena idea de cómo funciona un 
computador. También escribiste algunos programas en lenguaje ensamblador 
y estudiaste la relación entre este y el lenguaje de máquina.

A partir de ahora vas a emprender un viaje por varios de los componentes
de software relacionados con los sistemas de cómputo. En esta unidad vas a
aprender un nuevo lenguaje de programación muy relacionado con la programación 
a nivel de sistema.

Propósito de aprendizaje
*****************************

Aprender un nuevo lenguaje de programación que te acerque a los conceptos 
de los sistemas de cómputo más naturalmente: lenguaje C.

Evaluación
-----------------------------------

.. note:: RESULTADO DE APRENDIZAJE DEL CURSO 

  ¿Recuerdas el resultado de aprendizaje del curso?

  Aplico los conceptos necesarios para el correcto diseño, implementación, 
  funcionamiento y diagnóstico del software en la producción de sistemas de 
  entretenimiento digital utilizando los procedimientos y herramientas 
  adecuadas según el contexto. ``NIVEL RESOLUTIVO``.

  La idea de esta evaluación es que evidencies que eres capaz de aplicar 
  los conceptos estudiados en la unidad anterior y esta mediante 
  la construcción de una aplicación interactiva. Se espera que puedas realizar:

  * Lectura de comandos de entrada mediante teclado.
  * Lectura de archivos en memoria usando el HEAP.
  * Procesamiento de la información y manipulación de la memoria.
  * Escritura de archivos.

  No solo se espera que apliques los conceptos para construir la aplicación, sino 
  también para resolver los problemas (errores) que se presenten al construir 
  la aplicación.

Enunciado 
************

El proyecto de esta unidad se trata de recrear el juego `Pong <https://youtu.be/fiShX2pTz9A>`__. 
`Aquí <https://en.wikipedia.org/wiki/Pong>`__ puedes leer un poco más acerca de las reglas del juego. 

Los requisitos del proyecto son:
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Usa el lenguaje de programación C, no C++.
* Usa la biblioteca SDL2.
* Usa Visual Studio y el sistema operativo windows.
* Usa git bash para hacer el control de versión de tu programa.
* Representación de elementos: el juego debe representar la pelota, las dos paletas de los 
  jugadores y el tablero en pantalla.
* Movimiento de las paletas: las paletas de los jugadores deben poder moverse hacia arriba y 
  hacia abajo para golpear la pelota.
* Movimiento de la pelota: la pelota debe moverse de manera diagonal y rebotar en las paletas y 
  los bordes del tablero.
* Puntuación: debe haber un marcador para mostrar la puntuación de ambos jugadores.
* Colisiones: el juego debe detectar y manejar las colisiones entre la pelota y las paletas, 
  actualizando la dirección de la pelota en función de dónde golpea la paleta.
* Aumento de velocidad: la velocidad de la pelota debe aumentar gradualmente a medida que 
  el juego avanza.
* Historial de eventos: se debe implementar una lista enlazada para registrar eventos 
  importantes, como la posición de la pelota y las paletas, la puntuación y los aumentos 
  de velocidad.
* Entrada del jugador: los jugadores deben poder controlar las paletas utilizando el teclado 
  para golpear la pelota.
* Reproducción: los jugadores deben poder ver una reproducción de la partida después de que 
  esta termine, utilizando el historial de eventos registrado.
* Almacenamiento en archivo: los eventos del historial deben poder almacenarse en un archivo 
  al finalizar una partida.
* Carga de partidas: los jugadores deben poder cargar partidas anteriores desde un archivo 
  para reproducirlas.

Guía de desarrollo gradual
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Te dejo una guía paso a paso para que desarrolles el juego de Pong:

Etapa 1: configuración básica con SDL2
++++++++++++++++++++++++++++++++++++++++

* Configurar un proyecto de C con SDL2 y cargar una ventana en blanco en pantalla.
* Mostrar las paletas y la pelota en posiciones iniciales estáticas.
* Implementar la lógica básica para mover las paletas arriba y abajo utilizando el teclado.

Etapa 2: movimiento de la pelota y rebotes
+++++++++++++++++++++++++++++++++++++++++++

* Implementar el movimiento de la pelota en diagonal.
* Detectar y manejar las colisiones con los bordes del tablero para que la pelota rebote.

Etapa 3: colisiones con las paletas y puntuación
+++++++++++++++++++++++++++++++++++++++++++++++++

* Detectar y manejar las colisiones entre la pelota y las paletas.
* Implementar la lógica para actualizar la dirección de la pelota según la posición de impacto 
  en la paleta.
* Mostrar la puntuación de ambos jugadores en pantalla.

Etapa 4: aumento de velocidad
++++++++++++++++++++++++++++++

* Implementar la lógica para aumentar gradualmente la velocidad de la pelota a medida que 
  avanza el juego.

Etapa 5: historial de eventos
++++++++++++++++++++++++++++++

* Definir la estructura para los eventos (PongEvent) y la estructura del nodo para la lista enlazada 
  (Node).
* Implementar la lista enlazada para registrar eventos importantes, como la posición de la 
  pelota, las paletas, la puntuación y los aumentos de velocidad.

Etapa 6: registro de eventos
+++++++++++++++++++++++++++++++

* En cada evento importante del juego (movimiento de la pelota, movimiento de las paletas, 
  cambios en la puntuación, etc.), agregar un nuevo nodo con los datos del evento 
  a la lista enlazada.

Etapa 7: entrada del jugador
+++++++++++++++++++++++++++++

* Permitir que los jugadores controlen las paletas utilizando el teclado para golpear la pelota.

Etapa 8: almacenamiento en archivo
+++++++++++++++++++++++++++++++++++

* Implementar una función para guardar el historial de eventos en un archivo al finalizar una partida. 
  Los eventos se escribirán en un formato adecuado para su posterior lectura.

Etapa 9: carga de partidas
++++++++++++++++++++++++++++

* Implementar una función para cargar el historial de eventos desde un archivo.
* Permitir a los jugadores seleccionar un archivo para cargar y reproducir partidas anteriores.

Etapa 10: reproducción de partidas
+++++++++++++++++++++++++++++++++++

* Implementar la función de reproducción que recorre la lista enlazada y restaura el estado del 
  juego en cada evento, ya sea cargado desde un archivo o generado durante la partida actual.

Etapa 11: Pulido y mejoras
++++++++++++++++++++++++++++

* Optimizar el código y solucionar posibles errores.

A medida que avances en cada etapa, puedes probar y depurar el juego para asegurarte que cada 
funcionalidad esté correcta antes de pasar a la siguiente etapa.


Entrega
*********

* El repositorio para entregar tu evaluación está `aquí <https://classroom.github.com/a/pVSO5AXZ>`__. 
* El proyecto lo debes realizar bajo control de versión TODO el tiempo, no solo 
  cuando lo entregues. La idea es que podamos ver juntos cómo es la evolución 
  de tu trabajo en el tiempo.
* Ten presente que bajo control de versión solo debes tener los archivos de código 
  fuente (archivos .c, .h, assets del juego). No incluyas archivos intermedios, ni ejecutables.
* Debes incluir un archive README.md con:

  * Tu nombre completo y ID.
  * Un enlace a un video no listado en youtube donde muestres
    tu aplicación funcionando.
  * Muestra en qué parte del código implementaste cada requisito y explica brevemente 
    como solucionaste el problema que plantea el requisito.

.. warning:: NO OLVIDES

    No olvides que SOLO se reciben proyectos completos. El proyecto solo se considera 
    entregado cuando cumplas todos los requisitos y esté la documentación solicitada 
    en el archivo README.md

Trayecto de actividades
------------------------

Ejercicios
**********

Ejercicio 1: de lenguaje de alto nivel a código ejecutable
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Para probar los comandos que están aquí puedes crear un Codespaces 
en el repositorio de tu evaluación.

.. warning:: ESTE EJERCICIO ES DIDÁCTICO

  En este ejercicio te muestro los pasos que ocurren al transformar 
  un programa de alto nivel a código de máquina ejecutable. La idea 
  es que que observes cómo funciona el proceso, PERO no es una manera práctica de 
  trabajar. Al final te muestro cómo puedes hacer el proceso 
  de traducción de forma más práctica.

Vamos a explorar juntos esta pregunta:

¿Cómo llegamos del código fuente en C al binario (unos y ceros, el ejecutable)?

En el caso del lenguaje C se siguen unos pasos conocidos como el
pipeline de compilación compuesto por 4 pasos: preprocesamiento,
compilación, ensamblado y enlazado.

.. note:: IMPORTANTE 

    Para poder conseguir un ejecutable desde el código fuente,
    es necesario que nuestro código pase por todas las etapas del pipeline
    de manera exitosa.

    ¿Qué significa para ti la afirmación anterior?

Para ilustrar el proceso vamos a crear un programa compuesto por 3 archivos:
dos archivos .c y un archivo .h. Todos los archivos estarán almacenados
en el mismo directorio.

min.h

.. code-block:: c

    #ifndef MIN_H
    #define MIN_H
    int min(int, int);
    #endif

min.c

.. code-block:: c

    #include "min.h"

    int min(int a, int b){
        if(a < b) return a;
        else return b;
    }

main.c

.. code-block:: c

    #include "min.h"
    #include <stdio.h>

    int main(int argc, char* argv[]){
        printf("the min value is: %d\n",min(1,2));
        return 0;
    }

La idea será crear un ``ejecutable`` partiendo de estos tres archivos.
Ten presente que los archivos ``.h`` se usan para informarle al compilador
qué tipo de datos recibe la función min y qué tipo de dato devuelve. Los
archivos .h no se compilan, solo los archivos ``.c``.

Vas a ver que utilizaremos el comando ``gcc```. Este comando sabe 
que herramienta utilizar dependiendo de las opciones que le pasemos. Ya verás.

Iniciemos entonces el proceso con ``min.c``:

* Preprocesamiento:  ``gcc -E min.c``. Al ejecutar este comando gcc llama 
  al preprocesador. Nota que al ejecutar este comando el preprocesador 
  imprime en la terminal una salida que muestra una mezcla del archivo 
  min.c y min.h. Dicho de otra manera, el procesador INCLUYE (#include) la información 
  del archivo min.h en min.c. De todas maneras ten presente que tu archivo min.c
  original no se modificará.
* Compilación: ejecuta el comando ``gcc -S min.c``. La opción ``-S`` indica 
  que ``gcc`` debe hacer el proceso de preprocesador y con la
  salida de este paso se alimenta al compilador y detenerse en ese punto. El archivo
  de salida generado será ``min.s`` que contendrá el código ensamblador.
  ¿Notas que el lenguaje ensamblador de la CPU de tu computador es diferente 
  al de la unidad anterior?

.. code-block:: bash

        .file	"min.c"
        .text
        .globl	min
        .type	min, @function
    min:
    .LFB0:
        .cfi_startproc
        endbr64
        pushq	%rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq	%rsp, %rbp
        .cfi_def_cfa_register 6
        movl	%edi, -4(%rbp)
        movl	%esi, -8(%rbp)
        movl	-4(%rbp), %eax
        cmpl	-8(%rbp), %eax
        jge	.L2
        movl	-4(%rbp), %eax
        jmp	.L3
    .L2:
        movl	-8(%rbp), %eax
    .L3:
        popq	%rbp
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
    .LFE0:
        .size	min, .-min
        .ident	"GCC: (Ubuntu 9.3.0-10ubuntu2) 9.3.0"
        .section	.note.GNU-stack,"",@progbits
        .section	.note.gnu.property,"a"
        .align 8
        .long	 1f - 0f
        .long	 4f - 1f
        .long	 5
    0:
        .string	 "GNU"
    1:
        .align 8
        .long	 0xc0000002
        .long	 3f - 2f
    2:
        .long	 0x3
    3:
        .align 8
    4:

* Ensamblado: en esta fase se genera el código de máquina.
  ``as min.s -o min.o``. También es posible generar el código de
  máquina con el comando ``gcc -c min.c``

* Debemos repetir este proceso con todos los archivos ``.c`` de nuestro
  proyecto: ``gcc -c main.c``. El comando anterior
  ejecutará automáticamente todos los pasos previos, es decir, el preprocesado,
  la compilación y el proceso de ensamblado.

.. note:: HASTA AQUÍ YA TIENES TODOS LOS .o

  Mira, si generar el ejecutable fuera como hacer una torta, 
  en este momento ya tienes todos los ingredientes (archivos .o) listos 
  para que los revuelvas (el proceso de enlazado).

* Enlazado: una vez tengas todos los archivos ``.o`` lo último que debes hacer
  es enlazar todos los archivos para generar un archivo ejecutable. Este archivo
  contiene el código de máquina de todos los ``.o`` pero organizado en un formato
  específico. En el caso de Linux el formato típico es ``.ELF``. Ejecuta el siguiente
  comando para enlazar: ``ld min.o main.o``. Verás el siguiente resultado:

.. code-block:: bash

    ld: warning: cannot find entry symbol _start; defaulting to 0000000000401000
    ld: main.o: in function main:
    main.c:(.text+0x31): undefined reference to printf

Este resultado indica que no fue posible generar el ejecutable 
(``main.c:(.text+0x31): undefined reference to printf``). Pero ¿Por qué?
la razón es que nos falta el archivo con el código de máquina de la función ``printf``.
Esta función está prototipada en el archivo de cabecera (``stdio.h``), pero el archivo
no contiene el código fuente de ``printf``. ¿Y dónde está el código entonces? este
código hace parte de la biblioteca `glibc <https://www.gnu.org/software/libc/>`__ 
que debes tener en tu sistema operativo y que contiene el código de máquina de varias
funciones, entre ellas, ``printf``.

Una forma fácil de generar el ejecutable es utilizar de nuevo ``gcc``. Este comando
se encargará de suministrarle a ``ld`` todo los archivos con código máquina necesarios para
generar nuestro ejecutable: ``gcc min.o main.o -o main``.

.. warning:: MANERA PRÁCTICA DE HACER LA TRADUCCIÓN 

  Como te comenté al comienzo, una manera más práctica de hacer todo el proceso 
  anterior es con este comando::

    gcc -Wall main.c min.c -o main

  Nota que el comando ``gcc`` se encargará de llamar todos 
  los programas por ti. Inicialmente le dices a gcc cuáles son los archivos 
  .c de tu programa y con la opción -o cómo se llamará el ejecutable. La opción 
  -Wall le dice a gcc que te muestre TODAS la advertencias.

  No olvides que cada que cambies un archivo DEBES volver a llamar gcc 
  para repetir todo el proceso de traducción.

  Finalmente para ejecutar el programa::

    ./main

  Observa que no estoy colocando main.c. Nota que main.c es uno de los 
  archivos de código fuente, no es el ejecutable. De hecho el ejecutable 
  no tiene extensión. ¿Ves la diferencia? y si en vez de main llamas al ejecutable 
  con el nombre ``ejecutable`` ¿Hay alguna diferencia? ¿Tendrías que cambiar algo 
  cuando llames a gcc?

Ejercicio 2: retrieval practice (evaluación formativa)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Realiza un diagrama mostrando los pasos necesarios para traducir 
  un programa escrito en lenguaje C compuesto por 3 archivos .c, dos 
  de los cuales tienen su archivo .h correspondiente. Muestra en tu 
  diagrama que información entra y sale de cada paso.

* ¿Cuál es la diferencia entre preprocesamiento y compilación?
* ¿Cuál es la diferencia entre ensamblado y compilación?
* ¿Para qué sirve el proceso de ensamblado?
* ¿Cuál es la diferencia entre un error reportado en compilación 
  y otro reportado en enlazado?

Ejercicio 3: retrieval practice (evaluación formativa)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* En una sola línea de comando ¿Cómo puedes generar el ejecutable?
* ¿Qué debes hacer para compilar SOLO un archivo .c?
* ¿Por qué crees que puede ser útil compilar solo un archivo .c?

Ejercicio 4: para pensar
^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Inventa un programa que genere un error de compilación, es decir 
  un error sintáctico.
* Inventa un programa que genere un error semántico, es decir, compila 
  pero no hace lo que se espera.
* Inventa un error generado por el enlazador.

.. warning:: ERRORES DEL ENLAZADOR VS EL COMPILADOR 

  ¿Cómo haces para diferenciar, observando la salida en terminal, 
  un error de compilación vs un error en enlazado?

Ejercicio 5: lenguaje de programación C
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. warning:: ESTE EJERCICIO ES OPCIONAL 

  Mira, es posible que esta sea tu primera exposición al lenguaje de programación 
  ``C``. En este ejercicio te voy a dar un material, pero no tienes que usarlo 
  si no te gusta. Lo bueno es que tienes Internet, YouTube, ChatGPT, etc. El material 
  que te mostraré busca entrenar tu cerebro para que pienses al estilo de C.

Este será uno de los ejercicios más largos de la unidad porque te voy a mostrar 
el lenguaje de programación con el cual estudiarás los conceptos que quedan 
del curso: ``lenguaje C``.

.. toctree::
    :maxdepth: 3

    Introducción a C <./introC>

Ejercicio 6: SDL2
^^^^^^^^^^^^^^^^^^^^

Esta evaluación la vas a realizar utilizando una biblioteca llamada 
SDL2 y visual studio en Windows.

Te voy a dejar dos recursos que pueden ser de mucha utilidad:

* Página oficial de `SDL2 <https://www.libsdl.org/>`__.
* `Este <https://www.udemy.com/course/game-loop-c-sdl/>`__ curso gratuito en Udemy que te 
  ayudará a realizar la primera etapa de la evaluación, es decir, aprender a instalar 
  la biblioteca SDL2 en tu proyecto de Visual Studio y a generar un game loop para 
  que puedas construir desde ahí la base de tu aplicación.



