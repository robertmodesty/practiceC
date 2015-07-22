# include <stdio.h>
void main () {
	int N, N1, Cnt, Cnt1, Cnt2, Buf;
	unsigned char e [201], X [501], Out [501];

	e [0] = (unsigned char) 1;
	X [0] = (unsigned char) 1;
	for (Cnt = 1; Cnt <= 200; Cnt++) {
	  e [Cnt] = (unsigned char) 0;
	  X [Cnt] = (unsigned char) 0;
	}

	for (Cnt = 1; Cnt <= 242; Cnt++) {
	  /*X = X / Cnt;*/
	  Buf = 0;
	  for (Cnt1 = 0; Cnt1 <= 200 ; Cnt1++) {
	    Buf += (int) X [Cnt1];
	    X [Cnt1] = (unsigned char) (Buf / Cnt);
	    Buf = (Buf % Cnt) * 256;
	  }
	  /*e = e + X;*/
	  Buf = 0;
	  for (Cnt1 = 200; Cnt1 >= 0; Cnt1--) {
	    Buf /= 256;
	    Buf += (int) X [Cnt1] + (int) e [Cnt1];
	    e [Cnt1] = (unsigned char) (Buf % 256);
	  }
	}


	printf ("Input the digits in byte (1 to 180): ");
	scanf ("%d", &N);
	if (N > 180) N = 180;
	else if (N < 1) N = 1;


	printf ("e =%2x.", (int) e [0]);
	for (Cnt = 1; Cnt <= N; Cnt++) {
	  printf ("%1X", ((int) e [Cnt]) / 0x10);
	  printf ("%1X", ((int) e [Cnt]) % 0x10);
	  if ((Cnt % 5) == 0) printf (" ");
	  if ((Cnt % 25) == 0) printf ("\n      ");
	}
	printf ("\n");

	N1 = (int) ((float) N * 8. / 10. * 3.);
	for (Cnt = 0; Cnt <= 500; Cnt++) {
	  X [Cnt] = (unsigned char) 0;
	  Out [Cnt] = (unsigned char) 0;
	}
	Out [0] = e [0] + 48;
	X [1] = (unsigned char) 10;
	for (Cnt = 1; Cnt <= (N + 20); Cnt++) {
	  for (Cnt1 = 0; Cnt1 <= 7; Cnt1++) {
	    /*X = X / 2*/
	    Buf = 0;
	    for (Cnt2 = 1; Cnt2 <= (N1 + 68); Cnt2++) {
	      X [Cnt2] = (char) ((int) X [Cnt2] + Buf);
	      Buf = ((int) X [Cnt2] % 2) * 10;
	      X [Cnt2] = (char) ((int) X [Cnt2] / 2);
	    }
	    /*Out = Out + X if this bit is 1*/
	    if ((e [Cnt] & ((unsigned char) 0x80 >> Cnt1)) != '\0') {
	      Buf = 0;
	      for (Cnt2 = (N1 + 68); Cnt2 >=1; Cnt2--) {
		Buf += (int) X [Cnt2] + (int) Out [Cnt2];
		Out [Cnt2] = (char) (Buf % 10);
		Buf /= 10;
	      }
	    }
	  }
	}
	for (Cnt = 1; Cnt <= N1; Cnt++) Out [Cnt] += 48;

	printf ("e = %c.", Out [0]);
	for (Cnt = 1; Cnt <= N1; Cnt++) {
	  printf ("%c", Out [Cnt]);
	  if ((Cnt % 10) == 0) printf (" ");
	  if ((Cnt % 50) == 0) printf ("\n      ");
	}
	printf ("\n");

	}