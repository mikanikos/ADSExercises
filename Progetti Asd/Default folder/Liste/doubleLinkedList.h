#ifndef LISTE_DOUBLELINKEDLIST_H_
#define LISTE_DOUBLELINKEDLIST_H_

/* lista doppiamente concatenata circolare con nodo sentinella */
typedef struct elem2 {
    int          value;
    struct elem2  *prev;
    struct elem2  *next; } node;
typedef node *DoubleLinkedList;

/* doubleLinkedList */
int listEmpty(DoubleLinkedList);
DoubleLinkedList insElemTesta(DoubleLinkedList, int);
DoubleLinkedList insElemCoda(DoubleLinkedList, int);
DoubleLinkedList cancElem(DoubleLinkedList);
DoubleLinkedList eliminaVal(DoubleLinkedList, int);

#endif /* LISTE_DOUBLELINKEDLIST_H_ */
