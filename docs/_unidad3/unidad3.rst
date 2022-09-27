Unidad 3. Programación orientada a objetos 
================================================

Introducción
--------------

En esta unidad vas a repasar y analizar cómo implementar en C los tres conceptos 
fundamentales de la programación orientada a objetos.

Propósito de aprendizaje
**************************

Implementar los tres conceptos fundamentales de la programación orientada a objetos 
en el lenguaje de programación C.

Evaluación
-----------------------------------

.. warning:: FECHA DE ENTREGA Y SUSTENTACIÓN 

    La evaluación debe estar sustentada y entregada en el repositorio 
    el día 14 de octubre de 2022 finalizando la sesión de clase.

    Recuerda confirmar tu equipo de trabajo.

Enunciado 
************

Tu misión para esta evaluación es demostrar que entiendes los conceptos fundamentales de 
la programación orientada a objetos mediante la implementación de una caso de estudio en C.

Originalmente el caso de estudio está implementado en C#. Tu deberás implementar los conceptos 
que están allí en C.

La documentación y el código del caso de estudio los encuentras 
`aquí <https://refactoring.guru/design-patterns/observer>`__ y 
`aquí <https://refactoring.guru/design-patterns/observer/csharp/example>`__ 
respectivamente.


¿Qué debes entregar?
**********************

Debes entregar todo lo solicitado en 
`este <https://classroom.github.com/a/mTTnuZJR>`__ repositorio. Entrega:

* La implementación del caso de estudio en C# (esta ya está hecha).
* La implementación del caso de estudio en C.
* La documentación en el archivo README.md. Esta documentación debe tener:

    * Un enlace a un video corto en youtube (unlisted) (1 minuto máximo), SIN EXPLICACIONES, que muestre 
      la compilación y ejecución del caso de estudio.
    * Explicar cómo se implementó el encapsulamiento, la herencia y el polimorfismo.



Trayecto de actividades
------------------------

Te voy a dejar en esta sección un material que puedes usar si lo deseas para preparar la solución 
de la evaluación de la unidad.

Ejercicios 
************

.. warning:: ESTE ES EL MÁS IMPORTANTE DE LOS EJERCICIOS

    El ejercicio 1 es tal vez el recurso más importante para resolver el problema 
    propuesto. TE PUEDES concentrar solo en este ejercicio.

    Los ejercicios 2 al 20 son complementarios y en algunos casos te muestran implementaciones 
    alternativas a las que muestra el ejercicio 1.


Ejercicio 1: implementación en C
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

En `este <https://github.com/QuantumLeaps/OOP-in-C/blob/master/doc/AN_OOP_in_C.pdf>`__ enlace 
encontrarás un documento que te explicará detalladamente cómo implementar los conceptos 
fundamentales de la programación orientada a objetos en lenguaje C.

Todo el código fuente con la implementación del encapsulamiento, la herencia y el polimorfismo 
lo encontrarás en `este <https://github.com/QuantumLeaps/OOP-in-C>`__ repositorio.


.. warning:: EJERCICIOS COMPLEMENTARIOS

    Ahora te dejaré más material que puede serte de utilidad.

Ejercicio 2: el concepto de clase en C
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

En el siguiente ejemplo, el código en queue.h y queue.c tratan de implementar el concepto de ``CLASE`` que
ya conoces de otros lenguajes de programación.

queue.h:

.. code-block:: c 

    #ifndef _QUEUE_H
    #define _QUEUE_H

    typedef struct {
        int front;
        int rear;
        double* arr;
    } queue_t;

    queue_t* create(int size);
    void destroy(queue_t* this);
    int size(queue_t* this);
    void enqueue(queue_t* this, double item);
    double dequeue(queue_t* q);

    #endif

queue.c:

.. code-block:: c 

    #include "queue.h"
    #include <stdlib.h> 

    static void init(queue_t* this, int size) {
        this->front = 0;
        this->rear = 0;
        this->arr = (double*)malloc(size * sizeof(double));
    }

    queue_t* create(int size){
        queue_t* q = malloc(sizeof(queue_t));
        init(q,size);
        return(q);
    }

    void destroy(queue_t* this){
        free(this->arr);
        free(this);
    }

    int size(queue_t* this){
        return this->rear - this->front;
    }

    void enqueue(queue_t* this, double item) {
        this->arr[this->rear] = item;
        this->rear++;
    }
    
    double dequeue(queue_t* this) {
        double item = this->arr[this->front];
        this->front++;
        return item;
    }

main.c:

.. code-block:: c 

    #include <stdio.h> 
    #include "queue.h"

    int main(int argc, char** argv) {

        queue_t* q = create(10);
        enqueue(q, 6.5);
        enqueue(q, 1.3);
        enqueue(q, 2.4);
        printf("%f\n", dequeue(q));
        printf("%f\n", dequeue(q));
        printf("%f\n", dequeue(q));
        destroy(q);
        return 0;
    }

Para compilar este ejemplo sigue los siguientes pasos:

.. code-block:: bash

    gcc -c -g -Wall queue.c -o queue.o
    gcc -c -g -Wall main.c -o main.o
    gcc -g -Wall queue.o main.o -o exe

Ejecuta el código y verifica con valgrind el manejo de la memoria

.. code-block:: bash

    ./exe
    valgrind ./exe

¿Qué resultado obtienes?
¿En qué parte de la memoria está almacenada la variable q?
¿Explica cuánta memoria y dónde se está creando con la función create(10)?

Ejercicio 3: el concepto de objeto
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Como te has dado cuenta hasta ahora, C NO es un lenguaje de programación
orientado a objetos; sin embargo, te preguntarás ¿Es posible escribir 
programas orientados a objetos con C? La respuesta es si. El punto es que
en su sintaxis C NO soporta los conceptos de clases, herencia y polimorfismo.
Aún así, es posible implementar estos conceptos de manera indirecta.

¿Y en últimas qué son los objetos?

Mira, no le demos vueltas conceptuales al asunto. Un objeto no es más que
un conjunto de datos en la memoria. OJO: SON DATOS y están en la
MEMORIA. Esto último es clave. Los objetos solo viven en tiempo
de ejecución.

Entonces cuando estoy escribiendo el programa hay objetos? NO, ese es el punto
precisamente que intento aclararte de entrada. Cuando escribes un programa orientado
a objetos, NO TIENES OBJETOS aún. Lo que defines es cómo serán esos objetos,
cómo se crearán, cuándo se crearán, cómo y cuándo se usarán y cómo y cuándo
se destruirán (en algunos lenguajes de programación). Es decir, tu programa
describe lo que pasará con los OBJETOS cuando lo ejecutes.

Te lo repito de nuevo: cuando programas orientado a objetos NO estás creando objetos.
Estás más bien indicando qué se debe hacer para crearlos cuando el programa se EJECUTE.

¿Claro lo anterior? Pregunta si no es claro.

Por lo anterior, es que existe el término DISEÑO ORIENTADO A OBJECTOS. Porque
cuando DISEÑAS un programa orientado a objetos te tienes qué imaginar cómo serán esos
OBJETOS, cuándo se crearán y cuáles serán las relaciones entre ellos cuando 
ejecutes el programa.

Ejercicio 4: concepto de mutabilidad e inmutabilidad
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Profe, si yo pudiera ir a ver un objeto en memoria ¿Cómo se vería?

No lo olvides, en últimas, un objeto es una colección de bytes en la memoria. A esas 
posiciones de memoria que componen el objeto las denominamos ATRIBUTOS y al contenido
de esos atributos los llamamos EL ESTADO DEL OBJETO. 

Cuando puedes modificar los valor de los atributos de un objeto mientras el programa
corre se dice que el objeto es MUTABLE. Pero también el objeto puede ser INMUTABLE,
es decir, que una vez creado el objeto e inicializados sus atributos, no podrás cambiar
sus valores o su estado.

Ejercicio 5: concepto de relación entre objetos
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ya te comenté que los objetos (colecciones de bytes) pueden estar relacionados entre
ellos. ¿Qué significa eso?

En términos muy generales, si dos objetos están relacionados, es posible que al modificar
el estado de uno de ellos se afecte el estado del otro. Ya en términos más concretos podemos
decir que un objeto está relacionado con otro cuando uno de sus atributos contiene la dirección
de memoria del otro objeto.

Ejercicio 6: el concepto de método
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

No lo olvides, un objeto son bytes en memoria. Pero entonces, ¿Qué pasa con el código?

Parte de tus tareas al diseñar o PLANEAR un programa orientado a objetos es decir qué
OPERACIONES vas a realizar para crear los objetos (asignarles memoria), iniciar su estado
(construirlos), destruirlos, leer y modificar su ESTADO. PERO, POR FAVOR,
no lo olvides, cuando estás escribiendo el programa estás MODELANDO tu solución,
tu programa es un PLAN que DESCRIBE lo que ocurrirá cuando sea ejecutado.

Ejercicio 7: relación estado-comportamiento
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Cómo puedes definir la construcción de un objeto?

Lo puedes hacer de dos formas:

* Construyes un objeto vacío o con un conjuntos mínimo de atributos. A medida que el programa
  se ejecuta, se van añadiendo más atributos. A esta técnica se le conoce como 
  prototype-based OOP, por ejemplo en python y javascript.
* El objeto ya tiene unos atributos predeterminados. A esta
  técnica se le conoce como class-based OOP, por ejemplo en C++, C#, java y python.

Para utilizar la segunda forma, debes crear una plantilla predeterminada o CLASE que indique
los atributos que tendrá un objeto al ejecutar el programa.

Te preguntarás, pero en un clase también hay código, entonces ¿Los objetos tienen código? 
Nop. Por lo que hemos venido discutiendo ya sabes que los objetos son solo datos. 
También ya sabes que cuando escribes una clase estás PLANEANDO qué atributos tendrá cada
objeto en memoria. Entonces cuando escribes código en una clase estás indicando que ese código
y los atributos están relacionados, es decir, estás indicando de manera explícita 
las posibles OPERACIONES que puedes realizar sobre los DATOS. De esta manera ENCAPSULAS
en el concepto de CLASE los DATOS y el CÓDIGO. Ten en cuenta que al código también
se le conoce cómo el COMPORTAMIENTO de los objetos, es decir, las acciones que se realizarán
sobre los datos.  

Ejercicio 8: implementación del concepto de clase
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Cómo hacemos para implementar las ideas anteriores en C? Ya sabes que C no soporta 
de manera explícita el concepto de clase, pero podemos implementar dicho concepto de manera
implícita:

* Usa una estructura para encapsular los atributos del objeto.
* Utiliza funciones para definir el comportamiento de los objetos. Las funciones
  que definen el comportamiento del objeto recibirán como argumento la dirección en 
  memoria de la estructura que encapsula los atributos del objeto.

Analiza de nuevo este código:

queue.h:

.. code-block:: c 

    #ifndef _QUEUE_H
    #define _QUEUE_H

    typedef struct {
        int front;
        int rear;
        double* arr;
    } queue_t;

    queue_t* create(int size);
    void destroy(queue_t* this);
    int size(queue_t* this);
    void enqueue(queue_t* this, double item);
    double dequeue(queue_t* q);

    #endif

queue.c:

.. code-block:: c 

    #include "queue.h"
    #include <stdlib.h> 

    static void init(queue_t* this, int size) {
        this->front = 0;
        this->rear = 0;
        this->arr = (double*)malloc(size * sizeof(double));
    }

    queue_t* create(int size){
        queue_t* q = malloc(sizeof(queue_t));
        init(q,size);
        return(q);
    }

    void destroy(queue_t* this){
        free(this->arr);
        free(this);
    }

    int size(queue_t* this){
        return this->rear - this->front;
    }

    void enqueue(queue_t* this, double item) {
        this->arr[this->rear] = item;
        this->rear++;
    }
    
    double dequeue(queue_t* this) {
        double item = this->arr[this->front];
        this->front++;
        return item;
    }

Nota que en queue.h declaras qué atributos tendrá el objeto:

.. code-block:: c 

    #ifndef _QUEUE_H
    #define _QUEUE_H

    typedef struct {
        int front;
        int rear;
        double* arr;
    } queue_t;

Y qué funciones podrás invocar para leer o escribir dichos atributos, es decir, el comportamiento
del objeto:

.. code-block:: c 

    queue_t* create(int size);
    void destroy(queue_t* this);
    int size(queue_t* this);
    void enqueue(queue_t* this, double item);
    double dequeue(queue_t* q);

Estas cuatro funciones te permiten crear una cola, destruirla, conocer su tamaño,
almacenar en la cola y leer información de ella. Nota que casi todas las funciones
definen un parámetro llamado this. Este parámetro contendrá la dirección del objeto
sobre el cual actuará el código definido en la función.

Por último, observa de nuevo la función main.c:

.. code-block:: c 

    #include <stdio.h> 
    #include "queue.h"

    int main(int argc, char** argv) {

        queue_t* q = create(10);
        enqueue(q, 6.5);
        enqueue(q, 1.3);
        enqueue(q, 2.4);
        printf("%f\n", dequeue(q));
        printf("%f\n", dequeue(q));
        printf("%f\n", dequeue(q));
        destroy(q);
        return 0;
    }

Nota que debemos incluir queue.h para poder utilizar las funciones y el nuevo
tipo de dato ``queue_t``. Observa que la función ``create(10)`` nos permite
crear un cola (un objeto) de 10 enteros en el heap. La dirección de la cola la almacenamos
en la variable ``q`` que estará en el stack.

Si analizas un poco más el archivo ``queue.c`` varás que ``create`` reserva el espacio
en heap para el objeto y adicionalmente inicializa sus atributos:

.. code-block:: c 

    static void init(queue_t* this, int size) {
        this->front = 0;
        this->rear = 0;
        this->arr = (double*)malloc(size * sizeof(double));
    }

    queue_t* create(int size){
        queue_t* q = malloc(sizeof(queue_t));
        init(q,size);
        return(q);
    }

Ejercicio 9: comparación con C#
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora compara el programa anterior con una implementación en C#:

.. code-block:: csharp

    using System;

    public class Queue{
        
        private int front;
        private int rear;
        private double[] arr;
        
        public Queue(int size){
            
            front = 0;
            rear = 0;
            arr = new double[size];
        }    
        
        public int size(){
            return (rear - front);
        }
        
        public void enqueue(double item) {
            arr[rear] = item;
            rear++;
        }
        
        public double dequeue() {
            double item = arr[front];
            front++;
            return item;
        }
    }

    class Program {
        static void Main() {
            Queue q = new Queue(10);
            q.enqueue(6.5);
            q.enqueue(1.3);
            q.enqueue(2.4);
            Console.WriteLine(q.dequeue());
            Console.WriteLine(q.dequeue());
            Console.WriteLine(q.dequeue());
        }
    }

Mira los atributos:

En C:

.. code-block:: c 

    #ifndef _QUEUE_H
    #define _QUEUE_H

    typedef struct {
        int front;
        int rear;
        double* arr;
    } queue_t;

En C#:

.. code-block:: csharp

    using System;

    public class Queue{
        
        private int front;
        private int rear;
        private double[] arr;

Mira cómo se crea el objeto y se llaman los métodos:

En C:

.. code-block:: c

    queue_t* q = create(10);
    enqueue(q, 6.5);

.. code-block:: csharp

Queue q = new Queue(10);
q.enqueue(6.5);

En la comparación anterior, notas que la implementación en C# no tiene
código para ``destroy``. ¿Recuerdas por qué es esto?

El programa en C# también podríamos escribirlo así:

.. code-block:: csharp

    using System;

    public class Queue{
        
        private int front;
        private int rear;
        private double[] arr;
        
        public Queue(int size){
            
            this.front = 0;
            this.rear = 0;
            this.arr = new double[size];
        }    
        
        public int size(){
            return (this.rear - this.front);
        }
        
        public void enqueue(double item) {
            this.arr[rear] = item;
            this.rear++;
        }
        
        public double dequeue() {
            double item = this.arr[front];
            this.front++;
            return item;
        }
    }
    
    
    class Program {
        
        static void Main() {
            Queue q = new Queue(10);
            q.enqueue(6.5);
            q.enqueue(1.3);
            q.enqueue(2.4);
            Console.WriteLine(q.dequeue());
            Console.WriteLine(q.dequeue());
            Console.WriteLine(q.dequeue());
        }
    }

Nota qué cambió con respecto a la primera implementación que te mostré.
¿Lo notaste? En esta segunda implementación estoy utilizando la palabra
reservada ``this``. Esta variable contiene la dirección en memoria del
objecto a través del cual llamamos el método. Observa de nuevo el código
en C. Notas ¿Cómo están relacionados los conceptos?


Ejercicio 10: relación de composición entre objetos
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Cuando DISEÑAS un programa orientado a objetos
también debes considerar las relaciones entre esos objetos. Pues bien, en general
hay dos tipos:

* Relaciones TO-HAVE o HAS-TO (TIENE UN)

* Relaciones TO-BE o IS-A (ES UN) (¿recuerdas la herencia?)

Vamos a concentrarnos primero en las TO-HAVE: la composición y la agregación.

¿Qué es una relación de composición? 

Dos objetos tienen una relación de composición cuando uno de ellos contiene a
otro objeto. Debes tener en cuenta que en una relación de composición la VIDA del objeto
contenido depende de la vida del objeto contenedor, es decir, 
si el objeto contenedor muere, el objeto contenido también. Cuando el objeto
contenedor se va destruir, primero tendrá que hacerse con el objeto contenido.

Mira de nuevo este código:

.. code-block:: c 

    #include "queue.h"
    #include <stdlib.h> 

    static void init(queue_t* this, int size) {
        this->front = 0;
        this->rear = 0;
        this->arr = (double*)malloc(size * sizeof(double));
    }

    queue_t* create(int size){
        queue_t* q = malloc(sizeof(queue_t));
        init(q,size);
        return(q);
    }


Observa la función ``create``. Dicha función crear una ``queue``.
¿Qué datos componen la cola?

.. code-block:: c 

    typedef struct {
        int front;
        int rear;
        double* arr;
    } queue_t;

    #endif

A su vez se en ``init`` estamos creando un nuevo objeto que no es más
que un arreglo de ``size`` ``doubles``. La relación entre estos dos objetos
es de composición.  

Ahora nota que al momento de destruir el objeto contenedor, primero se
destruye el objeto contenido:

.. code-block:: c 

    void destroy(queue_t* this){
        free(this->arr);
        free(this);
    }

Ejercicio 11: relación de agregación
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Qué es la agregación?

En esta relación tenemos también un objeto contenedor y un objeto contenido, la
gran diferencia con la composición es que la vida del objeto contenido no depende
de la vida del objeto contenedor. El objeto contenido puede ser construido incluso
antes de que el objeto contenedor sea construido.

Ejercicio 12: MINI-RETO
^^^^^^^^^^^^^^^^^^^^^^^^^

Con todo lo anterior en mente y esta nueva definición, te tengo un mini RETO:

Implementa un programa en C modelado con objetos que implemente una relación de
agregación para esta situación: " ...el jugador recoge un arma, la usa varias veces 
y luego la tira..."

.. note::
    ¡Alerta de Spoiler!

    Una posible implementación a este mini-reto la puedes ver en el siguiente código
    tomado de `este <https://www.packtpub.com/free-ebook/extreme-c/9781789343625>`__ 
    . Le hice unas pequeñas modificaciones al código para que puedas ver el resultado
    en la terminal.

gun.h:

.. code-block:: c 

    #ifndef GUN_H_
    #define GUN_H_

    typedef struct
    {
        int bullets;
    } gun_t;

    gun_t *gun_new();
    void gun_ctor(gun_t *, int);
    void gun_dtor(gun_t *);

    int gun_has_bullets(gun_t *);
    void gun_trigger(gun_t *);
    void gun_refill(gun_t *);

    #endif /* GUN_H_ */


gun.c:

.. code-block:: c 

    #include <stdlib.h>
    #include <stdio.h>
    #include "gun.h"

    gun_t *gun_new()
    {
        return (gun_t *)malloc(sizeof(gun_t));
    }

    void gun_ctor(gun_t *this, int initial_bullets)
    {
        this->bullets = 0;
        if (initial_bullets > 0)
        {
            this->bullets = initial_bullets;
        }
    }

    void gun_dtor(gun_t *this)
    {

    }

    int gun_has_bullets(gun_t *this)
    {
        return (this->bullets > 0);
    }

    void gun_trigger(gun_t *this)
    {
        this->bullets--;
        printf("gun triggered\n");
    }

    void gun_refill(gun_t *this)
    {
        this->bullets = 7;
    }

    
player.h:

.. code-block:: c 

    #ifndef PLAYER_H_
    #define PLAYER_H_

    #include "gun.h"

    typedef struct
    {
        char *name;
        gun_t *gun;
    } player_t;

    player_t *player_new();
    void player_ctor(player_t *, const char *);
    void player_dtor(player_t *);

    void player_pickup_gun(player_t *, gun_t *);
    void player_shoot(player_t *);
    void player_drop_gun(player_t *);

    #endif /* PLAYER_H_ */


player.c:

.. code-block:: c 

    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
    #include "gun.h"
    #include "player.h"

    player_t *player_new()
    {
        return (player_t *)malloc(sizeof(player_t));
    }

    void player_ctor(player_t *this, const char *name)
    {
        this->name = (char *)malloc((strlen(name) + 1) * sizeof(char));
        strcpy(this->name, name);
        this->gun = NULL;
    }

    void player_dtor(player_t *this)
    {
        free(this->name);
    }

    void player_pickup_gun(player_t *this, gun_t *gun)
    {
        this->gun = gun;
    }

    void player_shoot(player_t *this)
    {
        if (this->gun)
        {
            gun_trigger(this->gun);
        }
        else
        {
            printf("Player wants to shoot but he doesn't have a gun!\n");
            exit(1);
        }
    }

    void player_drop_gun(player_t *this)
    {
        this->gun = NULL;
    }


main.c:

.. code-block:: c 

    #include <stdio.h>
    #include <stdlib.h>
    #include "gun.h"
    #include "player.h"

    int main(int argc, char *argv[])
    {
        gun_t *gun = gun_new();
        gun_ctor(gun, 3);

        player_t *player = player_new();
        player_ctor(player, "Billy");

        player_pickup_gun(player, gun);

        while (gun_has_bullets(gun))
        {
            player_shoot(player);
        }

        gun_refill(gun);

        while (gun_has_bullets(gun))
        {
            player_shoot(player);
        }

        player_drop_gun(player);

        player_dtor(player);
        free(player);

        gun_dtor(gun);
        free(gun);

        return 0;
    }

Para compilar:

.. code-block:: bash

    gcc -Wall -c  player.c -o player.o    
    gcc -Wall -c  gun.c -o gun.o          
    gcc -Wall -c  main.c -o main.o        
    gcc -Wall main.o player.o gun.o -o app


Ejercicio 13: representación UML de las relaciones
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Recuerdas que en tu curso de programación y diseño orientado a objetos
vistes las relaciones anteriores?

En ese curso a los dos relaciones anteriores: agregación y composición
se les denomina en general asociaciones, es decir, dos objetos pueden estar
asociados mediante una relación de agregación o composición.

Estas relaciones pueden mostrarse de manera gráfica utilizando un
lenguaje de modelado conocido como `UML <http://uml.org/>`__. Te dejo aquí
una imagen:

.. image:: ../_static/UMLasoc.png
    :alt: relaciones en UML

Ejercicio 14: ejercicio de modelado UML
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Te animas a realizar un modelo UML para nuestros los ejemplos anteriores de composición
y agregación?

Ejercicio 15: relación de herencia
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

El otro tipo de relación que podemos tener entre dos objetos es la relación TO-BE, 
mejor conocida como herencia. 

¿Cómo funciona la herencia?

En términos simples, la herencia permite añadirle a un objeto atributos de otro
objeto. 

.. code-block:: c

    typedef struct {
        char first_name[32];
        char last_name[32];
        unsigned int birth_year;
    } person_t;

    typedef struct {
        char first_name[32];
        char last_name[32];
        unsigned int birth_year;
        char student_number[16]; // Extra attribute
        unsigned int passed_credits; // Extra attribute
    } student_t;

En el ejemplo anterior (tomado del de `aquí <https://www.packtpub.com/free-ebook/extreme-c/9781789343625>`__
nota los atributos de la estructura person_t y student_t. ¿Ves alguna relación entre ellos?

student_t ``extiende`` los atributos de person_t. Por tanto, podemos decir que student_t también
ES UNA (IS-A) person_t.

Observa entonces que podemos escribir de nuevo el código anterior así:

.. code-block:: c

    typedef struct {
        char first_name[32];
        char last_name[32];
        unsigned int birth_year;
    } person_t;
    
    typedef struct {
        person_t person;
        char student_number[16]; // Extra attribute
        unsigned int passed_credits; // Extra attribute
    }student_t;personPrivate

¿Ves lo que pasó? estamos anidando una estructura en otra estructura. Por tanto student_t hereda
de person_t. Observa que un puntero a student_t estará apuntando al primer atributo que es
un person_t. ¿Lo ves? Por eso decimos que un student_t también ES UN person_t. Míralo en acción
aquí:

.. code-block:: c

    #include <stdio.h>

    typedef struct {
        char first_name[32];
        char last_name[32];
        unsigned int birth_year;
    }person_t;

    typedef struct {
        person_t person;
        char student_number[16]; // Extra attribute
        unsigned int passed_credits; // Extra attribute
    } student_t;

    int main(int argc, char* argv[]) {
        student_t s;
        student_t* s_ptr = &s;
        person_t* p_ptr = (person_t*)&s;
        printf("Student pointer points to %p\n", (void*)s_ptr);
        printf("Person pointer points to %p\n", (void*)p_ptr);
        return 0;
    }

Ejercicio 16: para reflexionar
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

En este punto te pido que te pongas cómodo. Lo que viene será alucinante...

Del ejercicio anterior concluimos que student_t está heredando de person_t.
Por tanto, a las funciones que definas para manipular un objeto de tipo
person_t también le puedes pasar un puntero a un student_t (para manipular
sus atributos correspondiente a person_t). SEÑORAS y SEÑORES, estamos
reutilizando código.

Ejercicio 17: implementación de herencia simple
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora te voy a mostrar una técnica para implementar herencia simple en C.
Analiza con detenimiento este código por favor 
(`tomado de aquí <https://www.packtpub.com/free-ebook/extreme-c/9781789343625>`__):

person.h:

.. code-block:: c

    #ifndef PERSON_H_
    #define PERSON_H_

    typedef struct {
        char first_name[32];
        char last_name[32];
        unsigned int birth_year;
    } person_t;

    person_t *person_new();
    void person_ctor( person_t *, const char *, const char *, unsigned int);
    void person_dtor(person_t *);

    void person_get_first_name(person_t *, char *);
    void person_get_last_name(person_t *, char *);
    unsigned int person_get_birth_year(person_t *);

    #endif /* PERSON_H_ */

Código para person.c:

.. code-block:: c

    #include <stdlib.h>
    #include <string.h>
    #include <stdlib.h>
    #include "person.h"

    person_t *person_new() {
        return malloc(sizeof(person_t));
    }

    void person_ctor(person_t *this,
            const char *first_name,
            const char *last_name,
            unsigned int birth_year) {

                strcpy(this->first_name, first_name);
                strcpy(this->last_name, last_name);
                this->birth_year = birth_year;
    }

    void person_dtor(person_t *this) {

    }

    void person_get_first_name(person_t *this, char *buffer) {
        strcpy(buffer, this->first_name);
    }

    void person_get_last_name(person_t *this, char *buffer) {
        strcpy(buffer, this->last_name);
    }

    unsigned int person_get_birth_year(person_t *this) {
        return this->birth_year;
    }

    void person_get_last_name(person_t *this, char *buffer) {
        strcpy(buffer, this->last_name);
    }

    unsigned int person_get_birth_year(person_t *this) {
        return this->birth_year;
    }

student.h:

.. code-block:: c

    #ifndef STUDENT_H_
    #define STUDENT_H_

    #include "person.h"

    typedef struct {
        person_t person;
        char *student_number;
        unsigned int passed_credits;
    } student_t;

    student_t *student_new();
    void student_ctor(student_t *,
                    const char * /* first name */,
                    const char * /* last name */,
                    unsigned int /* birth year */,
                    const char * /* student number */,
                    unsigned int /* passed credits */);
    void student_dtor(student_t *);

    void student_get_student_number(student_t *, char *);
    unsigned int student_get_passed_credits(student_t *);

    #endif /* STUDENT_H_ */


student.c:

.. code-block:: c

    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include "person.h"
    #include "student.h"

    student_t *student_new() {
        return (student_t *)malloc(sizeof(student_t));
    }

    void student_ctor(student_t *this,
                    const char * first_name,
                    const char * last_name,
                    unsigned int birth_year,
                    const char * student_number,
                    unsigned int passed_credits) {

        person_ctor((person_t *)this,
        first_name, last_name, birth_year);
        this->student_number = (char *)malloc(16 * sizeof(char));
        strcpy(this->student_number, student_number);
        this->passed_credits = passed_credits;
    }

    void student_dtor(student_t *this) {
        free(this->student_number);
        person_dtor((person_t *)this);
    }

    void student_get_student_number(student_t *this,
            char *buffer) {
            strcpy(buffer, this->student_number);
    }

    unsigned int student_get_passed_credits(student_t *this) {
        return this->passed_credits;
    }

main.c:

.. code-block:: c

    #include <stdio.h>
    #include <stdlib.h>
    #include "person.h"
    #include "student.h"

    int main(int argc, char* argv[]) {
        char buffer[32];

        student_t *student = student_new();
        student_ctor(student, "John", "Doe", 1987, "TA5667", 134);
        
        person_t *person_ptr = (person_t *)student;
        person_get_first_name(person_ptr, buffer);
        printf("First name: %s\n", buffer);
        person_get_last_name(person_ptr, buffer);
        printf("Last name: %s\n", buffer);
        printf("Birth year: %d\n", person_get_birth_year(person_ptr));

        student_get_student_number(student, buffer);
        printf("Student number: %s\n", buffer);
        printf("Passed credits: %d\n",
        student_get_passed_credits(student));

        student_dtor(student);
        free(student);
        return 0;
    }

Para compilar y generar la aplicación:

.. code-block:: bash

    gcc -Wall -c person.c -o person.o                             
    gcc -Wall -c student.c -o student.o                           
    gcc -Wall -c main.c -o main.o      
    gcc -Wall main.o person.o student.o -o app


Ejercicio 18: POLIMORFISMO en tiempo de ejecución
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

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
