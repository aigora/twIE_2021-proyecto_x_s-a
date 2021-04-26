
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char carta[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', '\0'};
    char palo[] = { 3, 4, 5, 6, '\0' };
    int n_c, i;
    char nc, pc;
    srand(time(NULL));
    nc = rand()%12 ;
    pc = rand()%4;

    for(i = 0; i < 2; i++)
    {

        if(carta[nc] == carta[9])
        {
            n_c = 10;
            printf("%d %c \n", n_c, palo[pc]);
        }
        else
        {
            printf("%c %c \n", carta[nc], palo[pc]);
        }
    }
    return 0;
}
