Guía de inicio con SDL2
=========================

Esta guía es más que un tutorial, aunque no es completamente uno. La idea es 
explicarte los pasos que requieres para trabajar con SDL2, pero tratando de 
comprender en la medida de lo posible qué es lo que estás haciendo y no 
simplemente siguiendo una receta de cocina.


Actividad 1: programa en C básico
----------------------------------

Cuando inicies a programar las aplicación en el sistema operativo Windows, en lenguaje C y con Visual Studio. Lo primero 
que debes probar es que sea posible compilar aplicaciones. 

* Crea un proyecto vacío C++ Windows Console en Visual Studio.
* En la carpeta source crea el archivo main.c (mira bien que dice main.c y no Main.cpp).
* Puedes probar con este programa:

.. code-block:: C

    #include <stdio.h>

    int main(int argc, char* argv[]) {
      printf("Hello IDED");
      return 0;
    }

* Construye el archivo ejecutable con F7.
* Si no hay errores de compilación puedes ejecutar la aplicación con Crtl+F5 para correr 
  sin depurar y con F5 para depurar.
* Ejecuta la aplicación con Crlt + F5.
* Ahora coloca un breakpoint en la línea con printf y ejecuta con F5. ¿Qué pasa?
* Trata de buscar un tutorial en YouTube donde te muestren cómo depurar. Es muy importante 
  que lo hagas para que puedas resolver problemas más adelante.

Actividad 2: biblioteca externa 
--------------------------------

SDL2 es una biblioteca externa que puedes usar en tus proyectos en lenguaje C como cualquier 
otra biblioteca. No olvides esto porque SDL2 no será la única biblioteca que usarás para resolver 
el reto. Por tanto, los pasos que te propongo aquí tendrás que repetirlos para una biblioteca 
nueva que requieras.

* Crea un proyecto vacío C++ Windows Console en Visual Studio.
* Lo primero es descargar la biblioteca. En el caso de SDL2 la puedes descargar de 
  `aquí <https://github.com/libsdl-org/SDL/releases>`__.
* En el caso de Visual Studio, descarga la versión más reciente SDL-devel-version-VC.zip.
* Descomprime la carpeta en la unidad C para que puedas encontrar fácilmente los archivos necesarios 
  posteriormente.
* Cuando usas una biblioteca debes incluir los archivos de .h. Ahí estarán declaradas, las funciones, 
  estructuras de datos, macros, etc, que podrás usar en tus programas.
* Ten presente que la definición de las funciones, por ejemplo, no estará en un archivo .h sino, en 
  el caso de una biblioteca, en los archivos .lib. Dicho esto, navega a la carpeta donde descomprimiste 
  la biblioteca. Allí encontrarás los directorios include y lib donde estarán los archivos .h y lib 
  respectivamente. Observa que en el directorio lib hay dos directorios más. Uno dirá x64 y el otro x86.
  Cuál usar dependerá de la versión de tu sistema operativo. En tu caso lo más seguro es que tengas 
  un Windows 10 u 11 de 64 bits y por tanto usarás los archivos de la carpeta x64.

Actividad 3: usar la biblioteca
---------------------------------

Para usar la biblioteca en tu aplicación C tendrás que incluir los archivos de cabecera de aquellas 
funciones que llamarás desde tu código e indicarle a tu compilador y enlazador en dónde se 
encuentran los archivos .h y los archivos .lib. No olvides que los .h tienen las declaraciones y los 
.lib tiene el código (compilado) con las definiciones de las funciones. Lo único que tendrá que hacer 
es compilar tu archivo .c y luego enlazarlo con los .lib que estés usando. Afortunadamente, todo 
esto lo puedes configurar en un Visual Studio.

¿Cómo puedes entonces informarle todo lo anterior a Visual Studio?

Te iré guiando para que lo entiendas:

* Escribe este programa:

.. code-block:: C

    #include <stdio.h>
    #include <SDL.h>

    int main(int argc, char* argv[]) {
      printf("Hello IDED");
      return 0;
    }

* Construye la aplicación (build) con F7. Notarás que aparece un mensaje de error en la salida. La razón, como 
  podrás notar es que el preprocesador no encuentra el archivo SDL.h.
* Tendrás que indicar en las propiedades del proyecto (click derecho al nombre del proyecto en el solution explorer 
  y bajas hasta el final) cuál es la ruta en el sistema de archivos donde está el directorio include de la biblioteca.
  En este caso lo indicarás en Directorios de Inclusión o Include Directories de VC++ Directories o Directorios de VC++.
* Además de lo anterior, también deberás indicar adicionar en la propiedad C/C++ en Additional Include Directories la 
  ruta de los archivos .h de la biblioteca. Mira, esto no es obligatorio para construir el proyecto, pero si muy 
  útil para navegar hacia el archivo SDL.h con CRTL+click. Puedes hacer el ensayo. Verás también en el explorador de soluciones 
  que los archivos .h de biblioteca aparecerán en la lista de External Dependencies.
* Ahora vas a usar una de las funciones de SDL.h. Añade:

.. code-block:: C

    #include <stdio.h>
    #include <SDL.h>

    int main(int argc, char* argv[]) {
      SDL_Init(SDL_INIT_EVERYTHING);
      printf("Hello IDED");
      return 0;
    }

* Construye de nuevo la aplicación con F7. Observa la salida de error. Verás varios mensajes del enlazador indicando 
  que hay símbolos sin resolver. ¿Por qué pasa esto? Mira, tu programa se deja compilar sin problema, pero para poder 
  construir tu programa hace falta que lo enlaces con el código de la biblioteca que está en los archivos .lib. En 
  el caso de SDL solo utilizarás SDL2.lib y SDL2main.lib. Ambos están en la carpeta lib. Por favor ve y compruébalo.
  ¿Entonces qué toca hacer? Toca decirle al enlazador en donde está esos archivos.
* Vuelve a las propiedades del proyecto. Busca la propiedad Linker o enlazador y en las opciones Generales añade 
  el directorio lib de la biblioteca en los directorios de biblioteca adicionales o Additional Library Directories.
  Finalmente, en Entrada o Input indica los archivos .lib específicos en Additional Dependencies o Dependencias Adicionales
  así: SDL2.lib;SDL2main.lib.
* Construye de nuevo el proyecto. Si todo lo configuraste bien debería compilar sin errores.
* Ahora ejecuta el programa con F5. Verás que sale un error que indica que no se ha encontrado el archivo SDL2.dll. En este 
  punto comienzas a sudar frio.
* Te explicaré que es lo que pasa. En unos pasos previos te conté que el código con las definiciones de las funciones 
  de la biblioteca está en los archivos .lib. La verdad te dije una mentira piadosa. Pero ya te aclaro. Cuando se construye 
  un proyecto en C o C++ tu código se compila a una representación intermedia de código de máquina. Tu código puede 
  tener dependencias a código externo como en este caso con SDL2. Para poder construir el ejecutable para Windows se 
  necesita que otra herramienta llamada el enlazador haga una mezcla entre tu código y el código externo. Lo interesante 
  es que el código externo se puede mezclar en tiempo de compilación o dejar unas instrucciones para enlazarlo 
  (hacer la mezcla) en tiempo de ejecución. A lo primero se le llama enlazado estático y al segundo enlazado dinámico. 
  Cuando el enlazado es estático, el ejecutable contiene el código de la biblioteca. Cuando es dinámica el ejecutable 
  contiene algo así como hipervínculos hacia el código de la biblioteca. Las instrucciones están en los archivos .lib y 
  el código en si en los archivos .dll. Te estarás preguntando a qué loco se le ocurrió esto, pero la verdad tiene 
  sentido. Te lo explico con una metáfora. Supón que compras dos libros y ambos libros tiene un capítulo igual en ambos. 
  Una opción sería efectivamente imprimir el capítulo en ambos libros, es decir, enlazado estático. La otra opción 
  sería imprimir solo una copia del capítulo y compartirlo con los otros dos libros. Esto es enlazado dinámico. En este 
  caso cuando llegues a al capítulo repetido en ambos libros, simplemente encontrarás una página que te dice que la 
  información realmente está en el libro compartido. En vez de imprimir dos veces el mismo capítulo lo imprimes una 
  vez y lo compartes entre varios libros. Brillante, no? Y en el caso de los computadores tiene más sentido aún. Si tienes 
  MUCHOS programas corriendo que comparten la misma biblioteca, si los enlazaste con una biblioteca dinámica como SDL2 
  entonces tendrás en memoria SOLO UNA COPIA de SDL2 que estará compartida por todos los programas. Genial, si o no?
* Entonces volviendo a nuestro programa, ¿Cómo solucionamos el error del dll? Lo único que tienes que hacer es guardar 
  en el proyecto, en el mismo directorio donde está tu archivo main.c, el archivo DLL. ¿Cómo? Busca el proyecto en el 
  explorador de archivos y copia allí el archivo SDL2.dll que estará en la carpeta lib de SDL. Observa que una 
  vez lo entiendes es fácil la cosa.
* Ahora si ejecuta el programa con F5. El programa, no hace nada, aún, pero ya no falla. ¿Notaste que no te pedí 
  que compilaras el programa? No es necesario, el programa ya estaba compilado, solo necesitaba que le diéramos 
  la biblioteca de enlace dinámico, el DLL y listo.

Actividad 4: crear una ventana
-------------------------------

El siguiente código creará una ventana:

.. code-block:: c

    #include <stdio.h>
    #include <SDL.h>

    #define TRUE 1
    #define FALSE 0
    #define WINDOW_WIDTH 800
    #define WINDOW_HEIGHT 600

    SDL_Window* window = NULL;


    int init_window(void){

        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            printf("Error SDL_Init\n");
            return FALSE;
        }

        window = SDL_CreateWindow(
            "My first Window",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            WINDOW_WIDTH,
            WINDOW_HEIGHT,
            SDL_WINDOW_BORDERLESS);
        if (window == NULL) {
            printf("Error SDL_CreateWindow\n");
            return FALSE;
        }
        return TRUE;
    }


    int main(int argc, char* argv[]) {
        init_window();
        while (TRUE) {
        }
        return 0;
    }


Nota esta parte del código en la función main:

.. code-block:: C

    while (TRUE) {
    
    }

La condición en el while es TRUE, es decir, 1. Quiere decir que el programa nunca saldrá 
de ese loop. A esto se le conoce como un loop infinito. Te preguntarás ¿Por qué es necesario hacer esto? 
Puedes ensayar qué pasa si quitas esas líneas de código y luego concluir. 
Ten presente algo. En cualquier programa C o C++ el punto de entrada es la función main. Te hago 
una pregunta para que la pienses bien. ¿Por qué el punto de entrada no es #include <stdio.h> si 
esa es la primera línea? Te dejo una pista. La implementación del lenguaje C y C++ es compilada, 
es decir, un programa lee el código y lo transforma en lenguaje de máquina. Entonces el computador no ejecuta 
el archivo .c sino el código de máquina que se genera luego del proceso de compilación y enlazado. 

Actividad 5: pintar en la ventana
-----------------------------------

Para pintar en una ventana es necesario tener un renderizador asociado a esa ventana. El renderizador 
es un componente de SDL2 que permite DIBUJAR en la ventana. El renderizador necesita un driver de 
renderizado. El driver de renderizado es un componente de software que media entre la aplicación y el 
hardware gráfico o capa de emulación gráfica del sistema de cómputo, facilitando la función de DIBUJAR 
en la pantalla.

Te dejo unos experimentos. Luego de iniciar la biblioteca puedes preguntarle a SDL que te ayude 
a determinar todos los driver de renderizado que tiene tu sistema:

.. code-block:: C

  	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("Error SDL_Init\n");
		return FALSE;
    }
    showRenderDriversInfo();

.. code-block:: C

    void showRenderDriversInfo(void) {
    int numRenderDrivers = SDL_GetNumRenderDrivers();
    printf("Número de drivers de renderizado disponibles: %d\n", numRenderDrivers);

    for (int i = 0; i < numRenderDrivers; i++) {
      SDL_RendererInfo info;
      if (SDL_GetRenderDriverInfo(i, &info) == 0) {
        printf("Driver %d: %s\n", i, info.name);
      }
    }
  }

Luego de crear la ventana y crear el renderizador puedes preguntarle a SDL cuál seleccionó 
por ti (se lo pedimos precisamente usando un -1 en el segundo parámetro de SDL_CreateRenderer):

.. code-block:: c

    int init_window(void){

      if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Error SDL_Init\n");
        return FALSE;
      }
      showRenderDriversInfo();

      window = SDL_CreateWindow(
        "My first Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN);
      if (window == NULL) {
        printf("Error SDL_CreateWindow\n");
        return FALSE;
      }

      renderer = SDL_CreateRenderer(window, -1, 0);
      if (renderer == NULL) {
        printf("Error SDL_CreateRenderer\n");
        return FALSE;
      }

      showSelectedRederer();

      return TRUE;
    }

.. code-block:: C

    void showSelectedRederer(void) {
      // Asumiendo que tienes un SDL_Renderer* llamado renderer que ya fue creado

      SDL_RendererInfo rendererInfo;
      if (SDL_GetRendererInfo(renderer, &rendererInfo) == 0) {
        printf("Driver de renderizado seleccionado: %s\n", rendererInfo.name);
      }
      else {
        printf("Error al obtener la información del renderizador: %s\n", SDL_GetError());
      }

    }

Para que esto te funcione tendrás que crear la variable global renderer:

.. code-block:: C

    SDL_Window* window = NULL;
    SDL_Renderer *renderer = NULL;

Te pregunto antes de seguir. ¿Por qué se necesita que sea una varibale global? Hay otra 
manera de preguntarle a showSelectedRederer de cuál redenderer queremos tener información? 

Actividad 6: el concepto de gameloop
--------------------------------------

Al desarrollar aplicaciones interactivas hay un patrón de diseño arquitectónico muy útil 
para estructurar el software. Se llama el patrón `gameloop <https://gameprogrammingpatterns.com/game-loop.html>`__. 
Te voy a compartir una versión más completa de un programa hecho con SDL2 que te permite crear una ventana, 
asociar a esa ventana un renderer y caputurar algunos eventos de la aplicación:

.. code-block:: C

    #include <stdio.h>
    #include <SDL.h>

    #define TRUE 1
    #define FALSE 0
    #define WINDOW_WIDTH 800
    #define WINDOW_HEIGHT 600

    SDL_Window* window = NULL;
    SDL_Renderer *renderer = NULL;
    int gameRunning = FALSE;

    void showRenderDriversInfo(void) {
      int numRenderDrivers = SDL_GetNumRenderDrivers();
      printf("Número de drivers de renderizado disponibles: %d\n", numRenderDrivers);

      for (int i = 0; i < numRenderDrivers; i++) {
        SDL_RendererInfo info;
        if (SDL_GetRenderDriverInfo(i, &info) == 0) {
          printf("Driver %d: %s\n", i, info.name);
        }
      }
    }

    void showSelectedRederer(void) {
      // Asumiendo que tienes un SDL_Renderer* llamado renderer que ya fue creado

      SDL_RendererInfo rendererInfo;
      if (SDL_GetRendererInfo(renderer, &rendererInfo) == 0) {
        printf("Driver de renderizado seleccionado: %s\n", rendererInfo.name);
      }
      else {
        printf("Error al obtener la información del renderizador: %s\n", SDL_GetError());
      }

    }


    int init_window(void){

      if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Error SDL_Init\n");
        return FALSE;
      }
      showRenderDriversInfo();

      window = SDL_CreateWindow(
        "My first Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN);
      if (window == NULL) {
        printf("Error SDL_CreateWindow\n");
        return FALSE;
      }

      renderer = SDL_CreateRenderer(window, -1, 0);
      if (renderer == NULL) {
        printf("Error SDL_CreateRenderer\n");
        return FALSE;
      }

      showSelectedRederer();

      return TRUE;
    }

    void process_input(void) {
      SDL_Event event;
      SDL_PollEvent(&event);

      switch (event.type) {
      case SDL_QUIT:
        gameRunning = FALSE;
        break;
      case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE) {
          gameRunning = FALSE;
        }
        break;
      }
    }

    void update(void) {


    }


    void render(void) {

    }

    void setup(void) {
      gameRunning = init_window();
    }

    void clean() {
      SDL_DestroyRenderer(renderer);
      SDL_DestroyWindow(window);
      SDL_Quit();
    }

    int main(int argc, char* argv[]) {
      setup();
      while (gameRunning) {
        // El concepto de gameloop para correr una aplicación
        // interactiva
        process_input(); // Leo las entradas
        update();        // calculo las físicas 
        render();        // actualizo las salidas
      }
      clean();
      return 0;
    }


Específicamente aquí está el gameloop:

.. code-block:: C

    while (gameRunning) {
      process_input(); // Leo las entradas
      update();        // calculo las físicas 
      render();        // actualizo las salidas
    }

La idea es muy simple. Como explican en el libro Game programming patterns 
que te compartí:

.. note::  Game programming patterns 
    
    This is the first key part of a real game loop: it processes user input, but doesn’t wait for it. 
    The loop always keeps spinning:

    .. code-block:: c

        while (true)
        {
          processInput();
          update();
          render();
        }

    processInput() handles any user input that has happened since the last call. Then, update() advances 
    the game simulation one step. It runs AI and physics (usually in that order). Finally, render() 
    draws the game so the player can see what happened.

Actividad 7: pintar un rectángulo
--------------------------------------

Vas a renderizar un rectángulo en la ventana recién creada. Puedes actualizar el código 
de render así:

.. code-block:: C

    void render(void) {
      SDL_Rect rect;
      rect.x = 250; // Posición x del rectángulo
      rect.y = 150; // Posición y del rectángulo
      rect.w = 200; // Ancho del rectángulo
      rect.h = 100; // Alto del rectángulo

      // Limpia el "lienzo" en este frame (?)
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Color de fondo: negro
      SDL_RenderClear(renderer);

      // Dibuja el rectángulo, pero aún no lo muestra
      SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Color del rectángulo: rojo
      SDL_RenderFillRect(renderer, &rect);

      // Actualiza el lienzo
      SDL_RenderPresent(renderer);
    }

Actividad 8: pintar en círculo
----------------------------------

Para pintar un círuclo necesitarás un algoritmo para decidir en qué parte del lienzo debes 
ubicar diferentes puntos de tal manera que tenga la forma de un círculo la distribución de esos 
puntos.

La ecuación de un círculo centrado en ``(cx, cy)`` con radio ``r`` es:

.. math::

   (x - cx)^2 + (y - cy)^2 = r^2

Entonces para pintar un círculo, debes encontrar los puntos ``(x,y)`` que satisfagan 
esta ecuación. Ten presente que en SDL2 las ``x`` incrementan de izquierda a derecha y 
las ``y`` de arriba hacia abajo. Por tanto, la coordenada (0,0) estaría en la esquina 
superior izquierda. Así mismo, la coordenada (WINDOWS_WIDTH - 1, 0) estaría en la 
esquina superior derecha.

Piensa en lo siguiente. Imagínate un plano cartesiana en el cual la coordenada ``(0,0)`` 
está en el origen del plano. Supón ahora que en ese punto está el centro del 
círculo. Por tanto, los puntos del círculo estarán ubicados para valores de ``x`` y ``y`` 
que cumplan :math:`-r <= x <= r` y :math:`-r <= y <= r`. ¿Aceptamos esto? 

Entonces, podrías seleccionar valores para ``y`` y luego, para cada valor, buscar todas las ``x`` 
que tengan ese mismo valor de ``y``, pero que cumplan la ecuación del círculo. ¿Te parece rezonable?

El código entonces quedaría así:

.. code-block:: C

    void DrawCircle(SDL_Renderer* renderer, int cx, int cy, int radius) {
      for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
          if (x * x + y * y <= radius * radius) {
            SDL_RenderDrawPoint(renderer, cx + x, cy + y);
          }
        }
      }
    }

Y tendrías que actualizar el render así:

.. code-block:: C

    void render(void) {
      SDL_Rect rect;
      rect.x = 250; // Posición x del rectángulo
      rect.y = 150; // Posición y del rectángulo
      rect.w = 200; // Ancho del rectángulo
      rect.h = 100; // Alto del rectángulo

      // Limpia el "lienzo" en este frame (?)
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Color de fondo: negro
      SDL_RenderClear(renderer);

      // Dibuja el rectángulo, pero aún no lo muestra
      SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Color del rectángulo: rojo
      SDL_RenderFillRect(renderer, &rect);

      // Dibuja el círculo	
      SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // Amarillo
      DrawCircle(renderer, 400, 360, 100); // Dibuja un círculo en (320, 240) con radio 100.

      // Actualiza el lienzo
      SDL_RenderPresent(renderer);
    }


Actividad 9: pintar puntos
--------------------------------

Ya lo hicimos, en la actividad anterior. Pero podrías experimentar un poco más 
con esto para entender cómo ubicar cosas en el linezo en SDL2.

Un versión actializada del código podría ser:

.. code-block:: c

    void render(void) {
      SDL_Rect rect;
      rect.x = 250; // Posición x del rectángulo
      rect.y = 150; // Posición y del rectángulo
      rect.w = 200; // Ancho del rectángulo
      rect.h = 100; // Alto del rectángulo

      // Limpia el "lienzo" en este frame (?)
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Color de fondo: negro
      SDL_RenderClear(renderer);

      // Dibuja el rectángulo, pero aún no lo muestra
      SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Color del rectángulo: rojo
      SDL_RenderFillRect(renderer, &rect);

      // Dibuja el círculo	
      SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // Amarillo
      DrawCircle(renderer, 400, 360, 100); // Dibuja un círculo en (320, 240) con radio 100.

      SDL_RenderDrawPoint(renderer, WINDOW_WIDTH-1, 0);
      SDL_RenderDrawPoint(renderer, WINDOW_WIDTH - 1, 2);

      // Actualiza el lienzo
      SDL_RenderPresent(renderer);
    }

Nota que la parte nueva es esta:

.. code-block:: c

    SDL_RenderDrawPoint(renderer, WINDOW_WIDTH-1, 0);
    SDL_RenderDrawPoint(renderer, WINDOW_WIDTH - 1, 2);

Para ver los puntos dibujados tendrás que hacer zoom.

Actividad 10: double buffering
--------------------------------

SDL2 utiliza un patrón de diseño llamado 
`double buffering <https://gameprogrammingpatterns.com/double-buffer.html>`__.
¿En dónde lo usa? Para renderizar. Observa de nuevo esta parte del código:

.. code-block:: c

    SDL_RenderDrawPoint(renderer, WINDOW_WIDTH-1, 0);
    SDL_RenderDrawPoint(renderer, WINDOW_WIDTH - 1, 2);

    // Actualiza el lienzo
    SDL_RenderPresent(renderer);

* ¿Qué pasa si quitas la función `SDL_RenderPresent(renderer)`?
* Mira de nuevo el enlace donde te explican en qué consiste el patrón 
  double buffering. ¿Puedes explicar cómo se está aplicando en el 
  código del render?

Actividad 11: frames por segundos (fps)
----------------------------------------

Vuelve a mirar por favor el concepto de `gameloop <https://gameprogrammingpatterns.com/game-loop.html>`__. 
Hay algo más que tendrá que hacer tu programa y es controlar la cantidad de frames que se ejecutan 
por segundo (fps). Mira de nuevo la estructura del gameloop:

.. code-block:: c

    while (true)
    {
      processInput();
      update();
      render();
    }

En términos muy simplistas, pero útiles para la discución, un frame sería una pasada por el loop. 
Entonces los frames por segundo serían cuántas veceses tu aplicación interactiva hace un loop 
completo por segundo. Si una aplicación interactiva se ejecuta a 60 fps ¿Cuánto tiempo transcurre 
entre frame y frame?

¿De qué depende ese tiempo entre frame y frame?

En principio de dos cosas:

* Que tanto trabajo tiene que hacerse en el loop, es decir, que tan complejos son los algoritmos para 
  hacer avanzar la aplicación. 
* Qué tan rápido es el hardware que ejecuta la aplicación.

Entonces la idea al contruir una aplicación interactiva es minimizar al máximo el trabajo que se 
hace en un loop y además, garantizar que independientemente de la rapidez del hardware en el que 
corra, siempre se obtenga una cantidad consistente de fps. Es decir, la aplicación debe correr 
a 60 fps o 16.6 ms sin importartar si el hardware es muy rápido o muy lento. De esta manera, 
la experiencia del usuario en términos temporales será la misma independientemente de la plataforma 
de ejecución.

Para lograr esto se usa el patrón gameloop:

.. note:: GAME LOOP 

    El loop o bucle se ejecuta continuamente durante la ejecución del juego o la aplicación interactiva. 
    En cada turno del bucle, procesa la entrada del usuario sin bloquearse, actualiza el estado del juego y 
    renderiza el juego. Además, debe tenerse en cuenta el paso del tiempo para controlar la velocidad de 
    jugabilidad.

Actividad 12: pixels por segundo
----------------------------------

.. code-block:: C

    #include <stdio.h>
    #include <SDL.h>

    #define TRUE 1
    #define FALSE 0
    #define WINDOW_WIDTH 800
    #define WINDOW_HEIGHT 600
    #define FPS 30
    #define FRAME_TAGET_TIME (1000/FPS)

    SDL_Window* window = NULL;
    SDL_Renderer *renderer = NULL;
    int gameRunning = FALSE;

    struct ball {
      float x;
      float y;
      float width;
      float height;
    }ball;



    void showRenderDriversInfo(void) {
      int numRenderDrivers = SDL_GetNumRenderDrivers();
      printf("Número de drivers de renderizado disponibles: %d\n", numRenderDrivers);

      for (int i = 0; i < numRenderDrivers; i++) {
        SDL_RendererInfo info;
        if (SDL_GetRenderDriverInfo(i, &info) == 0) {
          printf("Driver %d: %s\n", i, info.name);
        }
      }
    }

    void showSelectedRederer(void) {
      // Asumiendo que tienes un SDL_Renderer* llamado renderer que ya fue creado

      SDL_RendererInfo rendererInfo;
      if (SDL_GetRendererInfo(renderer, &rendererInfo) == 0) {
        printf("Driver de renderizado seleccionado: %s\n", rendererInfo.name);
      }
      else {
        printf("Error al obtener la información del renderizador: %s\n", SDL_GetError());
      }

    }


    int init_window(void){

      if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Error SDL_Init\n");
        return FALSE;
      }
      showRenderDriversInfo();

      window = SDL_CreateWindow(
        "My first Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN);
      if (window == NULL) {
        printf("Error SDL_CreateWindow\n");
        return FALSE;
      }

      renderer = SDL_CreateRenderer(window, -1, 0);
      if (renderer == NULL) {
        printf("Error SDL_CreateRenderer\n");
        return FALSE;
      }

      showSelectedRederer();

      return TRUE;
    }

    void process_input(void) {
      SDL_Event event;
      SDL_PollEvent(&event);

      switch (event.type) {
      case SDL_QUIT:
        gameRunning = FALSE;
        break;
      case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE) {
          gameRunning = FALSE;
        }
        break;
      }
    }

    void update(void) {
      static int last_frame_time = 0;

    //	while (!SDL_TICKS_PASSED(SDL_GetTicks(), last_frame_time + FRAME_TAGET_TIME));
      int time_to_wait = FRAME_TAGET_TIME - (SDL_GetTicks() - last_frame_time);
      if (time_to_wait > 0 && time_to_wait <= FRAME_TAGET_TIME) {
        SDL_Delay(time_to_wait);
      }
      
      float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0F;
      last_frame_time = SDL_GetTicks();

      ball.x += 20* delta_time;
      ball.y += 20* delta_time;

    }

    void DrawCircle(SDL_Renderer* renderer, int cx, int cy, int radius) {
      for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
          if (x * x + y * y <= radius * radius) {
            SDL_RenderDrawPoint(renderer, cx + x, cy + y);
          }
        }
      }
    }

    void render(void) {

      // Limpia el "lienzo" en este frame (?)
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Color de fondo: negro
      SDL_RenderClear(renderer);

      // Dibuja el rectángulo, pero aún no lo muestra
      SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Color del rectángulo: rojo
      SDL_Rect ball_rect;
      ball_rect.x = (int)ball.x; // Posición x del rectángulo
      ball_rect.y = (int)ball.y; // Posición y del rectángulo
      ball_rect.w = (int)ball.width; // Ancho del rectángulo
      ball_rect.h = (int)ball.height; // Alto del rectángulo
      SDL_RenderFillRect(renderer, &ball_rect);

      // Actualiza el lienzo
      SDL_RenderPresent(renderer);
    }

    void setup(void) {
      gameRunning = init_window();
      ball.x = 20;
      ball.y = 20;
      ball.width = 15;
      ball.height = 15;
    }

    void clean() {
      SDL_DestroyRenderer(renderer);
      SDL_DestroyWindow(window);
      SDL_Quit();
    }

    int main(int argc, char* argv[]) {
      setup();
      while (gameRunning) {
        // El concepto de gameloop para correr una aplicación
        // interactiva
        process_input(); // Leo las entradas
        update();        // calculo las físicas 
        render();        // actualizo las salidas
      }
      clean();
      return 0;
    }

La explicacón de esta parte del código está muy bien detallada en los 
videos:

.. code-block:: c

    void update(void) {
      static int last_frame_time = 0;

    //	while (!SDL_TICKS_PASSED(SDL_GetTicks(), last_frame_time + FRAME_TAGET_TIME));
      int time_to_wait = FRAME_TAGET_TIME - (SDL_GetTicks() - last_frame_time);
      if (time_to_wait > 0 && time_to_wait <= FRAME_TAGET_TIME) {
        SDL_Delay(time_to_wait);
      }
      
      float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0F;
      last_frame_time = SDL_GetTicks();

      ball.x += 20* delta_time;
      ball.y += 20* delta_time;

    }

¿Cómo funciona este código?
