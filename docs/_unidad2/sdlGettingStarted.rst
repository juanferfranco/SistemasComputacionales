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
