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

Ejercicio 5: lenguaje ensamblador
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Para introducir la arquitectura de un computador vamos a estudiar juntos cómo se programa 
un computador usando lenguaje ensamblador.

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

Ejercicio 6: proyecto
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

..
    Lectura 9
    ^^^^^^^^^^^^



    Ejercicio 5
    ^^^^^^^^^^^^
    En tu bitácora de trabajo responde las siguientes preguntas:


    Lectura 10 (con ejercicio)
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    Par el siguiente proyecto vas a necesitar un programa diferente. En este caso, un 
    emulador de CPU. Lee las `instrucciones <https://b1391bd6-da3d-477d-8c01-38cdf774495a.filesusr.com/ugd/44046b_f63aba2611944e82974c9c5d5a3821fe.pdf>`__ 
    de uso del software.

    Analiza los 3 ejemplos de programación de hack (sección 4.3 edición 2, habla con el profe). Simula cada programa.

    PROYECTO FORMATIVO 4
    ^^^^^^^^^^^^^^^^^^^^^^


    Lectura 11
    ^^^^^^^^^^^^

    Lee el `capítulo 5 del libro guía <https://b1391bd6-da3d-477d-8c01-38cdf774495a.filesusr.com/ugd/44046b_b2cad2eea33847869b86c541683551a7.pdf>`__.

    Ejercicio 6
    ^^^^^^^^^^^^
    En tu bitácora de trabajo responde las siguientes preguntas:

    #. Explica con tus propias palabras en qué consiste el concepto de programa almacenado.
    #. ¿Por qué es importante el concepto de programa almacenado? ¿Qué ventaja tiene frente a las primeras computadoras?
    #. Explica en qué cosiste la arquitectura con Neumann.
    #. ¿Cuál es la diferencia entre la memoria de datos y la memoria de instrucciones?
    #. ¿Cuáles son los elementos básicos de una CPU? ¿Qué función cumple cada uno?
    #. Explica con tus propias palabras en qué cosiste el concepto de dispositivos de entrada salida mapeados a memoria.


    PROYECTO EVALUATIVO DE LA UNIDAD 
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    Enunciado de la evaluación
    ############################

    Analiza detenidamente y responde las siguientes preguntas:

    Pregunta 1
    ************

    Considerando esta implementación de la CPU:

    .. code-block:: c

        CHIP CPU {

            IN  inM[16],         // M value input  (M = contents of RAM[A])
                instruction[16], // Instruction for execution
                reset;           // Signals whether to re-start the current
                                // program (reset=1) or continue executing
                                // the current program (reset=0).

            OUT outM[16],        // M value output
                writeM,          // Write into M? 
                addressM[15],    // Address in data memory (of M)
                pc[15];          // address of next instruction

            PARTS:
            // Implementation by Mark Armbrust.

            // Instruction decode
            Not (in=instruction[15], out=aInst);
            And (a=instruction[14], b=instruction[13], out=ones);
            And (a=ones,  b=instruction[15], out=cInst);
            And (a=cInst, b=instruction[12], out=srcM);
            And (a=cInst, b=instruction[11], out=aluZx);
            And (a=cInst, b=instruction[10], out=aluNx);
            And (a=cInst, b=instruction[9],  out=aluZy);
            And (a=cInst, b=instruction[8],  out=aluNy);
            And (a=cInst, b=instruction[7],  out=aluF);
            And (a=cInst, b=instruction[6],  out=aluNo);
            And (a=cInst, b=instruction[5],  out=destA);
            And (a=cInst, b=instruction[4],  out=destD);
            And (a=cInst, b=instruction[3],  out=writeM);   // destM
            And (a=cInst, b=instruction[2],  out=jmpLt);
            And (a=cInst, b=instruction[1],  out=jmpEq);
            And (a=cInst, b=instruction[0],  out=jmpGt);

            // A register and input mux
            Mux16 (sel=aInst, a=aluOut, b=instruction, out=aIn);
            Or (a=aInst, b=destA, out=loadA);
            ARegister (in=aIn, load=loadA, out=aReg, out[0..14]=addressM);
            
            // D register
            DRegister(in=aluOut, load=destD, out=dReg);

            // ALU and input mux
            Mux16 (sel=srcM, a=aReg, b=inM, out=aluY); 
            ALU (x=dReg, y=aluY, out=aluOut, out=outM, zr=aluZr, ng=aluNg,
                    zx=aluZx, nx=aluNx, zy=aluZy, ny=aluNy, f=aluF, no=aluNo);

            // PC with jump test
            Or (a=aluZr, b=aluNg, out=zrng);
            Not (in=zrng, out=aluPos);
            And (a=aluNg, b=jmpLt, out=jlt);
            And (a=aluZr, b=jmpEq, out=jeq);
            And (a=aluPos, b=jmpGt, out=jgt);
            Or (a=jlt, b=jeq, out=jle);
            Or (a=jle, b=jgt, out=jmp);
            PC (in=aReg, reset=reset, inc=true, load=jmp, out[0..14]=pc);
        }

    Dibuja el diagrama en bloques de la CPU. Recuerda marcar detalladamente cada chip con su nombre, 
    puertos y el tamaño en bits de cada puerto. COLOCA EL NOMBRE DE LOS PUERTOS Y DEL CHIP 
    adentro del rectángulo que identifica el circuito. 
    Esto con el fin de poder distinguir el nombre de los cables del nombre de los puertos.     

    Pregunta 2
    ************

    Considerando esta implementación del computador:

    .. code-block:: c

        CHIP Computer {

            IN reset;

            PARTS:

            // CPU
            CPU (inM=RAMout, instruction=ROMout, reset=reset, writeM=loadRAM,
                outM=RAMin, addressM=RAMaddress, pc=ROMaddress);

            // RAM
            Memory (in=RAMin, load=loadRAM, address=RAMaddress, out=RAMout);

            // ROM
            ROM32K (address=ROMaddress, out=ROMout);
        }

    Dibuja el diagrama en bloques del computador. Recuerda marcar detalladamente cada chip con su nombre, 
    puertos y el tamaño en bits de cada puerto. COLOCA EL NOMBRE DE LOS PUERTOS Y DEL CHIP 
    adentro del rectángulo que identifica el circuito. 
    Esto con el fin de poder distinguir el nombre de los cables del nombre de los puertos. 

    Pregunta 3
    ************

    Explica qué hace el siguiente programa:

    .. image:: ../_static/asmProg.png
    :alt: programa en ensamblador

    Muestra gráficamente qué pasa con la CPU, la memoria y los buses del computador al ejecutar cada 
    una de las siguientes instrucciones: ``@16384``, ``D;JLE``, ``A=M``, ``MD = M-1``. Estas instrucciones hacen parte 
    del programa que te muestré en la figura anterior y como puedes notar están ubicada en diferentes 
    partes del programa. Debes tener en cuenta el estado de la CPU y la memoria como consecuencia de las 
    instrucciones anteriores a la que te pido que analices.

    Pregunta 4
    ************

    Inventa una nueva instrucción para el computador de tal manera que al ejecutarla se reinicie el programa.

    * Define cuál sería la sintaxis simbólica. 
    * Define la sintaxis binaria.
    * Realice un nuevo diagrama de la CPU donde muestre la modificación necesaria para implementar la nueva instrucción.

    Pregunta 5
    *************

    En una implementación de la CPU (no sabemos si está correcta o no), al ejecutar esta instrucción 
    ``0111 1100 1001 0000`` el contenido del registro D se modifica. ¿Es esto correcto?

    Muestre en el diagrama de la CPU lo que podría estar pasando en dicha implementación.

    Entregables
    ############################

    * Sube a `este <https://www.dropbox.com/request/yuejWTLm3UsZ5mdnAVVM>`__ 
    enlace un archivo pdf nombrado con los nueve dígitos que componen tu ID. Por ejemplo: 000008716.pdf. El archivo 
    debe tener lo siguiente:

    * Tu nombre completo.
    * Evaluación de la unidad 1 y la fecha en la cual vas subir el archivo.
    * Define una sección en el documento para solucionar cada pregunta.

    .. warning:: USA DRAW.IO

        Te recomiendo usar la aplicación draw.io para realizar los diagramas solicitados.


    Criterios de evaluación
    ############################

    Estos son los puntos que te dará la solución a cada pregunta.

    * Pregunta 1: 0.5
    * Pregunta 2: 0.5
    * Pregunta 3: 2
    * Pregunta 4: 1
    * Pregunta 5: 1

    .. warning:: ASIGNACIÓN DE PUNTAJE

        La asignación de los puntos a la respuesta de cada pregunta se otorga 
        solo si la respuesta está completa. No se asignarán calificaciones intermedias. Por tanto,
        revisa cuidadosamente la respuesta a cada una de tus preguntas.


