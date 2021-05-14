/// Librerías
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// Definimos variables
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/// Funciones
void Continuar();
void imp_color_rojo_10(int num, char palo);
void imp_color_rojo_n(char num, char palo);

int suma_2cartas(int cart_1, int cart_2);

/// Estructuras
typedef struct                  /** Componentes de una carta **/
{
    char num_i;
    int num_j;
    char palo;
}e_carta;

typedef struct                  /** Cosas del jugador **/
{
    e_carta carta[20];         /* Estructura anidada en otra */
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
    int carta_jug[]  = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
    char carta_imp[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', '\0'};                 /** Números Posibles **/
    char palo[]      = { 3, 4, 5, 6, '\0' };                                                                    /** Palos Posibles **/
    char nc, pc;
    srand(time(NULL));
    int n_c, i;
    int num_jug, i1;
    int suma, eleccion;

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
        scanf("%i", &num_jug);
    }while ((num_jug<1)||(num_jug>7));

    datos_jugador participante[num_jug];

    for(i1 = 0; i1 < num_jug; i1++)
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
        }while((participante[i1].monedero <= 0));
        printf("\n");
    }

    ///Implementar para que cada jugador elija su apuesta.

    for(i1 = 0; i1 < num_jug; i1++)
    {
        for(i = 0; i < 20; i++)
            {
                nc = rand()%13;
                pc = rand()%4;
                if(carta_imp[nc] == carta_imp[9])
                {
                    n_c = 10;
                    participante[i1].carta[i].num_i = n_c;
                    participante[i1].carta[i].num_j = carta_jug[nc];
                    participante[i1].carta[i].palo  = palo[pc];
                }
                else
                {
                    participante[i1].carta[i].num_i = carta_imp[nc];
                    participante[i1].carta[i].num_j = carta_jug[nc];
                    participante[i1].carta[i].palo  = palo[pc];
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
            crupier.carta[i].num_i = n_c;
            crupier.carta[i].num_j = carta_jug[nc];
            crupier.carta[i].palo  = palo[pc];
        }
        else
        {
            crupier.carta[i].num_i = carta_imp[nc];
            crupier.carta[i].num_j = carta_jug[nc];
            crupier.carta[i].palo  = palo[pc];
        }
    }
    system("cls");

    printf("Las cartas del crupier son:");
    for(i = 0; i < 1; i++);
    {
        if(crupier.carta[i].num_i == 10)
        {
            imp_color_rojo_10(crupier.carta[i].num_i, crupier.carta[i].palo);
        }
        else
        {
            imp_color_rojo_n(crupier.carta[i].num_i, crupier.carta[i].palo);
        }
        printf("%c%c", 63, 63);
        printf("\n\n");
    }


    for(i1 = 0; i1 < num_jug; i1++)
    {
        printf("Las cartas de %s son:\t", participante[i1].nombre);
        for(i = 0; i < 2; i++)
        {
            if(participante[i1].carta[i].num_i == 10)
            {
                imp_color_rojo_10(participante[i1].carta[i].num_i, participante[i1].carta[i].palo);
            }
            else
            {
                imp_color_rojo_n(participante[i1].carta[i].num_i, participante[i1].carta[i].palo);
            }

        }
        printf("\n");
    }

    for(i1=0, suma=0; i1 < num_jug; i1++)
    {
        if((participante[i1].carta[0].num_j == 11) && (participante[i1].carta[1].num_j == 11))
            participante[i1].carta[1].num_j = 1;
        participante[i1].suma_t = participante[i1].carta[0].num_j + participante[i1].carta[1].num_j;
        printf("%i\n", participante[i1].suma_t);
    }
    Continuar();
    for (i1 = 0; i1 < num_jug; i1++)
    {
        printf("Las cartas del crupier son:");
        i=0;
        if(crupier.carta[i].num_i == 10)
        {
            imp_color_rojo_10(crupier.carta[i].num_i, crupier.carta[i].palo);
        }
        else
        {
            imp_color_rojo_n(crupier.carta[i].num_i, crupier.carta[i].palo);
        }
        printf("%c%c", 63, 63);
        printf("\n\n");

        printf("Es el turno de %s\n", participante[i1].nombre);
        printf("Tus cartas son: ", participante[i1].nombre);
        for(i = 0; i < 2; i++)
        {
            if(participante[i1].carta[i].num_i == 10)
            {
                imp_color_rojo_10(participante[i1].carta[i].num_i, participante[i1].carta[i].palo);
            }
            else
            {
                imp_color_rojo_n(participante[i1].carta[i].num_i, participante[i1].carta[i].palo);
            }
        }
        printf("\nLa suma es %i", participante[i1].suma_t);

        if (participante[i1].suma_t == 21)
        {
            printf("%cBlackjack!\n",173);
        }
        else
        {
            do
            {
                do
                {
                    printf("\n%cQu%c quieres hacer?\n", 168, 130);
                    printf("Pedir:1\tPlantarse:2\n");
                    scanf("%i", &eleccion);
                    i=0;
                    switch (eleccion)
                    {
                    case 1:
                        {
                            participante[i1].suma_t += participante[i1].carta[i+2].num_j;
                            printf("%c%c\t", participante[i1].carta[i+2].num_i, participante[i1].carta[i+2].palo);
                            printf("La suma es %i\n", participante[i1].suma_t);
                            i++;
                            break;
                        }
                    case 2:
                        break;
                    default:
                        printf("Por favor, introduzca una opción válida");
                        Continuar();
                        break;
                    }

                }while ((participante[i1].suma_t < 21) && (eleccion != 2));
            }while((eleccion < 1)||(eleccion > 3));

        }

    Continuar();
    }


    fclose(F_prueba);
    return 0;

}

void Continuar()
{
    system("pause");
    system("cls");
}

int suma_2cartas(int cart_1, int cart_2)
{
    int suma;
    suma = cart_1 + cart_2;
    if(suma <= 21)
    {
        return suma;
    }
    else if( suma > 21 )
    {
        cart_1 = 1;
        suma = 12;
        return suma;
    }
}

void imp_color_rojo_10(int num, char palo)
{
    if((palo == 3)||(palo == 4))
    {
        printf(ANSI_COLOR_RED);
        printf("%i%c ", num, palo);
        printf(ANSI_COLOR_RESET);
    }
    else
    {
        printf("%i%c ", num, palo);
        printf(ANSI_COLOR_RESET);
    }
}


void imp_color_rojo_n(char num, char palo)
{
    if((palo == 3)||(palo == 4))
    {
        printf(ANSI_COLOR_RED);
        printf("%c%c ", num, palo);
        printf(ANSI_COLOR_RESET);
    }
    else
    {
        printf("%c%c ", num, palo);
        printf(ANSI_COLOR_RESET);
    }
}

