#include <stdio.h>
#define MAX 10
#define TRUE 1
#define FALSE 0

/* prove su array e sugli elementi non esitenti */
void provaArray() {

	int a[4];
	a[0]=1;
	a[1]=2;
	int i;
	for(i=0; i<9; i++) // non c'e' controllo sugli elementi non esitenti
		printf("%d ",a[i]);
}

/* programmi per uso di array */
void leggiVettore(int a[MAX], int n) {
	int i;
    for (i = 0;i < n;i++) scanf("%d",&a[i]);
}

void scriviVettore(int a[MAX], int n) {
	int i;
    for (i = 0;i < n;i++) printf("%d\t",a[i]);
    printf("\n");
}

void copia(int a[], int b[], int n) {
	int i;
	for (i = 0; i < n; i++) a[i] = b[i];
}

int cerca(int x, int a[MAX], int n) {
	int i=0, trovato=FALSE;
	while ((i < n) && (!trovato))
    if (x == a[i]) trovato=TRUE;
    else i++;
    return trovato;
}



