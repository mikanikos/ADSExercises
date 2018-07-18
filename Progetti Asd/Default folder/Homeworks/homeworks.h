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

/* scrivi qui la definizione del tipo nodo_albero che rappresenta una struttura con tre campi: un campo info di tipo intero, un campo sx (il puntatore al sottoalbero sinistro), un campo dx (un puntatore al sottoalbero destro) */

struct nodo_albero {
	int info;
	struct nodo_albero* sx;
	struct nodo_albero* dx;
};

/* scrivi qui la definizione del tipo albero che rappresenta un puntatore alla struttura nodo_albero */

typedef struct nodo_albero* albero;

int conta_foglie(albero);
int altezza(albero);
int albero_altezza_foglie(albero);


#endif /* HOMEWORKS_HOMEWORKS_H_ */
