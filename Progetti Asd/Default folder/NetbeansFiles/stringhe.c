/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <math.h>
#include "esercizi.h"
#include <string.h>

void gestioneStringhe() {
    stringa s;
    printf("Inserisci la stringa\n");
    scanf("%s",s);
    printf("Carattere piu' frequente nella stringa: %c\n", occorrenza(s));
}

char occorrenza(stringa s) {
    int i,j,cont;
    int v[strlen(s)];
    char a,max;
    for(i=0; i<strlen(s); i++) {
        a = s[i];
        cont = 0;
        for(j=0; j<strlen(s); j++)
            if(s[j] == a)
                cont++;
        v[i]=cont;
    }
    max = s[maxArray(v,strlen(s))];
    return max;
}

int maxArray(int a[], int n) {
    int i;
    int posMax = 0;
    int max = a[0];
    for(i=1; i<n; i++)
        if(max < a[i]) {
            max = a[i];
            posMax = i;
        }
    return posMax;
}
