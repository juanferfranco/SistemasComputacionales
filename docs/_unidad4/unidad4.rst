Unidad 4. Sistema operativo
============================

Introducción
--------------

Hemos llegado a la última estación de este recorrido a través
de las diferentes capas que componen un sistema de cómputo.
Partimos del hardware, desde una compuerta nand, y estamos
por fin en la capa de sistema operativo.

Propósito de aprendizaje
**************************

Comprender algunos conceptos básicos de los servicios que ofrece
el sistema operativo a las aplicaciones de usuario y utilizar
algunos de esos servicios en la construcción de aplicaciones
simples.

Trayecto de actividades
------------------------
 
Sesión 1
***************************************

En esta sesión abordaremos el concepto de proceso e hilo.

Ejercicio 1: concepto de sistema operativo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Qué es un sistema operativo?

En términos generales, un sistema operativo es un SOFTWARE que administra
RECURSOS de hardware y software del computador Y provee servicios mediante
los cuales los programas de usuario pueden hacer uso de esos recursos.

Los siguientes ejercicios explorarán algunos servicios que ofrece el sistema
operativo. La exploración la realizaremos de manera práctica para que luego,
puedas profundizar leyendo uno de los tantos excelentes libros de sistemas
operativos. En particular te recomiendo este:

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
Vamos al tablero para introducir el concepto general de hilo.

Ejercicio 4: creación de hilos
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Vamos a crear un hilo en Linux:

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

Ejecuta en la terminal: 

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


Trabajo autónomo 1
***************************************
(Tiempo estimado: 1 horas 20 minutos)

Se tiene un archivo que tiene 100 líneas y 20 caracteres máximo por línea.

* Crea un programa llamado prog.c que lea el archivo de entrada y almacene las líneas de texto 
  en un arreglo en memoria.
  
* Crea 2 hilos para procesar de diferente manera la información cargada en memoria. Los hilos deben 
  lanzarse para que se ejecuten en paralelo, OJO, NO DE MANERA SECUENCIAL, SI EN PARALELO.

* El Hilo 1 escribe en el archivo de salida1 el arreglo de líneas de texto, pero recorriendo 
  las líneas en orden inverso.

* El Hilo 2 escribe en el archivo de salida 2 las líneas de texto en orden.

* NO OLVIDES Hilo 1 e Hilo 2 deben lanzarse a la vez. Una vez Hilo 1 e Hilo 2 finalicen, el hilo 
  principal debe abrir los archivos de salida e imprimir el resultado, primero del Hilo 1 y luego del 
  Hilo 2

* El programa se ejecutará así: ./prog In Out1 Out2

* prog es el nombre del ejecutable, In especifica el nombre del archivo de entrada
  Out1 y Out2 especifican el nombre de los los archivos de salida 1 y 2 respectivamente. RECUERDA que
  In, Out1 y Out2 son parámetros.

Sesión 2
**********

Continua trabajando en el reto de la sesión anterior

Trabajo autónomo 2
***************************************
(Tiempo estimado: 1 horas 20 minutos)

Terminar el RETO.

Sesión 3
**********

Ahora vas a estudiar cómo implementar hilos en C# y cómo se compara con C.

Ejercicio 7: veamos cómo es en C#
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora vamos a familiarizarnos con el concepto de hilo en C#. Ingresa 
a `este <http://www.albahari.com/threading/>`__ sitio y lee detalladamente
su contenido hasta la sección Creating and Starting Threads (sin incluirla,
claro, a menos que quieras).

* ¿Qué es un hilo?
* ¿Cuál es la diferencia entre un método y un hilo?
* ¿La ejecución de los hilos es determinística?
* ¿Cuál es la diferencia entre un método estático y un
  método no estático?
* ¿Cuál es la diferencia entre un hilo y un método estático?

Trabajo autónomo 3
*****************************************
(Tiempo estimado: 1 horas 20 minutos)

Repasa todo el material hasta este punto. Vuelve a leer el material de las sesiones 1 y 3.

Sesión 4
**********

En esta sesión aprenderás a comunicar procesos.

Ejercicio 8: comunicación de procesos mediante colas 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Existe varios mecanismos de comunicación entre procesos. En este ejercicio
te voy a proponer un servicio de comunicación entre procesos denominado POSIX 
queues. Este servicio te permitirá enviar mensajes en una dirección de un procesos 
a otro.

¿Y si necesitas recibir mensajes en el sentido opuesto? Necesitarás crear 
una segunda queue.

Vamos al tablero para que lo analicemos juntos.

Ejercicio 9: ejemplo
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

Ejercicio 10: analiza el ejemplo
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


Trabajo autónomo 4
*********************
(Tiempo estimado: 1 horas 20 minutos)

Vas a modificar el ejemplo de esta sesión de tal manera que 
los dos procesos puedan intercambiar mensajes. 

Antes de comenzar, piensa primero en esta pregunta:

¿Cómo hacer para que un proceso pueda hacer dos cosas a la vez? 
En este caso los procesos tendrán que esperar a que llegue un mensaje 
a la queue pero también tendrán que esperar a que el usuario ingrese 
un mensaje para enviarlo al otro proceso.

Evaluación de la Unidad 4
----------------------------
(Tiempo estimado 6 horas)

.. warning:: PARA CUÁNDO, DÓNDE Y CÓMO ES LA ENTREGA DE LA EVALUACIÓN

  La evaluación se debe entregar de manera presencial en las sesiones 
  de clase de la semana 16 del curso. Puedes entregar en la sesión 1 o 2.
  Puedes realizar la evaluación con otro compañero.

Enunciado
***************

Vas a realizar una aplicación que combinará los conocimiento adquiridos con 
la realización de los retos que te presenté en el trabajo autónomo 1 y 4.

Vas a comunicar dos PROCESOS considerando:

#. Cada proceso al ejecutarse estará esperando, al mismo tiempo, que le 
   llegue información del otro proceso y ordenes del usuario.
#. El usuario deberá indicar en qué archivo está la información mediante 
   una ruta relativa o absoluta y de qué manera se debe enviar dicha 
   información.
#. La información, que en cualquier momento, llegue del otro proceso 
   debe ser presentada en pantalla.

Debes poder enviar información de estas dos maneras:

* Enviar cada línea del archivo de la primera a la última.
* Enviar cada línea del archivo de la última a la primera.


Criterios de evaluación
**************************

Funcionamiento de la aplicación 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#. Diseño de la aplicación para soportar concurrencia: 1.25
#. Implementación de la concurrencia: 1.25
#. Implementación del mecanismo de comunicación: 1.25
#. Diseño e implementación de las estructuras de datos para almacenar y 
   procesar la información: 1.25

Sustentación
^^^^^^^^^^^^^^

Debes mostrar tu aplicación funcionando en las sesiones de clase de la 
semana 16. La sustentación será un factor multiplicativo en la nota final 
y tendrá un rango de 0 a 1. Consiste en responder las preguntas que te formule 
el profesor en relación al funcionamiento de tu aplicación (ver criterios).

Nota Final
*************

La nota final estará dada por el producto: CriteriosEvaluación*Sustentación.