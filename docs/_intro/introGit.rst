Introducción al control de versión con git y GitHub
====================================================

Con esta guía aprenderás los herramientas básicas para realizar 
todos los proyectos y ejercicios del curso bajo control de versión.

Trayecto de actividades
---------------------------------

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
la terminal. Una vez estés familiarizado con esta puedes explorar otras herramientas; sin embargo,
la ventaja de la terminal es su rapidez y que definitivamente te obliga a entender 
qué estás haciendo. Esto es importante porque luego este conocimiento lo podrás extrapolar 
a cualquier herramienta gráfica.

Es posible que esta sea tu primera experiencia con la terminal. La terminal 
es un programa que te permite interactuar con el sistema operativo y los programas 
que tienes instalados por medio de comandos. Es por ello que a la terminal 
también la conocemos como interfaz de línea de comandos.

Abre la terminal y escribe en el buscador de aplicaciones la palabra ``terminal``. 
Escribe el siguiente comando::

  pwd

En mi caso (en tu caso será distinto) el resultado es::

  /home/jfupb

Acabas de escribir tu primer comando en la terminal. ``pwd`` te permite 
conocer la ruta en la cual estás posicionado en el sistema de archivos. Por el momento,
piensa en el sistema de archivos como una forma de organizar la información en el computador 
usando DIRECTORIOS.

Ahora vas un nuevo DIRECTORIO::

  mkdir demo1


.. note:: RECUERDA

  ¿Qué comando debes ejecutar para saber en qué directorio estás posicionado en este momento?


¿Y si quieres posicionarte en el nuevo directorio que acabas de crear? Ejecutas el comando 
``cd`` que quiere decir ``change directory``::

  cd demo1

Para listar el contenido del nuevo directorio deberás escribir el comando::

  ls -al 

Verás algo como esto:

.. code-block::

    total 8
    drwxrwxr-x  2 jfupb jfupb 4096 Jan 11 15:40 .
    drwxr-x--- 37 jfupb jfupb 4096 Jan 11 15:43 ..

Te estarás preguntando, qué es ``.`` y ``..``. Se trata de referencias a dos directorios. ``.``
se refiere al directorio actual y ``..`` se refiere al directorio padre. Entonces, si 
escribes este comando::

.. code-block:: bash 

    cd ..

.. note:: RETO

    ¿Cuál crees que sea el resultado? 
    
¿Perdido? No te preocupes. Repitamos el proceso juntos. Supón que la posición actual es::
  pwd
  /home/jfupb/demo1

Luego de ejecutar el comando::

  cd ..

El resultado será::

    pwd
    /home/jfupb


.. note:: RECUERDA

  En este momento debes estar en el directorio padre del directorio demo1. ¿Te cambias 
  de nuevo al directorio demo1 por fa?

Debiste hacer algo como esto::

  cd demo1

Ahora regresa de nuevo al directorio padre de demo1 y una vez estés allí ejecuta los comandos::

  cd ./demo1
  pwd

El resultado será::

  /home/jfupb/demo1

¿Te diste cuenta? 

.. note:: RECUERDA

  La entrada `.` se refiere al directorio actual y ``..`` se refiere al directorio padre del 
  directorio actual.

Al cambiarte al padre de demo1, ``.`` se refiere al directorio padre de ``demo1``. 
Por tanto, ``./demo1`` será la ruta RELATIVA de demo1 con respecto a su padre. 


Ejercicio 2: Vas a practicar 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora te voy a pedir que hagas varias cosas y preguntes si tienes dudas:


* Crea el directorio demo2 en demo1. ¿Recuerdas cómo listar el contenido de un directorio? 
* Cámbiate al directorio padre de demo1 y desde allí crea el directorio demo3 en el directorio 
  demo2.
* ¿Cuál será la ruta relativa de demo3 con respecto a al padre de demo1?


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
* Antes de ejecutar un comando PIENSA cuál sería el resultado.Si el resultado es como 
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


Ejercicio 5: tu primer proyecto bajo control de versión
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Crea un directorio llamado project1 (mkdir)
* Cámbiate a ese directorio (cd)

En ``project1`` vas a simular la creación de un proyecto de software.

Ahora crea un archivo en el directorio::

    touch main.c

Abre el directorio::

    code .

.. warning:: MUY IMPORTANTE

    Siempre que trabajes en visual studio code abre DIRECTORIOS completos, no ARCHIVOS individuales.


``code`` es el comando que escribes en la terminal para abrir el programa visual studio code. 
¿Qué significa el ``.`` luego del comando?


.. note:: ALERTA DE SPOILER 

    No olvides que la entrada de directorio ``.`` se refiere al directorio actual en el que estás 
    posicionado. ¿Y qué era ``..``?

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


Ahora si vamos a crear el repositorio::

    git init

Y solo con esto, ya tenemos el proyecto bajo control de versión. ¿Fácil, no?

Escribe en la terminal el comando::

    ls -al

Notas que hay una nuevo directorio que no tenías antes::

    .
    ..
    main.c 
    .git

Ese directorio ``.git`` es lo que llamamos un ``REPOSITORIO DE GIT``. En ese repositorio 
el sistema de control de versión que tenemos instalado realizará el control de versión 
de todo lo que le indiquemos. Ten presente que en este repositorio, Git guardará toda la información 
relacionada con los cambios e historia de los archivos de tu proyecto que estén bajo control de versión.
Puedes pensar que el repositorio es una especie de base de datos donde Git almacena un diario de qué 
está pasando con cada uno de los archivos de tu proyecto.

Ejercicio 6: configura Git
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Para hacer tus primeros experimentos con Git vas a realizar unas configuraciones 
mínimas para informarle a Git un nombre de usuario y un correo. Esta información
permite que Git identifique a la persona responsable de realizar los cambios 
a un archivo. Recuerda que Git está diseñado para que puedas trabajar en equipo.

Escribe los siguientes comandos:

.. code-block:: bash 

    git config --global user.name "Coloca tu nombre"
    git config --global user.email "tu correo electrónico"


Ejercicio 7: para pensar
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Qué crees qué pase si borras el directorio ``.git`` en relación con el historial
de cambios de tus archivos?

¿Qué crees que pase si creas un directorio vacío y mueves allí todo los archivos 
de tu proyecto incluyendo el directorio .git?

Ejercicio 8: reconocer el estado del repositorio 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora ejecuta el siguiente comando:

.. code-block:: bash 

    git status

Verás algo así:

.. code-block:: bash 

    On branch master

    No commits yet

    nothing to commit (create/copy files and use "git add" to track)

El resultado por ahora es muy interesante. Verás que estás trabajando en la 
rama (branch) master. Las ramas son una característica MUY útil de git. Como 
su nombre indica te puedes ir por las ramas. Te lo explico con una historia. 
Supón que estás trabajando en tu proyecto y se te ocurre una idea, algo nuevo 
para implementar; sin embargo, no quieres dañar tu proyecto principal. Entonces 
lo que haces es que te creas una rama que tomará como punto de partida el estado 
actual de tu proyecto. En esa nueva rama realizas los ensayos que quieras. Si 
al final no te gusta el resultado, simplemente destruyes la rama y tu proyecto 
seguirá como lo habías dejado antes de crear la rama. Pero si el resultado te gusta 
entonces podrás hacer un MERGE e incorporar las ideas de la nueva rama a la rama 
inicial. Ten presente que si no quieres trabajar en la nueva rama y deseas retomar el 
trabajo en la rama principal lo puedes hacer, te puedes cambiar de ramas. Incluso puedes 
crear muchas más y probar varias ideas en simultáneo.

Ahora observa el mensaje ``No commits yet``. Este mensaje quiere decir que aún no has guardado 
nada en el repositorio. Finalmente, ``nothing to commit`` te está diciendo que no 
hay nada para guardar en el repositorio porque no has hecho nada hasta ahora; sin embargo,
observa que git te da pistas de lo que puedes hacer: ``(create/copy files and use "git add" to track)``. 
Te propone usar el comando ``git add``. Con este comando le puedes decir a Git  
qué archivos quieres observar o hacerles ``TRACK``. Es lógico, ¿Cierto? No siempre 
quieres mantener la historia de todos los archivos o simplemente algunos archivos 
son generados en procesos de compilación de código fuente a código ejecutable. En 
esos casos solo vas a querer mantener bajo control de versión los archivos de código fuente.

Ejercicio 9: adicionar un archivo al repositorio 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Para hacer las cosas más simples, por ahora solo vas a simular 
la creación de un proyecto de software usando archivos de texto 
simples.

Crea un archivo de texto así:

.. code-block:: bash 

    touch f1.txt 

Luego de este comando deberías tener el directorio demo1 así:

.. code-block:: bash 

    ls -al

    total 12
    drwxrwxr-x  3 jfupb jfupb 4096 Jan 12 15:52 .
    drwxr-x--- 22 jfupb jfupb 4096 Jan 12 15:52 ..
    -rw-rw-r--  1 jfupb jfupb    0 Jan 12 15:52 f1.txt
    drwxrwxr-x  7 jfupb jfupb 4096 Jan 12 15:32 .git

Ahora ejecuta el comando:

..  code-block:: bash 

    git status

Verás esto:

.. code-block:: bash 

    On branch master

    No commits yet

    Untracked files:
    (use "git add <file>..." to include in what will be committed)
        f1.txt

    nothing added to commit but untracked files present (use "git add" to track)

Nota entonces que ya tienes en el directorio tu primer archivo, pero aún no 
le has pedido a Git que te haga ``tracking`` de ese archivo. Entonces ejecuta el 
comando:

.. code-block:: bash 

    git add f1.txt 

Y de nuevo observa el estado del repositorio:

.. code-block:: bash 

    git status

    On branch master

    No commits yet

    Changes to be committed:
    (use "git rm --cached <file>..." to unstage)
        new file:   f1.txt

Te explico con una metáfora lo que está pasando. Imagina que Git 
le toma fotos al estado de tu proyecto cada que se lo solicitas; sin embargo, 
antes de tomar la foto tienes que decirle a Git (``con add``) a qué archivos 
le tomarás la foto. Todos los archivos que serán tenidos en cuenta para la 
próxima foto se ubican en una zona lógica denominada el STAGE. Mira el mensaje 
``(use "git rm --cached <file>..." to unstage)``. Observa que Git te está diciendo
que f1.txt ya está listo para la foto, pero si te arrepientes de incluir el archivo 
en la foto puedes ejecutar el comando sugerido. Prueba sacar de la foto a f1.txt:

.. code-block:: bash 

    git rm --cached f1.txt

Mira el estado del repositorio:

.. code-block:: bash 

    git status
    On branch master

    No commits yet

    Untracked files:
    (use "git add <file>..." to include in what will be committed)
        f1.txt

    nothing added to commit but untracked files present (use "git add" to track)

¿Te das cuenta? Hemos sacado de la foto (DEL STAGE) a f1.txt. Volvamos a invitar 
a f1.txt a la foto:

.. code-block:: bash 

    git add f1.txt 

Ahora ``TOMA LA FOTO``:

.. code-block:: bash 

    git commit -m "adicionamos f1.txt al repositorio"

Consulta el estado del repositorio:

.. code-block:: bash 

    On branch master
    nothing to commit, working tree clean

Puedes ver que Git está observando todo lo que pasa en el directorio de tu 
proyecto. Por ahora Git sabe que no has hecho nada más y por eso que te dice 
``nothing to commit, working tree clean``.

Lo último que te voy a pedir que hagas con este ejercicio es que le preguntes 
a Git qué fotos (``COMMITS``) se han tomado en el repositorio:

.. code-block:: bash 

    git log 

El resultado es:

.. code-block:: bash 

    commit c14b43cde2ebac63a56377ba1f6faa67316d48ff (HEAD -> master)
    Author: jfupb <juanf.franco@upb.edu.co>
    Date:   Wed Jan 12 16:10:17 2022 -0500

        adicionamos f1.txt al repositorio
    (END)

Nota que el commit está identificado con el hash ``c14b43cde2ebac63a56377ba1f6faa67316d48ff``, 
el autor, correo, fecha, hora y la descripción del commit.

Ejercicio 10: retos 
^^^^^^^^^^^^^^^^^^^^^

Para un momento. Repasa los ejercicios anteriores, actualiza tu lista 
de comandos con la explicación de qué hacen. Una vez estés en este punto 
realiza los siguientes retos:

#. Crea un nuevo commit con el archivo f2.txt
#. Crea un nuevo commit que incluya los archivos f3.txt y f4.txt

NOTA: no olvides escribir ``git status`` entre cada comando que ejecutes 
para que puedas ir leyendo qué va ocurriendo con el repositorio.

Al finalizar este ejercicio deberías ver algo así:

.. code-block:: bash 

    git log 

    commit 7ec66fb9215999518fe5907c8c1360036906476e (HEAD -> master)
    Author: jfupb <juanf.franco@upb.edu.co>
    Date:   Wed Jan 12 17:19:14 2022 -0500

        Add f3.txt and f4.txt

    commit 11950128c3d3dc6cc7b3cfda7a3e5a8ed566c235
    Author: jfupb <juanf.franco@upb.edu.co>
    Date:   Wed Jan 12 17:16:59 2022 -0500

        add f2.txt

    commit c14b43cde2ebac63a56377ba1f6faa67316d48ff
    Author: jfupb <juanf.franco@upb.edu.co>
    Date:   Wed Jan 12 16:10:17 2022 -0500

        adicionamos f1.txt al repositorio
    (END)


    git status  

    On branch master
    nothing to commit, working tree clean

Ejercicio 11: modificar el contenido de un archivo 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Modifica el contenido del archivo f1.txt añadiendo tres líneas de texto 
(escribe lo que tu corazón te dicte). Salva el archivo.

Al verificar el estado del repositorio verás:

.. code-block:: bash 

    git status

    On branch master
    Changes not staged for commit:
    (use "git add <file>..." to update what will be committed)
    (use "git restore <file>..." to discard changes in working directory)
        modified:   f1.txt

    no changes added to commit (use "git add" and/or "git commit -a")

¿Ves la diferencia con respecto al momento en el que creaste el archivo? Déjame recordarte 
el mensaje:

.. code-block:: bash 

    On branch master

    No commits yet

    Untracked files:
    (use "git add <file>..." to include in what will be committed)
        f1.txt

    nothing added to commit but untracked files present (use "git add" to track)

Nota que al crear el archivo, Git te dice que no le está haciendo seguimiento (untracked); 
sin embargo, una vez está creado el archivo y lo modificas, Git te dice 
``Changes not staged for commit``. 

En este caso, Git le hace tracking a tu archivo, pero tu no has decidido pasar el 
archivo a STAGE para poderle tomar la foto con los cambios que tiene ahora. 
¿Cómo lo haces? Mira que en el mensaje Git te dice: ``git add f1.txt``. Nota que Git 
también te dice que puedes descartar los cambios en el archivo con 
``git restore f1.txt``. ¿Por qué no haces la prueba?

Escribe:

.. code-block:: bash 

    git restore f1.txt

Luego para ver en la terminal el contenido del archivo:

.. code-block:: bash

    cat f1.txt

¿Ya no hay nada, cierto? Mira el estado del repositorio:

.. code-block:: bash 

    git status

    On branch master
    nothing to commit, working tree clean

Vuelve a modificar f1.txt, pero esta vez si guardarás los cambios 
en el repositorio. Recuerda los pasos:

#. Cambias el archivo
#. Verifica el estado del repositorio (status)
#. Adiciona los cambios en el STAGE (add) 
#. Toma la foto (commit)
#. Verifica de nuevo el estado del repositorio (status)
#. Verifica el historial del repositorio (log)

Te debe quedar algo así:

.. code-block:: bash 

    commit 3c8fee79d84b5e1bee87eebd67d06db821168951 (HEAD -> master)
    Author: jfupb <juanf.franco@upb.edu.co>
    Date:   Thu Jan 13 08:15:26 2022 -0500

        update f1.txt

    commit 7ec66fb9215999518fe5907c8c1360036906476e
    Author: jfupb <juanf.franco@upb.edu.co>
    Date:   Wed Jan 12 17:19:14 2022 -0500

        Add f3.txt and f4.txt

    commit 11950128c3d3dc6cc7b3cfda7a3e5a8ed566c235
    Author: jfupb <juanf.franco@upb.edu.co>
    Date:   Wed Jan 12 17:16:59 2022 -0500

        add f2.txt

    commit c14b43cde2ebac63a56377ba1f6faa67316d48ff
    Author: jfupb <juanf.franco@upb.edu.co>
    Date:   Wed Jan 12 16:10:17 2022 -0500

        adicionamos f1.txt al repositorio


Ejercicio 12: ¿Y si ya tienes un proyecto creado? 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Supón que ya tienes un proyecto creado o justo acabas de crear un 
proyecto y quieres iniciar desde ese punto el control de versión.

Vamos a simular esta situación. Abre la terminal. Si la tenías abierta 
cámbiate al directorio padre de demo1. Crea lo que te mostraré ahora:

.. code-block:: bash 

    ./demo2
    ├── f1.txt
    ├── f2.txt
    └── f3.txt

Adiciona algunas líneas de texto a cada archivo. Piensa entonces 
que esto que acabas de hacer es el resultado de la reciente creación 
de un proyecto de software, pero aún sin control de versión.

Para adicionar control de versión al proyecto:

#. Cámbiate al directorio ``demo2`` (cd)
#. Inicia un nuevo repositorio (init)
#. Verifica el estado del repositorio (status)

El resultado esperado es este:

.. code-block:: bash 

    On branch master

    No commits yet

    Untracked files:
    (use "git add <file>..." to include in what will be committed)
        f1.txt
        f2.txt
        f3.txt

    nothing added to commit but untracked files present (use "git add" to track)

¿Te parece familiar lo que ves? Ahora solo es que le digas a Git que haga 
tracking a los archivos que quieras. Para este ejercicio dile que todos los archivos.

.. code-block:: bash 

    git add .

Y el resultado cuando verifiques el estado del repositorio (status) será:

.. code-block:: bash 

    On branch master

    No commits yet

    Changes to be committed:
    (use "git rm --cached <file>..." to unstage)
        new file:   f1.txt
        new file:   f2.txt
        new file:   f3.txt

Entonces recuerda. Lo que acabas de hacer es decirle a Git que haga tracking a 
f1.txt, f2.txt y f3.txt. Además acabas de preparar en el STAGE los archivos 
que entrarán en la foto (commit). Realiza el commit y verifica el estado.

Si verificas el historial en este punto, verás que acabas de iniciar el control 
de versión.

.. code-block:: bash 

    commit 6c2e0fc824981b406c68dccc9ef34ad86f9ea8e4 (HEAD -> master)
    Author: jfupb <juanf.franco@upb.edu.co>
    Date:   Thu Jan 13 09:11:27 2022 -0500

        init repo

Ejercicio 13: configura GitHub
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora te pediré que compartas el repositorio local ``demo2`` con el mundo. 
Para hacerlo necesitarás usar GitHub.

#. Crea una cuenta en GitHub o usa la que ya tienes.
#. Descarga e instala la `GitHub cli <https://cli.github.com/>`__ de 
   `aquí <https://github.com/cli/cli#installation>`__. Recuerda seleccionar 
   la opción adecuada según tu sistema operativo y plataforma de hardware.
#. Abre una terminal y ejecuta el comando:

   .. code-block:: bash 

       gh auth login

   El comando anterior te permitirá autorizar el acceso de tu computador 
   a tu cuenta en GitHub por medio de un proceso interactivo entre la terminal 
   y el browser.

Ejercicio 14: comparte tu trabajo usando GitHub
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Abre la terminal y cámbiate al directorio demo2. Ejecuta el siguiente comando:

.. code-block:: bash 

    gh repo create demo2 --public --source=. --push --remote=upstream

``gh repo create demo2`` te permiten crear el repositorio remoto demo2 en 
GitHub. ``--public`` hace que el repositorio sea público y lo puedas compartir 
con cualquier persona. ``--source=.`` especifica en dónde está el 
repositorio. ``--push`` permite enviar todos los commits locales al repositorio 
remoto. Finalmente, ``--remote=upstream`` permite asignarle un nombre corto 
al servidor remoto, en este caso upstream.

Ingresa al sitio: https://github.com/TU_USUARIO/demo2 para observar tu repositorio 
en GitHub. NO OLVIDES modificar la cadena ``TU_USUARIO`` con tu nombre de usuario 
en GitHub.

Ejercicio 15: actualiza tu repositorio remoto
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Realiza los siguientes pasos:

#. Modifica f1.txt
#. Realiza un commit con los cambios

Verifica el estado del repositorio:

.. code-block:: bash 

    git status

    On branch master
    Your branch is ahead of 'upstream/master' by 1 commit.
    (use "git push" to publish your local commits)

    nothing to commit, working tree clean

Observa el mensaje ``Your branch is ahead of 'upstream/master' by 1 commit.`` 
Git detecta que tu repositorio local está adelantado un commit con respecto 
al repositorio remoto. Observa que el propio Git te dice cómo actualizar 
el repositorio remoto:

.. code-block:: bash 

    git push 

Vuelve el verificar el estado:

.. code-block:: bash 

    git status

    On branch master
    Your branch is up to date with 'upstream/master'.

    nothing to commit, working tree clean

Y finalmente el historial:

.. code-block:: bash 

    commit 74f273a64864279df506e95ba496dc2a521cb876 (HEAD -> master, upstream/master)
    Author: jfupb <juanf.franco@upb.edu.co>
    Date:   Thu Jan 13 11:31:50 2022 -0500

        add LINEA 14 to test my remote

    commit 6c2e0fc824981b406c68dccc9ef34ad86f9ea8e4
    Author: jfupb <juanf.franco@upb.edu.co>
    Date:   Thu Jan 13 09:11:27 2022 -0500

        init repo

Mira el texto ``(HEAD -> master, upstream/master)``. Indica que tu repositorio 
local y remoto apuntan al mismo commit.

Ejercicio 16: repasa (evaluación formativa)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

En este punto te pediré que descanses un momento. En este 
ejercicio vas a repasar el material que has trabajo. Te pediré 
que hagas lo siguiente:

#. Crea un directorio llamado demo3. Ten presente cambiarte 
   primero al directorio padre de demo2. NO DEBES tener un repositorio 
   en otro repositorio (se puede hacer, pero aprenderás la manera adecuada
   de hacerlo luego).
#. Inicia un repositorio allí.
#. Crea unos cuantos archivos.
#. Dile a Git que haga tracking de esos archivos.
#. Realiza un primer commit.
#. Crea un repositorio remoto en GitHub que esté sincronizado con 
   tu repositorio local. No olvides comprobar su creación.
#. Modifica los archivos creados.
#. Realiza un par de commits más.
#. Sincroniza los cambios con el repositorio remoto.

Ejercicio 17: clona un repositorio de GitHub
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora vas a descargar un repositorio de GitHub. Cámbiate al directorio padre 
de demo3. Escribe el comando:

.. code-block:: bash 

    gh repo clone juanferfrancoudea/demo4

.. note::

    También puedes usar el comando git clone https://github.com/juanferfrancoudea/demo4.git

Cámbiate al directorio demo4.

#. Verifica el estado del repositorio (status).
#. Verifica el historial (log).
#. Realiza un cambio a f1.txt.
#. Realiza un commit al repositorio local.

Ahora trata de actualizar el repositorio remoto con:

.. code-block:: bash 

    git push
    
Deberías obtener un mensaje similar a este:

.. code-block:: bash 

    remote: Permission to juanferfrancoudea/demo4.git denied to juanferfranco.
    fatal: unable to access 'https://github.com/juanferfrancoudea/demo4.git/': The requested URL returned error: 403

¿Qué está pasando? Lo que ocurre es que el repositorio que clonaste NO ES DE TU PROPIEDAD y por 
tanto NO TIENES permiso de actualizarlo. Para poderlo modificar, el dueño del repositorio te 
debe dar acceso.

.. note::

    Más de una persona puede trabajar en un repositorio siguiendo una serie de pasos 
    y consideraciones. Para aprender más al respecto tendrías que leer sobre Git Workflows. 
    De todas maneras no te preocupes, por ahora hay otras cosas que debes entender y practicar 
    antes de abordar el TRABAJO EN EQUIPO usando Git. PERO OJO, TE RUEGO que más adelante 
    lo aprendas porque será tu día a día cuando estés trabajando en la industria.


Ejercicio 18: repasa (evaluación formativa)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ha llegado la hora de volver a repasar TODOS los comandos que has aprendido. 
Actualiza tu lista de comandos y escribe al frente de cada uno con tus palabras 
qué hace. En este punto ya deberías tener más claridades. Por tanto, revisa de nuevo 
la redacción de los comandos que ya tenías.

Ejercicio 19: entrega de evaluaciones usando GitHub
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
* Abre una nueva pestaña e ingresa a `este <https://classroom.github.com/a/-RlC33Hq>`__ sitio.
* Busca y selecciona tu nombre y ID. Esta operación ENLAZARÁ tu cuenta de GitHub con tu nombre 
  y ID.
* Por último acepta la tarea.
* Espera un momento y refresca (con F5) el browser.
* Abre tu nuevo repositorio en otra pestaña.
* Selecciona el menú Actions y dale click al botón ``Enable Actions on this 
  repository``. Si no aparece el botón es porque ya están habilitadas las acciones.
* Descarga el repositorio a tu computador.
* Ingresa al directorio ``dirTest/project``.
* Lee el archivo ``README.md``. Lo puedes hacer en tu computador y en Internet. Cuando 
  lo leas en tu computador verás que está escrito en un lenguaje llamado 
  `Markdown <https://docs.github.com/en/github/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax>`__. 
  Ve mirando este lenguaje porque lo usarás para escribir la documentación de las evaluaciones. PERO 
  no te preocupes es muy fácil. Además, en un rato te propondré un ejercicio para que practiques. Por 
  otro lado, cuando leas el archivo README.md en GitHub notarás que este lo renderiza para que se 
  vea bonito.
* Observa el archivo wcat.c inicial:

  .. code-block:: c 

        #include <stdio.h>
        #include <stdlib.h>


        int main(int argc, char *argv[]){
            exit(EXIT_SUCCESS);
        }

* Modifica wcat.c con este código:

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
* Luego sincroniza con el repositorio remoto (push). Esto hará que se disparen 
  las pruebas (acciones) en GitHub.
* Ingresa de nuevo al repositorio en GitHub. Ingresa al menú Actions. 
  Espera un minuto y refresca la página. Si todo está bien verás 
  una marca verde al lado izquierdo del commit que enviaste.
* Dale click al mensaje al lado de la marca verde. Luego dale click a 
  Autograding para observar todos los pasos que se realizaron para verificar 
  tu trabajo.

Ejercicio 20: documentación de las evaluaciones
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Todas las entregas que realices deben estar acompañadas de una documentación 
que explique los aspectos técnicos (y otros que te pediré) de la solución que 
propongas a los problemas que te plantearé para las evaluaciones. Lo interesante 
de GitHub es que te permite almacenar repositorios no solo para el código, sino 
también para la documentación. En el ejercicio anterior te hablé del lenguaje con el 
cual se escribió el archivo README.md. Se trata del lenguaje Markdown que será 
el mismo que utilizarás para escribir la documentación de tus entregas. Como 
te comenté antes, no tienes de qué preocuparte, realmente es muy fácil.

#. Crea un directorio llamado demo6. Ten presente cambiarte 
   primero al directorio padre donde están almacenados los demos anteriores.
#. Ahora crea un directorio llamado code y cámbiate a ese directorio.
#. Inicia un repositorio allí.
#. Crea unos cuantos archivos.
#. Dile a Git que haga tracking de esos archivos.
#. Realiza un primer commit.
#. Crea un repositorio remoto en GitHub que esté sincronizado con 
   tu repositorio local. No olvides comprobar su creación.

   .. note:: RECUERDA cómo crear el repositorio

       .. code-block:: bash 

          gh repo create NOMBRE --public --source=. --push --remote=upstream

#. Modifica los archivos creados.
#. Realiza un par de commits más.
#. Sincroniza los cambios con el repositorio remoto.

Hasta aquí nada nuevo, ¿Verdad? 

#. Ingresa a GitHub y selecciona el menú Wiki.
#. Click en el botón Create the first page.
#. Verás que se abre un editor en el cual podrás añadir tu documentación. Además 
   podrás formatearlo en lenguaje Markdown utilizando las ayudas gráficas.
#. Cambia el título del documento por ``DOCUMENTACIÓN DEL DEMO 6``.
#. Indica que ese texto tendrá formato ``h1``.
#. Puedes hacer click en el menú ``preview`` para que puedas ver cómo te va quedando el 
   documento.
#. Ahora te pediré que explores las demás ayudas gráficas para insertar imágenes, 
   hipervínculos, títulos de tipo h2 y h3, negrita, itálica, resaltado y listas ordenadas 
   y no ordenadas.
#. A medida que experimentas ve observando en preview cómo te queda.
#. Una vez termines, dale click al botón ``save page``.
#. Ahora copia la URL que aparece en ``Clone this wiki locally``.
#. Cámbiate al directorio demo6.
#. Clona el repositorio con la documentación así:

   .. code-block:: bash 

       git clone https://github.com/juanferfranco/demo6.wiki.git

Notarás que se ha creado el directorio ``demo6.wiki`` y en el interior un archivo 
llamado Home.md. Si lo abres podrás ver el código de tu documentación. En este punto 
puedes elegir si quieres seguir editando tu documentación localmente o en GitHub; sin 
embargo, para terminar el ejercicio y practicar un poco más te voy a pedir que 
modifiques localmente el documento Home.md y añadas lo siguiente, pero ten en cuenta 
que por cada paso puedes ir realizando un commit local y luego sincronizando con 
el repositorio remoto.

#. Un subtítulo h2.
#. Un texto. En el cuerpo del texto coloca algo en negrita, en itálica y resaltado.
#. Agrega una imagen.
#. Agrega una lista ordenada y no ordenada que contengan hipervínculos.


