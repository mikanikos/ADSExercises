/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "esercizi.h"

void listInit(DoubleLinkedList *l) {
    *l = (DoubleLinkedList)malloc(sizeof(node));
    (*l)->value = 0;     // un valore dummy
    (*l)->prev = NULL;
    (*l)->next = NULL;
}

/* metodo che ritorna una lista vuota */
int listEmpty(DoubleLinkedList l) {
	return(l->next == NULL);
}

/* metodo che crea una lista da input */
DoubleLinkedList creaDLL(DoubleLinkedList l) {
    l->value = 0;     // un valore dummy
    l->prev = NULL;
    l->next = NULL;
    
    int i;
    DoubleLinkedList temp1 = l;
    for(i=0; i<N; i++) {
        DoubleLinkedList temp2 = (DoubleLinkedList)malloc(sizeof(node));
        scanf("%d", &temp2->value);
        temp2->next = NULL;
        temp2->prev = temp1;
        temp1->next = temp2;
        temp1 = temp2;
    }
    temp1->next = l;
    l->prev = temp1;
    
    return l;
}

/* metodo che stampa una lista */
void stampaDLL(DoubleLinkedList l) {
    DoubleLinkedList temp1 = l->next;
    printf("( ");
    while (temp1 != l) {
        printf("[");
        printf("%d",temp1->value);
        printf("] ");
        temp1 = temp1->next;
    }
    printf(")\n");
}

/* inserimento di un elemento in testa e in coda alla lista */
DoubleLinkedList insElem(DoubleLinkedList l, int a, int b) {
    DoubleLinkedList n = (DoubleLinkedList)malloc(sizeof(node));
    n->value = a;
    l->next->prev = n;
    n->next = l->next;
    l->next = n;
    n->prev = l;
    
    /* inserimento in coda */
    DoubleLinkedList p = (DoubleLinkedList)malloc(sizeof(node));
    p->value = b;
    p->prev = l->prev;
    p->next = l;
    l->prev->next = p;
    l->prev = p;
    
    return l;
}

/* cancellazione di un elemento in testa e in coda alla lista */
DoubleLinkedList cancElem(DoubleLinkedList l) {
    /* cancellazione in testa */
    DoubleLinkedList temp1 = l->next;
    temp1->next->prev = l;
    l->next = temp1->next;
    free(temp1);
    
    /* cancellazione in coda */
    DoubleLinkedList temp2 = l->prev;
    temp2->prev->next = l;
    l->prev = temp2->prev;
    free(temp2);
    
    return l;
}

/* L'eliminazione di un elemento qualunque della lista (passando il valore
 *  dell’elemento come parametro formale) */
DoubleLinkedList eliminaVal(DoubleLinkedList l, int val) {
    DoubleLinkedList prev = l, cur = l->next;
    while(cur->value != l) {
        if(cur->value == val) {
           cur->next->prev = prev;
           prev->next = cur->next;
           free(cur);
           cur = prev->next;
        }
        else {
            prev = prev->next;
            cur = cur->next;
        }
    }
    
    return l;
}

/* Definire una rappresentazione tramite lista per insiemi di numeri interi e
 * scrivere delle funzioni C che realizzino queste operazioni */

/* intersezione (va bene anche per mantenere la lista ordinata) */
void intersezione(DoubleLinkedList l, DoubleLinkedList m) {
    DoubleLinkedList i;
    listInit(&i);
    DoubleLinkedList tempI = i;
    DoubleLinkedList tempL = l->next;
    while(tempL != l) {
        DoubleLinkedList tempM = m->next;
        while(tempM != m) {
            if(tempL->value == tempM->value) {
                DoubleLinkedList temp = (DoubleLinkedList)malloc(sizeof(node));
                temp->value = tempL->value;
                temp->prev = tempI;
                temp->next = i;
                tempI->next = temp;
                i->prev = temp;
                tempI = temp;
            }
            tempM = tempM->next;
        }
        tempL = tempL->next;        
    }
    stampaDLL(i);
}

/* unione */
void unione(DoubleLinkedList l, DoubleLinkedList m) {
    DoubleLinkedList u; 
    listInit(&u);
    DoubleLinkedList temp;
    DoubleLinkedList tempU = u;
    DoubleLinkedList tempL = l->next;
    DoubleLinkedList tempM = m->next;
    while(tempL != l) {
        temp = (DoubleLinkedList)malloc(sizeof(node));
        temp->value = tempL->value;
        temp->prev = tempU;
        temp->next = u;
        tempU->next = temp;
        u->prev = temp;
        tempU = tempU->next;
        tempL = tempL->next;
    }
    while(tempM != m) {
        temp = (DoubleLinkedList)malloc(sizeof(node));
        temp->value = tempM->value;
        temp->prev = tempU;
        temp->next = u;
        tempU->next = temp;
        u->prev = temp;
        tempU = tempU->next;
        tempM = tempM->next;
    }
    u->prev = temp;
    temp->next = u;
    
    stampaDLL(u);
}

/* unione ordinata */
void unioneSorted(DoubleLinkedList l, DoubleLinkedList m) {
    DoubleLinkedList u; 
    listInit(&u);
    DoubleLinkedList new;
    DoubleLinkedList tempU = u;
    DoubleLinkedList tempL = l->next;
    DoubleLinkedList tempM = m->next;
    while(tempL != l && tempM != m) {
        if(tempL->value > tempM->value) {
            new = (DoubleLinkedList)malloc(sizeof(node));
            new->value = tempM->value;
            new->prev = tempU;
            new->next = u;
            tempU->next = new;
            u->prev = new;
            tempM = tempM->next;
        }
        else {
            new = (DoubleLinkedList)malloc(sizeof(node));
            new->value = tempL->value;
            new->prev = tempU;
            new->next = u;
            tempU->next = new;
            u->prev = new;
            tempL = tempL->next;
        }
        tempU = tempU->next;
    }
    if(tempM != m) {
        while(tempM != m) {
            new = (DoubleLinkedList)malloc(sizeof(node));
            new->value = tempM->value;
            new->prev = tempU;
            new->next = u;
            tempU->next = new;
            u->prev = new;
            tempU = tempU->next;
            tempM = tempM->next;
        }
    }
    else {
        while(tempL != l) {
            new = (DoubleLinkedList)malloc(sizeof(node));
            new->value = tempL->value;
            new->prev = tempU;
            new->next = u;
            tempU->next = new;
            u->prev = new;
            tempU = tempU->next;
            tempL = tempL->next;
        }
    }
    stampaDLL(u);
}

/* inserimento in un insieme equivale a inserire in coda o in testa */
/* rimozione dall'insieme signgifica cercare l'elemento e levarlo (già fatto sopra) */

/* inserimento ordinato */
void insOrdinato(DoubleLinkedList l, int k) {
    DoubleLinkedList new = (DoubleLinkedList)malloc(sizeof(node));
    new->value = k;
    DoubleLinkedList temp = l->next;
    if(temp->value > k){
        new->next = temp;
        new->prev = l;
        temp->prev = new;
        l->next = new;
    }
    else {
        while(temp != l && temp->value < k)
            temp = temp->next;
        new->next = temp->next;
        new->prev = temp;
        temp->next->prev = new;
        temp->next = new;
    }   
}


