/// Librerías
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// Definimos variables
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"


///Funciones
void Borrar();

/// Estructuras
typedef struct                  /** Componentes de una carta **/
{
    char numero;
    char palo;
}e_carta;

typedef struct                  /** Cosas del jugador **/
{
    e_carta carta[20];         /* Estructura anidada en otra */
    char nombre[100];
    int monedero;
}jugador;

typedef struct
{
    e_carta carta[20];
    char nombre[100];
}dealer;

/// Programa
int main()
{
    system("cls");
    FILE *F_prueba;
    dealer crupier = {.nombre = "Susana Picado"};
    char carta[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', '\0'};                 /** Números Posibles **/
    char palo[] = { 3, 4, 5, 6, '\0' };                                                                     /** Palos Posibles **/
    int n_c, i;
    char nc, pc;
    int num_jug, i1;
    srand(time(NULL));
    F_prueba = fopen("Prueba_de_Ficheros.txt", "w");
    if (F_prueba == NULL)
    {
        printf("Error al abrir el fichero.\n");
        return -1;
    }
    else
    {
        printf("Fichero abierto correctamente");
    }
    do
    {
        system("cls");
        printf("Hola, Bienvenido al Blackjack. Mi nombre es %s y ser%c vuestra crupier hoy d%ca. \n", crupier.nombre, 130, 161);
        printf("Por favor, seguid mis indicaciones en todo momento, y contestad coherentemente a las preguntas que haga.\n");
        printf("Elija un n%cmero de jugadores de 1 a 7.\n", 163);
        scanf("%i",&num_jug);
    }while ((num_jug<1)||(num_jug>7));

    jugador participante[num_jug];

    for(i1=0; i1 < num_jug;i1++)
    {
        printf("Introducid el nombre del participante %i:\n", i1+1);
        scanf("%49s[^\n]", participante[i1].nombre);
        fflush(stdin);
        do
        {
            printf("Elija la cantidad inicial con la que %s quiere empezar a jugar (Cantidad entera): \n", participante[i1].nombre);
            scanf("%i", &participante[i1].monedero);
            fprintf(F_prueba, "El nombre del participante %i es: %s\n", i1+1, participante[i1].nombre);
            fprintf(F_prueba, "El tiene %i €.\n", participante[i1].monedero);
        }while((participante[i1].monedero <=0));
        printf("\n");
    }
    for(i1=0; i1 < num_jug;i1++)
    {
        for(i = 0; i < 2; i++)
            {
                nc = rand()%13;
                pc = rand()%4;
                if(carta[nc] == carta[9])
                {
                    n_c = 10;
                    participante[i1].carta[i].numero = n_c;
                    participante[i1].carta[i].palo = palo[pc];
                }
                else
                {
                    participante[i1].carta[i].numero = carta[nc];
                    participante[i1].carta[i].palo = palo[pc];
                }
            }
    }

    for(i1 = 0; i1 < num_jug; i1++)
    {
        printf("Las cartas de %s son:\t", participante[i1].nombre);
        for(i = 0; i < 2; i++)
        {
            if(participante[i1].carta[i].numero == 10)
            {
                if((participante[i1].carta[i].palo == 3)||(participante[i1].carta[i].palo == 4))
                {
                    printf(ANSI_COLOR_RED);
                    printf("%i%c ", participante[i1].carta[i].numero, participante[i1].carta[i].palo);
                    printf(ANSI_COLOR_RESET);
                }
                else
                {
                    printf("%i%c ", participante[i1].carta[i].numero, participante[i1].carta[i].palo);
                    printf(ANSI_COLOR_RESET);
                }
            }
            else
            {
                if((participante[i1].carta[i].palo == 3)||(participante[i1].carta[i].palo == 4))
                {
                    printf(ANSI_COLOR_RED);
                    printf("%c%c ", participante[i1].carta[i].numero, participante[i1].carta[i].palo);
                    printf(ANSI_COLOR_RESET);
                }
                else
                {
                    printf("%c%c ", participante[i1].carta[i].numero, participante[i1].carta[i].palo);
                    printf(ANSI_COLOR_RESET);
                }
            }

        }
        printf("\n");
    }

    fclose(F_prueba);
    return 0;
}

void Borrar()
{
    system("pause");
    system("cls");
}
