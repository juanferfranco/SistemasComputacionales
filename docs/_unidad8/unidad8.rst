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

Primero te mostraré la versión sin hilos:

ofApp.h:

.. code-block:: c++

    #pragma once

    #include "ofMain.h"

    class Boid {
    public:
        Boid(float x, float y);
        void run(const vector<Boid>& boids);
        void applyForce(ofVec2f force);
        void flock(const vector<Boid>& boids) ;
        void update();
        void borders();
        ofVec2f seek(ofVec2f target);
        void draw();

        ofVec2f separate(const vector<Boid>& boids);
        ofVec2f align(const vector<Boid>& boids);
        ofVec2f cohere(const vector<Boid>& boids);

        ofVec2f position;
        ofVec2f velocity;
        ofVec2f acceleration;
        float r;
        float maxforce;
        float maxspeed;
    };


    class Flock {
    public:
        void addBoid(float x, float y);
        void run();

        vector<Boid> boids;
    };


    class ofApp : public ofBaseApp {

    public:
        void setup();
        void update();
        void draw();
        void mouseDragged(int x, int y, int button);

        Flock flock;
    };

ofApp.cpp:

.. code-block:: c++

    #include "ofApp.h"

    Boid::Boid(float x, float y) {
        acceleration.set(0, 0);
        velocity.set(ofRandom(-1, 1), ofRandom(-1, 1));
        position.set(x, y);
        r = 3.0;
        maxspeed = 3;
        maxforce = 0.05;
    }

    void Boid::run(const vector<Boid>& boids){
        flock(boids);
        update();
        borders();
    }

    void Boid::applyForce(ofVec2f force) {
        acceleration += force;
    }

    void Boid::flock(const vector<Boid>& boids) {
        ofVec2f sep = separate(boids);
        ofVec2f ali = align(boids);
        ofVec2f coh = cohere(boids);
        sep *= 1.5;
        ali *= 1.0;
        coh *= 1.0;

        applyForce(sep);
        applyForce(ali);
        applyForce(coh);
    }

    void Boid::update() {
        velocity += acceleration;
        velocity.limit(maxspeed);
        position += velocity;
        acceleration *= 0;
    }

    ofVec2f Boid::seek(ofVec2f target) {
        ofVec2f desired = target - position;
        desired.normalize();
        desired *= maxspeed;
        ofVec2f steer = desired - velocity;
        steer.limit(maxforce);
        return steer;
    }

    void Boid::borders() {

        float width = ofGetWidth();
        float height = ofGetHeight();

        if (position.x < -r) position.x = width + r;
        if (position.y < -r) position.y = height + r;
        if (position.x > width + r) position.x = -r;
        if (position.y > height + r) position.y = -r;

    }

    void Boid::draw() {
        float theta = atan2(velocity.y, velocity.x) + PI / 2;
        ofSetColor(255);
        ofFill();
        ofPushMatrix();
        ofTranslate(position.x, position.y);
        ofRotate(ofRadToDeg(theta));
        ofBeginShape();
        ofVertex(0, -r * 2);
        ofVertex(-r, r * 2);
        ofVertex(r, r * 2);
        ofEndShape();
        ofPopMatrix();
    }

    ofVec2f Boid::separate(const vector<Boid>& boids) {
        float desiredSeparation = 25;
        ofVec2f steer(0, 0);
        int count = 0;

        for (const Boid& other : boids) {
            float d = position.distance(other.position);
            if (d > 0 && d < desiredSeparation) {
                ofVec2f diff = position - other.position;
                diff.normalize();
                diff /= d;
                steer += diff;
                count++;
            }
        }
        if (count > 0) {
            steer /= (float)count;
        }

        if (steer.length() > 0) {
            steer.normalize();
            steer *= maxspeed;
            steer -= velocity;
            steer.limit(maxforce);
        }
        return steer;
    }

    ofVec2f Boid::align(const vector<Boid>& boids) {
        float neighborDist = 50;
        ofVec2f sum(0, 0);
        int count = 0;

        for (const Boid& other : boids) {
            float d = position.distance(other.position);
            if (d > 0 && d < neighborDist) {
                sum += other.velocity;
                count++;
            }
        }
        if (count > 0) {
            sum /= (float)count;
            sum.normalize();
            sum *= maxspeed;
            ofVec2f steer = sum - velocity;
            steer.limit(maxforce);
            return steer;
        }
        return ofVec2f(0, 0);
    }

    ofVec2f Boid::cohere(const vector<Boid>& boids){
        float neighborDist = 50;
        ofVec2f sum(0, 0);
        int count = 0;

        for (const Boid& other : boids) {
            float d = position.distance(other.position);
            if (d > 0 && d < neighborDist) {
                sum += other.position;
                count++;
            }
        }
        if (count > 0) {
            sum /= count;
            return seek(sum);
        }
        return ofVec2f(0, 0);
    }

    void Flock::addBoid(float x, float y) {
        boids.emplace_back(x,y);
    }

    void Flock::run() {
        for (Boid& b : boids) {
            b.run(boids);
        }
    }


    void ofApp::setup() {
        flock.boids.reserve(120);
        for (int i = 0; i < 120; i++) {
            flock.addBoid(ofGetWidth() / 2, ofGetHeight() / 2);
        }
    }

    void ofApp::update() {
        flock.run();
    }

    void ofApp::draw() {
        ofBackground(0);
        for (Boid& b : flock.boids) {
            b.draw();
        }
        ofDrawBitmapStringHighlight("FPS: " + ofToString(ofGetFrameRate()), 20, 20);
        ofDrawBitmapStringHighlight("Boids: " + ofToString(flock.boids.size()), 20, 40);

    }

    void ofApp::mouseDragged(int x, int y, int button) {
        flock.addBoid(x,y);
    }

Ahora mira la versión con hilos:

ofApp.h:

.. code-block:: c++

    #pragma once

    #include "ofMain.h"
    #include "ofThread.h"

    class Boid {
    public:
        Boid(float x, float y);
        void run(const vector<Boid>& boids);
        void applyForce(ofVec2f force);
        void flock(const vector<Boid>& boids);
        void update();
        void borders();
        ofVec2f seek(ofVec2f target);
        void draw();

        ofVec2f separate(const vector<Boid>& boids);
        ofVec2f align(const vector<Boid>& boids);
        ofVec2f cohere(const vector<Boid>& boids);

        ofVec2f position;
        ofVec2f velocity;
        ofVec2f acceleration;
        float r;
        float maxforce;
        float maxspeed;
    };


    class Flock : public ofThread {
    public:
        void addBoid(int x, int y);
        void run();
        void threadedFunction();

        std::vector<Boid> boids;
    };


    class ofApp : public ofBaseApp {

    public:
        void setup();
        void update();
        void draw();
        void exit();
        void mouseDragged(int x, int y, int button);

        Flock flock;
    };

ofApp.cpp:

.. code-block:: c++

    #include "ofApp.h"

    Boid::Boid(float x, float y) {
        acceleration.set(0, 0);
        velocity.set(ofRandom(-1, 1), ofRandom(-1, 1));
        position.set(x, y);
        r = 3.0;
        maxspeed = 3;
        maxforce = 0.05;
    }

    void Boid::run(const vector<Boid>& boids) {
        flock(boids);
        update();
        borders();
    }

    void Boid::applyForce(ofVec2f force) {
        acceleration += force;
    }

    void Boid::flock(const vector<Boid>& boids) {
        ofVec2f sep = separate(boids);
        ofVec2f ali = align(boids);
        ofVec2f coh = cohere(boids);
        sep *= 1.5;
        ali *= 1.0;
        coh *= 1.0;

        applyForce(sep);
        applyForce(ali);
        applyForce(coh);
    }

    void Boid::update() {
        velocity += acceleration;
        velocity.limit(maxspeed);
        position += velocity;
        acceleration *= 0;
    }

    ofVec2f Boid::seek(ofVec2f target) {
        ofVec2f desired = target - position;
        desired.normalize();
        desired *= maxspeed;
        ofVec2f steer = desired - velocity;
        steer.limit(maxforce);
        return steer;
    }

    void Boid::borders() {
        if (position.x < -r) position.x = ofGetWidth() + r;
        if (position.y < -r) position.y = ofGetHeight() + r;
        if (position.x > ofGetWidth() + r) position.x = -r;
        if (position.y > ofGetHeight() + r) position.y = -r;
    }

    void Boid::draw() {
        float theta = atan2(velocity.y, velocity.x) + PI / 2;
        ofSetColor(255);
        ofFill();
        ofPushMatrix();
        ofTranslate(position.x, position.y);
        ofRotate(ofRadToDeg(theta));
        ofBeginShape();
        ofVertex(0, -r * 2);
        ofVertex(-r, r * 2);
        ofVertex(r, r * 2);
        ofEndShape();
        ofPopMatrix();
    }

    ofVec2f Boid::separate(const vector<Boid>& boids) {
        float desiredSeparation = 25;
        ofVec2f steer(0, 0);
        int count = 0;

        for (const Boid& other : boids) {
            float d = position.distance(other.position);
            if (d > 0 && d < desiredSeparation) {
                ofVec2f diff = position - other.position;
                diff.normalize();
                diff /= d;
                steer += diff;
                count++;
            }
        }
        if (count > 0) {
            steer /= (float)count;
        }

        if (steer.length() > 0) {
            steer.normalize();
            steer *= maxspeed;
            steer -= velocity;
            steer.limit(maxforce);
        }
        return steer;
    }

    ofVec2f Boid::align(const vector<Boid>& boids) {
        float neighborDist = 50;
        ofVec2f sum(0, 0);
        int count = 0;

        for (const Boid& other : boids) {
            float d = position.distance(other.position);
            if (d > 0 && d < neighborDist) {
                sum += other.velocity;
                count++;
            }
        }
        if (count > 0) {
            sum /= (float)count;
            sum.normalize();
            sum *= maxspeed;
            ofVec2f steer = sum - velocity;
            steer.limit(maxforce);
            return steer;
        }
        return ofVec2f(0, 0);
    }

    ofVec2f Boid::cohere(const vector<Boid>& boids) {
        float neighborDist = 50;
        ofVec2f sum(0, 0);
        int count = 0;

        for (const Boid& other : boids) {
            float d = position.distance(other.position);
            if (d > 0 && d < neighborDist) {
                sum += other.position;
                count++;
            }
        }
        if (count > 0) {
            sum /= count;
            return seek(sum);
        }
        return ofVec2f(0, 0);
    }

    void Flock::addBoid(int x, int y) {
        lock();
        boids.emplace_back(x,y);
        unlock();
    }

    void Flock::run() {
        if (!isThreadRunning()) {
            startThread();
        }
    }

    void Flock::threadedFunction() {
        while (isThreadRunning()) {
            lock();
            for (Boid& b : boids) {
                b.run(boids);
            }
            unlock();
            sleep(10);
        }
    }

    void ofApp::setup() {
        // Add an initial set of boids
        for (int i = 0; i < 120; i++) {
            flock.addBoid(ofGetWidth() / 2, ofGetHeight() / 2);
        }
    }

    void ofApp::update() {
        flock.run();
    }

    void ofApp::draw() {
        ofBackground(0);

        flock.lock();
        for (Boid& b : flock.boids) {
            b.draw();
        }
        flock.unlock();

        ofDrawBitmapStringHighlight("FPS: " + ofToString(ofGetFrameRate()), 20, 20);
        ofDrawBitmapStringHighlight("Boids: " + ofToString(flock.boids.size()), 20, 40);
    }

    void ofApp::mouseDragged(int x, int y, int button) {
        flock.addBoid(x,y);
    }

    void ofApp::exit() {
        flock.stopThread();
        flock.waitForThread();
    }

* Estudia en detalle el código de ambas versiones. ¿Cómo funciona 
  cada versión del programa?
* Cómo se incorpora el concepto de hilo en la versión con hilos?
* ¿Qué es lock y unlock? ¿Por qué es importante realizar esta 
  sincronización? ¿Qué pasaría si no se realiza?
* Compara la eficienca de ambas versiones. ¿Cuál es más eficiente? 
  ¿Por qué?
* El uso de lock y unlock en la versión con hilos, ¿Cómo afecta 
  la eficiencia del programa?

.. warning:: ACTIVIDAD OPCIONAL
    Esta actividad es opcional. Te voy a mostrar cómo puedes implementar 
    el flocking utilizando la GPU y shaders.

  .. toctree::
    :maxdepth: 1

    ../cases/flockingShaders

Reto 
------
En este reto, implementarás una simulación de partículas que se muevan 
libremente en la pantalla y colisionen entre sí cuando se acerquen. 
El objetivo es comparar una implementación **secuencial (sin hilos)** y 
una **concurrente (usando hilos)**, observando las diferencias en rendimiento.

El reto está dividido en dos partes:

Primera parte: implementación secuencial (sin hilos)
******************************************************
Implementar una simulación donde unas partículas se muevan por 
la pantalla y colisionen entre sí sin el uso de hilos.

Requisitos:

1. Las partículas deben moverse libremente y rebotar cuando colisionen entre sí.
2. La simulación debe ejecutarse secuencialmente, sin utilizar `ofThread` ni 
   ninguna técnica de concurrencia.
3. Debes poder aumentar en tiempo real la cantidad de partículas en pantalla, 
   permitiendo observar cómo el rendimiento disminuye al aumentar el número de 
   partículas.
4. Visualizar el **framerate** en pantalla, el número de partículas y el número 
   de colisiones en cada frame.
  
Segunda parte: implementación concurrente (con hilos)
******************************************************

Modificar la simulación para usar varios hilos (`ofThread`), de manera que el 
cálculo del movimiento y las colisiones de las partículas esté distribuido 
entre diferentes hilos.

Requisitos:

1. Las partículas deben estar divididas en 4 grupos y cada grupo deberá ser 
   gestionado por un hilo.
2. No es necesario que aumentes en tiempo real la cantidad de partículas. Distribuye 
   de manera equitativa las partículas en los 4 grupos. De todas maneras 
   debes poder configurar la cantidad de partículas en tu programa para que puedas 
   comparar con la versión sin hilos. NO OLVIDES: esta variación lo realizarás 
   en tiempo de compilación.
3. Las colisiones dentro de un mismo grupo de partículas se deben calcular sin 
   necesidad de sincronización.
4. Las colisiones entre partículas de diferentes grupos deben gestionarse 
   usando sincronización (locks) para evitar condiciones de carrera.
5. Visualizar el **framerate**, el número de partículas, el número de grupos y el 
   número de colisiones en cada frame.

Comparación entre ambas versiones
***********************************

Después de completar ambas partes, deberás hacer una **comparación de rendimiento** 
entre la implementación secuencial y la concurrente. Responde a las siguientes 
preguntas:

1. ¿Cómo afecta el uso de hilos al framerate a medida que aumenta el número de partículas?
2. ¿Qué impacto tiene la sincronización (locks) en el rendimiento?
3. ¿Dónde encontraste mayor beneficio en el uso de hilos y dónde causó más complicaciones?

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

El RAE1 lo evidenciarás con:

* La implementación de los requisitos funcionales de la aplicación sin hilos.
* La implementación de los requisitos funcionales y el uso de los locks para 
  evitar las condiciones de carrera en la aplicación con hilos.
* Solución a las preguntas de comparación entre ambas aplicaciones.

El RAE2 lo evidenciarás con:

* Evidencias de las pruebas realizadas a las aplicaciones. Debes 
  mostrar cómo probaste cada requisito y luego cómo fuiste probando la 
  integración de los mismos.
* Evidencias que sustenten la comparación entre ambas aplicaciones.

