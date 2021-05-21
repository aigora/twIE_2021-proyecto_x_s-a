///Presentación de las librerías
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// Definimos variables
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

///Presentación de las funciones
void Bienvenida();
void Continuar();
void Borrar();
void Menu_Opciones();
void Menu_BlackJack();
void Menu_EscapeRoom();
void Despedida();
void Game_Over();

//Funciones del Black Jack
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

///Programa
int main()
{
    FILE *reglas;
    int decision_1, decision_2, y, j, x;
    //Variables del Escape Room
    int dec_0,  dec_1,  dec_2,  dec_3a,   dec_4a,   dec_5a,   dec_3b,   dec_4b;
    int a0, v0, a1, v1, a2, v2, a3a, v3a, a4a, v4a, a5a, v5a, a3b, v3b, a4b, v4b;
    //Varaiables del BlackJack
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
    //Menú Principal
    Bienvenida();
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
        printf("HOLA, BIENVENIDO AL PROYECTO_X.\n");
        printf("Por favor, seguid las indicaciones en todo momento, y contestad coherentemente a las preguntas que se os hagan.\n");
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
    Continuar();
    do
    {
        Menu_Opciones();
        printf("Introduzca el número de la opción que desee:");
        scanf("%d", &decision_1);
        system("cls");
        switch(decision_1)
        {
            case 1:
                for(y = 0, j = 0; y != 1; y = j)
                {
                    Menu_BlackJack();
                    printf("Introduzca el n%cmero de la opci%cn que desee:", 163, 162);
                    scanf("%d", &decision_2);
                    system("cls");
                    switch(decision_2)
                    {
                        case 1:
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
                                crupier.suma_t = crupier.carta[0].num_j + crupier.carta[1].num_j;
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
                            break;
                        case 2:
                            F_prueba = fopen("Prueba_de_Ficheros.txt", "r");
                            while (fscanf(reglas, "%c", &x) != EOF)
                                printf("%c", x);
                            Continuar();
                            fclose(F_prueba);
                            break;
                        case 3:
                            break;
                        case 4:
                            reglas = fopen("Reglas_del_BlackJack.txt", "r");
                            while (fscanf(reglas, "%c", &x) != EOF)
                                printf("%c", x);
                            Continuar();
                            break;
                        case 5:
                            j = 1;
                            continue;
                        case 6:
                            printf("\nGracias por confiar en nosotros\n");
                            Continuar();
                            Despedida();
                            return 0;
                            break;
                        default:
                            printf("Opci%cn incorrecta, vuelva a introducir una opci%cn.\n", 162, 162);
                            Continuar();
                            break;
                    }
                system("cls");
                }
                break;
            case 2:
                for (i = 0, j = 0; i != 1; i = j)
                {
                    Menu_EscapeRoom();
                    printf("Introduzca el número de la opción que desee:");
                    scanf("%d", &decision_2);
                    system("cls");
                    switch(decision_2)
                    {
                        case 1:
                            for(a0 = 0, v0 = 0; a0 != 1; a0 = v0)
                            {
                                Borrar();
                                printf("*Despiertas tirado en el suelo y oyes a lo lejos una explosi%cn, te encuentras confuso y no sabes d%cnde est%cs, lo %cnico\n", 162, 162, 160, 163);
                                printf("que recuerdas es haber estado en la nave con tu equipo, pero ahora a tu alrededor no ves a nadie.*\n");
                                Continuar();
                                printf("*El traje empieza a emitir ruidos, intentas contactar con alg%cn miembro de tu equipo, pero pasan varios segundos sin \n", 163);
                                printf(" respuesta y decides ponerte en acci%cn.*\n", 162);
                                Continuar();
                                printf("*Te levantas y te sacudes la tierra del cuerpo, por lo visto estas ileso, aunque solo te duele el brazo derecho\n");
                                printf(" un pitido molesto en el o%cdo izquierdo.*\n", 161);
                                Continuar();
                                printf("*Una vez en pie, ves tu mochila cerca, pero al inspeccionarla te das cuenta de que esta vac%ca, te la pones a la y tienes\n", 161);
                                printf(" espalda y caminas un poco por tus alrededores, de pronto, ves a lo lejos la nave %cQu%c vas a hacer?* \n", 168, 130);
                                printf("DECISI%cN 1: Contemplar el paisaje.\n", 162);
                                printf("DECISI%cN 2: Ir a mirar el estado de la nave.\n", 162);
                                printf("Pulse cualquier otro n%cmero para volver a leer.\n", 163);
                                scanf("%i", &dec_0);
                                switch(dec_0)
                                {
                                    case 1:
                                        v0 = 1;
                                        Borrar();
                                        printf("Contemplas el paisaje el cual encuentras muy familiar, se parece demasiado a la tierra. Subes a lo alto de una colina\n");
                                        printf("cercana pero no ves nada que llame tu atención; por lo que decides centrarte en comprobar el estado de la nave.\n");
                                        Continuar();
                                        printf("Necesitas encontrar respuestas.");
                                        system("pause");
                                        case 2:
                                        v0 = 1;
                                        for( a1 = 0, v1 = 0; a1 != 1; a1 = v1)
                                        {
                                        Borrar();
                                        printf("*Te diriges a la nave, y por fuera ves que la cosa pinta mal. Se ha roto el dep%csito de combustible, y hay algunos \n", 162);
                                        printf(" huecos en el casco de titanio, por lo que debes hallar los materiales necesarios para repararla si quieres poder\n");
                                        printf(" despegarla, placas met%clicas de titanio. Pero tienes claro de que va a ser una tarea muy dura.*\n", 160);
                                        Continuar();
                                        printf("*Una vez analizada la situaci%cn por fuera, te dispones a ver que componentes siguen siendo %ctiles dentro de la nave, al\n", 162, 163);
                                        printf(" parecer todo esta bien, pero te das cuenta de que el radio transmisor est%c estropeado, por lo que tendr%cs que\n", 160, 160);
                                        printf(" repararlo si quieres pedir ayuda.(Para repararlo debes encontrar cables, chips localizadores, una antena y un altavoz).*\n", 160);
                                        Continuar();
                                        printf("*Te adentras en el habit%cculo de reabastecimiento de la nave en busca de materiales, para arreglar la nave. Ves una\n");
                                        printf(" caja de herramientas, unos cuantos cables en el suelo, por los que tienes claro que no circula corriente, y otros\n");
                                        printf(" en unas m%cquinas rotas de la nave, por los que puede que circule algo de corriente. %cQu%c vas a hacer?.*\n", 160, 168, 130);
                                        printf("DECISI%cN 1: Coger cables del suelo.\n", 162);
                                        printf("DECISI%cN 2: Coger cables de la m%cquina.\n", 162, 160);
                                        printf("Pulse cualquier otro n%cmero para volver a leer.\n", 163);
                                        scanf("%i",&dec_1);
                                        switch (dec_1)
                                        {
                                            case 1:
                                                v1=1;
                                                Borrar();
                                                printf("*Decides agacharte a coger los cables del suelo y examinas su estado. Pero al inspeccionarlos te das cuenta de que no\n");
                                                printf(" te sirven. De repente, escuchas un chirrido met%clico y antes de que puedas reaccionar una gran placa met%clica cae\n", 160, 160);
                                                printf(" sobre ti mat%cndote en el acto.*\n", 160);
                                                Continuar();
                                                Game_Over();
                                                break;

                                            case 2:
                                                v1 = 1;
                                                Borrar();
                                                for(a2 = 0, v2 = 0; a2 != 1; a2 = v2)
                                                {
                                                    printf("*Te acercas a las maquinas rotas, y tienes que cortar el cable, asi que buscas en la caja de herramientas y encuentras\n");
                                                    printf(" unos alicates con los que consigues cortarlas. Los cables estan buenos, asi que te los guardas en la mochila.*\n");
                                                    Continuar();
                                                    printf("*De repente, un estruendo te interrumpe, acaba de desprenderse del techo del habitaculo una gran placa metalica, justo \n");
                                                    printf(" encima de donde estaban los cables que se encontraban en el suelo. La inspeccionas, pero es de aluminio y no te sirve \n");
                                                    printf(" para reparar el casco. Con ayuda de las herramientas y unos cuantos tornillos consigues volver a colocar la placa\n");
                                                    printf(" met%clica en su sitio.*\n", 160);
                                                    Continuar();
                                                    printf("*Como las herramientas fueron utiles, asi que, sacas las herramientas de su caja y te las guardas en la mochila. Ahora \n");
                                                    printf(" tienes un: alicate universal, un juego de destornilladores, y una llave inglesa.*\n");
                                                    Continuar();
                                                    printf("*Inspeccionado en su totalidad la sala, encuentras galones de combustible en un armario, pero ahora mismo no los \n");
                                                    printf(" necesitas, y como ves que no hay nada mas relevante alli. Sales del habitaculo ¿Que decides hacer ahora?.*\n");
                                                    printf("DECISI%cN 1: Seguir inspeccionando la nave.\n", 162);
                                                    printf("DECISI%cN 2: Salir de la nave.\n", 162);
                                                    printf("Pulse cualquier otro n%cmero para volver a leer.\n", 163);
                                                    scanf("%i",&dec_2);
                                                    switch (dec_2)
                                                    {
                                                        case 1:
                                                            v2=1;
                                                            Borrar();
                                                            for(a3a = 0, v3a = 0; a3a != 1; a3a = v3a)
                                                            {
                                                                printf("*Te adentras por los largos pasillos de la nave, teniendo m%cs cuidado de por donde vas, ahora que sabes que la nave es\n", 160);
                                                                printf(" un campo de minas. Tu objetivo sigue siendo el mismo, as%c que ahora te dispones a buscar los chips localizadores. No\n", 161);
                                                                printf(" sabes muy bien el donde est%cs, en uno de los pasillos encuentras un mapa del interior de la nave y te lo guardas. \n", 160);
                                                                Continuar();
                                                                printf(" ¿A qu%c lugar quieres ir ahora?*\n", 130);
                                                                printf("DECISI%cN 1: Buscar en la sala de mandos.\n", 162);
                                                                printf("DECISI%cN 2: Buscar en la sala de navegaci%cn principal.\n", 162, 162);
                                                                printf("Pulse cualquier otro n%cmero para volver a leer.\n", 163);
                                                                scanf("%i", &dec_3a);
                                                                switch (dec_3a)
                                                                {
                                                                    case 1:
                                                                    v3a=1;
                                                                    Borrar();
                                                                    for(a4a = 0, v4a = 0; a4a != 1; a4a = v4a)
                                                                    {
                                                                        printf("*Te diriges a la sala de mandos. De camino recuerdas que hay un radar que te podr%ca ser %ctil, puesto que dentro\n", 161, 163);
                                                                        printf(" seguro que tiene un chip localizador. Ni bien entras en la sala, el radar es lo primero que buscas. Al no encontrarlo\n");
                                                                        printf(" a la vista empiezas a buscar por los cajones hasta que lo encuentras. Ya en tu mano, te dispones a desmontarlo con \n");
                                                                        printf(" ayuda de las herramientas, y tras desmontar la pantalla del radar, ah%c lo ves, el chip localizador, lo arrancas y\n", 161);
                                                                        printf(" lo analizas, por lo que se ve, est%c en buen estado, as que la guardas en la mochila. De repente, mientras ve%cas que\n", 160, 161);
                                                                        printf(" m%cs cosas hab%ca en la sala, te empieza a dar un fuerte dolor de cabeza, y te sangra la nariz.\n", 160, 161);
                                                                        Continuar();
                                                                        printf("*Te sientes muy d&cbil; por lo que la mejor opcion va a ser descansar un rato para recuperar las fuerzas. Como no hay \n", 130);
                                                                        printf(" sillones ni ningún lugar donde echarte, te sientas en el suelo apoyado contra la pared y te quedas dormido.*\n");
                                                                        Continuar();
                                                                        printf("-Creo que lo mejor ser%c buscar en la sala de mandos, all%c hay un pequeño radar que me puede ser %ctil.\n", 160, 161, 163);
                                                                        Continuar();
                                                                        printf("*Te diriges al puesto de mandos por un pasillo seguro*\n");
                                                                        Continuar();
                                                                        printf("-Bien, ahora solo tengo que arrancar el chip localizador del panel de control.\n");
                                                                        Continuar();
                                                                        printf("*Rompes la pantalla protectora del panel y consigues arrancar el chip sin ning%cn problema*\n", 163);
                                                                        Continuar();
                                                                        printf("-Cada vez queda menos para que esta pesadilla acabe.\n");
                                                                        Continuar();
                                                                        printf("*Sientes un fuerte dolor en la cabeza y empiezas a sangrar por la nariz*\n");
                                                                        Continuar();
                                                                        printf("-*****, que dolor... Espero que no me cause problemas. Creo que descansar%c un rato hasta recuperar fuerzas.\n", 130);
                                                                        Continuar();
                                                                        printf("*Te sientas en una pared del habit%cculo y descansas durante unos cuantos minutos hasta que te vuelves a encontrar mejor*\n", 160);
                                                                        Continuar();
                                                                        printf("-Creo que tengo las suficientes fuerzas como para proseguir en mi b%csqueda. Lo siguiente era… Una antena. En la sala de\n", 163);
                                                                        printf(" comunicaciones tiene que haber algún tipo de antena parab%clica.", 162);
                                                                        Continuar();
                                                                        printf("*Emprendes tu camino hacia la sala de comunicaciones, pero tienes un dilema, el pasillo es estrecho y hay riesgo de que \n");
                                                                        printf(" el traje espacial se quede enganchado*\n");
                                                                        printf("DECISI%cN 1: Intentas pasar.\n", 162);
                                                                        printf("DECISI%cN 2: Buscas otro camino por el sistema de ventilaci%cn.\n", 162, 162);
                                                                        printf("Pulse cualquier otro n%cmero para volver a leer.\n", 163);
                                                                        scanf("%i", &dec_4a);
                                                                        switch (dec_4a)
                                                                        {
                                                                            case 1:
                                                                            v4a=1;
                                                                            Borrar();
                                                                            for(a5a = 0, v5a = 0; a5a != 1; a5a = v5a)
                                                                            {
                                                                                printf("-Si no me he muerto hasta el momento creo que podr%c pasar por esto.\n", 130);
                                                                                Continuar();
                                                                                printf("*Te agachas y gateas por el suelo hasta llegar al final del pasillo*\n");
                                                                                Continuar();
                                                                                printf("-Buff… Eso ha estado cerca, por un momento cre%c que no pasar%ca, era m%cs estrecho de lo que esperaba.\n", 161, 161, 160);
                                                                                Continuar();
                                                                                printf("*Miras a tu alrededor y encuentras la antena y el micr%cfono que tambi%cn necesitabas*\n", 162, 130);
                                                                                Continuar();
                                                                                printf("-Perfecto, ya tengo todo lo que quer%ca, ya puedo salir de este trozo de chatarra.\n", 161);
                                                                                Continuar();
                                                                                printf("*Sales de la nave por donde has venido*\n");
                                                                                Continuar();
                                                                                printf("-Ahora solo necesito montar el transmisor.\n");
                                                                                Continuar();
                                                                                printf("*Empiezas a montar el transmisor y lo construyes sin ning%cn problema, se nota que estudiaste en la UPM*\n", 163);
                                                                                Continuar();
                                                                                printf("-Ahora solo tengo que enviar la señal de mi posici%cn…\n", 162);
                                                                                Continuar();
                                                                                printf("*En este momento tienes dudas, no sabes si enviar la señal de rescate o quedarte en el planeta misterioso*\n");
                                                                                printf("DECISI%cN 1: Enviar la señal de socorro.\n", 162);
                                                                                printf("DECISI%cN 2: Quedarte a explorar el planeta.\n", 162);
                                                                                printf("Pulse cualquier otro n%cmero para volver a leer.\n",163);
                                                                                scanf("%i", &dec_5a);
                                                                                switch (dec_5a)
                                                                                {
                                                                                    case 1:
                                                                                        v5a=1;
                                                                                        Borrar();
                                                                                        printf("*Decides que lo m%cs prudente es enviar la señal de socorro. Al cabo de un rato aparece un veh%cculo a%creo que te \n", 160, 161, 130);
                                                                                        printf(" resulta familiar, pero est%cs confundido, ¿c%cmo han tardado tan poco en encontrarte? Los integrantes del equipo de\n", 160, 162);
                                                                                        printf(" rescate te explican la situaci%cn, emprendiste un viaje solitario en la nave cuando esta sufri%c un fallo mec%cnico \n", 162, 162);
                                                                                        printf(" provocando que te estrellases sin salir siquiera del planeta. El golpe te caus%c p%crdida de memoria y no recordabas \n", 162, 130);
                                                                                        printf(" nada posterior al lanzamiento. Eres llevado al hospital m%cs cercano donde te recuperar%cs del accidente*\n", 160, 160);
                                                                                        Continuar();
                                                                                        printf("HAS GANADO\n");
                                                                                        return 0;
                                                                                    case 2:
                                                                                        v5a=1;
                                                                                        Borrar();
                                                                                        printf("*Decides darte una oportunidad en el planeta extraterrestre y quedarte all%c. Pasas las siguientes semanas recogiendo frutas, aunque estas te resultan muy familiares. Despu%cs de casi un mes realizas contacto con otros humanos, est%cs contrariado hasta que estos te explican que sigues en la Tierra. Inmediatamente te desmayas y te llevan al hospital m%cs cercano. El accidente con la nave sucedi%c debido a un fallo mec%cnico y al estrellarte sufriste perdidas de memoria con las que no pod%cas recordar nada posterior al lanzamiento de la nave. Permanecer%cs en el hospital hasta tu recuperaci%cn total*\n", 161, 130, 160, 160, 162, 160, 161, 160, 162);
                                                                                        Continuar();
                                                                                        printf("HAS GANADO\n");
                                                                                        return 0;
                                                                                    default:
                                                                                        Borrar();
                                                                                        printf("Ha decidido repetir.\n");
                                                                                        break;
                                                                                }
                                                                            }
                                                                            break;
                                                                        case 2:
                                                                            v4a=1;
                                                                            Borrar();
                                                                            printf("-Lo mejor ser%c ir por los conductos de ventilaci%cn superior.\n", 160, 162);
                                                                            Continuar();
                                                                            printf("*Arrancas la rejilla de ventilaci%cn y te metes dentro del conducto gateando*\n", 162);
                                                                            Continuar();
                                                                            printf("-Vale, ahora solo tengo que seguir as%c hasta llegaaaa… \n", 161);
                                                                            Continuar();
                                                                            printf("*Pesas demasiado como para que la estructura de ventilaci%cn dañada aguante tu peso. El golpe es tan fuerte que te \n", 162);
                                                                            printf(" rompes las piernas en la ca%cda y la pequeña conmoción producida por el accidente de la nave se agrava produciendo \n", 161);
                                                                            printf(" tu muerte*\n");
                                                                            Continuar();
                                                                            Game_Over();
                                                                            break;
                                                                        default:
                                                                            Borrar();
                                                                            printf("Ha decidido repetir.\n");
                                                                            break;
                                                                        }
                                                                    }
                                                                    break;
                                                                case 2:
                                                                    v3a=1;
                                                                    system ("cls");
                                                                    printf("*Entras en la sala de navegaci%cn principal, con la esperanza de encontrar algo de utilidad. Cuando ya est%cs llegando \n", 162, 160);
                                                                    printf(" te das cuenta de que la sala est%c al lado del dep%csito de combustible, y que a medida que te acercas, el suelo est%c \n", 160, 162, 160);
                                                                    printf(" cubierto de una fina capa de combustible. No te parece buena idea seguir, pero la curiosidad de saber s%c dentro de \n", 161);
                                                                    printf(" la sala principal hay algo %ctil te puede m%cs.\n", 163, 160);
                                                                    Continuar();
                                                                    printf("*Una vez dentro de la sala principal, encuentras un GPS el cual dentro tiene un chip localizador, el GPS est%c averiado,\n", 160);
                                                                    printf(" asi que, si lo abres no afectar%cs en nada el funcionamiento de la nave, por lo que decides, extraer el chip.*\n", 160);
                                                                    Continuar();
                                                                    printf("*Utilizas las herramientas, pero en el proceso de desarmado, encuentras una tapa, la cual no puedes abrir con las \n");
                                                                    printf("herramientas, asi que decides hacer fuerza para romper la tapa. Terminas rompi%cndola y se ve un hueco y al fondo de \n", 130);
                                                                    printf(" %cl, el chip localizador, tratas de usar las herramientas, pero no entran, son muy grandes para caber dentro del hueco, \n", 130);
                                                                    printf(" asi que, metes tu mano y tiras con todas tus fuerzas del %cl, hasta que lo extraes, todo parece estar bien hasta que \n", 130);
                                                                    printf(" saltan unas chispas, que prenden el combustible bajo tus pies. Ardes por completo*\n");
                                                                    Continuar();
                                                                    Game_Over();
                                                                    break;

                                                                default:
                                                                    Borrar();
                                                                    printf("Ha decidido repetir.\n");
                                                                    break;
                                                                }
                                                            }
                                                            break;

                                                        case 2:
                                                            v2=1;
                                                            Borrar();
                                                            for(a3b = 0, v3b = 0; a3b != 1; a3b = v3b)
                                                            {
                                                                printf("-Ser%c mejor que salga de la nave, no quiero acabar sepultado por este mont%cn de chatarra.\n", 160, 162);
                                                                Continuar();
                                                                printf("*Decides salir de la nave con cuidado, crees que es lo m%cs seguro*\n", 160);
                                                                Continuar();
                                                                printf("-Bien, creo que ser%c mejor investigar la zona, aunque no se d%cnde voy a conseguir el resto de los materiales que \n", 160, 162);
                                                                printf(" necesito para montar el transmisor.\n");
                                                                Continuar();
                                                                printf("*Te alejas un par de pasos y te sientas en el suelo a pensar qu%c hacer, recuerdas que la nave tiene un m%cdulo de \n", 130, 162);
                                                                printf(" almacenamiento*\n");
                                                                Continuar();
                                                                printf("-¡Claro! ¿C%cmo no se me hab%ca ocurrido antes? Es mi %cnica fuente de recursos ahora mismo, espero encontrar lo \n", 162, 161, 163);
                                                                printf(" necesario.\n");
                                                                Continuar();
                                                                printf("*Comienzas a andar hacia el almac%cn y encuentras un arma en el suelo, la coges y la enganchas al traje \n", 130);
                                                                printf(" espacial*\n");
                                                                Continuar();
                                                                printf("*Sigues andando hasta entrar en el almac%cn*\n", 130);
                                                                Continuar();
                                                                printf("-De acuerdo, ahora tengo que buscar el chip de localizaci%cn, la antena parab%clica y el micr%cfono.\n", 162, 162, 162);
                                                                printf("DECISI%cN 1: Buscar por la izquierda.\n", 162);
                                                                printf("DECISI%cN 2: Buscar por la derecha.\n", 162);
                                                                printf("Pulse cualquier otro n%cmero para volver a leer.\n", 163);
                                                                scanf("%i", &dec_3b);
                                                                switch(dec_3b)
                                                                {
                                                                    case 1:
                                                                        v3b=1;
                                                                        Borrar();
                                                                        for (a4b = 0, v4b = 0; a4b != 1; a4b = v4b)
                                                                        {
                                                                            printf("-Empezar%e por la izquierda, siendo zurdo eso tendr%ca que darme suerte.\n", 130, 161);
                                                                            Continuar();
                                                                            printf("*Comienzas a buscar por la parte izquierda del almac%cn por alg%cn tipo de raz%cn supersticiosa*\n", 130, 162, 162);
                                                                            Continuar();
                                                                            printf("-Aqu%c parece haber muchas cajas, espero tener suerte.\n", 161);
                                                                            Continuar();
                                                                            printf(" *Est%cs un buen rato buscando hasta que encuentras la antena parab%clica, no es tan grande como esperabas, pero servir%c*\n",160, 162, 160);
                                                                            Continuar();
                                                                            printf("-Una cosa menos, solo faltan dos.\n");
                                                                            Continuar();
                                                                            printf("*Sigues buscando*\n");
                                                                            Continuar();
                                                                            printf("-Parece que aqu%c no hay nada m%cs.\n", 161, 160);
                                                                            Continuar();
                                                                            printf("*Empiezas a buscar por la derecha*\n");
                                                                            Continuar();
                                                                            printf("*Abres la primera caja y encuentras el micr%cfono*\n", 162);
                                                                            Continuar();
                                                                            printf("-Parece que he vuelto a tener suerte.\n");
                                                                            Continuar();
                                                                            printf("*Despu%cs de un rato buscando encuentras el chip y comienzas a salir del almac%cn*\n", 130, 130);
                                                                            Continuar();
                                                                            printf("-Ya tengo todo lo que buscaba y lo he conseguido bastante r%cpido, parece que he tenido suerte.\n", 160);
                                                                            Continuar();
                                                                            printf("*Mientas buscabas se ha hecho de noche*\n");
                                                                            printf("DECISI%cN 1: Quedarte dentro de la nave.\n", 162);
                                                                            printf("DECISI%cN 2: Salir de la nave y crear una hoguera.\n", 162);
                                                                            printf("Pulse cualquier otro n%cmero para volver a leer.\n", 163);
                                                                            scanf("%i", &dec_4b);
                                                                            switch (dec_4b)
                                                                            {
                                                                                case 1:
                                                                                    v4b=1;
                                                                                    Borrar();
                                                                                    printf("-Me quedar%c aqu%c dentro, es m%cs seguro que salir.\n", 130, 161, 160);
                                                                                    Continuar();
                                                                                    printf("*Te tumbas encima de un mont%cn de cajas y duermes hasta el d%ca siguiente*\n", 162, 161);
                                                                                    Continuar();
                                                                                    printf("*Te despiertas y escuchas un ruido parecido al de un helic%cptero, sales y compruebas que es un veh%cculo a%creo que \n", 162, 161,130);
                                                                                    printf(" acaba de aterrizar. Del interior de la nave sale una criatura. ¡Es un humano! ¿C%cmo es posible? Te sientas en el \n", 162);
                                                                                    printf(" suelo debido a la confusi%cn. Este te explica que pertenece al equipo de rescate de la Agencia Espacial Europea,\n", 162);
                                                                                    printf(" despu%cs del lanzamiento de tu nave esta tuvo un fallo mec%cnico provocando que se estrellase contra el suelo. Este \n", 130, 160);
                                                                                    printf(" accidente te ha provocado p%crdidas de memoria y no recuerdas nada posterior al lanzamiento. Eres llevado al hospital \n", 130);///
                                                                                    printf(" m%cs cercano para que seas atendido*\n", 160);
                                                                                    Continuar();
                                                                                    printf("HAS GANADO\n");
                                                                                    break;

                                                                                case 2:
                                                                                    v4b=1;
                                                                                    Borrar();
                                                                                    printf("-Necesito salir de esta nave, no me da seguridad, no tanta como salir.\n");
                                                                                    Continuar();
                                                                                    printf("*Creas una hoguera y te duermes profundamente, al cabo de un rato parte del combustible procedente del dep%csito llega \n", 162);
                                                                                    printf(" hasta ti. El fuego de la hoguera chisporrotea provocando un incendio al caer sobre el combustible. Mueres quemado*\n");
                                                                                    Continuar();
                                                                                    Game_Over();
                                                                                    break;

                                                                                default:
                                                                                    Borrar();
                                                                                    printf("Ha decidido repetir.\n");
                                                                                    break;
                                                                            }
                                                                        }
                                                                        break;

                                                                    case 2:
                                                                        v3b=1;
                                                                        Borrar();
                                                                        printf("Empezar%c a buscar por la derecha.\n", 130);
                                                                        Continuar();
                                                                        printf("*Comienzas la b%csqueda de los materiales por la parte derecha del almac%cn*\n", 163, 130);
                                                                        Continuar();
                                                                        printf("-Parece que es mi d%ca de suerte, en la primera caja que abro encuentro el micr%cfono, esto me ahorrar%c tiempo.\n", 161, 162, 160);
                                                                        Continuar();
                                                                        printf("*Sigues buscando y encuentras el chip*\n");
                                                                        Continuar();
                                                                        printf("-¡Genial! Ahora solo me falta la antena parab%clica.\n", 162);
                                                                        Continuar();
                                                                        printf("*Detr%cs de unas cajas encuentras una gran antena, ya tienes todos los materiales y sigue siendo de d%ca*\n", 160, 161);
                                                                        Continuar();
                                                                        printf("-Perfecto, ya solo me queda montar el radio transmisor.\n");
                                                                        Continuar();
                                                                        printf("*Te diriges al exterior del almac%cn para montar el transmisor cuando a lo lejos ves una figura acercándose a ti,\n", 130);
                                                                        printf(" entras en p%cnico y disparas con tu arma*\n", 160);
                                                                        Continuar();
                                                                        printf("-No s%c qu%c ser%ca eso, pero creo que me he salvado. Voy a ver que era.\n", 130, 130, 161);
                                                                        Continuar();
                                                                        printf("*Te acercas al cad%cver del ser al que acabas de disparar y es un humano. No sabes que hacer, tu cerebro colapsa y caes \n", 160);///
                                                                        printf(" al suelo. Despiertas dentro de un calabozo. Nunca llegaste a abandonar la Tierra, tu nave se estrell%c despu%cs de un \n", 162, 130);
                                                                        printf(" fallo mec%cnico y por culpa del golpe no recuerdas nada posterior al lanzamiento. Pasar%cs el resto de tus d%cas en la \n", 160, 160, 161);
                                                                        printf(" c%crcel*\n", 160);
                                                                        Continuar();
                                                                        Game_Over();
                                                                        return 0;
                                                                        break;

                                                                    default:
                                                                        Borrar();
                                                                        printf("Ha decidido repetir.\n");
                                                                        break;
                                                                }
                                                            }
                                                            break;
                                                        default:
                                                            Borrar();
                                                            printf("Ha decidido repetir.\n");
                                                            break;
                                                    }
                                                }
                                                break;
                                            default:
                                                Borrar();
                                                printf("Ha decidido repetir.\n");
                                                break;
                                        }
                                    }
                                    break;
                                default:
                                    system ("cls");
                                    printf("Ha decidido repetir.\n");
                                    break;
                                }
                            }
                            break;
                        case 2:
                            j = 1;
                            break;
                        case 3:
                            printf("\nGracias por confiar en nosotros\n");
                            Continuar();
                            Despedida();
                            return 0;
                            break;
                        default:
                            printf("Opci%cn incorrecta, vuelva a introducir una opci%cn.\n", 162, 162);
                            Continuar();
                            break;
                    }
                    system("cls");
                }
                break;
            case 3:
                printf("\nGracias por confiar en nosotros\n");
                Continuar();
                Despedida();
                return 0;
                break;
            default:
                printf("Opci%cn incorrecta, vuelva a introducir una opci%cn.\n", 162, 162);
                system ("pause");
                system("cls");
                break;
        }
    }while (1);
}

///Funciones
void Bienvenida()
{
	printf("%cPREPARADO PARA LA DIVERSI%cN?\n", 168, 224);
	system("Pause");
	printf("%c%cBIENVENIDO AL SAL%cN DE JUEGOS!!\n\n", 173, 173, 224);
	Continuar();
}

void Continuar()
{
	system("Pause");
    system("cls");
}

void Menu_Opciones()
{
	printf("\n");
	printf("MEN%c PRINCIPAL:\n", 233);
	printf("1.Jugar al BlackJack\n");
	printf("2.Probar suerte en el EscapeRoom\n");
	printf("3.Salir del programa\n\n");
}
void Menu_BlackJack()
{
	printf("\n");
	printf("MEN%c DEL BLACKJACK:\n", 233);
	printf("1.Jugar\n");
    printf("2.Comprobar el dinero\n");
    printf("3.Ranking\n");
    printf("4.Reglas del BlackJack\n");
	printf("5.Volver al Men%c Principal\n", 163);
	printf("6.Salir del programa\n\n");
}


void Menu_EscapeRoom()
{
	printf("\n");
	printf("MEN%c DEL ESCAPEROOM:\n", 233);
	printf("1.Comenzar la partida\n");
	printf("5.Volver al Men%c Principal\n", 163);
	printf("3.Salir del programa\n\n");
}

void Despedida()
{
	printf("\n");
	printf("ESPERAMOS QUE HAYAS DISFRUTADO DE LA EXPERIENCIA\n");
	Continuar();
	printf("\n HASTA LA PR%cXIMA.\n", 224);
}
void Game_Over()
{
    printf("       GGGGGGG          AAAA      MMMMM            MMMMM  EEEEEEEEEEE \n");
    printf("     GGGGGGGGGGG       AAAAAA      MMMMM          MMMMM    EEE    EEE \n");
    printf("    GGGGG    GGGG     AAA  AAA      MMMMM        MMMMM     EEE     EE \n");
    printf("    GGGG     GGGG    AAA    AAA     MMMMMM      MMMMMM     EEE        \n");
    printf("    GGGG            AAA      AAA    MMMMMMM    MMMMMMM     EEE     EE \n");
    printf("    GGGG            AAA      AAA    MMM MMMM  MMMM MMM     EEEEEEEEEE \n");
    printf("    GGGG    GGGGGG  AAA      AAA    MMM  MMMMMMMM  MMM     EEEEEEEEEE \n");
    printf("    GGGG     GGGG   AAAAAAAAAAAA    MMM    MMMM    MMM     EEE     EE \n");
    printf("    GGGG     GGGG   AAAAAAAAAAAA    MMM            MMM     EEE        \n");
    printf("    GGGGG   GGGGG   AAA      AAA    MMM            MMM     EEE     EE \n");
    printf("     GGGGGGGGGGGG   AAA      AAA    MMM            MMM     EEE    EEE \n");
    printf("      GGGGGGGG GG   AAA      AAA   MMMMM          MMMMM   EEEEEEEEEEE \n\n");

    printf("            OOOOOOO    VVVV    VVVV   EEEEEEEEEEE  RRRRRRRRRR         \n");
    printf("           OOOOOOOOO    VVV    VVV     EEE    EEE   RRR    RRR        \n");
    printf("          OOO     OOO   VVV    VVV     EEE     EE   RRR    RRR        \n");
    printf("          OOO     OOO   VVV    VVV     EEE          RRR    RRR        \n");
    printf("          OOO     OOO   VVV    VVV     EEE     EE   RRR   RRR         \n");
    printf("          OOO     OOO   VVV    VVV     EEEEEEEEEE   RRRRRRRR          \n");
    printf("          OOO     OOO   VVV    VVV     EEEEEEEEEE   RRRRRRRR          \n");
    printf("          OOO     OOO   VVV    VVV     EEE     EE   RRR  RRR          \n");
    printf("          OOO     OOO   VVV    VVV     EEE          RRR   RRR         \n");
    printf("          OOO     OOO    VVV  VVV      EEE     EE   RRR    RRR        \n");
    printf("           OOOOOOOOO      VVVVVV       EEE    EEE   RRR     RRR       \n");
    printf("            OOOOOOO        VVVV       EEEEEEEEEEE   RRR     RRRR      \n\n");
}
void Borrar()
{
    system("cls");
}
//Funciones Tool
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

//Funciones para comprobar siempre la suma
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
