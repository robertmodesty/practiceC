# include <stdio.h>
# include <time.h>
void main () {
	int Cnt;
	long N = 0, X, O, Y, Z;
	unsigned char str [80];
	time_t T1, T2;
	struct tm *tm;

	printf ("How many number do you like? ");
	scanf ("%s", str);
	printf ("\n");
	for (Cnt = 0; (48 > str [Cnt]) || (57 < str [Cnt]); Cnt++);
	for (; (48 <= str [Cnt]) && (57 >= str [Cnt]); Cnt++) {
	  N *= 10;
	  N += (str [Cnt] - 48);
	}

	T1 = time (NULL);
	for (X = 1; X <= N; X++) {
	  O = 0;
	  Y = 1;
	  Z = X / Y;
	  for (; Y <= Z;) {
	    if (X % Y == 0) {
	      if (Z != Y) O += Z;
	      O += Y;
	    }
	    Y++;
	    Z = X / Y;
	  }
	  if (O == (2 * X)) {
	    O = X;
	    for (Cnt = 0; O > 0; Cnt++) {
	      str [Cnt] = O % 10 + 48;
	      O /= 10;
	    }
	    for (; Cnt > 0; Cnt--) putchar (str [Cnt - 1]);
	    printf ("\n");
	  }
	}
	T2 = time (NULL);
	tm = localtime (&T1);
	O = 0;
	O = (*tm).tm_mday * 24;
	O = (O + (*tm).tm_hour) * 60;
	O = (O + (*tm).tm_min) * 60;
	O += (*tm).tm_sec;
	tm = localtime (&T2);
	Z = 0;
	Z = (*tm).tm_mday * 24;
	Z = (Z + (*tm).tm_hour) * 60;
	Z = (Z + (*tm).tm_min) * 60;
	Z += (*tm).tm_sec;
	Z -= O;
	printf ("Use %d second.\n", Z);
	}
