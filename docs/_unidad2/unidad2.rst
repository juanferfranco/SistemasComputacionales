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


Temas
*********

* Introducción al lenguaje C


Trayecto de actividades
------------------------

Ejercicios
**********

Ejercicio 1: lenguaje de programación C
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Este será uno de los ejercicios más largos de la unidad porque vamos a introducir 
el lenguaje de programación con el cual estudiaremos los conceptos que nos quedan del curso: ``lenguaje C``.

.. toctree::
    :maxdepth: 3

    Introducción a C <./introC>

Ejercicio 2: de lenguaje de alto nivel a código ejecutable
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


Evaluación
-----------------------------------

.. warning:: FECHA DE ENTREGA Y SUSTETACIÓN 

    La evaluación debe estar en el repositorio que les daré 
    en Github y sustentada para el viernes 23 de septiembre 
    de 2022.

Enunciado 
************

Una estructura de datos típica en la solución de problemas 
de entretenimiento digital es la LISTA. Te voy a proponer un 
proyecto que hace uso de LISTAS; sin embargo, el proyecto 
está INCOMPLETO. Tu misión será completar el proyecto y pasar 
todos los vectores de prueba. Una vez termines la solución debes 
estudiarla detenidamente para preparar la sustentación. Dicha 
sustentación será una pregunta relacionada con el proyecto.

El primer reto es entender el PROBLEMA. Te dejo algunas pistas:

* El programa es interactivo, es decir, para funcionar requiere 
  que el usuario le ingrese órdenes.
* Puedes comenzar a explorar en el archivo main.c. 
* Nota que para cada comando el programa realizará acciones. Las 
  acciones llamarán funciones. Son precisamente las funciones 
  que se llaman las que tendrás que completar.

.. warning:: ESTA EVALUACIÓN ES EN EQUIPO

    Arma tu equipo de trabajo. Uno de los miembros debe crear el equipo
    y los demás se unen a ese equipo. El enlace para crear 
    el equipo y tener acceso al repositorio está `aquí <https://classroom.github.com/a/GD4pT6wn>`__.

En el directorio tests encontrarás todos los vectores de prueba. Serán 19 en total.
Los archivos .desc contienen la descripción de la prueba. Los archivos .in te 
muestran la secuencia de comandos que ejecutará el programa. Los archivos .out 
te muestran la salida esperada. Los archivos .err almacenarán el mensaje de error 
esperado. Los archivos .rc el valor que se espera que retorne el programa 
al terminar. Los archivos .run te muestran cómo se ejecuta la prueba.

.. warning:: ¿QUÉ HAGO PARA PASAR UNA PRUEBA?

  Observa cuáles son los comandos que ejecutará el programa (archivo .in) y 
  qué se espera que haga (archivo .out). Debes implementar la lógica del 
  programa que permita conseguir el resultado.

MUY IMPORTANTE 
*****************

* No uses ninguna función para imprimir en pantalla a menos que sean las que ya están en el código
  o donde se te pide que las uses. En la función ``ListEvents`` deberás imprimir cada evento 
  usando la cadena formateada ``"%s\n"`` y en caso de tener una lista vacía usarás esta función
  ``printf("empty\n");``. La razón de esto es que tu programa será verificado automáticamente 
  y por tanto, si imprimes información no esperada es posible que las pruebas automáticas fallen.
* Para compilar, cámbiate el directorio donde están los archivos ``.c`` y ejecuta el comando 
  ``make``. Ten en cuanta que con el comando ``make clean`` puedes limpiar todos los archivos 
  compilados y luego con ``make`` volver a generarlos.
* Para hacer las pruebas puedes correr todos los vectores de prueba así:

  .. code-block:: bash

    ./test-main.sh
  
  O si quiere correr solo un vector, por ejemplo, el 10, lo haces así:

  .. code-block:: bash

    ./test-main.sh -t 10

* Verifica que estás usando correctamente la memoria dinámica. Para ello instala valgrind y luego 
  realiza la verificación. Te dejo los comandos, primero para instalar valgrind y luego para verificar.

  .. code-block:: bash 

        sudo apt update
        sudo apt install valgrind

  .. code-block:: bash 

        valgrind ./main < ./tests/12.in
  
  Si la memoria está bien verás algo así en el resumen:

  .. code-block:: none
  
        ==17813== 
        ==17813== HEAP SUMMARY:
        ==17813==     in use at exit: 0 bytes in 0 blocks
        ==17813==   total heap usage: 12 allocs, 12 frees, 5,360 bytes allocated
        ==17813== 
        ==17813== All heap blocks were freed -- no leaks are possible
        ==17813== 
        ==17813== For lists of detected and suppressed errors, rerun with: -s
        ==17813== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
  
  La salida anterior se consigue ejecutando el programa con el vector de prueba 12.in. Con este 
  vector de prueba, el programa realiza 12 reservas con malloc y detecta 12 liberaciones con free. 
  Por tanto, al final indica que no hay errores.

Criterios de evaluación
*****************************

Cada vector de prueba tiene un puntaje. El puntaje de cada punto lo puedes encontrar en el 
archivo ``.github/classroom/autograding.json`` que está en tu repositorio.