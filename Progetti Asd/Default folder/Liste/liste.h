#ifndef LISTE_LISTE_H_
#define LISTE_LISTE_H_

// definizione della struttura nodo
typedef struct elem{
      int info; // <tipo> <valore del nodo>;
      struct elem* next;
    } elist;

// definizione del puntatore ai nodi della lista
typedef elist* plist;

/* funzioni*/
void stampa(plist);
void inserisciInTesta(plist*, int);
void inserisciInCoda(plist*, int);
int lungLista(plist);
void inserisciInPos(plist, int, int);
void cancellaInTesta(plist*);
void cancellaInCoda(plist*);
void cancellaInPos(plist*, int);
int cercaLista(plist l, int);
void cancVal(plist*, int);
int contVal(plist, int);
void insVal(plist*, int, int);

#endif /* LISTE_LISTE_H_ */
