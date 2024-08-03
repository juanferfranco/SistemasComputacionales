Experiencia de aprendizaje 2. Lenguaje ensamblador 
============================================================

Introducción
--------------

En esta unidad vas a explorar la pregunta ¿Cómo se pueden implementar 
en lenguaje ensamblador algunos conceptos básicos de programación en alto nivel?

Investigación 
---------------

Actividad 1
**************

En el capítulo 4 del libro 'The Elements of Computing Systems' que puedes 
encontrar `aquí <https://www.nand2tetris.org/_files/ugd/44046b_7ef1c00a714c46768f08c459a6cab45a.pdf>`__, vas 
a repasar de nuevo cómo se realizan las operaciones de entrada y salida en la plataforma de cómputo que 
estamos estudiando, es decir, la plataforma Hack y la CPU Hack. También puedes ver 
`este <https://youtu.be/gTOFd80QfBU?si=6FLpT907cx1Q_NDB>`__ video, si quieres,  
donde te explican el concepto. En la sección 4.2.5. vas a encontrar el 
concepto de entrada-salida mapeada a memoria o memory maped I/O. Analiza lo siguiente:

* ¿Qué es la entrada-salida mapeada a memoria?
* ¿Cómo se implementa en la plataforma Hack?
* Inventa un programa que haga uso de la entrada-salida mapeada a memoria.
* Investiga el funcionamiento del programa con el simulador.

Actividad 2
**************

Vas a revisar de nuevo el reto 20 de la unidad anterior. Asegúrate de entenderlo, simularlo y  
experimentar con él antes de continuar con el siguiente reto.

Actividad 3
*************

Vas a implementar y simular una modificación al retos 20 de la unidad anterior. Si se presiona 
la letra 'd' muestras la imagen que diseñaste en el reto 18. Si no se presiona ninguna tecla, 
borraras la imagen.

Actividad 4
*************

Ahora realizarás una nueva variación al programa de la actividad anterior. Si se presiona la 
letra 'd' muestras la imagen que diseñaste en el reto 18. Solo si se presiona la letra 'e' borraras 
la imagen que se muestra en pantalla.

Reto 
------

Ahora te propondré de nuevo unos mini-retos que te acercarán a la programación en alto 
nivel, pero desde el lenguaje ensamblador, precisamente para abordar la gran pregunta 
de esta unidad: ¿Cómo se pueden implementar en lenguaje ensamblador algunos conceptos 
básicos de programación en alto nivel?

1. Escribe un programa en lenguaje ensamblador que sume los primeros 100 números naturales.

   .. code-block:: c

    int i = 1;
    int sum = 0;
    While (i <= 100){
        sum += i;
        i++;
    }
 
   * ¿Cómo están implementadas las variables i y sum?
   * ¿En qué direcciones de memoria están estas variables?
   * ¿Cómo está implementado el ciclo while?
   * ¿Cómo se implementa la variable i?
   * ¿En qué parte de la memoria se almacena la variable i?
   * Después de todo lo que has hecho, ¿Qué es entonces una variable?
   * ¿Qué es la dirección de una variable?
   * ¿Qué es el contenido de una variable?

2. Transforma el programa en alto nivel anterior para que utilice un ciclo for en vez 
   de un ciclo while.

3. Escribe un programa en lenguaje ensamblador que implemente el programa anterior.

.. warning:: FALTAN OTROS retos

    Aún faltan otros retos, esta sección sigue en construcción