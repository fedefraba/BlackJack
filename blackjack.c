/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>


int main()
{
    
    char nombre1[20], nombre2[20], opcion ;
    int monto1, monto2, apuesta1, apuesta2;
    
    printf("Bienvenidos/as, por favor ingesen sus datos:\n");
    printf("Ingrese su nombre:\n");
    scanf("%s",nombre1);
    printf("ingrese el monto inicial entre 50 y 1000:\n ");
    scanf("%d", &monto1);
    while(monto1>1000 || monto1<50){
         printf("Ingrese un monto valido \n");
         scanf("%d", &monto1);}
     
     
     printf("Ingrese su nombre:\n");
    scanf("%s",nombre2);
    printf("ingrese el monto inicial entre 50 y 1000:\n ");
    scanf("%d", &monto2);
    while(monto2>1000 || monto2<50){
         printf("Ingrese un monto valido \n");
         scanf("%d", &monto2);
     }
    
    printf( "%s" " : "  "%d \n" , nombre1,monto1 );
    printf( "%s" " : "  "%d \n" , nombre2,monto2 );

    do {
        printf("Opciones: (J)ugar, (V)er apuestas, (S)alir:");
        
        scanf("%c", opcion);
      
        switch(opcion){
            case 'J':
                printf(" monola\n");
                break;
            case 'V':
                printf(" hila\n");
                break;
            case 'S':
                printf("gracias por jugar");
                break;
            default:
                printf("Ingrese una opcion valida");
             }
        } while(opcion!='S');
    
    
    return 0;
}
