/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "esercizi.h"

/* esercizio 1 */
int isPerfect(int *v) {
    int i,j,cont,a;
    int perfect = 1;
    for(i=0; i<27 && perfect == 1; i++) {
        a = v[i];
        if (a < 1 || a > 9)
            perfect = 0;
        cont = 0;
        for(j=0; j<27; j++)
            if(v[j] == a)
                cont++;
        if(cont != 3)
            perfect = 0;   
    }
    return perfect;
}

/* esercizio 2 */
int listaAbbr(plist l, char abbr[2], char *estesa) {
    plist temp=l;
    int inter = 0;
    while(temp != NULL && inter == 0) {
        if(temp->abbr[0] == abbr[0] &&  temp->abbr[1] == abbr[1] && strcmp(temp->estesa,estesa)==0)
            return 0;
        if(temp->abbr[0] == abbr[0] &&  temp->abbr[1] == abbr[1] && strcmp(temp->estesa,estesa)!=0) {
            strcpy(temp->estesa,estesa);
            return 2;
        }
        if(temp->next == NULL)
            inter = 1;
        else
            temp = temp->next;
    }
    plist new = (plist)malloc(sizeof(struct elem));
    new->abbr[0] = abbr[0];
    new->abbr[1] = abbr[1];
    strcpy(new->estesa,estesa);
    new->next = NULL;
    if(l == NULL) l = new;
    else temp->next = new;
    return 1;    
}

/* esercizio 3 */
int maxVectList(struct nodo **v, int n){
    int i,max=0,posMax=0;
    int a[n];
    struct nodo *temp;
    for(i=0; i<n; i++) {
        temp = v[i];
        while(temp != NULL) {
            if(max < temp->valore) {
                max = temp->valore;
                posMax = i;
            }
            temp = temp->next;
        }
    }
    return posMax;
}

/* esercizio 4 */
struct element3* gestisciStudenti(int n) {
    struct element3 *p;
    char app[21];
    int i;
    p = (struct element3*)calloc(n,sizeof(struct element3));
    if (p == NULL) return NULL;
    for (i = 0; i < n; ++i) {
        printf("%d: Inserisci nome: ",i);
        scanf("%s", app);
        printf("%d: Inserisci eta': ",i);
        scanf("%d", &(p[i].eta));
        p[i].nome = (char *)malloc(strlen(app)+1);
        if (p[i].nome == NULL) return NULL;
        strcpy(p[i].nome, app);
    } 
    return p;
}

/* esercizio 5 */
char* ultimaPalindroma(char* v[]) {
    int ind=-1,i=0;
    char *pal;
    while(strcmp(v[i],"")!=0) {
        if(palindroma(v[i])==1)
            ind = i;
        i++;
    }
    if(ind == -1)
        return NULL;
    pal = (char*)malloc(strlen(v[ind]));
    strcpy(pal,v[ind]);      
    return pal;
}

int palindroma(char* s) {
    int len = strlen(s);
    int i=0,j=len-1;
    int isPal = 1;
    for(i=0,j=len-1; i < j && isPal == 1; i++,j--) {
        while(s[i] == ' ')
            i++;
        while(s[j] == ' ')
            j--;
        if(s[i] != s[j])
            isPal = 0;
    }
    return isPal;
}

/* esercizio 6 */
struct elem4** puntaLista(struct elem4* l) {
    int i,len = length(l);
    struct elem4** v;
    if(len != 0) {
        v = (struct elem4**)calloc(len,sizeof(struct elem4*));
        for(i=0; i<len; i++) {
            v[i]=l;
            l = l->next;
        }
        return v;
    }
    return NULL;
}

int length(struct elem4* l) {
    int i=0;
    while(l!= NULL){
        i++;
        l = l->next;
    }
    return i;
}

/* esercizio 7 */
char* eliminaChar(char* s, char c) {
    int length = strlen(s);
    if(length != 0) {
        char* new = (char*)calloc(length+1,sizeof(char));
        int i,j=0;
        for(i=0; i <= strlen(s); i++) {
            if(s[i] != c) {
                new[j]=s[i];
                j++;
            }   
        }
        return new;
    }
    return NULL;
}

/* esercizio 8 */
void modificaVect(char** v, int n) {
    int i,j;
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
            if(v[j][0] == v[i][strlen(v[i])-2] && v[j][1] == v[i][strlen(v[i])-1]) {
                v[i] = (char *)realloc(v[i],strlen(v[i])+strlen(v[j])-2+1);
                strcat(v[i],v[j]+2);
                break;
            }
}

/* esercizio 9 */
char* newStringa(char* s1, char* s2) {
    int i,j,k;
    int num_spazi = 0;
    for (k = 0; s1[k] != '\0'; k++)
        if (s1[k] == ' ')
            num_spazi++;
    char* new = (char*)calloc(strlen(s1)-num_spazi+strlen(s2)+5,sizeof(char));
    for (k = 0; s1[k] != ' '; k++)
        new[k] = s1[k];
    j = k;
    new[j++]= ' ';
    new[j++]='(';
    for (i = 0; s2[i] != '\0'; i++, j++)
        new[j] = s2[i];
    new[j++]=')';
    new[j++]=' ';
    while(s1[k] == ' ')
        k++;
    while(s1[k] != '\0') {
        new[j]=s1[k];
        k++;
        j++;
    }
    new[j]='\0';
    return new;
}

/* esercizio 10 */
void modifica(struct nodo *l){
    int prec, copia;
    prec = l->valore;
    do {
        l = l->next;
        copia = l->valore;
        l->valore = l->valore * prec;
        prec = copia;
    }
    while (l->next);
}

/* esercizio 11 */
char* sommaStringhe(char* s1, char* s2) {
    char* ris;
    int n = strlen(s1);
    int i, carry = 0, somma;
    ris = (char*) calloc(n + 1,sizeof(char));
    ris[n] = '\0';
    for (i = n-1; i >= 0; i--) {
        somma = (s1[i] - '0') + (s2[i] - '0') + carry;
        carry = somma / 10;
        ris[i] = somma % 10 + '0';
    }
    return ris;
}