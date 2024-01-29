Unidad 1. Arquitectura del computador
=======================================

Introducción
--------------

En esta unidad vas a estudiar cómo funciona un computador digital moderno entendiendo 
cómo hace este para ejecutar un programa en lenguaje ensamblador y la relación entre 
el lenguaje ensamblador y código de alto nivel.

Duración de esta etapa 
-----------------------

Consulta en la sección :ref:`cronograma` la duración de esta etapa.

Reto 
------

Construye una aplicación interactiva en el lenguaje ensamblador 
de la CPU que estudiaste en esta unidad. La aplicación la vas a correr 
en el simulador CPUEmulator. La aplicación debe:

* Funcionar en un ciclo infinito.
* Leer el teclado. Si la tecla presionada es la primera 
  letra de tu primer apellido entonces debes mostrar en la pantalla 
  una imagen de tu elección. Si la letra presionada es la última de tu primer 
  apellido entonces debes borrar la pantalla. Si la última letra de 
  tu apellido es la misma que la primera letra entonces toma la penúltima y 
  así sucesivamente hasta que encuentres una diferente.

Investigación
--------------

.. warngin:: (EN CONSTRUCCIÓN)

    Aún no esta lista esta fase.

Preguntas guía iniciales 
**************************

#. Los computadores digitales modernos funcionan gracias a la teoría de la lógica booleana.
   observa el video 6, unidad 1.1. de `este <https://youtube.com/playlist?list=PLrDd_kMiAuNmSb-CKWQqq9oBFN_KNMTaI&si=Mgnd99qVJaZKDkyO>`__  
   playlist. Selecciona una función booleana. Representa dicha operación de dos maneras diferentes. ¿Pudiste observar 
   en el video esas dos maneras?
#. Ahora observa el video 7. Inventa una tabla de verdad de tres entradas y una salida. ¿Cuál es la 
   función booleana que la representa?
#. Observa el video 8. ¿Cómo sería el circuito lógico que representa la función booleana del punto anterior?
#. Observa el video 14, unidad 2.1. ¿Cuántos números diferentes puede representar un computador de 8 bits?
#. ¿Cuál es la representación binaria del número en 8 bits del número 128?
#. Observa el video 15. ¿Qué es un overflow en una suma binaria? inventa un ejemplo.
#. Observa el video 16. ¿Cómo se representan números enteros negativos en un computador en complemento a dos?
   Construye una tabla que represente un conjunto de número enteros positivos y negativos usando 4 bits.
#. Observa el video 17. ¿Qué es una unidad aritmética lógica? ¿Qué se puede hacer si una función no está implementada en 
   la ALU?
#. ¿La ALU del video anterior puede multiplicar? ¿Cómo podrías resolver por software la multiplicación?
#. Observa el video 20, unidad 3.1. ¿Cuál es la diferencia entre la lógica combinacional y la lógica secuencial?
#. Observa el video 21. ¿Por qué se combina lógica combinacional y secuencial para construir un computador? Muestra un 
   circuito que permita almacenar un bit en un computador.
#. Observa el video 22. ¿Cómo funciona una memoria memoria RAM? ¿Cuál es la relación entre el bus de direcciones 
   y la salida cuando el bit de load es 0 y cuando es 1?
#. Observa el video 23. ¿Cuál es la función del program counter en un computador?
#. Observa el video 26, unidad 4.1. ¿Cuál es la diferencia entre el lenguaje ensamblador y el lenguaje de máquina?

(TODO: faltan otras preguntas de la unidad 4)

Actividad guía
**************************

(TODO: proponer algunos ejercicios antes de enfrentarse al reto)

Recursos guía iniciales 
**************************

* En `esta <https://youtube.com/playlist?list=PLrDd_kMiAuNmSb-CKWQqq9oBFN_KNMTaI&si=Mgnd99qVJaZKDkyO>`__ 
  lista puedes encontrar videos que explican los conceptos de esta unidad.
* `Unidad 4 <https://www.nand2tetris.org/_files/ugd/44046b_7ef1c00a714c46768f08c459a6cab45a.pdf>`__, machine language 
  del texto The Elements of Computing Systems.
* Para dibujar compuertas lógicas puedes usar la herramienta `draw.io <https://app.diagrams.net/>`__.

Aplicación 
-----------

Una vez termines la fase de investigación y tengas todos los fundamentos necesarios puedes 
comenzar la etapa de aplicación. En este etapa construirás las aplicaciones para 
resolver el reto.

Compartir
-----------

.. warngin:: (EN CONSTRUCCIÓN)

    Aún no esta lista esta fase.


Vas a evidenciar tu proceso con las siguientes evidencias que compartirás en 
el archivo README.md de esta unidad:

#. Bitácoras de las 3 sesiones de trabajo de cada semana.
#. Archivo program.asm con la solución.
#. Explica cómo solucionaste los problemas para diseñar, implementar y probar tu aplicación.
.. warning:: NO es explicar línea por línea el código 

    La explicación no es explicar línea por línea el código, es explicar 
    cómo está estructurada la solución, pero debes mostrar los bloques de código que  
    resuelven la parte de la solución que estás explicando.
#. Muestra cómo probaste las partes de tu aplicación y luego cómo probaste 
   las partes integradas.
#. Vas a mostrar la solución a tu problema con un diagrama de flujo. Muestra 
   que parte de tu código ensamblador implementa las estructuras de control condicionales 
   y los ciclos.
#. El archivo README.md de la carpeta `Unidad1` del repositorio deberá tener todas las bitácoras 
   y la documentación final.
#. No olvides responder las preguntas guía.
#. No olvides mantener bajo control de versión el código de todas las aplicaciones que hagas.
