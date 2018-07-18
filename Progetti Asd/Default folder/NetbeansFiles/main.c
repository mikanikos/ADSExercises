/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Andrea
 *
 * Created on 08 December 2016, 21:32
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "esercizi.h"

int main() {
    /* doubleLinkedList */
    //DoubleLinkedList l = (DoubleLinkedList)malloc(sizeof(node)); // prima lista
    //DoubleLinkedList m = (DoubleLinkedList)malloc(sizeof(node)); // seconda lista
    
    //creaDLL(l);
    //creaDLL(m);
    //l = insElem(l,33,66);
    //l = cancElem(l);
    //l = eliminaVal(l,4);
    //intersezione(l,m);
    //unione(l,m);
    //unioneSorted(l,m);
    //insOrdinato(l,2);
    //stampaDLL(l);
    int* A = NULL;
    A = (int*)calloc(3,sizeof(int));
    A[0]=4;
    A[1]=3;
    int i;
    for(i=0; i<3; i++)
        printf("%d",A[i]);
    return 1;
}
