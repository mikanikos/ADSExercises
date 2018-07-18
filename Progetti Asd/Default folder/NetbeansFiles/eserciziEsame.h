/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   eserciziEsame.h
 * Author: Andrea
 *
 * Created on 04 January 2017, 16:41
 */

#ifndef ESERCIZIESAME_H_
#define ESERCIZIESAME_H_

/* 16.09.16 */
typedef struct elem{
    int valore;
    struct elem* sx;
    struct elem* dx;
}nodo_albero;
typedef nodo_albero* BTree;

typedef struct elem2{
    int valore;
    struct elem2* primofiglio;
    struct elem2* fratello;
 }nodo_alberoN;
typedef nodo_alberoN* BNTree;

int cammino_vero(BTree);
int livello_vero(BTree, int);
int conta_booleani(BNTree);

/* 22.06.16 */
typedef char stringa[20];
typedef struct elem3{
    stringa nome;
    struct elem3* sx;
    struct elem3* dx;
 }nodo_albero2;
typedef nodo_albero2* BTree2;

typedef struct elem4{
    stringa nome;
    struct elem4* primofiglio;
    struct elem4* fratello;
 }nodo_alberoN2;
typedef nodo_alberoN2* Ntree; 

int verificaDiscendenza(BTree2, stringa, stringa);
int verificaAntenato(BTree2, stringa, stringa, stringa);
int contaFratelli(Ntree, stringa);

/* 04.02.16 COMPITO A */
int discendenti(BTree2, stringa, stringa);
int contieneStr(BTree2, stringa);
int conta_genealogia(BTree, int);
int contaNodi(BTree);
int conta_discendenti(Ntree, int);

/* 04.02.16  COMPITO B */
int dist(BTree2, stringa, stringa);
int calcola_cammino(BTree2, stringa, int);
int conta_nodi(BTree2, int, char);
int conta_figli(Ntree, int, char);

/* 03.07.16 */
int conta_livello(BTree, int);
int confronta_alberi(BTree, BTree);
int confrontaAlb(BTree, BTree, int);
int max(int, int);

/* 18.06.14 */
struct elemABR{
    char c;
    struct elemABR* left;
    struct elemABR* right;
    struct elemABR* parent;
};
typedef struct elemABR* ABRTree;

struct elemList{
    int info;
    struct elemList* next;
};
typedef struct elemList* List;

/* 11.06.13 */
int altezzaAlb(BTree);
int contaFoglieAlb(BTree);
int** creaMatrice(BTree);
void aggiornaMatrice(BTree, int**, int, int);
int contaDiagonale(BTree, List);

/* 01.02.13 */
struct nodoEspressione{
    struct {
        int info;
        char op;
    }valore;
    struct nodoEspressione* left;
    struct nodoEspressione* right;
    struct nodoEspressione* parent;
};
typedef struct nodoEspressione* ExpressionTree;

struct listaEspressione{
    ExpressionTree expr;
    struct listaEspressione* next;
};
typedef struct listaEspressione* ExpressionList;

struct alberoBinRic{
    ExpressionTree expr;
    struct alberoBinRic* left;
    struct alberoBinRic* right;
    struct alberoBinRic* parent;
};
typedef struct alberoBinRic* BST;

int contaExpr(ExpressionList, int);
int calcolaExpr(ExpressionTree);
void createPABR(ExpressionList);
void BstInserisci(BST*, ExpressionTree);

/* 3.09.12 */
typedef char parola[20];

struct structIndex{
    struct {
        parola p;
        int n;
    }valore;
    struct structIndex* next;
    struct structIndex* prev;
};
typedef struct structIndex* Index;

void inserisciParola(Index *, parola, int);
int cercaParola(Index, parola, int);

/* 13.06.12 */
typedef char par[15];
typedef char sillaba[3];

struct elencoSillabe{
    sillaba sil;
    struct elencoSillabe* next;
};
typedef struct elencoSillabe* sillabario;

struct elencoParole{
    par word;
    struct elencoParole* next;
};
typedef struct elencoParole* parolario;

int numeroSillabe(sillabario, par);
int esisteSillaba(par, sillaba);
int contaSupportate(parolario, sillabario);

/* 14.02.12 */
struct carattere{
    char info;
    struct carattere* next;
};
typedef struct carattere* paroliere;

int verificaAlgoritmi(paroliere);
int minimoN(int*);

/* 31.01.13 */
char* allocaLivello(ABRTree, char);
int conta_nodi_livello(ABRTree, int);
int profonditaABR(ABRTree, int);
void costruisciArrayLivello(ABRTree, char*, int, int);

/* 26.11.13 */
struct parole {
    parola info;
    struct parole* next;
};
typedef struct parole* wordList;

typedef struct {
    int code;
    wordList indovinate;
    int score;
}giocatore;

struct giocatori {
    giocatore info;
    struct giocatori* next;
};
typedef struct giocatori* playersList;

int indovina(parola);
void insParola(playersList*, int, parola);

/* 21.11.12 */
struct esame {
    int info;
    struct esame* next;
};
typedef struct esame* examList;

typedef struct{
    char matr[5];
    examList esami;
}studente; 

struct insiemeStud {
    studente info;
    struct insiemeStud* next;
};
typedef struct insiemeStud* studentList;

void inserisciStudente(studentList*);
int calcolaMedia(studentList, char*);
void cancellaStudenti(studentList*, int);
#endif