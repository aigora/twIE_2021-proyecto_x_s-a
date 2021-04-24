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
                y = 1;
                int i, j;
                for(i = 0, j = 0; i != 1; i = j)
                {
                    int decision2;
                    printf("*Te acercas a las máquinas rotas, y tienes que cortar el cable, así que buscas en la caja de herramientas y encuentras unos alicates con los que consigues cortarlas. Los cables están buenos, así que te los guardas en la mochila.*\n");
                    Continuar();
                    printf("*De repente, un estruendo te interrumpe, acaba de desprenderse del techo del habitáculo una gran placa metálica, justo encima de donde estaban los cables que se encontraban en el suelo. La inspeccionas, pero es de aluminio y no te sirve para reparar el casco. Con ayuda de las herramientas y unos cuantos tornillos consigues volver a colocar la placa metálica en su sitio.*\n");
                    Continuar();
                    printf("*Como las herramientas fueron útiles, así que, sacas las herramientas de su caja y te las guardas en la mochila. Ahora tienes un: alicate universal, un juego de destornilladores, y una llave inglesa.*\n");
                    Continuar();
                    printf("*Inspeccionado en su totalidad la sala, encuentras galones de combustible en un armario, pero ahora mismo no los necesitas, y como ves que no hay nada más relevante allí. Sales del habitáculo ¿Qué decides hacer ahora?.*\n");
                    printf("DECISIÓN 1: Seguir inspeccionando la nave.\n");
                    printf("DECISIÓN 2: Salir de la nave.\n");
                    printf("Pulse cualquier otro numero para volver a leer.\n");
                    scanf("%i",&decision2);
                    switch (decision2)
                    {
                    case 1:
                        j=1;
                        int u, k;
                for(u = 0, k = 0; u != 1; u = k)
                {
                        int decision3;
                        printf("*Te adentras por los largos pasillos de la nave, teniendo más cuidado de por dónde vas, ahora que sabes que la nave es un campo de minas. Tu objetivo sigue siendo el mismo, así que ahora te dispones a buscar los chips localizadores. No sabes muy bien el dónde estás, en uno de los pasillos encuentras un mapa del interior de la nave y te lo guardas. ¿A qué lugar quieres ir ahora?*\n");
                        Continuar();
                        printf("DECISIÓN 1: Buscar por la izquierda.\n");
                        printf("DECISIÓN 2: Buscar por la derecha.\n");
                        printf("Pulse cualquier otro numero para volver a leer.\n");
                        scanf("%i", &decision3);
                        switch (decision3)
                        {
                        case 1:
                            k=1;
                            printf("-Empezaré por la izquierda, siendo zurdo eso tendría que darme suerte.\n");
                            Continuar();
                            printf("*Comienzas a buscar por la parte izquierda del almacén por algún tipo de razón supersticiosa*\n");
                            Continuar();
                            printf("-Aquí parece haber muchas cajas, espero tener suerte.\n");
                            Continuar();
                            printf("*Estás un buen rato buscando hasta que encuentras la antena parabólica, no es tan grande como esperabas, pero servirá*\n");
                            Continuar();
                            printf("-Una cosa menos, solo faltan dos.\n");
                            Continuar();
                            printf("*Sigues buscando*\n");
                            Continuar();
                            printf("-Parece que aquí no hay nada más.\n");
                            Continuar();
                            printf("*Empiezas a buscar por la derecha*\n");
                            Continuar();
                            printf("*Abres la primera caja y encuentras el micrófono*\n");
                            Continuar();
                            printf("-Parece que he vuelto a tener suerte.\n");
                            Continuar();
                            printf("*Después de un rato buscando encuentras el chip y comienzas a salir del almacén*\n");
                            Continuar();
                            printf("-Ya tengo todo lo que buscaba y lo he conseguido bastante rápido, parece que he tenido suerte.\n");
                            Continuar();
                            printf("*Mientas buscabas se ha hecho de noche*\n");
                            Continuar();
                            break;
                        case 2:
                            k=1;
                            printf("-Empezaré a buscar por la derecha.\n");
                            Continuar();
                            printf("*Comienzas la búsqueda de los materiales por la parte derecha del almacén*\n");
                            Continuar();
                            printf("-Parece que es mi día de suerte, en la primera caja que abro encuentro el micrófono, esto me ahorrará tiempo.\n");
                            Continuar();
                            printf("*Sigues buscando y encuentras el chip*\n");
                            Continuar();
                            printf("-¡Genial! Ahora solo me falta la antena parabólica.\n");
                            Continuar();
                            printf("*Detrás de unas cajas encuentras una gran antena, ya tienes todos los materiales y sigue siendo de día*\n");
                            Continuar();
                            printf("-Perfecto, ya solo me queda montar el radio transmisor.\n");
                            Continuar();
                            printf("*Te diriges al exterior del almacén para montar el transmisor cuando a lo lejos ves una figura acercándose a ti, entras en pánico y disparas con tu arma*\n");
                            Continuar();
                            printf("-No sé qué sería eso, pero creo que me he salvado. Voy a ver que era.\n");
                            Continuar();
                            printf("*Te acercas al cadáver del ser al que acabas de disparar y es un humano. No sabes que hacer, tu cerebro colapsa y caes al suelo. Despiertas dentro de un calabozo. Nunca llegaste a abandonar la Tierra, tu nave se estrelló después de un fallo mecánico y por culpa del golpe no recuerdas nada posterior al lanzamiento. Pasarás el resto de tus días en la cárcel*\n");
                            Continuar();
                            printf("GAME OVER\n");
                            Continuar();
                            break;

                        }
                }


                        break;
                    case 2:
                        j=1;
                        printf("-Será mejor que salga de la nave, no quiero acabar sepultado por este montón de chatarra.\n");
                        Continuar();
                        printf("*Decides salir de la nave con cuidado, crees que es lo más seguro*\n");
                        Continuar();
                        printf("-Bien, creo que será mejor investigar la zona, aunque no se dónde voy a conseguir el resto de los materiales que necesito para montar el transmisor.\n");
                        Continuar();
                        printf("*Te alejas un par de pasos y te sientas en el suelo a pensar qué hacer, recuerdas que la nave tiene un módulo de almacenamiento*\n");
                        Continuar();
                        printf("-¡Claro! ¿Cómo no se me había ocurrido antes? Es mi única fuente de recursos ahora mismo, espero encontrar lo necesario.\n");
                        Continuar();
                        printf("*Comienzas a andar hacia el almacén y encuentras un arma en el suelo, la coges y la enganchas al traje espacial*\n");
                        Continuar();
                        printf("*Sigues andando hasta entrar en el almacén*\n");
                        Continuar();
                        printf("-De acuerdo, ahora tengo que buscar el chip de localización, la antena parabólica y el micrófono.\n");
                        Continuar();
                        break;

                    default:
                        printf("Ha decidido repetir.\n");
                        break;
                    }
                }
                break;
            default:
                printf("Ha decidido repetir.\n");
                break;
        }
    }
}


void Continuar()
{
	system("Pause");
    system("cls");
}
