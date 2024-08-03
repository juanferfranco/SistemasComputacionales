Experiencia de aprendizaje 1. Arquitectura del computador
==========================================================

Introducción
--------------

En esta unidad vas a explorar las preguntas ¿Cómo funciona un computador digital 
moderno? Y ¿cómo hace este para ejecutar un programa?

El acercamiento a estas preguntas lo harás desde la perspectiva de un programador 
en lenguaje ensamblador.

Investigación 
---------------

Te voy a proponer algunas actividades para ayudarte a explorar la preguntas. La idea 
es que reportes en tu bitácora de aprendizaje lo que vas observando, reflexionando, 
experimentando y concluyendo.

Actividad 1
***************

Esta actividad te permitirá explorar la arquitectura de un computador digital moderno.
Exploremos juntos mediante un caso de estudio utilizando un simulador de un computador.

Para tu bitácora:

* ¿Qué es un computador digital moderno? 
* ¿Cuáles son sus partes?

Actividad 2
***************

Ahora vamos a explorar juntos un poco más cómo se ejecuta el programa del caso de estudio 
anterior, pero esta vez utilizaremos un simulador diferente.

Para tu bitácora:

* ¿Qué es entonces un programa?
* ¿Qué es un lenguaje ensamblador?
* ¿Qué es lenguaje de máquina?

Actividad 3
***************

Seguimos analizando nuestro caso de estudio: 

* ¿Qué son PC, D y A?
* ¿Para qué los usa la CPU? 

Actividad 4
***************

Considera el siguiente fragmento de código en lenguaje ensamblador:

.. code:: bash

    @16384
    D = A
    @16
    M = D

El resultado de este programa es que guarda en la posición 16 de la RAM el valor 16384. Ahora 
escribe un programa en lenguaje ensamblador que guarde en la posición 32 de la RAM un 100.

Actividad 5
***************

Para tu sesión de trabajo independiente, te propondré que revises uno de estos 
dos recursos:

* Videos 4.3 a 4.8 del curso From Nand to Tetris Part 1. Puedes aumentar un poco la velocidad 
  de los videos para que te dé tiempo de verlos todos. Mira, la idea es que te des una idea, no 
  tienes que entender todo a la perfección.
  `Playlist de youtube <https://youtube.com/playlist?list=PLrDd_kMiAuNmSb-CKWQqq9oBFN_KNMTaI&si=AntL-bx5HV9QxTyO>`__.
* Si prefieres leer, puedes revisar el capítulo 4 del libro "The Elements of Computing Systems" 
  que puedes encontrar `aquí <https://www.nand2tetris.org/_files/ugd/44046b_7ef1c00a714c46768f08c459a6cab45a.pdf>`__.

Reto 
------

Este reto consiste en la elaboración de una serie de programas en lenguaje ensamblador. 

* Para realizar las pruebas puedes utilizar uno de los simuladores que puedes 
  encontrar `aquí <https://www.nand2tetris.org/software>`__. 
* El simulador que hemos venido utilizando es `este <https://nand2tetris.github.io/web-ide/chip/>`__. 
* Utiliza Google Chrome o Microsoft Edge para abrir el simulador.
* Cada que modifiques el programa, asegúrate de guardar el archivo, actualizar la página web y cargar 
  el archivo nuevamente.

1. Carga en D el valor 1978.
2. Guarda en la posición 100 de la RAM el número 69.
3. Guarda en la posición 200 de la RAM el contenido de la posición 24 de la RAM
4. Lee lo que hay en la posición 100 de la RAM, resta 15 y guarda el resultado en la posición 100 de la RAM.
5. Suma el contenido de la posición 0 de la RAM, el contenido de la posición 1 de la RAM y con la
   constante 69. Guarda el resultado en la posición 2 de la RAM.
6. Si el valor almacenado en D es igual a 0 salta a la posición 100 de la ROM.
7. Si el valor almacenado en la posición 100 de la RAM es menor a 100 salta a la posición 20 de la ROM.
8. Considera el siguiente programa:

   .. code:: bash

      @var1
      D = M
      @var2
      D = D + M
      @var3
      M = D
    
   * ¿Qué hace este programa?
   * En qué posición de la memoria está var1, var2 y var3? ¿Por qué en esas posiciones?

9. Considera el siguiente programa:

   .. code:: c

        i = 1
        sum = 0
        sum = sum + i
        i = i + 1

   La traducción a lenguaje ensamblador del programa anterior es:

   .. code:: bash

      // i = 1
      @i
      M=1
      // sum = 0
      @sum
      M=0
      // sum = sum + i
      @i
      D=M
      @sum
      M=D+M
      // i = i + 1
      @i
      D=M+1
      @i
      M=D


   * ¿Qué hace este programa?
   * ¿En qué parte de la memoria RAM está la variable i y sum? ¿Por qué en esas posiciones?
   * Optimiza esta parte del código para que use solo dos instrucciones:

     .. code:: bash

        // i = i + 1
        @i
        D=M+1
        @i
        M=D

10. Las posiciones de memoria RAM de 0 a 15 tienen los nombres simbólico R0 a R15.
    Escribe un programa en lenguaje ensamblador que guarde en R1 la operación 2 * R0.
11. Considera el siguiente programa:

    .. code:: c

        i = 1000
        LOOP:
        if (i == 0) goto CONT
        i = i - 1
        goto LOOP
        CONT:

    La traducción a lenguaje ensamblador del programa anterior es:

    .. code:: bash

        // i = 1000
        @1000
        D=A
        @i
        M=D
        (LOOP)
        // if (i == 0) goto CONT
        @i
        D=M
        @CONT
        D;JEQ
        // i = i - 1
        @i
        M=M-1
        // goto LOOP
        @LOOP
        0;JMP
        (CONT)

    * ¿Qué hace este programa?
    * En qué memoria está almacenada la variable i? ¿En qué dirección de esa memoria?
    * ¿En qué memoria y en qué dirección de memoria está almacenado el comentario //i = 1000?
    * ¿Cuál es la primera instrucción del programa anterior? ¿En qué memoria y en qué 
      dirección de memoria está almacenada esa instrucción?
    * ¿Qué son CONT y LOOP? 
    * ¿Cuál es la diferencia entre los símbolos i y CONT?

12. Implemente en ensamblador:

    .. code:: C

      R4 = R1 + R2 + 69

13. Implementa en ensamblador:

    .. code:: none
      
        if R0 >= 0 then R1 = 1
        else R1 = –1

        (LOOP)
        goto LOOP

14. Implementa en ensamblador:

    .. code:: C

      R4 = RAM[R1]

15. Implementa en ensamblador el siguiente problema. En la posición R0 está almacenada 
    la dirección inicial inicial de una región de memoria. En la posición R1 está 
    almacenado el tamaño de la región de memoria. Almacena un -1 en esa región de memoria.

16. Implementa en lenguaje ensamblador el siguiente programa:


    .. code:: csharp

        int[] arr = new int[10];
        int sum = 0;
        for (int j = 0; j < 10; j++) {
            sum = sum + arr[j];
        }

    * ¿Qué hace este programa?
    * ¿Cuál es la dirección base de arr en la memoria RAM?
    * ¿Cuál es la dirección base de sum en la memoria RAM y por qué?
    * ¿Cuál es la dirección base de j en la memoria RAM y por qué?

17. Implementa en lenguaje ensamblador:

    .. code:: c

      if ( (D - 7) == 0) goto a la instrucción en ROM[69]

18. Utiliza `esta <https://nand2tetris.github.io/web-ide/bitmap>`__ herramienta para dibujar un bitmap en la pantalla.
19. Analiza el siguiente programa en lenguaje de máquina:

    .. code:: bash

        0100000000000000
        1110110000010000
        0000000000010000
        1110001100001000
        0110000000000000
        1111110000010000
        0000000000010011
        1110001100000101
        0000000000010000
        1111110000010000
        0100000000000000
        1110010011010000
        0000000000000100
        1110001100000110
        0000000000010000
        1111110010101000
        1110101010001000
        0000000000000100
        1110101010000111
        0000000000010000
        1111110000010000
        0110000000000000
        1110010011010000
        0000000000000100
        1110001100000011
        0000000000010000
        1111110000100000
        1110111010001000
        0000000000010000
        1111110111001000
        0000000000000100
        1110101010000111

    * ¿Qué hace este programa?

20. Implementa un programa en lenguaje ensamblador que dibuje el bitmap que diseñaste en la 
    pantalla solo si se presiona la tecla 'd'.


