Introducción al al flujo de trabajo del curso
================================================

Introducción
--------------

En estas sesiones del curso vas a tener un primer el flujo de trabjo 
que deberás emplear para realizar de manera exitosa el curso. 
Además, vas a repasar y/o aprender algunas fundamentos básicos del control 
de versión.

Duración
-----------------------

Consulta en la sección :ref:`cronograma` la duración de esta introducción al curso.

Trayecto de actividades
------------------------

Actividad 1
*************

Esta actividad será guiada. La idea es que simulemos un programa en lenguaje ensamblador. 
En el proceso configuraremos las herramientas que usarás en la próxima unidad. Además, 
te pediré que hagas una modificación al programa para que practiques el control de versión 
de este.

* Descarga `este <https://drive.google.com/open?id=1xZzcMIUETv3u3sdpM_oTJSTetpVee3KZ>`__ 
  archivo.
* Descomprime el archivo descargado.
* Abre el directorio tools y ejecuta el archivo CPUEmulator.bat. 
* Amplia el tamaño de la ventana del simulador en la parte inferior para que puedas ver el campo
  de texto donde aparecerán los mensajes de error.

Actividad 2
*************

Esta actividad será guiada. En este punto ya tienes funcionando el simulador del computador 
que usarás para observar el programa en lenguaje ensamblador. Ahora necesitas escribir el programa.

* Descarga o abre Visual Studio Code.
* Añade `esta <https://marketplace.visualstudio.com/items?itemName=Throvn.nand2tetris>`__ extensión.
* Ahora escribe el siguiente programa que guardarás como ex15.asm:

  .. code-block::

  @16384
  D=A
  @16
  M=D
  @24576
  D=M
  @19
  D;JNE
  @16
  D=M
  @16384
  D=D-A
  @4
  D;JLE
  @16
  AM=M-1
  M=0
  @4
  0;JMP
  @16
  D=M
  @24576
  D=D-A
  @4
  D;JGE
  @16
  A=M
  M=-1
  @16
  M=M+1
  @4
  0;JMP

* Salva el programa. No olvides el nombre, ex15.asm.
* Carga en la memoria ROM el archivo ex15.asm. Si la sintaxis es correcta puedes comenzar 
  a simular tu programa. De lo contrario quiere decir que no escribiste bien algo. Revisa.
* Cada vez que modifiques el programa debes cargarlo de nuevo en la memoria ROM y 
  verificar de nuevo que no tenga errores. ¿Cómo sabes que no tiene errores? Porque 
  el programa se podrá cargar y no tendrás mensajes de color rojo en la parte inferior 
  de la ventana del simulador.
* Ahora vas a probar que el programa haga lo que se supone debe hacer, es decir, que esté 
  bien la semántica. 
* Para simular vas a:

  * Coloca el slider en fast.
  * Animate: No animation.
  * Click en Run 
  * Click en el botón de teclado para activar la entrada de teclado del simulador.
  * Presiona y deja presionada esa tecla. Espera un momento. ¿Qué pasa? ¿Qué pasa 
    cuando sueltas la tecla?.

Actividad 3
*************

Colocar bajo control de versión ex15.asm.


Actividad 4
*************

Ahora modifica el programa así:

.. code-clobk::

  @16384
  D=A
  @16
  M=D
  (LOOP)
  @24576
  D=M
  @19
  D;JNE
  @16
  D=M
  @16384
  D=D-A
  @LOOP
  D;JLE
  @16
  AM=M-1
  M=0
  @LOOP
  0;JMP
  @16
  D=M
  @24576
  D=D-A
  @LOOP
  D;JGE
  @16
  A=M
  M=-1
  @16
  M=M+1
  @LOOP
  0;JMP

* Realiza un nuevo commit con este cambio.

Evidencias
-------------

* Muestra los resultados de los experimentos en tu bitácora de trabajo.
* No olvides que tu archivo ex15.asm tendrá varios cambios bajo control 
  de versión.

