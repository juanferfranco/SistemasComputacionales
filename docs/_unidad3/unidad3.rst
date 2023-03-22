Unidad 3. Programación orientada a objetos 
================================================

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

.. tip:: RESULTADO DE APRENDIZAJE DEL CURSO 

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

Ejercicio 3: concepto de relación entre objetos
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

Ejercicio 6: relación estado-comportamiento
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

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


Ejercicio 9: el concepto de encapsulamiento en C
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

La herencia es la habilidad de definir una nueva clase basada en clases existentes para reusar 
y organizar el código (aunque te cuento que hay mucha controversia con este concepto y 
algunos lenguajes de programación modernos han prescindido de él porque son más los problemas 
que lo beneficios que trae). En `este <https://github.com/juanferfranco/OOP-in-C/blob/main/inheritance/main.c>`__ 
enlace encontrarás un ejemplo que ilustra el concepto.

El siguiente código te muestro cómo la clase Rectangle hereda de la clase Shape.

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

Ejercicio 11: el concepto de polimorfismo en C
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

El polimorfismo es la habilidad de sustituir, en tiempo de ejecución, objetos que tengan interfaces que coinciden. 
En `este <https://github.com/juanferfranco/OOP-in-C/blob/main/polymorphism/main.c>`__ 
enlace encontrarás un ejemplo que ilustra el concepto.

El siguiente código te muestro una manera de lograr lo anterior. Nota que Rectangle y Circle 


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


Ahora te voy a mostrar una técnica para implementar polimorfismo en tiempo de 
ejecución en C (`tomado de aquí <https://www.packtpub.com/free-ebook/extreme-c/9781789343625>`__).

Pero antes ¿Qué es el polimorfismo en tiempo de ejecución? Antes mira qué te permite hacer
el polimorfismo. Considera que tienes estos tres objetos:

.. code-block:: c

    animal_t *animal = animal_new();
    animal_ctor(animal);

    struct cat_t *cat = cat_new();
    cat_ctor(cat);

    struct duck_t *duck = duck_new();
    duck_ctor(duck);

cat y duck heredan de animal. Por tanto, como cat y duck son animal también,
entonces al hacer esto:

.. code-block:: c

    // This is a polymorphism
    animal_sound(animal);
    animal_sound((animal_t *)cat);
    animal_sound((animal_t *)duck);

Consigues esta salida:

.. code-block:: c

    Animal: Beeeep
    Cat: Meow
    Duck: Quack

Entonces puedes ver que la función animal_sound exhibe un comportamiento polimórfico
dependiendo del tipo de referencia que le pasemos.

¿Para qué sirve esto? Supón que tienes un código base al cual quieres adicionarle
funcionalidades nuevas. El polimorfismo te permite mantener el código base lo más intacto
posible a medida que añades más comportamientos por medio de la herencia.

Ahora, si. Mira cómo se puede implementar:

animal.h:

.. code-block:: c

    #ifndef ANIMAL_H_
    #define ANIMAL_H_

    typedef void (*sound_func_t)(void *);

    typedef struct {
        char *name;
        // This member is a pointer to the function which
        // performs the actual sound behavior
        sound_func_t sound_func;
    } animal_t;


    animal_t *animal_new();

    void animal_ctor(animal_t *);
    void animal_dtor(animal_t *);

    void animal_get_name(animal_t *, char *);
    void animal_sound(animal_t *);

    #endif /* ANIMAL_H_ */

animal.c:

.. code-block:: c

    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
    #include "animal.h"

    void __animal_sound(void *this) {
        animal_t* animal = (animal_t *)this;
        printf("%s: Beeeep\n", animal->name);
    }

    animal_t *animal_new() {
        return (animal_t *)malloc(sizeof(animal_t));
    }

    void animal_ctor(animal_t *this) {
        this->name = (char *)malloc(10 * sizeof(char));
        strcpy(this->name, "Animal");
        this->sound_func = &__animal_sound;
    }

    void animal_dtor(animal_t *this) {
        free(this->name);
    }

    void animal_get_name(animal_t *this, char *buffer) {
        strcpy(buffer, this->name);
    }

    void animal_sound(animal_t *this) {
        this->sound_func(this);
    }

cat.h:

.. code-block:: c

    #ifndef CAT_H_
    #define CAT_H_

    #include "animal.h"

    typedef struct {
        animal_t animal;
    } cat_t;

    cat_t *cat_new();

    void cat_ctor(cat_t *);

    void cat_dtor(cat_t *);

    #endif /* CAT_H_ */

cat.c:

.. code-block:: c

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "cat.h"

    void __cat_sound(void *this) {
        animal_t *animal = (animal_t *) this;
        printf("%s: Meow\n", animal->name);
    }

    // Memory allocator
    cat_t *cat_new() {
        return (cat_t *)malloc(sizeof(cat_t));
    }
    // Constructor
    void cat_ctor(cat_t *this) {
        animal_ctor((animal_t *)this);
        strcpy(this->animal.name, "Cat");
        this->animal.sound_func = __cat_sound;
    }

    void cat_dtor(cat_t *this) {
        animal_dtor((animal_t *)this);
    }

duck.h:

.. code-block:: c

    #ifndef DUCK_H_
    #define DUCK_H_

    #include "animal.h"

    typedef struct {
        animal_t animal;
    } duck_t;

    duck_t *duck_new();

    void duck_ctor(duck_t *);

    void duck_dtor(duck_t *);


    #endif /* DUCK_H_ */


duck.c:

.. code-block:: c

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "duck.h"

    void __duck_sound(void *this) {
        animal_t* animal = (animal_t*)this;
        printf("%s: Quacks\n", animal->name);
    }

    duck_t *duck_new() {
        return (duck_t *)malloc(sizeof(duck_t));
    }

    void duck_ctor(duck_t *this) {
        animal_ctor((animal_t *)this);
        strcpy(this->animal.name, "Duck");
        this->animal.sound_func = __duck_sound;
    }

    void duck_dtor(duck_t *this) {
        animal_dtor((animal_t *)this);
    }

main.c:

.. code-block:: c

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "animal.h"
    #include "cat.h"
    #include "duck.h"


    int main(int argc, char* argv[]) {

        animal_t *animal = animal_new();
        animal_ctor(animal);

        cat_t *cat = cat_new();
        cat_ctor(cat);

        duck_t *duck = duck_new();
        duck_ctor(duck);

        animal_sound(animal);
        animal_sound((animal_t *)cat);
        animal_sound((animal_t *)duck);

        animal_dtor(animal);
        free(animal);

        cat_dtor(cat);
        free(cat);

        duck_dtor(duck);
        free(duck);

        return EXIT_SUCCESS;
    }

Para ejecutar el código realizas las siguientes operaciones:

.. code-block:: bash 

    gcc -Wall -c cat.c -o cat.o
    gcc -Wall -c duck.c -o duck.o
    gcc -Wall -c animal.c -o animal.o
    gcc -Wall -c main.c -o main.o    
    gcc -Wall main.o cat.o duck.o animal.o -o app

Ejercicio 19: implementación en C#
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora vas a implementar el ejercicio 18 en C#. Compara, analiza, questiona y concluye.

.. warning:: ALERTA DE SPOILER

    Te dejo una posible implementación del ejercicio 18 en C#

.. code-block:: csharp

    using System;

    public class Animal
    {
        public string Name { get; private set; }

        public Animal(string name)
        {
            Name = name;
        }
        public virtual void AnimalSound()
        {
            Console.WriteLine(Name + ": Beep");
        }
    }

    public class Cat : Animal
    {

        public Cat(string name) : base(name)
        {

        }
        public override void AnimalSound()
        {
            Console.WriteLine(Name + ": Meow");
        }
    }

    public class Duck : Animal
    {

        public Duck(string name) : base(name)
        {

        }
        public override void AnimalSound()
        {
            Console.WriteLine(Name + ": Quacks");
        }
    }


    public class Program
    {
        static void Main(string[] args)
        {

            var Animals = new List<Animal>
            {
                new Animal("Animal"),
                new Cat("Nucita"),
                new Duck("Lindo")
            };

            foreach(var animal in Animals){
                animal.AnimalSound();
            }
        }
    }

El resultado sería:

.. code-block:: bash

    Animal: Beep
    Nucita: Meow
    Lindo: Quacks

Ejercicio 20: clases abstractas
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Qué son las clases abstractas? Son un tipo de clases de las cuales no puedes
crear OBJETOS porque les falta o tienen incompleta una parte. 
Entonces ¿Para qué sirven? Sirven para crear programas
orientados a objetos que puedan extenderse al máximo y con la menor cantidad
de dependencias entre sus componentes. ¿Te suena que vale la pena?

Mira este problema: tienes que construir una biblioteca que te permita comunicar,
por un puerto serial, a Unity con un sensor. Las responsabilidades del código
son: gestionar el puerto serial, gestionar la comunicación con el hilo
principal o hilo del motor y enviar-recibir datos siguiendo un protocolo específico.
En este escenario podrías escribir una biblioteca que resuelva este problema solo
para el sensor particular o escribirla de tal manera que puedas reutilizar
casi todo el código y solo cambiar el protocolo de comunicación si a futuro
cambias de sensor.

¿Cuál de las dos opciones de suena más?

Si te suena más la segunda, entonces todas las partes comunes del código irán
en la clase abstracta y las partes que varían, en este caso el protocolo de comunicación,
irán en otra clase que herede de la clase abstracta. Aquí entra en juego el otro concepto
que estudiamos, el POLIMORFISMO, ¿Cómo? En el código de la clase
abstracta se llamará el código que varía o métodos VIRTUALES, pero este código no estará 
implementado. Por tanto, los métodos virtuales tendrás que implementarlo en la clase que
hereda, de la cual, si PUEDES crear OBJETOS. Hermoso, ¿No?.

Ten presente que en la medida que llevas al extremo este concepto de abstracción podrás
llegar a clases que no tengan atributos sino SOLO métodos virtuales. En este punto habrás
llegado a las INTERFACES, de las cuales tampoco podrás crear objetos.
