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

Comprender cómo se transforma un programa escrito en lenguaje C a lenguaje 
de máquina.

Temas
*********

* Introducción al lenguaje C


Trayecto de actividades
------------------------

Sesión 1
**********
(Tiempo estimado: 1 hora 40 minutos)

Ejercicio 1: entorno de trabajo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Para poder trabajar en los ejercicios vas a necesitar un ambiente de trabajo basado en Linux.
En este punto del curso ya deberías tener tu sistema operativo funcionando en casa.

Ejercicio 2: instala las herramientas 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Una vez tengas Linux funcionando debes instalar unas cuentas herramientas en tu 
sistema.

Abre la terminal y ejecuta los comandos:

.. code-block:: bash

    $ sudo apt update
    $ sudo apt install build-essential
    $ sudo apt install gdb

Ejercicio 3: instala un editor de texto 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Para el curso te recomiendo que instales 
`Visual Studio Code <https://code.visualstudio.com>`__

Ejercicio 4: lenguaje de programación C
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Este será uno de los ejercicios más largos de la unidad porque vamos a introducir 
el lenguaje de programación con el cual estudiaremos los conceptos que nos queda del curso: ``lenguaje C``.

.. toctree::
    :maxdepth: 3

    Introducción a C <./introC>

Trabajo autónomo 1
********************
(Tiempo estimado: 1 hora 20 minutos)

Continua avanzando en el ejercicio 4.

Sesión 2
**********
(Tiempo estimado: 1 hora 40 minutos)

Sigue trabajando en el ejercicio 4.

Trabajo autónomo 2
********************
(Tiempo estimado: 1 hora 20 minutos)

Continua avanzando en el ejercicio 4.

Sesión 3
**********
(Tiempo estimado: 1 hora 40 minutos)

Sigue trabajando en el ejercicio 4.

Trabajo autónomo 3
********************
(Tiempo estimado: 1 hora 20 minutos)

Continua avanzando en el ejercicio 4.

Sesión 4
**********
(Tiempo estimado: 1 hora 40 minutos)

Sigue trabajando en el ejercicio 4.

Trabajo autónomo 4
********************
(Tiempo estimado: 1 hora 20 minutos)

Continua avanzando en el ejercicio 4.

Sesión 5
**********
(Tiempo estimado: 1 hora 40 minutos)

Realiza la evaluación 1 de la unidad.

Trabajo autónomo 5
********************
(Tiempo estimado: 1 hora 20 minutos)

Continua avanzando con la evaluación 1 de la unidad.

Sesión 6
**********
(Tiempo estimado: 1 hora 40 minutos)

Sigue con la evaluación de la unidad 1.

Trabajo autónomo 6
********************
(Tiempo estimado: 1 hora 20 minutos)

Termina la evaluación 1 de la unidad.

Sesión 7
**********
(Tiempo estimado: 1 hora 40 minutos)

Ejercicio 5: de lenguaje de alto nivel a código ejecutable
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Cómo llegamos del código fuente  al binario (el ejecutable)?

En el caso del lenguaje C se siguen unos pasos conocidos como el
pipeline de compilación compuesto por 4 pasos: preprocesamiento,
compilación, ensamblado y enlazado.

IMPORTANTE: para poder conseguir un ejecutable desde el código fuente,
es necesario que nuestro código pase por todas las etapas del pipeline
de manera exitosa.

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

La idea será crear un ejecutable partiendo de estos tres archivos.
Ten presente que los archivos ``.h`` se usan para informarle al compilador
qué tipo de datos recibe la función min y qué tipo de dato devuelve. Los
archivos .h no se compilan, solo los archivos ``.c``.

Compilamos primero ``min.c``:

* Preprocesamiento:  ``gcc -E min.c``. Al ejecutar este comando nota como
  el preprocesador incluye la información de min.h a min.c
* Compilación: ejecuta el comando ``gcc -S min.c``. La opción ``-S`` indica 
  que ``gcc`` debe hacer el proceso de preprocesador y con la
  salida de este paso se alimenta al compilador y detenerse en ese punto. El archivo
  de salida generado será ``min.s`` que contendrá el código ensamblador.

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


..
    Ejercicio 7: máquinas virtuales
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    .. note:: EN CONSTRUCCIÓN

        En los próximos días te estaré publicando este contenido

..
  En este ejercicio aprenderás acerca de las máquinas virtuales.  

  .. toctree::
    :maxdepth: 3

    Máquinas virtuales <./VM>

Evaluación 1
-----------------
(Tiempo total estimado 6 horas)

La evaluación consiste de dos partes:

* Parte 1: solución a un problema.
* Parte 2: sustentación de la solución al problema.

.. note:: FECHA MÁXIMA DE ENTREGA

    La fecha máxima de entrega es el 06 de marzo de 2022 a las 23:59


Enunciado del problema
**************************

Vas a completar la aplicación que aparece `aquí <https://classroom.github.com/a/dKXDoh5P>`__. Debes 
escribir el código de estas dos funciones: 

.. code-block:: c

    void getArray(struct array *parr)
    {
        
    }

    void arrayCommon(struct array *arrIn1, struct array *arrIn2, struct array *arrOut)
    {
        
    }

Las funciones manipularán una estructura dada por:  

.. code-block:: c

    struct array
    {
        int *pdata;
        int size;
    };

La variable ``pdata`` almacenará la dirección de un arreglo de enteros de tamaño ``size``. El arreglo 
de enteros lo debes crear en el ``HEAP``. 

La función ``getArray`` se encargará de construir el arreglo recibiendo desde la línea de comandos 
su tamaño y los elementos. Por ejemplo, para un arreglo de 5 elementos se ingresarán los siguientes 
datos en la línea de comandos:

.. code-block:: bash 

    5
    1
    2
    3
    4
    5

En este caso ``5`` es el tamaño y los elementos serán ``1,2,3,4,5``.

La función ``arrayCommon`` recibirá la dirección de tres ``struct array`` que están previamente 
construidos en el HEAP. Esta función deberá encontrar todos los elementos comunes de los arreglos 
apuntados por arrIn1 y arrIn2 y almacenar dichos elementos en el arreglo apuntado por arrOut. 
El arreglo apuntado por arrOut NO DEBE tener elementos repetidos.

Para interactuar con el programa podrás ejecutar los siguientes comandos una vez ejecutes la aplicación: 

* arr1: para ingresar el tamaño y los elementos del primer arreglo.
* arr2: para ingresar el tamaño y los elementos del segundo arreglo.
* printArr1: para imprimir los elementos del primer arreglo.
* printArr2: para imprimir los elementos del segundo arreglo.
* compare: para comparar los arreglos llamando a la función ``arrayCommon``.
* printResult: imprime el resultado mostrando la cantidad de elementos comunes y los elementos.
* exit: para liberar la memoria y terminar el programa.

Mira un ejemplo de cómo se ejecuta y usa el programa:

.. code-block:: bash

    ./main 
    arr1
    3
    1 
    2
    3
    arr2
    4
    5
    4
    3
    2
    printArr1
    1 2 3 
    printArr2
    5 4 3 2 
    compare
    printResult
    2
    2 3

En este caso el número 3 luego del comando arr1 indica el tamaño del primer arreglo. Los elementos 
serán 1,2,3. El número 4 luego del comando arr2 indica el tamaño del segundo arreglo. Los elementos 
del segundo arreglo son 5,4,3,2. Nota que luego del comando ``compare`` se llama ``printResult`` que muestra el 
resultado para este ejemplo. El número 2 indica la cantidad de elementos comunes y los elementos comunes 
que serán 2,3.

Consideraciones
**************************

* Para compilar la aplicación escribe en la terminal el comando ``make`` una vez te cambies 
  al directorio problem1.
* Para borrar todos los archivos compilados escribe ``make clean``.
* Las pruebas locales las puedes hacer de dos maneras: manualmente y automáticamente. Ya te mostré 
  como puedes hacer las pruebas manuales. Para realizar las pruebas automáticas ejecuta el siguiente 
  comando en el directorio problem1 para aplicar todos los vectores de prueba.

  .. code-block:: bash 

      ./test-main.sh

* Si quieres hacer pruebas de manera individual ejecuta en el directorio problem1 el comando anterior 
  pero esta vez indicando el vector de prueba así:

  .. code-block:: bash 

      ./test-main.sh -t X

  Donde X puede ser un número de 1 a 7 correspondiente a las pruebas que encontrarás en el directorio 
  tests ubicado en el directorio problem1.

¿Qué pasos debes seguir para realizar la evaluación?
******************************************************

* Ingresa a tu repositorio `aquí <https://classroom.github.com/a/dKXDoh5P>`__ para que aceptes la 
  evaluación y veas que se cargue tu repositorio. No olvides presionar F5 para actualizar la página.
* Una vez ingreses a tu repositorio verifica que la carpeta .github esté presente. Si no es así 
  espera un momento y presiona F5. 
* Verifica que en la sección ``ACTIONS`` esté el Workflow ``GitHub Classroom``.
* Habla con el profesor si los pasos anteriores no están bien.
* Clona el repositorio en tu computador.
* Completa el programa mientras realizas commit y push frecuentemente.
* Realiza pruebas locales y no olvides hacer push para realizar las pruebas remotas.
* Sabrás que todo está bien cuando veas en GitHub la marca verde que indica que todos 
  los vectores de prueba pasaron.
* Procede a realizar la wiki con la sustentación. 

Enunciado de la sustentación
*********************************

Para la sustentación vas a escribir un texto en la wiki donde explicarás cómo resolviste el problema.

Criterios de evaluación
**************************

La nota estará dada por la expresión: ``(solución_problema)*sustentación``. En Github podrás ver de manera 
ponderada los puntos de cada vector de prueba que pases. Este puntaje se multiplicará por la sustentación así:

* Sustentación es 1 si haces la explicación en la wiki.
* Sustentación es 0 si no la haces y por tanto la nota sería 0.
