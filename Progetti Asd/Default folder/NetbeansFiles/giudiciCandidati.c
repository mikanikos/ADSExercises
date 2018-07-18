/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "giudiciCandidati.h"
#include <stdlib.h>
#include <stdio.h>

void gestioneGiudizi(int N, int K) {
    int i,j;
    GiudCand g[N],c[K];
    printf("Inserisci gli N giudici (nome e cognome) ordinatamente\n");
    for(i=0; i<N; i++) {
        printf("%d giudice\n",i+1);
        g[i].codice=i+1;
        printf("Nome: ");
        scanf("%s",g[i].nome);
        printf("Cognome: ");
        scanf("%s",g[i].cognome);
    }
    printf("Inserisci i K candidati (nome e cognome) ordinatamente\n");
    for(i=0; i<K; i++) {
        printf("%d candidato\n",i+1);
        c[i].codice=i+1;
        printf("Nome: ");
        scanf("%s",c[i].nome);
        printf("Cognome: ");
        scanf("%s",c[i].cognome);
    }
    printf("\n");
    printf("Giudici:\n");
    stampaGiudCand(g,N);
    printf("Candidati:\n");
    stampaGiudCand(c,K);
    int** M;
    M = (int**)calloc(K,sizeof(int*));
    for (i=0; i<K; i++)
        M[i] = (int*)calloc(N,sizeof(int));

    printf("Inserimento dei giudizi dei giudici sui candidati \n");
    for(j=0; j<N; j++)
        for(i=0; i<K; i++) {
            printf("Inserisci il giudizio del %d giudice sul %d candidato: ",j+1,i+1);
            scanf("%d",&M[i][j]);
        }
    printf("\n");
    stampaGiudizi(M,N,K);
    printf("\n");
    smartest(c,M,N,K);
    strictest(g,M,N,K);
}

void stampaGiudizi(int** M, int n, int k) {
    int i,j;
    for(i=0; i<k; i++) {
        for(j=0; j<n; j++)
            printf("%d ",M[i][j]);
        printf("\n");
    }
}

void stampaGiudCand(GiudCand* a, int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d %s %s\n",a[i].codice,a[i].nome,a[i].cognome);
    printf("\n");
}


void smartest(GiudCand* c, int** M, int N, int K) {
    
    int i,j,sum,max=-1,posMax=-1;
    for(i=0; i<K; i++) {
        sum=0;
        for(j=0; j<N; j++)
            sum += M[i][j];
        if(max < sum) {
            max = sum;
            posMax = i;
        }
    }
    printf("Il candidato piu' intelligente e' %s %s \n", c[posMax].nome, c[posMax].cognome);
}

void strictest(GiudCand* g, int** M, int N, int K) {
    int i,j,sum=0,min=5*K+1,posMin=-1;
    for(j=0; j<N; j++) {
        sum = 0;
        for(i=0; i<K; i++)
            sum += M[i][j];
        if(min > sum) {
            min = sum;
            posMin = j;
        }
    }
    printf("Il giudice piu' severo e' %s %s \n", g[posMin].nome, g[posMin].cognome);
}