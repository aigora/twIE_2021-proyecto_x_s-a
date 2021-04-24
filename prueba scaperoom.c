#include <stdio.h>
#include <stdlib.h>
int main ()
{
    int d1, x, y;
    for(x=0, y=0; x!= 1; x=y)
    {
        int decision1;
        printf("*Despiertas tirado en el suelo y oyes a lo lejos una explosión, te encuentras confuso y no sabes dónde estás, lo único que recuerdas es haber estado en la nave con tu equipo, pero ahora a tu alrededor no ves a nadie.*\n");
        Continuar();
        printf("*El traje empieza a emitir ruido, intentas contactar con algún miembro de tu equipo pero pasan varios segundos sin respuesta, y decides ponerte en acción.*\n");
        Continuar();
        printf("*Te levantas y te sacudes la tierra del cuerpo, por lo visto estás ileso, aunque solo te duele el brazo derecho, y tienes un pitido molesto en el oído izquierdo.*\n");
        Continuar();
        printf("*Una vez en pie, ves tu mochila cerca, pero al inspeccionarla te das cuenta de que está vacía, te la pones a la espalda y caminas un poco por tus alrededores y a lo lejos ves la nave a lo lejos ¿Qué vas a hacer?*\n");
        Continuar();
        printf("DECISION 1: Coger cables del suelo.\n");
        printf("DECISION 2: Coger cables de la máquina.\n");
        printf("Pulse cualquier otro numero para volver a leer.\n");
        scanf("%i",&decision1);
        switch (decision1)
        {
            case 1:
                y=1;
                printf("*Decides agacharte a coger los cables del suelo y examinas su estado. Pero al inspeccionarlos te das cuenta de que no te sirven.*\n");
                Continuar();
                printf("*De repente escuchas un chirrido metálico y antes de que puedas reaccionar una gran placa metálica cae sobre ti matándote en el acto.*\n");
                Continuar();
                printf("GAME OVER\n");
                break;

            case 2:
                y=1;
                printf("*Te acercas a las máquinas rotas, y tienes que cortar el cable, así que buscas en la caja de herramientas y encuentras unos alicates con los que consigues cortarlas. Los cables están buenos, así que te los guardas en la mochila.*\n");
                Continuar();
                printf("*De repente, un estruendo te interrumpe, acaba de desprenderse del techo del habitáculo una gran placa metálica, justo encima de donde estaban los cables que se encontraban en el suelo. La inspeccionas, pero es de aluminio y no te sirve para reparar el casco. Con ayuda de las herramientas y unos cuantos tornillos consigues volver a colocar la placa metálica en su sitio.*\n");
                Continuar();
                break;

            default: printf("Ha decidido repetir.\n");
        }
    }
        }


void Continuar()
{
	system("Pause");
    system("cls");
}
