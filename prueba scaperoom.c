#include <stdio.h>
#include <stdlib.h>

void Continuar();
void Game_Over();
void Borrar();

int main()
{
    int dec_0,  dec_1,  dec_2,  dec_3a,   dec_4a,   dec_5a,   dec_3b,   dec_4b;
    int a0, v0, a1, v1, a2, v2, a3a, v3a, a4a, v4a, a5a, v5a, a3b, v3b, a4b, v4b;
    for(a0 = 0, v0 = 0; a0 != 1; a0 = v0)
    {
        Borrar();
        printf("*Despiertas tirado en el suelo y oyes a lo lejos una explosi%cn, te encuentras confuso y no sabes d%cnde est%cs,\n", 162, 162, 160);
        printf(" lo %cnico que recuerdas es haber estado en la nave con tu equipo, pero ahora a tu alrededor no ves a nadie.*\n", 163);
        printf("*El traje empieza a emitir ruidos, intentas contactar con alg%cn miembro de tu equipo, pero pasan varios segundos\n", 163);
        printf(" sin respuesta y decides ponerte en acci%cn.*\n", 162);
        printf("*Te levantas y te sacudes la tierra del cuerpo, por lo visto estas ileso, aunque solo te duele el brazo derecho\n");
        printf(" y tienes un pitido molesto en el o%cdo izquierdo.*\n", 161);
        printf("*Una vez en pie, ves tu mochila cerca, pero al inspeccionarla te das cuenta de que esta vac%ca, te la pones a la \n", 161);
        printf(" espalda y caminas un poco por tus alrededores, de pronto, ves a lo lejos la nave %cQu%c vas a hacer?* \n", 168, 130);
        printf("DECISI%cN 1: Ir a mirar el estado de la nave.\n", 162);
        printf("DECISI%cN 2: Contemplar el paisaje.\n", 162);
        printf("Pulse cualquier otro n%cmero para volver a leer.\n", 163);
        scanf("%i", &dec_0);
        switch(dec_0)
        {
            case 1:
                v0 = 1;
                for( a1 = 0, v1 = 0; a1 != 1; a1 = v1)
                {
                    Borrar();
                    printf("*Te diriges a la nave, y por fuera ves que la cosa pinta mal. Se ha roto el dep%csito de combustible, y hay algunos \n", 162);
                    printf(" huecos en el casco de titanio, por lo que debes hallar los materiales necesarios para repararla si quieres poder\n");
                    printf(" despegarla, placas met%clicas de titanio. Pero tienes claro de que va a ser una tarea muy dura.*\n", 160);
                    printf("*Una vez analizada la situaci%cn por fuera, te dispones a ver que componentes siguen siendo %ctiles dentro de la nave,\n", 162, 163);
                    printf(" al parecer todo esta bien, pero te das cuenta de que el radio transmisor est%c estropeado, por lo que tendr%cs que\n", 160, 160);
                    printf(" repararlo si quieres pedir ayuda.(Para repararlo debes encontrar cables, chips localizadores, una antena y un altavoz).*\n", 160);
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
                            Game_Over();
                            break;

                        case 2:
                            v1 = 1;
                            Borrar();
                            for(a2 = 0, v2 = 0; a2 != 1; a2 = v2)
                            {
                                printf("*Te acercas a las maquinas rotas, y tienes que cortar el cable, asi que buscas en la caja de herramientas y encuentras\n");
                                printf(" unos alicates con los que consigues cortarlas. Los cables estan buenos, asi que te los guardas en la mochila.*\n");
                                printf("*De repente, un estruendo te interrumpe, acaba de desprenderse del techo del habitaculo una gran placa metalica,\n");
                                printf(" justo encima de donde estaban los cables que se encontraban en el suelo. La inspeccionas, pero es de aluminio y no\n");
                                printf(" te sirve para reparar el casco. Con ayuda de las herramientas y unos cuantos tornillos consigues volver a colocar\n");
                                printf(" la placa metalica en su sitio.*\n");
                                printf("*Como las herramientas fueron utiles, asi que, sacas las herramientas de su caja y te las guardas en la mochila.\n");
                                printf(" Ahora tienes un: alicate universal, un juego de destornilladores, y una llave inglesa.*\n");
                                printf("*Inspeccionado en su totalidad la sala, encuentras galones de combustible en un armario, pero ahora mismo no los \n");
                                printf(" necesitas, y como ves que no hay nada mas relevante alli. Sales del habitaculo ¿Que decides hacer ahora?.*\n");
                                printf("DECISIÓN 1: Seguir inspeccionando la nave.\n");
                                printf("DECISIÓN 2: Salir de la nave.\n");
                                printf("Pulse cualquier otro numero para volver a leer.\n");
                                scanf("%i",&dec_2);
                                switch (dec_2)
                                {
                                    case 1:
                                        v2=1;
                                        Borrar();
                                        for(a3a = 0, v3a = 0; a3a != 1; a3a = v3a)
                                        {
                                            printf("*Te adentras por los largos pasillos de la nave, teniendo mas cuidado de por donde vas, ahora que sabes que la \n");
                                            printf(" nave es un campo de minas. Tu objetivo sigue siendo el mismo, asi que ahora te dispones a buscar los chips\n");
                                            printf(" localizadores. No sabes muy bien el donde estas, en uno de los pasillos encuentras un mapa del interior de la\n");
                                            printf(" nave y te lo guardas. ¿A que lugar quieres ir ahora?*\n");
                                            printf("DECISION 1: Buscar en la sala de mandos.\n");
                                            printf("DECISION 2: Buscar en la sala de navegacion principal.\n");
                                            printf("Pulse cualquier otro numero para volver a leer.\n");
                                            scanf("%i", &dec_3a);
                                            switch (dec_3a)
                                            {
                                                case 1:
                                                    v3a=1;
                                                    Borrar();
                                                    for(a4a = 0, v4a = 0; a4a != 1; a4a = v4a)
                                                    {
                                                        printf("*Te diriges a la sala de mandos. De camino recuerdas que hay un radar que te podria ser util, puesto que dentro\n");
                                                        printf(" seguro que tiene un chip localizador. Ni bien entras en la sala, el radar es lo primero que buscas. Al no\n");
                                                        printf(" encontrarlo a la vista empiezas a buscar por los cajones hasta que lo encuentras. Ya en tu mano, te dispones\n");
                                                        printf(" a desmontarlo con ayuda de las herramientas, y tras desmontar la pantalla del radar, ahi lo ves, el chip localizador,\n");
                                                        printf(" lo arrancas y lo analizas, por lo que se ve, esta en buen estado, asi que la guardas en la mochila. De repente\n");
                                                        printf(" mientras veias que mas cosas habia en la sala, te empieza a dar un fuerte dolor de cabeza, y te sangra la nariz.\n");
                                                        printf("*Te sientes muy debil; por lo que la mejor opcion va a ser descansar un rato para recuperar las fuerzas. Como no hay \n");
                                                        printf(" sillones ni ningún lugar donde hecharte, te sientas en el suelo apoyado contra la pared y te quedas dormido.*\n");
                                                        printf("-Creo que lo mejor sera buscar en el sala de mandos, alli hay un pequeño radar que me puede ser util.\n");
                                                        printf("*Te diriges al puesto de mandos por un pasillo seguro*\n");
                                                        printf("-Bien, ahora solo tengo que arrancar el chip localizador del panel de control.\n");
                                                        printf("*Rompes la pantalla protectora del panel y consigues arrancar el chip sin ningun problema*\n");
                                                        printf("-Cada vez queda menos para que esta pesadilla acabe.\n");
                                                        printf("*Sientes un fuerte dolor en la cabeza y empiezas a sangrar por la nariz*\n");
                                                        printf("-*****, que dolor... Espero que no me cause problemas. Creo que descansare un rato hasta recuperar fuerzas.\n");
                                                        printf("*Te sientas en una pared del habitaculo y descansas durante unos cuantos minutos hasta que te vuelves a encontrar mejor*\n");
                                                        printf("-Creo que tengo las suficientes fuerzas como para proseguir en mi busqueda. Lo siguiente era… Una antena. En la sala de\n");
                                                        printf(" comunicaciones tiene que haber algún tipo de antena parabolica.");
                                                        printf("*Emprendes tu camino hacia la sala de comunicaciones, pero tienes un dilema, el pasillo es estrecho y hay riesgo de que \n");
                                                        printf(" el traje espacial se quede enganchado*");
                                                        printf("DECISIÓN 1: Intentas pasar.\n");
                                                        printf("DECISIÓN 2: Buscas otro camino por el sistema de ventilación.\n");
                                                        printf("Pulse cualquier otro numero para volver a leer.\n");
                                                        scanf("%i", &dec_4a);
                                                        switch (dec_4a)
                                                        {
                                                            case 1:
                                                                v4a=1;
                                                                Borrar();
                                                                for(a5a = 0, v5a = 0; a5a != 1; a5a = v5a)
                                                                {
                                                                    printf("-Si no me he muerto hasta el momento creo que podré pasar por esto.\n");
                                                                    printf("*Te agachas y gateas por el suelo hasta llegar al final del pasillo*\n");
                                                                    printf("-Buff… Eso ha estado cerca, por un momento creí que no pasaría, era más estrecho de lo que esperaba.\n");
                                                                    printf("*Miras a tu alrededor y encuentras la antena y el micrófono que también necesitabas*\n");
                                                                    printf("-Perfecto, ya tengo todo lo que quería, ya puedo salir de este trozo de chatarra.\n");
                                                                    printf("*Sales de la nave por donde has venido*\n");
                                                                    printf("-Ahora solo necesito montar el transmisor.\n");
                                                                    printf("*Empiezas a montar el transmisor y lo construyes sin ningún problema, se nota que estudiaste en la UPM*\n");
                                                                    printf("-Ahora solo tengo que enviar la señal de mi posición…\n");
                                                                    printf("*En este momento tienes dudas, no sabes si enviar la señal de rescate o quedarte en el planeta misterioso*\n");
                                                                    printf("DECISIÓN 1: Enviar la señal de socorro.\n");
                                                                    printf("DECISIÓN 2: Quedarte a explorar el planeta.\n");
                                                                    printf("Pulse cualquier otro numero para volver a leer.\n");
                                                                    scanf("%i", &dec_5a);
                                                                    switch (dec_5a)
                                                                    {
                                                                        case 1:
                                                                            v5a=1;
                                                                            Borrar();
                                                                            printf("*Decides que lo más prudente es enviar la señal de socorro. Al cabo de un rato aparece un vehículo aéreo que te resulta familiar, pero estás confundido, ¿cómo han tardado tan poco en encontrarte? Los integrantes del equipo de rescate te explican la situación, emprendiste un viaje solitario en la nave cuando esta sufrió un fallo mecánico provocando que te estrellases sin salir siquiera del planeta. El golpe te causó pérdida de memoria y no recordabas nada posterior al lanzamiento. Eres llevado al hospital más cercano donde te recuperarás del accidente*\n");
                                                                            printf("HAS GANADO\n");
                                                                            return 0;

                                                                        case 2:
                                                                            v5a=1;
                                                                            Borrar();
                                                                            printf("*Decides darte una oportunidad en el planeta extraterrestre y quedarte allí. Pasas las siguientes semanas recogiendo frutas, aunque estas te resultan muy familiares. Después de casi un mes realizas contacto con otros humanos, estás contrariado hasta que estos te explican que sigues en la Tierra. Inmediatamente te desmayas y te llevan al hospital más cercano. El accidente con la nave sucedió debido a un fallo mecánico y al estrellarte sufriste perdidas de memoria con las que no podías recordar nada posterior al lanzamiento de la nave. Permanecerás en el hospital hasta tu recuperación total*\n");
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
                                                                printf("-Lo mejor será ir por los conductos de ventilación superior.\n");
                                                                printf("*Arrancas la rejilla de ventilación y te metes dentro del conducto gateando*\n");
                                                                printf("-Vale, ahora solo tengo que seguir así hasta llegaaaa… \n");
                                                                printf("*Pesas demasiado como para que la estructura de ventilación dañada aguante tu peso. El golpe es tan fuerte que te rompes las piernas en la caída y la pequeña conmoción producida por el accidente de la nave se agrava produciendo tu muerte*\n");
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
                                                    printf("*Entras en la sala de navegación principal, con la esperanza de encontrar algo de utilidad. Cuando ya estás llegando te das cuenta de que la sala está al lado del depósito de combustible, y que a medida que te acercas, el suelo está cubierto de una fina capa de combustible. No te parece buena idea seguir, pero la curiosidad de saber si dentro de la sala principal hay algo útil te puede más.\n");
                                                    printf("*Una vez dentro de la sala principal, encuentras un GPS el cual dentro tiene un chip localizador, el GPS está averiado, así que, si lo abres para no afectaras en nada el funcionamiento de la nave, por lo que decides, extraer el chip.*\n");
                                                    printf("*Utilizas las herramientas, pero en el proceso de desarmado, encuentras una tapa, la cual no puedes abrir con las herramientas, así que decides hacer fuerza para romper la tapa. Terminas rompiéndola y se ve un hueco y al fondo  de él, el chip localizador, tratas de usar las herramientas, pero no entran, son muy grandes para caber dentro del hueco, así que, metes tu mano y tiras con todas tus fuerzas del él, hasta que lo extraes, todo parece estar bien hasta que saltan unas chispas, que prenden el combustible bajo tus pies. Ardes por completo*\n");
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
                                            printf("-Será mejor que salga de la nave, no quiero acabar sepultado por este montón de chatarra.\n");
                                            printf("*Decides salir de la nave con cuidado, crees que es lo más seguro*\n");
                                            printf("-Bien, creo que será mejor investigar la zona, aunque no se dónde voy a conseguir el resto de los materiales que necesito para montar el transmisor.\n");
                                            printf("*Te alejas un par de pasos y te sientas en el suelo a pensar qué hacer, recuerdas que la nave tiene un módulo de almacenamiento*\n");
                                            printf("-¡Claro! ¿Cómo no se me había ocurrido antes? Es mi única fuente de recursos ahora mismo, espero encontrar lo necesario.\n");
                                            printf("*Comienzas a andar hacia el almacén y encuentras un arma en el suelo, la coges y la enganchas al traje espacial*\n");
                                            printf("*Sigues andando hasta entrar en el almacén*\n");
                                            printf("-De acuerdo, ahora tengo que buscar el chip de localización, la antena parabólica y el micrófono.\n");
                                            printf("DECISIÓN 1: Buscar por la izquierda.\n");
                                            printf("DECISIÓN 2: Buscar por la derecha.\n");
                                            printf("Pulse cualquier otro numero para volver a leer.\n");
                                            scanf("%i", &dec_3b);
                                            switch(dec_3b)
                                            {
                                                case 1:
                                                    v3b=1;
                                                    Borrar();
                                                    for (a4b = 0, v4b = 0; a4b != 1; a4b = v4b)
                                                    {
                                                        printf("-Empezaré por la izquierda, siendo zurdo eso tendría que darme suerte.\n");
                                                        printf("*Comienzas a buscar por la parte izquierda del almacén por algún tipo de razón supersticiosa*\n");
                                                        printf("-Aquí parece haber muchas cajas, espero tener suerte.\n");
                                                        printf(" *Estás un buen rato buscando hasta que encuentras la antena parabólica, no es tan grande como esperabas, pero servirá*\n");
                                                        printf("-Una cosa menos, solo faltan dos.\n");
                                                        printf("*Sigues buscando*\n");
                                                        printf("-Parece que aquí no hay nada más.\n");
                                                        printf("*Empiezas a buscar por la derecha*\n");
                                                        printf("*Abres la primera caja y encuentras el micrófono*\n");
                                                        printf("-Parece que he vuelto a tener suerte.\n");
                                                        printf("*Después de un rato buscando encuentras el chip y comienzas a salir del almacén*\n");
                                                        printf("-Ya tengo todo lo que buscaba y lo he conseguido bastante rápido, parece que he tenido suerte.\n");
                                                        printf("*Mientas buscabas se ha hecho de noche*\n");
                                                        printf("DECISIÓN 1: Quedarte dentro de la nave.\n");
                                                        printf("DECISIÓN 2: Salir de la nave y crear una hoguera.\n");
                                                        printf("Pulse cualquier otro numero para volver a leer.\n");
                                                        scanf("%i", &dec_4b);
                                                        switch (dec_4b)
                                                        {
                                                            case 1:
                                                                v4b=1;
                                                                Borrar();
                                                                printf("-Me quedaré aquí dentro, es más seguro que salir.\n");
                                                                printf("*Te tumbas encima de un montón de cajas y duermes hasta el día siguiente*\n");
                                                                printf("*Te despiertas y escuchas un ruido parecido al de un helicóptero, sales y compruebas que es un vehículo aéreo que acaba de aterrizar. Del interior de la nave sale una criatura. ¡Es un humano! ¿Cómo es posible? Te sientas en el suelo debido a la confusión. Este te explica que pertenece al equipo de rescate de la Agencia Espacial Europea, después del lanzamiento de tu nave esta tuvo un fallo mecánico provocando que se estrellase contra el suelo. Este accidente te ha provocado pérdidas de memoria y no recuerdas nada posterior al lanzamiento. Eres llevado al hospital más cercano para que seas atendido*\n");
                                                                printf("HAS GANADO\n");
                                                                break;

                                                                case 2:
                                                                v4b=1;
                                                                Borrar();
                                                                printf("-Necesito salir de esta nave, no me da seguridad, no tanta como salir.\n");
                                                                printf("*Creas una hoguera y te duermes profundamente, al cabo de un rato parte del combustible procedente del depósito llega hasta ti. El fuego de la hoguera chisporrotea provocando un incendio al caer sobre el combustible. Mueres quemado*\n");
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
                                                    printf("Empezaré a buscar por la derecha.\n");
                                                    printf("*Comienzas la búsqueda de los materiales por la parte derecha del almacén*\n");
                                                    printf("-Parece que es mi día de suerte, en la primera caja que abro encuentro el micrófono, esto me ahorrará tiempo.\n");
                                                    printf("*Sigues buscando y encuentras el chip*\n");
                                                    printf("-¡Genial! Ahora solo me falta la antena parabólica.\n");
                                                    printf("*Detrás de unas cajas encuentras una gran antena, ya tienes todos los materiales y sigue siendo de día*\n");
                                                    printf("-Perfecto, ya solo me queda montar el radio transmisor.\n");
                                                    printf("*Te diriges al exterior del almacén para montar el transmisor cuando a lo lejos ves una figura acercándose a ti, entras en pánico y disparas con tu arma*\n");
                                                    printf("-No sé qué sería eso, pero creo que me he salvado. Voy a ver que era.\n");
                                                    printf("*Te acercas al cadáver del ser al que acabas de disparar y es un humano. No sabes que hacer, tu cerebro colapsa y caes al suelo. Despiertas dentro de un calabozo. Nunca llegaste a abandonar la Tierra, tu nave se estrelló después de un fallo mecánico y por culpa del golpe no recuerdas nada posterior al lanzamiento. Pasarás el resto de tus días en la cárcel*\n");
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
            case 2:
                v0 = 1;
                Borrar();
                printf("COMING SOON...");
                break;
            default:
                system ("cls");
                printf("Ha decidido repetir.\n");
                break;
        }
    }

}

void Continuar()
{
	system("pause");
    system("cls");
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

