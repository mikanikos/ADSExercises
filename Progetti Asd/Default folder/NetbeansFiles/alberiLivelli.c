/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "esercizi.h"
#include <stdlib.h>


int esiste_foglia(albero T, int v) {
    if(T) {
        if(T->info == v && T->dx == NULL && T->sx==NULL)
            return 1;
        return esiste_foglia(T->sx,v) || esiste_foglia(T->dx,v);
    }
    return 0;
}

int altezzaAlbero(albero T) {
    if(T==NULL) return -1;
    return 1 + maxNumber(altezzaAlbero(T->sx),altezzaAlbero(T->dx));
}

int maxNumber(int a, int b) {
    if(a > b) return a;
    return b;
}

int num_nodi_livello(albero T, int l) {
    if(T){
        if(l==0) return 1;
        return num_nodi_livello(T->dx,l-1) + num_nodi_livello(T->sx,l-1);
    }
    return 0;
}

int esiste_nodo_al_livello(albero T, int v, int l) {
    if(T){
        if(l==0 && T->info == v)
            return 1;
        return esiste_nodo_al_livello(T->sx,v,l-1) || esiste_nodo_al_livello(T->dx,v,l-1);
    }
    return 0;
}

int* costruisci_livello_foglia(albero T, int v) {
    if(esiste_foglia(T,v)) {
        int l = profonditaNodo(T,v);
        int* a = (int*)calloc(num_nodi_livello(T,l),sizeof(int));
        costruisciArray(T,a,l);
        return a;
    }
    return NULL;
}

int profonditaNodo(albero T, int v) {
    int i,depth=-1;
    for(i=0; i<=altezzaAlbero(T); i++) 
        if(esiste_nodo_al_livello(T,v,i))
            depth = i;
    return depth;
}

void costruisciArray(albero T, int* a, int l) {
    static int i = 0;
    if(T) {
        if(l==0) {
            a[i]=T->info;
            i++;
        }
        costruisciArray(T->sx,a,l-1);
        costruisciArray(T->dx,a,l-1);
    }
}

/* crea un array con i nodi comuni ai due alberi per ogni livello */
/*int** livelli_nodo_comune(albero T1, albero T2) {
    int** a = (int**)calloc(altezzaAlbero(T1)+1,sizeof(int*));
    int i;
    for(i=0; i <= altezzaAlbero(T1); i++) {
        int n1 = num_nodi_livello(T1,i);
        int n2 = num_nodi_livello(T2,i);
        int* v1 = (int*)calloc(n1,sizeof(int));
        int* v2 = (int*)calloc(n2,sizeof(int));
        costruisciArray(T1,v1,i);
        costruisciArray(T2,v2,i);
        int* b = array_comuni(v1,v2,n1,n2);
        a[i]=b;
    }
    return a;
}

int* array_comuni(int* v1, int* v2, int n1, int n2) {
    int i,j,cont;
    for(i=0, j=0; i<n1 && j<n2; i++, j++)
        if(v1[i] == v2[j])
            cont++;
    int* b = (int*)calloc(cont,sizeof(int));
    int k = 0;
    for(i=0, j=0; i<n1 && j<n2; i++, j++)
        if(v1[i] == v2[j])
            b[k]++;
    return b;
}*/

int** livelli_nodo_comune(albero T1, albero T2){
    int** A = NULL;
    int h = altezzaAlbero(T1);
    A = calloc(h+1,sizeof(int*));
    int i = 0;
    for (i=0; i<=h; i++)
        A[i] = NULL;
    livelli_nodo_comune_aux(T1, T1, T2, A,0);
    return A;
    
}

void livelli_nodo_comune_aux(albero principale, albero T1, albero T2, int** A, int l){
    if (T1 != NULL){
        if (esiste_nodo_al_livello(T2, T1->info, l)){
            if (A[l] == NULL) {
                int n = num_nodi_livello(principale, l);
                int* B = calloc(n,sizeof(int));
                int i = 0;
                costruisciArray(principale,B,l);
                A[l] = B;
            }
        }
        livelli_nodo_comune_aux(principale, T1->sx, T2, A,l+1);
        livelli_nodo_comune_aux(principale, T1->dx, T2, A,l+1);
    }
}

int livelli_figli_nodo(albero T1, alberoN T2, int x, int h) {
    if(T2==NULL) return 0;
    if(T2->valore == x) {
        alberoN temp = T2->primo_figlio_sx;
        if(temp == NULL) return 0;
        while(temp != NULL) {
            if(!esiste_nodo_al_livello(T1, temp->valore, h))
                return 0;
            temp = temp->fratello_dx;
        }
        return 1;
    }
    else
        return livelli_figli_nodo(T1,T2->primo_figlio_sx,x,h) || livelli_figli_nodo(T1,T2->fratello_dx,x,h);
}




