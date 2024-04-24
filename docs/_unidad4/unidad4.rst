Unidad 4. Sistema operativo
============================

Introducción
--------------

Llegaste a la última estación de este recorrido a través
de las diferentes capas que componen un sistema de cómputo. Esta unidad 
corresponde al SISTEMA OPERATIVO.

El propósito de esta unidad es que comprendas 
algunos conceptos básicos de los servicios que ofrece
el sistema operativo a las aplicaciones de usuario y apliques
algunos de esos servicios a la aplicación que has venido construyendo.

Duración de esta etapa 
-----------------------

Consulta en la sección :ref:`cronograma` la duración de esta etapa.

Reto 
------

* Usa el lenguaje de programación C, no C++.
* Usa la biblioteca SDL2.
* Usa Visual Studio y el sistema operativo Windows.
* Mantén bajo control de versión tu programa.
* Utiliza el código de la unidad 2 o unidad 3 como punto 
  de partida.

Los requisitos del reto son:
********************************

* Vas a adicionar EFECTOS sonoros a tu Pong, pero tendrás una 
  restricción. Deberás utilizar la técnica con callback del 
  último ejercicio propuesto en la fase de investigación. 
* Deberás garantizar que no se reproduzca un sonido hasta que no 
  termine el actual.
* Utiliza semáforos para sincronizar los hilos de la aplicación, 
  es decir, un hilo debe estar esperando y otro hilo debe indicarle 
  que puede continuar mediante un semáforo.
* Adiciona tantos efectos sonoros como desees, pero incluye al menos 
  estos:

  * Golpear la pelota.
  * Servir la pelota.
  * Ganar un punto.
  * Terminar el juego.
  * Iniciar el juego

Investigación
--------------

.. warning::

    Te propondré algunos ejercicios a partir de los cuales 
    puedes construir tus propios experimentos que reportarás 
    en la bitácora.

Para realizar algunos ejercicios tendrás que utilizar 
CodeSpaces en tu repositorio de GitHub. Yo te indicaré 
cuándo debes hacerlo.

Ten presente que te mostraré los conceptos aplicados en Linux, 
pero en el reto debes evidenciar que eres capaz de trasladar lo 
aprendido a Windows utilizando los servicios adecuados del sistema 
operativo por medio del API que te ofrece la biblioteca SDL2. 

Ejercicio 1: concepto de sistema operativo
********************************************

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

De todos los posibles servicios que ofrece el sistema operativo, Linux en 
nuestro caso, vamos a seleccionar solo algunos que te permitirán 
resolver posteriormente el reto de esta Unidad.

Ejercicio 2: preguntas sobre los conceptos básicos de los procesos 
*******************************************************************

Ahora te propondré que busques en Internet información para 
responder las siguientes preguntas (puedes hablar con algún 
modelo de lenguaje si lo prefieres):

* ¿Cuál es la diferencia entre un programa y un proceso?
* ¿Puedo tener múltiples procesos corriendo el mismo programa?
* ¿Para qué sirve el stack de un proceso?
* ¿Para qué sirve el heap de un proceso?
* ¿Qué es la zona de texto de un proceso?
* ¿Dónde se almacenan las variables globales inicializadas?
* ¿Dónde se almacenan las variables globales no inicializadas?
* ¿Cuáles son los posibles estados de un proceso en general? Ten en cuenta
  que esto varía entre sistemas operativos.

Ejercicio 3: concepto de hilo 
********************************************

Hasta ahora todos los programas que has realizado tienen 
``un SOLO flujo de instrucciones``. ¿Y si quieres tener en el 
mismo programa ``VARIOS flujos de instrucciones independientes``? 
Lo puedes hacer con los hilos. Los hilos permitirán que un programa 
pueda ``HACER VARIAS COSAS AL MISMO TIEMPO``, cada cosa con hilo 
independiente. Ten presente que los hilos compartirán recursos del 
proceso entre ellos estará el HEAP; sin embargo, cada hilo tendrá 
su propio STACK.

Ejercicio 4: creación de hilos
********************************************

.. warning::

    Este ejercicio lo debes realizar en CodeSpaces.

El siguiente programa tiene dos hilos. ¿Qué código ejecuta cada hilos?

.. code-block:: c

    #include <stdio.h>
    #include <stdlib.h>
    #include <pthread.h>

    void* imprime_x(void *param){
        while(1) printf("x");
        return NULL;
    }


    int main(int argc, char *argv[]){
        pthread_t threadID;
        pthread_create(&threadID,NULL,&imprime_x,NULL);
        while(1) printf("o");
        exit(EXIT_SUCCESS);
    }

Compila el código así (recuerda, en el CodeSpace):

.. code-block:: bash

    gcc -Wall main.c -o main -lpthread

Ejecuta el código como siempre, pero esta vez para terminar el programa 
debes enviar la señal ``CRTL+C`` a la terminal.

* ¿Pudiste identificar cuáles son los hilos?
* Explica cómo podría funciona este programa en el computador.

Ejercicio 5: análisis de código con hilos
********************************************

.. warning::

    Este ejercicio lo debes realizar en CodeSpaces.

Ahora vas a escribir este código, compilarlo y ejecutarlo:

.. code-block:: c

    #include <stdio.h>
    #include <stdlib.h>
    #include <pthread.h>

    struct threadParam_t
    {
        char character;
        int counter;
    };


    void* imprime(void *parg){
        struct threadParam_t *pargTmp = (struct threadParam_t *)parg;
        for(int i = 0; i < pargTmp->counter;i++){
            printf("%c",pargTmp->character);
        }
        return NULL;
    }


    int main(int argc, char *argv[]){
        pthread_t threadID1;
        pthread_t threadID2;

        struct threadParam_t threadParam1 = {'a',30000};
        struct threadParam_t threadParam2 = {'b',20000};

        pthread_create(&threadID1,NULL,&imprime, &threadParam1);
        pthread_create(&threadID2,NULL,&imprime, &threadParam2);

        exit(EXIT_SUCCESS);
    }

* ¿Qué pasó al ejecutarlo? 
* Notaste que el programa no hace nada, te animas a proponer un hipótesis 
  al respecto de lo que puede estar ocurriendo?
  
NO TE PREOCUPES, ya te digo qué pasa en el ejercicio siguiente, PERO te 
invito a que te animes ha pensar una posible explicación. Te doy una pista, 
este programa tiene 3 hilos y uno de ellos, el principal, está terminando 
primero que los otros de ejecutar todas sus instrucciones.

Ejercicio 6: esperar un hilo
********************************************

.. warning::

    Este ejercicio lo debes realizar en CodeSpaces.

El problema con el código anterior es que el proceso está terminando antes 
que los hilos puedan comenzar incluso a funcionar (porque termina 
el hilo principal). Por tanto, será necesario 
que el hilo principal espere a que los dos hilos creados terminen antes de 
que el mismo pueda terminar. 

.. code-block:: c

    #include <stdio.h>
    #include <stdlib.h>
    #include <pthread.h>

    struct threadParam_t
    {
        char character;
        int counter;
    };


    void* imprime(void *parg){
        struct threadParam_t *pargTmp = (struct threadParam_t *)parg;
        for(int i = 0; i < pargTmp->counter;i++){
            printf("%c",pargTmp->character);
        }
        return NULL;
    }


    int main(int argc, char *argv[]){
        pthread_t threadID1;
        pthread_t threadID2;

        struct threadParam_t threadParam1 = {'a',30000};
        struct threadParam_t threadParam2 = {'b',20000};

        pthread_create(&threadID1,NULL,&imprime, &threadParam1);
        pthread_create(&threadID2,NULL,&imprime, &threadParam2);

        pthread_join(threadID1,NULL);
        pthread_join(threadID2,NULL);

        exit(EXIT_SUCCESS);
    }

* ¿Qué debes hacer para esperara a que un hilo en particular termine? 
  (la respuesta está en el código anterior. Solo necesito que seas 
  consciente de lo que se debe hacer).
* Considera los siguientes fragmentos de código y piensa cuál puede ser la 
  diferencia entre ambos:

.. code-block:: c

    pthread_create(&threadID1,NULL,&imprime, &threadParam1);
    pthread_join(threadID1,NULL);
    pthread_create(&threadID2,NULL,&imprime, &threadParam2);
    pthread_join(threadID2,NULL);


.. code-block:: c

    pthread_create(&threadID1,NULL,&imprime, &threadParam1);
    pthread_create(&threadID2,NULL,&imprime, &threadParam2);
    pthread_join(threadID1,NULL);
    pthread_join(threadID2,NULL);

Recuerda que el hilo que ejecute un join, en este caso el principal, 
será bloqueado, no podrá seguir, hasta que el hilo que está esperando 
termine. Entonces dicho esto piensa de nuevo ¿Cuál puede ser 
la diferencia entre los programas anteriores?

Ejercicio 7: para pensar 
********************************************

.. warning::

    Este ejercicio lo debes realizar en Windows con SDL2.


Vas a buscar en Internet información sobre SDL2 relacionada con:

* ¿Cómo se crea un hilo?
* Busca e implementa un ejemplo que cree un hilo con SDL2.
* ¿Cuál es el equivalente de join en el API de SDL2?
* Busca e implementa un ejemplo.
* ¿Para qué sirven los semáforos en SDL2?
* Busca e implementa un ejemplo que use un semáforo 
  para evitar una condición de carrera. ¿Qué es una 
  condición de carrera?
* Busca e implementa un ejemplo que use un semáforo 
  para sincronizar dos hilos.
 
Ejercicio 8: ejemplo de referencia para el reto   
********************************************************

.. warning::

    Este ejercicio lo debes realizar en Windows con SDL2.

En este ejemplo te voy a mostrar cómo se puede reproducir un 
sonido usando SDL2.

Para poder reproducir este ejemplo necesitarás un archivo de audio. 
Puedes descargar `este <https://github.com/juanferfranco/SistemasComputacionales/tree/main/docs/_static/tap.wav>`__. 

Aquí está el código:

.. code-block:: c

    #include <stdio.h>
    #include <stdbool.h>
    #include <SDL.h>
    #include "./constants.h"
    #include <SDL_audio.h>

    typedef struct {
        Uint8* audioData; // Pointer to audio data
        Uint32 audioLength; // Length of audio data in bytes
        Uint32 audioPosition; // Current position in audio data
        SDL_bool audioFinished;
    } AudioContext;


    void AudioCallback(void* userdata, Uint8* stream, int len) {
        AudioContext *audioContext = (AudioContext*)userdata;

        if (audioContext->audioPosition >= audioContext->audioLength) {
            audioContext->audioFinished = SDL_TRUE;
            return;
        }


        // Calculate the amount of data to copy to the stream
        int remainingBytes = audioContext->audioLength - audioContext->audioPosition;
        int bytesToCopy = (len < remainingBytes) ? len : remainingBytes;

        // Copy audio data to the stream
        SDL_memcpy(stream, audioContext->audioData + audioContext->audioPosition, bytesToCopy);

        // Update the audio position
        audioContext->audioPosition += bytesToCopy;

    }


    void play_audio(void){
        static uint8_t isaudioDeviceInit = 0;
        static SDL_AudioSpec audioSpec;
        static SDL_AudioDeviceID audioDevice = 0;
        static AudioContext audioContext;

        if (isaudioDeviceInit == 0) {
            /*
            audioSpec.freq = 44100;
            audioSpec.format = AUDIO_S16SYS;
            audioSpec.channels = 1;
            audioSpec.samples = 2048;
            */

            audioSpec.callback = AudioCallback;
            audioSpec.userdata = &audioContext;

            audioDevice = SDL_OpenAudioDevice(NULL, 0, &audioSpec, NULL, 0);
            if (audioDevice == 0) {
                printf("Unable to open audio device: %s\n", SDL_GetError());
                return 1;
            }
            isaudioDeviceInit = 1;
        }

        audioContext.audioPosition = 0;
        audioContext.audioFinished = SDL_FALSE;
        if (SDL_LoadWAV("tap.wav", &audioSpec, &audioContext.audioData, &audioContext.audioLength) != NULL) {
            SDL_PauseAudioDevice(audioDevice, 0); // Start audio playback
        }
        else {
            printf("Unable to load WAV file: %s\n", SDL_GetError());
        }

        while (audioContext.audioFinished != SDL_TRUE) {
            SDL_Delay(100);
        }

        printf("Audio finished\n");
        SDL_CloseAudio(audioDevice);
        SDL_FreeWAV(audioContext.audioData); // Free the loaded WAV data
    }


    int game_is_running = false;
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    int last_frame_time = 0;

    struct game_object {
        float x;
        float y;
        float width;
        float height;
        float vel_x;
        float vel_y;
    } ball, paddle;

    int initialize_window(void) {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            fprintf(stderr, "Error initializing SDL.\n");
            return false;
        }
        window = SDL_CreateWindow(
            NULL,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            WINDOW_WIDTH,
            WINDOW_HEIGHT,
            SDL_WINDOW_BORDERLESS
        );
        if (!window) {
            fprintf(stderr, "Error creating SDL Window.\n");
            return false;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (!renderer) {
            fprintf(stderr, "Error creating SDL Renderer.\n");
            return false;
        }
        return true;
    }

    void process_input(void) {
        SDL_Event event;
        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                game_is_running = false;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    game_is_running = false;
                if (event.key.keysym.sym == SDLK_LEFT)
                    paddle.vel_x = -400;
                if (event.key.keysym.sym == SDLK_RIGHT)
                    paddle.vel_x = +400;
                break;
            case SDL_KEYUP:
                if (event.key.keysym.sym == SDLK_LEFT)
                    paddle.vel_x = 0;
                if (event.key.keysym.sym == SDLK_RIGHT)
                    paddle.vel_x = 0;
                if (event.key.keysym.sym == SDLK_p) {
                    play_audio();
                }

                break;
        }
    }

    void setup(void) {
        // Initialize values for the the ball object
        ball.width = 15;
        ball.height = 15;
        ball.x = 20;
        ball.y = 20;
        ball.vel_x = 300;
        ball.vel_y = 300;

        // Initialize the values for the paddle object
        paddle.width = 100;
        paddle.height = 20;
        paddle.x = (WINDOW_WIDTH / 2) - (paddle.width / 2);
        paddle.y = WINDOW_HEIGHT - 40;
        paddle.vel_x = 0;
        paddle.vel_y = 0;
    }

    void update(void) {
        // Calculate how much we have to wait until we reach the target frame time
        int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);

        // Only delay if we are too fast too update this frame
        if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME)
            SDL_Delay(time_to_wait);

        // Get a delta time factor converted to seconds to be used to update my objects
        float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0;

        // Store the milliseconds of the current frame
        last_frame_time = SDL_GetTicks();

        // update ball and paddle position
        ball.x += ball.vel_x * delta_time;
        ball.y += ball.vel_y * delta_time;
        paddle.x += paddle.vel_x * delta_time;
        paddle.y += paddle.vel_y * delta_time;

        // Check for ball collision with the walls
        if (ball.x <= 0 || ball.x + ball.width >= WINDOW_WIDTH)
            ball.vel_x = -ball.vel_x;
        if (ball.y < 0)
            ball.vel_y = -ball.vel_y;

        // Check for ball collision with the paddle
        if (ball.y + ball.height >= paddle.y && ball.x + ball.width >= paddle.x && ball.x <= paddle.x + paddle.width)
            ball.vel_y = -ball.vel_y;

        // Prevent paddle from moving outside the boundaries of the window
        if (paddle.x <= 0)
            paddle.x = 0;
        if (paddle.x >= WINDOW_WIDTH - paddle.width)
            paddle.x = WINDOW_WIDTH - paddle.width;

        // Check for game over
        if (ball.y + ball.height > WINDOW_HEIGHT) {
            ball.x = WINDOW_WIDTH / 2;
            ball.y = 0;
        }
    }

    void render(void) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw a rectangle for the ball object
        SDL_Rect ball_rect = {
            (int)ball.x,
            (int)ball.y,
            (int)ball.width,
            (int)ball.height
        };
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &ball_rect);

        // Draw a rectangle for the paddle object
        SDL_Rect paddle_rect = {
            (int)paddle.x,
            (int)paddle.y,
            (int)paddle.width,
            (int)paddle.height
        };
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &paddle_rect);

        SDL_RenderPresent(renderer);
    }

    void destroy_window(void) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    int main(int argc, char* args[]) {

        game_is_running = initialize_window();
        setup();

        while (game_is_running) {
            process_input();
            update();
            render();
        }

        destroy_window();

        return 0;
    }

La actividad es:

* Crea una proyecto donde veas en funcionamiento el programa.
* Analiza el programa para determinar qué condición se requiere 
  para que el programa reproduzca el sonido?
* Analiza con detenimiento el código e identifica las partes 
  necesarias para reproducir el sonido.
* Observa qué pasa cuando se reproduce el sonido. ¿Identificas 
  el problema?
* Cómo crees que puedas solucionar el problema del programa? Recuerda 
  los ejercicios que has realizado en esta unidad. ¿Hiciste 
  el ejercicio 7? 
* Soluciona el problema que tiene el programa, pero sin utilizar 
  una API diferente de audio de SDL2, es decir, no debes usar 
  la función SDL_QueueAudio y DEBES garantizar que el programa 
  reproducirá un sonido a la vez. 
* Usa un semáforo para sincronizar los hilos de tu programa. 
  ¿Qué es lo que debes sincronizar? (ten presente que una 
  parte del programa debe detectar el evento y avisarle a otra 
  parte del programa que debe reproducir un sonido). Explica 
  por qué y cómo el semáforo te ayuda a solucionar 
  el problema de sincronización.

Aplicación 
-----------

¿Ya has realizado los ejercicios preparatorios? Si es así, 
entonces estás listo para comenzar la aplicación de los 
conceptos aprendidos en la solución del reto de esta 
unidad.

Antes de comenzar a programar, te propongo que escribas 
cómo vas a resolver el reto. Verbaliza la solución y 
una vez lo tengas claro implementa la solución. 

Compartir
-----------

En compartir evidencias los resultados de aprendizaje. Te los recuerdo:

RAE 1
*******

Construyo aplicaciones interactivas aplicando patrones y estrategias 
que permitan alcanzar los requisitos funcionales y no funcionales 
establecidos.

Se espera que llegues a un nivel resolutivo.

Las evidencias para el RAE1 son:

#. Muestras una aplicación funcional que cumple con todos 
   los requisitos establecidos.
#. Explicas cómo solucionaste cada requisito de la aplicación.

RAE 2
*******

Aplico pruebas de las partes y del todo de un software siguiendo 
metodologías, técnicas y estándares de la industria para 
garantizar el correcto funcionamiento de las aplicaciones.

Se espera que llegues a un nivel autónomo.

Las evidencias para el RAE2 son:

#. Muestras cómo probaste cada requisito por separado.
#. Muestras cómo probaste que la aplicación funciona 
   integrada, con todos los requisitos.




