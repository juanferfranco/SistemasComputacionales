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

.. warning:: ESTA EVALUACIÓN ES UN RETO!!!

    Esta evaluación busca que demuestres tu capacidad de integrar los conceptos 
    que trabajaste en el curso. ES UN RETO y necesitarás creatividad 
    para solucionarlo. PIENSA MUCHO primero, luego programa. Ten en cuenta 
    que es una RETO para PENSAR en la solución no para BUSCARLA.


.. warning:: FECHA DE ENTREGA Y SUSTENTACIÓN 

    La evaluación debe estar sustentada y entregada en el repositorio 
    el día 4 de noviembre de 2022 finalizando la sesión de clase.

    El viernes 4 de noviembre al finalizar la sesión de clase FINALIZA el curso.
    Finalizan todos los plazos. No se aceptarán más entregas luego de este plazo 
    MÁXIMO.

    Recuerda conformar tu equipo de trabajo.

Enunciado 
************

Vas a utilizar lo aprendido en las unidades 2, 3 y 4. De la unidad 1 tomarás la implementación 
de la lista enlazada. De la unidad 3 tomarás el caso de estudio del patrón observer. Y de la unidad 
4 el mecanismo de comunicación por colas POSIX y los hilos.

Vas a implementar dos programas: un servidor y un cliente. En ejecución solo tendrás un servidor 
o publicador (con su propia terminal). Tendrás un número arbitrario de clientes o suscriptores (de ahí la necesidad de usar  
una estructura de datos dinámica como la lista enlazada) cada uno con su propia terminal.

La idea es que crees eventos en el servidor que podrás guardar en una lista enlazada. Para crear un evento 
solo tienes que asignarle un nombre. A cada evento podrán suscribirse los clientes que deseen hacerlo. 
Cada cliente puede retirar la suscripción a un evento. Ten presente que cada evento tendrá que mantener 
una lista de interesados. Para publicar un evento tendrás que darle la orden al servidor desde la terminal y 
este enviará el evento a cada cliente suscrito.

Características del servidor:

* El servidor debe ser capaz de atender al mismo tiempo las órdenes que le darás desde la terminal 
  y las solicitudes que le enviarán los clientes.
* Cada petición de un cliente será visualizada con un mensaje en la terminal que incluirá un identificador del
  cliente y el mensaje de la petición.
* Las órdenes que le darás al servidor serán:
  
  * Listar la cantidad de eventos que puede publicar.
  * Crear un evento.
  * Publicar un evento.
  * Borrar un evento.
  * Muestra los clientes o suscriptores conectados.
  * Terminar. El servidor termina, pero antes debe avisarle a todos los cliente conectados para 
    que ellos también terminen.

Características de cada cliente:

* Debe visualizar en la terminal cada que evento publicado por el servidor.
* Cada cliente debe ser capaz de atender al mismo tiempo las órdenes que le darás desde la terminal y 
  los mensajes enviados por el servidor.
* Debe soportar las siguientes órdenes:

    * Suscribirse a un evento.
    * Retirar la suscripción a un evento.
    * Listar todos los eventos a los que está suscrito.
    * Preguntarle al servidor todos los eventos que hay disponibles.

¿Qué debes entregar?
**********************

.. warning:: MUY IMPORTANTE

    No se recibirán entregas parciales. El problema debe estar 100% solucionado.


Debes entregar todo lo solicitado en 
`este <https://classroom.github.com/a/5cv9ZIs2>`__ repositorio. Entrega:

* El código con la solución al problema.
* La documentación en el archivo README.md. Esta documentación debe tener:

    * Un enlace a un video corto en youtube (unlisted) (2 minutos máximo), SIN EXPLICACIONES, que muestre 
      la compilación y ejecución del caso de estudio.
    * Explicar (EN TEXTO) cómo se solucionó el problema.


Trayecto de actividades
------------------------
 
Ejercicios preparatorios para el problema
************************************************

Ejercicio 1: concepto de sistema operativo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Qué es un sistema operativo?

En términos generales, un sistema operativo es un SOFTWARE que administra
RECURSOS de hardware y software del computador Y provee servicios mediante
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

Vamos a discutir juntos estas preguntas:

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

Hasta ahora todos los programas que has realizado tienen un SOLO flujo de instrucciones. ¿Y si 
quieres tener en el mismo programa VARIOS flujos independientes? Lo puedes hacer con los hilos.
Los hilos permitirán que un programa pueda ``HACER VARIAS COSAS AL MISMO TIEMPO``.

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
  
NO TE PREOCUPES, ya te digo qué pasa.

Ejercicio 6: esperar un hilo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

El problema con el código anterior es que el proceso está terminando antes 
que los hilos puedan comenzar incluso a funcionar. Por tanto, será necesario 
que el hilo principal espere a que los dos hilos creados terminen antes de 
que el pueda terminar. 

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
queues. Este servicio te permitirá enviar mensajes en una dirección de un proceso 
a otro.

¿Y si necesitas recibir mensajes en el sentido opuesto? Necesitarás crear 
una segunda queue.

Ejercicio 8: ejemplo
^^^^^^^^^^^^^^^^^^^^^^^

En este ejemplo comunicarás dos procesos. Uno de ellos esperará los mensajes 
que enviará el otro.

Vas a lanzar primero el proceso que ejecutará la imagen receiver:

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

Luego lanza el proceso que ejecutará la imagen sender:

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
* Definir unos atributos para la cola como son la cantidad máximo 
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
    Te recomiendo que lo hagas antes de comenzar la evaluación.