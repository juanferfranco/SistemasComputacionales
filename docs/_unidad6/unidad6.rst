Experiencia de aprendizaje 6. Patrones de diseño
===================================================

Introducción
--------------

En esta unidad exploraremos algunos patrones de diseño (**Observer**, **Factory** y 
**State**). Estos patrones son soluciones comprobadas a problemas comunes en el diseño de 
software orientado a objetos. Aplicarás estos patrones al desarrollo de un proyecto de 
arte generativo interactivo en tiempo real utilizando **C++** y **openFrameworks**. Además, 
enfatizaremos la importancia de realizar pruebas desde el inicio del desarrollo para 
garantizar el correcto funcionamiento de las aplicaciones.

.. warning:: Esta unidad es alimento para el pensamiento.

    Mira, los patrones de diseño son una herramienta muy útil para resolver problemas comunes en 
    el diseño de software, en esta unidad te voy a proponer que construyas un proyecto de arte 
    generativo interactivo utilizando los patrones de diseño que hemos estudiado, pero esto no quiere 
    decir que debas utilizarlos en todos tus proyectos, de hecho, en la práctica, la mayoría de los 
    proyectos no requieren de patrones de diseño, pero es importante que los conozcas y sepas cómo
    aplicarlos cuando sea necesario.

Investigación
---------------

.. warning:: Para tu bitácora 

    Evidencia en tu bitácora todo el proceso de investigación realizado en esta unidad.

Sesión 1: profundización teórica de patrones de diseño
**********************************************************

A continuación, te presentaré los recursos teóricos para cada patrón. Estudia cada uno detenidamente 
y conversa con ChatGPT sobre ellos. Puedes hacer preguntas, pedir ejemplos y aclarar tus dudas.

* `Factory method <https://refactoring.guru/design-patterns/factory-method>`__.
* `Observer <https://refactoring.guru/design-patterns/observer>`__.
* `State <https://refactoring.guru/design-patterns/state>`__.

Sesión 2: análisis de un caso de estudio
**********************************************************

Ahora te voy a presentar un caso de estudio que utiliza los patrones de diseño que hemos estudiado.
Ten presente que no voy a partir el código en múltiples archivos para que puedas hacer las 
pruebas y configuración rápidamente, pero en la práctica deberías hacerlo por orden y para favorecer 
el trabajo en equipo.

ofApp.h:

.. code-block:: c++

    #pragma once

    #include "ofMain.h"
    #include <vector>
    #include <string>

    class Observer {
    public:
        virtual void onNotify(const std::string& event) = 0;
    };

    class Subject {
    public:
        void addObserver(Observer* observer);
        void removeObserver(Observer* observer);
    protected:
        void notify(const std::string& event);
    private:
        std::vector<Observer*> observers;
    };

    class Particle;

    class State {
    public:
        virtual void update(Particle* particle) = 0;
        virtual void onEnter(Particle* particle) {}
        virtual void onExit(Particle* particle) {}
        virtual ~State() = default;
    };

    class Particle : public Observer {
    public:
        Particle();
        ~Particle();

        void update();
        void draw();
        void onNotify(const std::string& event) override;
        void setState(State* newState);

        ofVec2f position;
        ofVec2f velocity;
        float size;
        ofColor color;

    private:
        State* state;
    };


    class NormalState : public State {
    public:
        void update(Particle* particle) override;
        virtual void onEnter(Particle* particle) override;
    };


    class AttractState : public State {
    public:
        void update(Particle* particle) override;
    };

    class RepelState : public State {
    public:
        void update(Particle* particle) override;
    };

    class StopState : public State {
    public:
        void update(Particle* particle) override;
    };

    class ParticleFactory {
    public:
        static Particle* createParticle(const std::string& type);
    };

    class ofApp : public ofBaseApp, public Subject {
        public:
            void setup();
            void update();
            void draw();
            void keyPressed(int key);
    private:
        std::vector<Particle*> particles;
    };


ofApp.cpp:

.. code-block:: c++

    #include "ofApp.h"

    void Subject::addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void Subject::removeObserver(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void Subject::notify(const std::string& event) {
        for (Observer* observer : observers) {
            observer->onNotify(event);
        }
    }

    Particle::Particle() {
        // Inicializar propiedades
        position = ofVec2f(ofRandomWidth(), ofRandomHeight());
        velocity = ofVec2f(ofRandom(-0.5f, 0.5f), ofRandom(-0.5f, 0.5f));
        size = ofRandom(2, 5);
        color = ofColor(255);

        state = new NormalState();
    }

    Particle::~Particle() {
        delete state;
    }

    void Particle::setState(State* newState) {
        if (state != nullptr) {
            state->onExit(this);
            delete state;
        }
        state = newState;
        if (state != nullptr) {
            state->onEnter(this);
        }
    }

    void Particle::update() {
        if (state != nullptr) {
            state->update(this);
        }
        // Mantener las partículas dentro de la ventana
        if (position.x < 0 || position.x > ofGetWidth()) velocity.x *= -1;
        if (position.y < 0 || position.y > ofGetHeight()) velocity.y *= -1;
    }

    void Particle::draw() {
        ofSetColor(color);
        ofDrawCircle(position, size);
    }

    void Particle::onNotify(const std::string& event) {
        if (event == "attract") {
            setState(new AttractState());
        }
        else if (event == "repel") {
            setState(new RepelState());
        }
        else if (event == "stop") {
            setState(new StopState());
        }
        else if (event == "normal") {
            setState(new NormalState());
        }
    }

    void NormalState::update(Particle* particle) {
        particle->position += particle->velocity;
    }

    void NormalState::onEnter(Particle* particle) {
        particle->velocity = ofVec2f(ofRandom(-0.5f, 0.5f), ofRandom(-0.5f, 0.5f));
    }

    void AttractState::update(Particle* particle) {
        ofVec2f mousePosition(((ofApp*)ofGetAppPtr())->mouseX, ((ofApp*)ofGetAppPtr())->mouseY);
        ofVec2f direction = mousePosition - particle->position;
        direction.normalize();
        particle->velocity += direction * 0.05;
        ofClamp(particle->velocity.x, -3, 3);
        particle->position += particle->velocity * 0.2;
    }

    void RepelState::update(Particle* particle) {
        ofVec2f mousePosition(((ofApp*)ofGetAppPtr())->mouseX, ((ofApp*)ofGetAppPtr())->mouseY);
        ofVec2f direction = particle->position - mousePosition;
        direction.normalize();
        particle->velocity += direction * 0.05;
        ofClamp(particle->velocity.x, -3, 3);
        particle->position += particle->velocity * 0.2;
    }

    void StopState::update(Particle* particle) {
        particle->velocity.x = 0;
        particle->velocity.y = 0;
    }

    Particle* ParticleFactory::createParticle(const std::string& type) {
        Particle* particle = new Particle();

        if (type == "star") {
            particle->size = ofRandom(2, 4);
            particle->color = ofColor(255, 0, 0); 
        }
        else if (type == "shooting_star") {
            particle->size = ofRandom(3, 6);
            particle->color = ofColor(0, 255, 0); 
            particle->velocity *= 3;
        }
        else if (type == "planet") {
            particle->size = ofRandom(5, 8);
            particle->color = ofColor(0, 0, 255); 
        }
        return particle;
    }


    void ofApp::setup() {
        ofBackground(0);
        // Crear partículas usando la fábrica
        for (int i = 0; i < 100; ++i) {
            Particle* p = ParticleFactory::createParticle("star");
            particles.push_back(p);
            addObserver(p);
        }

        for (int i = 0; i < 5; ++i) {
            Particle* p = ParticleFactory::createParticle("shooting_star");
            particles.push_back(p);
            addObserver(p);
        }

        for (int i = 0; i < 10; ++i) {
            Particle* p = ParticleFactory::createParticle("planet");
            particles.push_back(p);
            addObserver(p);
        }

    }


    void ofApp::update() {
        for (Particle* p : particles) {
            p->update();
        }
    }


    void ofApp::draw() {
        for (Particle* p : particles) {
            p->draw();
        }
    }

    void ofApp::keyPressed(int key) {
        if (key == 's') {
            notify("stop");
        }
        else if (key == 'a') {
            notify("attract");
        }
        else if (key == 'r') {
            notify("repel");
        }
        else if (key == 'n') {
            notify("normal");
        }
    }

Ahora te pediré que te tomes un tiempo para analizar el código y entender su funcionamiento.

* ¿Qué hace el patrón observer en este caso?
* ¿Qué hace el patrón factory en este caso?
* ¿Qué hace el patrón state en este caso?

Experimenta con el código y realiza algunas modificaciones para entender mejor su funcionamiento.
Por ejemplo:

* Adiciona un nuevo tipo de partícula.
* Adiciona un nuevo estado.
* Modifica el comportamiento de las partículas.
* Crea otros eventos para notificar a las partículas.

Sesión 3: revisión de la teoría y caso de estudio
******************************************************

En esta sesión de trabajo por fuera de aula continuarás el proceso de análisis y experiementación.

Reto
--------

Desarrolla un proyecto de arte generativo interactivo en tiempo real. Diferente, lo más 
que puedas al caso de estudio.

Requisitos
***********

* Utilizando **C++** y **openFrameworks**. 
* Aplica el patrón de diseño **Observer**.
* Aplica el patrón de diseño **Factory**. 
* Aplica el patrón de diseño **State**.
* Realiza pruebas desde el inicio del desarrollo para garantizar el correcto
  funcionamiento de la aplicación.

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

* La construcción de la aplicación que propone el reto. 
* La explicación de para qué y cómo implentaste cada patrón.
* El código fuente de tu aplicación.
* Un ENLACE a un video que muestre en funcionamiento la aplicación.

El RAE2 lo evidenciarás con:

* Explica y muestra cómo probaste cada patrón.
* Explica y muestra cómo probaste toda la aplicación.
