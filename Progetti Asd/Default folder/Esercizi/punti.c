#include <stdio.h>
#include <math.h>
#include "esercizi.h"

#define N 5

void gestionePunti() {

	int i;

	/* definizione dell'insieme e inizializzazione */
	printf("Definisci ogni punto dell'insieme \n");
	for(i=0; i<N; i++) {
		printf("%d°\n",i+1);
		printf("Inserisci le coordinate");
		scanf("%lf %lf", &a[i].x, &a[i].y);
	}

	/* stampa elementi */
	stampaElementi(a);
	/* punto medio */
	struct punto m = puntoMedio(a[0],a[1]);
	printf("Coordinate punto medio: (%lf; %lf)\n", m.x, m.y);
	/* distanza tra due punti */
	printf("Distanza tra due punti: %lf\n", distanza(a[0],a[1]));
	/* quadrante di appartenenza */
	printf("Quadrante di appartenenza: %d\n", quadrante(a[0]));
	/* quanti punti nel quadrante indicato */
	printf("Punti appartenenti al primo quadrante: %d\n", contatore(a,1));

}

void stampaElementi(struct punto a[]) {
	int i;
	for(i=0; i<N; i++)
		printf("%d° : (%lf; %lf)\n", i+1, a[i].x, a[i].y);
}

struct punto puntoMedio(struct punto p1, struct punto p2) {

	struct punto m;
	m.x = (p1.x + p2.x)/2;
	m.y = (p1.y + p2.y)/2;

	return m;
}

double distanza(struct punto p1, struct punto p2) {

	double d;

	d = sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));

	return d;
}

int quadrante(struct punto p) {

	int q;

	if(p.x > 0 && p.y > 0)
		q = 1;
	if(p.x < 0 && p.y > 0)
		q = 2;
	if(p.x < 0 && p.y < 0)
		q = 3;
	if(p.x > 0 && p.y < 0)
	    q = 4;

	return q;
}

int contatore(struct punto a[], int q) {

	int cont=0,i;
	for(i=0; i<N; i++)
		if(quadrante(a[i]) == q)
			cont++;

	return cont;
}
