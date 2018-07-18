#include <stdio.h>
#include "homeworks.h"

/* primo homework */
int valore_massimo(int **A, int r, int c){
    /* scrivi qui il codice che ritorna il valore massimo di una matrice A di interi con r righe e c colonne */

    int max;         // variabile intera per il massimo elemento
    int i,j;         // variabili intere contatori, rispettivamente di righe e colonne della matrice

    max = A[0][0];   // max inizializzata al primo elemento della matrice

    /* scansiono tutti gli elementi dell'array e li confronto con max */
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            /* se l'elemento considerato è più grande di max, lo memorizzo nella variabile max e proseguo il confronto */
            if(A[i][j]>max)
                max = A[i][j];

    /* max è il valore restituito */
    return max;
}

/* secondo homework */

int valore_massimo_lista(plist p){

    /* scrivi qui il codice che calcola il valore massimo
       contenuto in una lista semplicemente concatenata di
       interi passata in input e lo ritorna come output.
       Se la lista non ha nessun elemento ritorna zero. */

	plist temp;     // puntatore per scorrere la lista
	    temp = p;       // puntatore parte dall'inizio della lista
	    int max;        // variabile valore massimo
	    max = 0;        // variabile valore massimo inizializzata a 0 per default
	    /* se la lista è vuota restituisce 0, altrimenti inzializzo max
	       al valore contenuto nel primo nodo della lista */
	    if(temp != NULL) {
	    	max = temp->info;
	        /* scorro la lista: finché non è finita, confronto max con l'elemento corrente
	           ed eventualmente aggiorno max */
	    	while(temp != NULL){
	    	        if(temp->info > max)
	    	            max = temp->info;
	    	        temp = temp->next;
	    	    }
	    }
	    /* valore max resituito */
	    return max;
}


/* puoi scrivere qui eventuali funzioni di supporto che vuoi
   utilizzare nella funzione compara_array_lista */

int compara_array_lista(int A[], int n, plist p){

    /* Scrivi qui il codice che conta quanti elementi dell'array A
       lungo n siano presenti anche nella lista semplicemente
       concatenata p di interi.
       L'array A ha tutti elementi distinti, mentre la lista p
       potrebbe avere elementi duplicati. Se un elemento di A
       appare duplicato in p, deve essere contato una sola volta.
       Se la lista e' vuota oppure n e' zero allora ritorna zero.  */

	int cont,i;   // variabili contatore
	    plist temp;   // puntatore per scorrere la lista
	    cont = 0;     // variabile contatore degli elementi comuni inzializzato a 0
	    i = 0;        // variabile contatore per scorrere l'array parte da 0
	    /* ogni elemento dell'array è confrontato con tutti gli elementi
	       dei nodi della lista */
	    for(i=0; i<n; i++) {
	        temp = p;
	        /* scorro tutta la lista finché non finisce */
	        while(temp != NULL){
	            /* se trovo un elemento uguale incremento contatore ed esco dal while
	               per non considerare più gli elementi che si ripetono */
	            if(temp->info == A[i]) {
	                cont++;
	                break;
	            }
	            else
	                temp = temp->next;
	        }
	    }
	    /* valore contatore restituito */
	    return cont;
}

/* terzo homework */

/* Completa il codice in linguaggio C della funzione albero_altezza_foglie che prende
 * in input un albero binario T di interi e ritorna un booleano: 1 (true) se l'altezza
 * di T è pari al numero di foglie di T, 0 (false) altrimenti. Assumi che in un albero
 * binario vuoto l'altezza sia pari a -1 mentre il numero di foglie è pari a 0; quindi
 * se T è vuoto allora la funzione albero_altezza_foglie deve ritornare 0 */

/* scrivi qui eventuali funzioni di appoggio */

/* funzione per il calcolo del numero di foglie in un albero T */
int conta_foglie(albero T) {
    if (T)
      if (T->sx == NULL && T->dx == NULL )
       return 1;
      else
       return conta_foglie(T->sx) + conta_foglie(T->dx);
    else
       return 0;
}

/* funzione per il calcolo dell'altezza di un albero T */
int altezza(albero T) {
	if(T==NULL)
	    return -1;
	int l = altezza(T->sx);
	int r = altezza(T->dx);
	if(l>r)
		return l+1;
	else
		return r+1;
}

/* INIZIO FUNZIONE */

int albero_altezza_foglie(albero T) {

    /* Si consideri un albero binario T di interi. La funzione albero_altezza_foglie deve ritornare un booleano: 1 (true) se l'altezza di T è pari al numero di foglie di T, 0 (false) altrimenti. Si ricorda che in un albero binario vuoto l'altezza è pari a -1 mentre il numero di foglie è pari a 0; quindi se T è vuoto allora la funzione albero_altezza_foglie deve ritornare 0.*/
	if(conta_foglie(T) == altezza(T))
		return 1;
	else return 0;

}
