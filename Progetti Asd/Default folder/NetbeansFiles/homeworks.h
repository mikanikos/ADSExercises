/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   homeworks.h
 * Author: Andrea
 *
 * Created on 08 December 2016, 21:43
 */
#ifndef HOMEWORKS_HOMEWORKS_H_
#define HOMEWORKS_HOMEWORKS_H_

/* primo homework */
int valore_massimo(int**, int, int);


/* secondo homework */

/* scrivi qui sotto la definizione del tipo "elist" (elemento
   della lista) con i campi "info" (intero) e "next"
   (prossimo elemento) */

typedef struct elem{
      int info; // <tipo> <valore del nodo>;
      struct elem* next;
    } elist;

/* scrivi qui sotto la definizione del tipo "plist" che e'
   un riferimento ad un oggetto di tipo "elist" */

typedef elist* plist;

int valore_massimo_lista(plist);
int compara_array_lista(int[], int, plist);

/* terzo homework */

/* scrivi qui la definizione del tipo nodo_albero che rappresenta una struttura
 * con tre campi: primo campo ha nome info ed è di tipo intero, secondo campo ha
 * nome sx (un puntatore al sottoalbero sinistro), terzo campo ha nome dx (un puntatore
 * al sottoalbero destro) [IMPORTANTE: non scambiare l'ordine dei campi] */

typedef struct elem_albero {
    int info;
    struct elem_albero* sx;
    struct elem_albero* dx;
} nodo_albero;


/* scrivi qui la definizione del tipo albero che rappresenta un puntatore alla struttura nodo_albero */

typedef nodo_albero* albero;

int conta_foglie(albero);
int altezza(albero);
int albero_altezza_foglie(albero);

/* quarto homework */

/* struttura albero gia' definita sopra */

int nodi_livello(albero, int);
int albero_pieno(albero);
int albero_completo(albero);
int larghezza_albero(albero);

/* quinto homework */

int esiste_fogliaBRT(albero, int);
int depthBRT(albero, int);
void riempiBRT(albero, int, int*, int);
int* albero_cammino(albero, int);

#endif /* HOMEWORKS_HOMEWORKS_H_ */