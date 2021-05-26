/// Librerías
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// Definimos variables
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/// Funciones
void Continuar();
void Menu_Final();
int Premio( _Bool BJ_p, _Bool BJ_c, int apuesta, int suma_p, int suma_c);
void imp_color_rojo_10(int num, char palo);
void imp_color_rojo_n(char num, char palo);

int suma_cartas(int i, int cartas[]);

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
    int cartas[21];
    char nc, pc;
    srand(time(NULL));
    int n_c, i, c, aux, Dec_BJ;
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
            fprintf(F_prueba, "El tiene %i euros.\n", participante[i1].monedero);
        }while((participante[i1].monedero <= 0));
        printf("\n");
    }
    do
    {
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
            if(participante[i1].apuesta == 0)
            {
                printf("%s, no participa en esta ronda.\n", participante[i1].nombre);
            }
            else
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
                    cartas[i] = participante[i1].carta[i].num_j;
                }
                participante[i1].suma_t = suma_cartas(2, cartas);
                printf("   -->   %i\n", participante[i1].suma_t);
            }
            printf("\n");

        }
        Continuar();

        //Se muestra en pantalla la carta del crupier, y las cartas del jugador, con su respectiva suma. También, se imprimen las cartas que pida el jugador, incluyendo la nueva suma de valores.
        for (i1 = 0; i1 < num_jug; i1++)
        {
            if(participante[i1].apuesta == 0)
            {
                printf("%s, no participa en esta ronda.\n", participante[i1].nombre);
                system("cls");
            }
            else
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
                    cartas[i] = participante[i1].carta[i].num_j;
                }
                participante[i1].suma_t = suma_cartas(2, cartas);
                printf("--> %i", participante[i1].suma_t);
                aux = 3;

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
                                printf("Pedir:1 \t Plantarse:2\n");
                                scanf("%i", &eleccion);
                                switch (eleccion)
                                {
                                case 1:
                                    for(i = 0; i < aux ; i++)
                                    {
                                        if(participante[i1].carta[i].num_i == 10)
                                        {
                                            imp_color_rojo_10(participante[i1].carta[i].num_i, participante[i1].carta[i].palo);
                                        }
                                        else
                                        {
                                            imp_color_rojo_n(participante[i1].carta[i].num_i, participante[i1].carta[i].palo);
                                        }
                                        cartas[i] = participante[i1].carta[i].num_j;
                                    }
                                    participante[i1].suma_t = suma_cartas(aux, cartas);
                                    aux++;
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
            if(participante[i1].suma_t <= 21)
            {
                participante[i1].Pasar_21 = 0;
            }
            Continuar();
            }

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
        crupier.suma_t = suma_cartas(2, cartas);
        printf("   -->   %i\n", crupier.suma_t);
        if( crupier.suma_t == 21)
        {
            printf("¡El crupier tiene Black Jack!");
            crupier.BJ = 1;/*Si obtiene 21 con las dos primeras cartas _Bool BJ (Black Jack), tendrá valor 1, que afirma ese hecho*/
        }
        else
            crupier.BJ = 0;/*Sino, recibirá el valor 0.*/

        if (crupier.suma_t < 17)
        {
            aux = 3;
            do
            {
                for(c = 0; c < aux; c++)
                {
                    if(crupier.carta[c].num_i == 10)
                    {
                    imp_color_rojo_10(crupier.carta[c].num_i, crupier.carta[c].palo);
                    }
                    else
                    {
                    imp_color_rojo_n(crupier.carta[c].num_i, crupier.carta[c].palo);
                    }
                    cartas[c] = crupier.carta[c].num_j;
                }
                crupier.suma_t = suma_cartas(aux, cartas);
                printf("  -->   %i\n", crupier.suma_t);
                aux++;
            }while(crupier.suma_t < 17);
        }
        /*Si se pasa de 21 el crupier, le daremos al _Bool Pasar_de_21, valor 1, que afirma ese hecho. Sino, recibirá el valor 0.*/
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
        printf("FASE DE RECOMPENSAS:\n");
        printf("La suma de la mano del crupier es %i\n\n", crupier.suma_t);
        for(i1 = 0, premio = 0; i1 < num_jug; i1++)
        {
            if(participante[i1].apuesta == 0)
            {
                printf("%s, no participa en esta ronda.\n\n", participante[i1].nombre);
            }
            else
            {
                printf("La suma de la mano de %s es %i\n", participante[i1].nombre, participante[i1].suma_t);
                printf("Apost%c: %i euros\n", 162, participante[i1].apuesta);
                if(participante[i1].Pasar_21 == 1)
                {
                    printf("En el monedero de %s hay %i euros\n", participante[i1].nombre, participante[i1].monedero);
                    printf("perdi%c lo apostado\n\n", 162);
                }
                else
                {
                    premio = Premio( participante[i1].BJ, crupier.BJ , participante[i1].apuesta, participante[i1].suma_t, crupier.suma_t);
                    if( premio == 0)
                    {
                        printf("En el monedero de %s hay %i euros\n", participante[i1].nombre, participante[i1].monedero);
                        printf("perdi%c lo apostado\n\n", 162);
                    }
                    else
                    {
                        printf("En el monedero de %s hay %i euros\n", participante[i1].nombre, participante[i1].monedero);
                        printf("gan%c %i euros\n", 162, premio);
                        participante[i1].monedero += premio;
                        printf("Su monedero asciende a %i euros\n\n", participante[i1].monedero);
                    }
                }
            }
        }
        do
        {
            Continuar();
            Menu_Final();
            scanf("%i", &Dec_BJ);
        }while((Dec_BJ != 1)&&(Dec_BJ != 2));

    }while(Dec_BJ != 2);
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

void Menu_Final()
{
    printf("\n\n%cQuier%cn volver a jugar?\n", 163, 130);
    printf("1. Si\n");
    printf("2. No\n");
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
int Premio( _Bool BJ_p, _Bool BJ_c, int apuesta, int suma_p, int suma_c)
{
    int premio;

    if(BJ_p == 1)
    {
        if(BJ_c == 1)
            return apuesta;
        else
        {
            premio = apuesta * 2.5;
            return premio;
        }
    }
    else
    {
        if(BJ_c == 1)
            return 0;
        else
        {
            if((suma_p > 21)&&(suma_c > 21))
                return 0;
            if((suma_p > 21)&&(suma_c < 22))
                return 0;
            if((suma_p < 22)&&(suma_c > 21))
            {
                premio = apuesta * 2;
                return premio;
            }
            if((suma_p < 22)&&(suma_c < 22))
            {
                if(suma_p < suma_c)
                    return 0;
                else if(suma_p > suma_c)
                {
                    premio = apuesta * 2;
                    return premio;
                }
                if(suma_p == suma_c)
                    return apuesta;
            }
        }
    }
}


//Función para comprobar siempre la suma
int suma_cartas(int n_cartas, int cartas[])
{
    int suma, i;
    for(i = 0, suma = 0; i < n_cartas; i++)
    {
        suma += cartas[i];
    }
    if(suma <= 21)
    {
        return suma;
    }
    else
    {
        for(i = 0, suma = 0; i < n_cartas; i++)
        {
            if (cartas[i] == 11)
                {
                    cartas[i] = 1;
                    suma += cartas[i];
                }
            else
                {
                    suma += cartas[i];
                }
        }
        return suma;
    }
}
