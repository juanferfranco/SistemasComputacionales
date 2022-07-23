Trabajo en equipo git y GitHub
====================================================

Ahora que ya sabes hacer algunas operaciones básicas con Git y GitHub, 
vas a aprender a trabajar en equipo con otros compañeros

Trayecto de actividades
---------------------------------

Lectura 1: el concepto de ramas 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Recuerdas qué es un commit?

.. note:: ALERTA DE SPOILER

    Un commit es una foto del proyecto en un punto del tiempo.

En Git SOLO puedes trabajar con un commit a la vez; sin embargo, 
puedes tener diferente RAMAS apuntando a diferentes commits. De 
esta manera tienes un mecanismo que te permite saltar fácilmente 
de un commit a otro.

Por ahora solo hemos trabajado con la rama ``master``, pero cuando 
queremos trabajar en equipo es necesario crear muchas más ramas. Las 
ramas te permite crear secuencias independientes de commits. De esta 
manera es posible que dos o más personas puedan trabajar simultáneamente 
en el mismo proyecto sin problema siempre y cuando cada una trabaje 
en una rama diferente.

Ejercicio 1: creación de ramas 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Considera la siguiente figura:

.. image:: ../_static/projectInit.svg
    :alt: Inicio del proyecto

Acabas de iniciar un proyecto, tu estás en la rama 
master y acabas de realizas el primer commit (tomas la primera foto). 
Ahora aparece un nuevo compañero que comienza a trabajar a partir de tu commit, 
pero en una nueva rama llamada feature1:

.. image:: ../_static/projectFeatur1Init.svg
    :alt: Inicia feature1

Tu y tu compañero podrán seguir trabajando en paralelo, cada uno en su propia rama, 
es decir, tu en la rama master y tu compañero en la rama feature1:

.. image:: ../_static/projectMasterAndFeature1.svg
    :alt: Trabajo en paralelo de master y feature1

El proyecto sigue progresando y ahora se une otro compañero:

.. image:: ../_static/projectMasterF1F2.svg
    :alt: se añade feature2

Entonces para crear una rama debes ejecutar::

    git switch -c feature1

Ejercicio 3: experimenta
^^^^^^^^^^^^^^^^^^^^^^^^^

Considera la última figura del ejercicio anterior. ¿Te animas a reproducirla? 
La idea es que simules que en un proyecto están trabajando tres personas, una 
para master, otra para feature1 y la otra para feature2.

.. note:: ALERTA DE SPOILER

    Te dejo los primeros comandos, pero tu terminas de completar

Los comandos serían::

    mkdir project
    git init
    touch f1
    git add f1
    git commit -m "add f1 to master"
    git switch -c feature1
    git add f2
    git commit -m "add f2 to feature1"
    git switch master
    git add f3
    git commit -m "add f3 to master"
    git switch feature1
    git add f4
    git commit -m "add f4 to feature1"





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
    posicionado. 
    
    Trata de recordar de nuevo ¿Qué era ``..``?

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

Y solo con esto ya tienes un proyecto con control de versión. ¿Fácil, no?

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

Escribe los siguientes comandos, pero cambia name y email por tus datos::

    git config --local user.name "yo"
    git config --local user.email "yo@yolandia.com"


Ejercicio 7: para pensar
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Qué crees qué pase si borras el directorio ``.git`` en relación con el historial
de cambios de tus archivos?

¿Qué crees que pase si creas un directorio vacío y mueves allí todo los archivos 
de tu proyecto incluyendo el directorio .git?

Ejercicio 8: reconocer el estado del repositorio 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora ejecuta el siguiente comando::

    git status

Verás algo así::

    On branch master

    No commits yet

    Untracked files:
    (use "git add <file>..." to include in what will be committed)
        main.c

    nothing added to commit but untracked files present (use "git add" to track)


El resultado por ahora es muy interesante. Verás que estás trabajando en la 
rama (branch) master. Las ramas son una característica MUY útil de Git. Como 
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

Ahora observa el mensaje ``No commits yet``. Este mensaje quiere decir que aún no has guardado 
nada en el repositorio.  Luego te dice ``Untracked files`` y te muestra una lista de los 
archivos detectados en tu proyecto (main.c en este caso), pero que no están bajo control 
de versión. Tu debes decirle explícitamente a Git a qué archivos debe hacer ``tracking``.
Finalmente, ``nothing added to commit but untracked files present (use "git add" to track)`` quiere 
decir que si en este momento le pides a Git que guarde en el repositorio una ``FOTO`` (``commit``) 
del estado actual de los archivos que están bajo tracking, Git te dice que no hay nada para guardar.
Nota que Git da sugerencias: ``(use "git add" to track)``, es decir, te dice qué necesitas 
hacer para colocar el archivo main.c en tracking.


Ejercicio 9: adiciona tu primer archivo al repositorio 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: bash 

    git add main.c 

Y de nuevo observa el estado del repositorio::

    git status

El resultado será::

    On branch master

    No commits yet

    Changes to be committed:
    (use "git rm --cached <file>..." to unstage)
        new file:   main.c


Te explico con una metáfora lo que está pasando. Imagina que Git 
le toma fotos al estado de tu proyecto cada que se lo solicitas; sin embargo, 
antes de tomar la foto tienes que decirle a Git (``con add``) a qué archivos 
le tomará la foto. Todos los archivos que serán tenidos en cuenta para la 
próxima foto se ubican en una zona lógica denominada el ``STAGE``. Mira el mensaje 
``(use "git rm --cached <file>..." to unstage)``. Observa que Git te está diciendo
que main.c ya está listo para la foto (``Changes to be committed``), pero si te arrepientes de incluir el archivo 
en la foto puedes ejecutar el comando sugerido. Prueba sacar de la foto a main.c::

    git rm --cache main.c

Mira el estado del repositorio::

    git status

Verás algo así::

    On branch master

    No commits yet

    Untracked files:
    (use "git add <file>..." to include in what will be committed)
        main.c

    nothing added to commit but untracked files present (use "git add" to track)


¿Te das cuenta? Acabas de sacar de la foto (DEL STAGE) a main.c. Ahora vuelve a invitar a 
main.c a la foto::

    git add main.c 

Ahora ``TOMA LA FOTO`` (realiza el commit)::

    git commit -m "Initial version of the project main file"

Consulta el estado del repositorio::

    git status

El resultado será::

    On branch master
    nothing to commit, working tree clean

Puedes ver que Git está observando todo lo que pasa en el directorio de tu 
proyecto. Por ahora Git sabe que no has hecho nada más y por eso te dice 
``nothing to commit, working tree clean``.

Lo último que te voy a pedir que hagas con este ejercicio es que le preguntes 
a Git qué fotos (``COMMITS``) se han tomado en el repositorio::

    git log 

El resultado es::

    commit 1f2009fabfc4895ee6b063c23c6f5c7ea7175209 (HEAD -> master)
    Author: yo <yo@yolandia.com>
    Date:   Wed Jul 20 10:52:46 2022 -0500

        Initial version of the project main file

Nota que el commit está identificado con el hash ``1f2009fabfc4895ee6b063c23c6f5c7ea7175209``, 
el autor, correo, fecha, hora y la descripción del commit.

Ejercicio 10: recuerda
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Para un momento. Repasa los ejercicios anteriores, actualiza tu lista 
de comandos con la explicación de qué hacen.

Ejercicio 11: modificar el contenido de un archivo 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Modifica el contenido del archivo main.c añadiendo otro mensaje para imprimir 
(escribe lo que tu corazón te dicte). ``Salva el archivo``. NO LO OLVIDES, salva 
el archivo.

Al verificar el estado del repositorio verás::

    On branch master
    Changes not staged for commit:
    (use "git add <file>..." to update what will be committed)
    (use "git restore <file>..." to discard changes in working directory)
        modified:   main.c

    no changes added to commit (use "git add" and/or "git commit -a")

¿Ves la diferencia con respecto al momento en el que creaste el archivo? Déjame recordarte 
el mensaje:

.. code-block:: bash 

    On branch master

    No commits yet

    Untracked files:
    (use "git add <file>..." to include in what will be committed)
        main.c

    nothing added to commit but untracked files present (use "git add" to track)

Nota que al crear el archivo, Git te dice que no le está haciendo seguimiento (untracked); 
sin embargo, una vez está creado el archivo y lo modificas, Git te dice 
``Changes not staged for commit``. 

En este caso, Git le hace tracking a tu archivo, pero tu no has decidido pasar el 
archivo a ``STAGE`` para poderle tomar la foto con los cambios que tiene ahora. 
¿Cómo lo haces? Mira que en el mensaje Git te dice: ``git add main.c``. Nota que Git 
también te dice que puedes descartar los cambios en el archivo con 
``git restore main.c``. ¿Por qué no haces la prueba?

Escribe::

    git restore main.c

Vuelve a visual studio code y verifica qué paso con el archivo.

¿Ya no está la modificación anterior, cierto? Mira el estado del repositorio::

    On branch master
    nothing to commit, working tree clean

Vuelve a modificar main.c, pero esta vez si guardarás los cambios 
en el repositorio. Recuerda los pasos:

#. Cambias el archivo
#. Verifica el estado del repositorio (status)
#. Adiciona los cambios en el STAGE (add) 
#. Toma la foto (commit)
#. Verifica de nuevo el estado del repositorio (status)
#. Verifica el historial del repositorio (log)

Te debe quedar algo así::

    commit 2a0afbb7efa9c58a364143edf6c5cf76dccfab0b (HEAD -> master)
    Author: yo <yo@yolandia.com>
    Date:   Wed Jul 20 11:02:03 2022 -0500

        add a new print

    commit 1f2009fabfc4895ee6b063c23c6f5c7ea7175209
    Author: yo <yo@yolandia.com>
    Date:   Wed Jul 20 10:52:46 2022 -0500

        Initial version of the project main file    

Y ahora main.c está así::

    #include <stdio.h>
    #include <stdlib.h>

    int main(){
        printf("La vida es bella\n");
        printf("El feo es uno\n");
        return(EXIT_SUCCESS);
    }


Ejercicio 12: volver a una versión anterior del proyecto 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora supón que quieres volver a una versión anterior del proyecto. 
Git ofrece varias alternativas que irás aprendiendo con el tiempo. Por ahora, 
piensa que lo que harás es pedirle a Git que traiga una versión del pasado y haga 
un nuevo commit de esa versión en el presente.

¿Cuál versión del proyecto quieres recuperar? Para saberlo puedes leer 
el historial de mensajes que adicionaste a cada COMMIT::

    git log --oneline

En el ejemplo que estás trabajando::

    2a0afbb (HEAD -> master) add a new print
    1f2009f Initial version of the project main file

Ahora digamos que deseas ver cómo estaba el proyecto en el commit 1f2009f (estos son 
los primeros 7 números del identificador del commit o hash único que se calcula con 
el algoritmo sha-1)::

    git checkout 1f2009f

El resultado es::

    Note: switching to '1f2009f'.

    You are in 'detached HEAD' state. You can look around, make experimental
    changes and commit them, and you can discard any commits you make in this
    state without impacting any branches by switching back to a branch.

    If you want to create a new branch to retain commits you create, you may
    do so (now or later) by using -c with the switch command. Example:

    git switch -c <new-branch-name>

    Or undo this operation with:

    git switch -

    Turn off this advice by setting config variable advice.detachedHead to false

    HEAD is now at 1f2009f Initial version of the project main file

Escribe el comando::

    git status

El resultado es::

    HEAD detached at 1f2009f
    nothing to commit, working tree clean

Ahora revisa el archivo main.c. ¿Qué concluyes hasta ahora? En este momento estás en 
un estado especial llamado detached HEAD. En este estado puedes jugar con el código y 
hacer ensayos y luego puedes descartar todo lo que hagas sin dañar lo que ya tenías. Mira 
que Git te dice qué debes hacer para conservar los experimentos o para descartarlos.

En este caso, supon que solo quieres ver el estado del archivo main.c en el commit 1f2009f::

    #include <stdio.h>
    #include <stdlib.h>

    int main(){
        printf("La vida es bella\n");
        return(EXIT_SUCCESS);
    }

¿Quieres volver main.c al último commit? Simplemente escribes::

    git switch -

Ahora main.c se verá así::

    #include <stdio.h>
    #include <stdlib.h>

    int main(){
        printf("La vida es bella\n");
        printf("El feo es uno\n");
        return(EXIT_SUCCESS);
    }

Luego de analizar las dos versiones de main.c decides que vas a conservar la versión del 
commit 1f2009f. Para que compares escribe::

    git log --oneline

El resultado::

    2a0afbb (HEAD -> master) add a new print
    1f2009f Initial version of the project main file

Ahora::

    git revert HEAD

El resultado::

    [master 882d93e] Revert "add a new print"
    1 file changed, 1 deletion(-)

Y si observas el historial::

    git log --oneline

Verás::

    882d93e (HEAD -> master) Revert "add a new print"
    2a0afbb add a new print
    1f2009f Initial version of the project main file

Si abres el archivo main.c::

    #include <stdio.h>
    #include <stdlib.h>

    int main(){
        printf("La vida es bella\n");
        return(EXIT_SUCCESS);
    }

Entonces el comando::

    git revert HEAD

Hace un ``revert`` del commit ``2a0afbb`` creando un nuevo commit, el ``882d93e``, con el 
estado del proyecto en el commit ``1f2009f``.    


Ejercicio 13: configura GitHub
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora te pediré que compartas el repositorio local ``project1`` con el mundo. 
Para hacerlo necesitarás usar GitHub. 

Abre tu browser y cierra la cuenta que esté activa en GitHub en este momento, claro, 
a menos que sea tu cuenta.

Abre una terminal y ejecuta el comando::

       gh auth logout

Este comando termina la sesión del cliente de Git de tu computador con el servidor de 
Github. Pero el cliente de Git que corre en el browser sigue funcionando con el usuario
actual. Ten presente que CONTROLAR quien está autenticado con el servidor lo haces cuando 
compartes computador con otros compañeros, pero si estás trabajando con tu computador 
personal no es necesario.

Ahora conecta el cliente local de git con tu cuenta de GitHub::

    gh auth login

Acepta todas las opciones por defecto. Una vez hagas todo correctamente saldrá algo similar 
a esto::

    ✓ Authentication complete.
    - gh config set -h github.com git_protocol https
    ✓ Configured git protocol
    ✓ Logged in as juanferfranco    


El comando anterior te permitirá autorizar el acceso desde la termina de tu computador 
a tu cuenta en GitHub por medio de un proceso interactivo entre la terminal 
y el browser. Recuerda que en el browser ya tienes acceso a tu cuenta en el servidor.

En este punto tu computador tiene dos clientes autenticados con GitHub: la terminal y 
el browser.

Ejercicio 14: comparte tu trabajo usando GitHub
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora ejecuta el siguiente comando::

    gh repo create project1 --public --source=. --push --remote=origin

Si todo sale bien verás esto::

    ✓ Created repository juanferfranco/project1 on GitHub
    ✓ Added remote https://github.com/juanferfranco/project1.git
    ✓ Pushed commits to https://github.com/juanferfranco/project1.git
    ➜  project1 git:(master)

¿Qué estás haciendo? ``gh repo create project1``  te permiten crear el repositorio 
remoto project1 en GitHub. ``--public`` hace que el repositorio sea público y lo puedas compartir 
con cualquier persona. ``--source=.`` especifica en dónde está el 
repositorio local que enviarás a Internet. ``--push`` permite enviar todos los commits locales al repositorio 
remoto. Finalmente, ``--remote=origin`` permite asignarle un nombre corto 
al servidor remoto, en este caso ``origin``.

Ingresa al sitio: https://github.com/TU_USUARIO/project1 para observar tu repositorio 
en GitHub. NO OLVIDES modificar la cadena ``TU_USUARIO`` con tu nombre de usuario 
en GitHub.

Ejercicio 15: actualiza tu repositorio remoto
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora modifica de nuevo el archivo main.c así::

    #include <stdio.h>
    #include <stdlib.h>

    int main(){
        printf("La vida es bella!!!\n");
        return(EXIT_SUCCESS);
    }

Realiza un commit en el respositorio local::

    git commit -am "add exclamation marks"


¿Notaste algo? En un solo paso pasaste main.c a la zona de fotos (STAGE) y 
realizaste el commit.

Verifica el estado del repositorio::

    On branch master
    Your branch is ahead of 'origin/master' by 1 commit.
    (use "git push" to publish your local commits)

    nothing to commit, working tree clean

Observa el mensaje ``Your branch is ahead of 'origin/master' by 1 commit.`` 
Git detecta que tu repositorio local está adelantado un commit con respecto 
al repositorio remoto. Observa que el propio Git te dice cómo actualizar 
el repositorio remoto::

    git push 

Vuelve el verificar el estado::

    git status

Y el resultado será::

    On branch master
    Your branch is up to date with 'origin/master'.

    nothing to commit, working tree clean


Y finalmente vuelve a mirar el historial del proyecto::

    git log 

El resultado será::

    commit 56cef2b7d4a8f6fd03dcf302890d4e110cccb861 (HEAD -> master, origin/master)
    Author: yo <yo@yolandia.com>
    Date:   Wed Jul 20 16:02:12 2022 -0500

        add exclamation marks

    commit 882d93e233a7634ae03566c267f5cb9e55a42f45
    Author: yo <yo@yolandia.com>
    Date:   Wed Jul 20 15:22:00 2022 -0500

        Revert "add a new print"
        
        This reverts commit 2a0afbb7efa9c58a364143edf6c5cf76dccfab0b.

    commit 2a0afbb7efa9c58a364143edf6c5cf76dccfab0b
    Author: yo <yo@yolandia.com>
    Date:   Wed Jul 20 11:02:03 2022 -0500

        add a new print

    commit 1f2009fabfc4895ee6b063c23c6f5c7ea7175209
    Author: yo <yo@yolandia.com>
    Date:   Wed Jul 20 10:52:46 2022 -0500

        Initial version of the project main file

Mira el texto ``(HEAD -> master, origin/master)``. Indica que tu repositorio 
local y remoto apuntan al mismo commit.

Ejercicio 16: repasa (evaluación formativa)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

En este punto te pediré que descanses un momento. En este 
ejercicio vas a repasar el material que has trabajo. Te pediré 
que hagas lo siguiente:

#. Crea un directorio llamado project2. Ten presente cambiarte 
   primero al directorio padre de project1. NO DEBES tener un repositorio 
   en otro repositorio.
#. Inicia un repositorio allí.
#. Crea unos cuantos archivos de texto.
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
de project2. Escribe el comando::

    git clone https://github.com/juanferfrancoudea/demo4.git

Cámbiate al directorio demo4.

#. Verifica el estado del repositorio (status).
#. Verifica el historial (log).
#. Realiza un cambio a f1.txt.
#. Realiza un commit al repositorio local.

Ahora trata de actualizar el repositorio remoto con::

    git push
    
Deberías obtener un mensaje similar a este::

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
Actualiza tu lista de comandos y escribe al frente de cada uno, con tus palabras,  
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
* Abre una nueva pestaña e ingresa a `este <https://classroom.github.com/a/sXNRDAEb>`__ sitio.
* Busca y selecciona tu nombre y ID. Esta operación ENLAZARÁ tu cuenta de GitHub con tu nombre 
  y ID.
* Por último acepta la tarea.
* Espera un momento y refresca (con F5) el browser.
* Abre tu nuevo repositorio en otra pestaña.
* Selecciona el menú Actions y dale click al botón ``Enable Actions on this 
  repository``. Si no aparece el botón es porque ya están habilitadas las acciones.
* CLONA el repositorio a tu computador. En tu repositorio despliega el botón ``Code``, selecciona 
  la pestaña http y copia la URL de tu repositorio. Usa esta URL con el comando git clone. Recuerda 
  NO CLONAR el respositorio dentro de otro repositorio LOCAL.
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

#. Crea un directorio llamado project4. Ten presente cambiarte 
   primero al directorio padre donde están almacenados los projects anteriores.
#. Inicia un repositorio allí.
#. Crea unos cuantos archivos.
#. Dile a Git que haga tracking de esos archivos.
#. Realiza un primer commit.
#. Crea un repositorio remoto en GitHub que esté sincronizado con 
   tu repositorio local. No olvides comprobar su creación.

   .. note:: RECUERDA cómo crear el repositorio

       .. code-block:: bash 

          gh repo create NOMBRE --public --source=. --push --remote=origin

#. Modifica los archivos creados.
#. Realiza un par de commits más.
#. Sincroniza los cambios con el repositorio remoto.

Hasta aquí nada nuevo, ¿Verdad? 

#. Ingresa a GitHub y selecciona la opción Create New File en el botón ``Add file``.
#. Le vas a poner de nombre ``README.md``.
#. Verás que se abre un editor en el cual podrás añadir tu documentación. Además 
   podrás formatearlo en lenguaje Markdown.
#. En `este <https://www.markdownguide.org/cheat-sheet/>`__ sitio puedes encontrar una 
   cheat sheet del lenguaje.
#. Cambia el título del documento por ``DOCUMENTACIÓN DEL PROJECT 4``.
#. Indica que ese texto tendrá formato ``h1`` colocando el símbolo ``#`` seguido de un espacio antes del título.
#. Puedes hacer click en el menú ``preview`` para que puedas ver cómo te va quedando el 
   documento.
#. Ahora te pediré que insertes una imagen, un hipervínculo, un título de tipo h2 y otro tipo h3, 
   escribas unas cuantas líneas de texto y coloques una palabra en negrita, itálica y resaltada,
   crea una lista ordenada y una lista no ordenada.
#. A medida que experimentas ve observando en preview cómo te queda.
#. Una vez termines, dale click al botón ``Commit changes``.
#. Regresa al inicio del repositorio para que veas tu obra de arte.
#. En este ejercicio creaste un archivo en GitHub que no tienes en tu computador local. Escribe 
   en tu repositorio local los comando::
    
    git fetch
    git status
    git pull
    git status

   ¿Qué puedes ver en el primer status y luego en el segundo? ¿Alguna diferencia?

.. note:: ESCRIBIR documentos en GitHub

    En `este <https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax>`__ 
    enlace puedes encontrar más información.