# include <stdio.h>
void main () {
	unsigned char X;
	unsigned long A, B, LA, Rndm, Sh, Sk;
	int Cnt;
	char Chk (unsigned long, unsigned long);
	Rndm = 0;
	LA = 0;
	Cnt = 0;
	for (A = 0; (int)(A/16777216) < 255; A += Rndm % 150000) {
	  for (B = 1 ; (int)(B/16777216) < 255; B += Rndm) {
	    X = Chk (A, B);
	    if (X == (char) 1) return;
	    Cnt++;
	    if (A != 0) {
	      X = Chk (B, A);
	      if (X == (char) 1) return;
	      Cnt++;
	    }
	    Rndm = ((Rndm + 8456) * 364182) % 550715;
	  }
	  if ((A - LA) >= 250000) {
	    LA = (A / 250000) * 250000;
	    printf(".");
	    if (LA % 10000000 == 0) {
	      printf("# %d %2d%04d%04d\n", Cnt, (int)(A/100000000),
		     (int)(A/10000%10000), (int)(A%10000));
	      Cnt = 0;
	    }
	  }
	}

	Sh = 0xf0;
	for (A = 0; A < 0xe0000000; A = Sh) {
	  for (Sk = A + 500; A < Sk; A++) {
	    for (B = 1 ; (int)(B/16777216) < 255; B += Rndm) {
	      X = Chk (A, B);
	      if (X == (char) 1) return;
	      if (A != 0) {
		X = Chk (B, A);
		if (X == (char) 1) return;
	      }
	      Rndm = ((Rndm + 8456) * 364182) % 550715;
	    }
	    if (A % 10 == 0) printf(".");
	  }
	  printf("#%2d%04d%04d\n", (int)(A/100000000),
	      (int)(A/10000%10000), (int)(A%10000));
	  if (Sh < 0x20000000) Sh = Sh * 2 + 16;
	  else Sh += 0x20000000;
	}
	printf("OK!\n");
	}

char Chk(unsigned long A, unsigned long B) {
	unsigned long C, D, C2, D2;
	int Cnt;
	unsigned char Rtn, A1[5], B1[5], C1[5], D1[5];
	char LInt_Div (unsigned char *, unsigned char *, unsigned char *,
			unsigned  char *);

	C = A / B;
	D = A % B;

	A1[0] = (char) 4;
	B1[0] = (char) 4;
	A1[1] = (char) (A % 256);
	B1[1] = (char) (B % 256);
	A1[2] = (char) ((A / 256) % 256);
	B1[2] = (char) ((B / 256) % 256);
	A1[3] = (char) ((A / 65536) % 256);
	B1[3] = (char) ((B / 65536) % 256);
	A1[4] = (char) (A / 16777216);
	B1[4] = (char) (B / 16777216);

	LInt_Div (A1, B1, C1, D1);

	if ((int)C1[0] > 0) {
	  C2 = (long) C1[1];
	  if (C1[0] > (char) 1) C2 += (unsigned long) C1[2] * 256;
	  if (C1[0] > (char) 2) C2 += (unsigned long) C1[3] * 65536;
	  if (C1[0] > (char) 3) C2 += (unsigned long) C1[4] * 16777216; }
	else C2 = 0;
	if ((int)D1[0] > 0) {
	  D2 = (long) D1[1];
	  if (D1[0] > (char) 1) D2 += (unsigned long) D1[2] * 256;
	  if (D1[0] > (char) 2) D2 += (unsigned long) D1[3] * 65536;
	  if (D1[0] > (char) 3) D2 += (unsigned long) D1[4] * 16777216; }
	else D2 = 0;

	if (C != C2 || D != D2) {
	  printf ("\nWarning! %2d%04d%04d /", (int)(A/100000000),
		   (int)(A/10000%10000), (int)(A%10000));
	  printf(" %2d%04d%04d =", (int)(B/100000000),
		  (int)(B/10000%10000), (int)(B%10000));
	  printf(" %2d%04d%04d ..", (int)(C/100000000),
		  (int)(C/10000%10000), (int)(C%10000));
	  printf(" %2d%04d%04d but", (int)(D/100000000),
		  (int)(D/10000%10000), (int)(D%10000));
	  printf(" %2d%04d%04d ..", (int)(C2/100000000),
		  (int)(C2/10000%10000), (int)(C2%10000));
	  printf(" %2d%04d%04d\n", (int)(D2/100000000),
		  (int)(D2/10000%10000), (int)(D2%10000));
	}

	for (Cnt = (int) A1[0]; Cnt != 0 && A1[Cnt] == (char) 0; Cnt--);
	  A1[0]=(char)Cnt;
	for (Cnt = (int) B1[0]; Cnt != 0 && B1[Cnt] == (char) 0; Cnt--);
	  B1[0]=(char)Cnt;

	LInt_Div (A1, B1, C1, D1);

	if ((int)C1[0] > 0) {
	  C2 = (long) C1[1];
	  if (C1[0] > (char) 1) C2 += (unsigned long) C1[2] * 256;
	  if (C1[0] > (char) 2) C2 += (unsigned long) C1[3] * 65536;
	  if (C1[0] > (char) 3) C2 += (unsigned long) C1[4] * 16777216; }
	else C2 = 0;
	if ((int)D1[0] > 0) {
	  D2 = (long) D1[1];
	  if (D1[0] > (char) 1) D2 += (unsigned long) D1[2] * 256;
	  if (D1[0] > (char) 2) D2 += (unsigned long) D1[3] * 65536;
	  if (D1[0] > (char) 3) D2 += (unsigned long) D1[4] * 16777216; }
	else D2 = 0;

	if (C != C2 || D != D2) {
	  printf ("\nError! %2d%04d%04d /", (int)(A/100000000),
		   (int)(A/10000%10000), (int)(A%10000));
	  printf(" %2d%04d%04d =", (int)(B/100000000),
		  (int)(B/10000%10000), (int)(B%10000));
	  printf(" %2d%04d%04d ..", (int)(C/100000000),
		  (int)(C/10000%10000), (int)(C%10000));
	  printf(" %2d%04d%04d but", (int)(D/100000000),
		  (int)(D/10000%10000), (int)(D%10000));
	  printf(" %2d%04d%04d ..", (int)(C2/100000000),
		  (int)(C2/10000%10000), (int)(C2%10000));
	  printf(" %2d%04d%04d\n", (int)(D2/100000000),
		  (int)(D2/10000%10000), (int)(D2%10000));

	 return (char) 1;
       }

	return (char) 0;

	}

char LInt_Div (unsigned char *A, unsigned char *B,
		unsigned char *Quo, unsigned char *Odd) {
	unsigned char Odd1 [256], *OddA, *OddB, *Tmp, Adr [256], RtCod;
	int Cnt, Cnt1, Shft;
	unsigned int ASub, DivSub, QuoSub, BLth, OLth, QuoSubB;
	char LInt_Add (unsigned char *, unsigned char *);

	/* Find the length of B (divider). */
	for (BLth = (int) *B;
	      BLth != 0 && *(B + BLth) == (char) 0;
	       BLth--) ;
	/* Error! Divided by zero. */
	if (BLth == 0) return (char) 1;

	/* Find the length of A (dividend). */
	for (OLth = (int) *A;
	      OLth != 0 && *(A + OLth) == (char) 0;
	       OLth--) ;
	/* Initialize Quotient and Odd. */
	*Quo = (char) 0;
	for (Cnt = 1; Cnt <= OLth; Cnt++) *(Odd + Cnt) = *(A + Cnt);
	*Odd = (char) OLth;

	/* Complite dividing if length of A < length of B (in bit). */
	if ((OLth < BLth) || ((OLth == BLth) && (*(A + OLth) < *(B + BLth))))
	  return (char) 0;

	/* Point the Odd. */
	OddA = Odd;
	OddB = Odd1;

	do {
	  /* Calculite the maximum and minimum of quotient. */
	  QuoSubB = (int) *(OddA + OLth) / ((int) *(B + BLth) + 1);
	  QuoSub = (int) *(OddA + OLth) / (int) *(B + BLth);

	  /* Divide with one byte quotient. */
	  RtCod = (char) 0;
	  do {
	    /* Divide the highest byte. */
	    if (QuoSub != 0) {
	      Shft = OLth - BLth;
	      ASub = (int) *(OddA + OLth);
	      DivSub = (int) *(B + BLth) * QuoSub;
	      ASub -= DivSub;
	      ASub = (ASub & 0xff) << 8;
	    }
	    /* Number in highest byte is too less, get the second byte */
	    /* or complite dividing if Odd is not enough. */
	    else if (OLth == BLth) RtCod = (char) 2;
	    else {
	      QuoSub = ((unsigned int) *(OddA + OLth) << 8)
			 + (unsigned int) *(OddA + OLth - 1);
	      ASub = QuoSub;
	      QuoSub /= ((int) *(B + BLth) + 1);
	      Shft = OLth - BLth - 1;
	      DivSub = (int) *(B + BLth) * QuoSub;
	      ASub -= DivSub;
	      *(OddB + OLth) = (char) (ASub >> 8);
	      ASub = (ASub & 0xff) << 8;
	    }

	    /* Divide the remaining if RtCod != 2. */
	    if (RtCod == (char) 1) RtCod = (char) 0;
	    for (Cnt = BLth - 1; Cnt > 0 && RtCod == (char) 0; Cnt--) {
	      ASub += (int) *(OddA + Cnt + Shft);
	      DivSub = (int) *(B + Cnt) * QuoSub;
	      /* Divide if the Odd is still enough. */
	      if (ASub >= DivSub) {
		ASub -= DivSub;
		*(OddB + Cnt + Shft + 1) = (char) (ASub >> 8);
		ASub = (ASub & 0xff) << 8;
	      }
	      /* Sub number not enough, get from high byte. */
	      else {
		for (Cnt1 = Cnt + Shft + 2;
		      Cnt1 <= OLth && *(OddB + Cnt1) == (char) 0;
		       Cnt1++) ;
		if (Cnt1 <= OLth) {
		  *(OddB + Cnt1) -= 1;
		  for (Cnt1-- ; Cnt1 >= Cnt + Shft + 2; Cnt1--)
		    *(OddB + Cnt1) = (char) 0xff ;
		  ASub += (0xffff - DivSub) + 1;
		  *(OddB + Cnt1) = (char) (ASub >> 8);
		  ASub = (ASub & 0xff) << 8;
		}
		/* Odd is too less, decress the maximum of quotient. */
		else {
		  QuoSub -= (QuoSub - QuoSubB + 1) >> 1;
		  RtCod = (char) 1;
		}
	      }
	    }

	    /* If one byte diveding complite normally, correct the Odd. */
	    if (RtCod == (char) 0) {
	      *(OddB + Shft + 1) = (char) (ASub >> 8);

	      /* Copy the part of Odd that been or did not divided. */
	      if (((int) OddA - Shft) <= Shft) {
		for (Cnt = Shft; Cnt >= 0; Cnt--)
		  *(OddB + Cnt) = *(OddA + Cnt);
		Tmp = OddB;
		OddB = OddA;
		OddA = Tmp; }
	      else
		for (Cnt = (int) *OddA; Cnt > Shft; Cnt--)
		  *(OddA + Cnt) = *(OddB + Cnt);

	      /* Correct the length. */
	      for (OLth = (int) *OddA;
		    OLth != 0 && *(OddA + OLth) == (char) 0;
		     OLth--) ;
	      *OddA = (char) OLth;

	      /* Add the one byte quotient into Quotient.*/
	      Adr [0] = Shft + 1;
	      for (Cnt = 1; Cnt <= Shft; Cnt++) Adr [Cnt] = (char) 0;
	      Adr [Cnt] = QuoSub;
	      LInt_Add (Quo, Adr);

	      /* Complite dividing if Odd is too less. */
	      if (OLth >= BLth) RtCod = (char) 0;
	      else RtCod = (char) 2; }
	  } while (RtCod == (char) 1);
	} while (RtCod == (char) 0);

	if (OddB == Odd) for (Cnt = 0; Cnt <= (int) *OddA; Cnt++)
	    *(Odd + Cnt) = *(OddA + Cnt);
	return (char) 0;
	}

char LInt_Div2 (unsigned char *A, unsigned char *B,
		unsigned char *Quo, unsigned char *Odd) {
	unsigned char Odd1 [256], Odd2[256], *OddA, *OddB, *Tmp, RtCod;
	int Cnt, Cnt1, Shft;
	unsigned int OSub, DivSub, QuoSub, BLth, OLth, QuoSubB;
	char LInt_Add (unsigned char *, unsigned char *);

	/* Find the length of B (divider). */
	for (BLth = (int) *B;
	      BLth != 0 && *(B + BLth) == (char) 0;
	       BLth--) ;
	/* Error! Divided by zero. */
	if (BLth == 0) {
	  *Odd = (char) 0;
	  *Quo = (char) 0;
	  return (char) 1;
	}

	/* Find the length of A (dividend). */
	for (OLth = (int) *A;
	      OLth != 0 && *(A + OLth) == (char) 0;
	       OLth--) ;
	/* Initialize Quotient and Odd. */
	*Quo = (char) 0;
	for (Cnt = 1; Cnt <= OLth; Cnt++) *(Odd + Cnt) = *(A + Cnt);
	Odd1 [0] = (char) OLth;

	/* Complite dividing if length of A < length of B (in bit). */
	if ((OLth < BLth) ||
	    ((OLth == BLth) && (*(A + OLth) < *(B + BLth)))) {
	  for (Cnt = 0; Cnt <= OLth; Cnt++) *(Odd + Cnt) = Odd1 [Cnt];
	  return (char) 0;
	}

	/* Point the Odd. */
	OddA = Odd1;
	OddB = Odd2;

	do {
	  /* Calculite the maximum and minimum of quotient. */
	  QuoSubB = (int) *(OddA + OLth) / ((int) *(B + BLth) + 1);
	  QuoSub = (int) *(OddA + OLth) / (int) *(B + BLth);

	  /* Divide with one byte quotient. */
	  RtCod = (char) 0;
	  do {
	    /* Divide the highest byte. */
	    if (QuoSub != 0) {
	      Shft = OLth - BLth;
	      OSub = (int) *(OddA + OLth);
	      DivSub = (int) *(B + BLth) * QuoSub;
	      OSub -= DivSub;
	      OSub <<= 8;
	    }
	    /* Number in highest byte is too less, get the second byte */
	    /* or complite dividing if Odd is not enough. */
	    else if (OLth == BLth) RtCod = (char) 2;
	    else {
	      QuoSub = (int) *(unsigned short *) (OddA + OLth - 1);
	      OSub = QuoSub;
	      QuoSub /= ((int) *(B + BLth) + 1);
	      Shft = OLth - BLth - 1;
	      DivSub = (int) *(B + BLth) * QuoSub;
	      OSub -= DivSub;
	      *(OddB + OLth) = (char) (OSub >> 8);
	      OSub = (OSub & 0xff) << 8;
	    }

	    /* Divide the remaining if RtCod != 2. */
	    if (RtCod == (char) 1) RtCod = (char) 0;
	    for (Cnt = BLth - 1; Cnt > 0 && RtCod == (char) 0; Cnt--) {
	      OSub += (int) *(OddA + Cnt + Shft);
	      DivSub = (int) *(B + Cnt) * QuoSub;
	      /* Divide if the Odd is still enough. */
	      if (OSub >= DivSub) {
		OSub -= DivSub;
		*(OddB + Cnt + Shft + 1) = (char) (OSub >> 8);
		OSub = (OSub & 0xff) << 8;
	      }
	      /* Sub number not enough, get from high byte. */
	      else {
		for (Cnt1 = Cnt + Shft + 2;
		      Cnt1 <= OLth && *(OddB + Cnt1) == (char) 0;
		       Cnt1++) ;
		if (Cnt1 <= OLth) {
		  *(OddB + Cnt1) -= 1;
		  for (Cnt1-- ; Cnt1 >= Cnt + Shft + 2; Cnt1--)
		    *(OddB + Cnt1) = (char) 0xff ;
		  OSub += (0xffff - DivSub) + 1;
		  *(OddB + Cnt1) = (char) (OSub >> 8);
		  OSub = (OSub & 0xff) << 8;
		}
		/* Odd is too less, decress the maximum of quotient. */
		else {
		  QuoSub -= (QuoSub - QuoSubB + 1) >> 1;
		  RtCod = (char) 1;
		}
	      }
	    }

	    /* If one byte diveding complite normally, correct the Odd. */
	    if (RtCod == (char) 0) {
	      *(OddB + Shft + 1) = (char) (OSub >> 8);

	      /* Copy the part of Odd that been or did not divided. */
	      if (((int) OddA - Shft) <= Shft) {
		for (Cnt = Shft; Cnt >= 0; Cnt--)
		  *(OddB + Cnt) = *(OddA + Cnt);
		Tmp = OddB;
		OddB = OddA;
		OddA = Tmp; }
	      else
		for (Cnt = (int) *OddA; Cnt > Shft; Cnt--)
		  *(OddA + Cnt) = *(OddB + Cnt);

	      /* Correct the length. */
	      for (OLth = (int) *OddA;
		    OLth != 0 && *(OddA + OLth) == (char) 0;
		     OLth--) ;
	      *OddA = (char) OLth;

	      /* Add the one byte quotient into Quotient.*/
	      *OddB = (char) (Shft + 1);
	      for (Cnt = 1; Cnt <= Shft; Cnt++) *(OddB + Cnt) = (char) 0;
	      *(OddB + Cnt) = QuoSub;
	      LInt_Add (Quo, OddB);

	      /* Complite dividing if Odd is too less. */
	      if (OLth >= BLth) RtCod = (char) 0;
	      else RtCod = (char) 2; }
	  } while (RtCod == (char) 1);
	} while (RtCod == (char) 0);

	for (Cnt = 0; Cnt <= OLth; Cnt++) *(Odd + Cnt) = *(OddA + Cnt);
	return (char) 0;
	}

char LInt_Add (unsigned char *X1, unsigned char *X2) {
	int X1Sub, Cnt, BigLth, SmlLth;

	if (*X1 < *X2) {
	  for (Cnt = (int) *X1 + 1; Cnt <= (int) *X2; Cnt++)
	    *(X1 + Cnt) = (char) 0;
	  *X1 = *X2; }

	X1Sub = 0;
	for (Cnt = 1; Cnt <= (int) *X2; Cnt++) {
	  X1Sub += (int) *(X1 + Cnt);
	  X1Sub += (int) *(X2 + Cnt);
	  *(X1 + Cnt) = (char) (X1Sub & 255);
	  X1Sub >>= 8; }
	for (; Cnt <= (int) *X1; Cnt++) {
	  X1Sub += (int) *(X1 + Cnt);
	  *(X1 + Cnt) = (char) (X1Sub & 255);
	  X1Sub >>= 8; }

	if (Cnt < 256 && X1Sub != 0) {
	  *(X1 + Cnt) = (char) X1Sub;
	  (*X1)++;
	  return ((char) 0); }
	else
	  return ((char) X1Sub);
	}
