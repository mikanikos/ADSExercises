#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkedList.h"

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

/* inserimento di un elemento in testa e in coda alla lista */
DoubleLinkedList insElemTesta(DoubleLinkedList l, int a) {
	/* inserimento in testa */
	DoubleLinkedList n = (DoubleLinkedList)malloc(sizeof(node));
    n->value = a;
    l->next->prev = n;
    n->next = l->next;
    l->next = n;
    n->prev = l;

    return l;
}

DoubleLinkedList insElemCoda(DoubleLinkedList l, int b) {
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
    while(cur->value != 0) {
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
