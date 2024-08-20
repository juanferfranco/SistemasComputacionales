Experiencia de aprendizaje 3. Lenguaje de alto nivel 
===========================================================

Introducción
--------------

En esta unidad retomarás algunos conceptos de programación en alto nivel y 
analizarás cómo están implementados. 

Investigación 
---------------

Actividad 1
*************

Esta actividad será grupal y demostrativa. Te mostraré los pasos a seguir 
para instalar y probar la herramienta que usarás desde ahora en el curso. Se trata 
de `openframeworks <https://openframeworks.cc/>`__. El objetivo en este curso 
no es que aprendas a programar en openframeworks, sino que entiendas cómo se 
implementan algunos conceptos de programación en alto nivel, pero usando un 
framework de programación creativa en C++ que te permitan explorar y experimentar 
de manera más visual y creativa.

Para verificar que todo quedó correctamente instalado, vamos a realizar un pequeño 
ejercicio modificando ligeramente el archivo ofApp.cpp que se genera por defecto:

.. code-block:: c++

    #include "ofApp.h"

    //--------------------------------------------------------------
    void ofApp::setup(){
        ofBackground(0);
    }

    //--------------------------------------------------------------
    void ofApp::update(){

    }

    //--------------------------------------------------------------
    void ofApp::draw(){
        ofSetColor(255);
        ofDrawCircle(ofGetMouseX(), ofGetMouseY(), 20);
    }

* ¿Cuál es el resultado que se obtiene al ejecutar este programa?

Actividad 2 
*************

De nuevo una actividad grupal en la cual escribiremos juntos nuestra primera aplicación 
y analizaremos las diferentes partes que la componen.

* Genera un proyecto con el generador de proyectos de openframeworks.
* Abre el proyecto en Visual Studio.
* Modifica el archivo ofApp.h así:

.. code-block:: c++

    #pragma once

    #include "ofMain.h"

    class ofApp : public ofBaseApp{

        public:
            void setup();
            void update();
            void draw();

            void mouseMoved(int x, int y );
            void mousePressed(int x, int y, int button);

        private:

            vector<ofVec2f> particles;
            ofColor particleColor;
            
    };

* Ahora modifica el archivo ofApp.cpp así:

.. code-block:: c++

    #include "ofApp.h"

    //--------------------------------------------------------------
    void ofApp::setup(){
        ofBackground(0);
        particleColor = ofColor::white;
    }

    //--------------------------------------------------------------
    void ofApp::update(){

    }

    //--------------------------------------------------------------
    void ofApp::draw(){
        for(auto &pos: particles){
            ofSetColor(particleColor);
            ofDrawCircle(pos.x, pos.y, 50);
        }
    }

    //--------------------------------------------------------------
    void ofApp::mouseMoved(int x, int y ){
        particles.push_back(ofVec2f(x, y));
        if (particles.size() > 100) {
            particles.erase(particles.begin());
        }
    }

    //--------------------------------------------------------------
    void ofApp::mousePressed(int x, int y, int button){
        particleColor = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    }

Analicemos juntos este código:

* ¿Qué fue lo que incluimos en el archivo .h?
* ¿Cómo funciona la aplicación?
* ¿Qué hace la función mouseMoved?
* ¿Qué hace la función mousePressed?
* ¿Qué hace la función setup?
* ¿Qué hace la función update?
* ¿Qué hace la función draw?
  
Actividad 3
*************

Analiza la aplicación anterior. ¿Qué hace cada función? ¿Qué hace cada línea de código?

Realiza un experimento con la aplicación anterior. Modifica alguna parte de su código.

Actividad 4
***************

Esta actividad la puedes realizar en tu tiempo de trabajo independiente de la semana de investigación. 
Invierte el espacio completo de 1 hora 40 minutos, pero si realmente piensas que quieres 
explorar más sobre programación en C++, entonces invierte más tiempo.

Ten presente que este recurso que te propongo se ajusta a la metodología que estamos siguiendo 
que es aprender a aprender mediante la investigación y la experimentación. Notarás entonces 
que en los videos hay muchos experimentos que podrás reproducir y analizar, pero ten presente 
que el autor usa Linux y tu usarás, normalmente, Windows.

Te voy a proponer varios videos que te ayudarán a introducirte en la programación con C++. 
Mira, en este curso no buscamos que aprendas C++, pero sí que entiendas cómo se implementan 
algunos conceptos de programación en alto nivel. Por tanto, usaremos lo necesario de C++ 
para lograr este objetivo.

Analiza algunos videos del playlist de Mike Shah 
`The C++ Programming Language <https://youtube.com/playlist?list=PLvv0ScY6vfd8j-tlhYVPYgiIyXduu6m-L&si=ISrbMNVl2z6Qf-yO>`__

Actividad 5
*************

En la unidad anterior introducimos el concepto de puntero. Ahora vamos a profundizar en este 
concepto de manera práctica.

El siguiente ejemplo se supone (en la actividad que sigue vas a corregir un error) que te permite 
seleccionar una espera y moverla con el mouse.

Modifica el archivo ofApp.h de la siguiente manera:

.. code-block:: c++

    #pragma once

    #include "ofMain.h"


    class Sphere {
    public:
        Sphere(float x, float y, float radius);
        void draw();
        void update(float x, float y);
        float getX();
        float getY();
        float getRadius();

    private:
        float x, y; 
        float radius; 
        ofColor color; 
    };

    class ofApp : public ofBaseApp{

        public:
            void setup();
            void update();
            void draw();

            void mouseMoved(int x, int y );
            void mousePressed(int x, int y, int button);

        private:
            
            vector<Sphere*> spheres;
            Sphere* selectedSphere;
    };

Y el archivo ofApp.cpp así:

.. code-block:: c++

    #include "ofApp.h"

    Sphere::Sphere(float x, float y, float radius) : x(x), y(y), radius(radius) {
        color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255)); 
    }

    void Sphere::draw() {
        ofSetColor(color);
        ofDrawCircle(x, y, radius);
    }

    void Sphere::update(float x, float y) {
        this->x = x;
        this->y = y;
    }

    float Sphere::getRadius() {
        return radius;
    }

    float Sphere::getX() {
        return x;
    }

    float Sphere::getY() {
        return y;
    }

    //--------------------------------------------------------------
    void ofApp::setup(){
        ofBackground(0);

        for (int i = 0; i < 5; i++) {
            float x = ofRandomWidth();
            float y = ofRandomHeight();
            float radius = ofRandom(20, 50);
            spheres.push_back(new Sphere(x, y, radius));
        }
        selectedSphere = nullptr;

    }

    //--------------------------------------------------------------
    void ofApp::update(){
        if (selectedSphere != nullptr) {
            selectedSphere->update(ofGetMouseX(), ofGetMouseY());
        }
    }

    //--------------------------------------------------------------
    void ofApp::draw(){
        for (auto sphere : spheres) {
            sphere->draw();
        }
    }


    //--------------------------------------------------------------
    void ofApp::mouseMoved(int x, int y ){

    }

    //--------------------------------------------------------------
    void ofApp::mousePressed(int x, int y, int button){

        if(button == OF_MOUSE_BUTTON_LEFT){
            for (auto sphere : spheres) {
                float distance = ofDist(x, y, sphere->getX(), sphere->getY());
                if (distance < sphere->getRadius()) {

                    selectedSphere = sphere;
                    break;
                }
            }
        }
    }

* ¿Cuál es la definición de un puntero?
* ¿Dónde está el puntero?
* ¿Cómo se inicializa el puntero?
* ¿Para qué se está usando el puntero?
* ¿Qué es exactamente lo que está almacenado en el puntero?

Actividad 6
*************

El código anterior tiene un problema. ¿Puedes identificar cuál es? ¿Cómo lo solucionarías?
Recuerda que deberías poder seleccionar una esfera y moverla con el mouse.

Actividad 7
*************

Ahora te voy a proponer que reflexiones profundamente sobre el manejo de la memoria en un programa.
Se trata de un experimento en el que tienes que analizar por qué está funcionando mal.

Modifica el archivo ofApp.h de la siguiente manera:

.. code-block:: c++

    #pragma once

    #include "ofMain.h"

    class Sphere {
    public:
        Sphere(float x, float y, float radius);
        void draw() const;

        float x, y; 
        float radius; 
        ofColor color; 
    };

    class ofApp : public ofBaseApp {
    public:
        void setup();
        void update();
        void draw();
        
        void keyPressed(int key);

    private:
        std::vector<Sphere*> globalVector; 
        void createObjectInStack(); 
    };

Y el archivo ofApp.cpp así:

.. code-block:: c++

    #include "ofApp.h"

    Sphere::Sphere(float x, float y, float radius) : x(x), y(y), radius(radius) {
        color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    }

    void Sphere::draw() const {
        ofSetColor(color);
        ofDrawCircle(x, y, radius); 
    }

    void ofApp::setup() {
        ofBackground(0);
    }

    void ofApp::update() {
    }

    void ofApp::draw() {
        ofSetColor(255);
        for (Sphere* sphere : globalVector) {
            if (sphere != nullptr) {
                ofDrawBitmapString("Objects pointed: " + ofToString(globalVector.size()), 20, 20);
                ofDrawBitmapString("Attempting to draw stored object...", 20, 40);
                ofDrawBitmapString("Stored Object Position: " + ofToString(sphere->x) + ", " + ofToString(sphere->y), 20, 60);
                sphere->draw();
            }
        }
    }

    void ofApp::keyPressed(int key) {
        if (key == 'c') {
            if (globalVector.empty()) {
                createObjectInStack();
            }
        }
        else if (key == 'd') {
            if (!globalVector.empty()) {
                ofLog() << "Accessing object in global vector: Position (" << globalVector[0]->x << ", " << globalVector[0]->y << ")";
            }
            else {
                ofLog() << "No objects in the global vector.";
            }
        }
    }

    void ofApp::createObjectInStack() {
        Sphere localSphere(ofRandomWidth(), ofRandomHeight(), 30); 
        globalVector.push_back(&localSphere);
        ofLog() << "Object created in stack: Position (" << localSphere.x << ", " << localSphere.y << ")";
        localSphere.draw();
    } 


* ¿Qué sucede cuando presionas la tecla 'c'?

Realiza esta modificación a la función createObjectInStack donde claramente se está creando un objeto, pero 
se está creando en el heap y no en el stack, así que no te dejes confundir por el nombre de la función. 

.. code-block:: c++ 

    void ofApp::createObjectInStack() {
        // Sphere localSphere(ofRandomWidth(), ofRandomHeight(), 30); 
        // globalVector.push_back(&localSphere);
        // ofLog() << "Object created in stack: Position (" << localSphere.x << ", " << localSphere.y << ")";
        // localSphere.draw();
        Sphere* heapSphere = new Sphere(ofRandomWidth(), ofRandomHeight(), 30);
        globalVector.push_back(heapSphere);
        ofLog() << "Object created in heap: Position (" << heapSphere->x << ", " << heapSphere->y << ")";
        heapSphere->draw();
    } 

* ¿Qué sucede cuando presionas la tecla 'c'?
* ¿Por qué ocurre esto?

Actividad 8
*************

Construye un experimento (un programa) en el que puedas crear y dibujar objetos que se almancenan:

* En el heap.
* En el stack.
* En memoria global.

.. note:: si puedes usar el stack

    Pero recuerda que los objetos solo dudarán en el stack el tiempo que dure la función que los creó. 
    ¿Hay alguna función en el programa que dure durante toda la ejecución del programa? 

* ¿Cuándo debo crear objetos en el heap y cuándo en memoria global?


Actividad 9
*************

Considera el siguiente código. El archivo ofApp.h es el siguiente:

.. code-block:: c++

    #pragma once

    #include "ofMain.h"

    class ofApp : public ofBaseApp{
    public:
        void setup();
        void update();
        void draw();
        
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);

    private:
        vector<ofVec2f*> heapObjects;
    };

Y el archivo ofApp.cpp es el siguiente:

.. code-block:: c++

    #include "ofApp.h"

    void ofApp::setup(){
        ofBackground(0);
    }

    void ofApp::update(){
    }

    void ofApp::draw(){
        ofSetColor(0, 0, 255); // Color azul para los objetos del heap
        for(auto& pos : heapObjects) {
            ofDrawCircle(pos->x, pos->y, 20);
            ofDrawBitmapString("Heap Memory", pos->x - 40, pos->y - 40);
        }
    }

    void ofApp::keyPressed(int key){
        if(key == 'f') {
            if(!heapObjects.empty()) {
                delete heapObjects.back(); 
                heapObjects.pop_back(); 
            }
        }
    }

    void ofApp::mousePressed(int x, int y, int button){
        heapObjects.push_back(new ofVec2f(x, y));
    }

* ¿Qué sucede cuando presionas la tecla 'f'?
* Analiza detalladamente esta parte del código:
  
.. code-block:: c++ 

    if(!heapObjects.empty()) {
        delete heapObjects.back(); 
        heapObjects.pop_back(); 
    }

Actividad 10
*************

Llegaste a este punto y tienes aún tiempo para invertir? Entonces te propongo que sigas 
observando los videos de Mike Shah sobre C++.

Reto 
------

.. note:: TODO 

    Lo publicaré la semana entrante. Por favor concéntrate en investigar y experimentar. 
    Si lo haces bien, el reto será muy sencillo.

