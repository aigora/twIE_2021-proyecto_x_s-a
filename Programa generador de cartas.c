/// Librerías
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// Definimos variables
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
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

/// Programa
int main()
{
    system("cls");

    char carta[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', '\0'};                 /** Números Posibles **/
    char palo[] = { 3, 4, 5, 6, '\0' };                                                                     /** Palos Posibles **/
    int n_c, i;
    char nc, pc;
    int num_jug, i1;
    int x, y;
    srand(time(NULL));

    printf("Bienvenido a Blackjack.\n");

    do
    {
        Borrar();
        printf("Elija un numero de jugadores de 1 a 7.\n");
        scanf("%i",&num_jug);
    }while ((num_jug<1)||(num_jug>7));

    jugador participante[num_jug];

    for (i1=0; i1 < num_jug;i1++)
    {
        printf("Escriba el nombre del participante %i.\n",i1+1);
        scanf("%s", &participante[i1].nombre);
        do
        {
            printf("Elija la cantidad inicial con la que %s quiere empezar a jugar.\n",participante[i].nombre);
            scanf("%i", &participante[i1].monedero);
        }while((participante[i1].monedero <=0));

        for(i = 0; i < 2; i++)
        {
            nc = rand()%12;
            pc = rand()%4;
            if(carta[nc] == carta[9])
            {
                if ((palo[pc] == 3)||(palo[pc] == 4))
                {
                    n_c = 10;
                    printf(ANSI_COLOR_RED);
                    printf("%d%c", n_c, palo[pc]);
                    printf(ANSI_COLOR_RESET);
                    participante[i1].carta[i].numero = n_c;
                    participante[i1].carta[i].palo = palo[pc];
                }
                if ((palo[pc] == 5)||(palo[pc] == 6))
                {
                    n_c = 10;
                    printf("%d%c", n_c, palo[pc]);
                    printf(ANSI_COLOR_RESET);
                    participante[i1].carta[i].numero = n_c;
                    participante[i1].carta[i].palo = palo[pc];
                }

            }
            else
            {
                if ((palo[pc] == 3)||(palo[pc] == 4))
                {
                    printf(ANSI_COLOR_RED);
                    printf("%c%c ", carta[nc], palo[pc]);
                    printf(ANSI_COLOR_RESET);
                    participante[i1].carta[i].numero = carta[nc];
                    participante[i1].carta[i].palo = palo[pc];
                }
                if ((palo[pc] == 5)||(palo[pc] == 6))
                {
                    printf("%c%c ", carta[nc], palo[pc]);
                    printf(ANSI_COLOR_RESET);
                    participante[i1].carta[i].numero = carta[nc];
                    participante[i1].carta[i].palo = palo[pc];
                }
            }
        }
        printf("\n");
    }
    for(x = 0; x < num_jug; x++)
    {
        printf("Las cartas de %s son:", participante[x].nombre);
        for(y = 0; y < 2; y++)
        {
            if(participante[x].carta[y].numero == 10)
            {
                if((participante[x].carta[y].palo == 3)||(participante[x].carta[y].palo == 4))
                {
                    printf(ANSI_COLOR_RED);
                    printf("%i%c ", participante[x].carta[y].numero, participante[x].carta[y].palo);
                    printf(ANSI_COLOR_RESET);
                }
                if((participante[x].carta[y].palo == 5)||(participante[x].carta[y].palo == 6))
                {
                    printf("%i%c ", participante[x].carta[y].numero, participante[x].carta[y].palo);
                    printf(ANSI_COLOR_RESET);
                }
            }
            else
            {
                if((participante[x].carta[y].palo == 3)||(participante[x].carta[y].palo == 4))
                {
                    printf(ANSI_COLOR_RED);
                    printf("%c%c ", participante[x].carta[y].numero, participante[x].carta[y].palo);
                    printf(ANSI_COLOR_RESET);
                }
                if((participante[x].carta[y].palo == 5)||(participante[x].carta[y].palo == 6))
                {
                    printf("%c%c ", participante[x].carta[y].numero, participante[x].carta[y].palo);
                    printf(ANSI_COLOR_RESET);
                }
            }

        }
        printf("\n");
    }
    return 0;
}

void Borrar()
{
    system("pause");
    system("cls");
}
