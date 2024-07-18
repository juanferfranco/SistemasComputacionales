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

