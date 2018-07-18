/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "primaEsercitazione.h"

/* funzione per aggiungere un candidato alla lista dei candidati */
void aggiungiC (listaCandidati l, candidato c) {
    listaCandidati temp = l;
    listaCandidati new = (listaCandidati)malloc(sizeof(nodo1));
    new->info = c;
    new->next = NULL;
    if(l == NULL)
        l = new;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = new;
}

/* funzione per aggiungere un votante alla lista dei votanti */
void aggiungiV (listaVotanti l, votante v) {
    listaVotanti temp = l;
    listaVotanti new = (listaVotanti)malloc(sizeof(nodo2));;
    new->info = v;
    new->next = NULL;
    if(l == NULL)
        l = new;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = new;
}

/* lunghezza della lista di votanti */
int lungLV (listaVotanti l) {
    listaVotanti temp = l;
    int lung = 0;
    while(temp != NULL) {
        lung++;
        temp = temp->next;
    }
    return lung;
}

/* COPIA di una stringa */
void copia(string s1, string s2){
    int i=0;
    while (s2[i] != '\0'){
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}


/* conta i voti non validi */
int checkVoti(listaCandidati c, listaVotanti v) {
    int cont = 0;
    listaVotanti temp;
    while(c != NULL) {
        string cod;
        copia(cod,c->info.cod);
        temp = v;
        while(temp != NULL) {
            if(!(confronta(temp->info.cod,cod)))
                cont++;
            temp = temp->next;
        }
        c = c->next;
    }
}

/* confronta se le stringhe sono uguali */
int confronta (string s1, string s2) {
    int cond = 1;
    int i=0;
    if(lung(s1) == lung(s2)) {
        while(s1[i] != '\0' && s2[i] != '\0' && cond==1) {
            if(s1[i] != s2[i])
                cond = 0;
            i++;
        }
    }
    return cond;
}

/* calcola la lunghezza di una stringa */
int lung(string s) {
    int i = 0;
    int lung = 0;
    while(s[i] != '\0') {
        i++;
        lung++;
    }
    return lung;
}

/* funzione che conta i voti di un candidato */
int contaVoti(listaCandidati c, listaVotanti v, string nome, string cognome) {
    string codice;
    int voti = 0;
    while(c!=NULL) {
        if(confronta(c->info.nome,nome) && confronta(c->info.cognome,cognome))
            copia(codice, c->info.cod);
        c = c->next;
    }
    
    while(v!=NULL) {
        if(confronta(v->info.cod,codice))
            voti++;
        v = v->next;
    }
    return voti;
}

/* funzione che elimina dalla lista dei votanti i voti non validi */
void rimuovi (listaCandidati c, listaVotanti v) {
    listaVotanti prev, curr;
    while(c != NULL) {
        string cod;
        copia(cod, c->info.cod);
        prev = v;
        curr = v->next;
        if(!(confronta(prev->info.cod,cod))) {
            v = curr;
            free(prev);
            prev = v;
            curr = v->next;
        }
        while(curr != NULL) {
            if(!(confronta(curr->info.cod,cod))) {
                prev->next = curr->next;
                free(curr);
            }
            prev = prev->next;    
            curr = curr->next;
        }
        c = c->next;
    }
}





