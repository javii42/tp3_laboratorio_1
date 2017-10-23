#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int loadFile(EMovie* movie,int t)
{
	int flag = 0;
	FILE *f;
	f=fopen("bin.dat", "rb");
	if(f==NULL)
	{
		f= fopen("bin.dat", "wb");
		if(f==NULL)
		{
			return 1;
		}
		flag=1;
	}
	if(flag ==0)
	{
	fread(movie,sizeof(movie),t,f);
    }
	fclose(f);
	return 0;

}
int agregarPelicula(EMovie* movie, int t){
    int id;
    id = obtenerEspacioLibre(movie,t);
    printf("Ingrese el titulo de la pelicula: ");
    fflush(stdin);
    scanf("%s",(movie+id)->titulo);
    printf("Ingrse el genero de la pelicula: ");
    fflush(stdin);
    scanf("%s",movie->genero);
    printf("Ingrse la duracion de la pelicula(min): ");
    scanf("%d",&(movie+id)->duracion);
    printf("Ingrse una descripcion de la pelicula: ");
    fflush(stdin);
    scanf("%s",(movie+id)->titulo);
    printf("Ingrse el puntaje de la pelicula: ");
    fflush(stdin);
    scanf("%d",&(movie+id)->puntaje);
    printf("Ingrse el link de la imagen de la pelicula: ");
    fflush(stdin);
    scanf("%s",(movie+id)->linkImagen);
    (movie+id)->estado=1;
    (movie+id)->id=id;
    return id;

}

int obtenerEspacioLibre(EMovie* movie, int t){
    int i;
    int espacioLibre = t+1;
    for(i=0;i<t;i++){
        if(movie->estado == 0){
            espacioLibre=i;
            break;
        }
    }
    return espacioLibre;
}
/*
int borrarPelicula(EMovie* movie){

}

void generarPagina(EMovie lista[], char nombre[]){

}*/
void listar(EMovie* movie, int t){
    int i;
    for(i=0;i<t;i++){
        if((movie+i)->estado == 1){
            printf("%s\t%s\t%d\n",(movie+i)->titulo,(movie+i)->descripcion,(movie+i)->duracion);
        }
    }
}
int saveFile(EMovie* movie,int t)
{

	FILE *f;

		f=fopen("bin.dat","wb");
		if(f == NULL)
		{
			return 1;
		}

	fwrite(movie,sizeof(movie),t,f);

	fclose(f);

	return 0;
}
