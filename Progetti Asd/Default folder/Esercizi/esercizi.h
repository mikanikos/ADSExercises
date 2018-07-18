#ifndef ESERCIZI_ESERCIZI_H_
#define ESERCIZI_ESERCIZI_H_

#define N 5

typedef char stringa[30];

struct punto {
	    double x;
	    double y;
    } a[N];

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

#endif /* ESERCIZI_ESERCIZI_H_ */
