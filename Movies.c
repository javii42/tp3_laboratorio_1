
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Movies.h"

int listSize;
EMovie** movie;
int index;

void initMovie(int* i)
{
    index = 0;
    printf("Inicializado: %d\n",*i);
    listSize=(*i)+2;
    movie = (EMovie**)malloc(sizeof(EMovie*)*listSize); // Ahora cada item del array es un puntero a una estructura
}

void addMovie(EMovie* m)
{
    movie[index]=m; /
    index++;
    //  printf("INDEX: %d\n",index);
    // si no hay mas lugar, pedimos más memoria para hacer un array más grande
    if(index>=listSize)
    {
      //  printf("listSize: %d\n",listSize);
        listSize+=2; // agregamos dos mas
        movie = (EMovie**)realloc(movie,sizeof(EMovie*)*listSize);
    }

}


EMovie* newMovie(void)
{
    EMovie* m = (EMovie*)malloc(sizeof(EMovie)); 
    return m;
}

EMovie* list_get(int i)
{
    if(i<index)
    {
        return movie[i];
    }

    return NULL;
}

int list_getSize(void)
{
    return index;
}

void list_free(void)
{
    free(movie);

}

int setDataMovie(EMovie* m, int id)
{
    char titulo[10000];
    char genero[5000];
    int duracion;
    char descripcion[5000];
    int puntaje;
    char linkImagen[1500];
    if(id>index)
    {
        return 0;
    }
    else
    {
        printf("Ingrese el titulo de la pelicula: ");
        fflush(stdin);
        gets(titulo);
        setTitulo(m,titulo);
        printf("Ingrese el genero de la pelicula: ");
        fflush(stdin);
        gets(genero);
        setGenero(m,genero);
        printf("Ingrese la duracion de la pelicula (min): ");
        fflush(stdin);
        scanf("%d",&duracion);
        setDuracion(m,duracion);
        printf("Ingrese una descripcion de la pelicula: ");
        fflush(stdin);
        gets(descripcion);
        setDescripcion(m,descripcion);
        printf("Ingrese el puntaje de la pelicula (1-10): ");
        fflush(stdin);
        scanf("%d",&puntaje);
        setPuntaje(m,puntaje);
        printf("Ingrese el link de la imagen de la pelicula: ");
        fflush(stdin);
        gets(linkImagen);
        setLink(m,linkImagen);
        m->estado=1;
        m->id=id;
        return 1;
    }
}


void toListMovie(EMovie* m)
{
    printf("\nPELICULA ID- %d\n",m->id);
    printf(" TITULO: %s\n GENERO: %s\n DESCRIPCION: %s\n DURACION: %d\n PUNTAJE: %.2f\n LINK: %s\n",m->titulo,m->genero,m->descripcion,m->duracion,m->puntaje,m->linkImagen);

}


void setTitulo(EMovie* m, char* titulos)
{
    while(strlen(titulos) > 100)
    {
        printf("\n Titulo demasiado largo, por favor abrevielo: ");
        fflush(stdin);
        scanf("%[^\n]%*c",titulos);
    }
    strcpy(m->titulo,titulos);
}
void setGenero(EMovie* m, char* genero)
{
    while(strlen(genero) > 50)
    {
        printf("\n Genero demasiado largo, por favor abrevielo: ");
        fflush(stdin);
        scanf("%[^\n]%*c",genero);
    }
    strcpy(m->genero,genero);
}

void setDuracion(EMovie* m, int duracion)
{
    while(duracion < 1 || duracion > 600)
    {
        printf("\n Tiempo, en minutos, invalido. Por favor ingreselo nuevamente: ");
        fflush(stdin);
        scanf("%d",&duracion);
    }
    m->duracion = duracion;
}
void setDescripcion(EMovie* m, char* descripcion)
{
    while(strlen(descripcion) > 500)
    {
        printf("\n Descripcion demasiado larga, por favor abreviela: ");
        fflush(stdin);
        scanf("%[^\n]%*c",descripcion);
    }
    strcpy(m->descripcion, descripcion);
}
void setPuntaje(EMovie* m, int puntaje)
{
    while(puntaje < 1 || puntaje > 10)
    {
        printf("\n Puntaje invalido. Por favor ingreselo nuevamente: ");
        fflush(stdin);
        scanf("%d",&puntaje);
    }
    (m->puntaje) = puntaje;
}

void setLink(EMovie* m, char* link)
{
    while(strlen(link) > 150)
    {
        printf("\n Link demasiado largo, por favor cargue otro: ");
        fflush(stdin);
        scanf("%[^\n]%*c",link);
    }
    strcpy(m->linkImagen, link);
}


int deleteMovie()
{
    int i;
    int id;
    printf("Ingrese el ID de la pelicula que desea eliminar: ");
    scanf("%d",&id);
    id = id-1;
    //printf("ID: %d \n",id);
    if(index!=0 && id<index)
    {
        printf("\n");
        toListMovie(list_get(id));

        for(i=id ; i<index-1; i++)
        {
            // list_get(i)->id--;
            movie[i]=movie[i+1];
            movie[i]->id= i+1;
        }
        index--;
        return 1;
    }
    else
    {
        return 0;
    }
}

int updateMovie()
{
    int i;
    int id;
    printf("Ingrese el ID de la pelicula que desea modificar: \n");
    scanf("%d",&id);
    id = id-1;
    if(index!=0 && id<index)
    {
        setDataMovie(movie[id],id+1);
        return 1;
    }
    else
    {
        return 0;
    }
}
// ------------------------------->


int loadFile(EMovie* m)
{
    int flag = 0;
    int c=0;
    int i;
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
        printf("ListSize: %d\n", c);
        initMovie(&c);
    }
    if(flag ==0)
    {
        fread(&c,sizeof(int),1,f);
        printf("ListSize: %d\n", c);
        initMovie(&c);
        for(i =0; i<c; i++)
        {
            m = newMovie();
            fread(m,sizeof(EMovie),1,f);
            addMovie(m);
        }
    }
    fclose(f);
    return 0;

}
int saveFile(EMovie* m)
{
    int i;
    FILE *f;

    f=fopen("bin.dat","wb");
    if(f == NULL)
    {
        printf("No se pudo abrir el fichero");
    }
    else
    {
        fwrite(&index,sizeof(int),1,f);
        printf("INDEX: %d\n", index);
        for(i=0; i<list_getSize(); i++)
        {
            fwrite(list_get(i),sizeof(EMovie),1,f);
        }
        //fwrite(*movie,sizeof(EMovie)+sizeof(int),index+1,f);
    }
    fclose(f);

    return 0;
}
void createWebPage()
{
    int i;
    FILE *f;
    f=fopen("./template/index.html", "w");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        fprintf(f,"<!DOCTYPE html> <html lang = 'en'> <head> <meta charset = 'utf-8'> ");
        fprintf(f,"<meta http-equiv='X-UA-Compatible' content='IE=edge'> ");
        fprintf(f,"<meta name='viewport' content='width=device-width, initial-scale=1'>  <title>Lista peliculas</title>");
        fprintf(f,"<link href='css/bootstrap.min.css' rel='stylesheet'> ");
        fprintf(f,"<link href='css/custom.css' rel='stylesheet'> ");
        fprintf(f,"</head> ");
        fprintf(f,"<body> ");
        fprintf(f,"<div class='container'> ");
        fprintf(f,"<div class='row'> ");
        for(i=0; i<list_getSize(); i++)
        {
            if(list_get(i)->estado == 1)
            {
                fprintf(f,"<article>\n");
                fprintf(f,"<a href='#'><img class='img-responsive img-rounded' src='%s'alt=''></a>",list_get(i)->linkImagen);
                fprintf(f,"<H2>%s</H2>\n",list_get(i)->titulo);
                fprintf(f,"<ul><li>Genero:%s</li><li>Puntaje:%.2f</li><li>Duracion:%d</li></ul><p>%s</p></article><br /><hr />",list_get(i)->genero,list_get(i)->puntaje,list_get(i)->duracion,list_get(i)->descripcion);
                /* printf("PELICULA N° %d\n",(movie+i)->id);
                 printf(" TITULO: %s\n GENERO: %s\n DESCRIPCION: %s\n DURACION: %d\n PUNTAJE: %d\n LINK: %s\n\n",(movie+i)->titulo,(movie+i)->genero,(movie+i)->descripcion,(movie+i)->duracion,(movie+i)->puntaje,(movie+i)->linkImagen);
                */
            }
        }
        fprintf(f,"</div> ");
        fprintf(f,"</div> ");
        fprintf(f,"<script src='js/jquery-1.11.3.min.js'></script> ");
        fprintf(f,"<script src='js/bootstrap.min.js'></script> ");
        fprintf(f,"<script src='js/ie10-viewport-bug-workaround.js'></script> ");
        fprintf(f,"<script src='js/holder.min.js'></script> ");
        fprintf(f,"</body> ");
        fprintf(f,"</html> ");

    }

    fclose(f);

    printf("\nPagina web creada con exito\n");
}


