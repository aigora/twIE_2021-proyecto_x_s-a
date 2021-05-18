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
int Premio( _Bool Mas_de_21, _Bool BJ, int apuesta, int suma_p, int suma_c);

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
    _Bool BJ;
    _Bool Pasar_21;
}datos_jugador;



/// Programa
int main()
{
    //Variables
    system("cls");
    FILE *F_prueba;
    datos_jugador crupier = {.nombre = "Susana Picado"};
    int carta_jug[]  = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
    char carta_imp[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', '\0'};                 /** Números Posibles **/
    char palo[]      = { 3, 4, 5, 6, '\0' };                                                                    /** Palos Posibles **/
    char nc, pc;
    srand(time(NULL));
    int n_c, i, c, aux;
    int num_jug, i1;
    int suma, eleccion, premio;

    //Apertura del fichero e ingreso del número de jugadores
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

    //generador de los jugadores
    datos_jugador participante[num_jug];

    //se guardan en la memoria los nombres y dinero de los jugadores
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

    //Se generan las 10 primeras cartas de todos los jugadores
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
    //se generan las 10 primeras cartas del crupier
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

    //Se introduce la cantidad a apostar por los jugadores
    for(i1 = 0; i1 < num_jug; i1++)
    {
        do
        {
            system ("cls");
            printf("Tu monedero actual es %i.\n", participante[i1].monedero);
            printf("%s, %ccu%cnto quieres apostar de tu monedero?\n", participante[i1].nombre, 168, 160);
            scanf("%i", &participante[i1].apuesta);
        }while (participante[i1].apuesta < 0 || participante[i1].apuesta > participante[i1].monedero);
        participante[i1].monedero -= participante[i1].apuesta;
    }

    Continuar();

    //Imprimimos solo una carta del crupier
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

    //Imprimimos las cartas de los jugadores
    for(i1 = 0; i1 < num_jug; i1++)
    {
        printf("Las cartas de %s son:", participante[i1].nombre);
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
        participante[i1].suma_t = suma_2cartas(participante[i1].carta[0].num_j, participante[i1].carta[1].num_j);
        printf("   -->   %i\n", participante[i1].suma_t);
    }
    Continuar();

    //Se muestra en pantalla la carta del crupier, y las cartas del jugador, con su respectiva suma. También, se imprimen las cartas que pida el jugador, incluyendo la nueva suma de valores.
    for (i1 = 0; i1 < num_jug; i1++)
    {
        /*Primero las cartas del crupier*/
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

        /*Primero imprimimos las primeras 2 cartas y su suma.*/
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

        /*Ahora comprobamos la suma de las dos primeras, y si son menores que 21, le damos la opción a que pida más o se plante*/
        if (participante[i1].suma_t == 21)
        {
            printf("%cBlackjack!\n",173);
            participante[i1].BJ = 1;/*Si obtiene 21 con las dos primeras cartas _Bool BJ (Black Jack), tendrá valor 1, que afirma ese hecho.*/
        }
        else
        {
            participante[i1].BJ = 0;/*Sino, recibirá el valor 0.*/
            do
            {
                do
                {
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
                            printf("Por favor, introduzca una opción válida...");
                            Continuar();
                            break;
                        }
                    }
                }while((eleccion < 1)||(eleccion > 3));
            }while((participante[i1].suma_t < 21)&&(eleccion != 2));
        }
    /*Si se pasa de 21 el jugador, le daremos al _Bool Pasar_de_21, valor 1, que afirma ese hecho. Sino, recibirá el valor 0.*/
    if(participante[i1].suma_t > 21)
    {
        participante[i1].Pasar_21 = 1;
    }
    else
    {
        participante[i1].Pasar_21 = 0;
    }
    Continuar();
    }

    //Ahora viene el turno del crupier, el cual si saca menos de un 16, pedirá carta; pero, si saca más, no pedira más.
    crupier.suma_t = crupier.carta[0].num_j + crupier.carta[1].num_j;
    printf("Ahora es el turno del crupier.\n");
    printf("Las cartas del crupier son: \n");
    for(c = 0; c < 2; c++)
    {
        if(crupier.carta[c].num_i == 10)
        {
            imp_color_rojo_10(crupier.carta[c].num_i, crupier.carta[c].palo);
        }
        else
        {
            imp_color_rojo_n(crupier.carta[c].num_i, crupier.carta[c].palo);
        }
    }
    printf("   -->   %i\n", crupier.suma_t);
    if( crupier.suma_t == 21)
    {
        printf("¡El crupier tiene Black Jack!");
        crupier.BJ = 1;/*Si obtiene 21 con las dos primeras cartas _Bool BJ (Black Jack), tendrá valor 1, que afirma ese hecho*/
    }
    else
    participante[i1].BJ = 0;/*Sino, recibirá el valor 0.*/

    if (crupier.suma_t < 17)
    {
        do
        {
            if(crupier.carta[c].num_i == 10)
            {
                imp_color_rojo_10(crupier.carta[c].num_i, crupier.carta[c].palo);
            }
            else
            {
                imp_color_rojo_n(crupier.carta[c].num_i, crupier.carta[c].palo);
            }
            c++;
            switch(c-2)
            {
                case 1:
                    crupier.suma_t = suma_3cartas(crupier.carta[0].num_j, crupier.carta[1].num_j, crupier.carta[2].num_j);
                    break;
                case 2:
                    crupier.suma_t = suma_4cartas(crupier.carta[0].num_j, crupier.carta[1].num_j, crupier.carta[2].num_j, crupier.carta[3].num_j);
                    break;
                case 3:
                    crupier.suma_t = suma_5cartas(crupier.carta[0].num_j, crupier.carta[1].num_j, crupier.carta[2].num_j, crupier.carta[3].num_j, crupier.carta[4].num_j);
                    break;
                case 4:
                    crupier.suma_t = suma_6cartas(crupier.carta[0].num_j, crupier.carta[1].num_j, crupier.carta[2].num_j, crupier.carta[3].num_j, crupier.carta[4].num_j, crupier.carta[5].num_j);
                    break;
                case 5:
                    crupier.suma_t = suma_7cartas(crupier.carta[0].num_j, crupier.carta[1].num_j, crupier.carta[2].num_j, crupier.carta[3].num_j, crupier.carta[4].num_j, crupier.carta[5].num_j, crupier.carta[6].num_j);
                    break;
                case 6:
                    crupier.suma_t = suma_8cartas(crupier.carta[0].num_j, crupier.carta[1].num_j, crupier.carta[2].num_j, crupier.carta[3].num_j, crupier.carta[4].num_j, crupier.carta[5].num_j, crupier.carta[6].num_j, crupier.carta[7].num_j);
                    break;
                case 7:
                    crupier.suma_t = suma_9cartas(crupier.carta[0].num_j, crupier.carta[1].num_j, crupier.carta[2].num_j, crupier.carta[3].num_j, crupier.carta[4].num_j, crupier.carta[5].num_j, crupier.carta[6].num_j, crupier.carta[7].num_j, crupier.carta[8].num_j);
                    break;
                case 8:
                    crupier.suma_t = suma_10cartas(crupier.carta[0].num_j, crupier.carta[1].num_j, crupier.carta[2].num_j, crupier.carta[3].num_j, crupier.carta[4].num_j, crupier.carta[5].num_j, crupier.carta[6].num_j, crupier.carta[7].num_j, crupier.carta[8].num_j, crupier.carta[9].num_j);
                    break;
            }
        }while(crupier.suma_t < 17);
            printf("   -->   %i\n", crupier.suma_t);
    }
    /*Si se pasa de 21 el jugador, le daremos al _Bool Pasar_de_21, valor 1, que afirma ese hecho. Sino, recibirá el valor 0.*/
    if(crupier.suma_t > 21)
    {
        crupier.Pasar_21 = 1;
    }
    else
    {
        crupier.Pasar_21 = 0;
    }
    Continuar();

    //Ahora viene la lista de ganadores, ESTO HAY QUE MEJORARLO LA VERDAD.
    printf("Lista de ganadores:\n");
    printf("La suma de la mano del crupier es %i\n", crupier.suma_t);
    for(i1 = 0, premio = 0; i1 < num_jug; i1++)
    {
        printf("La suma de la mano del %s es %i\n", participante[i1].nombre, participante[i1].suma_t);
        printf("Apost%c: %i\n", 162, participante[i1].apuesta);
        if(participante[i1].Pasar_21 == 1)
        {
            printf("En el monedero de %s hay %i\n", participante[i1].nombre, participante[i1].monedero);
            printf("perdi%c lo apostado\n\n", 162);
        }
        else
        {
            printf("En el monedero de %s hay %i\n", participante[i1].nombre, participante[i1].monedero);
            premio = Premio(participante[i1].Pasar_21, participante[i1].BJ, participante[i1].apuesta, participante[i1].suma_t, crupier.suma_t);
            printf("gan%c %i\n", 162, premio);
            participante[i1].monedero += premio;
            printf("Su monedero asciende a %i\n\n", participante[i1].monedero);
        }
    }
    //Cierre del fichero de prueba.
    fclose(F_prueba);
    return 0;
}

///Funciones

//Funciones Tool
void Continuar()
{
    system("pause");
    system("cls");
}

//Funciones para imprimir colores
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
//Funcion de premios
int Premio(_Bool Mas_de_21, _Bool BJ, int apuesta, int suma_p, int suma_c)
{
    int premio;

    if(BJ == 1)
    {
        if (suma_p > suma_c)
        {
            premio = apuesta * 2,5;
            return premio;
        }
        else if (suma_c == suma_p)
        {
            return apuesta;
        }

    }
    else
    {
        if(suma_p == suma_c)
        {
            return apuesta;
        }
        else if(suma_p < suma_c)
            {
                return 0;
            }
            else
            {
                premio = apuesta * 2;
                return premio;
            }
    }
}

//Funciones para comprobar siempre la suma
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

