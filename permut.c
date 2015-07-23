/*------------------------------------------------------------------\
|                                                                   |
|                     PERMUTING   FUNCTION                          |
|                                                  by Robert D. Wei |
|                                                        2002/12/20 |
| Input:                                                            |
|        A character pointer points to a character sequence with a  |
|       variable length data structure as:                          |
|          struct {                                                 |
|              char number_of_terms;                                |
|              char 1st_term;                                       |
|              char 2nd_term;                                       |
|              char 3rd_term;                                       |
|                    |                                              |
|              char (number_of_terms)th_term;                       |
|          }                                                        |
|                                                                   |
| Function:                                                         |
|         Permute the input sequence to a new combination. Feeding  |
|        the privious resopnse back repeatedly will go through all  |
|        different combination of those terms cyclically.           |
|                                                                   |
| Output:                                                           |
|        0: normal, sequence converted to next one.                 |
|        1: check pinot, input sequence is decreasing, and be       |
|           converted into increasing combination.                  |
|        2: error, empty sequence.                                  |
\------------------------------------------------------------------*/
char next_sequence (char *seqnc) {
     char *chk, *start, *end, *exg1, *exg2, exg_bfr;

     /* Skip empty data and return 2.*/
     if (*seqnc == 0) return (2);

     /* Find the frunt decreasing partial sequence. */
     start = seqnc + 1;
     end = seqnc + *seqnc;
     for (chk = start; (chk < end) && (*chk >= *(chk + 1)); chk++);

     /* Turn the partial sequence into increasing.*/
     exg1 = start;
     for (exg2 = chk; exg1 < exg2; exg2--) {
       exg_bfr = *exg1;
       *exg1 = *exg2;
       *exg2 = exg_bfr;
       exg1++;
     }

     /* Decrease the term next to the partial sequence.*/
     if (chk < end) {
       for (exg1 = chk++; *exg1 >= *chk; exg1--);
       exg_bfr = *exg1;
       *exg1 = *chk;
       *chk = exg_bfr;

       return (0);
     }

     /* The whole sequence is decreasing, return 1. */
     else return (1);
}