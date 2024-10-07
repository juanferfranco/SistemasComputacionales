Experiencia de aprendizaje 7. Gráficas
===========================================

Introducción
--------------

En esta unidad vas interactuar con un dispositivo del computador que te permite 
pintar en pantalla a altas velocidades. Este dispositivo es la tarjeta gráfica 
o Graphics Processing Unit (GPU). La GPU es un dispositivo que se encarga de procesar 
y enviar señales de video a la pantalla del computador. Es un dispositivo 
especializado en procesar gráficos y video. Aunque actualmente también se usa, y 
mucho, para trabajar con inteligencia artificial y aprendizaje profundo.

La idea de esta experiencia de aprendizaje es que te familiarices con los conceptos 
básicos de la programación de la GPU, es decir, que experimentes a nivel introductorio 
con shaders y que además veas cómo comunicar la CPU con la GPU para realizar 
aplicaciones interactivas.

Investigación 
---------------

Para la fase de investigación te vas a concentrar en el tutorial Introducing Shaders
hecho por Lucasz Karluk, Joshua Noble y Jordi Puig. Este es un tutorial oficial 
del material de aprendizaje de openframeworks. Ten presente que todos los ejemplos 
que se presentan en este tutorial están la carpeta examples/shaders numerados del 
01 al 09.


Actividad 1
**************

.. warning:: ¿Cómo sacar el máximo de los videos educativos?

    * Mira el video una vez.
    * Luego, de memoria, trata de listar los conceptos fundamentales y hacer 
      un resumen de estos. Puedes también hacer diagramas o mapas conceptuales. 
      Trata de conectar estos con conceptos que ya conoces.
    * Observa por segunda vez el video y compara tus notas con lo que el video 
      presenta.
    * Busca material para realizar experimentos donde puedas ver aplicados 
      los conceptos que has aprendido. Los experimentos tienen otra bondad, y 
      es que te permiten hacer la pregunta mágica: ¿Qué pasa si...?
    * ¿Qué pasa si cambio este parámetro? ¿Qué pasa si cambio este otro? ¿Qué pasa 
      si ...? Cada pregunta te propondrá que generes una hipótesis y que la pongas 
      a prueba. Esto es lo que se llama el método científico. Y es una de las 
      mejores maneras de aprender.
    * Si algún experimento no genera el resultad que esperabas, no te preocupes. 
      Todo lo contrario, en un motivo para celebrar. Has encontrado algo nuevo.   
      Tienes una oportunidad de aprender algo nuevo.  


Ya conoces cómo funciona un CPU, ahora es momento de aprender cómo funciona una GPU. 
Mira este `video <https://youtu.be/-P28LKWTzrI?si=YM7OOn7B2eJ7uLGk>`__ y tendrás una 
buena idea.

Ahora dale una mira a este `video <https://youtu.be/C8YtdC8mxTU?si=710jq1R2Z88m4jtz>`__ 
donde podrás ver un poco más profundo cómo funciona una GPU.

Te voy plantear algunas preguntas para que reflexiones sobre lo que acabas de ver. 
Recuerda que puedes conversar con ChatGPT para profundizar y aclarar tus dudas, pero 
antes de pedirle una respuesta intenta responderlas por ti mismo y luego compara tus
respuestas con las de ChatGPT. Si ves que hay diferencias, intenta entender por qué 
hay diferencias.

* ¿Qué son los vértices?
* ¿Con qué figura geométrica se dibuja en 3D?
* ¿Qué es un shader?
* ¿Cómo se le llaman a los grupos de pixeles de un mismo triángulo?
* ¿Qué es un fragment shader?
* ¿Qué es un vertex shader?
* ¿Al proceso de determinr qué pixels del display va a cubrir cada triángulo de una mesh 
  se le llama? 
* ¿Qué es el render pipeline?
* ¿Hay alguna diferencia entre aplicar un color a una superficie de una mesh 
  o aplicar una textura?
* ¿Cuál es la diferencia entre una textura y un material?
* ¿Qué transformaciones se requieren para mover un vértice del 3D world al View Screen?
* Al proceso de convertir los triángulos en fragmentos se le llama?
* ¿Qué es el framebuffer?
* ¿Para qué se usa el Z-buffer o depth buffer en el render pipeline?

Luego de ver el segundo video entiendes por qué la GPU tiene que funcionar tan rápido 
y de manera paralela. ¿Por qué?

¿Te gustaron los videos? Hay uno más que te podría llamar la atención. Te propongo 
que sigas con las demás actividades, pero si tienes tiempo y ganas, mira 
`este <https://youtu.be/iOlehM5kNSk?si=yBRNVjRU3lULY0hr>`__ video más adelante.

Actividad 2
**************

Comienza realizando las lectura de la introducción del tutorial 
`Introducing Shaders <https://openframeworks.cc/ofBook/chapters/shaders.html>`__. 
Realiza la sección Your First Shader, pero antes de ejecutar el código, realiza 
un pequeño experimento. Modifica ligeramente el método draw:

.. code-block:: c++

    void ofApp::draw(){
        ofSetColor(255);
        
        //shader.begin();
        
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        
        //shader.end();
    }

Observa la salida.

Ahora ejecuta el código original. ¿Qué resultados obtuviste?


* ¿Cómo funciona?
* ¿Qué resultados obtuviste?
* ¿Estás usando un vertex shader?
* ¿Estás usando un fragment shader?
* Analiza el código de los shaders. ¿Qué hace cada uno?

Actividad 3
**************

Ahora vas pasar información personalizada de tu programa a los shaders. 
Vas a leer con detenimiento el tutorial Adding Uniforms.

* ¿Qué es un uniform?
* ¿Cómo funciona el código de aplicación, los shaders y cómo se comunican estos?

Modifica el código de la actividad para modificar el color de cada uno 
de los pixeles de la pantalla modificando el fragment shader.

Actividad 4
**************

Vas a realizar la última actividad de esta experiencia de aprendizaje. Yo se 
que quieres seguir haciendo más, pero tenemos un tiempo muy limitado.

Analiza el ejemplo Adding some interactivity. 

* ¿Qué hace el código del ejemplo?
* ¿Cómo funciona el código de aplicación, los shaders y cómo se comunican estos?

* Realiza modificaciones a ofApp.cpp y al vertex shader para conseguir otros 
  comportamientos.
* Realiza modificaciones al fragment shader para conseguir otros comportamientos.

Reto 
------

Con lo que aprendiste en esta unidad vas a realizar una aplicación interactiva 
que utilice shaders. 

.. warning:: No uses ChatGPT esta vez.

    Con los conocimientos que has adquirido en esta unidad, realiza la aplicación
    interactiva que se describe a continuación. No uses ChatGPT para realizar esta
    actividad. Regálate la oportunidad de aplicar lo que has aprendido. Experimenta 
    y diviértete. 

Requisitos
***********

* Utilizando **C++** y **openFrameworks**. 
* Modifica los vértices de una malla en el vertex shader.
* Modifica los colores de los fragmentos en el fragment shader.

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
* Vas a explicar detalladamente cómo funciona la aplicación.
* El código fuente de tu aplicación.
* Un ENLACE a un video que muestre en funcionamiento la aplicación.

El RAE2 lo evidenciarás con:

* Explica y muestra cómo probaste la aplicación en ofApp.cpp.
* Explica y muestra cómo probaste el vertex shader.
* Explica y muestra cómo probaste el fragment shader.
* Explica y muestra cómo probaste toda la aplicación completa.

..
    Estas son algunas actividades interesantes que no serán incluidas en este release del curso:


    Actividad 
    **********

    Explorar el concepto de mesh, vértices e índices.






    Actividad
    ************

    Explorar el concepto de mesh, vértices, indices y colores.

    Pregunta guía de investigación:

    ¿Por qué se ven los colores de las superficies del icosaedro 
    no son sólidas sino con gradientes?

    .. code-block:: c++

        #pragma once

        #include "ofMain.h"

        class ofApp : public ofBaseApp {
        public:
            void setup();
            void update();
            void draw();

            ofEasyCam cam; // Cámara fácil para manipular la vista
            ofMesh icosahedronMesh; // Malla para el icosaedro
            vector<ofColor> faceColors; // Colores para cada cara del icosaedro
        };

    .. code-block:: c++

        #include "ofApp.h"

        void ofApp::setup() {
            // Crear un icosaedro de radio 200
            const int X = 158;
            const int Z = 256;
            vector<ofVec3f> vertices = {
                ofVec3f(-X, 0.0, Z), ofVec3f(X, 0.0, Z), ofVec3f(-X, 0.0, -Z), ofVec3f(X, 0.0, -Z),
                ofVec3f(0.0, Z, X), ofVec3f(0.0, Z, -X), ofVec3f(0.0, -Z, X), ofVec3f(0.0, -Z, -X),
                ofVec3f(Z, X, 0.0), ofVec3f(-Z, X, 0.0), ofVec3f(Z, -X, 0.0), ofVec3f(-Z, -X, 0.0)
            };

            // Definir los índices de los triángulos del icosaedro
            vector<ofIndexType> indices = {
                0, 4, 1,    0, 9, 4,    9, 5, 4,    4, 5, 8,    4, 8, 1,
                8, 10, 1,   8, 3, 10,   5, 3, 8,    5, 2, 3,    2, 7, 3,
                7, 10, 3,   7, 6, 10,   7, 11, 6,   11, 0, 6,   0, 1, 6,
                6, 1, 10,   9, 0, 11,   9, 11, 2,   9, 2, 5,    7, 2, 11
            };

            for (auto& v : vertices) {
                icosahedronMesh.addVertex(v);
            }

            for (auto& i : indices) {
                icosahedronMesh.addIndex(i);
            }

            int numTriangles = indices.size() / 3;
            for (int i = 0; i < numTriangles; ++i) {
                faceColors.push_back(ofColor::fromHsb(ofRandom(255), 255, 255)); // Color aleatorio
            }
        
            for (int i = 0; i < numTriangles; ++i) {
                ofColor color = faceColors[i];
                icosahedronMesh.addColor(color); 
                icosahedronMesh.addColor(color); 
                icosahedronMesh.addColor(color); 
            }
            ofEnableDepthTest();
        }

        //--------------------------------------------------------------
        void ofApp::update() {
        }

        //--------------------------------------------------------------
        void ofApp::draw() {
            ofBackground(0);
            cam.begin();
            icosahedronMesh.enableColors();
            icosahedronMesh.drawFaces();
            cam.end();
        }

    Para lograr colores sólidos en cada cara del icosaedro sin que aparezcan gradientes, 
    es necesario asegurar que los vértices de cada cara no compartan información de color con 
    los vértices de otras caras.

    El problema surge porque en una malla los vértices pueden ser compartidos entre varios 
    triángulos. Al asignar un color por vértice, y ese vértice es usado por múltiples triángulos, 
    se obtienen gradientes, ya que cada triángulo puede tener un color diferente en los 
    vértices compartidos.

    Solución: cada triángulo debe tener sus propios sus vértices. De esa manera cada vértice 
    tendrá el mismo color y al renderizar el triángulo se verá con un color sólido.

    En este caso se logra el efecto deseado:

    .. code-block:: c++

        #include "ofApp.h"

        void ofApp::setup() {
            // Crear un icosaedro de radio 200
            const int X = 158;
            const int Z = 256;

            vector<ofVec3f> vertices = {
                ofVec3f(-X, 0.0, Z), ofVec3f(X, 0.0, Z), ofVec3f(-X, 0.0, -Z), ofVec3f(X, 0.0, -Z),
                ofVec3f(0.0, Z, X), ofVec3f(0.0, Z, -X), ofVec3f(0.0, -Z, X), ofVec3f(0.0, -Z, -X),
                ofVec3f(Z, X, 0.0), ofVec3f(-Z, X, 0.0), ofVec3f(Z, -X, 0.0), ofVec3f(-Z, -X, 0.0)
            };

            vector<ofIndexType> indices = {
                0, 4, 1,    0, 9, 4,    9, 5, 4,    4, 5, 8,    4, 8, 1,
                8, 10, 1,   8, 3, 10,   5, 3, 8,    5, 2, 3,    2, 7, 3,
                7, 10, 3,   7, 6, 10,   7, 11, 6,   11, 0, 6,   0, 1, 6,
                6, 1, 10,   9, 0, 11,   9, 11, 2,   9, 2, 5,    7, 2, 11
            };

            int numTriangles = indices.size() / 3;
            for (int i = 0; i < numTriangles; ++i) {
                faceColors.push_back(ofColor::fromHsb(ofRandom(255), 255, 255)); // Color aleatorio
            }

            for (int i = 0; i < indices.size(); i += 3) {
                ofVec3f v1 = vertices[indices[i]];
                ofVec3f v2 = vertices[indices[i + 1]];
                ofVec3f v3 = vertices[indices[i + 2]];
                icosahedronMesh.addVertex(v1);
                icosahedronMesh.addVertex(v2);
                icosahedronMesh.addVertex(v3);
                ofColor color = faceColors[i / 3];
                icosahedronMesh.addColor(color);
                icosahedronMesh.addColor(color);
                icosahedronMesh.addColor(color);
            }
            ofEnableDepthTest();
        }

        //--------------------------------------------------------------
        void ofApp::update() {
        }

        //--------------------------------------------------------------
        void ofApp::draw() {
            ofBackground(0);
            cam.begin();
            icosahedronMesh.enableColors();
            icosahedronMesh.drawFaces();
            cam.end();
        }

    Actividad
    *************

    Explorar el concepto de Depth test a la hora de dibujar.

    En el siguiente programa:


    .. code-block:: c++

        #pragma once

        #include "ofMain.h"

        class ofApp : public ofBaseApp {
        public:
            void setup();
            void update();
            void draw();

            ofEasyCam cam; // Cámara fácil para manipular la vista
            ofMesh icosahedronMesh; // Malla para el icosaedro
            vector<ofColor> faceColors; // Colores para cada cara del icosaedro
        };


    .. code-block:: c++

        #include "ofApp.h"

        void ofApp::setup() {
            // Crear un icosaedro de radio 200
            const int X = 158;
            const int Z = 256;

            vector<ofVec3f> vertices = {
                ofVec3f(-X, 0.0, Z), ofVec3f(X, 0.0, Z), ofVec3f(-X, 0.0, -Z), ofVec3f(X, 0.0, -Z),
                ofVec3f(0.0, Z, X), ofVec3f(0.0, Z, -X), ofVec3f(0.0, -Z, X), ofVec3f(0.0, -Z, -X),
                ofVec3f(Z, X, 0.0), ofVec3f(-Z, X, 0.0), ofVec3f(Z, -X, 0.0), ofVec3f(-Z, -X, 0.0)
            };

            vector<ofIndexType> indices = {
                0, 4, 1,    0, 9, 4,    9, 5, 4,    4, 5, 8,    4, 8, 1,
                8, 10, 1,   8, 3, 10,   5, 3, 8,    5, 2, 3,    2, 7, 3,
                7, 10, 3,   7, 6, 10,   7, 11, 6,   11, 0, 6,   0, 1, 6,
                6, 1, 10,   9, 0, 11,   9, 11, 2,   9, 2, 5,    7, 2, 11
            };

            int numTriangles = indices.size() / 3;
            for (int i = 0; i < numTriangles; ++i) {
                faceColors.push_back(ofColor::fromHsb(ofRandom(255), 255, 255)); // Color aleatorio
            }

            for (int i = 0; i < indices.size(); i += 3) {
                ofVec3f v1 = vertices[indices[i]];
                ofVec3f v2 = vertices[indices[i + 1]];
                ofVec3f v3 = vertices[indices[i + 2]];
                icosahedronMesh.addVertex(v1);
                icosahedronMesh.addVertex(v2);
                icosahedronMesh.addVertex(v3);
                ofColor color = faceColors[i / 3];
                icosahedronMesh.addColor(color);
                icosahedronMesh.addColor(color);
                icosahedronMesh.addColor(color);
            }
            ofEnableDepthTest();
        }

        //--------------------------------------------------------------
        void ofApp::update() {
        }

        //--------------------------------------------------------------
        void ofApp::draw() {
            ofBackground(0);
            cam.begin();
            icosahedronMesh.enableColors();
            icosahedronMesh.drawFaces();
            cam.end();
        }


    ¿Qué pasa si usas ofEnableDepthTest y si luego lo comentas?

    ofEnableDepthTest() en openFrameworks habilita el test de profundidad o depth testing, 
    que es una técnica usada en gráficos 3D para asegurarse de que los objetos más cercanos a 
    la cámara se dibujen encima de los que están más lejos, logrando una correcta visualización 
    tridimensional.

    Actividad
    *************

    Explorar el concepto de texturizar una primitiva.

