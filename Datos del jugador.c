#include <stdio.h>
#include <stdlib.h>


void borrar();

typedef struct
{
    char nombre[50];
    float monedero;
}datos_ini;


int main ()
{
    int num_jug, i;

    printf("Bienvenido a Blackjack.\n");
    system ("pause");

    do
    {
        borrar();
        printf("Elija un numero de jugadores de 1 a 7.\n");
        scanf("%i",&num_jug);
    }while ((num_jug<1)||(num_jug>7));

    datos_ini participante[num_jug];

    for (i=0; i < num_jug;i++)
    {
        printf("Escriba el nombre del participante %i.\n",i+1);
        scanf("%s", &participante[i].nombre);
        do
        {
            printf("Elija la cantidad inicial con la que %s quiere empezar a jugar.\n",participante[i].nombre);
            scanf("%f", &participante[i].monedero);
        }while((participante[i].monedero <= 0));
    }
    return 0;
}

void borrar()
{
    system("cls");
}




