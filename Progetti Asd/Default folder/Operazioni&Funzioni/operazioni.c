/* implementazione di operazioni basilari */
#include <stdio.h>
#include <stdint.h>

/* somma */
void sum() {

	int a,b;
	printf("Inserisci due numeri: ");
	scanf("%d %d",&a,&b);
	printf("La somma è: %d\n",a+b);
}

/* quadrato */
void quadrato() {

    int n;
    printf("Inserisci il valore di N: ");
    scanf ("%d",&n);
    printf("N al quadrato e' uguale a %d\n", n*n);
}
