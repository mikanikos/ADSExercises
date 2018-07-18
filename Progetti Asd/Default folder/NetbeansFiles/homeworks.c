/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
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

/* quarto homework */

/* funzioni di supporto (oltre ad altezza e conta_foglie gia' definite */
/* funzione che calcola il numero di nodi per un livello l */
int nodi_livello(albero T, int l) {
    if(T==NULL) return 0;
    if(l==0) return 1;
    return nodi_livello(T->dx,l-1) + nodi_livello(T->sx,l-1);
}

/* INIZIO FUNZIONE */

int albero_pieno(albero T){
    
    /* Dato un un albero binario T di interi, la funzione albero_pieno deve ritornare un booleano:
     * 1 se l'albero T è "pieno", 0 altrimenti. Un albero binario “pieno” è un albero binario in cui
     * tutti i nodi hanno esattamente 0 o 2 figli, e nessun nodo ha 1 figlio. Se l'albero T è vuoto la funzione deve ritornare 1.*/
    
    if(T==NULL) return 1;
    if(T->sx == NULL && T->dx == NULL) return 1;
    if(T->sx != NULL && T->dx != NULL)
        return albero_pieno(T->sx) && albero_pieno(T->dx);
    return 0;
}

/* INIZIO FUNZIONE */

int albero_completo(albero T){
    
    /* Dato un un albero binario T di interi, la funzione albero_completo deve ritornare un booleano:
     * 1 se l'albero T è completo, 0 altrimenti. Un albero binario completo di altezza k è un albero binario
     * in cui tutti i nodi, tranne le foglie, hanno esattamente due figli, e tutte le foglie si trovano al livello k.
     * Se l'albero T è vuoto la funzione deve ritornare 0.*/
    
    if(T==NULL) return 0;
    int i, foglie = 1;
    for(i=0; i<altezza(T); i++)
        foglie = 2*foglie;
    if(foglie == conta_foglie(T)) return 1;
    return 0;
    
    /* if(T==NULL) return 0;
     * if(T->sx != NULL && T->dx != NULL)
     *     return albero_completo(T->sx) && albero_completo(T->sx);
     * if(T->sx == NULL && T->dx == NULL)
     *     if(altezza(T) == profondita'(T,T->info))
     *         return 1;
     * return 0;
     */
}

/* INIZIO FUNZIONE */

int larghezza_albero(albero T){
    
    /* Dato un un albero binario T di interi, la funzione larghezza_albero deve ritornare la larghezza di T;
     * la larghezza di un albero binario è il numero massimo di nodi che stanno tutti al medesimo livello.
     * Nel caso in cui T sia vuoto la funzione ritornerà 0.*/
    
    if(T == NULL) return 0;
    int l, temp=0, max = 1;
    for(l=1; l<=altezza(T); l++) {
        temp = nodi_livello(T,l);
        if(max < temp)
            max = temp;
    }
    return max;
}

/* quinto homework */

/* scrivi qui eventuali funzioni di appoggio */

/* funzione che verifica la presenza di una foglia con valore v */
int esiste_fogliaBRT(albero T, int v) {
    if(T == NULL) return 0;
    if(T->info == v && T->dx == NULL && T->sx==NULL)
        return 1;
    if(T->info > v)
        return esiste_fogliaBRT(T->sx,v);
    else
        esiste_fogliaBRT(T->dx,v);
}

/* funzione per il calcolo della profondita' di un nodo */
int depthBRT(albero T, int v) {
    if(T==NULL) return 0;	
    if (T->info == v) return 0;
    if (T->info > v) return 1 + depthBRT(T->sx,v);
    else return 1 + depthBRT(T->dx,v);
}

/* funzione per riempire l'array A con i valori info dei nodi del cammino dalla radice di T alla foglia di T contenente il valore v */ 
void riempiBRT(albero T, int v, int* A, int i) {
    if(T){
        if (T->info == v) A[i] = v;
        else A[i] = T->info;
        if (T->info > v)
            riempiBRT(T->sx,v,A,i+1);
        else
            riempiBRT(T->dx,v,A,i+1);
    }
}

/* funzione altezza definita sopra */

/* INIZIO FUNZIONE */

int* albero_cammino(albero T, int v){
    
    /* Si consideri un albero binario di ricerca T e un intero v (si ricorda che rispetto ad ogni nodo,
     * il figlio sinistro avrà un valore minore rispetto al padre, il figlio destro avrà un valore maggiore
     * rispetto al padre): allocare dinamicamente un array A di interi contenente i valori info dei nodi
     * del cammino dalla radice di T alla foglia di T contenente il valore v. Alla fine restituire l'array A
     * così costruito. Se l'albero T è vuoto, oppure non esiste una foglia in T contenente il valore v allora
     * restituire NULL. Se l'albero T non presenta alcuna foglia contenente v, ma presenta un nodo intermedio
     * con il valore v, la funzione deve restituire NULL */
    if(T == NULL || !esiste_fogliaBRT(T,v)) return NULL;
    int* A = (int*)calloc(depthBRT(T,v)+1,sizeof(int));
    riempiBRT(T,v,A,0);
    return A;

    
}