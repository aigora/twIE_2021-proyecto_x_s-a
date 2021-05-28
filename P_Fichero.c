///Presentación de las librerías
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Estructuras

typedef struct{
    char cont[700];
}fichero;


int main(){

    FILE *F_EscRoom;

    F_EscRoom = fopen("Escape_Room.txt", "r");
    if(F_EscRoom == NULL){
        printf("Se ha producido un error a la hora de abrir el archivo...\n");
        return 1;
    }

    fichero linea[200];

    char cad_car[700];
    int p = 1;
    while(fgets(cad_car, 700, F_EscRoom) != NULL){
        printf("%s", cad_car);
        strcpy(linea[p].cont, cad_car);
        p++;
    }

    fclose(F_EscRoom);
    printf("\nSe la le%cdo el archivo correctamente...\n", 161);
    return 0;

    for(p = 0; p < 200; p++){
        printf("%s", linea[p].cont);
    }
}







