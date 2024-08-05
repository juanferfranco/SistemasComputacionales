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
-----

Ahora te propondré de nuevo unos mini-retos que te acercarán a la programación en alto 
nivel, pero desde el lenguaje ensamblador, precisamente para abordar la gran pregunta 
de esta unidad: ¿Cómo se pueden implementar en lenguaje ensamblador algunos conceptos 
básicos de programación en alto nivel?

¿Recuerdas los resultados de aprendizaje específicos (RAE) de este curso?

* RAE1: construyo aplicaciones interactivas aplicando patrones y estrategias que 
permitan alcanzar los requisitos funcionales y no funcionales establecidos. Se espera que 
llegues a un nivel resolutivo.
* RAE2: aplico pruebas de las partes y del todo de un software siguiendo metodologías, 
técnicas y estándares de la industria para garantizar el correcto funcionamiento de las 
aplicaciones. Se espera que llegues a un nivel autónomo.

El RAE1 lo evidenciarás con la construcción de las aplicaciones que proponen los retos, 
siguiendo los requisitos. El RAE2 lo evidenciarás con la implementación de pruebas utilizando 
el simulador.

.. note:: Para la bitácora BITÁcora

   En la bitácora vas a reportar para cada mini-reto dos cosas:

   * El código con la implementación (RAE1).
   * Explica cómo probaste las partes del programa y cómo probaste el programa completo (RAE2).

1. Escribe un programa en lenguaje ensamblador que sume los primeros 100 números naturales.

   .. code-block:: c

   int i = 1;
   int sum = 0;
   While (i <= 100){
      sum += i;
      i++;
   }

   * ¿Cómo están implementadas las variables ``i`` y ``sum``?
   * ¿En qué direcciones de memoria están estas variables?
   * ¿Cómo está implementado el ciclo ``while``?
   * ¿Cómo se implementa la variable ``i``?
   * ¿En qué parte de la memoria se almacena la variable ``i``?
   * Después de todo lo que has hecho, ¿Qué es entonces una variable?
   * ¿Qué es la dirección de una variable?
   * ¿Qué es el contenido de una variable?

2. Transforma el programa en alto nivel anterior para que utilice un ciclo 
   ``for`` en vez de un ciclo ``while``.

3. Escribe un programa en lenguaje ensamblador que implemente el programa anterior.

4. Ahora vamos a acercarnos al concepto de puntero. Un puntero es una variable que almacena 
   la dirección de memoria de otra variable. Observa el siguiente programa escrito en C++:

   .. code-block:: c

   int a = 10;
   int *p;
   p = &a;
   *p = 20;    

   El programa anterior modifica el contenido de la variable ``a`` por medio de la variable 
   ``p``. ``p`` es un puntero porque almacena la dirección de memoria de la variable ``a``. En este 
   caso el valor de la variable ``a`` será 20 luego de ejecutar ``*p = 20;``. Ahora analiza:
   
   * ¿Cómo se declara un puntero en C++? ``int *p;``. ``p`` es una variable que almacenará 
   la dirección de un variable que almacena enteros.
   * ¿Cómo se define un puntero en C++? ``p = &a;``. Definir el puntero es inicializar el valor 
   del puntero, es decir, guardar la dirección de una variable. En este caso ``p`` contendrá 
   la dirección de ``a``.
   * ¿Cómo se almacena en C++ la dirección de memoria de una variable? Con el operador ``&``. ``p = &a;``
   * ¿Cómo se escribe el contenido de la variable a la que apunta un puntero? Con el operador ``*``. ``*p = 20;``. 
   En este caso como ``p`` contiene la dirección de ``a`` entonces ``*p`` a la izquierda del igual 
   indica que quieres actualizar el valor de la variable ``a``.

5. Traduce este programa a lenguaje ensamblador:

   .. code-block:: c

   int a = 10;
   int *p;
   p = &a;
   *p = 20;   

6. Ahora vas a usar un puntero para leer la posición de memoria a la que este apunta, es decir, 
   vas a leer por medio del puntero la variable cuya dirección está almacenada en él.

   .. code-block:: c

   int a = 10;
   int b = 5;
   int *p;
   p = &a;
   b = *p;

   En este caso ``b = *p;`` hace que el valor de ``b`` cambie de 5 a 10 porque ``p`` apunta a la 
   la variable ``a`` y con ``*p`` a la derecha del igual estás leyendo el contenido de la variable 
   apuntada.

7. Traduce este programa a lenguaje ensamblador:

   .. code-block:: c

   int a = 10;
   int b = 5;
   int *p;
   p = &a;
   b = *p;

8. Vas a parar un momento y tratarás de recodar de memoria lo siguiente. Luego verifica con un 
   compañero o con el profesor.

   * ¿Qué hace esto ``int *pvar;``?
   * ¿Qué hace esto ``*pvar = var;``
   * ¿Qué hace esto ``var2 = *pvar``?
   * ¿Qué hace esto ``pvar = &var3``?

9.  Considera que el punto de entrada del siguiente programa es la función ``main``, es decir, el 
   programa inicia llamando la función ``main``. Vas a proponer una posible traducción a lenguaje 
   ensamblador de la función ``suma``, cómo llamar a suma y cómo regresar a 
   ``std::cout << "El valor de c es: " << c << std::endl;`` una vez suma termine.

   .. code-block:: cpp

      #include <iostream>

      int suma(int a, int b) {
         int var = a + b;
         return var;
      }


      int main() {
         int c = suma(6, 9);
         std::cout << "El valor de c es: " << c << std::endl;
         return 0;
      }

