#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
   // EMovie movie[TAM] = {};
   EMovie* movie;
    movie = calloc(TAM,sizeof(movie));
    if(loadFile(movie,TAM))
	{
		printf("No se pudo abrir el fichero");
	}
	else
	{
		printf("Se cargaron las estructuras con exito\n");
	}
    system("pause");
    while(seguir=='s')
    {
        system("cls");
        system("color 1A");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                agregarPelicula(&movie,TAM);
                break;
            case 2:
                break;
            case 3:
                system("cls");
                listar(&movie,TAM);
                system("pause");
               break;
            case 4:
                seguir = 'n';
                break;
        }
    }
    if(saveFile(movie,TAM))
    {
        printf("\nNo se pudo abrir el fichero\n");
    }
    else
    {
        printf("\nSe guardo la informacion con exito\n");
    }
    return 0;
}
