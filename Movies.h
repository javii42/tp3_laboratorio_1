
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define TAM 100
typedef struct{
    int id;
    char titulo[100];
    char genero[50];
    int duracion;
    char descripcion[500];
    float puntaje;
    char linkImagen[150];
    int estado;
}EMovie;


/**
 *  Crea una lista de punteros, en la cual cada item es otro puntero a una estructura.
 *  @param int*, puntero hacia donde guardaremos la cantidad de estructuras que queremos crear.
 */
void initMovie(int*);

/**
 *  Asigna un espacio de memoria a una estructura
 *  @return Devuelve la direccion de memoria donde se encuentra la estructura
 */
EMovie* newMovie(void);

/**
 *  Devuelve la cantidad de estructuras creadas.
 *  @return int, cantidad de estructuras.
 */
int list_getSize(void);

/**
 *  Libera la memoria
 */
void list_free(void);

/**
 *  Permite agregar y validad los datos que se quieran agregar o modificar en una estructura.
 *  @param puntero a la estructura
 *  @param int, id de la estructura
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int setDataMovie(EMovie*, int);

/**
 *  Obtiene la direccion de memoria de la estructura en la lista de estructuras.
 *  @param int, id de la estructura
 *  @return puntero a la estructura
 */
EMovie* list_get(int i);

/**
 *  Lista una estructura determinada.
 *  @param puntero a la estructura
 */
void toListMovie(EMovie* m);

// ------------------------>

/**
 *  Lee las peliculas del archivo binario
 *  @param puntero a la estructura
 *  @return retorna 1 o 0 de acuerdo a si pudo leer las peliculas o no
 */
int loadFile(EMovie*);

/**
 *  Guarda las peliculas en el archivo binario
 *  @param puntero a la estructura
 *  @return retorna 1 o 0 de acuerdo a si pudo leer las peliculas o no
 */
int saveFile(EMovie*);

/**
 *  Valida y setea el titulo en la estructura
 *  @param movie la estructura a ser agregada al archivo
 *  @param titulo de la pelicula
 */
void setTitulo(EMovie* , char*);

/**
 *  Valida y setea la descripcion en la estructura
 *  @param movie la estructura a ser agregada al archivo
 *  @param descripcion de la pelicula
 */
void setDescripcion(EMovie* ,char*);

/**
 *  Valida y setea el genero en la estructura
 *  @param movie la estructura a ser agregada al archivo
 *  @param genero de la pelicula
 */
void setGenero(EMovie* ,char*);

/**
 *  Valida y setea el link de la imagen en la estructura
 *  @param movie la estructura a ser agregada al archivo
 *  @param link de la imagen de la pelicula
 */
void setLink(EMovie* ,char*);

/**
 *  Valida y setea la duracion en la estructura
 *  @param movie la estructura a ser agregada al archivo
 *  @param duracion de la pelicula
 */
void setDuracion(EMovie* ,int);

/**
 *  Valida y setea el puntaje en la estructura
 *  @param movie la estructura a ser agregada al archivo
 *  @param puntaje de la pelicula
 */
void setPuntaje(EMovie* ,int);

/**
 *  Le asigna mas memoria a la lista de estructuras
 *  @param movie la estructura a ser agregada
 */
void addMovie(EMovie* m);

/**
 *  Borra una pelicula del archivo binario
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int deleteMovie();

/**
 *  Modifica una pelicula del archivo binario
 *  @return retorna 1 o 0 de acuerdo a si pudo modificar la pelicula o no
 */
int updateMovie();

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo array.
 */
void createWebPage();

#endif // FUNCIONES_H_INCLUDED


