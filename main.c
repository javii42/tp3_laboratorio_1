#include <stdio.h>
#include <stdlib.h>
#include "Movies.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int tam=1;
    int cargado;
    int i;
  //  initMovie();
    EMovie* m = newMovie();
    printf("INICIALIZANDO ... \n");
    if(loadFile(m))
    {
        printf("No se pudo abrir el fichero\n");
    }
    else
    {
        printf("Se cargaron las estructuras con exito\n");
    }
    system("pause");
    while(seguir=='s')
    {
        system("cls");
        system("color 1F");
        printf("1- Agregar pelicula\n");
        printf("2- Modificar pelicula\n");
        printf("3- Borrar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");
        printf("Opcion del usuario: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            addMovie(m);
            cargado = setDataMovie(m, list_getSize());
            m = newMovie();
            break;
        case 2:
            system("cls");
            if(list_get(0)== NULL){
                printf("No existen datos para mostrar.\n");
            }else{
                for(i=0; i<list_getSize(); i++)
                {
                    toListMovie(list_get(i));
                }
                if(updateMovie()){
                    printf("Pelicula modificada con exito\n");
                }else{
                    printf("Error al modificar la pelicula\n");
                }
            }
            system("pause");
            break;
        case 3:
            system("cls");
            if(list_get(0)== NULL){
                printf("No existen datos para mostrar.\n");
            }else{
                for(i=0; i<list_getSize(); i++)
                {
                    toListMovie(list_get(i));
                }
                if(deleteMovie()){
                    printf("Pelicula eliminada con exito\n");
                }else{
                    printf("Error al eliminar la pelicula\n");
                }
            }
            system("pause");
            break;
        case 4:
            system("cls");
            if(list_get(0)== NULL){
                printf("No existen datos para mostrar.\n");
            }else{
                for(i=0; i<list_getSize(); i++)
                {
                    toListMovie(list_get(i));
                }
                createWebPage(m);
            }
            system("pause");
            break;
        case 5:
            seguir = 'n';
            break;
        default:
                printf("Error, opcion incorrecta. \n");
                system("pause");
                break;
        }
    }
    if(saveFile(m))
    {
        printf("\nNo se pudo abrir el fichero\n");
    }
    else
    {
        printf("\nSe guardo la informacion con exito\n");
    }
    list_free();
    return 0;
}
/*  else
  {
      printf("No hay suficiente espacio en memoria para correr el sistema");
  }*/
