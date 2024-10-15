Caso de estudio: Flocking con shaders
======================================

.. warning:: EN CONSTRUCCIÓN
    Esta sección tiene todo el código del caso de estudio, pero aún falta el análisis 
    y la explicación detallada cada parte del código.

Introducción
--------------------

En este caso de estudio te voy a mostrar cómo acelerar el cálculo del flocking utilizando shaders. 
Específicamente, voy a mostrarte como el uso de compute shaders puede acelerar el cálculo. También 
te mostraré una técnica llamada GPU instancing que te permitirá renderizar miles de boids en tiempo 
real.

Análisis
----------

El flocking es un algoritmo que se basa en la interacción de múltiples agentes. Cada agente sigue 
tres reglas básicas: cohesión, separación y alineación. Estas reglas se aplican a cada agente 
individualmente y se calculan en función de la posición y velocidad de los agentes vecinos. 
El cálculo de estas reglas puede ser costoso, especialmente cuando el número de agentes es grande.

En la versión anterior, utilizamos un hilo para calcular el flocking. Sin embargo, el cálculo
de las reglas de flocking se puede paralelizar aún más utilizando shaders. Los shaders son programas
que se ejecutan en la GPU y son altamente paralelizables. En este caso, vamos a utilizar compute shaders
para calcular las reglas de flocking en paralelo.

Además, vamos a utilizar una técnica llamada GPU instancing para renderizar los boids. La técnica de 
GPU instancing nos permite renderizar múltiples instancias de un objeto utilizando una sola llamada
a la GPU. Esto es especialmente útil cuando queremos renderizar miles de boids en tiempo real.

La implementación de flocking con shaders consta de dos partes: el cálculo de las reglas de flocking
utilizando compute shaders y la renderización de los boids utilizando GPU instancing.

Para el cálculo de las reglas de flocking, vamos a utilizar un compute shader que se encargará de
calcular la posición y velocidad de cada boid en función de las reglas de cohesión, separación y alineación.
El compute shader se ejecutará en paralelo para cada boid, lo que nos permitirá acelerar el cálculo.

Para la renderización de los boids, vamos a utilizar GPU instancing.

Te voy a mostrar todos los códigos necesarios para implementar flocking con shaders en openFrameworks. 
Y luego los analizaremos juntos. Ten presente que para reproducir el código necesitas tener el addon 
ofxGui instalado.

main.cpp:

.. code-block:: cpp

    #include "ofMain.h"
    #include "ofApp.h"


    int main( ){

        ofGLWindowSettings settings;
        settings.setSize(1024, 768);
        settings.windowMode = OF_WINDOW;
        auto window = ofCreateWindow(settings);
        ofRunApp(window, make_shared<ofApp>());
        ofRunMainLoop();
    }

ofApp.h:

.. code-block:: cpp

    #pragma once
    #include "ofMain.h"
    #include "ofShader.h"
    #include "ofVboMesh.h"
    #include "ofxGui.h"

    class ofApp : public ofBaseApp {
    public:
        void setup();
        void update();
        void draw();
        void keyPressed(int key);
        void windowResized(int w, int h);

        ofShader computeShader;
        ofShader renderShader;
        GLuint positionBuffer;
        GLuint velocityBuffer;
        GLuint accelerationBuffer;
        ofVboMesh boidMesh;
        int numBoids;
        float maxForce;
        float maxSpeed;
        float desiredSeparation;
        float neighborDist;

        ofxPanel gui;
        ofxFloatSlider maxForceSlider;
        ofxFloatSlider maxSpeedSlider;
        ofxFloatSlider desiredSeparationSlider;
        ofxFloatSlider neighborDistSlider;

    };

ofApp.cpp:

.. code-block:: cpp

    #include "ofApp.h"

    void ofApp::setup() {
        
        ofSetFrameRate(60);
        numBoids = 1024;  //1024, 2048, 4096, 8192, 16384, 32768, 65536
        maxForce = 0.05;
        maxSpeed = 3.0;
        desiredSeparation = 25.0;
        neighborDist = 50.0;

        gui.setup();
        gui.setPosition(20, 140);
        gui.add(maxForceSlider.setup("Max Force", maxForce, 0.01, 0.5));
        gui.add(maxSpeedSlider.setup("Max Speed", maxSpeed, 0.1, 10.0));
        gui.add(desiredSeparationSlider.setup("Desired Separation", desiredSeparation, 10.0, 100.0));
        gui.add(neighborDistSlider.setup("Neighbor Distance", neighborDist, 20.0, 100.0));

        computeShader.loadCompute("shaders/flocking.comp");

        renderShader.load("shaders/render.vert", "shaders/render.frag");

        if (!computeShader.isLoaded()) {
            ofLogError() << "Failed to load compute shader!";
        }
        if (!renderShader.isLoaded()) {
            ofLogError() << "Failed to load render shaders!";
        }

        
        glGenBuffers(1, &positionBuffer);
        glBindBuffer(GL_SHADER_STORAGE_BUFFER, positionBuffer);
        glBufferData(GL_SHADER_STORAGE_BUFFER, numBoids * sizeof(glm::vec2), nullptr, GL_DYNAMIC_DRAW);

        glGenBuffers(1, &velocityBuffer);
        glBindBuffer(GL_SHADER_STORAGE_BUFFER, velocityBuffer);
        glBufferData(GL_SHADER_STORAGE_BUFFER, numBoids * sizeof(glm::vec2), nullptr, GL_DYNAMIC_DRAW);

        glGenBuffers(1, &accelerationBuffer);
        glBindBuffer(GL_SHADER_STORAGE_BUFFER, accelerationBuffer);
        glBufferData(GL_SHADER_STORAGE_BUFFER, numBoids * sizeof(glm::vec2), nullptr, GL_DYNAMIC_DRAW);

        
        glBindBuffer(GL_SHADER_STORAGE_BUFFER, positionBuffer);
        glm::vec2* positions = (glm::vec2*)glMapBufferRange(GL_SHADER_STORAGE_BUFFER, 0, numBoids * sizeof(glm::vec2), GL_MAP_WRITE_BIT);
        for (int i = 0; i < numBoids; i++) {
            positions[i] = glm::vec2(ofRandomWidth(), ofRandomHeight());
        }
        glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);

        glBindBuffer(GL_SHADER_STORAGE_BUFFER, velocityBuffer);
        glm::vec2* velocities = (glm::vec2*)glMapBufferRange(GL_SHADER_STORAGE_BUFFER, 0, numBoids * sizeof(glm::vec2), GL_MAP_WRITE_BIT);
        for (int i = 0; i < numBoids; i++) {
            velocities[i] = glm::vec2(ofRandom(-1, 1), ofRandom(-1, 1));
        }
        glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);

        
        boidMesh.setMode(OF_PRIMITIVE_TRIANGLES);
        boidMesh.addVertex(glm::vec3(0.0f, 10.0f, 0.0f));    
        boidMesh.addVertex(glm::vec3(-5.0f, -10.0f, 0.0f));  
        boidMesh.addVertex(glm::vec3(5.0f, -10.0f, 0.0f));   

        
        glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(1);
        glVertexAttribDivisor(1, 1); 
        glBindBuffer(GL_ARRAY_BUFFER, 0); 

        
        glBindBuffer(GL_ARRAY_BUFFER, velocityBuffer);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(2);
        glVertexAttribDivisor(2, 1); 
        glBindBuffer(GL_ARRAY_BUFFER, 0);


        glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, positionBuffer);
        glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, velocityBuffer);
        glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 2, accelerationBuffer);

        computeShader.begin();
        computeShader.setUniform1i("numBoids", numBoids);
        computeShader.setUniform1f("maxForce", maxForce);
        computeShader.setUniform1f("maxSpeed", maxSpeed);
        computeShader.setUniform1f("desiredSeparation", desiredSeparation);
        computeShader.setUniform1f("neighborDist", neighborDist);
        computeShader.setUniform1f("width", ofGetWidth());
        computeShader.setUniform1f("height", ofGetHeight());
        computeShader.end();
    }

    void ofApp::update() {


        maxForce = maxForceSlider;
        maxSpeed = maxSpeedSlider;
        desiredSeparation = desiredSeparationSlider;
        neighborDist = neighborDistSlider;

        computeShader.begin();
        computeShader.setUniform1f("maxForce", maxForce);
        computeShader.setUniform1f("maxSpeed", maxSpeed);
        computeShader.setUniform1f("desiredSeparation", desiredSeparation);
        computeShader.setUniform1f("neighborDist", neighborDist);
        glDispatchCompute((GLuint)ceil(numBoids / 512.0), 1, 1);
        glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);
        computeShader.end();
    }

    void ofApp::draw() {

        ofBackground(0);
        renderShader.begin();

        glm::mat4 viewMatrix = ofGetCurrentViewMatrix();
        glm::mat4 projectionMatrix = ofGetCurrentMatrix(OF_MATRIX_PROJECTION);
        glm::mat4 modelViewProjectionMatrix = projectionMatrix * viewMatrix;
        renderShader.setUniformMatrix4f("modelViewProjectionMatrix", modelViewProjectionMatrix);
        
        boidMesh.drawInstanced(OF_MESH_FILL, numBoids);
        renderShader.end();


        ofSetColor(255, 255, 255); 
        ofDrawBitmapString("FPS: " + ofToString(ofGetFrameRate()), 20, 20);
        ofDrawBitmapString("Boids: " + ofToString(numBoids), 20, 40);
        ofDrawBitmapString("Max Force: " + ofToString(maxForce), 20, 60);
        ofDrawBitmapString("Max Speed: " + ofToString(maxSpeed), 20, 80);
        ofDrawBitmapString("Desired Separation: " + ofToString(desiredSeparation), 20, 100);
        ofDrawBitmapString("Neighbor Distance: " + ofToString(neighborDist), 20, 120);

        gui.draw();

        
    }

    void ofApp::keyPressed(int key) {
        if (key == ' ') {
            glBindBuffer(GL_SHADER_STORAGE_BUFFER, positionBuffer);
            glm::vec2* positions = (glm::vec2*)glMapBufferRange(GL_SHADER_STORAGE_BUFFER, 0, numBoids * sizeof(glm::vec2), GL_MAP_WRITE_BIT);
            if (positions) { 
                for (int i = 0; i < numBoids; i++) {
                    positions[i] = glm::vec2(ofRandomWidth(), ofRandomHeight());
                }
                glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);
            }
        }

        if (key == 'r') {
            maxForce = 0.05;
            maxSpeed = 3.0;
            desiredSeparation = 25.0;
            neighborDist = 50.0;

            maxForceSlider = maxForce;
            maxSpeedSlider = maxSpeed;
            desiredSeparationSlider = desiredSeparation;
            neighborDistSlider = neighborDist;
        }

    }

    void ofApp::windowResized(int w, int h) {
        computeShader.begin();
        computeShader.setUniform1f("width", ofGetWidth());  
        computeShader.setUniform1f("height", ofGetHeight());  
        computeShader.end();
    }

shaders/flocking.comp:

.. code-block:: glsl

    #version 430

    layout(std430, binding = 0) buffer BoidPosition {
        vec2 positions[];
    };
    layout(std430, binding = 1) buffer BoidVelocity {
        vec2 velocities[];
    };
    layout(std430, binding = 2) buffer BoidAcceleration {
        vec2 accelerations[];
    };

    uniform int numBoids;
    uniform float maxForce;
    uniform float maxSpeed;
    uniform float desiredSeparation;
    uniform float neighborDist;
    uniform float width;
    uniform float height;

    layout(local_size_x = 512, local_size_y = 1, local_size_z = 1) in;

    void main() {
        uint i = gl_GlobalInvocationID.x;
        if (i >= numBoids) return;

        vec2 position = positions[i];
        vec2 velocity = velocities[i];
        vec2 acceleration = accelerations[i];

        vec2 separateForce = vec2(0.0);
        vec2 alignForce = vec2(0.0);
        vec2 cohesionForce = vec2(0.0);
        int separateCount = 0;
        int alignCount = 0;
        int cohesionCount = 0;

        for (int j = 0; j < numBoids; j++) {
            if (i == j) continue;

            vec2 otherPosition = positions[j];
            vec2 otherVelocity = velocities[j];
            float distance = length(position - otherPosition);

            if (distance < desiredSeparation && distance > 0.0) {
                vec2 diff = normalize(position - otherPosition) / distance;
                separateForce += diff;
                separateCount++;
            }

            if (distance < neighborDist && distance > 0.0) {
                alignForce += otherVelocity;
                cohesionForce += otherPosition;
                alignCount++;
                cohesionCount++;
            }
        }

        if (separateCount > 0) {
            separateForce /= float(separateCount);
        }

        if (length(separateForce) > 0){
            separateForce = normalize(separateForce) * maxSpeed - velocity;
            if (length(separateForce) > maxForce) {
                separateForce = normalize(separateForce) * maxForce;
            }
        }

        if (alignCount > 0) {
            alignForce /= float(alignCount);
            alignForce = normalize(alignForce) * maxSpeed - velocity;
            if (length(alignForce) > maxForce) {
                alignForce = normalize(alignForce) * maxForce;
            }
        }
        else {
            alignForce = vec2(0.0);
        }

        if (cohesionCount > 0) {
            cohesionForce /= float(cohesionCount);

            vec2 desired = cohesionForce - position;
            desired = normalize(desired) * maxSpeed;
            cohesionForce = desired - velocity;
            if (length(cohesionForce) > maxForce) {
                cohesionForce = normalize(cohesionForce) * maxForce;
            }
        }
        else {
            cohesionForce = vec2(0.0);
        }

        acceleration += separateForce * 1.5 + alignForce * 1.0 + cohesionForce * 1.0;
        accelerations[i] = acceleration;

        velocity += acceleration;
        if (length(velocity) > maxSpeed) {
            velocity = normalize(velocity) * maxSpeed;
        }
        velocities[i] = velocity;

        positions[i] += velocity;

        if (positions[i].x < 0.0) positions[i].x += width;
        if (positions[i].y < 0.0) positions[i].y += height;
        if (positions[i].x >= width) positions[i].x -= width;
        if (positions[i].y >= height) positions[i].y -= height;

        accelerations[i] = vec2(0.0);
    }

shaders/render.vert:

.. code-block:: glsl

    #version 430 core

    layout(location = 0) in vec3 vertexPosition;
    layout(location = 1) in vec2 instancePosition;
    layout(location = 2) in vec2 instanceVelocity;

    uniform mat4 modelViewProjectionMatrix;

    void main() {

        float angle = atan(instanceVelocity.x, instanceVelocity.y);
        mat2 rotationMatrix = mat2(cos(angle), -sin(angle), sin(angle), cos(angle));
        vec2 rotatedPosition = rotationMatrix * vertexPosition.xy;
        vec4 position = vec4(rotatedPosition + instancePosition, vertexPosition.z, 1.0);
        gl_Position = modelViewProjectionMatrix * position;
    }

shaders/render.frag:

.. code-block:: glsl

    #version 430

    out vec4 fragColor;

    void main() {
        fragColor = vec4(1.0, 0.0, 0.0, 1.0); 
    }
