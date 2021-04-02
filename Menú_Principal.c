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
void main()
{
    int decision_1, decision_2;
    Bienvenida();
    system("pause");
    system("cls");
    do
    {
        Menu_Opciones();
        printf("Introduzca el número de la opción que desee:");
        scanf("%d", &decision_1);
        Continuar();
        switch(decision_1)
        {
            case 1:
                Menu_BlackJack();
                printf("Introduzca el número de la opción que desee:");
                scanf("%d", &decision_2);
                Continuar();
                switch(decision_2)
                    {
                    case 1:
                        Menu_BlackJack();
                        printf("Introduzca el número de la opción que desee:");
                        scanf("%d", &decision_2);
                        Continuar();
                        break;
                    case 2:
                        Menu_BlackJack();
                        printf("Introduzca el número de la opción que desee:");
                        scanf("%d", &decision_2);
                        Continuar();
                        break;
                    case 3:
                        Menu_BlackJack();
                        printf("Introduzca el número de la opción que desee:");
                        scanf("%d", &decision_2);
                        Continuar();
                        break;
                    case 4:
                        Menu_Opciones();
                        break;
                    case 5:
                        printf("\nGracias por confiar en nosotros\n");
                        Continuar();
                        Despedida();
                        return 0;
                        break;
                    default:
                        printf("Opcion incorrecta, vuelva a introducir una opcion.\n");
                        Continuar();
                        Menu_BlackJack();
                        break;
                    }
                Continuar();
                break;
            case 2:
                Menu_EscapeRoom();
                printf("Introduzca el número de la opción que desee:");
                scanf("%d", &decision_2);
                switch(decision_2)
                    {
                    case 1:
                        Menu_EscapeRoom();
                        break;
                    case 2:
                        Menu_Opciones();
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
                Continuar();
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
    }while (1>0);
     return 0;
}




///Funciones
void Bienvenida()
{
<<<<<<< Updated upstream
    switch (Elegir)

case 'B':
    case 'b:'
=======
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
    printf("4.Volver al Menú Principal\n");
    printf("5.Salir del programa\n\n");
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
    system("pause");
    system("cls");
    printf("\n Hasta la próxima.\n");
>>>>>>> Stashed changes
}
