/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   esercizi.h
 * Author: Andrea
 *
 * Created on 08 December 2016, 21:42
 */
#ifndef ESERCIZI_H_
#define ESERCIZI_H_

#define N 5

typedef char stringa[30];

struct punto {
	    double x;
	    double y;
} a[N];

/* lista doppiamente concatenata circolare con nodo sentinella */
typedef struct elem2 {
    int          value;
    struct elem2  *prev; 
    struct elem2  *next; } node;
typedef node *DoubleLinkedList;

/* selectionSort.c */
void selectionSort();

/* punti.c */
void gestionePunti();
void stampaElementi(struct punto a[]);
struct punto puntoMedio(struct punto, struct punto);
double distanza(struct punto, struct punto);
int quadrante(struct punto);
int contatore(struct punto a[], int);

/* stringhe.c */
void gestioneStringhe();
char occorrenza(stringa);
int maxArray(int[], int);

/* doubleLinkedList */
int listEmpty(DoubleLinkedList);
DoubleLinkedList creaDLL(DoubleLinkedList);
void stampaDLL(DoubleLinkedList);
DoubleLinkedList insElem(DoubleLinkedList, int, int);
DoubleLinkedList cancElem(DoubleLinkedList);
DoubleLinkedList eliminaVal(DoubleLinkedList, int);
void intersezione(DoubleLinkedList, DoubleLinkedList);
void unione(DoubleLinkedList, DoubleLinkedList);
void unioneSorted(DoubleLinkedList, DoubleLinkedList);
void insOrdinato(DoubleLinkedList, int);

/* esercizi avanzati */
/* esercizio 1 */
int isPerfect(int*);

/* esercizio 2 */
struct elem{
    char abbr[2];
    char *estesa;
    struct elem *next;
};

typedef struct elem* plist;

int listaAbbr(plist, char*, char*);

/* esercizio 3 */
struct nodo {
    int valore;
    struct nodo *next;
};
typedef struct nodo* nodoLista;
int maxVectList(struct nodo**, int);

/* esercizio 4 */
struct element3{
    char *nome;
    int eta;
};
struct element3* gestisciStudenti(int);

/* esercizio 5 */
char* ultimaPalindroma(char*[]);
int palindroma(char*);

/* esercizio 6 */
struct elem4{
    char *nome;
    struct elem4 *next;
};
struct elem4** puntaLista(struct elem4*);
int length(struct elem4*);

/* esercizio 7 */
char* eliminaChar(char*, char);

/* esercizio 8 */
void modificaVect(char**, int);

/* esercizio 9 */
char* newStringa(char*, char*);

/* esercizio 10 */
void modifica(struct nodo *);

/* esercizio 11 */
char* sommaStringhe(char*, char*);

/* strade */
typedef char street[20];

struct strada{
    street nome;
    struct strada* sx;
    struct strada* dx;
};
typedef struct strada* stradario;

int verificaPercorso(stradario, street, street);
int esistenzaPercorso(stradario, street, street, int);
int verificaCiclo(stradario, street);
int verificaConnessione(stradario, stradario);
int contiene(stradario, street);
int uguali(stradario, stradario);
int verificaQuartiere(stradario, stradario);

/* alberiLivelli */
typedef struct elemento{
    int info;
    struct elemento* sx;
    struct elemento* dx;
} nodo_albero;
typedef nodo_albero* albero;

typedef struct elemento2{
    int valore;
    struct elemento2* primo_figlio_sx;
    struct elemento2* fratello_dx;
} nodo_albero_N;

typedef nodo_albero_N* alberoN;


int esiste_foglia(albero, int);
int altezzaAlbero(albero);
int maxNumber(int, int);
int num_nodi_livello(albero, int);
int esiste_nodo_al_livello(albero, int, int);
int* costruisci_livello_foglia(albero, int);
int profonditaNodo(albero, int);
void costruisciArray(albero, int*, int);
int** livelli_nodo_comune(albero, albero);
void livelli_nodo_comune_aux(albero, albero, albero, int**, int);
int livelli_figli_nodo(albero, alberoN, int, int);

#endif /* ESERCIZI_ESERCIZI_H_ */