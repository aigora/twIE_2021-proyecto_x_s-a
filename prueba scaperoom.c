#include <stdio.h>
#include <stdlib.h>
int main ()
{
    int x, y;
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
                            printf("DECISIÓN 1: Buscar en la sala de mandos.\n");
                            printf("DECISIÓN 2: Buscar en la sala de navegación principal.\n");
                            printf("Pulse cualquier otro numero para volver a leer.\n");
                            scanf("%i", &decision3);
                            switch (decision3)
                            {
                                case 1:
                                k=1;
                                int l, m;
                    for(l = 0, m = 0; l != 1; l = m)
                    {
                                int decision4;
                                printf("*Te diriges a la sala de mandos. De camino recuerdas que hay un radar que te podría ser útil, puesto que dentro seguro que tiene un chip localizador. Ni bien entras en la sala, el radar es lo primero que buscas. Al no encontrarlo a la vista empiezas a buscar por los cajones hasta que lo encuentras. Ya en tu mano, te dispones a desmontarlo con ayuda de las herramientas, y tras desmontar la pantalla del radar, ahí lo ves, el chip localizador, lo arrancas y lo analizas, por lo que se ve, está en buen estado, así que la guardas en la mochila. De repente mientras veías que más cosas había en la sala, te empieza a dar un fuerte dolor de cabeza, y te sangra la nariz.*\n");
                                Continuar();
                                printf("*Te sientes muy débil; por lo que la mejor opción va a ser descansar un rato para recuperar las fuerzas. Como no hay sillones ni ningún lugar donde hecharte, te sientas en el suelo apoyado contra la pared y te quedas dormido.*\n");
                                Continuar();
                                printf("-Creo que lo mejor será buscar en el sala de mandos, allí hay un pequeño radar que me puede ser útil.\n");
                                Continuar();
                                printf("*Te diriges al puesto de mandos por un pasillo seguro*\n");
                                Continuar();
                                printf("-Bien, ahora solo tengo que arrancar el chip localizador del panel de control.\n");
                            Continuar();
                            printf("*Rompes la pantalla protectora del panel y consigues arrancar el chip sin ningún problema*\n");
                            Continuar();
                            printf("-Cada vez queda menos para que esta pesadilla acabe.\n");
                            Continuar();
                            printf("*Sientes un fuerte dolor en la cabeza y empiezas a sangrar por la nariz*\n");
                            Continuar();
                            printf("-*****, que dolor... Espero que no me cause problemas. Creo que descansaré un rato hasta recuperar fuerzas.\n");
                            Continuar();
                            printf("*Te sientas en una pared del habitáculo y descansas durante unos cuantos minutos hasta que te vuelves a encontrar mejor*\n");
                            Continuar();
                            printf("-Creo que tengo las suficientes fuerzas como para proseguir en mi búsqueda. Lo siguiente era… Una antena. En la sala de comunicaciones tiene que haber algún tipo de antena parabólica.\n");
                            Continuar();
                            printf("*Emprendes tu camino hacia la sala de comunicaciones, pero tienes un dilema, el pasillo es estrecho y hay riesgo de que el traje espacial se quede enganchado*\n");
                            Continuar();
                            printf("DECISIÓN 1: Intentas pasar.\n");
                            printf("DECISIÓN 2: Buscas otro camino por el sistema de ventilación.\n");
                            printf("Pulse cualquier otro numero para volver a leer.\n");
                            scanf("%i", &decision4);
                            switch (decision4)
                            {
                                case 1:
                                    m=1;
                                    int o,p;
                        for(o = 0, p = 0; o != 1; o = p)
                {
                                    int decision5;
                                    printf("-Si no me he muerto hasta el momento creo que podré pasar por esto.\n");
                                    Continuar();
                                    printf("*Te agachas y gateas por el suelo hasta llegar al final del pasillo*\n");
                                    Continuar();
                                    printf("-Buff… Eso ha estado cerca, por un momento creí que no pasaría, era más estrecho de lo que esperaba.\n");
                                    Continuar();
                                    printf("*Miras a tu alrededor y encuentras la antena y el micrófono que también necesitabas*\n");
                                    Continuar();
                                    printf("-Perfecto, ya tengo todo lo que quería, ya puedo salir de este trozo de chatarra.\n");
                                    Continuar();
                                    printf("*Sales de la nave por donde has venido*\n");
                                    Continuar();
                                    printf("-Ahora solo necesito montar el transmisor.\n");
                                    Continuar();
                                    printf("*Empiezas a montar el transmisor y lo construyes sin ningún problema, se nota que estudiaste en la UPM*\n");
                                    Continuar();
                                    printf("-Ahora solo tengo que enviar la señal de mi posición…\n");
                                    Continuar();
                                    printf("*En este momento tienes dudas, no sabes si enviar la señal de rescate o quedarte en el planeta misterioso*\n");
                                    Continuar();
                                    printf("DECISIÓN 1: Enviar la señal de socorro.\n");
                                    printf("DECISIÓN 2: Quedarte a explorar el planeta.\n");
                                    printf("Pulse cualquier otro numero para volver a leer.\n");
                                    scanf("%i", &decision5);
                                    switch (decision5)
                                    {
                                    case 1:
                                    p=1;
                                    printf("*Decides que lo más prudente es enviar la señal de socorro. Al cabo de un rato aparece un vehículo aéreo que te resulta familiar, pero estás confundido, ¿cómo han tardado tan poco en encontrarte? Los integrantes del equipo de rescate te explican la situación, emprendiste un viaje solitario en la nave cuando esta sufrió un fallo mecánico provocando que te estrellases sin salir siquiera del planeta. El golpe te causó pérdida de memoria y no recordabas nada posterior al lanzamiento. Eres llevado al hospital más cercano donde te recuperarás del accidente*\n");
                                    printf("HAS GANADO\n");

                                case 2:
                                    p=1;
                                    printf("*Decides darte una oportunidad en el planeta extraterrestre y quedarte allí. Pasas las siguientes semanas recogiendo frutas, aunque estas te resultan muy familiares. Después de casi un mes realizas contacto con otros humanos, estás contrariado hasta que estos te explican que sigues en la Tierra. Inmediatamente te desmayas y te llevan al hospital más cercano. El accidente con la nave sucedió debido a un fallo mecánico y al estrellarte sufriste perdidas de memoria con las que no podías recordar nada posterior al lanzamiento de la nave. Permanecerás en el hospital hasta tu recuperación total*\n");
                                    printf("HAS GANADO\n");

                                default:
                        printf("Ha decidido repetir.\n");
                        break;
                                    }
                }

                                    break;




                                case 2:
                                    m=1;
                                    printf("-Lo mejor será ir por los conductos de ventilación superior.\n");
                                    Continuar();
                                    printf("*Arrancas la rejilla de ventilación y te metes dentro del conducto gateando*\n");
                                    Continuar();
                                    printf("-Vale, ahora solo tengo que seguir así hasta llegaaaa… \n");
                                    Continuar();
                                    printf("*Pesas demasiado como para que la estructura de ventilación dañada aguante tu peso. El golpe es tan fuerte que te rompes las piernas en la caída y la pequeña conmoción producida por el accidente de la nave se agrava produciendo tu muerte*\n");
                                    Continuar();
                                    printf("GAME OVER\n");
                                    break;

                                 default:
                printf("Ha decidido repetir.\n");
                break;
                            break;
                            }
                        case 2:
                            k=1;
                            printf("*Entras en la sala de navegación principal, con la esperanza de encontrar algo de utilidad. Cuando ya estás llegando te das cuenta de que la sala está al lado del depósito de combustible, y que a medida que te acercas, el suelo está cubierto de una fina capa de combustible. No te parece buena idea seguir, pero la curiosidad de saber si dentro de la sala principal hay algo útil te puede más.\n");
                            Continuar();
                            printf("*Una vez dentro de la sala principal, encuentras un GPS el cual dentro tiene un chip localizador, el GPS está averiado, así que, si lo abres para no afectaras en nada el funcionamiento de la nave, por lo que decides, extraer el chip.*\n");
                            Continuar();
                            printf("*Utilizas las herramientas, pero en el proceso de desarmado, encuentras una tapa, la cual no puedes abrir con las herramientas, así que decides hacer fuerza para romper la tapa. Terminas rompiéndola y se ve un hueco y al fondo  de él, el chip localizador, tratas de usar las herramientas, pero no entran, son muy grandes para caber dentro del hueco, así que, metes tu mano y tiras con todas tus fuerzas del él, hasta que lo extraes, todo parece estar bien hasta que saltan unas chispas, que prenden el combustible bajo tus pies. Ardes por completo*\n");
                            Continuar();
                            printf("GAME OVER\n");
                            break;

                            default:
                printf("Ha decidido repetir.\n");
                break;
                }
                            break;



                    case 2:
                        j=1;
                        int r,e;
                        for(r = 0, e = 0; r != 1; r = e)
                {
                        int decision6;

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
                        printf("DECISIÓN 1: Buscar por la izquierda.\n");
                        printf("DECISIÓN 2: Buscar por la derecha.\n");
                        printf("Pulse cualquier otro numero para volver a leer.\n");
                        scanf("%i", &decision6);
                        switch (decision6)
                        {
                        case 1:
                            e=1;
                            int a, s;
                            for(a = 0, s = 0; a != 1; a = s)
                {
                            int decision7;
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
                            scanf("%i", decision7);
                            switch (decision7)
                            {
                            case 1:
                                s=1;
                                printf("-Me quedaré aquí dentro, es más seguro que salir.\n");
                                printf("*Te tumbas encima de un montón de cajas y duermes hasta el día siguiente*\n");
                                printf("*Te despiertas y escuchas un ruido parecido al de un helicóptero, sales y compruebas que es un vehículo aéreo que acaba de aterrizar. Del interior de la nave sale una criatura. ¡Es un humano! ¿Cómo es posible? Te sientas en el suelo debido a la confusión. Este te explica que pertenece al equipo de rescate de la Agencia Espacial Europea, después del lanzamiento de tu nave esta tuvo un fallo mecánico provocando que se estrellase contra el suelo. Este accidente te ha provocado pérdidas de memoria y no recuerdas nada posterior al lanzamiento. Eres llevado al hospital más cercano para que seas atendido*\n");
                                printf("HAS GANADO\n");
                                break;

                            case 2:
                                s=1;
                                printf("-Necesito salir de esta nave, no me da seguridad, no tanta como salir.\n");
                                printf("*Creas una hoguera y te duermes profundamente, al cabo de un rato parte del combustible procedente del depósito llega hasta ti. El fuego de la hoguera chisporrotea provocando un incendio al caer sobre el combustible. Mueres quemado*\n");
                                printf("GAME OVER\n");
                                break;

                            default:
                        printf("Ha decidido repetir.\n");
                        break; }
                }

                        case 2:
                            e=1;
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
                            printf("GAME OVER\n");
                            break;
                        default:
                        printf("Ha decidido repetir.\n");
                        break;  }
                }

                        break;

                    default:
                        printf("Ha decidido repetir.\n");
                        break;
                        }
                    }
                    }

                break;
            default:
                printf("Ha decidido repetir.\n");
                break;
                }
                    }
                }
        }





void Continuar()
{
	system("Pause");
    system("cls");
}
