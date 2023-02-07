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

.. warning:: EN CONSTRUCCIÓN 

  Evaluación en construcción. Cada que visites 
  esta página presiona F5 para refrescarla y cargar 
  la evaluación cuando esté disponible

Enunciado 
************

Vas a construir una aplicación interactiva de terminal. La aplicación 
servirá para extraer información de una base de datos de jugadores.
La base de 


 que estará 
atenta todo el tiempo a comandos que escriba el usuario. Implementa 
los siguientes comandos:

* 


Trayecto de actividades
------------------------

Ejercicios
**********

Para la realización de los ejercicios de la unidad te voy a crear 
`este <https://classroom.github.com/a/EN6l5Lyr>`__ repositorio donde puedas 
experimentar tu solo. Recuerda que la evaluación 
de la unidad tendrá su propio repositorio. USA CODESPACES.

Ejercicio 1: retrieval practice
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

En la unidad anterior programaste en el lenguaje ensamblador de 
una CPU específica. Viste cómo traducir de lenguaje ensamblador 
a lenguaje de máquina. También te mostré algunas traducciones de 
lenguaje C a lenguaje ensamblador. Te voy a pedir que lo recuerdes, 
mira:

.. code-block:: c

    MEMORY[16] = 16384;

    while (true)
    {
        if (MEMORY[KEYBOARD] == 0)
        {
            if ((MEMORY[16] - 16384) > 0)
            {
                MEMORY[16] = MEMORY[16] - 1;
                MEMORY[MEMORY[16]] = 0x0000;
            }
        }
        else
        {
            if ((MEMORY[16] - 24576) < 0)
            {
                MEMORY[MEMORY[16]] = 0xFFFF;
                MEMORY[16] = MEMORY[16] + 1;
            }
        }
    }

Este programa escrito en C puede tener una traducción a 
lenguaje ensamblador de la CPU que simulaste en la unidad anterior así:

========= ===================
Dirección Código ensamblador  
========= =================== 
0	        @16384
1	        D=A
2	        @16
3	        M=D
4	        @24576
5	        D=M
6	        @19
7	        D;JNE
8	        @16
9	        D=M
10	      @16384
11	      D=D-A
12	      @4
13	      D;JLE
14	      @16
15	      AM=M-1
16	      M=0
17	      @4
18	      0;JMP
19	      @16
20	      D=M
21	      @24576
22	      D=D-A
23	      @4
24	      D;JGE
25	      @16
26	      A=M
27	      M=-1
28	      @16
29	      M=M+1
30	      @4
31	      0;JMP
========= ===================

* Identifica en el código ensamblador la inicialización 
  de una variable.
* Identifica en el código ensamblador una estructura IF/ELSE.
* Identifica en el código ensamblador una while.


Ejercicio 2: de lenguaje de alto nivel a código ejecutable
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora te voy a mostrar cómo puedes hacer la traducción 
anterior, pero esta vez para la CPU de tu computador y usando 
herramientas (toolchain) específicas.

.. warning:: ESTE EJERCICIO ES DIDÁCTICO

  En este ejercicio te muestro los pasos para que observes 
  cómo funciona el proceso, PERO no es una manera práctica de 
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

Iniciemos entonces el proceso con ``min.c``:

* Preprocesamiento:  ``gcc -E min.c``. Al ejecutar este comando nota como
  el preprocesador incluye la información de min.h a min.c
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

* Ensamblado: en esta fase se genera el código máquina.
  ``as min.s -o min.o``. También es posible generar el código de
  máquina con el comando ``gcc -c min.c``

* Debemos repetir este proceso con todos los archivos ``.c`` de nuestro
  proyecto: ``gcc -c main.c``. Ten presente que el comando anterior
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

Ejercicio 3: retrieval practice (evaluación formativa)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Realiza un diagrama mostrando los pasos necesarios para traducir 
  un programa escritor en lenguaje C compuesto por 3 archivos .c, dos 
  de los cuales tienen su archivo .h correspondiente. Muestra en tu 
  diagrama que información entra y sale de cada paso.

* ¿Cuál es la diferencia entre preprocesamiento y compilación?
* ¿Cuál es la diferencia entre ensamblado y compilación?
* ¿Para qué sirve el proceso de ensamblado?
* ¿Cuál es la diferencia entre un error reportado en compilación 
  y otro reportado en enlazado?

Ejercicio 4: retrieval practice (evaluación formativa)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* En una sola línea de comando ¿Cómo puedes generar el ejecutable?
* ¿Qué debes hacer para compilar SOLO un archivo .c?
* ¿Por qué crees que puede ser útil compilar solo un archivo .c?

Ejercicio 5: para pensar
^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Inventa un programa que genere un error de compilación, es decir 
  un error sintáctico.
* Inventa un programa que genere un error semántico, es decir, compila 
  pero no hace lo que se espera.
* Inventa un error generado por el enlazador.

.. warning:: ERRORES DEL ENLAZADOR VS EL COMPILADOR 

  ¿Cómo haces para diferenciar, observando la salida en terminal, 
  un error de compilación vs un error en enlazado?

Ejercicio 6: lenguaje de programación C
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Este será uno de los ejercicios más largos de la unidad porque te voy a mostrar 
el lenguaje de programación con el cual estudiarás los conceptos que quedan 
del curso: ``lenguaje C``.

.. toctree::
    :maxdepth: 3

    Introducción a C <./introC>

