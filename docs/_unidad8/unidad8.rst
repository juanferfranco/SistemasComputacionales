Experiencia de aprendizaje 8. Sistema operativo
==================================================

Introducción
--------------

Has llegado a la última estación de este curso. En esta experiencia de aprendizaje, 
vas a explorar algunos conceptos básicos relacionados con algunos servicios que ofrece 
el sistema operativo y que permiten crear varias tareas en un mismo programa para poder 
hacer varias cosas al mismo tiempo. Además, aprenderás cómo se pueden comunicar entre 
sí y cómo se pueden sincronizar para que no se interfieran entre ellas.

Investigación 
---------------

Para esta fase de investigación vas a usar parte del material de apoyo de la plataforma 
openframeworks. En `este <https://openframeworks.cc/ofBook/chapters/threads.html>`__  
enlace se encuentra la documentación para esta experiencia de aprendizaje.

Actividad 1
************

¿Qué es un sistema operativo?

En términos generales, un sistema operativo es un SOFTWARE que administra
``RECURSOS de hardware y software del computador`` Y provee servicios mediante
los cuales los programas de usuario pueden hacer uso de esos recursos.

Los siguientes ejercicios explorarán algunos servicios que ofrece el sistema
operativo. La exploración la realizaremos de manera práctica para que luego 
(si te interesa al terminar el curso), puedas profundizar leyendo uno de los 
tantos excelentes libros de sistemas operativos. En particular te recomiendo 
este:

`Operating Systems: Three Easy Pieces <http://pages.cs.wisc.edu/~remzi/OSTEP/>`__

Ahora te propondré que busques en Internet información (o conversa con ChatGPT) 
para responder las siguientes preguntas:

* ¿Cuál es la diferencia entre un programa y un proceso?
* ¿Puedo tener múltiples procesos corriendo el mismo programa?
* ¿Para qué sirve el stack de un proceso?
* ¿Para qué sirve el heap de un proceso?
* ¿Qué es la zona de texto de un proceso?
* ¿Dónde se almacenan las variables globales inicializadas?
* ¿Dónde se almacenan las variables globales no inicializadas?
* ¿Cuáles son los posibles estados de un proceso en general? Ten en cuenta
  que esto varía entre sistemas operativos.

Actividad 2
************

Vas a explorar el concepto de hilo.

Hasta ahora todos los programas que has realizado tienen 
``un SOLO flujo de instrucciones``. ¿Y si quieres tener en el 
mismo programa ``VARIOS flujos de instrucciones independientes``? 
Lo puedes hacer con los hilos. Los hilos permitirán que un programa 
pueda ``HACER VARIAS COSAS AL MISMO TIEMPO``, cada cosa con hilo 
independiente. Cada cosa que se hace el mismo tiempo es una tarea y 
cada tarea tiene su propio hilo o flujo de instrucciones. Ten presente 
que los hilos compartirán recursos del proceso entre ellos estará el 
HEAP; sin embargo, cada hilo tendrá su propio STACK.

Vas a leer la sección del material de openframeworks, por ahora, solo 
la sección llamado: What's a thread and when to use it. Luego de leer,
Responde estas preguntas:

* ¿Qué es un hilo?
* ¿Cuándo se usa?
* Trata de inferior esto: ¿A qué se puede referir el concepto de tarea 
  ligada a la CPU y a la entrada/salida (E/S)?
* ¿Cuál es la relación entre operaciones ligadas a la CPU y los hilos?
* ¿Cuál es la relación entre operaciones ligadas a la E/S y los hilos?

Actividad 3
************

Vas a explorar la necesidad de tener un hilo cuando un programa 
tiene que hacer una tarea intensiva ligada a la CPU. 

Ejecuta el siguiente programa:

ofApp.h:

.. code-block:: c++

    #pragma once
    #include "ofMain.h"

    class ofApp : public ofBaseApp {
    public:
        float x = 0;
        float speed = 3;
        float circleSize = 50;

        void setup();
        void draw();
        void mousePressed(int x, int y, int button);
        void heavyComputation();
    };

ofApp.cpp:

.. code-block:: c++

    #include "ofApp.h"

    void ofApp::setup() {
        ofSetFrameRate(60);
        ofSetWindowShape(400, 400);
    }

    void ofApp::draw() {
        ofBackground(220);
        ofSetColor(0);
        ofDrawCircle(x, ofGetHeight() / 2, circleSize);
        x = fmod(x + speed, ofGetWidth());
    }

    void ofApp::mousePressed(int x, int y, int button) {
        heavyComputation();
    }

    void ofApp::heavyComputation() {
        double result = 0;
        for (int j = 0; j < 1000000000; ++j) {
            result += sqrt(j);
        }
        circleSize = ofRandom(20, 70);
        ofLog() << "Circle size: " << circleSize;
    }

* ¿Qué pasa cuando presionas el mouse?
* ¿Por qué?
* Considerando la definición de un hilo, ¿cómo podrías solucionar 
  el problema de que el programa se congele cuando presionas el mouse?

Actividad 4
*************

Vas a solucionar el problema de la actividad anterior usando hilos.

Para solucionar el problema de la actividad anterior, vas a crear un hilo. Observa 
el siguiente código:

ofApp.h:

.. code-block:: c++

    #pragma once
    #include "ofMain.h"
    #include "ofThread.h"

    class ofApp : public ofBaseApp, public ofThread {
    public:
        float x = 0;
        float speed = 3;
        float circleSize = 50;

        void setup();
        void draw();
        void mousePressed(int x, int y, int button);
        void heavyComputation();
        void startHeavyComputation();
        void threadedFunction() override;
        void exit();
    };


ofApp.cpp:

.. code-block:: c++

    #include "ofApp.h"

    void ofApp::setup() {
        ofSetFrameRate(60);
        ofSetWindowShape(400, 400);
    }

    void ofApp::draw() {

        ofBackground(220);
        ofSetColor(0);
        lock();
        ofDrawCircle(x, ofGetHeight() / 2, circleSize);
        unlock();
        x = fmod(x + speed, ofGetWidth());
    }

    void ofApp::mousePressed(int x, int y, int button) {
        if (!isThreadRunning()) {
            ofLog() << "Starting thread";
            startThread();
        }
        else {
            ofLog() << "Thread is already running";
        }
    }

    void ofApp::threadedFunction() {
        heavyComputation();
        ofLog() << "Thread ends";
    }

    void ofApp::heavyComputation() {
        double result = 0;
        for (int j = 0; j < 1000000000; ++j) {
            result += sqrt(j);
        }
        lock();
        ofSeedRandom();
        circleSize = ofRandom(20, 70);
        unlock();
        ofLog() << "Circle size: " << circleSize;
    }

    void ofApp::exit() {
        if (isThreadRunning()) {
            stopThread();
            waitForThread();
        }
    }


* ¿Qué pasa cuando presionas el mouse?
* ¿Por qué?
* ¿Qué hace el hilo?
* ¿Por qué el programa no se congela cuando presionas el mouse?
* ¿Qué pasa si presionas el mouse varias veces?
* ¿Por qué?
* ¿Qué pasa si presionas el mouse varias veces y rápido?
* ¿Por qué?
* Para qué se están usando las funciones lock y unlock?
* ¿Qué está pasando en la función exit?

Actividad 5
*************

Ahora te propondré un caso de estudio en el cual vas a comparar un 
programa con hilos y otro sin hilos resolviendo el mismo problema: flocking.



Reto 
------

..
    Ideas para la unidad:
    - Introducir de manera práctica el concepto de hilos.
    - Cómo crear un hilo.
    - Cómo comunicar el hilo principal con openframeworks para intercambiar datos.
    - Sincronización.