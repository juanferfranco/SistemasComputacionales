Unidad 1. Arquitectura del computador
=======================================

Introducción
--------------

En esta unidad vas a aprender los bloques de construcción
básicos del hardware de un sistema de cómputo moderno y cómo 
esos bloques pueden combinarse para construir computadores.

Propósito de aprendizaje
****************************

Comprender cómo funciona el hardware de un computador moderno 
desde una perspectiva sistémica, es decir, estudiando las partes 
que lo componen y cómo conectarlas entre ellas para conseguir funciones 
cada vez más complejas.

¿Cómo lo haremos? Emprendiendo una de las aventuras más interesantes: construyendo 
un computador.

Temas
********

* Compuertas lógicas
* Circuito lógicos y aritméticos: ALU
* Memorias y registros.
* Lenguaje de máquina / lenguaje ensamblador
* Arquitectura del computador

Trayecto de actividades
------------------------

Sesión 1
**********
(Tiempo estimado: 1 hora 40 minutos)


Ejercicio 1: introducción al control de versión 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. toctree::
    :maxdepth: 1

    Introducción a Git y GitHub <./introGit>

Trabajo autónomo 1
********************
(Tiempo estimado: 1 hora 20 minutos)

Ejercicio 2: entorno de trabajo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Para poder trabajar en los ejercicios vas a necesitar un ambiente de trabajo basado en Linux.

Te voy a pedir que le des una mirada a  `este video <https://youtu.be/ZPpo-uViT_o>`__ para 
que te hagas una idea de qué es Linux.

Hay varias opciones para tener Linux funcionando en tu computador: lo puedes instalar en una 
memoria, en una partición de tu computador, en una máquina virtual o incluso en 
`WSL2 <https://docs.microsoft.com/en-us/windows/wsl/install-win10>`__.

La opción que te voy a recomendar es instalar el sistema operativo en una memoria USB externa.

Vas a necesitar dos memorias USB. Una grande (> 16GB), donde instalarás tu sistema operativo
y otra más pequeña (8GB) donde grabaras el instalador. Trata de utilizar la USB más rápida y
más grande para instalar tu sistema operativo.

Te voy a dejar unos videos de ayuda:

* Este `video <https://www.youtube.com/watch?v=zSGZe8NSEAc>`__ 
  te muestra como grabar en la USB pequeña el instalador. En este caso la distribución es PopOS,
  es la misma que yo uso; sin embargo, puedes grabar la que más te guste, por ejemplo Ubuntu.
  Ten presente que la versión del video no será la última. También, debes investigar
  cómo entrar al menú de configuración de tu BIOS para que ajustes el orden de boot. 
  Nota que debes darle prioridad a la USB para que al tenerla conectada arranques el 
  instalador del sistema operativo.

* Ahora, este video `video <https://www.youtube.com/watch?v=RR9Vgytjj24>`__ te mostrará
  cómo instalar, usando la USB pequeña con el instalador, tu sistema operativo en la USB grande.
  Te recomiendo iniciar a ver el video en el minuto 6:29, donde comienza en si el proceso
  de instalación. Una vez termines de instalar Linux en la USB grande, NO OLVIDES desconectar la USB
  pequeña para que tu computador inicie con la versión instalada de Linux en la USB grande.

* Si tu computador no arranca en Linux debes reiniciarlo y entrar el menu de boot (debes indagar 
  cómo hacerlo en tu computador) y seleccionar Linux.

Si lo anterior no te funciona, prueba con una `máquina virtual <https://youtu.be/tNUgLsXD7xg>`__ o con WSL2.
Ten presente que las versiones de los videos pueden no coincidir con las versiones actuales.

Ejercicio 3: instala las herramientas 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Una vez tengas Linux funcionando debes instalar unas cuentas herramientas:

Abren la terminal y ejecuta los comandos:

.. code-block:: bash

    $ sudo apt update
    $ sudo apt install build-essential
    $ sudo apt install gdb

Ejercicio 4: instala un de entorno de desarrollo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Para el curso te recomiendo que instales Visual Studio Code. Te servirá 
para todas las modalidades de instalación del sistema operativo que te comenté, 
incluyendo WSL2.

#. `Visual Studio Code <https://code.visualstudio.com/>`__

Sesión 2
**********
(Tiempo estimado: 1 hora 40 minutos)

Vas a terminar el Ejercicio 1.

Trabajo autónomo 2
********************
(Tiempo estimado: 1 hora 20 minutos)

Termina los ejercicios de la sesión de trabajo autónomo 1. La meta 
es que para la semana entrante tengas funcionando Linux en tu 
propio computador.


Sesión 3
**********
(Tiempo estimado: 1 hora 40 minutos)

Ejercicio 5: circuitos lógicos
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

En esta sesión de clase vamos a realizar una actividad grupal para comprender 
los conceptos de circuitos lógicos. Vamos a jugar el primer nivel del 
videojuego `Silicon Zeroes <https://store.steampowered.com/app/684270/Silicon_Zeroes/>`__.

Trabajo autónomo 3
********************
(Tiempo estimado: 1 hora 20 minutos)

Lee el `capítulo 4 del libro guía <https://b1391bd6-da3d-477d-8c01-38cdf774495a.filesusr.com/ugd/44046b_7ef1c00a714c46768f08c459a6cab45a.pdf>`__.

Responde las siguientes preguntas:

#. Muestra una instrucción tipo A en representación simbólica y en lenguaje de máquina. Explica qué hace esta instrucción.
#. Muestra una instrucción tipo C en representación simbólica y en lenguaje de máquina. Explica qué hace esta instrucción.
#. En el lenguaje hack ¿Qué son los símbolos? muestra varios ejemplos de estos.
#. ¿Qué son los labels? ¿Para qué sirven? ¿En que se diferencian de los símbolos?

Sesión 4
**********
(Tiempo estimado: 1 hora 40 minutos)

Ejercicio 6: introducción al lenguaje ensamblador
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Realiza el proyecto 4 que encuentras `aquí <https://www.nand2tetris.org/project04>`__

Antes de comenzar a programar realiza un diagrama de flujo que indique cómo solucionarás el 
problema.

.. warning::
    CONTROL DE VERSIÓN

    Desde el inicio del proyecto debes crear un repositorio y realizar commits periódicamente. Tu repositorio 
    debe mostrar el proceso de trabajo.

Trabajo autónomo 4
********************
(Tiempo estimado: 1 hora 20 minutos)

Terminar el proyecto 4.

Sesión 5
**********
(Tiempo estimado: 1 hora 40 minutos)

Ejercicio 7: de ensamblador a alto nivel 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

En esta sesión analizaremos el siguiente programa:

.. image:: ../_static/asmProg.png
  :alt: programa en ensamblador

Responderemos las siguientes preguntas:

* ¿Qué hace el programa?
* ¿Cómo funciona?
* ¿Cómo quedaría una posible traducción a lenguaje de alto nivel?

.. warning:: ALERTA DE SPOILER

    Te mostraré dos posible respuestas a la última pregunta usando 
    como lenguaje de alto nivel C. Ten presente que en este caso R0 
    es la representación simbólica de la dirección 0, i es la dirección 
    16 y j es la dirección 17.

Traducción 1:

.. code:: c 

    int R0 =10;
    int i;
    int *j;

    if(R0 >0){
        i = R0;
        j = 16384;

        while(i > 0){
        // "RAM[j]" = -1;
        *j = -1;
            j = j + 32;
            i = i - 1;
        }
    }
    AQUI:
    goto AQUI;
            
Traducción 2:

.. code:: c 

    int R0 =10;
    int *j = 16384;

    if(R0 >0){
        for(int i = R0; i > 0;  i--){
        *j = -1;
            j = j + 32;
        }
    }
    while(1);

Trabajo autónomo 5
********************
(Tiempo estimado: 1 hora 20 minutos)

Revisar la unidad hasta este punto y terminar los ejercicios pendientes.

Sesión 6
**********
(Tiempo estimado: 1 hora 40 minutos)

Ejercicio 8: implementación de una CPU
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

En esta sesión vamos a analizar partes de la implementación del computador 
que realiza el set de instrucciones del lenguaje ensamblador estudiado 
previamente.

La herramienta que usaremos se llama Digital y se puede descargar 
`aquí <https://github.com/hneemann/Digital>`__.

El circuito que usaremos en clase se llama CPUplusMemDisplay.dig y se puede 
descargar (entre otros circuitos) 
`aquí <https://github.com/juanferfranco/SistemasComputacionales/tree/main/DigitalProjects/custom/project05>`__.

En la parte final de esta sesión veremos que el computador estudiado se puede 
llevar a una implementación física como se muestra en 
`este proyecto <https://gitlab.com/x653/nand2tetris-fpga/>`__. En particular 
puedes ver en 
`este video <https://gitlab.com/x653/nand2tetris-fpga/-/raw/master/08_Hack8-Sound/jack/Tetris/tetris.mp4>`__ 
una aplicación interactiva funcionando. 

Alguna vez te has preguntado ¿Cómo se implementa y construye un chip? Pues se 
parte de un diseño que se describe mediante algún lenguaje de descripción 
de hardware, como por ejemplo, el que puedes observar en la imagen:

.. image:: ../_static/gateHDL.png

Luego este diseño debe descomponerse en partes más simples. Esas partes se 
denominan `transistores <https://en.wikipedia.org/wiki/Transistor>`__:

.. image:: ../_static/transistor.png

Finalmente, los transistores y sus conexiones se deben transferir
a un medio físico. Esto se hace mediante un proceso conocido como
fotolitografía:

.. raw:: html

    <div style="position: relative; padding-bottom: 5%; height: 0; overflow: hidden; max-width: 100%; height: auto;">
        <iframe width="560" height="315" src="https://www.youtube.com/embed/vK-geBYygXo" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
    </div>


.. note:: 
    Material complementario 

    ¿Cómo funciona un transistor? 

.. raw:: html
    
    <div style="position: relative; padding-bottom: 5%; height: 0; overflow: hidden; max-width: 100%; height: auto;">
        <iframe width="560" height="315" src="https://www.youtube.com/embed/tz62t-q_KEc" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
    </div>

Trabajo autónomo 6
********************
(Tiempo estimado: 1 hora 20 minutos)

Analiza de nuevo el programa que estudiamos juntos en la sesión 5.

Evaluación de la unidad
-------------------------

Problema
***********

El problema está divido en dos challenges. Tu programa debe cumplir exitosamente ambos challenges.

* Challenge 1: ``leer indefinidamente el teclado`` y llenar la pantalla de negro si la tecla leída es 
  la letra F.
* Challenge 2: ``leer indefinidamente el teclado`` y llenar la pantalla de negro si la tecla leída es 
  la letra ``F`` y limpiar la pantalla si la letra leída es la ``C``. 

Sustentación 
**************

Para sustentar tu evaluación realizarás en el repositorio la Wiki (como aprendiste en el ejercicio 
20 de la introducción a Git y GitHub). 

* Tu sustentación debe tener la representación en lenguaje de alto  del programa que realizaste 
  en ensamblador (50% del valor total de la sustentación).
* Debes mostrar cada instrucción de alto a nivel a qué instrucciones de bajo nivel corresponde 
  (50% del valor total de la sustentación).


Consideraciones
*****************

* Para solucionar la evaluación debes utilizar Git y GitHub. 
  `Aquí <https://classroom.github.com/a/U7e2yEIR>`__ está el enlace de la evaluación así como lo 
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

Criterios de evaluación
************************

* Challenge 1: 1 unidad.
* Challenge 2: 2 unidades.
* Solo sustentación del challenge 1: 1 unidad.
* Sustentación del challenge 2 (esta incluye el challenge 1): 2 unidades.