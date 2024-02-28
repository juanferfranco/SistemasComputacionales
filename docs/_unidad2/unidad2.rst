Unidad 2. De lenguaje de alto nivel a código ejecutable 
============================================================

Introducción
--------------

En este punto del curso ya tienes una buena idea de cómo funciona un computador. 
También escribiste algunos programas en lenguaje ensamblador y estudiaste la relación 
entre este y el lenguaje de máquina.

A partir de ahora vas a emprender un viaje por varios de los componentes de software relacionados 
con los sistemas de cómputo. En esta unidad vas a aprender un nuevo lenguaje de programación 
muy relacionado con la programación a nivel de sistema, pero esto tiene como propósito 
explorar conceptos fundamentales de los sistemas computacionales y claro, implementar y 
probar una aplicación interactiva.

.. warning:: ¿Qué debes evidenciar al finalizar esta unidad?

    No podemos perder de vista que tenemos unos compromisos curriculares 
    relacionados con los resultados de aprendizaje.

RAE 1
*******

Construyo aplicaciones interactivas aplicando patrones y estrategias que permitan alcanzar los 
requisitos funcionales y no funcionales establecidos.

Se espera que llegues a un nivel resolutivo.

RAE 2
*******

Aplico pruebas de las partes y del todo de un software siguiendo metodologías, técnicas 
y estándares de la industria para garantizar el correcto funcionamiento de las aplicaciones.

Se espera que llegues a un nivel autónomo.

Duración de esta etapa 
-----------------------

Consulta en la sección :ref:`cronograma` la duración de esta etapa.

Reto 
------

El proyecto de esta unidad se trata de recrear el juego `Pong <https://youtu.be/fiShX2pTz9A>`__. 
`Aquí <https://en.wikipedia.org/wiki/Pong>`__ puedes leer un poco más acerca de las reglas del juego. 


.. warning:: VARIACIÓN AL PONG ORIGINAL

    La implementación del juego la harás en sentido vertical.



Los requisitos del proyecto son:
***********************************

* Usa el lenguaje de programación C, no C++.
* Usa la biblioteca SDL2.
* Usa Visual Studio y el sistema operativo windows.
* Mantén bajo control de versión tu programa.
* Representación de elementos: el juego debe representar la pelota, las dos paletas de los 
  jugadores y el tablero en pantalla.
* Movimiento de las paletas: las paletas de los jugadores deben poder moverse hacia la derecha y 
  hacia la izquierda.
* Movimiento de la pelota: la pelota debe moverse de manera diagonal y rebotar en las paletas y 
  los bordes del tablero.
* Puntuación: debe haber un marcador para mostrar la puntuación de ambos jugadores.
* Colisiones: el juego debe detectar y manejar las colisiones entre la pelota y las paletas, 
  actualizando la dirección de la pelota en función de dónde golpea la paleta.
* Aumento de velocidad: la velocidad de la pelota debe aumentar gradualmente a medida que 
  el juego avanza.
* Historial de eventos: se debe implementar una lista enlazada para registrar eventos 
  importantes, como la posición de la pelota y las paletas y la puntuación.
* Entrada del jugador: los jugadores deben poder controlar las paletas utilizando el teclado 
  para golpear la pelota.
* El juego debe iniciar con la posibilidad de escoger un nuevo juego o reproducir el juego anterior.
* Si no se guardó el juego anterior, entonces simplemente da la opción de un nuevo juego.
* Reproducción: una vez termine el juego se debe presentar la opción de jugar de nuevo 
  o reproducir la partida anterior. Por eso debes utilizar el historial de eventos registrados.
* Almacenamiento en archivo: los eventos del historial deben poder almacenarse en un archivo 
  al finalizar una partida.
* Carga del último juego: si se desea reproducir el último juego este tendrá que ser cargado 
  desde el archivo.

Guía de desarrollo gradual
**************************************

Te dejo una guía paso a paso para que desarrolles el juego de Pong:

Etapa 1: configuración básica con SDL2
############################################

* Configurar un proyecto de C con SDL2 y cargar una ventana en blanco en pantalla.
* Mostrar las paletas y la pelota en posiciones iniciales estáticas.
* Implementar la lógica básica para mover las paletas utilizando el teclado.

Etapa 2: movimiento de la pelota y rebotes
############################################

* Implementar el movimiento de la pelota en diagonal.
* Detectar y manejar las colisiones con los bordes del tablero para que la pelota rebote.

Etapa 3: colisiones con las paletas y puntuación
##################################################

* Detectar y manejar las colisiones entre la pelota y las paletas.
* Implementar la lógica para actualizar la dirección de la pelota según la posición de impacto 
  en la paleta.
* Mostrar la puntuación de ambos jugadores en pantalla.

Etapa 4: aumento de velocidad
##############################

* Implementar la lógica para aumentar gradualmente la velocidad de la pelota a medida que 
  avanza el juego.

Etapa 5: historial de eventos
###############################

* Definir la estructura para los eventos (PongEvent) y la estructura del nodo para la lista enlazada 
  (Node).
* Implementar la lista enlazada para registrar eventos importantes, como la posición de la 
  pelota, las paletas, la puntuación y los aumentos de velocidad.

Etapa 6: registro de eventos
#############################

* En cada evento importante del juego (movimiento de la pelota, movimiento de las paletas, 
  cambios en la puntuación, etc.), agregar un nuevo nodo con los datos del evento 
  a la lista enlazada.

Etapa 7: almacenamiento en archivo
####################################

* Implementar una función para guardar el historial de eventos en un archivo al finalizar una partida. 
  Los eventos se escribirán en un formato adecuado para su posterior lectura. Tu lo defines.

Etapa 8: carga de partidas
###########################

* Implementar una función para cargar el historial de eventos desde un archivo 
  a una lista enlazada en MEMORIA que representará la partida.

Etapa 9: reproducción de partidas
###################################

* Implementar la función de reproducción que recorre la lista enlazada y restaura el estado del 
  juego en cada evento.


.. warning:: ¿Qué commits como mínimo debe tener mi aplicación?

    Tu aplicación puede tener tantos comnits como requieras, pero al menos 
    vas a realizar un commit por cada etapa. Cuando hagas el commit lo marcarás 
    así Feature_numeroEtapa.

.. warning:: No olvides documentar lo que pasa en cada etapa.

    Ten presenta que en la documentación final (aunque esto debes irlo recolectando
    en el camino) debes documentar:

    * ¿Cómo implementaste cada etapa, qué conceptos, patrones, estrategias usaste 
      para alcanzar los requisitos funcionales y no funcionales establecidos en 
      esa etapa.

    * ¿Qué pruebas y cómo probaste cada etapa de manera aislada?
    * ¿Cómo probaste la integración con el resto de la aplicación?

Investigación
--------------

Esta fase de investigación será EXPERIMENTACIÓN PURA con los conceptos.

Preguntas guía iniciales 
**************************

* ¿Por qué utilizaremos en esta parte del curso el lenguaje C?

Recursos guía iniciales 
**************************

* Podrás usar ChatGPT, pero con sabiduría, es decir, tendrás que irle 
  preguntando y construyendo tu aplicación por partes. DEBES EVIDENCIAR 
  la construcción por partes de tu aplicación.
* Esta evaluación la vas a realizar utilizando una biblioteca llamada 
  SDL2. Utilizarás Visual Studio y el sistema operativo Windows. Te voy a dejar dos 
  recursos que pueden ser de mucha utilidad:

    * Página oficial de `SDL2 <https://www.libsdl.org/>`__.
    * `Este <https://www.udemy.com/course/game-loop-c-sdl/>`__ curso gratuito en Udemy que te 
      ayudará a realizar la primera etapa de la evaluación, es decir, aprender a instalar 
      la biblioteca SDL2 en tu proyecto de Visual Studio y a generar un game loop para 
      que puedas construir desde ahí la base de tu aplicación.
* Puedes aprender sobre lenguaje C donde gustes, es decir, ChatGPT, YouTube, etc. De 
  todas maneras te voy a dejar `aquí <https://sistemascomputacionales.readthedocs.io/es/v2023.20/_unidad2/introC.html>`__ 
  un material que construí que puede ser de mucha utilidad para ti.
* ¿En qué `momento temporal <https://tecky.io/en/blog/evolution-of-programming-languages/>`__ se ubica el lenguaje C?

.. note:: SOLO PARA LAS PERSONAS MÁS CURIOSAS

    En `este <https://sistemascomputacionales.readthedocs.io/es/v2023.20/_unidad2/unidad2.html#trayecto-de-actividades>`__ 
    trayecto de actividades te cuento con más detalle cómo se convierte un programa escrito en C a lenguaje 
    de máquina.

Actividades guía iniciales
****************************

* 
  .. toctree::
    :maxdepth: 1

    ./sdlGettingStarted

Aplicación 
-----------

En esta unidad irás investigando y aplicando. Es por eso que el desarrollo está dividido 
por etapas.

Compartir
-----------

Vas a evidenciar tu proceso con las siguientes evidencias que compartirás en 
el archivo README.md de esta unidad:

#. Bitácoras de las 3 sesiones de trabajo de cada semana.
#. Códigos .c de la aplicación interactiva bajo control de versión.
#. Para cada etapa debes explicar cómo la implementaste, qué investigaste y que 
   ensayos realizaste para entender el concepto implementado.
#. Para cada etapa debes explicar cómo probaste la funcionalidad de esa etapa.
#. Para cada etapa debes explicar cómo probaste la integración de esa etapa con las demás.
#. El archivo README.md de la carpeta `Unidad2` del repositorio deberá tener todas las bitácoras 
   y la documentación final.
#. No olvides responder las preguntas guía.
#. No olvides mantener bajo control de versión el código de todas las aplicaciones que hagas.
