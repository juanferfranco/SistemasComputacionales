Unidad 3. Programación orientada a objetos 
================================================


Introducción
--------------

En esta unidad vas a revisar los conceptos fundamentales de la programación orientada a objetos, 
pero desde una perspectiva diferente a la que ya usaste en tu curso de programación y diseño orientado 
a objetos. Esta nueva perspectiva se abordará desde la implementación de dichos conceptos usando un 
lenguaje de programación que no los soporta, C, pero en el que puedes implementarlos. Mira, en 
últimas lo que quiero que desarrolles es pensamiento crítico frente a estos pilares de la programación 
orientada a objectos para que tengas el criterio necesario para aplicarlos o no a la resolución de 
un problema particular.


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

Tu misión para este reto es aplicar los conceptos de encapsulamiento, herencia y polimorfismo  
mediante un refactoring al proyecto de la unidad anterior.


Los requisitos del proyecto son:
***********************************

* Usa el lenguaje de programación C, no C++.
* Usa la biblioteca SDL2.
* Usa Visual Studio y el sistema operativo windows.
* Mantén bajo control de versión tu programa.
* Realiza un refactoring donde justifiques y apliques claramente los conceptos de 
  encapsulamiento, herencia y polimorfismo.

Refactoring
***********************************

A continuación te voy a mostrar posibles ejemplos de lo que podrías hacer. Si tienes 
dudas o se te ocurren otras ideas habla con el profe para validar lo que quieres 
hacer.

1. Encapsulamiento. En el juego de Pong, puedes aplicar encapsulamiento al dividir el código en clases o 
   estructuras (structs) que representen diferentes componentes del juego. 
   
   Por ejemplo:

   * Clase Bola: esta clase encapsularía la lógica y los atributos relacionados con la bola en 
     el juego, como su posición, velocidad y métodos para moverla y detectar colisiones.
   * Clase Paleta: puedes crear una clase para las paletas de los jugadores, que encapsule su 
     posición, velocidad y métodos para moverlas.

2. Herencia. Puedes usar herencia para manejar diferentes tipos de paletas y power-ups en el juego.

   * Clase PaletaJugador: esta podría ser una clase base para las paletas de los jugadores. 
     Luego, puedes derivar clases como PaletaRápida y PaletaLenta que hereden de PaletaJugador, 
     pero ajusten sus atributos y comportamientos.
   * Clase PowerUp: implementa una clase base PowerUp y crea clases derivadas como 
     PowerUpAgrandar y PowerUpReducir que hereden de ella.

3. Polimorfismo. El polimorfismo se puede aplicar para manejar eventos y comportamientos 
   generales en diferentes objetos:

   * Define una interfaz o clase base llamada ElementoJuego, que podría tener métodos como 
     Actualizar() y Dibujar(). Tanto Bola como Paletas pueden implementar esta interfaz, 
     permitiendo que el código principal trate a estos objetos de manera genérica.
   * Puedes crear una lista de ElementoJuego para almacenar tanto la bola como las paletas, 
     y luego recorrerla para actualizar y dibujar cada elemento sin preocuparse por su tipo específico.

.. nota:: Esto no te recuerda a Unity?

    Lo que te pido con el polimorfismo no te recuerda un poquito a Unity? ¿No te parece 
    que ElementoJuego se parece un poco a Monobehaviour?

Estructuras de Datos:

* Lista de Elementos: utiliza una lista para representar los elementos en el juego. 
* Lista de Power-Ups: utiliza una lista enlazada o un array dinámico para almacenar los 
  power-ups presentes en el juego. Esto permitirá agregar, eliminar y gestionar los power-ups 
  de manera eficiente.

Para los Power-Ups ten presente:

* Puedes crear una clase base PowerUp que encapsulará los atributos y comportamientos 
  básicos de todos los power-ups. Esta clase podría tener métodos como 
  AplicarEfecto() y Desactivar().
* Define Power-Ups específicos. Deriva clases específicas de PowerUp para representar diferentes 
  tipos de power-ups. Cada clase derivada podría tener atributos adicionales y un 
  comportamiento único cuando se activa.

Generación de Power-Ups:

En tu juego, puedes generar power-ups en momentos específicos (por ejemplo, cuando la bola 
choca con ciertas áreas de la pantalla) o aleatoriamente durante el juego. Cuando se genere un 
power-up, crea una instancia de una de las clases derivadas y configura sus atributos según el 
tipo de efecto que deseas.

Aplicación y Efecto:

Cuando un jugador atrapa un power-up (por ejemplo, al hacer que la paleta colisione 
con el power-up), puedes activar el efecto correspondiente llamando al método 
AplicarEfecto() del power-up.

Temporización y Desactivación:

Al aplicar un efecto, el power-up puede tener una duración limitada. Configura un temporizador 
interno y desactiva el power-up después de cierto tiempo llamando al método Desactivar(). Esto 
podría revertir el efecto o simplemente hacer que el power-up desaparezca.

Gestión de Power-Ups:

Puedes mantener una lista de power-ups activos en el juego. En cada ciclo de actualización del 
juego, verifica si algún power-up ha alcanzado su tiempo límite y desactívalo. Si un power-up 
está activo, actualiza su estado y efecto en cada ciclo.

Al implementar power-ups de esta manera, estarás utilizando herencia para crear diferentes 
tipos de power-ups y polimorfismo para tratarlos de manera genérica mediante la 
clase base PowerUp. Esto permitirá que el juego maneje varios power-ups con distintos efectos 
y duraciones de manera eficiente.

Investigación
--------------

Esta fase de investigación será EXPERIMENTACIÓN PURA con los conceptos.

Ejercicios 
************

Ejercicio 1: el concepto de encapsulamiento en C
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

El encapsulamiento es la habilidad de empacar datos y funciones JUNTAS en clases. En 
`este <https://github.com/juanferfranco/OOP-in-C/blob/main/encapsulation/main.c>`__ enlace encontrarás un 
ejemplo que ilustra el concepto.

El siguiente código muestra un fragmento del ejemplo donde puedes observar la 
declaración de la clase. Nota que se declaran los datos: (x,y) y las funciones 
que modificarán esos datos.

.. code-block:: c 

    /***************************************************************************
    * Class
    ****************************************************************************/
    typedef struct Shape Shape;

    struct Shape{
        int16_t x; 
        int16_t y; 
    };

    void Shape_ctor(Shape * const me, int16_t x, int16_t y);
    void Shape_dtor(Shape * const me);
    void Shape_moveBy(Shape * const me, int16_t dx, int16_t dy);
    int16_t Shape_getX(Shape const * const me);
    int16_t Shape_getY(Shape const * const me);

Ahora te pediré que hagas lo siguiente:

* Ejecuta el programa y analiza cada aspecto detenidamente.
* ¿En qué parte del programa se crean objetos?
* ¿En qué parte de la memoria están creados esos objetos?
* ¿Qué es un objeto entonces?
* Vas a crear tres versiones del programa creando los objetos en el stack, el 
  heap y en memoria global.

.. warning:: MUY IMPORTANTE 

    NO AVANCES hasta que no hagas este ejercicio con detenimiento.

Ejercicio 2: el concepto de objeto
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Entonces, considerando el ejercicio anterior define:

* ¿Qué es una clase?
* ¿Qué es un objeto?

Ejercicio 3: el concepto de relación entre objetos
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Los objetos (colecciones de bytes) pueden estar relacionados entre
ellos. ¿Qué significa eso?

En términos muy generales, si dos objetos están relacionados, es posible que al modificar
el estado de uno de ellos se afecte el estado del otro. Ya en términos más concretos podemos
decir que un objeto está relacionado con otro cuando uno de sus atributos contiene la dirección
de memoria del otro objeto. También es posible establecer una relación cuando un método de 
una clase requiere como parámetro una referencia a un objeto de otra clase.

Crea un programa donde practiques el concepto de encapsulamiento y relaciones 
dos objetos. Puedes modificar el ejemplo que ya te di, ¿Vale?

Ejercicio 4: el concepto de método
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

No lo olvides, un objeto son bytes en memoria. Pero entonces, ¿Qué pasa con el código?

Parte de tus tareas al diseñar o PLANEAR un programa orientado a objetos es decir qué
OPERACIONES vas a realizar para crear los objetos (asignarles memoria), iniciar su estado
(construirlos), destruirlos, leer y modificar su ESTADO. PERO, POR FAVOR,
no lo olvides, cuando estás escribiendo el programa estás MODELANDO tu solución,
tu programa es un PLAN que DESCRIBE lo que ocurrirá cuando sea ejecutado.

* ¿Qué significa eso que te acabo de decir acerca de ver un programa como un PLAN o MODELO?
* Construye un ejemplo (puedes usar el de algún ejercicio anterior) donde implementes 
  una operación o método.

Ejercicio 5: el concepto de constructor
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿En los ejercicios anteriores puedes identificar al constructor de la clase?

Considerando lo que vienes analizando, define entonces qué es el constructor de una 
clase y para qué sirve.

Ejercicio 6: la relación estado-comportamiento
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Te preguntarás, pero en un clase también hay código, entonces ¿Los objetos tienen código? 
Nop. Por lo que hemos venido discutiendo ya sabes que los objetos son solo datos, pero 
ten presente que si es posible que algunos objetos tengan, como atributos, la dirección de memoria 
de algunos métodos. 

Ya sabes que al escribir una clase estás PLANEANDO qué atributos tendrá cada
objeto en memoria. Entonces, cuando escribes código en una clase estás indicando que ese código
y los atributos están relacionados, es decir, estás indicando de manera explícita 
las posibles OPERACIONES que puedes realizar sobre los DATOS. De esta manera ENCAPSULAS
en el concepto de CLASE los DATOS y el CÓDIGO. Ten en cuenta que al código también
se le conoce cómo el COMPORTAMIENTO de los objetos, es decir, las acciones que se realizarán
sobre los datos. A la información en si que almacena un objeto se le conoce como el ESTADO.  

En el ejemplo de encapsulamiento:

* ¿Cuál es el estado y el comportamiento?

Ejercicio 7: comparación con C#
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora te pediré que implementes el ejemplo de encapsulamiento (el que está en C) en C#. 

Ejercicio 8: representación UML 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Cómo sería el diagrama de clases del ejemplo de encapsulamiento?

Ejercicio 9: el concepto de herencia en C
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

La herencia es la habilidad de definir una nueva clase basada en clases existentes para reusar 
y organizar el código (aunque te cuento que hay mucha controversia con este concepto y 
algunos lenguajes de programación modernos han prescindido de él porque son más los problemas 
que lo beneficios que trae). En `este <https://github.com/juanferfranco/OOP-in-C/blob/main/inheritance/main.c>`__ 
enlace encontrarás un ejemplo que ilustra el concepto.

En el siguiente código te muestro cómo la clase Rectangle hereda de la clase Shape.

.. code-block:: c 

    /*****************************************************
    * Class Shape
    ******************************************************/
    typedef struct Shape Shape;
    struct Shape{
        int16_t x; 
        int16_t y; 
    };

    /*****************************************************
    * Class Rectangle
    ******************************************************/
    typedef struct Rectangle Rectangle;

    struct Rectangle {
        Shape super;
        uint16_t width;
        uint16_t height;
    };

Analiza con detenimiento el ejemplo y piensa:

* ¿Cómo se vería en memoria un objeto de la clase Shape?
* ¿Cómo se vería en memoria un objeto de la clase Rectangle?
* ¿Qué relación ves entre los dos objetos en términos de cómo se ven en memoria?
* Cuando decimos que un Rectangle también es un Shape ¿Tiene sentido?
* ¿Qué está pasando en el siguiente código?

.. code-block:: c 

    (Shape *)r1


Ejercicio 10: comparación con C#
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora es un buen momento para que construyas la versión en C# del ejercicio anterior 
y compares.

Ejercicio 11: representación UML
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Construye un diagrama de clases para el ejemplo de herencia. 


Ejercicio 12: el concepto de polimorfismo en C
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

El polimorfismo es la habilidad de sustituir, en tiempo de ejecución, objetos que tengan interfaces que coinciden. 
Te pongo un ejemplo con C#. Piensa que tienes
un método que puede recibir objetos de diferentes clases, pero todos tienen en común que implementan 
la misma interfaz. El truco es hacer que el tipo de dato que recibe el método sea del tipo de la interfaz. 
De esta manera podrás pasarle un objeto de cualquier clase que implemente la interfaz. De ahí que el método 
tendrá un comportamiento polimórfico porque hará cosas diferentes dependiendo del tipo de objeto 
que le pases. Ufffff. ¡Es muy cool!

.. warning:: ESTE CONCEPTO ES MUY IMPORTANTE 

    Este concepto es muy importante y es la base de muchas de las estrategias de diseño 
    orientado a objetos que verás en el curso de Scripting.

.. warning:: PAUSA

    ¿Qué te parece? ¿Genial no?

    Pausa para suspirar y secarte las lágrimas de felicidad luego de un momento tan emotivo.

En `este <https://github.com/juanferfranco/OOP-in-C/blob/main/polymorphism/main.c>`__ 
enlace encontrarás un ejemplo que ilustra el concepto implementado en lenguaje C. Trata de hacer 
una primer lectura y entender lo que está pasando. 

Ahora me gustaría pedirte que te enfoques en el siguiente fragmento:

.. code-block:: c 

    /*****************************************************
    * Class Shape
    ******************************************************/
    typedef struct IShapeOperations IShapeOperations;
    typedef struct Shape Shape;

    struct IShapeOperations {
        uint32_t (*area)(Shape const * const me);
        void (*draw)(Shape const * const me);
    };

    struct Shape{
        IShapeOperations const *vptr;
        int16_t x; 
        int16_t y; 
    };

    /*****************************************************
    * Class Rectangle
    ******************************************************/
    typedef struct Rectangle Rectangle;

    struct Rectangle {
        Shape super;
        uint16_t width;
        uint16_t height;
    };

    /*****************************************************
    * Class Circle
    ******************************************************/
    typedef struct Circle Circle;

    struct Circle {
        Shape super;
        uint16_t rad;
    };


Nota que Rectangle y Circle están heredando de la clase Shape, pero a diferencia del ejercicio de herencia 
observa que hay un elemento nuevo. Se trata de IShapeOperations. Esta estructura es el primer miembro 
de Shape y por tanto será también el primer atributo de Rectangle y Circle. 

Nota que IShapeOperations tiene punteros a las funciones area y draw. Mira ahora por favor el constructor 
de Shape:

.. code-block:: c 

  void Shape_ctor(Shape * const me, int16_t x, int16_t y){
    static IShapeOperations const vptr = {Shape_area,Shape_draw};
    me->vptr = &vptr;
    me->x = x;
    me->y = y;
  }

¿Viste que los punteros están inicializados por defecto con dos implementaciones de area y draw? Se trata 
de Shape_area y Shape_draw. Por tanto, si no hacemos nada en los constructores de Rectangle y Circle 
estos tendrán por defecto la implementación que la clase Shape aporte para estos métodos. El truco es hacer 
que las clases que hereden de Shape hagan una ``sobre escritura`` o 
``OVERRIDE`` de los punteros de IShapeOperations. De esta manera harás que tanto area como draw sean polimórficas.
No pierdas de vista que area y draw reciben una referencia a Shape, pero es que Rectangle y Circle son también 
Shapes. Es precisamente este truco lo que permite que area y draw se comporten de manera polimórfica.

* ¿Le das una mirada de nueva al código?
* Modifica la aplicación para agregar un nuevo Shape.

Ejercicio 13: comparación con C#
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora es un buen momento para que construyas la versión en C# del ejercicio anterior 
y compares. Repasa antes qué son las clases abstractas en C#, ¿Vale?

Ejercicio 14: representación UML
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Construye un diagrama de clases para el ejemplo de polimorfismo. 

Ejercicio 15: interfaces
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Recuerdas el concepto de interfaz en C#?  Si no lo recuerdas dale una lectura y mira 
algunos ejemplos.

Analiza de nuevo el ejemplo de polimorfismo. 

* ¿Cómo podrías implementar una interfaz en C con lo que acabas de aprender sobre polimorfismo?

.. warning:: EJERCICIO IMPORTANTE

  Inventa un ejemplo que haga uso del concepto de interfaz usando lenguaje C. ¿Me lo muestras 
  cuando lo tengas para hacerme muy feliz?

Ejercicio 16: ejemplo de implementación del patrón Command en C
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

En `este <https://github.com/juanferfranco/OOP-in-C/blob/main/commandPattern/main.c>`__ enlace te mostraré 
un ejemplo donde se implementa el patrón de diseño Command. Este ejemplo es una implementación en C 
del ejemplo en C# que puedes encontrar `aquí <https://refactoring.guru/design-patterns/command/csharp/example>`__.

Ahora te toca a ti:

* Analiza el código y trata de explicarle a otra persona cómo funciona.
* Analiza en que parte de la memoria están los datos y trata de realizar diagramas que 
  relacionen las partes.
* Trata de decir en una frase CORTA para qué sirve el polimorfismo.


Aplicación 
-----------

* ¿Tienes los tres conceptos fundamentales claros? Si no es así regresa a la fase 
  de investigación.
* Planea, antes de implementar, lo qué vas a refactorizar y cómo mostrarás 
  la aplicación de los conceptos de encapsulamiento, herencia y polimorfismo. 
  Habla con el profe si esto te da más tranquilidad.
* Inicia el refactoring.
* No olvides ir documentando cómo vas haciendo las pruebas parciales y luego 
  las pruebas de integración. Es decir, cuando tienes una idea primero haces 
  algunos experimentos para probarla. Luego la incorporas a tu aplicación y 
  pruebas que se integre adecuadamente.

Compartir
-----------

Vas a evidenciar tu proceso con las siguientes evidencias que compartirás en 
el archivo README.md de esta unidad:

#. Bitácoras de las 3 sesiones de trabajo de cada semana.
#. Códigos .c de la aplicación interactiva bajo control de versión.
#. Muestro y explico mi implementación del encapsulamiento.
#. Muestro y explico mi implementación de la herencia.
#. Muestro y explico mi implementación del polimorfismo.
#. Muestra cómo probaste la funcionalidad de cada característica de la aplicación,
#. Muestra cómo probaste la integración de cada característica con las anteriores.
