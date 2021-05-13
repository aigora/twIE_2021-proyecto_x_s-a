/// Librer�as
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
    e_carta carta_i[20];         /* Estructura anidada en otra */
    e_carta carta_j[20];
    char nombre[100];
    int monedero;
    int suma_t;
    int apuesta;
}datos_jugador;



/// Programa
int main()
{
    system("cls");
    FILE *F_prueba;
    datos_jugador crupier = {.nombre = "Susana Picado"};
    int carta_jug[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
    char carta_imp[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', '\0'};                 /** N�meros Posibles **/
    char palo[] = { 3, 4, 5, 6, '\0' };                                                                     /** Palos Posibles **/
    int n_c, i;
    char nc, pc;
    int num_jug, i1;
    int suma;
    char eleccion;
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

    datos_jugador participante[num_jug];

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
            fprintf(F_prueba, "El tiene %i �.\n", participante[i1].monedero);
        }while((participante[i1].monedero <=0));
        printf("\n");
    }

    ///Implementar para que cada jugador elija su apuesta.

    for(i1=0; i1 < num_jug;i1++)
    {
        for(i = 0; i < 20; i++)
            {
                nc = rand()%13;
                pc = rand()%4;
                if(carta_imp[nc] == carta_imp[9])
                {
                    n_c = 10;
                    participante[i1].carta_i[i].numero = n_c;
                    participante[i1].carta_i[i].palo = palo[pc];
                    participante[i1].carta_j[i].numero=n_c;
                }
                else
                {
                    participante[i1].carta_i[i].numero = carta_imp[nc];
                    participante[i1].carta_i[i].palo = palo[pc];
                    participante[i1].carta_j[i].numero=carta_jug[nc];
                }
            }
    }
    for(i = 0; i < 20; i++)
    {
        nc = rand()%13;
        pc = rand()%4;
        if(carta_imp[nc] == carta_imp[9])
        {
            n_c = 10;
            crupier.carta_i[i].numero = n_c;
            crupier.carta_i[i].palo = palo[pc];
            crupier.carta_j[i].numero = 10;
        }
        else
        {
            crupier.carta_i[i].numero = carta_imp[nc];
            crupier.carta_i[i].palo = palo[pc];
            crupier.carta_j[i].numero = carta_jug[nc];
        }
    }
    system("cls");

    printf("Las cartas del crupier son:");

 i=0;
        if(crupier.carta_i[i].numero == 10)
        {
            if((crupier.carta_i[i].palo == 3)||(crupier.carta_i[i].palo == 4))
            {
                printf(ANSI_COLOR_RED);
                printf("%i%c ", crupier.carta_i[i].numero, crupier.carta_i[i].palo);    //Imprimir primera carta del crupier.
                printf(ANSI_COLOR_RESET);
            }
            else
            {
                printf("%i%c ", crupier.carta_i[i].numero, crupier.carta_i[i].palo);
                printf(ANSI_COLOR_RESET);
            }
        }
        else
        {
            if((crupier.carta_i[i].palo == 3)||(crupier.carta_i[i].palo == 4))
            {
                printf(ANSI_COLOR_RED);
                printf("%c%c ", crupier.carta_i[i].numero, crupier.carta_i[i].palo);
                printf(ANSI_COLOR_RESET);
            }
            else
            {
                printf("%c%c ", crupier.carta_i[i].numero, crupier.carta_i[i].palo);
                printf(ANSI_COLOR_RESET);
            }
        }
        printf("%c%c", 63, 63);
        printf("\n\n");


    for(i1 = 0; i1 < num_jug; i1++)
    {
        printf("Las cartas de %s son:\t", participante[i1].nombre);
        for(i = 0; i < 2; i++)
        {
            if(participante[i1].carta_i[i].numero == 10)
            {
                if((participante[i1].carta_i[i].palo == 3)||(participante[i1].carta_i[i].palo == 4))
                {
                    printf(ANSI_COLOR_RED);
                    printf("%i%c ", participante[i1].carta_i[i].numero, participante[i1].carta_i[i].palo);
                    printf(ANSI_COLOR_RESET);
                }
                else
                {
                    printf("%i%c ", participante[i1].carta_i[i].numero, participante[i1].carta_i[i].palo);
                    printf(ANSI_COLOR_RESET);
                }
            }
            else
            {
                if((participante[i1].carta_i[i].palo == 3)||(participante[i1].carta_i[i].palo == 4))
                {
                    printf(ANSI_COLOR_RED);
                    printf("%c%c ", participante[i1].carta_i[i].numero, participante[i1].carta_i[i].palo);
                    printf(ANSI_COLOR_RESET);
                }
                else
                {
                    printf("%c%c ", participante[i1].carta_i[i].numero, participante[i1].carta_i[i].palo);
                    printf(ANSI_COLOR_RESET);
                }
            }

        }
        printf("\n");
    }

    for(i1=0, suma=0; i1 < num_jug; i1++)
    {


        if (participante[i1].carta_j[0].numero == 1)
           participante[i1].carta_j[0].numero = 11;
        if (participante[i1].carta_j[1].numero == 1)                                                                 ///Arreglo para el as al principio
           participante[i1].carta_j[1].numero = 11;
        if((participante[i1].carta_j[0].numero == 11) && (participante[i1].carta_j[1].numero == 11))
            participante[i1].carta_j[1].numero = 1;



        participante[i1].suma_t = participante[i1].carta_j[0].numero + participante[i1].carta_j[1].numero;

        printf("%i\n", participante[i1].suma_t);

    }

    Borrar();




    for (i1 = 0; i1 < num_jug; i1++)
    {

            printf("Las cartas del crupier son:");

 i=0;
        if(crupier.carta_i[i].numero == 10)
        {
            if((crupier.carta_i[i].palo == 3)||(crupier.carta_i[i].palo == 4))
            {
                printf(ANSI_COLOR_RED);
                printf("%i%c ", crupier.carta_i[i].numero, crupier.carta_i[i].palo);    //Imprimir primera carta del crupier.
                printf(ANSI_COLOR_RESET);
            }
            else
            {
                printf("%i%c ", crupier.carta_i[i].numero, crupier.carta_i[i].palo);
                printf(ANSI_COLOR_RESET);
            }
        }
        else
        {
            if((crupier.carta_i[i].palo == 3)||(crupier.carta_i[i].palo == 4))
            {
                printf(ANSI_COLOR_RED);
                printf("%c%c ", crupier.carta_i[i].numero, crupier.carta_i[i].palo);
                printf(ANSI_COLOR_RESET);
            }
            else
            {
                printf("%c%c ", crupier.carta_i[i].numero, crupier.carta_i[i].palo);
                printf(ANSI_COLOR_RESET);
            }
        }
        printf("%c%c", 63, 63);
        printf("\n\n");



        printf("Turno de %s\n", participante[i1].nombre);

        printf("Tus cartas son: %c%c %c%c --> %i\n",
               participante[i1].carta_i[0].numero, participante[i1].carta_i[0].palo, participante[i1].carta_i[1].numero, participante[i1].carta_i[1].palo,
                participante[i1].suma_t);

        if (participante[i1].suma_t == 21)
            printf("%cBlackjack!\n",173);
        else
        {
            while ((participante[i1].suma_t < 21) && (eleccion != 2))
            {
                printf("%cQu%c quieres hacer?\n",
                        168, 130);
                printf("Pedir:1\tPlantarse:2\n");                                           ///Se imprime 2 veces
                scanf("%c", &eleccion);
                i=0;
                switch (eleccion)
                {
                case '1':
                    {
                        participante[i1].suma_t += participante[i1].carta_j[i+2].numero;
                        printf("%c%c\t", participante[i1].carta_i[i+2].numero, participante[i1].carta_i[i+2].palo);
                        printf("La suma es %i\n", participante[i1].suma_t);
                        i++;
                        break;
                    }
                    case '2':
                        break;
                }                                                                           ///No funciona el 2
            }


        Borrar();
    }

}


    fclose(F_prueba);
    return 0;

}

void Borrar()
{
    system("pause");
    system("cls");
}
