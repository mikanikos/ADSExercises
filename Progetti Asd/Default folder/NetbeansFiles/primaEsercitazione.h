/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef PRIMAESERCITAZIONE_PRIMAESERCITAZIONE_H_
#define PRIMAESERCITAZIONE_PRIMAESERCITAZIONE_H_

/* stringa */
typedef char string[30];

/* candidato */
typedef struct {
    string cod;
    string nome;
    string cognome;
}candidato;

/* lista di candidati */
typedef struct elem1 {
    candidato info;
    struct elem1* next;
} nodo1;

typedef nodo1* listaCandidati;

/* votante */
typedef struct {
    string cod;
    string nome;
    string cognome;
}votante;

/* lista di votanti */
typedef struct elem2 {
    votante info;
    struct elem2* next;
} nodo2;

typedef nodo2* listaVotanti;


/* funzioni */
void aggiungiC (listaCandidati, candidato);
void aggiungiV (listaVotanti, votante);
int lungLV (listaVotanti);
void copia(string, string);
int checkVoti(listaCandidati, listaVotanti);
int confronta (string, string);
int lung(string);
int contaVoti(listaCandidati, listaVotanti, string, string);
void rimuovi (listaCandidati, listaVotanti) ;
#endif

/* 
 * File:   primaEsercitazione.h
 * Author: Andrea
 *
 * Created on 28 December 2016, 15:04
 */