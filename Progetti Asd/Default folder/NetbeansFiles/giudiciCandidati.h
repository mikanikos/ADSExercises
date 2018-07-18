/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#ifndef GIUDICICANDIDATI_H_
#define GIUDICICANDIDATI_H_

typedef struct{ 
    char nome[30];
    char cognome[30];
    int codice;
}GiudCand;

void gestioneGiudizi(int, int);
void stampaGiudCand(GiudCand*, int);
void stampaGiudizi(int**, int, int);
void smartest(GiudCand*, int**, int, int);
void strictest(GiudCand*, int**, int, int);

#endif
/* 
 * File:   giudiciCandidati.h
 * Author: Andrea
 *
 * Created on 11 January 2017, 18:50
 */