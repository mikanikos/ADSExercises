#include <stdio.h>
#include <math.h>
#include "esercizi.h"
#include <string.h>

void gestioneStringhe() {
	stringa s;

	printf("Inserisci la stringa\n");
    scanf("%s",s);

	printf("Carattere più frequente nella stringa: %c", occorrenza(s));
}

char occorrenza(stringa s) {

	int i,j,cont,n=0;
	char a,max;
	for(i=0; i<strlen(s); i++) {
		a = s[i];
		cont = 0;
		for(j=0; j<strlen(s); j++)
			if(s[j] == a)
				cont++;
		if(cont > n) {
			n = cont;
			max = a;
		}
	}

	return max;
}

