/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "esercizi.h"

int verificaPercorso(stradario ST, street s1, street s2) {
    return esistenzaPercorso(ST,s1,s2,0);
}

int esistenzaPercorso(stradario ST, street s1, street s2, int trovato) {
    if(ST){
        if(trovato == 1 && strcmp(ST->nome,s2)==0)
            return 1;
        if(trovato == 0 && strcmp(ST->nome,s1)==0)
            return esistenzaPercorso(ST->sx,s1,s2,1) || esistenzaPercorso(ST->dx,s1,s2,1);
        return esistenzaPercorso(ST->sx,s1,s2,trovato) || esistenzaPercorso(ST->dx,s1,s2,trovato);
    }
    return 0;
}

int verificaCiclo(stradario ST, street s1) {
    return esistenzaPercorso(ST,s1,s1,0);
}

int verificaConnessione(stradario ST1, stradario ST2) {
    if(ST1 && ST2){
        if(ST1->sx == NULL && ST1->dx == NULL)
            return contiene(ST2,ST1->nome);
        return verificaConnessione(ST1->sx,ST2) || verificaConnessione(ST1->dx,ST2);
    }
    return 0;
}

int contiene(stradario ST, street s) {
    if(ST){
        if(strcmp(ST->nome,s)==0)
            return 1;
        return contiene(ST->sx,s) || contiene(ST->dx,s);   
    }
    return 0;
}

int uguali(stradario ST1, stradario ST2){
    if(ST2 == NULL) return 1;
    if(ST1)
        return (strcmp(ST1->nome,ST2->nome)==0) && uguali(ST1->sx,ST2->sx) && uguali(ST1->dx,ST2->dx);
    return 0;
}

int verificaQuartiere(stradario ST1, stradario ST2){
    if(ST1 == NULL) return 0;
    if(ST2 == NULL) return 1;
    if(strcmp(ST1->nome, ST2->nome) == 0)
        if (uguali(ST1,ST2)) return 1;
    return verificaQuartiere(ST1->sx,ST2) || verificaQuartiere(ST1->dx,ST2);
}

