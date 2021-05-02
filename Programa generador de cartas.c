/// Librerías
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

/// Estructuras
typedef struct
{
    char numero;
    char palo;
}e_carta;

typedef struct
{
    e_carta carta;
}jugador;

/// Programa
int main()
{
    system("cls");
    char carta[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', '\0'};
    char palo[] = { 3, 4, 5, 6, '\0' };
    int n_c, i;
    char nc, pc;
    srand(time(NULL));
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
    return 0;
}
