#include <stdio.h>

long bin_date(void);
char *str_date(long bintime);

main(int argc, char **argv) {
	long lresult; /* return from bin_date */
	char *sresult; /* return from str_date */

	if (argc != 1) {
		fprintf(stderr, "usage: %s\n", argv[0]);
		exit(1);
	}
	
	/* call the procedure bin_date */
	lresult = bin_date();
	printf("time is %ld\n", lresult);
	
	/* convert the result to a date string */
	sresult = str_date(lresult);
	printf("date is %s", sresult);
	exit(0);
} 
