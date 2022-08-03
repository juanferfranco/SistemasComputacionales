Evaluación 1
====================================================

Enunciado
-----------
(El framework de pruebas para esta evaluación está tomado de 
`aquí <https://github.com/remzi-arpacidusseau/ostep-projects>`__)

#. Ingresa y acepta la evaluación en 
   `este <https://classroom.github.com/a/VlWvsCi->`__ enlace.
#. Clone el repositorio con tu evaluación en tu computador local.
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

    * Adiciona un título de tipo H1 que diga: EVALUACIÓN 1
    * Adicionar un texto corto.
    * Adiciona una imagen.
    * Adiciona un hipervínculo.
    * Una lista ordenada con los comandos para:  
     
      * Clonar tu repositorio de la evaluación.
      * Adicionar un archivo al STAGE.
      * Realizar un commit.
      * Sincronizar con el repositorio remoto.

Criterios de calificación
--------------------------

#. Pasar todas las pruebas: 4 unidades.
#. Realizar correctamente la documentación 1 unidad.
