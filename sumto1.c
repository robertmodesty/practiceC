#include <stdio.h>
#include "permut.c"

char chk_eqn (char *seqnc);
char next_sequence (char *seqnc);
char jump (char *seqnc);

int main (void) {
    char seqnc [10] = {9, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char typ_out [24] = "0/00 + 0/00 + 0/00 = 1\n";
    int cnt, plc;

    printf ("       *******************************************\n");
    printf ("       *    ?      ?      ?                      *\n");
    printf ("       *  ---- + ---- + ---- = 1                 *\n");
    printf ("       *   ??     ??     ??                      *\n");
    printf ("       *    Find out the number behind           *\n");
    printf ("       *       every question mark. They         *\n");
    printf ("       *         are 1 to 9, and all different!  *\n");
    printf ("       *******************************************\n");
    
    do {
      if (chk_eqn (seqnc)) {
        for (cnt = 3; cnt > 0; cnt--) {
            plc = (cnt - 1) * 7;
	    typ_out [plc] = seqnc [cnt + 6] + '0';
	    typ_out [plc + 3] = seqnc [cnt * 2] + '0';
	    typ_out [plc + 2] = seqnc [cnt * 2 - 1] + '0';
	}
	printf ("\n");
	printf (typ_out);
      }

      next_sequence (seqnc);
    } while (jump (seqnc) == 0);

    return 0;
}


char chk_eqn (char *seqnc) {
     int demon [3], cnt;
     long mdemon = 1, tnumr = 0;

     for (cnt = 0; cnt < 3; cnt++)
	demon [cnt] = *(seqnc + cnt * 2 + 1) * 10
		    + *(seqnc + cnt * 2 + 2);

     for (cnt = 0; cnt < 3; cnt++) mdemon *= (long) demon [cnt];
     for (cnt = 0; cnt < 3; cnt++)
	tnumr += mdemon / demon [cnt] * *(seqnc + 7 + cnt);

     return (tnumr == mdemon);
}


char jump (char *seqnc) {
     char *ptr7, *ptr8, *ptr9, cnt;

     ptr7 = seqnc + 7;
     ptr8 = ptr7 + 1;
     ptr9 = ptr8 + 1;
     if (*ptr7 > *ptr8) {
       if (*ptr8 > 1) *ptr7 = *ptr8 - 1;
       else if (*ptr9 > 3) {
	 (*ptr9)--;
	 *ptr8 = *ptr9 - 1;
	 *ptr7 = *ptr8 - 1; }
       else return (1);

       ptr7--;
       for (cnt = 9; cnt > 0; cnt--) {
	  if (cnt != *ptr9) {
	    *ptr7 = cnt;
	    ptr7--; }
	  else ptr9--;
       }
     }
     return (0);
}