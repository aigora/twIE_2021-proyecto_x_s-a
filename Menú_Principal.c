///Presentación de las librerías
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


/// Definimos variables
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

///Presentación de las funciones

//Funciones Tool
void Bienvenida();
void Continuar();
void Borrar();

//Funciones Menú Principal
void Menu_Opciones();
void Menu_BlackJack();
void Menu_EscapeRoom();
void Despedida();

//Funciones de Escape Room
void Game_Over();
void Imprimir_lineas(int l1, int l2);

//Funciones del Black Jack
void Menu_Final();
void imp_color_rojo_10(int num, char palo);
void imp_color_rojo_n(char num, char palo);
int Premio( _Bool BJ_p, _Bool BJ_c, int apuesta, int suma_p, int suma_c);
int suma_cartas(int i, int cartas[]);

/// Estructuras

//Estrucutras del Menú Principal
typedef struct{                  /** Componentes de una carta **/
    char num_i;
    int num_j;
    char palo;
}e_carta;

typedef struct{                  /** Cosas del jugador **/
    e_carta carta[20];         /* Estructura anidada en otra */
    char nombre[100];
    int monedero;
    int suma_t;
    int apuesta;
    _Bool BJ;
    _Bool Pasar_21;
}datos_jugador;

//Estructuras del Escape Room
typedef struct{
    char cont[700];
}fichero;

///Programa
int main()
{
    //Variables del Menú Principal
    int decision_1, decision_2, y, j, x;

    //Variables del Escape Room
    FILE *F_EscRoom;
    int p;
    char enter;
    fichero linea[200];
    char cad_car[700];
    if((F_EscRoom = fopen("Escape_Room.txt", "r")) == NULL){
        printf("Se ha producido un error a la hora de abrir el archivo...\n");
        return 1;
    }
    while(fgets(cad_car, 700, F_EscRoom) != NULL){
        strcpy(linea[p].cont, cad_car);
    p++;
    }
    fclose(F_EscRoom);
    int dec_0,  dec_1,  dec_2,  dec_3a,   dec_4a,   dec_5a,   dec_3b,   dec_4b;
    int a0, v0, a1, v1, a2, v2, a3a, v3a, a4a, v4a, a5a, v5a, a3b, v3b, a4b, v4b;

    //Varaiables del BlackJack
    FILE *reglas;
    FILE *Datos_j;
    datos_jugador crupier = {.nombre = "Susana Picado"};
    int carta_jug[]  = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
    char carta_imp[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', '\0'};                 /** Números Posibles **/
    char palo[]      = { 3, 4, 5, 6, '\0' };                                                                    /** Palos Posibles **/
    char nc, pc;
    char x1, x2;
    char aux_c[5];
    int m, n;
    srand(time(NULL));
    int cartas[21];
    int n_c, i, c, aux, Dec_BJ;
    int num_jug, i1;
    int suma, eleccion, premio;

    //Menú Principal
    Bienvenida();
    if ((Datos_j = fopen("Datos_del_jugador.txt", "w")) == NULL){
        printf("Error al abrir el fichero.\n");
        return -1;
    }
    do{

        printf("HOLA, BIENVENIDO AL PROYECTO_X.\n");
        printf("Por favor, seguid las indicaciones en todo momento, y contestad coherentemente a las preguntas que se os hagan.\n");
        printf("Elija un n%cmero de jugadores de 1 a 7.\n", 163);
        scanf("%i", &num_jug);
    }while ((num_jug<1)||(num_jug>7));

    //generador de los jugadores
    datos_jugador participante[num_jug];

    //se guardan en la memoria los nombres y dinero de los jugadores
    for(i1 = 0; i1 < num_jug; i1++){
        printf("Introducid el nombre del participante %i:\n", i1+1);
        scanf("%49s[^\n]", participante[i1].nombre);
        fflush(stdin);
        do{
            printf("Elija la cantidad inicial con la que %s quiere empezar a jugar (Cantidad entera): \n", participante[i1].nombre);
            scanf("%i", &participante[i1].monedero);
            fprintf(Datos_j, "El nombre del participante %i es: %s\n", i1+1, participante[i1].nombre);
            fprintf(Datos_j, "El tiene %i euros.\n", participante[i1].monedero);
        }while((participante[i1].monedero <= 0));
        fclose(Datos_j);
        printf("\n");
    }
    Continuar();
    do{
        Menu_Opciones();
        printf("Introduzca el n%cmero de la opci%cn que desee:", 163, 162);
        scanf("%d", &decision_1);
        Continuar();
        switch(decision_1){
            case 1:
                for(y = 0, j = 0; y != 1; y = j){
                    Menu_BlackJack();
                    printf("Introduzca el n%cmero de la opci%cn que desee:", 163, 162);
                    scanf("%d", &decision_2);
                    switch(decision_2){
                        case 1:
                            do{
                                //Se generan las 10 primeras cartas de todos los jugadores
                                for(i1 = 0; i1 < num_jug; i1++){
                                    for(i = 0; i < 10; i++){
                                        nc = rand()%13;
                                        pc = rand()%4;
                                        if(carta_imp[nc] == carta_imp[9]){
                                            n_c = 10;
                                            participante[i1].carta[i].num_i = n_c;
                                            participante[i1].carta[i].num_j = carta_jug[nc];
                                            participante[i1].carta[i].palo  = palo[pc];
                                        }
                                        else{
                                            participante[i1].carta[i].num_i = carta_imp[nc];
                                            participante[i1].carta[i].num_j = carta_jug[nc];
                                            participante[i1].carta[i].palo  = palo[pc];
                                        }
                                    }
                                }

                                //se generan las 10 primeras cartas del crupier
                                for(c = 0; c < 10; c++){
                                    nc = rand()%13;
                                    pc = rand()%4;
                                    if(carta_imp[nc] == carta_imp[9]){
                                        n_c = 10;
                                        crupier.carta[c].num_i = n_c;
                                        crupier.carta[c].num_j = carta_jug[nc];
                                        crupier.carta[c].palo  = palo[pc];
                                    }
                                    else{
                                        crupier.carta[c].num_i = carta_imp[nc];
                                        crupier.carta[c].num_j = carta_jug[nc];
                                        crupier.carta[c].palo  = palo[pc];
                                    }
                                }

                                //Se introduce la cantidad a apostar por los jugadores
                                for(i1 = 0; i1 < num_jug; i1++){
                                    do{
                                            Continuar();
                                        printf("Tu monedero actual es %i.\n", participante[i1].monedero);
                                        printf("%s, %ccu%cnto quieres apostar de tu monedero?\n", participante[i1].nombre, 168, 160);
                                        scanf("%i", &participante[i1].apuesta);
                                    }while (participante[i1].apuesta < 0 || participante[i1].apuesta > participante[i1].monedero);
                                    participante[i1].monedero -= participante[i1].apuesta;
                                }
                                Continuar();

                                //Imprimimos solo una carta del crupier
                                printf("Las cartas del crupier son:");
                                for(c = 0; c < 1; c++){
                                    if(crupier.carta[c].num_i == 10){
                                        imp_color_rojo_10(crupier.carta[c].num_i, crupier.carta[c].palo);
                                    }
                                    else{
                                        imp_color_rojo_n(crupier.carta[c].num_i, crupier.carta[c].palo);
                                    }
                                    printf("%c%c", 63, 63);
                                    printf("\n\n");
                                }

                                //Imprimimos las cartas de los jugadores
                                for(i1 = 0; i1 < num_jug; i1++){
                                    if(participante[i1].apuesta == 0){
                                        printf("%s, no participa en esta ronda.\n", participante[i1].nombre);
                                    }
                                    else{
                                        printf("Las cartas de %s son:", participante[i1].nombre);
                                        for(i = 0; i < 2; i++){
                                            if(participante[i1].carta[i].num_i == 10){
                                                imp_color_rojo_10(participante[i1].carta[i].num_i, participante[i1].carta[i].palo);
                                            }
                                            else{
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
                                for (i1 = 0; i1 < num_jug; i1++){
                                    if(participante[i1].apuesta == 0){
                                        printf("%s, no participa en esta ronda.\n", participante[i1].nombre);
                                        Continuar();
                                    }
                                    else{
                                        /*Primero las cartas del crupier*/
                                        printf("Las cartas del crupier son:");
                                        i=0;
                                        if(crupier.carta[i].num_i == 10){
                                            imp_color_rojo_10(crupier.carta[i].num_i, crupier.carta[i].palo);
                                        }
                                        else{
                                            imp_color_rojo_n(crupier.carta[i].num_i, crupier.carta[i].palo);
                                        }
                                        printf("%c%c", 63, 63);
                                        printf("\n\n");

                                        /*Primero imprimimos las primeras 2 cartas y su suma.*/
                                        printf("Es el turno de %s\n", participante[i1].nombre);
                                        printf("Tus cartas son: ", participante[i1].nombre);
                                        for(i = 0; i < 2; i++){
                                            if(participante[i1].carta[i].num_i == 10){
                                                imp_color_rojo_10(participante[i1].carta[i].num_i, participante[i1].carta[i].palo);
                                            }
                                            else{
                                                imp_color_rojo_n(participante[i1].carta[i].num_i, participante[i1].carta[i].palo);
                                            }
                                            cartas[i] = participante[i1].carta[i].num_j;
                                        }
                                        participante[i1].suma_t = suma_cartas(2, cartas);
                                        printf("--> %i", participante[i1].suma_t);
                                        aux = 3;

                                        /*Ahora comprobamos la suma de las dos primeras, y si son menores que 21, le damos la opción a que pida más o se plante*/
                                        if (participante[i1].suma_t == 21){
                                            printf("%cBlackjack!\n",173);
                                            participante[i1].BJ = 1;/*Si obtiene 21 con las dos primeras cartas _Bool BJ (Black Jack), tendrá valor 1, que afirma ese hecho.*/
                                        }
                                        else{
                                            participante[i1].BJ = 0;/*Sino, recibirá el valor 0.*/
                                            do{
                                                do{
                                                    if(participante[i1].suma_t < 21){
                                                        printf("\n%cQu%c quieres hacer?\n", 168, 130);
                                                        printf("Pedir:1 \t Plantarse:2\n");
                                                        scanf("%i", &eleccion);
                                                        switch (eleccion){
                                                        case 1:
                                                            for(i = 0; i < aux ; i++){
                                                                if(participante[i1].carta[i].num_i == 10){
                                                                    imp_color_rojo_10(participante[i1].carta[i].num_i, participante[i1].carta[i].palo);
                                                                }
                                                                else{
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
                                    if(participante[i1].suma_t > 21){
                                        participante[i1].Pasar_21 = 1;
                                    }
                                    if(participante[i1].suma_t <= 21){
                                        participante[i1].Pasar_21 = 0;
                                    }
                                    Continuar();
                                    }
                                }

                                //Ahora viene el turno del crupier, el cual si saca menos de un 16, pedirá carta; pero, si saca más, no pedira más.
                                printf("Ahora es el turno del crupier.\n");
                                printf("Las cartas del crupier son: \n");
                                for(c = 0; c < 2; c++){
                                    if(crupier.carta[c].num_i == 10){
                                        imp_color_rojo_10(crupier.carta[c].num_i, crupier.carta[c].palo);
                                    }
                                    else{
                                        imp_color_rojo_n(crupier.carta[c].num_i, crupier.carta[c].palo);
                                    }
                                }
                                crupier.suma_t = crupier.carta[0].num_j + crupier.carta[1].num_j;
                                printf("   -->   %i\n", crupier.suma_t);
                                if( crupier.suma_t == 21){
                                    printf("¡El crupier tiene Black Jack!");
                                    crupier.BJ = 1;/*Si obtiene 21 con las dos primeras cartas _Bool BJ (Black Jack), tendrá valor 1, que afirma ese hecho*/
                                }
                                else{
                                    crupier.BJ = 0;/*Sino, recibirá el valor 0.*/
                                }
                                if(crupier.suma_t < 17){
                                    aux = 3;
                                    do{
                                        for(c = 0; c < aux; c++){
                                            if(crupier.carta[c].num_i == 10){
                                            imp_color_rojo_10(crupier.carta[c].num_i, crupier.carta[c].palo);
                                            }
                                            else{
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
                                if(crupier.suma_t > 21){
                                    crupier.Pasar_21 = 1;
                                }
                                else{
                                    crupier.Pasar_21 = 0;
                                }
                                Continuar();

                                //Ahora viene la lista de ganadores, ESTO HAY QUE MEJORARLO LA VERDAD.
                                Datos_j = fopen("Datos_del_jugador.txt", "w");
                                printf("FASE DE RECOMPENSAS:\n");
                                printf("La suma de la mano del crupier es %i\n\n", crupier.suma_t);
                                for(i1 = 0, premio = 0; i1 < num_jug; i1++){
                                    if(participante[i1].apuesta == 0){
                                        printf("%s, no participa en esta ronda.\n\n", participante[i1].nombre);
                                        fprintf(Datos_j, "El nombre del participante %i es: %s\n", i1+1, participante[i1].nombre);
                                        fprintf(Datos_j, "El tiene %i euros.\n", participante[i1].monedero);
                                    }
                                    else{
                                        fprintf(Datos_j, "El nombre del participante %i es: %s\n", i1+1, participante[i1].nombre);
                                        printf("La suma de la mano de %s es %i\n", participante[i1].nombre, participante[i1].suma_t);
                                        printf("Apost%c: %i euros\n", 162, participante[i1].apuesta);
                                        if(participante[i1].Pasar_21 == 1){
                                            printf("En el monedero de %s hay %i euros\n", participante[i1].nombre, participante[i1].monedero);
                                            printf("perdi%c lo apostado\n\n", 162);
                                            fprintf(Datos_j, "El tiene %i euros.\n", participante[i1].monedero);
                                        }
                                        else{
                                            premio = Premio( participante[i1].BJ, crupier.BJ , participante[i1].apuesta, participante[i1].suma_t, crupier.suma_t);
                                            if( premio == 0){
                                                printf("En el monedero de %s hay %i euros\n", participante[i1].nombre, participante[i1].monedero);
                                                printf("perdi%c lo apostado\n\n", 162);
                                                fprintf(Datos_j, "El tiene %i euros.\n", participante[i1].monedero);
                                            }
                                            else{
                                                printf("En el monedero de %s hay %i euros\n", participante[i1].nombre, participante[i1].monedero);
                                                printf("gan%c %i euros\n", 162, premio);
                                                participante[i1].monedero += premio;
                                                printf("Su monedero asciende a %i euros\n\n", participante[i1].monedero);
                                                fprintf(Datos_j, "El tiene %i euros.\n", participante[i1].monedero);
                                            }
                                        }
                                    }
                                }
                                fclose(Datos_j);
                                do{
                                    Continuar();
                                    Menu_Final();
                                    scanf("%i", &Dec_BJ);
                                }while((Dec_BJ != 1)&&(Dec_BJ != 2));
                            }while(Dec_BJ != 2);
                            break;
                        case 2:
                            Datos_j = fopen("Datos_del_jugador.txt", "r");
                            while (fscanf(Datos_j, "%c", &x1) != EOF){
                                printf("%c", x1);
                            }
                            fclose(Datos_j);
                            Continuar();
                            break;
                        case 3:
                            reglas = fopen("Reglas_del_BlackJack.txt", "r");
                            while (fscanf(reglas, "%c", &x2) != EOF){
                                printf("%c", x2);
                            }
                            fclose(reglas);
                            Continuar();
                            break;
                        case 4:
                            j = 1;
                            continue;
                        case 5:
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
                Continuar();
                }
                break;
            case 2:
                for (i = 0, j = 0; i != 1; i = j){
                    Menu_EscapeRoom();
                    printf("Introduzca el n%cmero de la opci%cn que desee:", 163, 162);
                    scanf("%d", &decision_2);
                    Continuar();
                    switch(decision_2){
                        case 1:
                            for(a0 = 0, v0 = 0; a0 != 1; a0 = v0){
                                Borrar();
                                Imprimir_lineas(0, 11);
                                Borrar();
                                scanf("%i", &dec_0);
                                switch(dec_0){
                                    case 1:
                                        v0 = 1;
                                        Borrar();
                                        Imprimir_lineas(12, 15);
                                    case 2:
                                        v0 = 1;
                                        for( a1 = 0, v1 = 0; a1 != 1; a1 = v1){
                                        Imprimir_lineas(16, 28);
                                        scanf("%i",&dec_1);
                                        switch (dec_1){
                                            case 1:
                                                v1=1;
                                                Borrar();
                                                Imprimir_lineas(29, 32);
                                                Game_Over();
                                                break;

                                            case 2:
                                                v1 = 1;
                                                Borrar();
                                                for(a2 = 0, v2 = 0; a2 != 1; a2 = v2){
                                                    Imprimir_lineas(33, 45);
                                                    scanf("%i",&dec_2);
                                                    switch (dec_2){
                                                        case 1:
                                                            v2=1;
                                                            Borrar();
                                                            for(a3a = 0, v3a = 0; a3a != 1; a3a = v3a){
                                                                Imprimir_lineas(46, 52);
                                                                printf("\nPulsa enter para continuar...\n");
                                                                getchar();
                                                                scanf("%i", &dec_3a);
                                                                switch (dec_3a){
                                                                    case 1:
                                                                    v3a=1;
                                                                    Borrar();
                                                                    for(a4a = 0, v4a = 0; a4a != 1; a4a = v4a){
                                                                        Imprimir_lineas(53, 76);
                                                                        scanf("%i", &dec_4a);
                                                                        switch (dec_4a){
                                                                            case 1:
                                                                            v4a=1;
                                                                            Borrar();
                                                                            for(a5a = 0, v5a = 0; a5a != 1; a5a = v5a){
                                                                                Imprimir_lineas(77, 90);
                                                                                scanf("%i", &dec_5a);
                                                                                switch (dec_5a){
                                                                                    case 1:
                                                                                        v5a=1;
                                                                                        Borrar();
                                                                                        Imprimir_lineas(91, 96);
                                                                                        printf("\nPulsa enter para continuar...\n");
                                                                                        getchar();
                                                                                        printf("HAS GANADO\n");
                                                                                        return 0;
                                                                                    case 2:
                                                                                        v5a=1;
                                                                                        Borrar();
                                                                                        Imprimir_lineas(97, 103);
                                                                                        printf("\nPulsa enter para continuar...\n");
                                                                                        getchar();
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
                                                                            Imprimir_lineas(104, 110);
                                                                            printf("\nPulsa enter para continuar...\n");
                                                                            getchar();
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
                                                                    Imprimir_lineas(111, 123);
                                                                    printf("\nPulsa enter para continuar...\n");
                                                                    getchar();
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
                                                            for(a3b = 0, v3b = 0; a3b != 1; a3b = v3b){
                                                                Imprimir_lineas(124, 138);
                                                                printf("\nPulsa enter para continuar...\n");
                                                                getchar();
                                                                scanf("%i", &dec_3b);
                                                                switch(dec_3b){
                                                                    case 1:
                                                                        v3b=1;
                                                                        Borrar();
                                                                        for (a4b = 0, v4b = 0; a4b != 1; a4b = v4b){
                                                                            Imprimir_lineas(139, 155);
                                                                            printf("\nPulsa enter para continuar...\n");
                                                                            getchar();
                                                                            scanf("%i", &dec_4b);
                                                                            switch (dec_4b){
                                                                                case 1:
                                                                                    v4b=1;
                                                                                    Borrar();
                                                                                    Imprimir_lineas(156, 164);
                                                                                    printf("\nPulsa enter para continuar...\n");
                                                                                    getchar();
                                                                                    printf("HAS GANADO\n");
                                                                                    break;

                                                                                case 2:
                                                                                    v4b=1;
                                                                                    Borrar();
                                                                                    Imprimir_lineas(165, 168);
                                                                                    printf("\nPulsa enter para continuar...\n");
                                                                                    getchar();
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
                                                                        Imprimir_lineas(169, 183);
                                                                        printf("\nPulsa enter para continuar...\n");
                                                                        getchar();
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
                                    Continuar();
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
                    Continuar();
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
                Continuar();
                break;

        }
    }while (1);
}

///Funciones Tool
void Bienvenida(){
	printf("%cPREPARADO PARA LA DIVERSI%cN?\n", 168, 224);
	printf("%c%cBIENVENIDO AL SAL%cN DE JUEGOS!!\n\n", 173, 173, 224);
	Continuar();
}
void Continuar(){
	char enter;
	printf("Pulse enter para continuar...\n");
	getchar();
	printf("\033[2J");
}
void Borrar(){
    printf("\033[2J");
}

//Funciones Menú Principal
void Menu_Opciones(){
	printf("\n");
	printf("MEN%c PRINCIPAL:\n", 233);
	printf("1.Jugar al BlackJack\n");
	printf("2.Probar suerte en el EscapeRoom\n");
	printf("3.Salir del programa\n\n");
}
void Menu_BlackJack(){
	printf("\n");
	printf("MEN%c DEL BLACKJACK:\n", 233);
	printf("1.Jugar\n");
    printf("2.Comprobar el dinero\n");
    printf("3.Reglas del BlackJack\n");
	printf("4.Volver al Men%c Principal\n", 163);
	printf("5.Salir del programa\n\n");
}
void Menu_EscapeRoom(){
	printf("\n");
	printf("MEN%c DEL ESCAPEROOM:\n", 233);
	printf("1.Comenzar la partida\n");
	printf("2.Volver al Men%c Principal\n", 163);
	printf("3.Salir del programa\n\n");
}
void Despedida(){
	printf("\n");
	printf("ESPERAMOS QUE HAYAS DISFRUTADO DE LA EXPERIENCIA\n");
	Continuar();
	printf("\n HASTA LA PR%cXIMA.\n", 224);
}

//Funciones de Escape Room
void Game_Over(){
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
void Imprimir_lineas(int l1, int l2){
    FILE *F_EscRoom;
    int p;
    char enter;
    fichero linea[200];
    char cad_car[700];
    if((F_EscRoom = fopen("Escape_Room.txt", "r")) == NULL){
        printf("Se ha producido un error a la hora de abrir el archivo...\n");
    }
    while(fgets(cad_car, 700, F_EscRoom) != NULL){
        strcpy(linea[p].cont, cad_car);
    p++;
    }
    p = 0;
    for(p = l1; p < l2; p++){
      printf("%s", linea[p].cont);
    }
}
//Funciones Tool
void Menu_Final(){
    printf("\n\n%cQuier%cn volver a jugar?\n", 163, 130);
    printf("1. Si\n");
    printf("2. No\n");
}
void imp_color_rojo_10(int num, char palo){
    if((palo == 3)||(palo == 4)){
        printf(ANSI_COLOR_RED);
        printf("%i%c ", num, palo);
        printf(ANSI_COLOR_RESET);
    }
    else{
        printf("%i%c ", num, palo);
        printf(ANSI_COLOR_RESET);
    }
}
void imp_color_rojo_n(char num, char palo){
    if((palo == 3)||(palo == 4)){
        printf(ANSI_COLOR_RED);
        printf("%c%c ", num, palo);
        printf(ANSI_COLOR_RESET);
    }
    else{
        printf("%c%c ", num, palo);
        printf(ANSI_COLOR_RESET);
    }
}
//Funcion de premios
int Premio( _Bool BJ_p, _Bool BJ_c, int apuesta, int suma_p, int suma_c){
    int premio;
    if(BJ_p == 1){
        if(BJ_c == 1)
            return apuesta;
        else{
            premio = apuesta * 2.5;
            return premio;
        }
    }
    else{
        if(BJ_c == 1)
            return 0;
        else{
            if((suma_p > 21)&&(suma_c > 21))
                return 0;
            if((suma_p > 21)&&(suma_c < 22))
                return 0;
            if((suma_p < 22)&&(suma_c > 21)){
                premio = apuesta * 2;
                return premio;
            }
            if((suma_p < 22)&&(suma_c < 22)){
                if(suma_p < suma_c)
                    return 0;
                else if(suma_p > suma_c){
                    premio = apuesta * 2;
                    return premio;
                }
                if(suma_p == suma_c)
                    return apuesta;
            }
        }
    }
}
int suma_cartas(int n_cartas, int cartas[]){
    int suma, i;
    for(i = 0, suma = 0; i < n_cartas; i++){
        suma += cartas[i];
    }
    if(suma <= 21){
        return suma;
    }
    else{
        for(i = 0, suma = 0; i < n_cartas; i++){
            if (cartas[i] == 11){
                cartas[i] = 1;
                suma += cartas[i];
            }
            else{
                suma += cartas[i];
            }
        }
        return suma;
    }
}
