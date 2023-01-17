Introducción al control de versión con git y GitHub
====================================================

Con esta guía aprenderás los herramientas básicas para realizar 
todos los proyectos y ejercicios del curso bajo control de versión.

Trayecto de actividades
---------------------------------

Antes de comenzar el trayecto de actividades haremos lo siguiente:

* Abre el browser e ingresa a `Github <https://github.com/>`__.
* Si estás en una cuenta que no es la tuya realiza un sign out (esquina superior derecha
  desplegando el menú).
* Ingresa a tu cuenta.
* Ingresa a este `este <https://classroom.github.com/a/B7iTtsIL>`__ sitio para unirte 
  al classroom del curso. Busca tu nombre y ID. En este paso asociarás tu cuenta 
  de Github al classroom del curso.
* Acepta el assigment.
* Ya estamos listos para comenzar a trabajar.

Lectura 1: sistemas de control de versión 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

En este curso vas a realizar todos los ejercicios y evaluaciones usando 
un sistema de control de versión: Git y Github.

¿Qué es un sistema de control versión?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Cuando estás desarrollando software, alguna vez te ha pasado que terminas 
nombrando tus archivos así::

* Versión buena con un error
* Versión casi lista con un bug
* Versión para compartir con Camila
* Versión para enviar al profesor
* Esta versión si está bien
* Versión 1, versión 1-1, versión 2, versión 3
* versión enero 11 de 2022.

¿No sería ideal que el nombre de una archivo siempre fuera el mismo y existiera 
una forma de acceder a todo el historial de cambios del archivo?

Lo anterior lo puedes lograr con un sistema de control de versión. Un sistema de control 
de versión te ayuda a evitar la necesidad de guardar tus archivos con nombres 
diferentes a medida que realizas cambios, incluyes nuevas características 
o tienes alguna nueva receta de archivos para producir tu programa. El sistema 
de control de versión te ayudará a gestionar la versión de los archivos 
de manera automática evitando procesos manuales tediosos y susceptibles al error.

El sistema de control de versión ES UN PROGRAMA (que instalas en tu computador)
que te permitirá trazar y guardar información de los cambios que haces a tus 
archivos en el tiempo. Podrás recuperar incluso una versión pasada de un archivo si 
descubres que cometiste un error. 

¿Te va sonando?

Quiero contarte además que hoy en día prácticamente es impensable una 
empresa que desarrolle cualquier producto de software que NO TENGA control 
de versión.

¿Qué es Git y GitHub?
^^^^^^^^^^^^^^^^^^^^^^^^

Git es un sistema de control de versión libre y de código abierto que instalas 
en tu computador para realizar el control de versión de tus proyectos. 
Por su parte GitHub te permite guardar tus proyectos de software en un servidor 
en Internet con la información del control de versión que tienes en tu computador. 
¿Para qué quieres esto? Para compartir tu código, para hacer copias de seguridad, 
para mostrar tus habilidades y portafolio y SOBRE TODO para trabajar en EQUIPO. 

Por medio de GitHub, los aportes de cada miembro del equipo se pueden 
sincronizar y compartir. De esta manera, es posible construir productos de software 
muy complejos en los cuales participen MUCHOS desarrolladores.


Ejercicio 1: introducción a la terminal 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Para realizar el control de versión de tus programas vas a usar inicialmente 
la terminal. Una vez estés familiarizado con esta puedes explorar otras herramientas; 
sin embargo, la ventaja de la terminal es su rapidez y que definitivamente te obliga a 
entender qué estás haciendo. Esto es importante porque luego este conocimiento lo podrás 
extrapolar a cualquier herramienta gráfica.

Es posible que esta sea tu primera experiencia con la terminal. La terminal 
es un programa que te permite interactuar con el sistema operativo y los programas 
que tienes instalados por medio de comandos. Es por ello que a la terminal 
también la conocemos como interfaz de línea de comandos.

Abre la terminal. Escribe el siguiente comando::

  pwd

Acabas de escribir tu primer comando en la terminal. ``pwd`` te permite 
conocer la ruta en la cual estás posicionado en el sistema de archivos. Por el momento,
piensa en el sistema de archivos como una forma de organizar la información en el 
computador usando DIRECTORIOS.

Ahora vas a crear un nuevo DIRECTORIO::

  mkdir demo1

.. note:: RECUERDA

  ¿Qué comando debes ejecutar para saber en qué directorio estás posicionado en 
  este momento?


¿Y si quieres posicionarte en el nuevo directorio que acabas de crear? 
Ejecutas el comando ``cd`` que quiere decir ``change directory``::

  cd demo1

Para listar el contenido del nuevo directorio deberás escribir el comando::

  ls -al 

Te estarás preguntando, qué es ``.`` y ``..``. Se trata de referencias a dos 
directorios. ``.`` se refiere al directorio actual y ``..`` se refiere al directorio 
padre. Entonces, si escribes este comando::

    cd ..

.. note:: RETO

    ¿Cuál crees que sea el resultado? 
    
¿Perdido? No te preocupes. Repitamos el proceso juntos. Supón que la posición actual 
en el sistema de archivos está en demo1

Luego de ejecutar el comando::

  cd ..

El resultado será que te posicionarás en el directorio padre de demo1.

.. note:: RECUERDA

  En este momento debes estar en el directorio padre del directorio demo1. ¿Te cambias 
  de nuevo al directorio demo1 por fa?

Debiste hacer algo como esto::

  cd demo1

Ahora regresa de nuevo al directorio padre de demo1 y una vez estés allí ejecuta los 
comandos::

  cd ./demo1
  pwd

¿Te diste cuenta? 

.. note:: RECUERDA

  La entrada `.` se refiere al directorio actual y ``..`` se refiere al directorio 
  padre del directorio actual.

Al cambiarte al padre de demo1, ``.`` se refiere al directorio padre de ``demo1``. 
Por tanto, ``./demo1`` será la ruta RELATIVA de demo1 con respecto a su padre. 

Ejercicio 2: Vas a practicar 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora te voy a pedir que hagas varias cosas y preguntes si tienes dudas:

* Crea el directorio demo2 en demo1. ¿Recuerdas cómo listar el contenido de un directorio? 
* Cámbiate al directorio padre de demo1 y desde allí crea el directorio demo3 en el directorio 
  demo2.
* ¿Cuál será la ruta relativa de demo3 con respecto al padre de demo1?

.. warning:: ALERTA DE SPOILER

  Crea el directorio demo2 en demo1. ¿Recuerdas cómo listar el contenido de un directorio?::

    mkdir demo2
    ls -al

  Cámbiate al directorio padre de demo1 y desde allí crea el directorio demo3 en el directorio 
  demo2. Asumiendo que estás posicionado en demo1::

    cd ..
    mkdir ./demo1/demo2/demo3

  ¿Cuál será la ruta relativa de demo3 con respecto a al padre de demo1?::

    ../demo1/demo2/demo3

Ejercicio 3: experimenta
^^^^^^^^^^^^^^^^^^^^^^^^^

¿Qué comandos has visto hasta ahora?::

  pwd
  ls -al
  cd
  mkdir

Ahora tómate unos minutos para experimentar. ¿Cómo? 

* Inventa tus propios ejemplo o retos.
* Antes de ejecutar un comando PIENSA cuál sería el resultado. Si el resultado es como 
  te lo imaginaste, en hora buena, vas bien. Si no es así, MUCHO mejor, tienes una 
  oportunidad de oro para aprender. Entonces trata de explicar qué está mal, discute 
  con otros compañeros y si quieres habla con el profe.

Ejercicio 4: recuerda (evaluación formativa)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

De nuevo tómate unos minutos para:

#. Listar cada uno de los comandos que has aprendido hasta ahora y escribe al 
   frete de cada uno qué hace.
#. ¿Qué es una ruta absoluta?
#. ¿Qué es una ruta relativa?

Ejercicio 5: añade un archivo al control de versión
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Te voy a explicar lentamente lo que viene. Actualmente tienes un repositorio 
en Github, pero cuando creas un Codespace lo que ocurre es que Github le da 
vida a un computador en Internet, lo llamaremos servidor, que correrá el sistema 
operativo Linux al cual tu tendrás acceso desde el browser e interactuarás con él 
desde la línea de comandos que tienes disponible.

El servidor tendrá un copia del repositorio que tienes en Github. TE REPITO, tendrás 
de entrada una copia del repositorio. Ten presente que es una copia. Entonces lo 
que hagas en la copia no se verá reflejado en el servidor a menos que tu lo indiques 
de manera explícita. Vamos bien?

En resumen. Tienes en Github un repositorio que te creó el profe. El profe también 
se encarga de configurar todo para que puedas tener un servidor en Internet. Ese 
servidor correrá el sistema operativo Linux. Cuando el servidor arranca hará una 
copia del repositorio en Github. Cualquier cosa que hagas en esta copia no modificará 
el repositorio en Github a menos que tu se lo digas.

Ahora si. Vas a crear en la copia del repositorio un archivo, lo vas a modificar y 
luego lo vas a enviar a Github, es decir, vas a sincronizar el repositorio en Github 
con el repositorio que tienes en el servidor. Vale?

* Asegúrate de cambiarte al directorio introgit.
* Escribe ls -al. Deberás ver un directorio oculto llamado ``.git```.
  Ese directorio ``.git`` es lo que llamamos un ``REPOSITORIO DE GIT``. En ese repositorio 
  el sistema de control de versión, ``Git```, que está corriendo en el servidor, 
  realizará el control de versión de todo lo que le indiquemos. Ten presente que en 
  este repositorio, Git guardará toda la información relacionada con los cambios e 
  historia de los archivos de tu proyecto que estén bajo control de versión. Puedes 
  pensar que el repositorio es una especie de base de datos donde Git almacena un 
  diario de qué está pasando con cada uno de los archivos de tu proyecto, PERO tu 
  le debes decir a Git a qué archivos debe hacerle control de versión.
* Crea un directorio llamado project1 (mkdir).
* Cámbiate a ese directorio (cd)

En ``project1`` vas a simular la creación de un proyecto.

Ahora crea un archivo en el directorio::

    touch main.c

Ahora modifica el archivo main.c con el siguiente código:

.. code-block:: c

    #include <stdio.h>
    #include <stdlib.h>

    int main(){
        printf("La vida es bella\n");
        return(EXIT_SUCCESS);
    }

Antes de continuar ejecuta el comando::

    ls -al

Deberías tener solo tres entradas::

    .
    ..
    main.c

Ahora dile a Git que coloque bajo control de versión el nuevo archivo main.c::

    git add main.c

Esto solo debes decírselo una vez a Git. De aquí en adelante cada que hagas 
cambios a main.c solo debes indicarle a Git cuándo debe guardar la versión de ese archivo 
en el repositorio.

Entonces, en este punto ya añadiste main.c al control de versión. Cuando añades un 
archivo, Git automáticamente lo pasa a una zona lógica llamada el ``STAGE``. Puedes 
entrar y sacar archivos del STAGE. Pero una vez tengas allí todos los archivos que quieras 
lo único que debes hacer es pedirle a Git que les tome una foto, es decir, que haga 
un COMMIT. Ese commit será una foto de tu proyecto que incluirá el nuevo archivo main.c 
con los cambios que recién realizaste. 

.. note:: NO PIERDAS DE VISTA 

    Git solo le toma la foto (hace el commit) de los archivos que tengas en el stage

Ahora escribe el comando::

    git status

Observa que el sistema de control de versión te dirá que tienes un archivo listo 
para el commit. Realiza el commit::

    git commit -am "version inicial de main.c"

Escribe de nuevo::

    git status

Ahora el sistema te dirá que no hay nada disponible para hacerle commit.

Te pediré ahora que regreses a tu repositorio en Github. Ves la carpeta project1 y 
el archivo main.c?

La respuesta debería ser no. ¿Por qué?

.. warning:: NO SIGAS POR FA

    Si aún no sabes la respuesta a la pregunta anterior te pediré que leas 
    de nuevo el ejercicio. Si aún así aún no entiendes llama al profe.

El archivo aún no está en Github porque recuerda que se encuentra en el repositorio 
del servidor que aún no está sincronizado con el repositorio en Github.

Para sincronizar los repositorios escribe::

    git push

Regresa a Github. Presiona F5 para refrescar. ¿Qué pasó?

Ejercicio 6: para pensar
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* ¿Qué crees que pase si borras el directorio .git del servidor?
* ¿Si borras el directorio .git del servidor qué crees que pase 
  con el repositorio en Github?

Ejercicio 7: adiciona un nuevo archivo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Adiciona a project1 en el servidor un nuevo archivo llamado file1.txt
* Adiciona al repositorio el archivo.
* Realiza el commit.
* Sincroniza el repositorio en el servidor con el repositorio en Github.

.. note:: LLAMA al profe

    Llama al profe y muéstrale este paso.


Ejercicio 8: analicemos un poco más lo que está pasando 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Adiciona un segundo archivo, file2.txt al sistema de control de versión, 
PERO no hagas commit aún. Escribe::

    git status

El resultado por ahora es muy interesante. Verás que estás trabajando en la 
rama (branch) main. Las ramas son una característica MUY útil de Git. Como 
su nombre indica te puedes ir por las ramas. Te lo explico con una historia. 
Supón que estás trabajando en tu proyecto y se te ocurre una idea, algo nuevo 
para implementar; sin embargo, no quieres dañar tu proyecto principal. Entonces 
lo que haces es que te creas una rama que tomará como punto de partida el estado 
actual de tu proyecto. En esa nueva rama realizas los ensayos que quieras. Si 
al final no te gusta el resultado, simplemente destruyes la rama y tu proyecto 
seguirá como lo habías dejado antes de crear la rama. Pero si el resultado te gusta 
entonces podrás hacer un ``MERGE`` e incorporar las ideas de la nueva rama a la rama 
inicial. Ten presente que si no quieres trabajar en la nueva rama y deseas retomar el 
trabajo en la rama principal lo puedes hacer, te puedes cambiar de ramas. Incluso puedes 
crear muchas más y probar varias ideas en simultáneo.

Observa el mensaje ``Untracked files`` y el nombre del archivo file2.txt. Quiere 
decir que Git detecta que hay un nuevo archivo en el sistema de archivos PERO no 
le está haciendo tracking, es decir, no está en el repositorio bajo control de versión.

¿Vamos bien? 

Finalmente, observa el mensaje 
``nothing added to commit but untracked files present (use "git add" to track)`` quiere 
decir que si en este momento le pides a Git que guarde en el repositorio una 
``FOTO`` (``commit``) del estado actual de los archivos que están bajo tracking, 
Git te dice que no hay nada para guardar.Nota que Git da sugerencias: 
``(use "git add" to track)``, es decir, te dice qué necesitas hacer para colocar 
el archivo file2.txt en tracking.

Ejercicio 9: termina de sincronizar los cambios  
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Sincroniza el repositorio local con el ``REMOTO`` (en Github) para 
que puedas ver los cambios.

Ejercicio 10: ahora modifica file1.txt
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Añade a file1.txt el mensaje ``HOLA PROFE``.
* Salva el archivo (CRTL+S).
* Escribe::

    git status

Nota que ahora ya no te sale el menaje ``Untracked files``. El mensaje ahora 
será ``Changes not staged for commit``. Quiere decir que Git le está 
haciendo tracking a tu archivo, pero que si quieres que salga en la próxima 
foto del proyecto (COMMIT) tendrás que pasarlo al stage. ¿Cómo?::

    git commit -am "Saludando al profe"

De nuevo escribe::

    git status

Ahora solo tiene que sincronizar el repositorio local (en el servidor) con 
el remoto (en Github). ¿Cómo se hace eso? Lee la salida de status ahí te dice.

.. note:: NO OLVIDES

    Cada que regreses al repositorio en Github para comprobar los cambios no 
    olvides presionar F5 para refrescar la página.

Ejercicio 11: volver a una versión anterior del proyecto 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Recuerda que con Git puedes irle tomando fotos al estado del proyecto.

Ahora supón que quieres volver a una versión anterior del proyecto (una foto del pasado). 
Git ofrece varias alternativas que irás aprendiendo con el tiempo. Por ahora, 
piensa que lo que harás es pedirle a Git que traiga una versión del pasado y haga 
un nuevo commit (tome una nueva foto) de esa versión en el presente.

¿Cuál versión del proyecto quieres recuperar? Para saberlo puedes leer 
el historial de mensajes que adicionaste a cada COMMIT::

    git log --oneline

En mi caso la salida es::

    938007f (HEAD -> main, origin/main, origin/HEAD) Saludando al profe
    6c238ac ADd file2.txt
    23b3d8f add file1
    9e88a2c version inicial de main.c
    2e12222 Setting up GitHub Classroom Feedback
    92a8419 (origin/feedback) GitHub Classroom Feedback
    36a2798 Initial commit

Ahora digamos que deseas ver cómo estaba el proyecto en el commit 23b3d8f (estos son 
los primeros 7 números del identificador del commit o hash único que se calcula con 
el algoritmo sha-1)::

    git checkout 23b3d8f

El resultado es::

    Note: switching to '23b3d8f'.

    You are in 'detached HEAD' state. You can look around, make experimental
    changes and commit them, and you can discard any commits you make in this
    state without impacting any branches by switching back to a branch.

    If you want to create a new branch to retain commits you create, you may
    do so (now or later) by using -c with the switch command. Example:

        git switch -c <new-branch-name>

    Or undo this operation with:

        git switch -

    Turn off this advice by setting config variable advice.detachedHead to false

    HEAD is now at 23b3d8f add file1

Escribe el comando::

    git status

El resultado es::

    HEAD detached at 23b3d8f
    nothing to commit, working tree clean

Observa qué paso con file2. 

¿Ya no está cierto? Lo que hace el sistema de control de versión es ajustar 
el sistema de archivos local a la foto de lo que tenías en el pasado. PERO NO TE 
PREOCUPES, no se ha perdido nada, SOLO viajaste en el tiempo.

En este momento estás en un estado especial llamado detached HEAD. En este estado 
puedes jugar con el código y hacer ensayos y luego puedes descartar todo lo que 
hagas sin dañar lo que ya tenías. Mira que Git te dice qué debes hacer para 
conservar los experimentos o para descartarlos.

¿Quieres volver a la foto actual?::

    git switch -

Ahora deberás ver de nuevo en el sistema de archivos a file2.txt

Ejercicio 12: repasa (evaluación formativa)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

En este punto te pediré que descanses un momento. En este 
ejercicio vas a repasar el material que has trabajo. Te pediré 
que hagas lo siguiente:

#. Crea un directorio llamado project2 por fuera de project1.
#. Crea unos cuantos archivos de texto.
#. Dile a Git que haga tracking de esos archivos.
#. Realiza un primer commit.
#. Sincroniza el repositorio local con el remoto.
#. Modifica los archivos creados.
#. Realiza un par de commits más.
#. Sincroniza los cambios con el repositorio remoto.

Ejercicio 13: entrega de evaluaciones
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

(El framework de pruebas para este ejercicio está tomado de 
`aquí <https://github.com/remzi-arpacidusseau/ostep-projects>`__)

Te voy a proponer un ejercicio que será muy importante para el curso 
porque será la manera típica como entregarás las evaluaciones.

Para la entrega de las evaluaciones utilizarás GitHub. Para cada evaluación 
te enviaré un enlace con una invitación para la evaluación. Cuando aceptes la 
invitación, automáticamente se creará un repositorio para ti con la estructura 
de directorios y archivos necesarios para comenzar a realizar la evaluación. Ten 
en cuenta que tu tendrás permisos para editar el nuevo repositorio. Podrás aplicar 
todo lo que trabajaste en esta guía.

Entonces vamos a simular una invitación a una evaluación en la cual tendrás que 
escribir un programa. En este caso deberás completar el programa wcat.c al cual 
se le aplicarán automáticamente unos vectores de prueba para verificar si es 
correcta la implementación.

Por ahora, los detalles del programa y las pruebas no importan. Lo importante es 
que puedas practicar el flujo de trabajo usando Git y GitHub.

Sigue estos pasos:

* Abre un browser e ingresa a tu cuenta de GitHub. ASEGÚRATE POR FAVOR que estás 
  en tu cuenta.
* Abre una nueva pestaña e ingresa a `este <https://classroom.github.com/a/sXNRDAEb>`__ sitio.
* Por último acepta la tarea.
* Espera un momento y refresca (con F5) el browser.
* Abre tu nuevo repositorio en otra pestaña.
* Selecciona el menú Actions y dale click al botón ``Enable Actions on this 
  repository``. Si no aparece el botón es porque ya están habilitadas las acciones.
* Observa el archivo wcat.c inicial:

.. code-block:: c 

        #include <stdio.h>
        #include <stdlib.h>


        int main(int argc, char *argv[]){
            exit(EXIT_SUCCESS);
        }

* Regresa al repositorio y espera que aparezca una marca roja indicando que el código 
  actual no pasa los vectores de prueba.
* Dale click a la marca roja y luego click en Details.
* Despliega ``Run education/autograding@v1``. Podrás ver allí que algunos vectores de 
  prueba tienen marcas rojas (falló la prueba) y otros marcas verdes (pasó la prueba).
* Ahora vamos a simular que arreglaremos el código. Modifica wcat.c con este código:

.. code-block:: c 

    #include <stdio.h>
    #include <stdlib.h>


    int main(int argc, char *argv[]){

        //printf("arc: %d\n",argc);

        if(argc <= 1){
            exit(EXIT_SUCCESS);
        }

        FILE *inFile = NULL;
        char buffer[256];
        char *status =  NULL;


        for(int i = 1 ; i < argc; i++){

            inFile = fopen(argv[i],"r");
            if (inFile == NULL){
                printf("wcat: cannot open file");
                printf("\n");
                exit(EXIT_FAILURE);
            }
            do{
                status = fgets(buffer, sizeof(buffer),inFile);
                if(status != NULL){
                    printf("%s",buffer);
                    //printf("hola mundo cruel");
                }
            }while (status !=NULL);

            fclose(inFile);
        }
        
        exit(EXIT_SUCCESS);
    }

* Salva wcat.c y realiza un commit.
* Luego sincroniza con el repositorio remoto. Esto hará que se disparen 
  las pruebas (acciones) en GitHub.
* Ingresa de nuevo al repositorio en GitHub. Espera un minuto y refresca la página. 
  Si todo está bien verás una marca verde al lado izquierdo del commit que enviaste.
* Despliega de nuevo ``Run education/autograding@v1`` para observar cómo se ven 
  los vectores cuando todo funciona bien.

Ejercicio 14: documentación de las evaluaciones
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

La documentación de las evaluaciones la realizarás en el archivo 
README.md. Vas a escribir la documentación en un lenguaje llamado Markdown.

Tu repositorio actualmente debe tener un archivo README.md, ¿Verdad?

Abre README.md y realiza las siguientes modificaciones:

#. Cambia el título del documento por ``DOCUMENTACIÓN DEL LA EVALUACIÓN``.
#. Indica que ese texto tendrá formato ``h1``.
#. Ahora te pediré que insertes una imagen, un hipervínculo, un título de tipo h2 y otro tipo h3, 
   escribe unas cuantas líneas de texto y coloques una palabra en negrita, 
   itálica y resaltada, crea una lista ordenada y una lista no ordenada.
#. Una vez termines sincroniza el repositorio local con el remoto.
#. Verifica el resultado en Github. No olvides presionar F5.

.. note:: ESCRIBIR documentos en GitHub

    En `este <https://www.markdownguide.org/cheat-sheet/>`__ sitio puedes encontrar una 
    cheat sheet del lenguaje.

    En `este <https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax>`__ 
    enlace puedes encontrar más información.

..
    Evaluación 1
    -----------------

    Enunciado
    ^^^^^^^^^^^^
    (El framework de pruebas para esta evaluación está tomado de 
    `aquí <https://github.com/remzi-arpacidusseau/ostep-projects>`__)

    #. Ingresa y acepta la evaluación en 
    `este <https://classroom.github.com/a/2ZfA7C8p>`__ enlace.
    #. Crear el archivo main.c en el ``directorio dirTest/project`` 
    con el siguiente código:

        .. code-block:: c
        
            #include <stdio.h>
            #include <stdlib.h>

            int main(int argc, char *argv[]){

                FILE *fin = fopen(argv[1],"r");

                if(fin == NULL){
                    perror("fopen-fin fails: ");
                    exit(EXIT_FAILURE);
                }

                char buffer[64];
                char *status = NULL;
                do{
                    status = fgets(buffer, sizeof(buffer),fin);
                    if(status != NULL){
                        printf("%s",buffer);
                    }
                }while(status !=NULL);
                fclose(fin);
                exit(EXIT_SUCCESS);
            }

    #. Envía los cambios al repositorio con tu evaluación.
    #. Verifica que la evaluación se calificó correctamente.
    #. Edita el archivo README.md SOLO con lo siguiente y en 
    el mismo orden.

        * Adiciona un título de tipo H1 que diga: EVALUACIÓN CONTROL DE VERSIÓN
        * Coloca tu nombre y ID
        * Adiciona una foto tuya.
        * Adiciona un hipervínculo a algún trabajo tuyo que esté publicado 
          en Internet.
        * Crea una lista ordenada mostrando cómo sería el comando en cada caso:
        
            * ¿Cómo se adiciona un archivo nuevo al repositorio?
            * Una vez modificado un archivo ¿Cómo se adiciona al stage?
            * ¿Cómo se realiza un commit?
            * ¿Cómo se sincroniza un repositorio local con un repositorio remoto?
