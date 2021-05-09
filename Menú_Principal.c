///Presentación de las librerías

#include <stdio.h>
#include <stdlib.h>

///Presentación de las funciones
void Bienvenida();
void Continuar();
void Menu_Opciones();
void Menu_BlackJack();
void Menu_EscapeRoom();
void Despedida();

///Programa
int main()
{
    FILE *reglas;
    int decision_1, decision_2, i, j, x;
    Bienvenida();
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
                for(i = 0, j = 0; i != 1; i = j)
                {
                    Menu_BlackJack();
                    printf("Introduzca el número de la opción que desee:");
                    scanf("%d", &decision_2);
                    system("cls");
                    switch(decision_2)
                    {
                        case 1:
                            break;
                        case 2:
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
                            printf("Opcion incorrecta, vuelva a introducir una opcion.\n");
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
                            printf("Opcion incorrecta, vuelva a introducir una opcion.\n");
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
                printf("Opcion incorrecta, vuelva a introducir una opcion.\n");
                system ("pause");
                system("cls");
                break;
        }
    }while (1);
return 0;
}

///Funciones
void Bienvenida()
{
	printf("¿Preparado para la diversion?\n");
	system("Pause");
	system("cls");
	printf("¡¡BIENVENIDO AL SALON DE  JUEGOS!!\n\n");
}

void Continuar()
{
	system("Pause");
    system("cls");
}

void Menu_Opciones()
{
	printf("\n");
	printf("MENÚ PRINCIPAL:\n");
	printf("1.Jugar al BlackJack\n");
	printf("2.Probar suerte en el EscapeRoom\n");
	printf("3.Salir del programa\n\n");
}
void Menu_BlackJack()
{
	printf("\n");
	printf("MENÚ DEL BLACKJACK:\n");
	printf("1.Jugar\n");
    printf("2.Comprobar el dinero\n");
    printf("3.Ranking\n");
    printf("4.Reglas del BlackJack\n");
	printf("5.Volver al Menú Principal\n");
	printf("6.Salir del programa\n\n");
}

void Menu_EscapeRoom()
{
	printf("\n");
	printf("MENÚ DEL ESCAPEROOM:\n");
	printf("1.Comenzar la partida\n");
	printf("2.Volver al Menú Principal\n");
	printf("3.Salir del programa\n\n");
}

void Despedida()
{
	printf("\n");
	printf("Esperamos haya disfrutado de la experiencia\n");
	Continuar();
	printf("\n Hasta la próxima.\n");
}
