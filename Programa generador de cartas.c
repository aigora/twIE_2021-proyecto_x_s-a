/// Librerías
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

///Funciones
void Borrar();

/// Estructuras
typedef struct
{
    char numero;
    char palo;
}e_carta;

typedef struct
{
    e_carta carta;
    char nombre[100];
    int monedero;
}jugador;

/// Programa
int main()
{
    system("cls");

    char carta[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', '\0'};
    char palo[] = { 3, 4, 5, 6, '\0' };
    int n_c, i;
    char nc, pc;
    int num_jug, i1;
    srand(time(NULL));

    printf("Bienvenido a Blackjack.\n");

    do
    {
        Borrar();
        printf("Elija un numero de jugadores de 1 a 7.\n");
        scanf("%i",&num_jug);
    }while ((num_jug<1)||(num_jug>7));

    jugador participante[num_jug]
    ;

    for (i1=0; i1 < num_jug;i1++)
    {
        printf("Escriba el nombre del participante %i.\n",i1+1);
        scanf("%s", &participante[i1].nombre);
        do
        {
            printf("Elija la cantidad inicial con la que %s quiere empezar a jugar.\n",participante[i].nombre);
            scanf("%i", &participante[i1].monedero);
        }while((participante[i1].monedero <=0));        //NO funciona si se introduce un número decimal negativo y entre 0 y 1
                                                        //usar if para cambiar el valor negativo a positivo.
                                                        for(i = 0; i < 2; i++)
        {
            nc = rand()%12;
            pc = rand()%4;
            if(carta[nc] == carta[9])
            {
                if ((palo[pc] == 3)||(palo[pc] == 4))
                {
                    n_c = 10;
                    printf("\033[0;31m");
                    printf("%d %c \n", n_c, palo[pc]);
                    printf("\033[0;37m");
                }
                if ((palo[pc] == 5)||(palo[pc] == 6))
                {
                    n_c = 10;
                    printf("\033[0;34m");
                    printf("%d %c \n", n_c, palo[pc]);
                    printf("\033[0;37m");
                }

            }
            else
            {
                if ((palo[pc] == 3)||(palo[pc] == 4))
                {
                    printf("\033[0;31m");
                    printf("%c %c \n", carta[nc], palo[pc]);
                    printf("\033[0;37m");
                }
                if ((palo[pc] == 5)||(palo[pc] == 6))
                {
                    printf("\033[0;34m");
                    printf("%c %c \n", carta[nc], palo[pc]);
                    printf("\033[0;37m");
                }
            }
        }
    }
    return 0;
}

void Borrar()
{
    system("pause");
    system("cls");
}
