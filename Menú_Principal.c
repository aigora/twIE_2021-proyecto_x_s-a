
#include <stdio.h>
#include <stdlib.h>

///Presentaci�n de las funciones
void Bienvenida();
void Continuar();
void Menu_Opciones();
void Menu_BlackJack();
void Menu_EscapeRoom();
void Despedida();

///Programa
int main()
{
    int decision_1, decision_2;
    Bienvenida();
    system("pause");
    system("cls");
    do
    {
        Menu_Opciones();
        printf("Introduzca el n�mero de la opci�n que desee:");
        scanf("%d", &decision_1);
        system("cls");
        switch(decision_1)
        {
            case 1:
                do
                {
                Menu_BlackJack();
                printf("Introduzca el n�mero de la opci�n que desee:");
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
                        continue;
                    case 5:
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
                }while(1 > 0);
                break;
            case 2:
                do
                {
                Menu_EscapeRoom();
                printf("Introduzca el n�mero de la opci�n que desee:");
                scanf("%d", &decision_2);
                switch(decision_2)
                    {
                    case 1:
                        break;
                    case 2:
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
            }while(1>0);
        }
    }while (1 > 0);
     return 0;
}




///Funciones
void Bienvenida()
{
	printf("�Preparado para la diversion?\n");
	system("Pause");
	system("cls");
	printf("��BIENVENIDO AL SALON DE  JUEGOS!!\n\n");
}

void Continuar()
{
	system("Pause");
    system("cls");
}

void Menu_Opciones()
{
	printf("\n");
	printf("MEN� PRINCIPAL:\n");
	printf("1.Jugar al BlackJack\n");
	printf("2.Probar suerte en el EscapeRoom\n");
	printf("3.Salir del programa\n\n");
}
void Menu_BlackJack()
{
	printf("\n");
	printf("MEN� DEL BLACKJACK:\n");
	printf("1.Jugar\n");
    printf("2.Comprobar el dinero\n");
    printf("3.Ranking\n");
	printf("4.Volver al Men� Principal\n");
	printf("5.Salir del programa\n\n");
}

void Menu_EscapeRoom()
{
	printf("\n");
	printf("MEN� DEL ESCAPEROOM:\n");
	printf("1.Comenzar la partida\n");
	printf("2.Volver al Men� Principal\n");
	printf("3.Salir del programa\n\n");
}

void Despedida()
{
	printf("\n");
	printf("Esperamos haya disfrutado de la experiencia\n");
	system("pause");
	system("cls");
	printf("\n Hasta la pr�xima.\n");
}


