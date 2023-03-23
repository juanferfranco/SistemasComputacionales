Unidad 3. Programación orientada a objetos 
================================================

.. warning:: UNIDAD EN CONSTRUCCIÓN

    Esta unidad se encuentra casi lista, le estoy dando una última revisión 
    antes de que comiences a trabajar en ella. Esta unidad es un refactoring 
    de la unidad 3 de los semestres anteriores. Si llegas aquí luego 
    de terminar la unidad 2 habla con el profesor.

Introducción
--------------

En esta unidad vas a revisar los conceptos fundamentales de la programación 
orientada a objetos, pero desde una perspectiva diferente a la que ya usaste en 
tu curso de programación y diseño orientado a objetos. Por tanto, esta nueva 
perspectiva se abordará desde la implementación de dichos conceptos usando un lenguaje 
de programación que no los soporta, C, pero en el que puedes implementarlos. Mira, 
en últimas lo que quiero que desarrolles es pensamiento crítico frente a estos pilares 
de la programación orientada a objectos para que desarrolles el criterio necesario 
para aplicarlos o no a la resolución de un problema particular.

Propósito de aprendizaje
**************************

Reflexionar profundamente sobre tres conceptos fundamentales de la programación orientada a objetos 
como son el encapsulamiento, la herencia y el polimorfismo mediante la implementación de estos 
usando el lenguaje de programación C.

Evaluación
-----------------------------------

.. note:: RESULTADO DE APRENDIZAJE DEL CURSO 

  ¿Recuerdas el resultado de aprendizaje del curso?

  Aplico los conceptos necesarios para el correcto diseño, implementación, 
  funcionamiento y diagnóstico del software en la producción de sistemas de 
  entretenimiento digital utilizando los procedimientos y herramientas 
  adecuadas según el contexto. ``NIVEL RESOLUTIVO``.

  La idea de esta evaluación es que evidencies que eres capaz de aplicar 
  los conceptos fundamentales de la programación orientada a objetos para la 
  solución de los problemas que encontrarás en la construcción de la 
  aplicación interactiva que te propondré.
  
  Se espera que puedas evidenciar:

  * Un entendimiento profundo de los conceptos de encapsulamiento, herencia y polimorfismo.
  * Aplicar un patrón de diseño donde verás los conceptos anteriores relacionados.
  * Diagnosticar y solucionar problemas en el proceso de implementación de la aplicación.

  No solo se espera que apliques los conceptos para construir la aplicación, sino 
  también para resolver los problemas (errores) que se presenten al construirla.

Enunciado 
************

Tu misión para esta evaluación es aplicar los conceptos de encapsulamiento, herencia y polimorfismo, 
mediante:

* La implementación de un patrón de diseño.
* La ampliación de las funcionalidades del proyecto de la unidad anterior.
* Un refactoring a la aplicación aplicando los conceptos adecuados.

Los requisitos de la aplicación son:

* Vas a realizar un refactoring a la solución del proyecto anterior aplicando los conceptos 
  de encapsulamiento, herencia y polimorfismo. Ten presente que deberás corregir los comandos 
  que implementaste con otro nombre o empleando una estrategia diferente a la solicitada. 
* Adicionarás la posibilidad de crear filas nuevas en tiempo de ejecución a la base de datos.
  Lo harás de dos maneras. Cargando los pokémon de un archivo o con el comando: 
  
  ``mkpok ID,Name,Form,Type1,Type2,Total,HP,Attack,Defense,Sp. Atk,Sp. Def,Speed,Generation``

* Adicionarás la posibilidad de editar un pokémon con el comando:

    ``edit stat_name stat_value``

* Adicionarás un comando para configurar la cantidad máxima de comandos que se podrán deshacer así:

  ``undomax value``

* Aplicarás el patrón de diseño Command para agregarle a la aplicación la posibilidad de deshacer 
  los últimos n comandos:

  ``undo n``

¿Qué debes entregar?
**********************

Debes entregar todo lo solicitado en `este <https://classroom.github.com/a/pD6bXkPG>`__ repositorio. 

Entrega:

* El código con la solución del problema.
* En el README.md explicarás por qué y cómo aplicaste los conceptos de encapsulamiento, herencia 
  y polimorfismo a cada aspecto de la solución.

Trayecto de actividades
------------------------

Para realizar los ejercicios y responder las preguntas del trayecto de actividades 
te voy a crear un repositorio. Es muy importante que evidencies tu avance por el trayecto 
dejando toda la evidencia en el repositorio del proceso.

Ejercicios 
************

Para la realización de los ejercicios de la unidad te voy a crear 
`este <https://classroom.github.com/a/NrcyB4P5>`__ repositorio donde puedas 
experimentar tu solo. Recuerda que la evaluación de la unidad tendrá su propio repositorio. USA CODESPACES.

Ejercicio 1: el concepto de encapsulamiento en C
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

El encapsulamiento es la habilidad de empacar datos y funciones JUNTAS en clases. En 
`este <https://github.com/juanferfranco/OOP-in-C/blob/main/encapsulation/main.c>`__ enlace encontrarás un 
ejemplo que ilustra el concepto.

El siguiente código muestra un fragmento del ejemplo donde puedes observar la 
declaración de la clase. Nota que se declaran los datos: x y y y las funciones 
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
de memoria del otro objeto.

Crea un programa donde practiques el concepto de encapsulamiento y relaciones 
dos objetos.

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
Nop. Por lo que hemos venido discutiendo ya sabes que los objetos son solo datos. 
También ya sabes que cuando escribes una clase estás PLANEANDO qué atributos tendrá cada
objeto en memoria. Entonces cuando escribes código en una clase estás indicando que ese código
y los atributos están relacionados, es decir, estás indicando de manera explícita 
las posibles OPERACIONES que puedes realizar sobre los DATOS. De esta manera ENCAPSULAS
en el concepto de CLASE los DATOS y el CÓDIGO. Ten en cuenta que al código también
se le conoce cómo el COMPORTAMIENTO de los objetos, es decir, las acciones que se realizarán
sobre los datos. A la información en si que almacena un objeto se le conoce como el ESTADO.  

En el ejemplo de encapsulamiento:

* ¿Cuál es el estado y el comportamiento?

Ejercicio 7: comparación con C#
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora te pediré que implementes el ejemplo de encapsulamiento en C#. 

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
tendrá un comportamiento polimórfico porque el método hará cosas diferentes dependiendo del tipo de objeto 
que le pases. Ufffff. ¡Es muy cool!

.. warning:: ESTE CONCEPTO ES MUY IMPORTANTE 

    Este concepto es muy importante y es la base de muchas de las estrategias de diseño 
    orientado a objetos que verás en el curso de Scripting.

.. warning:: PAUSA

    ¿Qué te parece? ¿Genial no?

    Pausa para suspirar y secarse las lágrimas de felicidad luego de un momento tan emotivo.

En `este <https://github.com/juanferfranco/OOP-in-C/blob/main/polymorphism/main.c>`__ 
enlace encontrarás un ejemplo que ilustra el concepto implementado en lenguaje C. Trata de hacer 
una primer lectura y entender lo que está pasando. Ahora me gustaría pedirte que te enfoques en 
el siguiente fragmento y leas luego algo que te diré para que analicemos juntos lo que está pasando.

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

Nota que IShapeOperations tiene punteros a las funciones area y draw. Mira ahora por favor, el constructor 
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