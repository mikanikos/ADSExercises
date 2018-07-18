#include <stdio.h>
#include <stdlib.h>

// definizione della struttura nodo
typedef struct elem{
      int info; // <tipo> <valore del nodo>;
      struct elem* next;
    } elist;

// definizione del puntatore ai nodi della lista
typedef elist* plist;

// stampa
void stampa(plist l) {
 printf("( ");
 while (l) {
  printf("[");
  printf("%d",l->info);
  printf("] ");
  l = l->next;
  }
 printf(")\n");
}


// funzione per inserire in testa ad una lista un nuovo nodo
void inserisciInTesta(plist* l, int n){
 plist temp = (plist)malloc(sizeof(elist));
 temp->info = n;
 temp->next = *l;
 *l = temp;
}

//funzione per inserire in coda ad una lista un nuovo nodo
void inserisciInCoda(plist* l, int n){
 plist temp = (plist)malloc(sizeof(elist));
 temp->info = n;
 temp->next = NULL;
 if (*l == NULL) *l = temp;
 else {
     plist temp2 = *l;
     while (temp2->next != NULL)
           temp2 = temp2->next;
     temp2->next=temp;
  }
}

// funzione per calcolare il numero di nodi di una lista
int lungLista(plist l){
  int cont = 0;
  while (l != NULL) {
      cont++;
      l = l->next;
      }
  return cont;
}

// funzione per inserire in un data posizione della lista un nuovo nodo
void inserisciInPos(plist *l, int n, int pos) {
 plist prev,cur;
 plist temp = (plist)malloc(sizeof(elist));
 temp->info = n;
 temp->next = NULL;
 int ln = lungLista(*l);
 if (ln<pos) inserisciInCoda(l,n);
 else
	 switch (pos) {
	      case 0: printf("bisogna indicare una posizione positiva maggiore di zero\n"); break;
	      case 1: inserisciInTesta(l,n); break;
	      default:
	        prev = *l; cur = prev->next;
	        while (pos>2) {
	          prev = cur;
	          cur = cur->next;
	          pos--;
	        }
	        prev->next = temp;
	        temp->next = cur;
	 }
}

// funzione per cancellare in una lista il nodo in testa
void cancellaInTesta(plist* l){
 if (*l != NULL) {
    plist temp = *l;
    *l = temp->next;
    free(temp);
    }
    else printf("La lista e' vuota\n");
}

// funzione per cancellare in una lista il nodo in coda
void cancellaInCoda(plist* l){
 plist prev,cur;
 switch(lungLista(*l)) {
   case 0: printf("La lista e' vuota\n"); break;
   case 1: free(*l); break;
   default:
     prev = *l;
     cur=prev->next;
     while (cur->next != NULL){
       prev = cur;
       cur = cur->next;
       }
     free(cur);
     prev->next=NULL;
   }
}

// funzione per cancellare in una lista un nodo in una data posizione
void cancellaInPos(plist* l, int pos){
  plist prev,cur;
  int ln = lungLista(*l);
  if (ln<pos) printf("La lunghezza della lista e' minore della posizione fornita\n");
  else
   switch(pos) {
     case 0: printf("Hai fornito una posizione non valida\n"); break;
     case 1: cancellaInTesta(l); break;
     default:
     prev = *l;
     cur=prev->next;
     while (pos>2){
       prev = cur;
       cur = cur->next;
       pos--;
       }
     prev->next=cur->next;
     free(cur);
   }
}

// funzione per cercare in una lista un nodo
int cercaLista(plist l, int n){
 int test = 0;
 while ((l!=NULL)&&(!test))
    if (l->info == n) test = 1;
    else l = l->next;
 return test;
}


/* ESERCIZI FATTI DA ME */

// cancella nella lista L i nodi con valore x
void cancVal(plist* l, int x) {
	plist prev,cur;
	if (l == NULL)
		printf("lista vuota");
	else {
		plist temp = *l;
		if(temp->info == x)
			cancellaInTesta(l);
		prev = *l;
	    cur=prev->next;
	    while(cur != NULL) {
	        if(cur->info == x)
	            prev->next = cur->next;
	        prev = cur;
	        cur = cur->next;
		}
	}
}

// conta in L quanti nodi hanno valore x
int contVal(plist l, int x) {
	int cont = 0;
	if(l == NULL)
		printf("lista vuota");
	else {
		plist temp = l;
	    while(temp != NULL) {
	    	if(temp->info == x)
	    		cont++;
			temp = temp->next;
	    }
	}
	return cont;
}

/* inserisce in L un nodo con valore x dopo il nodo esistente in L con valore y
   (se il nodo con valore y non esiste allora sarà fatto un inserimento in coda) */
void insVal(plist* l, int x, int y) {
	if (l == NULL)
		inserisciInTesta(l,x);
	else {
		plist temp2 = *l;
	    while(temp2 != NULL) {
	    	if(temp2->info == y) {
	    		plist temp = (plist)malloc(sizeof(elist));
	    		temp->info = x;
	    		temp->next = temp2->next;
	    		temp2->next = temp;
	    	}
	        temp2 = temp2->next;
	    }
	}
}

