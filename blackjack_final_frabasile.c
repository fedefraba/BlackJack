#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char nombre1[20], nombre2[20],croupier, opcionmenu, opcion1, opcion2 ;
    int monto1, monto2, apuesta1, apuesta2,sumaapuesta1=0,sumaapuesta2=0,carta,totalcartas1=0,totalcartas2=0,cont1 = 0,cont2 = 0, terminar1 = 0, terminar2 = 0, nojuega1 = 0,nojuega2 = 0, sumacroupier=0;
    const int apuestamin=50;

    printf("Bienvenidos/as, por favor ingesen sus datos:\n");
    printf("Jugador 1 Ingrese su nombre:\n");
    fflush(stdin);
    scanf("%s",nombre1);
    printf("ingrese el monto inicial entre 50 y 1000:\n ");
    fflush(stdin);
    scanf("%d", &monto1);
    while(monto1>1000 || monto1<50){
         printf("Ingrese un monto valido \n");
         fflush(stdin);
         scanf("%d", &monto1);
    }

    printf("Jugador 2 Ingrese su nombre:\n");
    fflush(stdin);
    scanf("%s",nombre2);
    printf("ingrese el monto inicial entre 50 y 1000:\n ");
    fflush(stdin);
    scanf("%d", &monto2);
    while(monto2>1000 || monto2<50){
         printf("Ingrese un monto valido \n");
         fflush(stdin);
         scanf("%d", &monto2);
    }
    do {
        printf("Opciones: (J)ugar, (V)er apuestas, (S)alir:\n");
        fflush(stdin);
        opcionmenu = getchar();
        fflush(stdin);//scanf("%c", opcion);
        switch(opcionmenu){
            case 'J':
                cont1=0;
                cont2=0;
                totalcartas1=0;
                totalcartas2=0;
                sumacroupier=0;
                terminar1=0;
                terminar2=0;
                nojuega1=0;
                nojuega2=0;
                sumaapuesta1=0;
                sumaapuesta2=0;

                if(monto1>=apuestamin && monto2>= apuestamin){
                    //apuestas punto3
                    do{
                        printf("%s, Ingrese su apuesta(min 50, monto disponible: %d): \n", nombre1, monto1);
                        fflush(stdin);
                        scanf("%d", &apuesta1);

                    }while(apuesta1<apuestamin || apuesta1>monto1);
                    monto1=monto1-apuesta1;
                    sumaapuesta1+=apuesta1;

                        do{
                        printf("%s, Ingrese su apuesta(min 50, monto disponible: %d): \n", nombre2, monto2);
                        fflush(stdin);
                        scanf("%d", &apuesta2);
                    }while(apuesta2<apuestamin || apuesta2>monto2);
                    monto2=monto2-apuesta2;
                    sumaapuesta2+=apuesta2;
                    //apuestas listas para jugar
                    srand(time(NULL));
                    carta =rand()%9+1;
                    printf("Carta de %s\n", nombre1);
                    printf(" ___ \n");
                    printf("|   | \n");
                    printf("| %d |\n",carta);
                    printf("|___|\n");
                    totalcartas1+=carta; //primer carta j1
                    printf("apuesta: %d\n",sumaapuesta1);
                    printf("suma total: %d\n\n",totalcartas1);

                    carta =rand()%9+1;
                    printf("Carta de %s\n", nombre2);
                    printf(" ___ \n");
                    printf("|   | \n");
                    printf("| %d |\n",carta);
                    printf("|___|\n");
                    totalcartas2+=carta; //primer carta j2
                    printf("apuesta: %d\n",sumaapuesta2);
                    printf("suma total: %d\n\n",totalcartas2);


                    while (((terminar1 == 0 && nojuega1==0) || (terminar2 == 0 && nojuega2==0))) {
                        if (terminar1 == 0) {
                            carta =rand()%9+1;
                            printf("carta de %s\n", nombre1);
                            printf(" ___ \n");
                            printf("|   | \n");
                            printf("| ? |\n");
                            printf("|___|\n");
                            printf("Apuesta: %d\n",apuesta1);
                            printf("Suma Total: %d\n\n",totalcartas1);
                            printf("(J)ugar o (T)erminar?:");
                            fflush(stdin);
                            opcion1= getchar();
                            fflush(stdin);

                            if (opcion1 == 'T') {
                                terminar1 = 1;
                            }
                            else if (opcion1 == 'J'){
                                carta =rand()%9+1;
                                printf("carta de %s\n", nombre1);
                                printf(" ___ \n");
                                printf("|   | \n");
                                printf("| %d |\n",carta);
                                printf("|___|\n");
                                totalcartas1+=carta;
                                printf("Total de puntos: %d\n",totalcartas1);
                                if(totalcartas1>21){
                                    printf("%s Pierde!\n",nombre1);
                                    nojuega1 = 1;
                                    //
                                    terminar1=1;
                                    //
                                    sumaapuesta1=0;
                                }
                                else if (totalcartas1==21){
                                    printf("%s GANA!\n",nombre1);
                                    nojuega1 = 1;
                                    terminar1 = 1;
                                    monto1+=sumaapuesta1*3;
                                }
                                else {
                                    if(monto1>apuestamin && cont1<2){
                                        printf("En cuanto desea aumentar su apuesta? \n");
                                        do{
                                            printf("Ingrese su apuesta (monto disponible: %d): \n", monto1);
                                            scanf("%d", &apuesta1);
                                        }   while(apuesta1>monto1);
                                        cont1++;
                                        sumaapuesta1+=apuesta1;
                                        monto1-=apuesta1;
                                    }
                                    if (terminar2 == 0){
                                        carta =rand()%9+1;
                                        printf("carta de %s\n", nombre2);
                                        printf(" ___ \n");
                                        printf("|   | \n");
                                        printf("| ? |\n");
                                        printf("|___|\n");
                                        printf("Apuesta: %d\n",apuesta2);
                                        printf("Suma Total: %d\n\n",totalcartas2);
                                        printf("(J)ugar o (T)erminar?:");
                                        fflush(stdin);
                                        opcion2= getchar();
                                        fflush(stdin);

                                        if (opcion2 == 'T') {
                                            terminar2 = 1;
                                        }

                                    // else if (opcion2 == 'J'){
                                    else{
                                            carta =rand()%9+1;
                                            printf("carta de %s\n", nombre2);
                                            printf(" ___ \n");
                                            printf("|   | \n");
                                            printf("| %d |\n",carta);
                                            printf("|___|\n");
                                            totalcartas2+=carta;
                                            printf("Total de puntos: %d\n",totalcartas2);
                                            if(totalcartas2>21){
                                                printf("%s Pierde!\n",nombre2);
                                                nojuega2 = 1;
                                                //
                                                terminar2=1;
                                                //
                                                sumaapuesta2=0;
                                            }
                                            else if (totalcartas2==21){
                                                printf("%s GANA!\n",nombre2);
                                                nojuega2 = 1;
                                                monto2+=sumaapuesta2*3;
                                            }
                                            else {
                                                if(monto2>apuestamin && cont2<2){
                                                    printf("En cuanto desea aumentar su apuesta? \n");

                                                    do{
                                                        printf("Ingrese su apuesta (monto disponible: %d): \n", monto2);
                                                        fflush(stdin);
                                                        scanf("%d", &apuesta2);
                                                    }   while(apuesta2>monto2);
                                                    cont2++;
                                                    sumaapuesta2+=apuesta2;
                                                    monto2-=apuesta2;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        else{
                            if (terminar2 == 0){
                            carta =rand()%9+1;
                            printf("carta de %s\n", nombre2);
                            printf(" ___ \n");
                            printf("|   | \n");
                            printf("| ? |\n");
                            printf("|___|\n");
                            printf("Apuesta: %d\n",apuesta2);
                            printf("Suma Total: %d\n",totalcartas2);
                            printf("(J)ugar o (T)erminar?:");
                            fflush(stdin);
                            opcion2= getchar();
                            fflush(stdin);

                            if(opcion2== 'T'){
                                terminar2=1;
                            }
                            else if (opcion2=='J'){
                                carta =rand()%9+1;
                                printf("carta de %s\n", nombre2);
                                printf(" ___ \n");
                                printf("|   | \n");
                                printf("| %d |\n",carta);
                                printf("|___|\n");
                                totalcartas2+=carta;
                                printf("Total de puntos: %d\n",totalcartas2);

                                if(totalcartas2>21){
                                printf("%s Pierde!\n",nombre2);
                                nojuega2 = 1;
                                //
                                terminar2=1;
                                //
                                sumaapuesta2=0;
                                }
                                else if (totalcartas2==21){
                                    printf("%s GANA!\n",nombre2);
                                    nojuega2 = 1;
                                    monto2+=sumaapuesta2*3;
                                }
                                else {
                                    if(monto2>apuestamin && cont2<2){
                                        printf("En cuanto desea aumentar su apuesta? \n");

                                        do{
                                            printf("Ingrese su apuesta (monto disponible: %d): \n", monto2);
                                            fflush(stdin);
                                            scanf("%d", &apuesta2);
                                        }   while(apuesta2>monto2);
                                        cont2++;
                                        sumaapuesta2+=apuesta2;
                                        monto2-=apuesta2;
                                    }
                                }
                            }
                        }
                    }
                }
                if((totalcartas1<21 && nojuega2==1) || (totalcartas2<21 && nojuega1==1) || (totalcartas1<21 && totalcartas2<21)){

                    //CROUPIER
                    printf("El croupier saca: \n");

                    while(sumacroupier<15){
                        carta =rand()%9+1;
                        printf(" ___ \n");
                        printf("|   | \n");
                        printf("| %d |\n",carta);
                        printf("|___|\n\n");
                        sumacroupier+=carta;
                    }
                    while(sumacroupier<21 && ((sumacroupier<totalcartas1 && nojuega1==0)||(sumacroupier<totalcartas2 && nojuega2==0))){
                        if((nojuega1==0 && totalcartas1>sumacroupier) && (nojuega2==1 ) || (nojuega2==0 && totalcartas2>sumacroupier)&& (nojuega1==1)|| (nojuega1==0 && totalcartas1>sumacroupier && nojuega2==0 && totalcartas2>sumacroupier)){
                            carta =rand()%9+1;
                            printf(" ___ \n");
                            printf("|   | \n");
                            printf("| %d |\n",carta);
                            printf("|___|\n\n");
                            sumacroupier+=carta;
                        }
                        if((nojuega1==0 && totalcartas1>sumacroupier && nojuega2==0 && totalcartas2<sumacroupier)||(nojuega2==0 && totalcartas2>sumacroupier && nojuega1==0 && totalcartas1<sumacroupier)){
                            if((rand()%2+1)==1){
                                carta =rand()%9+1;
                                printf(" ___ \n");
                                printf("|   | \n");
                                printf("| %d |\n",carta);
                                printf("|___|\n\n");
                                sumacroupier+=carta;
                            }
                        }
                    }
                        if(sumacroupier>21){
                            printf("%d\n",sumacroupier);
                            printf("Todos Ganan!\n");
                            if(nojuega1==0){
                            monto1+=2*sumaapuesta1;
                            }
                            if (nojuega2=0){
                            monto2+=2*sumaapuesta2;
                            }
                        }
                        else if ((sumacroupier>=totalcartas1 && sumacroupier<totalcartas2)&& nojuega2==0){
                            printf("%s GANA!",nombre2);
                            monto2+=2*sumaapuesta2;}
                        else if((sumacroupier>=totalcartas2 && sumacroupier<totalcartas1)&& nojuega1==0){
                            printf("%s GANA!",nombre1);
                            monto1+=2*sumaapuesta1;}
                        else{
                            printf("La Casa suma %d\n",sumacroupier);
                            printf("La Casa Siempre Gana\n");
                        }
                    }
                    else if (totalcartas1>21 && totalcartas2>21) {printf("La Casa Siempre Gana\n");}

            }
            else{
                printf("alguno de los jugadores no cuenta con el monto minimo \n");
            }
            break;
            case 'V':
                printf(" %s cuenta con: %d\n", nombre1,monto1);
                printf(" %s cuenta con: %d\n", nombre2,monto2);
                break;
            case 'S':
                printf("Nos vemos, que vuelvan pronto");
                break;
            default:
                printf("Ingrese una opcion valida\n");
        }
    } while(opcionmenu!='S');
    return 0;
}
