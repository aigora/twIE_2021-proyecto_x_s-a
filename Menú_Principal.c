#include <stdio.h>

int main ()
{
    float d1,d2,d3, d5;
    printf ("Seleccione modo de juego o salir.\n");
    printf ("Para jugar a Blackjack pulse d1, para jugar a Scaperoom pulse d2 y para Salir pulse d3.\n");
    scanf ("%f %f %f %f" , &d1, &d2, &d3, &d5);
    switch (d5)
{
    case 'd1':
    printf("Blackjack.\n");

    case 'd2':
    printf("Scaperoom.\n");

    case 'd3':
    printf("Hasta la próxima.\n");
    break;
}

}
