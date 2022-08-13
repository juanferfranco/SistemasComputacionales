Unidad 1. Arquitectura del computador
=======================================

Introducción
--------------

En esta unidad vas a aprender los bloques de construcción básicos del hardware de un sistema de cómputo 
moderno, cómo esos bloques pueden combinarse para construir computadores y cómo hacen para ejecutar 
programas.

Propósito de aprendizaje
****************************

Comprender cómo funciona el hardware de un computador moderno desde una perspectiva sistémica, es decir, 
estudiando las partes que lo componen y cómo se conectan para conseguir funciones más complejas.

Te acercarás al lenguaje de programación ensamblador y verás la relación de este con el lenguaje C.

Temas
********

* Organización básica de un computador digital moderno.
* Lenguaje de máquina-lenguaje ensamblador-lenguaje C

Trayecto de actividades
------------------------

Estos ejercicios te servirán para preparar la evaluación de esta unidad. Realiza 
cada uno con detenimiento y consciencia. No dejes de preguntar si tienes 
dudas.

Ejercicios
***********

Ejercicio 1: Demo 
^^^^^^^^^^^^^^^^^^^^

Verifica si en tu sistema tienes la aplicación Digital (escribe Digital en el lanzador de 
aplicaciones). Si no la tienes la puedes descargar `aquí <https://github.com/juanferfranco/SistemasComputacionales/tree/main/docs/_static/Digital.zip>`__

Si tuviste que descargar la aplicación, la puedes descomprimir en el directorio ``apps``. Luego 
abre el directorio en la terminal (click derecho, open in terminal). Ejecuta el archivo 
install.sh. Abre la aplicación.

Ve a la opción Edit/Settings/Advanced y en Java library adiciona 
esta biblioteca que está en ``Digital/custom/digitaln2t-1.0-SNAPSHOT.jar``.

Ahora abre el archivo demo que está en ``Digital/custom/project05/ComputerFull4Key.dig``.

Debes ver algo así:

.. image:: ../_static/HackComputer.png
  :alt: HackComputer demo
  :align: center
  :width: 100%

|

Por ahora nota que hay tres bloques de interés: ROM (Program), CPU y 
Memory. Dale click derecho al bloque que dice ROM, selecciona Advance y en la opción 
File carga el archivo ``Digital/custom/project05/fill.hex``. Las primeras líneas 
del archivo fill.hex se ven así::

  :020000000040BE
  :0200020010EC00
  :020004001000EA
  :0200060008E30D
  :02000800006096
  :02000A0010FCE8
  :02000C001300DF
  :02000E0005E308 

En esas líneas están almacenados los códigos de máquina de las instrucciones que 
ejecutará la CPU.

En este punto ya tienes configurado el DEMO. Se trata de un computador de 16 bits 
que ejecutará un programa almacenado en la memoria ROM. Para ejecutar el programa 
selecciona ``Simulation/Start of Simulation``. Nota el ícono de este comando. 
Puedes iniciar la simulación usando el botón marcado con el mismo ícono. Al iniciar 
la simulación se activa el botón que la detiene (botón con 
el cuadrado de color rojo).

Un vez inicie la simulación presiona con el mouse una de las teclas marcadas con los 
números 1, 2, 3 o 4. Se activará una ventana titulada HACK Display. Esta ventana 
simula una pantalla de 512 pixels de ancho por 256 pixels de alto. Mueve la ventana 
hacia la izquierda en caso de que te impida el acceso a las teclas. Deja presionada 
cualquiera de las teclas. Verás que los pixels del Hack Display se encenderán de color 
negro. Si dejas de presionar la tecla los pixels cambiarán a blanco.

.. tip:: CON ESTE COMPUTADOR PODEMOS HACER JUEGOS

  El computador que acabas de simular tiene todos los elementos para ejecutar 
  juegos. Tiene una memoria (ROM) para almacenar las instrucciones y datos iniciales del juego. 
  Tiene un circuito para ejecutar las instrucciones (CPU). Tiene una memoria para ir 
  almacenando cómo va cambiando el juego (Memory). Tiene teclado y pantalla (periféricos de 
  entrada salida).

Si ya terminaste de experimentar, cierra la ventana HACK Display y termina la simulación.

Ejercicio 2: concepto de programa almacenado
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora te mostraré el programa que está ejecutando el computador. Este programa está ALMACENADO 
en la memoria de programa (ROM). Puedes pensar la memoria como un arreglo de ``n posiciones`` donde 
cada posición tiene un índice o ``dirección`` que va desde la posición 0 para el primer componente 
del arreglo hasta la posición n-1 para el último. En cada posición se almacena un código de máquina que la 
CPU ``LEERÁ`` (leer), ``DECODIFICARÁ`` (entender) y ``EJECUTARÁ`` (realizar la operación solicitada):

========= ==================
Dirección Código de máquina  
========= ================== 
0	        0100000000000000
1	        1110110000010000
2	        0000000000010000
3	        1110001100001000
4	        0110000000000000
5	        1111110000010000
6	        0000000000010011
7	        1110001100000101
8	        0000000000010000
9	        1111110000010000
10	      0100000000000000
11	      1110010011010000
12	      0000000000000100
13	      1110001100000110
14	      0000000000010000
15	      1111110010101000
16	      1110101010001000
17	      0000000000000100
18	      1110101010000111
19	      0000000000010000
20	      1111110000010000
21	      0110000000000000
22	      1110010011010000
23	      0000000000000100
24	      1110001100000011
25  	    0000000000010000
26	      1111110000100000
27	      1110111010001000
28	      0000000000010000
29	      1111110111001000
30	      0000000000000100
31	      1110101010000111
========= ================== 

Muy claro el programa, ¿Verdad? :) 

Estas cadenas de unos y ceros no resultan fáciles de entender para las personas. Afortunadamente, 
cada cadena puede representarse de manera simbólica así:

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

Al lenguaje anterior se le conoce como lenguaje ensamblador y tiene una correspondencia uno a uno 
con el lenguaje de máquina. AL proceso de convertir el programa de lenguaje ensamblador a lenguaje 
de máquina se le conoce como ``ENSAMBLADO``.

¿Ahora si es más claro qué hace el programa? Puede que no. El lenguaje ensamblador es más 
fácil de leer y escribir que el lenguaje de máquina, pero sigue siendo un reto para las 
personas escribir programas a ese nivel. Adicionalmente, ten presente que el lenguaje de máquina 
y el lenguaje ensamblador son PARTICULARES para cada CPU. Eso quiere decir que tendrás que aprender 
tantos lenguajes ensamblador como CPU donde quieres que se ejecute tu programa.

¿Hay alguna manera de escribir un programa en un único lenguaje? Si. Mediante los lenguajes 
de alto nivel. Tu ya conoces uno, C#. Si programas en un lenguaje de alto nivel puedes 
generar el lenguaje en ensamblador mediante un proceso conocido como ``COMPILACIÓN``. Este 
proceso es realizado por una herramienta particular para cada CPU llamada ``COMPILADOR``. 

Ahora te voy a mostrar una nueva versión del programa, pero esta vez en un lenguaje de alto 
nivel conocido como C++:

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

.. note:: RETO

    ¿Te animas ahora si a decir qué hace el programa? Trata de analizarlo, pero no te 
    preocupes porque en un momento lo discutiremos.

Si te gusta la historia, te voy a dejar `aquí <https://youtu.be/cozcXiSSkwE>`__ un documental 
muy corto sobre la invención del programa almacenado.

Ejercicio 3: concepto de variable
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

El arreglo MEMORY representa al circuito Memory que te mostré previamente en el diagrama del computador. 
``MEMORY[16]`` representa el contenido de la posición de memoria 16, es decir, MEMORY[16] es una 
``VARIABLE``. Entonces una variable no es más que la representación del contenido de una posición de 
memoria, en este caso, la posición 16. Ten presente que en los programas que has usado hasta ahora 
no has tenido que indicar de manera explícita la dirección o posición de la variable, sino que usas 
un NOMBRE, el nombre de la variable para representar el contenido de esa posición de memoria.

.. note:: PARA REFLEXIONAR

  ¿Cuando usas el nombre de la variable en un programa te refieres a su dirección o 
  a su contenido? Por ejemplo::

    variable1 = variable2 + 1;

  ¿Qué está pasando en la expresión anterior? Piensa en direcciones y contenido cuando 
  analices la pregunta.


Ejercicio 4: concepto de entrada-salida mapeada a memoria
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

La variable ``MEMORY[KEYBOARD]`` es especial. En esa posición se almacena un cero 
si no hay una tecla presionada o un valor diferente de cero que indica cuál tecla se presionó. ¿Notas que 
leer si hay una tecla presionada o no es como leer una variable? a esto se le conoce 
como ``entrada-salida mapeada a memoria``. ¿Cómo aparece el valor en memoria? Primero observa que al bloque 
Memory se conectan cuatro teclas marcadas como ``1, 2, 3 y 4``. Internamente, Memory tiene 
un circuito que se encarga de determinar qué tecla está presionada y luego almacena un número que la 
representa en la posición de memoria que denota KEYBOARD que será la dirección 24576 para este 
computador.

El programa también está haciendo una operación de salida. Está pintando en pantalla. El truco es 
el mismo (entrada-salida mapeada a memoria). La pantalla del computador tiene 256x512 pixeles, es decir, 
131072 pixeles. Esos pixeles están asociados a ciertas posiciones de memoria. En este caso desde 
la dirección ``16384`` hasta la ``24575``.
De igual manera que en el caso del teclado, en Memory hay un circuito que lee las posiciones 
de memoria anteriores y pinta en la pantalla la información que allí se encuentra.

Nota esta línea::

  MEMORY[MEMORY[16]] = 0xFFFF;;

Supón que en MEMORY[16] está almacenado el valor 16384, es decir, la dirección inicial del rango 
de posiciones que representan a la pantalla. Por tanto, se puede transformar la línea anterior a::

  MEMORY[16384] = 0xFFFF;

¿Qué significa ``0xFFFF``? Es un número en base 16. A diferencia del sistema base 10 que usamos 
todo el tiempo, el sistema base 16 tiene 16 símbolos para representar cantidades numéricas. Tiene 
los mismos 10 símbolos del sistema base 10 (0, 1, 2, 3, 4, 5, 6, 7, 8, 9) y 6 más (A, B,C, D, E, F). 
En este caso, el número ``0xFFFF`` indica que todos los pixeles representados en la posición 
16384 deben encenderse. Nota también la línea::

  MEMORY[MEMORY[16]] = 0x0000;

Si MEMORY[16] tiene almacenado el valor 16384 entonces se está indicando lo contrario, es decir, 
los pixeles representados por esa posición de memoria se deben apagar.


.. note:: RETO (continuación)

   ¿Te animas ahora a explicar el programa? 

Ejercicio 5: fetch-decode-execute
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Cómo funciona una CPU? En términos generales una CPU hace tres cosas: fetch o 
buscar una instrucción. Las instrucciones están guardadas, en 
nuestro computador de ejemplo, en la memoria de programa. Luego la CPU decodifica 
la instrucción, es decir, determina qué operación debe realizar. Finalmente, 
la ejecuta, es decir, realiza la operación decodificada.

Regresemos a nuestro programa y analicemos detenimiento cómo se ejecuta. ¿En qué 
dirección de la memoria de programa inicia la ejecución? La CPU inicia a buscar 
instrucciones en la dirección 0 de la memoria de programa:

.. image:: ../_static/CPURest.png
  :alt: la CPU inicia
  :align: center

Nota en la figura la salida PC del circuito de la CPU. Esta salida se conecta a la 
entrada ``A`` de la memoria ROM. La entrada A es la entrada de dirección de la memoria. 
En respuesta, la memoria ROM muestra en su salida D el contenido de la posición 
presentada en A. En este caso el número en D es el 0x4000. Quiere decir que 
en la posición 0 de la memoria ROM está almacenado el número 0x4000. Si cambias el contenido 
de la posición 0 estarás cambiando la primera instrucción del programa. La instrucción 
0x4000 es leída por la CPU por medio de la entrada ``instruction`` y comienza el 
proceso de decodificación. 

¿Qué hace la instrucción 0x4000? Para entender mejor la instrucción te voy a mostrar 
cómo convertir el número 0x4000 a su representación binaria. 

Ejercicio 6: números en base 2
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

La representación binaria no es más que la representación en base 2. Ten presente 
que así como en base 10 hay 10 símbolos, en base 16 hay 16 símbolos, 
en base 2 solo tendrás dos símbolos: 0 y 1. Mira con detenimiento la siguiente tabla
que te muestra lo mismos números representados en las tres bases:

======== ======== ==================
Base 10  Base 16  Base 2
======== ======== ==================
0         0       0000
1         1       0001
2         2       0010
3         3       0011
4         4       0100
5         5       0101
6         6       0110
7         7       0111
8         8       1000
9         9       1001
10        A       1010
11        B       1011
12        C       1100
13        D       1101
14        E       1110  
15        F       1111
======== ======== ==================

Convertir de base 16 a base 2 es muy fácil. Solo tienes que representar 
``cada símbolo`` en base 16 por su equivalente en base 2. Así el símbolo 4 
en base 16 se representa por medio de 3 bits: 100. Te estarás preguntando 
¿Qué es un bit? ¿Por qué 3 bits si en la tabla me muestras 4 bits? Un bit 
no es más que un símbolo de la representación en binario. En la cadena 
100 el bit más significativo, el que está más a la izquierda, es ``1`` y el 
menos significativo, el que está más a la derecha, es ``0``. Así como en 
base 10, los ceros a la izquierda no modifican la representación del número. 
Por tanto 0100 es equivalente a 100. Regresando a la cuestión inicial, observa:

======== ===================
Base 16   Base 2
======== ===================
0x4000   0100 0000 0000 0000
======== ===================

Qué tal si tu mismo lo intentas:

======== ===================
Base 16   Base 2
======== ===================
0x1234   0001 0010 0011 0100
0xF0A2   1111 0000 1010 0010 
0xFFFF   ?
0x0C0D   ?
0x40B0   ? 
======== ===================

Ejercicio 7: instrucciones tipo A
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Las instrucciones de la CPU que estamos analizando tienen 16 bits. 
La CPU cuenta únicamente con dos tipos de instrucciones. Las instrucciones tipo A 
y las instrucciones tipo C. Las instrucciones tipo A tienen, TODAS, el bit de mayor 
peso siempre en 0. Por su parte, las instrucciones tipo C tienen los tres bits de 
mayor peso SIEMPRE en 111.

¿De qué tipo es la instrucción 0x4000? Convierte de nuevo a base 2 el número. 
Fíjate en los bits de mayor peso. ¿Te diste cuenta? se trata de una instrucción tipo A 
porque el bit de mayor peso está en 0. ¿Qué hacen las instrucciones tipo A? Estas 
instrucciones SIEMPRE hacen lo mismo: almacenan en el circuito de la CPU los 15 
bits menos significativos de la instrucción. ¿En dónde se almacenan esos bits? en 
una memoria interna de la CPU llamada ``REGISTRO A``.

En resumen. La instrucción tipo A 0x4000 al ejecutarse hace que la CPU almacene el 
número 0x4000 en el ``REGISTRO A``. Pero profe, me habías dicho que solo almacenaba 
los 15 bits de menor peso de la instrucción y ahora me muestras 16 bits (0x4000). No 
te preocupes, lo que pasa es que se adiciona un bits más, a la izquierda, pero ese 
bit es 0. Tu me dirás entonces si esto cambia el número o no.


Ejercicio 8: conversión de base 2 a base 10
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Puedes regresar unos ejercicios antes y ver la representación del programa 
en lenguaje ensamblador? ¿Cuál sería la representación simbólica de la instrucción 
0x4000 en lenguaje ensamblador? ¡Excelente! En efecto es 
@16384. Y como sabemos que es una instrucción tipo A podemos decir que la CPU 
está cargando en el registro A el número 16384. ¿Qué? ¿Te perdiste? Tranquilo vas 
bien. Si pensaste que el valor cargado en el registro A era 0x4000 déjame decirte 
que estás entendiendo. Lo que pasa es que 0x4000 es el número 16384 en base 10. 
¿Cómo se convierte? Mira, es muy fácil:

* Escribe 0x4000 en base 2: 0100 0000 0000 0000
* Cada uno de los bits tiene un peso. El bit menos significativo (:math:`b_0`) tiene 
  un peso de :math:`2⁰` el siguiente hacia la izquierda (:math:`b_1`) :math:`2¹` 
  y así sucesivamente hasta la posición 16 (:math:`b_{15}`) que tendrá un peso de :math:`2^{15}`.
* Puedes calcular el valor en base 10 así:

  .. math::
    \sum_{i=0}^{15} 2^i*b_i = 2^{14}*1 = 16384

Ejercicio 9: instrucciones tipo C
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Luego de buscar la instrucción en la posición 0 de la ROM, decodificarla y 
ejecutarla ¿Qué sigue? La verdad es muy simple la respuesta ¿Quieres intentarlo? 
La CPU busca ahora en la dirección 1 de la ROM y así seguirá a menos que una 
de las instrucciones que ejecute le indique que debe buscar en otra posición 
de la memoria ROM.

Observa la siguiente figura:

.. image:: ../_static/CPUPos1.png
  :alt: la CPU inicia
  :align: center

¿Qué valor tiene la instrucción almacenada en la posición 1 de la memoria ROM?

Tienes razón es 0xEC10. La convertimos juntos a base 2:

======== ===================
Base 16   Base 2
======== ===================
0xEC10   1110 1100 0001 0000
======== ===================

¿Qué tipo de instrucción es? ¿Será tipo A? No porque el bit de mayor peso no 
es 0. ¿Será tipo C? Si porque los tres bits de mayor peso son 1. ¡Genial! ¿Qué 
hace esta instrucción? Esta respuesta es un pelín (pero solo un pelín) más complicada. 
Resulta que las instrucciones tipo C pueden hacer MUCHAS cosas. Observa de nuevo el 
programa en lenguaje ensamblador. Dime cuál es la representación 
en ese lenguaje de la instrucción 0xEC10. ¿Ya lo tienes? Muy bien, la representación 
es ``D=A``. En general una instrucción tipo C se represente en lenguaje 
ensamblador así: 

``destino=operación;salto``

Los campos destino y salto son opcionales. 
Si los omites entonces debes hacer lo mismo con los símbolos = y ; respectivamente. En ``D=A`` el 
destino será C y la operación es A. Te explico. D es otro REGISTRO de la CPU. Llevamos tres. 
El registro A, el registro D y el registro PC. ¿PC? Si, en este registro se almacena la dirección 
de la instrucción que se está ejecutando. Por tanto ``D=A`` almacena en el registro 
D el contenido del registro A. Como te comenté, las instrucciones tipo C codifican MUCHAS 
funciones. Cada uno de los 16 bits de la instrucción tipo C sirve para indicar qué debe hacer la 
CPU. Observa:

  1 1 1 a c1 c2 c3 c4 c5 c6 d1 d2 d3 j1 j2 j3

* Los tres bit de mayor peso siempre en 1 indicando que es una instrucción tipo C.
* a c1 c2 c3 c4 c5 c6 indican la operación que debe realizar la CPU.
* d1 d2 d3 indican el destino o el resultado de la operación.
* j1 j2 j3 indican si debe ocurrir un salto, es decir, si el registro PC debe 
  modificarse con un valor particular para saltar a una posición específica de la memoria 
  de programa.

¿Cuáles son las posibles operaciones?

.. note:: ¿Qué es Memoria[A] en tabla?

    Se refiere al contenido de la posición de memoria cuya dirección 
    está almacenada en el registro A.

==================== =========================================================
a c1 c2 c3 c4 c5 c6  Operación 
==================== =========================================================
0 1 0 1 0 1 0        Produce un 0
0 1 1 1 1 1 1        Produce un 1
0 1 1 1 0 1 0        Produce un -1
0 0 0 1 1 0 0        Lee el valor del registro D
0 1 1 0 0 0 0        Lee el valor del registro A
0 0 0 1 1 0 1        Invierte todos los bits del registro D
0 1 1 0 0 0 1        Invierte todos los bits del registro A
0 0 0 1 1 1 1        Realiza el complemento a 2 del registro D: -D
0 1 1 0 0 1 1        Realiza el complemento a 2 del registro A: -A
0 0 1 1 1 1 1        Realiza D+1
0 1 1 0 1 1 1        Realiza A+1
0 0 0 1 1 1 0        Realiza D-1
0 1 1 0 0 1 0        Realiza A-1
0 0 0 0 0 1 0        Realiza D+A
0 0 1 0 0 1 1        Realiza D-A
0 0 0 0 1 1 1        Realiza A-D  
0 0 0 0 0 0 0        Realiza D and A bit a bit
0 0 1 0 1 0 1        Realiza D or A bit a bit
1 1 1 0 0 0 0        Lee el valor Memoria[A]     
1 1 1 0 0 0 1        Invierte todos los bits de Memoria[A]   
1 1 1 0 0 1 1        Realiza el complemento a 2 de Memoria[A]: -Memoria[A] 
1 1 1 0 1 1 1        Realiza Memoria[A] + 1 
1 1 1 0 0 1 0        Realiza Memoria[A] - 1
1 0 0 0 0 1 0        Realiza D+Memoria[A]
1 0 1 0 0 1 1        Realiza D-Memoria[A]
1 0 0 0 1 1 1        Realiza Memoria[A]-D
1 0 0 0 0 0 0        Realiza D and Memoria[A] bit a bit
1 0 1 0 1 0 1        Realiza D or Memoria[A] bit a bit 
==================== =========================================================

¿Cuáles son las posibles destinos?

========= ====================================
d1 d2 d3  Destino 
========= ====================================
0 0 0     Ninguno
0 0 1     Almacena en Memoria[A]
0 1 0     Almacena en D
0 1 1     Almacena en Memoria[A] y en D
1 0 0     Almacena en A
1 0 1     Almacena en A y en Memoria[A]
1 1 0     Almacena en A y en D
1 1 1     Almacena en A, en Memoria[A] y en D
========= ====================================

Y ¿Cuáles son las posibles saltos?

Aquí tengo que explicarte antes varias cosas. Las instrucciones tipo C con saltos modifican el PC. 
Estas instrucciones son MUY, MUY importantes porque permiten modificar el ``FLUJO DEL PROGRAMA``.
¿Para que sirve modificar el flujo del programa? Pues nada más ni nada menos que para 
implementar estructuras de control como los IF, los WHILE, los FOR, etc. Estas instrucciones 
dependen de las operaciones que realiza la CPU, basado en esas operaciones se decide 
si el salto se realiza o no. ¿Hacia que dirección de memoria ROM se salta? Tu lo decides 
previamente almacenando en el registro A el valor de la dirección.

========= ============== ==================================
j1 j2 j3  Mnemotécnico   Efecto 
========= ============== ==================================
0 0 0                    No modifica el PC
0 0 1     JGT            Si operación > 0 entonces PC = A  
0 1 0     JEQ            Si operación == 0 entonces PC = A  
0 1 1     JGE            Si operación >= 0 entonces PC = A   
1 0 0     JLT            Si operación < 0 entonces PC = A   
1 0 1     JNE            Si operación != 0 entonces PC = A   
1 1 0     JLE            Si operación <= 0 entonces PC = A   
1 1 1     JMP            No hay condición PC=A 
========= ============== ==================================

.. note:: RETO

  Con toda la información anterior te animas a analizar la instrucción 
  D=A

.. note:: ALERTA DE SPOILER 

  Ahora analicemos juntos para que repases

La instrucción ``D=A`` tiene la representación en hexadecimal y en binario así:

======== ===================
Base 16   Base 2
======== ===================
0xEC10   1110 1100 0001 0000
======== ===================

Analizando de izquierda a derecha:

* 111: instrucción tipo C 
* 0 1100 00: a c1 c2 c3 c4 c5 c6. Esta combinación indica que la operación es leer 
  el registro A.
* 01 0: d1 d2 d3. Almacenar en el registro D.
* 000: no modifica el PC, no hace salto. La próxima instrucción la tomará de PC = PC + 1.

Ejercicio 10: escribir una variable
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Continuamos analizando el programa:

========= ===================
Dirección Código ensamblador  
========= =================== 
0	        @16384
1	        D=A
2	        @16
3	        M=D
========= =================== 

Las instrucciones @16 y M=D permiten almacenar en una variable ubicada en la dirección de 
memoria 16 el valor 16384. Observa la siguiente figura:

.. image:: ../_static/CPUPos3.png
  :alt: CPU-dirección 3
  :align: center

¿Qué instrucción está ejecutado la CPU?

Muy bien, se ejecuta M=D. Observa la salida addressM de la CPU. ¿Ves un 0x10? este número 
corresponde a la dirección donde se almacenará el valor en Memory. En la salida outM de la CPU ¿Puedes 
ver el 0x4000? Pues ese es precisamente el 16384 que será almacenado.

Te voy a preguntar algo. Si cambio el orden de las instrucciones así:

========= ===================
Dirección Código ensamblador  
========= =================== 
0	        @16
1	        D=A
2	        @16384
3	        M=D
========= =================== 

¿El resultado es el mismo?

Ejercicio 11: RETO
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Te animas a traducir las instrucciones anteriores a lenguaje de máquina? Recuerda 
que ya tienes la respuesta para que compares, pero la idea es que practiques. ¿Vale?

Ejercicio 12: leer una variable e implementación de un IF
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

En el ejercicio anterior, la instrucción ``M=D`` guarda en memoria el valor 
que esté en D. ¿Recuerdas en qué dirección de memoria? La dirección será 
el último valor que almacenes en el registro A.

Observa las siguientes instrucciones:

========= ===================
Dirección Código ensamblador  
========= =================== 
4	        @24576
5	        D=M
6	        @19
7	        D;JNE
========= =================== 

En la instrucción ``D=M`` M está a la derecha del igual. En este caso la CPU NO está escribiendo 
en memoria, sino que está leyendo. ¿De qué dirección lee? La dirección será el último 
valor almacenado en el registro A. Por tanto, en este caso la CPU está guardando en el 
registro D el contenido de la dirección de memoria 24576. ¿Recuerdas que hay en esa dirección? 
MUY BIEN. Así es, ahí está el código de la tecla actualmente presionada o cero si no hay tecla 
presionada.

Ahora mira las instrucciones @19 y D;JNE. La primera almacena un 19 en el registro A. 
La segunda hace UNA OPERACIÓN Y UN SALTO. Nota que el resultado de la operación NO SE GUARDA.
¿Cual es la operación? Leer el contenido del registro D. En ese registro previamente se había 
almacenado el valor de la posición de memoria 24576. Si D es igual a cero quiere decir que no 
se está presionando una tecla. Si D es diferente a cero indica que se está presionando 
una tecla. ¿Puedes ver entonces lo que pasa? Si se está presionando una tecla el valor de D 
será diferente de cero. Por tanto, la operación será diferente de cero y el contador de programa 
se escribirá con un 19. Por consiguiente, la próxima instrucción a ejecutar no será la que esté 
almacenada en la dirección 8 de la ROM sino la que esté en la posición 19. 

========= ============== ==================================
j1 j2 j3  Mnemotécnico   Efecto 
========= ============== ==================================
1 0 1     JNE            Si operación != 0 entonces PC = A   
========= ============== ==================================

¿Te diste cuenta lo que pasó? Acabas de ver en vivo y en directo la implementación de 
una estructura de control IF-ELSE. ``SI`` hay tecla presionada se ejecutan la instrucción en la 
dirección 19 de la ROM, ``SINO`` se ejecuta la instrucción en la dirección 8 de la ROM.

Ahora te voy a dar un momento para que respires profundo y te seques las lágrimas. ¡NO ES PARA 
MENOS!

Ejercicio 13: ¡EL RETO!
^^^^^^^^^^^^^^^^^^^^^^^^^
Es hora de tu primera transformación ``Saiyajin``. Con todo lo que has aprendido 
vas a analizar el programa en lenguaje C++ y vas a traducirlo a lenguaje ensamblador. 
RECUERDA que ya tienes la respuesta, pero la idea es que intentes llegar a la traducción 
tu mismo:

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

Ejercicio 14: porque te encanta leer
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Quieres leer un poco más? Te voy a dejar un enlace al capítulo 4 de uno de nuestros 
textos guía `aquí <https://b1391bd6-da3d-477d-8c01-38cdf774495a.filesusr.com/ugd/44046b_7ef1c00a714c46768f08c459a6cab45a.pdf>`__.

Responde las siguientes preguntas:

#. Muestra una instrucción tipo A en representación simbólica y en lenguaje de máquina. 
   Explica qué hace esta instrucción.
#. Muestra una instrucción tipo C en representación simbólica y en lenguaje de máquina. 
   Explica qué hace esta instrucción.
#. En el lenguaje hack (lenguaje ensamblador de la CPU estudiada) ¿Qué son los símbolos? muestra 
   varios ejemplos de estos.
#. ¿Qué son los labels? ¿Para qué sirven? ¿En que se diferencian de los símbolos?

Ejercicio 15: practica con otro ejercicio
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Con este ejercicio vas a practicar la traducción a lenguaje 
ensamblador partiendo de un programa en alto nivel. Para escribir 
el programa en Visual Studio Code te voy a pedir que instales 
una herramienta que reconozca el lenguaje ensamblador del 
procesador que has estado estudiando. El objetivo es que el 
código se vea más bonito. Vas a instalar `esta <https://marketplace.visualstudio.com/items?itemName=Throvn.nand2tetris>`__ 
extensión así:

* Abre Visual Studio Code.
* Ingresa al buscador de extensiones. Lo encuentras dando click al ícono con los cuatro cuadrados, 
  al lado izquierdo de la interfaz de usuario.
* En el campo ``search extensions in marketplace`` puedes escribir la palabra nand2tetris. 
  El autor de la extensión es Louis.
* Click en ``install``.

En la página 65 del capítulo 4 del texto guía tienes el siguiente programa:

.. code-block:: c

  int i = 1;
  int sum = 0;
  While (i <= 100){
    sum += i;
    i++;
  }

La idea es que hagas la traducción de este programa a lenguaje ensamblador.

.. warning:: IMPORTANTE

  En la página 65 del capítulo 4 está la solución, PERO TRATA SIN VER, 
  luego compara, analiza, entiende y corrige.
  
Sigue estos pasos:

* Crea un directorio para este ejercicio.
* Abre el directorio en Visual Studio Code.
* Crea un nuevo archivo que puedes llamar ``ex15.asm``.
* Inicia la traducción.

.. warning:: NO TE RINDAS, ESTO NO SERÁ FÁCIL.

  Te pido que por favor no te rindas ni desanimes. Este ejercicio no será 
  fácil. De hecho, vas a poner a PRUEBA lo que has aprendido hasta ahora. 
  Si no entiendes algo te pediré que regreses y ANALICES de nuevo el material.

Una vez escribas el código en ensamblador vas a verificar que la ``sintaxis`` está 
correcta, es decir, cumpliste todas las reglas del lenguaje y estás usando 
instrucciones válidas. Luego lo vas a simular para verificar que es correcto 
desde el punto de vista ``semántico``. De nuevo, necesitarás más herramientas:

* Abre el directorio App o app del usuario pop-os.
* Verifica si tienes la carpeta nand2tetris. Si no la tienes, la puedes descargar de 
  `este <https://drive.google.com/open?id=1xZzcMIUETv3u3sdpM_oTJSTetpVee3KZ>`__ 
  enlace.
* Descomprime el archivo descargado en la carpeta app o App.
* Abre el directorio tools en la terminal.
* Ejecuta el comando::

    sudo chmod +x CPUEmulator.sh

* Abre el simulador:: 

    ./CPUEmulator.sh

* Amplia el tamaño de la ventana del simulador en la parte inferior para que puedas ver el campo
  de texto donde aparecerán los mensajes de error.
* Carga en la memoria ROM el archivo .asm. Si la sintaxis es correcta puedes comenzar 
  a simular tu programa. De lo contrario debes reparar la sintaxis del programa.
* Cada vez que modifiques el programa debes cargarlo de nuevo en la memoria ROM y 
  verificar de nuevo que no tenga errores. ¿Cómo sabes que no tiene errores? Porque 
  el programa se podrá cargar y no tendrás mensajes de color rojo en la parte inferior 
  de la ventana del simulador.
* Ahora vas a probar que el programa haga lo que se supone debe hacer, es decir, que esté 
  bien la semántica. 
* Para simular das click en el botón single step (ícono con una sola flecha azul apuntando 
  a la derecha) o usa la tecla F11.
* Observa los registros: PC, A y D. Observa el bloque denominado ALU. Este bloque 
  es la parte de la CPU que realiza las operaciones. El bloque denominado RAM 
  es el mismo bloque que llamamos Memory. 

.. tip:: EL SIMULADOR TIENE UN MANUAL

    Puedes aprender más sobre esta y otras herramientas en 
    `este <https://www.nand2tetris.org/software>`__ enlace.
    
Por último te voy a pedir que pruebes otra herramienta. Se llama el Assembler, la puedes 
encontrar también en el directorio tools; sin embargo, antes de ejecutarla y solo la 
primera vez que la abras escribe en la terminal (debes abrir la carpeta tools en la terminal)::

  sudo chmod +x Assembler.sh

El paso anterior es necesario para darles permisos de ejecución al script Assembler.sh. Es 
una operación típica en Linux. 

Ahora si la lanzas::

  ./Assembler.sh

Carga el archivo .asm y dale click al botón Fast Translation. Podrás ver el código 
en lenguaje de máquina.


Ejercicio 16: retrieval practice
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Vas a repetir los pasos del ejercicio anterior, pero cambiando de programa. Esta vez con el 
ejemplo inicial de la Unidad, es decir, traduce el siguiente código a lenguaje ensamblador. 
Una vez termines compara tu solución con la que hemos venido discutiendo. Analiza, entiende y 
corrige. Escribe en Visual Studio Code el lenguaje ensamblador, usa CPUEmulator.sh y Assembler.sh.

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


..
  Ejercicio 17: (OPCIONAL) solo para los más curiosos
  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

  ¿Quieres jugar un poco más con el programa en C++?

  * Clona `este <https://github.com/juanferfranco/playWithHack.git>`__ repositorio.
  * 
  Ejercicio 17: evaluación formativa
  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

  El problema está divido en dos challenges. Tu programa debe cumplir exitosamente ambos challenges.

  * Challenge 1: ``leer el teclado`` y llenar la pantalla de negro si la tecla leída es 
    la letra F. Volver a repetir este proceso infinitamente (loop infinito).
  * Challenge 2: ``leer el teclado`` y llenar la pantalla de negro si la tecla leída es 
    la letra ``F`` y limpiar la pantalla si la letra leída es la ``C``. Repetir infinitamente 
    este proceso (loop infinito). 

  Consideraciones
  *****************

  * `Aquí <https://classroom.github.com/a/K6fxXFex>`__ está el enlace de la evaluación así como lo 
    practicaste en el ejercicio 19 de la guía de introducción a Git y GitHub.
  * Debes realizar constantemente commit y push al repositorio en GitHub. Debe verse claramente la 
    evolución de tu evaluación en el tiempo.
  * No olvides colocar la información solicitada en la parte superior de ``program.asm``.

  Para realizar la evaluación: 

  * CLONA el repositorio.
  * Cámbiate al directorio problem.
  * edita ÚNICAMENTE el archivo program.asm.
  * No olvides hacer commits y push.
  * Puedes hacer las pruebas usando la herramienta CPUEmulator.sh o CPUEmulator.bat dependiendo de tu 
    sistema operativo.
  * Al hacer las pruebas te recomiendo colocar la animación en FAST y con la opción No Animation. No 
    olvides que debes dar click en el botón del teclado para que el programa reciba las teclas que 
    presionarás.
  * También puedes hacer pruebas automáticas. En este caso usarás la línea de comandos. Cámbiate al 
    directorio problem y luego ejecuta:

    Para el challenge 1:

    .. code-block:: bash 

        ../tools/CPUEmulator.sh programBasic.tst
      
    Para el challenge 2:
    .. code-block:: bash 

        ../tools/CPUEmulator.sh program.tst

    Si tienes éxito verás el mensaje ``End of script - Comparison ended successfully``. De lo contrario 
    te aparecerá un mensaje que indicará la línea del archivo ``.out`` que no coincide con el vector de prueba 
    en el archivo ``.cmp``.

  * Ten en cuanta que cada que hagas ``push`` al repositorio remoto, las pruebas anteriores se ejecutarán 
    automáticamente y podrás ver el resultado.

  .. warning:: ALERTA DE SPOILER
      
      En `este <https://github.com/juanferfranco/scu1-e1-2022-10-feedback.git>`__ enlace podrás consultar 
      y clonar el repositorio con una posible solución a la evaluación formativa.