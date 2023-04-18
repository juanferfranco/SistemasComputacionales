Unidad 4. Sistema operativo
============================

Introducción
--------------

Llegaste a la última estación de este recorrido a través
de las diferentes capas que componen un sistema de cómputo. Esta unidad 
corresponde al SISTEMA OPERATIVO.

Propósito de aprendizaje
**************************

Comprender algunos conceptos básicos de los servicios que ofrece
el sistema operativo a las aplicaciones de usuario y utilizar
algunos de esos servicios para la construcción de aplicaciones.

Evaluación
-------------------

.. warning:: ¡¡¡MUY IMPORTANTE!!!

    Llegamos al final del recorrido. Este punto también nos marca 
    el último plazo para entregar TODAS las evaluaciones pendientes 
    del curso. ESE PLAZO SERÁ el 12 de mayo de 2023 hasta las 11:40 a.m.

.. warning:: ¡¡¡PLAZO FINAL!!!

    El plazo final para entregar esta y LAS OTRAS evaluaciones 
    es el 12 de mayo de 2023 a las 11:40 a.m. A esa hora deben quedar 
    entregadas y sustentadas TODAS LAS EVALUACIONES. Recuerda que una evaluación 
    está entregada cuando esté TODO lo solicitado en el repositorio y la 
    presentes al profesor. TODO eso debe ocurrir antes de las 11:40 a.m. del 
    12 de mayo de 2023. LUEGO DE ESO NO HAY MÁS PLAZOS.

.. note:: RESULTADO DE APRENDIZAJE DEL CURSO

    ¿Recuerdas el resultado de aprendizaje del curso?

    Aplico los conceptos necesarios para el correcto diseño, implementación, funcionamiento 
    y diagnóstico del software en la producción de sistemas de entretenimiento digital 
    utilizando los procedimientos y herramientas adecuadas según el contexto. 
    NIVEL RESOLUTIVO.

    La idea de esta evaluación es que evidencies que eres capaz de aplicar los 
    conceptos de esta unidad para la solución de los problemas que encontrarás en 
    la construcción de la aplicación interactiva que te propondré. 
    Todos estos conceptos están relacionados con servicios que provee el SISTEMA OPERATIVO.
    
    
    Se espera que puedas evidenciar:

    * Entiendes y aplicas los conceptos de proceso, hilo y un mecanismo de 
      comunicación entre hilos.

    * Eres capaz de diagnosticar y solucionar problemas en el proceso de 
      implementación de la aplicación. 
    
Enunciado 
************

Vas a realizar dos programas. El primero, que llamaremos servir, es una modificación del programa 
de la unidad anterior así:

* Este programa se ejecutará en la terminal.
* Podrá recibir comandos de otros programas, que llamaremos clientes, que se ejecuten en otra 
  terminal.
* También podrá recibir solicitudes locales en su propia terminal.
* Si el programa termina deberá avisarle a los clientes conectados a él y
  estos deberán terminar.

El segundo programa, el cliente:

* Se conectará al servidor desde otra terminal.
* Deberá terminar en caso de que el servidor termine.
* Se pueden ejecutar tantos clientes como se deseen en terminales diferentes.

¿Qué debes entregar?
**********************

.. warning:: MUY IMPORTANTE

    Recuerda que no se recibirán entregas parciales. El problema debe estar 100% solucionado.


Debes entregar todo lo solicitado en 
`este <https://classroom.github.com/a/gNTXzkux>`__ repositorio. Entrega:

* Los códigos con la solución al problema tanto para el cliente como el servidor.
* La documentación en el archivo README.md. Esta documentación debe tener:

    * Un enlace a un video corto en youtube (unlisted) (2 minutos máximo), SIN EXPLICACIONES, que muestre 
      la compilación y ejecución de los programas.
    * Explicar (EN TEXTO) cómo se solucionó el problema tanto para el cliente como para el servidor.


Trayecto de actividades
------------------------

Para realizar los ejercicios y responder las preguntas del trayecto de actividades 
te voy a crear un repositorio. Es muy importante que evidencies tu avance por el trayecto 
dejando toda la evidencia del proceso en este repositorio. 


.. warning:: REPOSITORIO PARA EL TRAYECTO DE ACTIVIDADES

    Para la realización de los ejercicios de la unidad te voy a crear 
    `este <https://classroom.github.com/a/XCkJZAc4>`__ repositorio donde puedas 
    experimentar tu solo. Recuerda que la evaluación de la unidad tendrá su propio repositorio. USA CODESPACES.

Ejercicios preparatorios para el problema
************************************************

Ejercicio 1: concepto de sistema operativo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Qué es un sistema operativo?

En términos generales, un sistema operativo es un SOFTWARE que administra
``RECURSOS de hardware y software del computador`` Y provee servicios mediante
los cuales los programas de usuario pueden hacer uso de esos recursos.

Los siguientes ejercicios explorarán algunos servicios que ofrece el sistema
operativo. La exploración la realizaremos de manera práctica para que luego 
(si te interesa al terminar el curso), puedas profundizar leyendo uno de los 
tantos excelentes libros de sistemas operativos. En particular te recomiendo este:

`Operating Systems: Three Easy Pieces <http://pages.cs.wisc.edu/~remzi/OSTEP/>`__

De todos los posibles servicios que ofrece el sistema operativo, Linux en nuestro
caso, vamos a seleccionar solo algunos que te permitirán resolver posteriormente
la evaluación de esta Unidad.

Ejercicio 2: preguntas sobre los conceptos básicos de los procesos 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora te propondré que busques en Internet información para 
responder las siguientes preguntas:

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
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Hasta ahora todos los programas que has realizado tienen ``un SOLO flujo de instrucciones``. ¿Y si 
quieres tener en el mismo programa ``VARIOS flujos de instrucciones independientes``? Lo puedes hacer 
con los hilos. Los hilos permitirán que un programa pueda ``HACER VARIAS COSAS AL MISMO TIEMPO``.

Ejercicio 4: creación de hilos
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

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

Compila el código así:

.. code-block:: bash

    gcc -Wall main.c -o main -lpthread

Ejecuta el código como siempre, pero esta vez para terminar el programa debes enviar 
la señal ``CRTL+C`` a la terminal.

* ¿Pudiste identificar cuáles son los hilos?
* Explica cómo podría funciona este programa en el computador.

Ejercicio 5: análisis de código con hilos
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

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
este programa tiene 3 hilos.

Ejercicio 6: esperar un hilo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

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

Ejercicio 7: comunicación de procesos mediante colas 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Existe varios mecanismos de comunicación entre procesos. En este ejercicio
te voy a proponer un servicio de comunicación entre procesos denominado POSIX 
queues. Este servicio te permitirá enviar mensajes de un proceso 
a otro.

¿Y si necesitas recibir mensajes en el sentido opuesto? Necesitarás crear 
una segunda queue. Puedes crear tantas queues como el sistema operativo te lo permita.

Ejercicio 8: ejemplo
^^^^^^^^^^^^^^^^^^^^^^^

En este ejemplo comunicarás dos procesos. Uno de ellos esperará los mensajes 
que enviará el otro.

Vas a lanzar, en un terminal, primero el proceso que ejecutará la versión 
ejecutable de este programa:

.. code-block:: c

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <mqueue.h>

    int main(int argc, char *argv[])
    {
        mqd_t mq;

        struct mq_attr attr;
        attr.mq_flags = 0;
        attr.mq_maxmsg = 10;
        attr.mq_msgsize = 32;
        attr.mq_curmsgs = 0;

        mq = mq_open("/mq0", O_RDONLY | O_CREAT, 0644, &attr);
        char buff[32];

        while (1)
        {
            mq_receive(mq, buff, 32, NULL);
            printf("Message received: %s\n", buff);
            if( strncmp(buff, "exit", strlen("exit")) == 0){
                break;
            }
        }

        mq_close(mq);
        mq_unlink("/mq0");
        exit(EXIT_SUCCESS);
    }

Para compilar:

.. code-block:: bash

    gcc -Wall receiver.c -lrt -o receiver

Luego lanza, en una segunda terminal, el proceso que ejecutará la versión 
ejecutable de este programa:

.. code-block:: c

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <mqueue.h>

    int main(int argc, char *argv[])
    {
        mqd_t mq = mq_open("/mq0", O_WRONLY);
        char str[64];

        while (1)
        {
            fgets(str, sizeof(str), stdin);
            if(str[strlen(str) - 1 ] == '\n') str[strlen(str) - 1 ] = 0; 
            mq_send(mq, str, strlen(str) + 1, 0);
            if (strncmp(str, "exit", strlen("exit")) == 0)
            {
                break;
            }
        }

        mq_close(mq);
        exit(EXIT_FAILURE);
    }

Para compilar:

.. code-block:: bash

    gcc -Wall sender.c -lrt -o sender

Ejercicio 9: analiza el ejemplo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Te propongo que analices el ejemplo con estas preguntas:

¿Cómo se crea una cola? La cola la está creando el proceso que ejecuta 
la imagen receiver. Las colas se crean en el sistema operativo y una vez 
se terminen de usuar debes solicitarle al sistema operativo que la destruya.

Para crear una cola necesitarás:

* Guardar en descriptor de la cola en una variable.
* Definir unos atributos para la cola como son la cantidad máxima 
  de mensajes y el tamaño máximo que podría tener un mensaje.

.. code-block:: c

    mqd_t mq;

    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 32;
    attr.mq_curmsgs = 0;

    mq = mq_open("/mq0", O_RDONLY | O_CREAT, 0644, &attr);

¿Cómo acceder a una cola una vez está creada?

.. code-block:: c

    mqd_t mq = mq_open("/mq0", O_WRONLY);

¿Cómo recibir mensajes?

.. code-block:: c

    mq_receive(mq, buff, 32, NULL);

¿Cómo enviar mensajes?

.. code-block:: c

    mq_send(mq, str, strlen(str) + 1, 0);

Una vez termines de usuar la cola debes cerrarla:

.. code-block:: c

    mq_close(mq);

Finalmente uno de los procesos le pedirá al sistema operativo 
que la destruya:

.. code-block:: c

    mq_unlink("/mq0");

Ejercicio 10: mini reto
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Vas a modificar el ejercicio 9 de tal manera que 
los dos procesos puedan intercambiar mensajes. 

Antes de comenzar, piensa primero en esta pregunta:

¿Cómo hacer para que un proceso pueda hacer dos cosas a la vez? 
En este caso los procesos tendrán que esperar a que llegue un mensaje 
a la queue pero también tendrán que esperar a que el usuario ingrese 
un mensaje para enviarlo al otro proceso.

.. warning:: SI NO PIENSAS ESTE EJERCICIO NO PODRÁS RESOLVER LA EVALUACIÓN

    Este ejercicio es crítico para poder resolver la evaluación de la unidad. 
    Te recomiendo que lo hagas antes de comenzar dicho RETO.