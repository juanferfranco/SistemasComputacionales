Experiencia de aprendizaje 5. Programación orientada a objetos
====================================================================

Introducción
--------------

¡Bienvenido a esta nueva aventura en la programación orientada a objetos (OOP)! 
En esta unidad, vamos a hacer un viaje fascinante hacia el interior de los conceptos más 
fundamentales de OOP en C++. Pero esta vez, no solo vamos a usar estos conceptos; vamos a 
desentrañar sus secretos y ver cómo funcionan realmente bajo el capó.

¿Qué exploraremos?

1. ¿Qué es realmente un objeto? Todos sabemos que los objetos son una parte central de OOP, 
   pero ¿Alguna vez te has preguntado qué son realmente? Vamos a crear y analizar objetos, explorando 
   cómo se representan en la memoria del computador. Imagina que estamos abriendo un objeto y 
   mirando dentro para ver cómo está hecho. ¡Es como desarmar un reloj para entender cómo funciona!

2. ¿Dónde viven los datos y los métodos de una clase? Los objetos tienen datos y métodos, 
   pero ¿dónde se guardan estos cuando ejecutamos un programa? Vamos a usar herramientas como el 
   depurador para observar en detalle cómo se organizan estos datos y métodos en la memoria.
   Descubriremos cómo el computador sabe a dónde ir cuando llamas a un método o accedes a un atributo.

3. Encapsulamiento, herencia y polimorfismo: ¿Qué hay bajo el capó? Seguro has oído hablar de estos 
   conceptos antes, pero ¿Sabes realmente cómo se implementan? Vamos a investigar cómo el compilador 
   convierte estas abstracciones en código ejecutable. Será como mirar el motor de un carro y entender 
   cómo cada pieza contribuye a que funcione.

¿Cómo lo haremos?

Sesiones de investigación: durante las primeras tres sesiones (2 en el aula y otra por fuera), 
realizaremos experimentos y casos de estudio que nos ayudarán a explorar y entender estos 
conceptos desde dentro.

* Experimentaremos con objetos, observando cómo cambian cuando añadimos más datos o métodos.
* Usaremos herramientas para explorar la memoria, entendiendo cómo se organizan los datos y métodos.
* Desentrañaremos el encapsulamiento, herencia y polimorfismo, y veremos cómo el computador los ejecuta.
  
Sesiones de aplicación: en las últimas tres sesiones, aplicarás todo lo que has aprendido creando una 
pieza de arte generativo con openframeworks y C++. Aquí, cada decisión de diseño que tomes estará informada 
por tu comprensión profunda de cómo funcionan las cosas a nivel interno. Además, documentarás este proceso 
en una bitácora, reflexionando sobre cómo tus conocimientos sobre el funcionamiento interno de OOP te 
ayudan a crear algo único.

¿Y si necesitas ayuda?

No te preocupes si al principio algunos conceptos parecen complejos. Estaremos usando una combinación de 
exploración práctica y recursos adicionales, como ChatGPT, para ayudarte a reflexionar y entender cada concepto 
en profundidad. La idea es que aprendas a tu propio ritmo y descubras por ti mismo cómo la programación 
orientada a objetos es más que un conjunto de reglas; es una forma de pensar y estructurar soluciones de 
manera eficiente y creativa.

Así que prepárate para un viaje lleno de descubrimientos y revelaciones. ¡Vamos a desarmar y entender 
juntos el increíble mundo de la programación orientada a objetos!


Investigación 
---------------

En las próximas tres sesiones, nos convertiremos en exploradores del mundo interno de la programación 
orientada a objetos. Vamos a investigar y experimentar con los conceptos clave de OOP, como si estuviéramos 
desarmando un mecanismo para entender cómo funciona. Desde la representación de los objetos en la memoria 
hasta la implementación del encapsulamiento, herencia y polimorfismo, descubriremos lo que realmente sucede 
bajo el capó.


Estructura General
********************

* Duración: 6 sesiones de 1 hora y 40 minutos cada una.
* Fases:

  * Fase de Investigación (Sesiones 1-3): exploración detallada de los fundamentos y las abstracciones de 
    OOP, centrándose en cómo funcionan internamente.
  * Fase de Aplicación (Sesiones 4-6): implementación de un proyecto de arte generativo y documentación 
    profunda del proceso, con énfasis en la reflexión individual sobre las abstracciones.

Sesión 1: la naturaleza de los objetos en C++
***********************************************

Objetivo: profundizar en el concepto de "objeto" en C++, explorando su representación en memoria y la 
diferencia entre objetos y clases.

Introducción a los Objetos
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Concepto: un objeto es una instancia de una clase que combina datos (atributos) y comportamiento (métodos).

Considera el siguiente caso de estudio: 

.. code-block:: cpp

    class Particle {
    public:
        float x, y;
        void move(float dx, float dy) {
            x += dx;
            y += dy;
        }
    };
    
* ¿Qué representa la clase Particle?
* ¿Cómo interactúan sus atributos y métodos?
* Prompt para ChatGPT: explícame en detalle qué es un objeto en C++ y cómo se relaciona con una clase. 
  Usa el ejemplo de una clase Particle con atributos x y y y un método move.

.. warning:: MUY IMPORTANTE

    Recuerda que ChatGPT puede proporcionar información inexacta. Verifica sus respuestas implementando y 
    experimentando con el código en tu entorno de desarrollo.

Explorando la memoria
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Objetivo: entender cómo se almacenan los objetos en memoria.

Considera los siguientes pasos:

1. Crear instancias:

.. code-block:: cpp

    Particle p1;
    Particle p2;

2. Explorar la memoria usando punteros:

.. code-block:: cpp

    std::cout << "Dirección de p1: " << &p1 << std::endl;
    std::cout << "Dirección de p2: " << &p2 << std::endl;

3. Determinar el tamaño del objeto:

.. code-block:: cpp

    std::cout << "Tamaño de Particle: " << sizeof(Particle) << " bytes" << std::endl;

4. Imprimir direcciones de atributos:

.. code-block:: cpp

    std::cout << "Dirección de p1.x: " << &(p1.x) << std::endl;
    std::cout << "Dirección de p1.y: " << &(p1.y) << std::endl;

Reflexión Guiada:

* ¿Los atributos están almacenados de forma contigua?
* ¿Qué indica el tamaño del objeto sobre su estructura interna?
* Prompt para ChatGPT: ¿Cómo se almacenan los objetos en memoria en C++? Si tengo dos instancias de Particle, 
  ¿Cómo se relacionan sus direcciones de memoria? ¿Los atributos están contiguos?

.. warning:: MUY IMPORTANTE

    Verifica las respuestas de ChatGPT mediante experimentación práctica.

Análisis de diferencias
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Objetivo: comparar cómo diferentes clases afectan el uso de memoria.

Considera los siguientes pasos: 

1. Crear clases con diferentes atributos y métodos:

.. code-block:: cpp

    class Simple {
    public:
        int a;
    };

    class Complex {
    public:
        int a, b, c;
        void method1() {}
        void method2() {}
    };

2. Compara los tamaños:

.. code-block:: cpp

    std::cout << "Tamaño de Simple: " << sizeof(Simple) << " bytes" << std::endl;
    std::cout << "Tamaño de Complex: " << sizeof(Complex) << " bytes" << std::endl;

3. Agregar datos estáticos y dinámicos:

.. code-block:: cpp

    class StaticData {
    public:
        static int s;
        int a;
    };

    int StaticData::s = 0;

    class DynamicData {
    public:
        int* ptr;
        DynamicData() {
            ptr = new int[10];
        }
        ~DynamicData() {
            delete[] ptr;
        }
    };

* ¿Cómo afectan los datos estáticos al tamaño de la instancia?
* ¿Qué diferencias hay entre datos estáticos y dinámicos en términos de memoria?
* Prompt para ChatGPT: explícame cómo el uso de variables estáticas y dinámicas en una clase 
  afecta el tamaño de sus instancias. ¿Las variables estáticas ocupan espacio en cada objeto?

.. warning:: MUY IMPORTANTE

    Implementa ejemplos y comprueba si las respuestas de ChatGPT coinciden con tus resultados.

Reflexión
^^^^^^^^^^^^

Documenta en tu bitácora de aprendizaje:

* ¿Qué es un objeto desde la perspectiva de la memoria?
* ¿Cómo influyen los atributos y métodos en el tamaño y estructura del objeto?
* Conclusión: resumir los hallazgos y cómo esto impacta el diseño de clases.

Sesión 2: ubicación en memoria de datos y métodos
****************************************************

Objetivo: explorar cómo y dónde se almacenan los datos y métodos de una clase en la memoria del computador.


Análisis de la estructura de una clase
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^	

* Datos: los atributos se almacenan en el stack o heap, según cómo se instancien.
* Métodos: el código de los métodos reside en la sección de código (texto) del programa.
* Vtables: estructuras usadas para implementar métodos virtuales.

Prompt para ChatGPT: ¿Dónde se almacenan los datos y métodos de una clase en C++ en la memoria? Explica el concepto de 
vtable y cómo se relaciona con los métodos virtuales.

.. warning:: MUY IMPORTANTE

    Verifica las explicaciones de ChatGPT realizando tus propios experimentos.

Exploración de métodos virtuales
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^	

Objetivo: comprender el impacto de los métodos virtuales en la memoria y el rendimiento.

Considera los siguientes pasos:

1. Crea una jerarquía de clases con métodos virtuales:

.. code-block:: cpp

    class Base {
    public:
        virtual void display() {
            std::cout << "Base display" << std::endl;
        }
    };

    class Derived : public Base {
    public:
        void display() override {
            std::cout << "Derived display" << std::endl;
        }
    };

2. Analiza la vtables. ¿En qué parte de la memoria se encuentran las 
   vtable de cada objeto? 

.. code-block:: cpp

    Base b;
    Derived d;
    std::cout << "Vtable de Base: " << *(void**)&b << std::endl;
    std::cout << "Vtable de Derived: " << *(void**)&d << std::endl;

3. Usar un depurador: observar cómo se resuelven las llamadas a métodos virtuales en tiempo de ejecución. Puedes 
   usar para ello varias herramientas del depurador. En el menú Debug de Visual Studio, selecciona Windows y luego 
   Memory. Allí podrás explorar la memoria. Si das click derecho sobre una función del código puedes ver 
   el programa en ensamblador con Go to Dissasembly.

* ¿Cómo afecta la presencia de métodos virtuales al tamaño del objeto?
* ¿Qué papel juegan las vtables en el polimorfismo?
* Prompt para ChatGPT: ¿Cómo se implementan los métodos virtuales en C++? Explica el concepto de vtable y cómo se 
  utiliza para resolver llamadas a métodos virtuales.

.. warning:: MUY IMPORTANTE

    Confirma las respuestas de ChatGPT experimentando con código y depuradores.

Uso de punteros y referencias
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Objetivo: explorar cómo los punteros y referencias afectan la gestión de la memoria y la llamada a métodos.

Considera estos pasos:

1. Implementar una clase con punteros a funciones:

.. code-block:: cpp 

    class FunctionPointerExample {
    public:
        void (*funcPtr)();
        static void staticFunction() {
            std::cout << "Static function called" << std::endl;
        }
        void assignFunction() {
            funcPtr = staticFunction;
        }
    };

2. Analizar el impacto en memoria:

* Observar si el tamaño de la instancia cambia al usar punteros a funciones.
* Verificar cómo se almacenan estos punteros.

3. Reflexión Guiada:

* ¿Cuál es la relación entre los punteros a métodos y la vtable?
* ¿Cómo afectan estos mecanismos al rendimiento del programa?
* Prompt para ChatGPT: ¿Qué diferencia hay entre punteros a funciones y punteros a métodos miembro en C++? 
  ¿Cómo afectan al tamaño de los objetos y al rendimiento?

.. warning:: MUY IMPORTANTE

    Realiza pruebas prácticas para validar las respuestas.

4. Reflexión individual:

* ¿Dónde residen los datos y métodos de una clase en la memoria?
* ¿Cómo interactúan las diferentes partes en tiempo de ejecución?
* Conclusión: cómo esta comprensión afecta el diseño de sistemas.

Sesión 3: implementación Interna de Encapsulamiento, Herencia y Polimorfismo
******************************************************************************

Objetivo: entender cómo se implementan las abstracciones del encapsulamiento, herencia y polimorfismo a nivel interno.

Profundizando en el encapsulamiento
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Modificadores de acceso: private, protected, public.
Control de acceso: implementado por el compilador, no por restricciones en tiempo de ejecución.

Crear una clase con diferentes niveles de acceso:

.. code-block:: cpp

    class AccessControl {
    private:
        int privateVar;
    protected:
        int protectedVar;
    public:
        int publicVar;
        AccessControl() : privateVar(1), protectedVar(2), publicVar(3) {}
    };

Intentar acceder a los miembros desde una función externa:

.. code-block:: cpp

    int main() {
        AccessControl ac;
        ac.publicVar = 10; // Válido
        // ac.protectedVar = 20; // Error de compilación
        // ac.privateVar = 30; // Error de compilación
        return 0;
    }

Prompt para ChatGPT: ¿Cómo implementa el compilador el encapsulamiento en C++? Si los miembros privados aún ocupan 
espacio en el objeto, ¿Qué impide que se acceda a ellos desde fuera de la clase? 

.. warning:: MUY IMPORTANTE

    Experimenta modificando el código y observa los mensajes del compilador.

Hagamos un poco de hackers y rompamos el encapsulamiento
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Objetivo: el objetivo de este experimento es demostrar cómo se pueden violar las restricciones de acceso a 
los miembros privados de una clase en C++ utilizando técnicas de bajo nivel como la aritmética de punteros 
y reinterpret_cast. Se ilustrará cómo es posible acceder a los datos privados de un objeto desde fuera de la 
clase, lo que rompe el principio de encapsulamiento.

Considera los siguientes pasos:

1. Definición de la clase: primero, define una clase con miembros privados para observar el acceso a esos miembros 
   desde fuera de la clase.

.. code-block:: cpp

    #include <iostream>

    class MyClass {
    private:
        int secret1;
        float secret2;
        char secret3;

    public:
        MyClass(int s1, float s2, char s3) : secret1(s1), secret2(s2), secret3(s3) {}

        void printMembers() const {
            std::cout << "secret1: " << secret1 << "\n";
            std::cout << "secret2: " << secret2 << "\n";
            std::cout << "secret3: " << secret3 << "\n";
        }
    };

1. Intento de acceso ilegal: verifica que no se puede acceder a los miembros privados directamente utilizando el compilador:

.. code-block:: cpp

    int main() {
        MyClass obj(42, 3.14f, 'A');
        // Esta línea causará un error de compilación
        std::cout << obj.secret1 << std::endl;
        
        obj.printMembers();  // Método público para mostrar los valores
        return 0;
    }

El código anterior intentará acceder directamente al miembro privado secret1, lo que resultará en un error de compilación.

3. Acceso a miembros privados usando reinterpret_cast: ahora, observa cómo violar el encapsulamiento utilizando 
   reinterpret_cast y la aritmética de punteros:

.. code-block:: cpp

    int main() {
        MyClass obj(42, 3.14f, 'A');
        
        // Usando reinterpret_cast para violar el encapsulamiento
        int* ptrInt = reinterpret_cast<int*>(&obj);
        float* ptrFloat = reinterpret_cast<float*>(ptrInt + 1);
        char* ptrChar = reinterpret_cast<char*>(ptrFloat + 1);

        // Accediendo y mostrando los valores privados
        std::cout << "Accediendo directamente a los miembros privados:\n";
        std::cout << "secret1: " << *ptrInt << "\n";       // Accede a secret1
        std::cout << "secret2: " << *ptrFloat << "\n";     // Accede a secret2
        std::cout << "secret3: " << *ptrChar << "\n";      // Accede a secret3
        
        return 0;
    }

Ahora reflexiona:

* ¿Qué es el encapsulamiento y cuál es su propósito en la programación orientada a objetos?
* ¿Por qué es importante proteger los datos de una clase y restringir el acceso desde fuera de la misma?
* ¿Qué significa reinterpret_cast y cómo afecta la seguridad del programa?
* ¿Por qué crees que se pudo acceder a los miembros privados de MyClass en este experimento, a pesar de que el 
  compilador normalmente lo impediría?
* ¿Cuáles podrían ser las consecuencias de utilizar técnicas como las mostradas en este experimento en un programa real?
* ¿Qué implicaciones tiene este experimento sobre la confianza en las barreras de encapsulamiento que proporciona C++?

Herencia y la Relación en Memoria
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^	

* Layout de memoria: ¿Cómo los objetos derivados contienen los datos de las clases base?
* Desplazamiento en memoria: los atributos de la clase base preceden a los de la clase derivada.

Considera los siguientes pasos:

1. Crear clases con herencia:

.. code-block:: cpp

    class Base {
    public:
        int baseVar;
    };
    class Derived : public Base {
    public:
        int derivedVar;
    };

2. Analizar las direcciones de memoria:

.. code-block:: cpp

    Derived d;
    std::cout << "Dirección de d: " << &d << std::endl;
    std::cout << "Dirección de d.baseVar: " << &(d.baseVar) << std::endl;
    std::cout << "Dirección de d.derivedVar: " << &(d.derivedVar) << std::endl;

* ¿Cómo se organizan los atributos en memoria?
* ¿Qué sucede si agregamos más niveles de herencia?

Prompt para ChatGPT: explícame cómo se organiza en memoria un objeto de una clase derivada en C++. 
¿Cómo se almacenan los atributos de la clase base y de la derivada?

.. warning:: MUY IMPORTANTE

    Verifica las respuestas mediante experimentación y análisis del código

Polimorfismo y Vtables en detalle
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Polimorfismo: permite usar una interfaz común para diferentes tipos de objetos.
* Implementación: uso de vtables para resolver métodos virtuales.

Considera los siguientes pasos:

1. Crear una jerarquía polimórfica:

.. code-block:: cpp

    class Animal {
    public:
        virtual void makeSound() {
            std::cout << "Some generic sound" << std::endl;
        }
    };
    class Dog : public Animal {
    public:
        void makeSound() override {
            std::cout << "Bark" << std::endl;
        }
    };
    class Cat : public Animal {
    public:
        void makeSound() override {
            std::cout << "Meow" << std::endl;
        }
    };

2. Usar punteros de la clase base:

.. code-block:: cpp

    Animal* animals[] = { new Dog(), new Cat() };
    for (Animal* animal : animals) {
        animal->makeSound();
    }

3. Analizar con un depurador: observa cómo se resuelven las llamadas a makeSound() en tiempo de ejecución.

* ¿Cómo utiliza el programa las vtables para el polimorfismo?
* ¿Cuál es el impacto en el rendimiento?
* Prompt para ChatGPT: ¿Cómo funciona el polimorfismo en C++ a nivel interno? Explica cómo se utilizan las 
  vtables para resolver métodos virtuales en una jerarquía de herencia.

.. warning:: MUY IMPORTANTE

    Experimenta con el código y utiliza herramientas de depuración para confirmar las explicaciones.

4. Reflexión Individual:

* ¿Cómo se implementan internamente el encapsulamiento, la herencia y el polimorfismo?
* Análisis: ventajas y desventajas en términos de eficiencia y complejidad.

Reto 
------

Ahora es momento de aplicar todo lo que has aprendido. En estas sesiones, crearás tu propio proyecto de 
arte generativo en openFrameworks, utilizando la programación orientada a objetos de manera consciente y 
fundamentada. Cada decisión que tomes estará basada en una comprensión profunda de cómo funcionan los objetos, 
datos y métodos en la memoria. Además, documentarás este proceso en tu bitácora, reflejando tus descubrimientos 
y aprendizajes. ¡Es tu oportunidad para transformar el conocimiento en creatividad!

Objetivo: implementar un proyecto de arte generativo, documentando en detalle cómo se aplican e impactan las 
abstracciones de OOP en el proyecto.

Enunciado
****************

* Diseñar y desarrollar un proyecto de arte generativo utilizando openFrameworks.
* Aplicar conceptos de encapsulamiento, herencia y polimorfismo.
* Ejemplos de proyectos: sistema de partículas con comportamientos variados, generación procedimental de formas y patrones. 
  Prompt para ChatGPT: ¿Puedes ayudarme a diseñar un proyecto de arte generativo en C++ utilizando openFrameworks que 
  utilice encapsulamiento, herencia y polimorfismo? Quiero implementar un sistema de partículas con diferentes comportamientos.

.. warning:: MUY IMPORTANTE

    Usa las sugerencias de ChatGPT como inspiración, pero verifica y adapta el código según tus necesidades.

Experimentación 
*****************

* Utiliza las herramientas de Visual Studio para medir el uso de memoria y rendimiento.
* Identificar cómo las decisiones de diseño OOP afectan el rendimiento.
* Optimización: mejorar el código basándose en el análisis.
* Considerar alternativas como evitar métodos virtuales cuando sea posible.

Prompt para ChatGPT:

¿Cómo puedo optimizar mi proyecto de arte generativo en openFrameworks para mejorar el rendimiento? 
¿Qué impacto tienen los métodos virtuales y cómo puedo minimizar su sobrecarga?

.. warning:: MUY IMPORTANTE

    Comprueba las recomendaciones mediante pruebas y mediciones de rendimiento.

Reflexión y ajuste Final
*************************

* Realizar pruebas finales y ajustes.
* Asegurar que el código sigue buenas prácticas de OOP.
* ¿Cómo influyó el entendimiento de los mecanismos internos de OOP en el proyecto?
* ¿Qué desafíos enfrentaste y cómo los superaste?
* ¿Qué aprendiste sobre el equilibrio entre diseño y eficiencia?

Prompt para ChatGPT:

Ayúdame a revisar mi proyecto para asegurarme de que sigo las mejores prácticas de programación orientada a 
objetos en C++. ¿Qué aspectos debo considerar en términos de encapsulamiento, herencia y polimorfismo?

.. warning:: MUY IMPORTANTE

    Verifica las sugerencias y aplica las que consideres apropiadas.

Evidencias de los resultados de aprendizaje
*********************************************

.. warning:: MUY IMPORTANTE 

    ¿Recuerdas los resultados de aprendizaje específicos (RAE) de este curso?

    * RAE1: construyo aplicaciones interactivas aplicando patrones y estrategias que 
      permitan alcanzar los requisitos funcionales y no funcionales establecidos. Se espera que 
      llegues a un nivel resolutivo.
    * RAE2: aplico pruebas de las partes y del todo de un software siguiendo metodologías, 
      técnicas y estándares de la industria para garantizar el correcto funcionamiento de las 
      aplicaciones. Se espera que llegues a un nivel autónomo.

* El RAE1 lo evidenciarás con la construcción de la aplicación que propone el reto. No olvides 
  que debes verificar el complimiento de todos los requisitos para poder entregar esta 
  parte de la unidad. Incluye en tu bitácora capturas de pantalla donde muestres en 
  funcionamiento tu obra de arte generativo. Cada captura debe mostrar un aspecto diferente 
  que capture los requisitos del reto.
* El RAE2 lo evidenciarás con capturas de pantalla y explicaciones de las mismas donde muestres 
  de manera progresiva como vas cumpliendo cada requisito, las pruebas realizadas a las partes y a 
  toda la aplicación.