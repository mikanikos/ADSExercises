/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "eserciziEsame.h"
#include <string.h>

/* 13.09.16 */
/* CONNESSE-SPARSE(A)
 *     // color nuovo array di interi di lunghezza A.length
 *     for i=0 to A.length-1
 *         color[i]=0
 *     cont = 0
 *     for i=0 to A.length-1
 *         if(colo[i]==0)
 *             cont++
 *             DFS(A,i,color,cont)
 *     output = 0
 *     for i=1 to cont
 *         numNodi=0
 *         numArchi=0
 *         for j=0 to A.length-1
 *             if(color[j]==i)
 *                 numNodi++
 *                 numArchi = numArchi + CONTA-ARCHI(A,j)
 *         if((numArchi/2)-1 == numNodi)
 *             output++
 *     return output
 * 
 * CONTA-ARCHI(A,u)
 *      cont = 0
 *      x = A[u]
 *      while(x != NULL)
 *          cont++
 *          x = x.next
 *      return cont       
 *
 * DFS(A,i,color,cont)
 *      color[i] = cont
 *	x = A[i]
 *	while x != NULL
 *	    if(color[x.info] == 0)
 *              DFS(A,x.info,color,cont)
 *	    x = x.next
 */

int cammino_vero(BTree T) {
    if(T == NULL) return 0;
    if(T->valore == 1 && T->sx == NULL && T->dx == NULL)
        return 1;
    if(T->valore == 1)
        return cammino_vero(T->sx) || cammino_vero(T->dx);
    return 0;
}

int livello_vero(BTree T, int h) {
    if(T == NULL) return 0;
    if(h>0)
        return (livello_vero(T->sx,h-1)) && (livello_vero(T->dx,h-1));
    if(h==0 && T->valore == 1)
        return 1;
    return 0;
}

int conta_booleani(BNTree T) {
    if(T) {
        BNTree temp = T->primofiglio;
        if(temp == NULL) return 0;
        int verificato = 1;
        while(temp != NULL && verificato == 1) {
            if(temp->valore == 0)
                verificato = 0;
            temp = temp->fratello;
        }
        if(verificato == 1)
            return 1 + conta_booleani(T->primofiglio) + conta_booleani(T->fratello);
        else
            return conta_booleani(T->primofiglio) + conta_booleani(T->fratello);
    }
    return 0;        
}

/* 22.06.16 */
/* FOGLIE-COMPONENTE(T,A)
 *     // color nuovo array di lunghezza A.length
 *     for i=0 to A.lengt-1
 *         color[i]=0
 *     cont = 0
 *     for i=0 to A.length-1
 *         if(color[i]==0)
 *             cont++
 *             DFS(A,i,color,cont)
 *     for i=1 to cont
 *         verifica = true
 *         for j=0 to A.length-1
 *             if(color[j]==i)
 *                 verifica = verifica && VERIFICA-FOGLIA(T.root,j)
 *         if(verifica)
 *             return TRUE
 *     return FALSE
 * 
 * VERIFICA-FOGLIA(n,j)
 *     if(n == NULL) return FALSE
 *     if(n.left == NULL && n.right == NULL && n.info == j)
 *         return TRUE
 *     return VERIFICA-FOGLIA(n.left,j) || VERIFICA-FOGLIA(n.right,j)
 *         
 */

int veriificaDiscendenza(BTree2 T, stringa S1, stringa S2){
    if (T == NULL) return 0;
    if (strcmp(T->nome,S1) == 0)
        return contieneStr(T->sx,S2) || contieneStr(T->dx,S2);
    return veriificaDiscendenza(T->sx,S1,S2) || veriificaDiscendenza(T->dx,S1,S2);
}

/* GIA' DEFINITA SOTTO
int contieneStr(BTree2 T1, stringa nome){
    if (T1 == NULL) return 0;
    else {
        if (strcmp(T1->nome,nome) == 0) return 1;
        else return contiene(T1->sx,nome) || contiene(T1->dx,nome);
    }
}
*/

// MESSA IN COMMENTO PERCHE' MI DA UN ERRORE STRANO IN COMPILAZIONE 
/*int verificaAntenato(BTree2 T, stringa A, stringa S1, stringa S2) {
    int x = verificaDiscendenza(T,A,S1) && verificaDiscendenza(T,A,S2);
    return x;
}*/

int contaFratelli(Ntree T, stringa S) {
    if(T == NULL) return 0;
    int k = 0;
    Ntree temp = T->primofiglio;
    int verifica = 0;
    while(temp != NULL) {
        if(strcmp(temp->nome,S)==0)
            verifica = 1;
        k++;
        temp = temp->fratello;
    }
    if(verifica == 1) return k-1;
    return max(contaFratelli(T->primofiglio,S),contaFratelli(T->fratello,S));
}

/* 04.02.16  COMPITO A */
/* CONNESSE-DENSE(A)
 *     // color array di interi di lunghezza A.length
 *     for i=0 to color.length-1
 *         color[i]=0
 *     cont = 0
 *     for i=0 to A.length-1
 *         if(color[i] == 0)
 *             cont++
 *	       DFS(A,i,color,cont)
 *     output = 0
 *     for i=1 to cont
 *         verifica = true
 *    	   for j=0 to color.length-1
 *    	       if(color[j]==i)
 *    	           verifica = verifica && VERIFICA-MAX-ARCHI(A,j)
 *   	   if(verifica) 
 *             output++
 *     return output
 *
 * VERIFICA-MAX-ARCHI(A,u)
 *      cont = 0
 *      x = A[u]
 *      while(x != NULL)
 *          cont++
 *          x = x.next
 *      if(cont == A.length-1) return TRUE
 *      return FALSE         
 *
 * DFS(A,i,color,cont)
 *      color[i] = cont
 *	x = A[i]
 *	while x != NULL
 *	    if(color[x.info] == 0)
 *              DFS(A,x.info,color,cont)
 *	    x = x.next
 */

/* CONNESSE-SENZA-CICLI(A)
 *     // color array di interi di lunghezza A.length
 *     for i=0 to color.length-1
 *         color[i]=0
 *     cont = 0
 *     for i=0 to A.length-1
 *         if(color[i] == 0)
 *             cont++
 *	       DFS(A,i,color,cont)
 *     output = 0
 *     for i=1 to cont
 *         numNodi=0
 *         numArchi=0
 *         for j=0 to A.length-1
 *             if(color[j]==i)
 *                 numNodi++
 *                 numArchi = numArchi + CONTA-ARCHI(A,j)
 *         if((numArchi/2)-1 == numNodi)
 *             output++
 *     return output
 * 
 * CONTA-ARCHI(A,u)
 *      cont = 0
 *      x = A[u]
 *      while(x != NULL)
 *          cont++
 *          x = x.next
 *      return cont        
 *
 * DFS(A,i,color,cont)
 *      color[i] = cont
 *	x = A[i]
 *	while x != NULL
 *	    if(color[x.info] == 0)
 *              DFS(A,x.info,color,cont)
 *	    x = x.next
 */

int discendenti(BTree2 T, stringa S1, stringa S2){
    if (T == NULL) return 0;
    else {
        if (strcmp(T->nome,S1) == 0)
            return contieneStr(T->sx,S2) || contieneStr(T->dx,S2);
        else return discendenti(T->sx,S1,S2) || discendenti(T->dx,S1,S2);
    }
}

int contieneStr(BTree2 T1, stringa nome){
    if (T1 == NULL) return 0;
    else {
        if (strcmp(T1->nome,nome) == 0) return 1;
        else return contieneStr(T1->sx,nome) || contieneStr(T1->dx,nome);
    }
}


int conta_livello(BTree T, int m) {
    if(T == NULL) return 0;
    if(m==0)
        return 1;
    else
        return conta_livello(T->dx,m-1) + conta_livello(T->sx,m-1);
}

// ALCUNE FUNZIONI VENGONO DATE GIA' IMPLEMENTATE
/* int confronta_alberi(BTree T1, BTree T2) {
 *     int* A1 = NULL, A2 = NULL;
 *     int alt1,alt2,i,cont = 0;
 *     if(T1 == NULL || T2 == NULL) return 0;
 *     alt1 = altezza(T1);
 *     alt2 = altezza(T2);
 *     if(alt1 > alt2) max = alt1;
 *     else max = alt2;
 *     for(i=0; i<=max; i++) {
 *         A1 = creaArray(T1,i);
 *         A2 = creaArray(T1,i);
 *         if(confrontaArray(A1,A2,conta_livello(T1,i))
 *             cont++;
 *     }
 *     return cont;
}*/
int conta_genealogia(BTree T, int x) {
    if(T) {
        if(contaNodi(T) > x)
            return 1 + conta_genealogia(T->sx,x) + conta_genealogia(T->dx,x);
        else
            return conta_genealogia(T->sx,x) + conta_genealogia(T->dx,x);
    }
    return 0;
}

int contaNodi(BTree T) {
    if(T)
        return 1 + contaNodi(T->sx) + contaNodi(T->dx);
    return 0;   
}

int conta_discendenti(Ntree T, int x) {
    int k1=0;
    Ntree temp;
    if (T == NULL) return 0;
    else {
        temp=T->primofiglio;
        while (temp!=NULL){
            k1++;
            temp = temp->fratello;
        }
        if (x==k1)
            return 1+conta_discendenti(T->fratello,x)+ conta_discendenti(T->primofiglio,x);
        else
            return conta_discendenti(T->fratello,x)+conta_discendenti(T->primofiglio,x);
    }
}

/* 04.02.16  COMPITO B */

int dist(BTree2 T, stringa S1, stringa S2) {
    if(T == NULL) return 0;
    if (strcmp(T->nome,S1) == 0)
            return calcola_cammino(T,S2,0);
    return dist(T->sx,S1,S2) || dist(T->dx,S1,S2);
}

int calcola_cammino(BTree2 T1, stringa nome, int i){
    if (T1 == NULL) return 0;
    if (strcmp(T1->nome,nome) == 0) return i;
    return max(calcola_cammino(T1->sx,nome,i+1),calcola_cammino(T1->dx,nome,i+1));
}

int conta_nodi(BTree2 T, int x, char c) {
    if(T) {
        //if(conta_occorrenza(T,c)>= x) // conta_occorrenza viene data già implementata
            return 1 + conta_nodi(T->dx,x,c) + conta_nodi(T->sx,x,c);
        return conta_nodi(T->dx,x,c) + conta_nodi(T->sx,x,c);
    }
    return 0;
}

int conta_figli(Ntree T, int x, char c) {
    int k=0;
    if(T == NULL) return 0;
    Ntree temp = T->primofiglio;
    while(temp != NULL) {
        if(memchr(temp->nome,c,strlen(temp->nome)) != NULL)
            k++;
        temp = temp->fratello;
    }
    if(k==x)
        return 1 + conta_figli(T->primofiglio,x,c) + conta_figli(T->fratello,x,c);
    else
        return conta_figli(T->primofiglio,x,c) + conta_figli(T->fratello,x,c);
}

/* 03.07.15 */
/* CONNESSE-DUE-ARCHI(A)
 *	for i=0 to color.length-1
 *	    color[i]=0
 *       cont = 0
 *	for i=0 to A.length-1
 *          if color[i] == 0
 *		cont++
 *		DFS(A,i,color,cont)
 *      output = 0
 *      for i=1 to cont
 *    	    verifica = true
 *    	    for j=0 to color.length-1
 *    		if color[j]==i
 *    	            verifica = verifica && VERIFICA-DUE-ARCHI(A,j)
 *   	    if (verifica) output++
 *      return output
 *
 * VERIFICA-DUE-ARCHI(A,u)
 *      cont = 0
 *      x = A[u]
 *      while( x != NULL)
 *          cont++
 *          x = x.next
 *      if(cont > 2) return FALSE
 *      return TRUE         
 *
 * DFS(A,i,color,cont)
 *	color[i] = cont
 *	x = A[i]
 *	while x != NULL
 *	    if( color[x.info] == 0)
 *       	DFS(A,x.info,color,cont)
 *	    x = x.next
 */

// ALCUNE FUNZIONI VENGONO DATE GIA' IMPLEMENTATE
/* int confronta_alberi(BTree T1, BTree T2) {
 *     int* A1 = NULL, A2 = NULL;
 *     int alt1,alt2,i,cont = 0;
 *     if(T1 == NULL || T2 == NULL) return 0;
 *     alt1 = altezza(T1);
 *     alt2 = altezza(T2);
 *     if(alt1 > alt2) max = alt1;
 *     else max = alt2;
 *     for(i=0; i<=max; i++) {
 *         A1 = creaArray(T1,i);
 *         A2 = creaArray(T1,i);
 *         if(confrontaArray(A1,A2,conta_livello(T1,i))
 *             cont++;
 *     }
 *     return cont;
}*/

int max(int a, int b) {
    if(a>b)
        return a;
    return b;
}

/* 18.06.14 */

// ESERCIZIO 1 DI PSEUDOCODIFICA
/* 
 * DEPTH(T)
 *     n = CONTA_NODI(T.root)
 *     // creo un array di interi v con n posizioni 
 *     DEPTH_RIC(T.root,v,0)
 *     return v
 * 
 * DEPTH_RIC(n,v,i)
 *     if(n == NULL) return
 *     v[n.info] = i
 *     DEPTH_RIC(n.left,v,i++)
 *     DEPTH_RIC(n.right,v,i)
 */

/* SAME(A,T,u)
 *     // a e b nuovi array di lunghezza A.length
 *     a = DEPTH(T)
 *     b = DISTANCE(A,u)
 *     for i=0 to A.length-1
 *         if(a[i]!=b[i])
 *             return FALSE
 *     return TRUE
 * 
 * DISTANCE(A,v)
  	for i=0 to A.length-1
  		color[i] = 0
  		D[i] = 0
  	q = EMPTY-QUEUE()
  	color[v] = 1
  	EUQUEUE(q,v)
  	while !IS-EMPTY(q)
  		u = DUQUEUE(q)
  		x = A[u]
		while x != NULL
			if(color[x.info] == 0)
				D[x.info] = D[u]+1
				color[x.info] = 1
				ENQUEUE(q,x.info)
			x = x.next
		color[u] = 2

    return D
 *     
 */

/* SAME(A,T)
 *     // a e b nuovi array di lunghezza A.length
 *     a = DEPTH(T)
 *     b = DEGREE(A)
 *     for i=0 to A.length-1
 *         if(a[i]!=b[i])
 *             return FALSE
 *     return TRUE
 * 
 * DEGREE(A)
 *     // a è un nuovo array di interi di lunghezza A.length
 *     for i=0 to A.length-1
 *         a[i] = 0
 *     for i=0 to A.length-1
 *         x = A[i]
 *         while(x != NULL)
 *             a[i] = a[i] + 1
 *             x = x.next
 *     return a
 */

/* int distanza(ABRTree T, char v1, char v2) {
    if(T == NULL) return 0;
    if(v1 == T->info)
        return calcola_cammino(T,v2,0);
    if(v2 == T->info)
        return calcola_cammino(T,v1,0);
    return distanza(T->sx,S1,S2) || distanza(T->dx,S1,S2);
}

int calcola_cammino(ABRTree T, char c, int i){
    if (T1 == NULL) return 0;
    if (T->info == c) return i;
    return max(calcola_cammino(T->sx,c,i+1),calcola_cammino(T->dx,c,i+1));
}
 */

/*
List allocaLista(ABRTree T, char v) {
    List l = (List)malloc(sizeof(struct elemABR));
    if(T == NULL) return NULL;
    while(T != NULL && T->c != v) {
        if(T->c < v)
            T = T->left;
        else
            T = T->right;
    }
    alloca(T,v,l);
    return l;
}

// FUNZIONI GIA' IMPLEMENTATE
void alloca(ABRTree T, char v, List *l) {
    if(T == NULL) return
    if(T->left == NULL && T->right == NULL) {
        List temp = (List)malloc(sizeof(struct elemABR));
        temp->info = distanza(v,T->info));
        temp->next = *l;
        *l = temp;
    }
    alloca(T->left,v,*l);
    alloca(T->right,v,*l);
    }
}*/

/* 31.01.2014 */
// ESERCIZIO 3 PSEUDOCODICE 
/*
 * RIMOZIONE(L,A)
 *     for i = 0 to A.length
 *         a = A[i]
 *         temp = l.head
 *         while(temp != NULL)
 *             if(temp.info == a)
 *                 if(temp == L.head)
 *                     L.head = temp.next
 *                 else
 *                     temp.prev.next = temp.next
 *                 if temp.next != NULL
 *                     temp.next.prev = temp.prev
 *             temp = temp.next
 */

/*
List allocaLista(ABRTree T, int v) {
    if(T == NULL) return NULL;
    List l = (List)malloc(sizeof(struct elemABR));
    alloca(T,l,v);
    return l;
}

void alloca(ABRTree T, List *l, int v) {
    if(T){
        if(v == 0)
            insertOrdered(*l,T->c);
        else {
            alloca(T->left,l,v--);
            alloca(T->right,l,v--);
        }
    }
}
 * 
 * void insert-Ordered(List *l, int c)
 *     List prev,curr;
 *     List new = (List)malloc(sizeof(struct elemABR));
 *     new->info = c;
 *     new->next = NULL;
 *     if(c < (*l)->info) {
 *         new->next = *l;
 *         *l = new;
 *     }
 *     else {
 *         prev = *l;
 *         curr = *l->next;
 *         while(curr != NULL && curr->info < c)
 *             prev = curr;
 *             curr = curr->next;
 *         }
 *         prev->next = new;
 *         new->next = curr;
 *     }
 * }
 */

/* int verificaLivelli(ABRTree T1, ABRTree T2, int v) {
 *     List l1 = allocaLista(T1,v);
 *     List l2 = allocaLista(T2,v);
 *     List temp1 = l1,temp2=l2;
 *     int cont = 0;
 *     while(temp1 != NULL) {
 *         temp2 = l2;
 *         while(temp2 != NULL)
 *             if(temp1->info == temp2->info)
 *                 cont++;
 *             temp2 = temp2->next;
 *         temp1 = temp1->next;
 *     return cont;
 */            

/* 11.06.13 */
/* ESERCIZIO 1 PSEUDOCODIFICA 
 * CAMMINO_PIU_CORTO(T)
 *     if T != NULL
 *         return CAMM_RIC(t.root)
 *     return NULL
 * 
 * CAMM_RIC(n)
 *     if n == NULL return -1
 *     return 1 + min(CAMM_RIC(n.left),CAMM_RIC(n.left))
 */

/* NODI_LONTANI(A,u,d)
 *     // color e D nuovi array con A.length posizioni
 *     for i=0 to A.length-1
 *         color[i]=0
 *         D[i]=0
 *     q = CREATE-QUEUE()
 *     ENQUEUE(q,u)
 *     color[u]=1
 *     while !IS-EMPTY-QUEUE()
 *         u = DEQUEUE(q)
 *         x = A[u]
 *         while x != NULL
 *             if color[x.info] == 0
 *                 D[x.info]=D[u]+1
 *                 color[x.info]=1
 *                 ENQUEUE(q,x.info)
 *             x = x.next
 *     cont = 0
 *     for i = 0 to A.length-1
 *         if D[i]>d
 *             cont++
 *     return cont
 */

int altezzaAlb(BTree T) {
    if(T)
        return 1 + max(altezzaAlb(T->sx), altezzaAlb(T->dx));
    return -1;
}

int contaFoglieAlb(BTree T) {
    if(T) {
        if(T->sx == NULL && T->dx == NULL)
            return 1;
        return contaFoglieAlb(T->sx) + contaFoglieAlb(T->dx);
    }
    return 0;
}

int** creaMatrice(BTree T) {
    int** M; int i,j;
    int n = altezzaAlb(T)+1;
    int m = contaFoglieAlb(T);
    M = (int**)calloc(n,sizeof(int*));
    for (i=0; i<n; i++)
       M[i] = (int*)calloc(m,sizeof(int));
    for (i=0; i<n; i++) 
        for (j=0; j<m; j++)
            M[i][j]=0;
    aggiornaMatrice(T,M,0,0);
    return M;
}

// !!!!!!!!!!!!! NON CORRETTA !!!!!!!!!!!!!!!!!!!//
void aggiornaMatrice(BTree T, int** M, int i, int j) {
    if(T) {
        aggiornaMatrice(T->sx,M,i+1,j);
        M[i][j]=T->valore;
        aggiornaMatrice(T->dx,M,i,j+1);
    }
}
//////////////////////////////////////////////////////////

int contaDiagonale(BTree T, List L) {
    int** M = creaMatrice(T);
    int n = altezzaAlb(T)+1;
    int m = contaFoglieAlb(T);
    int i,j,cont=0;
    for(i=0, j=0; i<n && j<m; i++, j++) {
        int curr = M[i][j];
        List temp = L;
        while(temp != NULL) {
            if(temp->info == curr)
                cont++;
            temp = temp->next;
        }
    }
    return cont;
}

/* 01.02.13 */
/* ESERCIZIO 1 PSEUDOCODICE
 * MERGE_LIST(L1,L2)
 *     l1 = LENGTH(L1)
 *     l2 = LENGTH(L2)
 *     // CREO UN NUOVO ARRAY A CON l1+l2 elementi
 *     x1 = L1.head
 *     x2 = L2.head
 *     while(x1 != NULL && x2 != NULL)
 *         if(x1.info < x2.info)
 *             A[i++] = x1.info
 *             x1 = x1.next
 *         else
 *             A[i++] = x2.info
 *             x2 = x2.next
 *     while(x1 != NULL)
 *         A[i++] = x1.info
 *         x1 = x1.next
 *     while(x2 != NULL)  
 *         A[i++] = x2.info
 *         x2 = x2.next
 *     
 *     return A
 */

/* CONTA‐COMPONENTI‐CONNESSE(A)
 *     for i=0 to A.length-1
 *         color[i] = 0
 *     cont = 0;
 *     for i=0 to A.length-1
 *         if(color[i]==0)
 *             cont++
 *             DFS(A,u,color)
 *     return cont
 * 
 * DFS(A,u,color)
 *     color[u]=1
 *     x = A[u]
 *     while(x != NULL)
 *         if(color[x.key]==0)
 *            DFS(A,x.key,color)
 *         x = x.next
 */

/* INVERTI-ARCHI(A)
 *     B NUOVO GRAFO
 *     for i=0 to A.length-1
 *         B[i]=NULL
 *     for i=0 to A.length-1
 *         x = A[i]
 *         while(x != NULL)
 *             AGGIUNGI-ARCO(B,x.info,u)
 *             x = x.next
 *     return B
 * 
 * AGGIUNGI-ARCO(A,u,v)
 *     temp.info = v
 *     temp.prev = NULL
 *     temp.next = A[u]
 *     if(A[u]!=NULL)
 *         A[u].prev = temp
 *     A[u]=temp
 */        

/* COMPONENTI-CONNESSE-SIGNIFICATIVE(A)
 *     // color nuovo array di A.length posizioni
 *     for i=0 to color.length-1
 *         color[i]=0
 *     cont = 0
 *     for i=0 to color.length-1
 *         if(color[i]==0)
 *             cont++
 *             DFS(A,0,color,cont)
 *     contComp = 0
 *     for i=1 to cont
 *         nodi = 0
 *         for j=0 to color.length-1
 *             if(color[j]==i)
 *                 nodi++
 *         if(nodi > 1)
 *             contComp++
 *     return contComp
 * 
 * DFS(A,u,color,cont)
 *     color[u]=cont
 *     x = A[u]
 *     while(x != NULL)
 *         if(color[x.info]==0)
 *             DFS(A,x.info,color,cont)
 *         x = x.next
 */

/* COMPONENTI-CONNESSE.BANALI(A)
 *     // color nuovo array di A.length posizioni
 *     for i=0 to color.length-1
 *         color[i]=0
 *     cont = 0
 *     for i=0 to color.length-1
 *         if(color[i]==0)
 *             cont++
 *             DFS(A,0,color,cont)
 *     contComp = 0
 *     for i=1 to cont
 *         nodi = 0
 *         for j=0 to color.length-1
 *             if(color[j]==i)
 *                 nodi++
 *         if(nodi < 3)
 *             contComp++
 *     return contComp
 * 
 * DFS(A,u,color,cont)
 *     color[u]=cont
 *     x = A[u]
 *     while(x != NULL)
 *         if(color[x.info]==0)
 *             DFS(A,x.info,color,cont)
 *         x = x.next
 */

int contaExpr(ExpressionList L, int v) {
    int x = 0;
    while(L != NULL) {
        if(calcolaExpr(L->expr) > v)
            x++;
        L = L->next;
    }
    return x;
}

int calcolaExpr(ExpressionTree T) {
    if(T){
        switch(T->valore.op) {
            case '+':  return calcolaExpr(T->left) + calcolaExpr(T->right); break;
            case '-':  return calcolaExpr(T->left) - calcolaExpr(T->right); break;
            case '*':  return calcolaExpr(T->left) * calcolaExpr(T->right); break;
            case '/':  return calcolaExpr(T->left) / calcolaExpr(T->right); break;
            default:  return T->valore.info;
        }
    }
}

void createPABR(ExpressionList L) {
    BST T = (BST)malloc(sizeof(struct alberoBinRic));
    while(L != NULL){
        if(calcolaExpr(L->expr) % 2)
            BstInserisci(T,L->expr);
        L = L->next;
    }
}

void BstInserisci(BST* B, ExpressionTree A) {
	if (*B == NULL) {
		(*B) = (BST)malloc(sizeof(struct alberoBinRic)); 
		(*B)->expr = A; 
		(*B)->left = NULL; 
		(*B)->right = NULL;
	}
	else 
		if (calcolaExpr(A) < calcolaExpr((*B)->expr)) BstInserisci((*B)->left,A);
	else 
		if (calcolaExpr(A) > calcolaExpr((*B)->expr)) BstInserisci((*B)->right,A);
}

/* ESERCIZIO 1 PSEUDOCODICE COMPITO A
 * LISTA_ORDINATA(V)
 *     // creo una nuoa lista L
 *     L.head = NULL
 *     for i = 1 to n - 1
 *         posmin = i
 *         for j = (i + 1) to n
 *             if V[j] < V[posmin]
 *                 posmin = j
 *         inserisciInCoda(L,V[posmin])
 */

/* GLI ALTRI ESERCIZI PER LA PARTE DI C SONO SIMILI A SOPRA */

/* 3.09.12 */
/* CONTA-RAGGIUNTI(G,n,L)
 *     // color nuovo array di G.length posizioni
 *     for i=0 to color.length-1
 *         color[i]=0
 *     DFS(G,n,color)
 *     cont = 0
 *     x = L.head
 *     while(x != NULL)
 *         if(color[x.info] != 0)
 *             cont++
 *         x = x.next
 *     return cont
 * 
 * DFS(A,u,color)
 *     color[u]=1
 *     x = A[u]
 *     while(x != NULL)
 *         if(color[x.info]==0)
 *             DFS(A,x.info,color)
 *         x = x.next
 */
/* GLI ALTRI ESERCIZI IN PSEUDOCODIFICA SONO BANALI (IL PRIMO FACILE, IL SECONDO UGUALE A QUESTO SOPRA E L'ULTIMO GIA' FATTO IN CLASSE */
void inserisciParola(Index *i, parola p, int n) {
    Index new = (Index)malloc(sizeof(struct structIndex));
    strcpy(new->valore.p,p);
    new->valore.n = n;
    Index temp = *i;
    if(temp->valore.p[0] > p[0]) {
        new->next = *i;
        *i = new;
    }
    else {
        while(temp->next != NULL && temp->next->valore.p[0] < p[0])
            temp = temp->next;
        new->next = temp->next;
        temp->next = new;
    }
}

int cercaParola(Index i, parola p, int n) {
    int verifica = 0;
    Index temp = i;
    while(temp != NULL && verifica==0) {
        if(strcmp(temp->valore.p,p)==0 && temp->valore.n == n)
            verifica = 1;
        temp = temp->next;
    }
    if(verifica == 0)
        inserisciParola(i,p,n);
    return verifica;
}

/* 12.06.12 */
/* ESERCIZI PSEUDOCODIFICA */
/* FIGLI-RADICE(T)
 *     if(T.root.right != NULL && T.root.left != NULL)
 *         return TRUE
 *     return FALSE
 */

/* CERCA(T.u)
 *     if(T)
 *         return CERCA_RIC(T.root,u)
 *     return NULL
 * 
 * CERCA_RIC(n,u)
 *     if(!n) return NULL
 *     if(n.info == u)
 *         return n
 *     a = CERCA_RIC(n.left,u)
 *     if(a) return a 
 *     return CERCA_RIC(n.right,u)
 */

/* CAMMINO(A,u,v)
 *     for i=0 to A.length-1
 *         color[i] = 0
 *     DFS(A,u,color)
 *     if (color[v] == 1) return TRUE
 *     return FALSE 
 * 
 * DFS(A,u,color)
 *     color[u]=1
 *     x = A[u]
 *     while(x != NULL)
 *         if(color[x.key]==0)
 *            DFS(A,x.key,color)
 *         x = x.next
 */

/* ANTENATO(T,u,v)
 *     if(CERCA(T,v)!=NULL)
 *         while(n.parent != NULL)
 *             if(n.parent.info == u)
 *                 return TRUE
 *             n = n.parent
 *     return FALSE
 */

int numeroSillabe(sillabario s, par p) {
    int i,j,cont,trovato = 0;
    sillaba temp;
    while(s != NULL) {
        if(!esisteSillaba(p,s->sil))
            cont++;
        s = s->next;
    }
    return cont;
}

int esisteSillaba(par p, sillaba s) {
    int l1=strlen(p),l2=strlen(p);
    int i,j,finito,contenuto;
    finito = 0;
    for (i=0; i+(l2-1)<l1 && finito==0; i++) {
        contenuto = 1;
        for (j=0; j<l2 && contenuto==1; j++) {
            if(p[i+j] != s[j])
                contenuto = 0;
        }
        if (contenuto==1)
            finito = 1;
    }
    return contenuto;
}

int contaSupportate(parolario p, sillabario s) {
    int cont = 0;
    while(p != NULL) {
        if(numeroSillabe(s,p->word)==0)
            cont++;
        p = p->next;
    }
    return cont;
}

/* 14.02.2012 */
/* ESERCIZI PSEUDOCODIFICA */
/* SOLO-RADICE(T)
 *     if(T)
 *         return T.root.left == NULL && T.root.right == NULL
 *     return FALSE
 */

/* CONTA-NODI(T)
 *     return CONTA-NODI-RIC(T.root)
 * 
 * CONTA-NODI-RIC(n)
 *     if(n == NULL) return 0
 *     return 1 + CONTA-NODI-RIC(n.right) + CONTA-NODI-RIC(n.left)
 */

/* VERIFICA-ALBERO(A,u)
 *     for i=0 to A.length-1
 *         color[i]=0
 *     return DFS(A,u,color)
 * 
 * DFS(A,u,color)
 *     color[u]=1
 *     x = A[u]
 *     albero = TRUE
 *     while(x != NULL)
 *         if(color[x.key]==1)
 *             return FALSE
 *         if(color[x.key]==0)
 *            albero = albero && DFS(A,x.key,color)
 *         x = x.next
 *     return albero
 */

int verificaAlgoritmi(paroliere p) {
    int a,l,g,o,r,i,t,m;
    int cont;
    while(p!= NULL) {
        switch(p->info) {
            case 'a': a++; break;
            case 'l': l++; break;
            case 'g': g++; break;
            case 'o': o++; break;
            case 'r': r++; break;
            case 'i': i++; break;
            case 't': t++; break;
            case 'm': m++; break;
            default: ;
        }
        p=p->next;
    }
    int x[7];
    x[0]=a; x[1]=l; x[2]=g; x[3]=o; x[4]=r; x[5]=t; x[6]=m; 
    int min = minimoN(x);
    if(i >= 2*min)
        cont = min;
    else
        cont = i/3;
    return cont;
}

int minimoN(int* x) {
    int min = x[0];		
    for(int i=1; i<20; i++) 
        if(x[i]<min)
            min = x[i];
    return min;    
}

/* 31.01.14 */
/* ORDINE-BFS(A,u)
 *     // color nuovo array
 *     for i=0 to A.length-1
 *         color[i]=0
 *     // l nuova lista di interi dopp. conc.
 *     q = CREATE-QUEUE()
 *     ENQUEUE(q,u)
 *     color[u]=1
 *     while !IS-EMPTY-QUEUE(q)
 *         i = DEQUEUE(q)
 *         AGGIUNGI-IN-TESTA(l,i)
 *         x = A[i]
 *         while x != NULL
 *             if color[x.info]==0
 *                 color[x.info]=1
 *                 ENQUEUE(q,x.info)
 *             x = x.next
 *     // l2 nuova lista
 *     x = l.head
 *     while x != NULL
 *         AGGIUNGI-IN-TESTA(l2,x.info)
 *         x = x.next
 *     return l2
 * 
 * AGGIUNGI-IN-TESTA(l,v)
 *     // temp nuovo nodo
 *     temp.info = v
 *     temp.prev = NULL
 *     temp.next = l.head
 *     if(temp != NULL)
 *         l.head.prev = temp
 *     l.head = temp
 */ 

/* GRAFO-CICLO(A)
 *     for i=0 to A.length-1
 *         color[i] = 0
 *     DFS(A,0,color)
 *     for i=0 to A.length-1
 *         if(color[i] == 0)
 *             return FALSE
 *     for i=0 to A.length-1
 *         x = A[i]
 *         cont = 0
 *         while(x != NULL)
 *             if(x.info == i)
 *                 return FALSE
 *             cont++
 *             x = x.next
 *         if(cont != 2)
 *             return FALSE
 *     return TRUE
 *     
 * DFS(A,u,color)
 *     color[u]=1
 *     x = A[u]
 *     while(x != NULL)
 *         if(color[x.key]==0)
 *            DFS(A,x.key,color)
 *         x = x.next
 */

/* ALBERI-UGUALI(T1,T2)
 *     return UGUALI_RIC(T1.root,T2.root)
 * 
 * UGUALI_RIC(n1,n2)
 *     if((n1 == NULL && n2 == NULL)) return TRUE
 *     if(n1 != NULL && n2 != NULL)
 *         return UGUALI_RIC(n1.left,n2.left) && UGUALI_RIC(n1.right,n2.right) && n1.info == n2.info
 *     return FALSE
 */

char* allocaLivello(ABRTree T, char c) {
    int l = profonditaABR(T,c);
    if(l == -1) return NULL;
    char* a = (char*)calloc(conta_nodi_livello(T,l),sizeof(char));
    costruisciArrayLivello(T,a,l,0);
    return a;
}

int conta_nodi_livello(ABRTree T, int l) {
    if(!T)return 0;
        if(l==0) return 1;
        return conta_nodi_livello(T->right,l-1) + conta_nodi_livello(T->left,l-1);
}

int profonditaABR(ABRTree T, int v) {
    int depth=0;
    while(T!= NULL && T->c != v) {
        if(T->c < v)
            T = T->left;
        else T = T->right;
        depth++;
    }
    if(T == NULL) return -1;
    return depth;
}

void costruisciArrayLivello(ABRTree T, char* a, int l, int i) {
    if(T) {
        if(l==0) {
            a[i]=T->c;
            i++;
        }
        costruisciArrayLivello(T->left,a,l-1,i);
        costruisciArrayLivello(T->right,a,l-1,i);
    }
}

/* 26.11.13 */
/* ESERCIZIO 1 PSEUDOCODIFICA */
/* SPECULARI(L1,L2)
 *     temp1 = L1.head
 *     temp2 = L2.head
 *     if(temp1 == NULL && temp2 == NULL)
 *         return TRUE
 *     if((temp1 != NULL && temp2 == NULL) || (temp2 != NULL && temp1 == NULL))
 *         return FALSE
 *     while(temp1.next != NULL)
 *         temp1 = temp1.next
 *     while(temp2 == NULL || temp1 == NULL)
 *         if(temp2.info != temp1.info)
 *             return FALSE
 *         temp1 = temp1.prev
 *         temp2 = temp2.next
 *     return TRUE
 */

int indovina(parola p) {
    int i,vittoria=0,tent=10;
    char c;
    char w[strlen(p)];
    for(i=0; i<strlen(p); i++)
        w[i]='_';
    w[i]='\0';
    while(tent != 0 && !vittoria){
        int esiste = 0;
        printf("Parola attuale: %s\n",w);
        printf("Digita una lettera: ");
        scanf("%c",&c);
        printf("\n");
        for(i=0; i<strlen(w); i++)
            if(p[i]==c) {
                esiste = 1;
                w[i]=c;
            }
        if(esiste)
            printf("Giusto!\n");
        else {
            printf("Sbagliato!\n");
            tent--;
            if(tent != 0)
                printf("Hai altri %d tentativi a disposizione.\n",tent);
        }
        if(strcmp(w,p)==0)
            vittoria = 1;
    }
    if(tent == 0) {
        printf("Mi spiace hai commesso troppi errori.\n");
        return 0;
    }
    else {
        printf("Complimenti hai indovinato la parola: %s\n",w);
        return 1;
    }
}

void insParola(playersList *G, int cod, parola p) {
    int ris = indovina(p);
    int aggiorna = 0;
    if(ris == 0) return;
    playersList temp = *G;
    while(temp != NULL) {
        if(temp->info.code == cod) {
            wordList new;
            strcpy(new->info,p);
            new->next = temp->info.indovinate;
            temp->info.indovinate = new;
            temp->info.score += strlen(p);
            aggiorna = 1; 
        }
        temp = temp->next; 
    }
    if(aggiorna == 0) {
        giocatore new;
        new.code = cod;
        strcpy(new.indovinate,p);
        new.score = strlen(p);
        playersList temp;
        temp->info = new;
        temp->next = *G;
        *G = temp;
    }
}

/* 21.11.12 */
/* ESERCIZI PSEUDOCODIFICA */
/* CRESCENTE(L)
 *     temp = L.head
 *     if(temp != NULL)
 *         while(temp.next != NULL)
 *             if(temp.info > temp.next.info)
 *                 return FALSE
 *             temp = temp.next
 *     return TRUE
 */

/* INSERISCI(L,i)
 *     // new nuovo nodo
 *     new.info=i
 *     prec = NULL
 *     temp = L.head
 *     if(temp == NULL)
 *         L.head = new
 *         return
 *     while(temp != NULL && temp.info < i)
 *         prec = temp
 *         temp = temp.next
 *     if(temp.prev == NULL)
 *         new.next = L.head
 *         L.head.prev = new
 *         L.head = new
 *     else
 *         new.next = temp
 *         if(temp != NULL)
 *             temp.prev = new
 *         new.prev = prec
 */

void inserisciStudente(studentList *S) {
    studente new;
    char v;
    int voto;
    printf("Inserire la matricola: ");
    scanf("%s",new.matr);
    do {
        printf("Inserire un voto: ");
        scanf("%d",&voto);
        examList e;
        e->info = voto;
        e->next = new.esami;
        new.esami = e;
        printf("Si vuole continuare (y/n): ");
        scanf("%c",&v);
    }
    while(v == 'y');
    studentList n = (studentList)malloc(sizeof(struct insiemeStud));
    n->info = new;
    n->next = *S;
    *S=n;
}
    
int calcolaMedia(studentList S, char* m) {
    studentList temp=S;
    int cont=0,somma=0;
    while(temp != NULL) {
        if(strcmp(temp->info.matr,m)==0) {
            examList curr = temp->info.esami;
            while(curr != NULL) {
                somma += curr->info;
                cont++;
                curr = curr->next;
            }
        }
        temp = temp->next;
    }
    return somma/cont;
}

void cancellaStudenti(studentList *S, int v) {
    studentList curr = *S;
    studentList prev = NULL;
    int media,cont;
    while(curr != NULL) {
        studentList temp = curr;
        if(calcolaMedia(*S,temp->info.matr) < v) {
            if(prev == NULL)
                *S=temp->next;
            else {
                prev->next=temp->next;
                curr = temp->next;
            }
            free(temp);
        }
        else {
            prev = temp;
            temp = temp->next;
        }
    }
}

/* 08.09.10 */
/* PSEUDOCODIFICA */
/* VERIFICA-MAGGIORI(A,u)
 *     x = A[u]
 *     while x != NULL
 *         if(x.info < u)
 *             return FALSE
 *         x = x.next
 *     return TRUE
 * 
 * VERIFICA-TUTTI-MAGGIORI(A)
 *     for i=0 to A.length-1
 *         if(!VERIFICA-MAGGIORI(A,i))
 *             return FALSE
 *     return TRUE
 * 
 * RIMUOVI-ARCHI-ENTRANTI(A,u)
 *     for i=0 to A.length-1
 *         x = A[i]
 *         while (x != NULL)
 *             if(x.info == u)
 *                 if(x.next != NULL)
 *                     x.next.prev = x.prev
 *                 if(x.prev != NULL)
 *                     x.prev.next = x.next
 *                 else
 *                     A[i]=x.next
 *             x = x.next
 * 
 * CONNESSO GIA' FATTO IN CLASSE
 */              

/* 15.06.10 */
/* PSEUDOCODIFICA */
/* VERIFICA-NO-ARCHI(A)
 *     for i=0 to A.length-1
 *         if (A[i] != NULL)
 *             return FALSE
 *     return TRUE
 * 
 * VERIFICA-NODO-ISOLATO(A,u)
 *     if(A[u] != NULL)
 *         return FALSE
 *     for i=0 to A.length-1
 *         x = A[i]
 *         while(x != NULL)
 *             if(x.info == u)
 *                 return FALSE
 *             x = x.next
 *     return TRUE
 * 
 * INVERTI-ARCHI(A)
 *     B è un nuovo grafo rappresentato con liste di adicacenza, un array lungo A.length di liste dopp conc
 *     for i=0 to B.length-1
 *         A[i]=NULL
 *     for i=0 to A.length-1
 *         x = A[i]
 *         while(x!= NULL)
 *             AGGIUNGI-ARCO(B,x.info,u)
 *             x = x.next
 *     return B
 * 
 * AGGIUNGI-ARCO(B,v1,v2)
 *     temp nuovo nodo
 *     temp.info = v2
 *     temp.next = A[v1]
 *     temp.prev = NULL
 *     if(A[v1]!= NULL)
 *         A[v1].prev = temp
 *     A[v1]= temp
 * 
 * ESISTE-NODO-ISOLATO(A)
 *     for i=0 to color.length-1
 *         color[i]=0
 *     cont = 0
 *     for i=0 to A.length-1
 *         if(color[i]==0)
 *             cont++
 *             DFS(A,i,color,cont)
 *     for i=1 to cont
 *         app = 0
 *         for j=0 to color.length-1
 *             if(color[j]=i)
 *                 app++
 *         if(app == 1)
 *             return TRUE
 *     return FALSE
 * 
 * DFS(A,i,color,cont)
 *     color[i]=cont
 *     x = A[i]
 *     while x!= NULL
 *         if(color[x.info]==0)
 *             DFS(A,x.info,color,cont)
 *         x = x.next            
 */

/* 05.09.11 */
/* PSEUDOCODIFICA */
/* GRAFO-NEGATO(A)    
 *     for i=0 to M.length-1
 *         for j=0 to M[i].length-1
 * 	       M[i][j] = 0
 *     for i=0 to A.length-1	
 *         x = A[i]
 * 	   while (x!=NULL)
 * 	       M[i][x.key] = 1
 *             x = x.next
 *     B NUOVO GRAFO CON MATRICE DI ADIACENZA DI DIMENSIONI UGUALI AD A
 *     for i=0 to B.length-1
 *         for j=0 to B[i].length-1
 * 	       M[i][j] = 0
 *     for i=0 to B.length-1
 *         for j=0 to B[i].length-1
 *             if(A[i][j]==0)
 *                 B[i][j]=1
 *     return B
 */

/* 15.06.11 */
/* PSEUDOCODIFICA */
/* CONTA-RAGGIUNTI(A,u)
 *     for i=0 to color.length-1
 *         color[i]=0
 *     DFS(A,i,color,1) 
 *     for j=0 to color.length-1
 *         if(color[j]=1)
 *             app++
 *     return app
 * 
 * DFS(A,i,color,cont)
 *     color[i]=cont
 *     x = A[i]
 *     while x!= NULL
 *         if(color[x.info]==0)
 *             DFS(A,x.info,color,cont)
 *         x = x.next   
 */

/* 16.02.16 */
/* PSEUDOCODIFICA */
/* VERIFICA(A)
 *     for i=0 to A.length-1
 *         x = A[i]
 *         if(x != NULL)
 *             if(x.next == NULL)
 *                 return FALSE
 *     // B NUOVO ARRAY DI INTERI CON A.LENGTH POSIZIONI
 *     for i=0 to B.length-1
 *         B[i] = 0
 *     for i=0 to B.length-1
 *         B[A[i]] = B[A[i]]+1
 *     for i=0 to B.length-1
 *         if(B[i]==1)
 *             return FALSE
 *     return TRUE
 * 
 * VERIFICA-CICLO(A)
 *     for i=0 to color.length-1
 *         color[i]=0
 *     DFS(A,i,color) 
 *     for i=0 to color.length-1
 *         if(color[i]==0)
 *             return FALSE
 *     if(!VERIFICA(A))
 *         return FALSE
 *     return TRUE
 * 
 * DFS(A,i,color)
 *     color[i]=cont
 *     x = A[i]
 *     while x!= NULL
 *         if(color[x.info]==0)
 *             DFS(A,x.info,color,cont)
 *         x = x.next   
 */

