/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include "esercizi.h"

#define N 5

void selectionSort() {
	int a[N];
	int i,j,min,temp;

	/* array creato da input */
	for(i=0; i<N; i++)
		scanf("%d", &a[i]);

	/* ordinamento */
	for(i=0; i<N-1; i++) {
		min = i;
		for(j=i+1; j<N; j++)
			if(a[min] > a[j])
				min = j;
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}

}

