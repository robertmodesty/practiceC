# include <stdio.h>
void main () {
	int N, N1, Cnt, Cnt1, Cnt2, Bit;
	long Buf;
	unsigned char X [201], Sqr [501], Out [501];

	for (Cnt = 1; Cnt <= 200; Cnt++) X [Cnt] = '\0';
	for (Cnt = 1; Cnt <= 400; Cnt++) Sqr [Cnt] = '\0';

	X [0] = (char) 2;
	Sqr [0] = (char) 4;
	for (Cnt = 1; Cnt <= 200; Cnt++) {
	  for (Bit = 0; Bit <= 7; Bit++) {
	    /*(A+B)^2 = A^2 + 2AB + B^2)*/
	    /*+B^2*/
	    Buf = ((unsigned char) 1 << (2 * (7- Bit)));
	    for (Cnt1 = (Cnt * 2); Buf > 0; Cnt1--) {
	      Buf += (long) Sqr [Cnt1];
	      Out [Cnt1] = (unsigned char) Buf & (unsigned char) 0xff;
	      Buf >>= 8;
	    }
	    for (; Cnt1 >= 0; Cnt1--)
	      Out [Cnt1] = Sqr [Cnt1];
	    for (Cnt1 = (Cnt * 2 + 1); Cnt1 <= (Cnt + 200); Cnt1++)
	      Out [Cnt1] = Sqr [Cnt1];
	    /*2AB*/
	    Buf = 0;
	    for (Cnt1 = 200; Cnt1 >= 0; Cnt1--) {
	      Buf += (long) X [Cnt1] << (8 - Bit);
	      Buf += (long) Out [Cnt1 + Cnt];
	      Out [Cnt1 + Cnt] = (unsigned char) Buf & (unsigned char) 0xff;
	      Buf >>= 8;
	    }
	    for (Cnt1 = (Cnt - 1); /*Cnt1 >= 0*/Buf > 0; Cnt1--) {
	      Buf += (long) Out [Cnt1];
	      Out [Cnt1] = (unsigned char) Buf & (unsigned char) 0xff;
	      Buf >>= 8;
	    }
	    if (Out [0] < (char) 5) {
	      X [Cnt] += ((unsigned char) 0x80 >> Bit);
	      for (Cnt1 = 0; Cnt1 <= (Cnt + 200); Cnt1++)
		Sqr [Cnt1] = Out [Cnt1];
	    }
	  }
	}
	X [0] += 1;
	Buf = 0;
	for (Cnt = 0; Cnt <= 200; Cnt++) {
	  Buf += X [Cnt];
	  X [Cnt] = (unsigned char) (Buf >> 1);
	  Buf = (Buf & (long) 1 ) << 8;
	}



	printf ("Input the digits in byte (1 to 180): ");
	scanf ("%d", &N);
	if (N > 180) N = 180;
	else if (N < 1) N = 1;


	printf ("fai =%2x.", (int) X [0]);
	for (Cnt = 1; Cnt <= N; Cnt++) {
	  printf ("%1X", ((int) X [Cnt]) / 0x10);
	  printf ("%1X", ((int) X [Cnt]) % 0x10);
	  if ((Cnt % 5) == 0) printf (" ");
	  if ((Cnt % 25) == 0) printf ("\n        ");
	}
	printf ("\n");

	N1 = (int) ((float) N * 8. / 10. * 3.);
	for (Cnt = 0; Cnt <= 500; Cnt++) {
	  Sqr [Cnt] = (unsigned char) 0;
	  Out [Cnt] = (unsigned char) 0;
	}
	Out [0] = X [0] + 48;
	Sqr [1] = (unsigned char) 10;
	for (Cnt = 1; Cnt <= (N + 20); Cnt++) {
	  for (Cnt1 = 0; Cnt1 <= 7; Cnt1++) {
	    /*Sqr = Sqr / 2*/
	    Buf = 0;
	    for (Cnt2 = 1; Cnt2 <= (N1 + 68); Cnt2++) {
	      Sqr [Cnt2] = (char) ((int) Sqr [Cnt2] + Buf);
	      Buf = ((int) Sqr [Cnt2] % 2) * 10;
	      Sqr [Cnt2] = (char) ((int) Sqr [Cnt2] / 2);
	    }
	    /*Out = Out + Sqr if this bit is 1*/
	    if ((X [Cnt] & ((unsigned char) 0x80 >> Cnt1)) != '\0') {
	      Buf = 0;
	      for (Cnt2 = (N1 + 68); Cnt2 >=1; Cnt2--) {
		Buf += (int) Sqr [Cnt2] + (int) Out [Cnt2];
		Out [Cnt2] = (char) (Buf % 10);
		Buf /= 10;
	      }
	    }
	  }
	}
	for (Cnt = 1; Cnt <= N1; Cnt++) Out [Cnt] += 48;

	printf ("fai = %c.", Out [0]);
	for (Cnt = 1; Cnt <= N1; Cnt++) {
	  printf ("%c", Out [Cnt]);
	  if ((Cnt % 10) == 0) printf (" ");
	  if ((Cnt % 50) == 0) printf ("\n        ");
	}
	printf ("\n");

	}