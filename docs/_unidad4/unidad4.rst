Experiencia de aprendizaje 4. Estructuras de datos
====================================================

Introducción
--------------

En esta unidad, te adentrarás en el mundo de las estructuras de datos, un componente esencial en 
la programación creativa. Las estructuras de datos te permiten organizar, gestionar y almacenar 
datos de manera eficiente, lo que es crucial para el desarrollo de software optimizado y escalable.
Durante esta unidad, explorarás varias estructuras de datos fundamentales, incluyendo arreglos, 
listas enlazadas, pilas y colas. Lo harás a través de actividades prácticas en un entorno de 
programación creativa.

Además, de lo anterior te mostraré una novedad del lenguaje C++ acerca de la gestión de memoria que, a 
diferencia de otros lenguajes como C#, requiere que el programador gestione explícitamente 
el ciclo de vida de los objetos. Esto implica no solo la creación de objetos en memoria, sino también la 
responsabilidad de liberar esa memoria cuando los objetos ya no son necesarios, evitando así fugas de 
memoria y otros problemas relacionados con la gestión de recursos.

La unidad se divide en dos fases: la fase de investigación, donde explorarás y experimentarás con 
estas estructuras de datos en un contexto creativo; y la fase de reto, donde aplicarás lo aprendido para 
desarrollar una pieza de arte generativo dinámica que combine diferentes estructuras de datos y gestione de 
manera eficiente la memoria. Esta experiencia no solo reforzará tu comprensión de las estructuras de datos, 
sino que también te permitirá ver su aplicación en un contexto visual y creativo.

Investigación
--------------

Actividad 1: 
****************************************************************

En esta actividad vas a experimentar con una aplicación interactiva y listas enlazadas
El siguiente código código además incluye la gestión de memoria.

**ofApp.h:**

.. code-block:: cpp

    #pragma once

    #include "ofMain.h"

    class Node {
    public:
        float x, y;
        Node* next;

        Node(float _x, float _y) {
            x = _x;
            y = _y;
            next = nullptr;
        }

        ~Node() {
            // Destructor para Node (si hay recursos adicionales)
        }
    };

    class LinkedList {
    public:
        Node* head;
        Node* tail;
        int size;

        LinkedList() {
            head = new Node(ofGetWidth() / 2, ofGetHeight() / 2);
            tail = head;
            size = 1;
        }

        ~LinkedList() {
            clear();
        }

        void clear() {
            // Liberar toda la memoria de los nodos
            Node* current = head;
            while (current != nullptr) {
                Node* nextNode = current->next;
                delete current;
                current = nextNode;
            }
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        void addNode(float x, float y) {
            Node* newNode = new Node(x, y);
            if (tail != nullptr) {
                tail->next = newNode;
                tail = newNode;
            }
            else {
                // Si la lista estaba vacía, inicializa head y tail con el nuevo nodo
                head = tail = newNode;
            }
            size++;
        }

        void update(float x, float y) {
            Node* current = head;
            float prevX = x;
            float prevY = y;

            while (current != nullptr) {
                float tempX = current->x;
                float tempY = current->y;
                current->x = prevX;
                current->y = prevY;
                prevX = tempX;
                prevY = tempY;
                current = current->next;
            }
        }

        void display() {
            Node* current = head;
            while (current != nullptr) {
                ofDrawCircle(current->x, current->y, 10);
                current = current->next;
            }
        }
    };

    class ofApp : public ofBaseApp {

    public:
        LinkedList snake;

        void setup();
        void update();
        void draw();
        void keyPressed(int key);  // Nueva función para manejar el teclado
    };



**ofApp.cpp:**

.. code-block:: cpp

    #include "ofApp.h"

    //--------------------------------------------------------------
    void ofApp::setup() {
        // Añadir nodos a la serpiente
        for (int i = 0; i < 10; i++) {
            snake.addNode(ofGetWidth() / 2, ofGetHeight() / 2);
        }
    }

    //--------------------------------------------------------------
    void ofApp::update() {
        // Actualizar la posición de la serpiente
        snake.update(ofGetMouseX(), ofGetMouseY());
    }

    //--------------------------------------------------------------
    void ofApp::draw() {
        ofBackground(220);
        // Dibujar la serpiente
        snake.display();
    }

    //--------------------------------------------------------------
    void ofApp::keyPressed(int key) {
        if (key == 'c') {
            snake.clear();  // Limpiar explícitamente la lista cuando se presiona la tecla 'c'
        }
    }

Gestión de memoria: se maneja explícitamente la liberación de memoria mediante la función ``clear()``. 
Nota que también se llama a clear en el destructor de la clase LinkedList para asegurar que la memoria 
se libere cuando el objeto se destruye. 

Vas a reportar en tu bitácora de aprendizaje:

1. **Entiende la aplicación**: comienza explorando detenidamente cómo funciona el programa. Usa un 
   un modelo del lenguaje como ChatGPT y el depurador para que verifiques las explicaciones que te 
   propone ChatGPT. Puedes escribir el prompt: quiere entender de manera muy detallada el siguiente 
   programa escrito en C++ y el openframeworks. Luego le das el código. Ve preguntando lo que no entiendas. 
   recuerda ir usando al mismo tiempo el depurador de visual studio.
2. **Realiza evaluaciones formativas**. Dile a ChatGPT que te genere preguntas para verificar si entiendes 
   cómo funciona el programa. Trata de verificar tus hipótesis usando el depurador y luego con las 
   conclusiones del experimento responde la pregunta de ChatGPT. Continúa con este proceso hasta que 
   estés seguro de que entiendes cómo funciona el programa.
3. ¿Qué es una lista enlazada y en qué se diferencia de un arreglo en cuanto a la forma en que los 
   elementos están almacenados en la memoria?
4. Al observar el código de una lista enlazada en C++, ¿Cómo crees que se vinculan los nodos 
   entre sí? ¿Qué estructura se utiliza para lograr esta conexión?
5. ¿Cómo se gestiona la memoria en una lista enlazada? Investiga cómo se crea y se destruye un nodo 
   en memoria utilizando el operador `new` y `delete` en C++.
6. Considerando la estructura de una lista enlazada, ¿qué ventajas ofrece en comparación con un arreglo 
   cuando se trata de insertar o eliminar elementos en posiciones intermedias?
7. En el código presentado, ¿Cómo se asegura que no haya fugas de memoria? ¿Qué papel juega el destructor 
   en la clase `LinkedList`?
8. ¿Qué sucede en la memoria cuando se invoca el método `clear()` en una lista enlazada? Explica paso a 
   paso cómo se liberan los recursos.
9. Explica cómo cambia la estructura en memoria de una lista enlazada al agregar un nuevo nodo al final de 
   la lista. ¿Cómo afecta esto al rendimiento de la lista enlazada?
10. Analiza una situación en la que utilizar una lista enlazada sería más ventajoso que 
    utilizar un arreglo. Justifica tu respuesta considerando la gestión de memoria y las operaciones 
    de inserción y eliminación.
11. Después de estudiar el manejo de memoria en listas enlazadas, ¿Cómo aplicarías este conocimiento 
    para diseñar una estructura de datos personalizada para una aplicación creativa? ¿Qué aspectos 
    considerarías para asegurar la eficiencia y evitar fugas de memoria?
12. Reflexiona sobre las diferencias en la gestión de memoria entre C++ y un lenguaje con recolección 
    de basura automática como C#. ¿Qué ventajas y desafíos encuentras en la gestión explícita de memoria 
    en C++ al trabajar con estructuras de datos?
13. Imagina que estás optimizando una pieza de arte generativo que usa listas enlazadas para representar 
    elementos en movimiento. ¿Qué consideraciones tomarías en cuenta para garantizar que la gestión de 
    la memoria sea eficiente y que no ocurran fugas de memoria?
14. **Pruebas:** pregunta a ChatGPT cómo podrías probar las partes del programa y el programa completo. 
    Luego realiza las pruebas y verifica si los resultados coinciden con tus expectativas. 

Actividad 2: 
***********************************************

En esta actividad vas a experimentar con pilas y colas en un contexto de arte generativo. El 
código incluye la gestión de memoria.

**ofApp.h:**

.. code-block:: cpp

    #pragma once

    #include "ofMain.h"

    class Node {
    public:
        ofVec2f position;
        Node* next;

        Node(float x, float y) {
            position.set(x, y);
            next = nullptr;
        }
    };

    class Stack {
    public:
        Node* top;
        
        Stack() {
            top = nullptr;
        }

        ~Stack() {
            clear();
        }

        void push(float x, float y) {
            Node* newNode = new Node(x, y);
            newNode->next = top;
            top = newNode;
        }

        void pop() {
            if (top != nullptr) {
                Node* temp = top;
                top = top->next;
                delete temp;  // Liberar memoria del nodo eliminado
            }
        }

        void clear() {
            while (top != nullptr) {
                pop();
            }
        }

        void display() {
            Node* current = top;
            while (current != nullptr) {
                ofDrawCircle(current->position.x, current->position.y, 20);
                current = current->next;
            }
        }
    };

    class ofApp : public ofBaseApp {

    public:
        Stack circleStack;

        void setup();
        void update();
        void draw();
        void keyPressed(int key);
    };


**ofApp.cpp:**

.. code-block:: cpp

    #include "ofApp.h"

    //--------------------------------------------------------------
    void ofApp::setup() {
        ofSetBackgroundColor(220);
    }

    //--------------------------------------------------------------
    void ofApp::update() {

    }

    //--------------------------------------------------------------
    void ofApp::draw() {
        // Dibujar todos los círculos en la pila
        circleStack.display();
    }

    //--------------------------------------------------------------
    void ofApp::keyPressed(int key) {
        if (key == 'a') { // Apilar un nuevo círculo
            circleStack.push(ofGetMouseX(), ofGetMouseY());
        }
        else if (key == 'd') { // Desapilar el último círculo
            circleStack.pop();
        }
    }

**ofApp.h:**

.. code-block:: cpp

    #pragma once

    #include "ofMain.h"

    class Node {
    public:
        ofVec2f position;
        Node* next;

        Node(float x, float y) {
            position.set(x, y);
            next = nullptr;
        }
    };

    class Queue {
    public:
        Node* front;
        Node* rear;

        Queue() {
            front = rear = nullptr;
        }

        ~Queue() {
            clear();
        }

        void enqueue(float x, float y) {
            Node* newNode = new Node(x, y);
            if (rear == nullptr) {
                front = rear = newNode;
            }
            else {
                rear->next = newNode;
                rear = newNode;
            }
        }

        void dequeue() {
            if (front != nullptr) {
                Node* temp = front;
                front = front->next;
                if (front == nullptr) {
                    rear = nullptr;
                }
                delete temp;  // Liberar memoria del nodo eliminado
            }
        }

        void clear() {
            while (front != nullptr) {
                dequeue();
            }
        }

        void display() {
            Node* current = front;
            while (current != nullptr) {
                ofDrawCircle(current->position.x, current->position.y, 20);
                current = current->next;
            }
        }
    };

    class ofApp : public ofBaseApp {

    public:
        Queue circleQueue;

        void setup();
        void update();
        void draw();
        void keyPressed(int key);
    };



**ofApp.cpp:**
   
.. code-block:: cpp

    #include "ofApp.h"

    //--------------------------------------------------------------
    void ofApp::setup() {
        ofSetBackgroundColor(220);
    }

    //--------------------------------------------------------------
    void ofApp::update() {

    }

    //--------------------------------------------------------------
    void ofApp::draw() {
        // Dibujar todos los círculos en la cola
        circleQueue.display();
    }

    //--------------------------------------------------------------
    void ofApp::keyPressed(int key) {
        if (key == 'a') { // Encolar un nuevo círculo
            circleQueue.enqueue(ofGetMouseX(), ofGetMouseY());
        }
        else if (key == 'd') { // Desencolar el primer círculo
            circleQueue.dequeue();
        }
    }

Gestión de memoria: se maneja explícitamente la liberación de memoria mediante las funciones `clear()`. 
Nota que también se llama a `clear()` en el destructor de las clases `Stack` y `Queue` para asegurar que 
la memoria se libere cuando los objetos se destruyen.

Vas a reportar en tu bitácora de aprendizaje:


1. **Entendiendo la aplicación**: comienza explorando detenidamente cómo funciona el programa. Usa un 
   un modelo del lenguaje como ChatGPT y el depurador para que verifiques las explicaciones que te 
   propone ChatGPT. Puedes escribir el prompt: quiere entender de manera muy detallada el siguiente 
   programa escrito en C++ y el openframeworks. Luego le das el código. Ve preguntando lo que no entiendas. 
   recuerda ir usando al mismo tiempo el depurador de visual studio.
2. **Realiza evaluaciones formativas**. Dile a ChatGPT que te genere preguntas para verificar si entiendes 
   cómo funciona el programa. Trata de verificar tus hipótesis usando el depurador y luego con las 
   conclusiones del experimento responde la pregunta de ChatGPT. Continúa con este proceso hasta que 
   estés seguro de que entiendes cómo funciona el programa. 
3. **Pruebas:** pregunta a ChatGPT cómo podrías probar las partes del programa y el programa completo. 
   Luego realiza las pruebas y verifica si los resultados coinciden con tus expectativas.

Preguntas de reflexión para el stack:

1. ¿Cómo se gestiona la memoria en una implementación manual de un stack en C++? Reflexiona sobre 
   cómo el uso de `new` y `delete` en la creación y destrucción de nodos afecta el rendimiento y la 
   seguridad de tu programa.
2. ¿Por qué es importante liberar la memoria cuando se desapila un nodo en un stack? Considera las 
   consecuencias de no liberar memoria en términos de fugas de memoria y cómo esto puede 
   impactar aplicaciones de largo tiempo de ejecución.
3. ¿Qué diferencias existen entre usar un stack de la STL (`std::stack`) y crear un stack manualmente? 
   Explora cómo la abstracción que proporciona la STL puede simplificar la implementación, pero también 
   cómo una implementación manual ofrece mayor control sobre la gestión de recursos.
4. ¿Cómo afecta la estructura de un stack al orden de acceso y eliminación de elementos? 
   Analiza cómo la naturaleza LIFO (Last In, First Out) del stack influye en los tipos de problemas que esta 
   estructura de datos puede resolver eficientemente.
5. ¿Cómo podrías modificar el stack para almacenar tipos de datos más complejos (e.g., objetos con múltiples 
   atributos) sin causar problemas de memoria?
   Reflexiona sobre cómo gestionar adecuadamente la memoria para objetos más complejos y cómo esto afectaría 
   tu implementación actual.

Preguntas de autoevaluación:

1. ¿Puedo explicar detalladamente cómo funciona el proceso de apilar y desapilar nodos en un stack, 
   incluyendo la gestión de memoria?
2. ¿Soy capaz de identificar y corregir una fuga de memoria en una implementación de stack manual?
3. ¿Puedo modificar el stack para que incluya una función que busque un elemento específico, sin alterar 
   el orden de los elementos apilados?
4. ¿Entiendo cómo la estructura LIFO del stack afecta el flujo de datos y puedo dar ejemplos de 
   problemas que se resuelvan mejor con un stack?
5. ¿Puedo implementar y depurar un stack para tipos de datos más complejos, asegurándome de que no haya 
   fugas de memoria ni errores de puntero?

Preguntas de reflexión para la queue:

1. ¿Cómo se maneja la memoria en una implementación manual de una queue en C++? Reflexiona sobre cómo 
   se gestionan los nodos al encolar y desencolar elementos y las implicaciones en 
   términos de eficiencia y seguridad.
2. ¿Qué desafíos específicos presenta la implementación de una queue en comparación con un stack en términos 
   de gestión de memoria? 
   Considera las diferencias en el manejo de punteros `front` y `rear`, y cómo estos afectan el proceso de 
   encolado y desencolado.
3. ¿Cómo afecta la estructura FIFO (First In, First Out) de una queue a su uso en diferentes tipos de problemas?
   Analiza cómo la estructura FIFO influye en la resolución de problemas donde el orden de procesamiento es 
   crucial, como en sistemas de colas de espera.
4. ¿Cómo podrías implementar una queue circular y cuál sería su ventaja respecto a una queue lineal en términos 
   de uso de memoria?
   Reflexiona sobre cómo una queue circular puede mejorar la eficiencia en ciertos contextos y qué 
   cambios serían necesarios en la implementación.
5. ¿Qué problemas podrían surgir si no se gestionan correctamente los punteros `front` y `rear` en una queue, y 
   cómo podrías evitarlos?
   Considera posibles errores como la pérdida de referencias a nodos y cómo una gestión cuidadosa de los punteros 
   puede prevenir estos problemas.

Preguntas de autoevaluación:

1. ¿Puedo explicar claramente el proceso de encolar y desencolar nodos en una queue, incluyendo la 
   gestión de memoria?
2. ¿Soy capaz de identificar y corregir problemas relacionados con la gestión de los punteros `front` y `rear` en una queue?
3. ¿Puedo modificar la queue para implementar una queue circular, entendiendo cómo esto afectaría la gestión de memoria?
4. ¿Entiendo cómo la estructura FIFO de una queue afecta el flujo de datos y puedo dar ejemplos de problemas que 
   se resuelvan mejor con una queue?
5. ¿Puedo implementar y depurar una queue para tipos de datos más complejos, asegurándome de que no haya fugas 
   de memoria ni errores de puntero?

Reto
------

Crea una obra de arte generativo dinámica (con gestión de memoria). Utilizando los conceptos de arreglos, 
listas enlazadas, pilas y colas, crea una obra de arte generativo dinámica. Asegúrate de gestionar el 
ciclo de vida de todos los objetos creados dinámicamente.

Requisitos
************

1. **Combinación de estructuras de datos:** usa al menos un arreglo o lista enlazada y una pila o cola para 
   gestionar diferentes aspectos de tu obra (por ejemplo, la posición y color de los elementos, la velocidad de 
   movimiento, etc.).
2. **Interactividad:** implementa al menos una forma de interacción con el usuario, que cambie la visualización 
   o el comportamiento de la obra.
3. **Gestión de memoria:** asegúrate de liberar la memoria de todos los objetos creados dinámicamente.

Preguntas para guiar el proceso
**********************************

1. **Exploración creativa:** ¿Qué tipo de efecto visual quieres lograr? ¿Cómo pueden ayudarte las diferentes
   estructuras de datos a lograr ese efecto?
2. **Gestión de memoria:** ¿Qué consideraciones debes tener en cuenta al gestionar dinámicamente la memoria 
   de los objetos? ¿Cómo asegurar que no haya fugas de memoria?
3. **Interacción y dinamismo:** ¿Cómo puedes hacer que la interacción del usuario influya en múltiples 
   estructuras de datos simultáneamente para crear un efecto visual coherente y dinámico?
4. **Optimización:** ¿Qué técnicas puedes implementar para optimizar la gestión de memoria y el rendimiento de 
   tu aplicación mientras mantienes una experiencia visual rica y fluida?

Ejemplo de idea:
    **"Lluvia de colores:"** crea una simulación de gotas de lluvia de colores que caen desde la parte superior 
    de la pantalla. Usa un arreglo para almacenar las posiciones iniciales de las gotas y una pila para apilar 
    nuevas gotas a medida que se generan. Al liberar las gotas que han caído fuera de la pantalla, asegúrate 
    de gestionar y liberar correctamente la memoria.

Evidencia de los resultados de aprendizaje 
********************************************

.. warning:: MUY IMPORTANTE 

    ¿Recuerdas los resultados de aprendizaje específicos (RAE) de este curso?

    * RAE1: construyo aplicaciones interactivas aplicando patrones y estrategias que 
      permitan alcanzar los requisitos funcionales y no funcionales establecidos. Se espera que 
      llegues a un nivel resolutivo.
    * RAE2: aplico pruebas de las partes y del todo de un software siguiendo metodologías, 
      técnicas y estándares de la industria para garantizar el correcto funcionamiento de las 
      aplicaciones. Se espera que llegues a un nivel autónomo.

* El RAE1 lo evidenciarás con la construcción de las aplicaciones que proponen los retos, 
  siguiendo los requisitos. Incluye en tu bitácora capturas de pantalla donde muestres en 
  funcionamiento tu obra de arte generativo. Cada captura debe mostrar un aspecto diferente 
  que capture los requisitos del reto.
* El RAE2 lo evidenciarás explicando cómo probaste cada requisito de manera independiente 
  y cómo probaste el programa completo. Además de las explicaciones, es importante que 
  incluyas capturas de pantalla donde muestras las pruebas realizadas.