/* Adapted from https://samate.nist.gov/SARD/test-cases/841/versions/1.0.0
   Part of https://samate.nist.gov/SARD/test-suites/81
   See:
     Black, P. , Koo, H. and Irish, T. (2013), A Basic CWE-121 Buffer Overflow Effectiveness Test Suite, Proc. 6th Latin-American Symposium on Dependable Computing, Rio de Janeiro, -1, [online], https://tsapps.nist.gov/publication/get_pdf.cfm?pub_id=913117 (Accessed January 17, 2023)
*/

/* Taxonomy Classification: 0000300602130000031110 */

/*
 *  WRITE/READ               	 0	write
 *  WHICH BOUND              	 0	upper
 *  DATA TYPE                	 0	char
 *  MEMORY LOCATION          	 0	stack
 *  SCOPE                    	 3	inter-file/inter-proc
 *  CONTAINER                	 0	no
 *  POINTER                  	 0	no
 *  INDEX COMPLEXITY         	 6	N/A
 *  ADDRESS COMPLEXITY       	 0	constant
 *  LENGTH COMPLEXITY        	 2	constant
 *  ADDRESS ALIAS            	 1	yes, one level
 *  INDEX ALIAS              	 3	N/A
 *  LOCAL CONTROL FLOW       	 0	none
 *  SECONDARY CONTROL FLOW   	 0	none
 *  LOOP STRUCTURE           	 0	no
 *  LOOP COMPLEXITY          	 0	N/A
 *  ASYNCHRONY               	 0	no
 *  TAINT                    	 3	file read
 *  RUNTIME ENV. DEPENDENCE  	 1	yes
 *  MAGNITUDE                	 1	1 byte
 *  CONTINUOUS/DISCRETE      	 1	continuous
 *  SIGNEDNESS               	 0	no
 */

/*
Copyright 2004 M.I.T.

Permission is hereby granted, without written agreement or royalty fee, to use, 
copy, modify, and distribute this software and its documentation for any 
purpose, provided that the above copyright notice and the following three 
paragraphs appear in all copies of this software.

IN NO EVENT SHALL M.I.T. BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT, SPECIAL, 
INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT OF THE USE OF THIS SOFTWARE 
AND ITS DOCUMENTATION, EVEN IF M.I.T. HAS BEEN ADVISED OF THE POSSIBILITY OF 
SUCH DAMANGE.

M.I.T. SPECIFICALLY DISCLAIMS ANY WARRANTIES INCLUDING, BUT NOT LIMITED TO 
THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, 
AND NON-INFRINGEMENT.

THE SOFTWARE IS PROVIDED ON AN "AS-IS" BASIS AND M.I.T. HAS NO OBLIGATION TO 
PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
*/

#include <assert.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  FILE * f;
  char buf[10];

  f = fopen("TestInputFile1", "r");
  assert(f != NULL);

  /*  BAD  */
  fgets(buf, 11, f); /* { dg-warning "stack-based buffer overflow" "PR analyzer/105895" { xfail *-*-* } } */

  fclose(f);


  return 0;
}
