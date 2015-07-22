# include <stdio.h>
void main () {
	unsigned int N = 1, Cnt;
	double e = 1, X = 1;

	printf ("Input N: ");
	scanf ("%d", &N);

	for (Cnt = 1; Cnt <= N; Cnt++) {
	  X = X / Cnt;
	  e = e + X;
	}

	printf ("e = %.20f\n", e);

	}