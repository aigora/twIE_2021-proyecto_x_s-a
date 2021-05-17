/// Librer�as
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
int suma_3cartas(int cart_1, int cart_2, int cart_3);
int suma_4cartas(int cart_1, int cart_2, int cart_3, int cart_4);
int suma_5cartas(int cart_1, int cart_2, int cart_3, int cart_4, int cart_5);
int suma_6cartas(int cart_1, int cart_2, int cart_3, int cart_4, int cart_5, int cart_6);
int suma_7cartas(int cart_1, int cart_2, int cart_3, int cart_4, int cart_5, int cart_6, int cart_7);
int suma_8cartas(int cart_1, int cart_2, int cart_3, int cart_4, int cart_5, int cart_6, int cart_7, int cart_8);
int suma_9cartas(int cart_1, int cart_2, int cart_3, int cart_4, int cart_5, int cart_6, int cart_7, int cart_8, int cart_9);
int suma_10cartas(int cart_1, int cart_2, int cart_3, int cart_4, int cart_5, int cart_6, int cart_7, int cart_8, int cart_9, int cart_10);
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
    char carta_imp[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', '\0'};                 /** N�meros Posibles **/
    char palo[]      = { 3, 4, 5, 6, '\0' };                                                                    /** Palos Posibles **/
    char nc, pc;
    srand(time(NULL));
    int n_c, i, c;
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
            fprintf(F_prueba, "El tiene %i �.\n", participante[i1].monedero);
        }while((participante[i1].monedero <= 0));
        printf("\n");
    }

    for(i1 = 0; i1 < num_jug; i1++)
    {
        for(i = 0; i < 10; i++)
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
    for(c = 0; c < 10; c++)
    {
        nc = rand()%13;
        pc = rand()%4;
        if(carta_imp[nc] == carta_imp[9])
        {
            n_c = 10;
            crupier.carta[c].num_i = n_c;
            crupier.carta[c].num_j = carta_jug[nc];
            crupier.carta[c].palo  = palo[pc];
        }
        else
        {
            crupier.carta[c].num_i = carta_imp[nc];
            crupier.carta[c].num_j = carta_jug[nc];
            crupier.carta[c].palo  = palo[pc];
        }
    }
    system("cls");



            for(i1 = 0; i1 < num_jug; i1++)
    {
        do
        {
            system ("cls");
            printf("Tu monedero actual es %i.\n", participante[i1].monedero);
            printf("%s, %ccu%cnto quieres apostar de tu monedero?\n",
                    participante[i1].nombre, 168, 160);
            scanf("%i", &participante[i1].apuesta);
        }while (participante[i1].apuesta < 0 || participante[i1].apuesta > participante[i1].monedero);
    }

    Continuar();


    printf("Las cartas del crupier son:");
    for(c = 0; i < 1; c++);
    {
        if(crupier.carta[c].num_i == 10)
        {
            imp_color_rojo_10(crupier.carta[c].num_i, crupier.carta[c].palo);
        }
        else
        {
            imp_color_rojo_n(crupier.carta[c].num_i, crupier.carta[c].palo);
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

    for(i1=0; i1 < num_jug; i1++)
    {
        participante[i1].suma_t = suma_2cartas(participante[i1].carta[0].num_j, participante[i1].carta[1].num_j);
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
        printf("--> %i", participante[i1].suma_t);

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
                    participante[i1].suma_t = participante[i1].suma_t;
                    if(participante[i1].suma_t < 21)
                    {
                        printf("\n%cQu%c quieres hacer?\n", 168, 130);
                        printf("Pedir:1\tPlantarse:2\n");
                        scanf("%i", &eleccion);
                        switch (eleccion)
                        {
                        case 1:
                            if(participante[i1].carta[i].num_i == 10)
                            {
                                imp_color_rojo_10(participante[i1].carta[i].num_i, participante[i1].carta[i].palo);
                            }
                            else
                            {
                                imp_color_rojo_n(participante[i1].carta[i].num_i, participante[i1].carta[i].palo);
                            }
                            i++;
                            switch(i-2)
                            {
                                case 1:
                                    participante[i1].suma_t = suma_3cartas(participante[i1].carta[0].num_j, participante[i1].carta[1].num_j, participante[i1].carta[2].num_j);
                                   break;
                                case 2:
                                    participante[i1].suma_t = suma_4cartas(participante[i1].carta[0].num_j, participante[i1].carta[1].num_j, participante[i1].carta[2].num_j, participante[i1].carta[3].num_j);
                                    break;
                                case 3:
                                    participante[i1].suma_t = suma_5cartas(participante[i1].carta[0].num_j, participante[i1].carta[1].num_j, participante[i1].carta[2].num_j, participante[i1].carta[3].num_j, participante[i1].carta[4].num_j);
                                    break;
                                case 4:
                                    participante[i1].suma_t = suma_6cartas(participante[i1].carta[0].num_j, participante[i1].carta[1].num_j, participante[i1].carta[2].num_j, participante[i1].carta[3].num_j, participante[i1].carta[4].num_j, participante[i1].carta[5].num_j);
                                    break;
                                case 5:
                                    participante[i1].suma_t = suma_7cartas(participante[i1].carta[0].num_j, participante[i1].carta[1].num_j, participante[i1].carta[2].num_j, participante[i1].carta[3].num_j, participante[i1].carta[4].num_j, participante[i1].carta[5].num_j, participante[i1].carta[6].num_j);
                                    break;
                                case 6:
                                    participante[i1].suma_t = suma_8cartas(participante[i1].carta[0].num_j, participante[i1].carta[1].num_j, participante[i1].carta[2].num_j, participante[i1].carta[3].num_j, participante[i1].carta[4].num_j, participante[i1].carta[5].num_j, participante[i1].carta[6].num_j, participante[i1].carta[7].num_j);
                                    break;
                                case 7:
                                    participante[i1].suma_t = suma_9cartas(participante[i1].carta[0].num_j, participante[i1].carta[1].num_j, participante[i1].carta[2].num_j, participante[i1].carta[3].num_j, participante[i1].carta[4].num_j, participante[i1].carta[5].num_j, participante[i1].carta[6].num_j, participante[i1].carta[7].num_j, participante[i1].carta[8].num_j);
                                    break;
                                case 8:
                                    participante[i1].suma_t = suma_10cartas(participante[i1].carta[0].num_j, participante[i1].carta[1].num_j, participante[i1].carta[2].num_j, participante[i1].carta[3].num_j, participante[i1].carta[4].num_j, participante[i1].carta[5].num_j, participante[i1].carta[6].num_j, participante[i1].carta[7].num_j, participante[i1].carta[8].num_j, participante[i1].carta[9].num_j);
                                    break;
                            }
                            printf("  -->   %i\n", participante[i1].suma_t);
                            break;
                        case 2:
                            printf("Te has plantado con %i, se acab%c tu turno.\n", participante[i1].suma_t, 162);
                            break;
                        default:
                            printf("Por favor, introduzca una opci�n v�lida...");
                            Continuar();
                            break;
                        }
                    }
                }while((eleccion < 1)||(eleccion > 3));
            }while((participante[i1].suma_t < 21)&&(eleccion != 2));

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
int suma_3cartas(int cart_1, int cart_2, int cart_3)
{
    int suma;
    suma = cart_1 + cart_2 + cart_3;
    if(suma <= 21)
    {
        return suma;
    }
    else if( suma > 21 )
    {
        if(cart_1 == 11)
            cart_1 = 1;
        if(cart_2 == 11)
            cart_2 = 1;
        if(cart_3 == 11)
            cart_3 = 1;
        suma = cart_1 + cart_2 + cart_3;
        return suma;
    }
}
int suma_4cartas(int cart_1, int cart_2, int cart_3, int cart_4)
{
    int suma;
    suma = cart_1 + cart_2 + cart_3 + cart_4;
    if(suma <= 21)
    {
        return suma;
    }
    else if( suma > 21 )
    {
        if(cart_1 == 11)
            cart_1 = 1;
        if(cart_2 == 11)
            cart_2 = 1;
        if(cart_3 == 11)
            cart_3 = 1;
        if(cart_4 == 11)
            cart_4 = 1;
        suma = cart_1 + cart_2 + cart_3 + cart_4;
        return suma;
    }
}
int suma_5cartas(int cart_1, int cart_2, int cart_3, int cart_4, int cart_5)
{
    int suma;
    suma = cart_1 + cart_2 + cart_3 + cart_4 + cart_5;
    if(suma <= 21)
    {
        return suma;
    }
    else if( suma > 21 )
    {
        if(cart_1 == 11)
            cart_1 = 1;
        if(cart_2 == 11)
            cart_2 = 1;
        if(cart_3 == 11)
            cart_3 = 1;
        if(cart_4 == 11)
            cart_4 = 1;
        if(cart_5 == 11)
            cart_5 = 1;
        suma = cart_1 + cart_2 + cart_3 + cart_4 + cart_5;
        return suma;
    }
}
int suma_6cartas(int cart_1, int cart_2, int cart_3, int cart_4, int cart_5, int cart_6)
{
    int suma;
    suma = cart_1 + cart_2 + cart_3 + cart_4 + cart_5 + cart_6;
    if(suma <= 21)
    {
        return suma;
    }
    else if( suma > 21 )
    {
        if(cart_1 == 11)
            cart_1 = 1;
        if(cart_2 == 11)
            cart_2 = 1;
        if(cart_3 == 11)
            cart_3 = 1;
        if(cart_4 == 11)
            cart_4 = 1;
        if(cart_5 == 11)
            cart_5 = 1;
        if(cart_6 == 11)
            cart_6 = 1;
        suma = cart_1 + cart_2 + cart_3 + cart_4 + cart_5 + cart_6;
        return suma;
    }
}
int suma_7cartas(int cart_1, int cart_2, int cart_3, int cart_4, int cart_5, int cart_6, int cart_7)
{
    int suma;
    suma = cart_1 + cart_2 + cart_3 + cart_4 + cart_5 + cart_6 + cart_7;
    if(suma <= 21)
    {
        return suma;
    }
    else if( suma > 21 )
    {
        if(cart_1 == 11)
            cart_1 = 1;
        if(cart_2 == 11)
            cart_2 = 1;
        if(cart_3 == 11)
            cart_3 = 1;
        if(cart_4 == 11)
            cart_4 = 1;
        if(cart_5 == 11)
            cart_5 = 1;
        if(cart_6 == 11)
            cart_6 = 1;
        if(cart_7 == 11)
            cart_7 = 1;
        suma = cart_1 + cart_2 + cart_3 + cart_4 + cart_5 + cart_6 + cart_7;
        return suma;
    }
}
int suma_8cartas(int cart_1, int cart_2, int cart_3, int cart_4, int cart_5, int cart_6, int cart_7, int cart_8)
{
    int suma;
    suma = cart_1 + cart_2 + cart_3 + cart_4 + cart_5 + cart_6 + cart_7 + cart_8;
    if(suma <= 21)
    {
        return suma;
    }
        if(cart_1 == 11)
            cart_1 = 1;
        if(cart_2 == 11)
            cart_2 = 1;
        if(cart_3 == 11)
            cart_3 = 1;
        if(cart_4 == 11)
            cart_4 = 1;
        if(cart_5 == 11)
            cart_5 = 1;
        if(cart_6 == 11)
            cart_6 = 1;
        if(cart_7 == 11)
            cart_7 = 1;
        if(cart_8 == 11)
            cart_8 = 1;
        suma = cart_1 + cart_2 + cart_3 + cart_4 + cart_5 + cart_6 + cart_7 + cart_8;
        return suma;
}
int suma_9cartas(int cart_1, int cart_2, int cart_3, int cart_4, int cart_5, int cart_6, int cart_7, int cart_8, int cart_9)
{
    int suma;
    suma = cart_1 + cart_2 + cart_3 + cart_4 + cart_5 + cart_6 + cart_7 + cart_8 + cart_9;
    if(suma <= 21)
    {
        return suma;
    }
        if(cart_1 == 11)
            cart_1 = 1;
        if(cart_2 == 11)
            cart_2 = 1;
        if(cart_3 == 11)
            cart_3 = 1;
        if(cart_4 == 11)
            cart_4 = 1;
        if(cart_5 == 11)
            cart_5 = 1;
        if(cart_6 == 11)
            cart_6 = 1;
        if(cart_7 == 11)
            cart_7 = 1;
        if(cart_8 == 11)
            cart_8 = 1;
        if(cart_9 == 11)
            cart_9 = 1;
        suma = cart_1 + cart_2 + cart_3 + cart_4 + cart_5 + cart_6 + cart_7 + cart_8+ cart_9;
        return suma;
}
int suma_10cartas(int cart_1, int cart_2, int cart_3, int cart_4, int cart_5, int cart_6, int cart_7, int cart_8, int cart_9, int cart_10)
{
    int suma;
    suma = cart_1 + cart_2 + cart_3 + cart_4 + cart_5 + cart_6 + cart_7 + cart_8 + cart_9 + cart_10;
    if(suma <= 21)
    {
        return suma;
    }
        if(cart_1 == 11)
            cart_1 = 1;
        if(cart_2 == 11)
            cart_2 = 1;
        if(cart_3 == 11)
            cart_3 = 1;
        if(cart_4 == 11)
            cart_4 = 1;
        if(cart_5 == 11)
            cart_5 = 1;
        if(cart_6 == 11)
            cart_6 = 1;
        if(cart_7 == 11)
            cart_7 = 1;
        if(cart_8 == 11)
            cart_8 = 1;
        if(cart_9 == 11)
            cart_9 = 1;
        if(cart_10 == 11)
            cart_10 = 1;
        suma = cart_1 + cart_2 + cart_3 + cart_4 + cart_5 + cart_6 + cart_7 + cart_8 + cart_9 + cart_10;
        return suma;
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
