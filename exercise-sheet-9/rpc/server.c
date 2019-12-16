/* bin_date returns the system time in binary format */
long bin_date(void) {
	long timeval;
	long time(); /* Unix time function; returns time */
	
	timeval = time((long *)0);
	return timeval;
}

/* str_date converts a binary time into a date string */
char *str_date(long bintime) {
	char *ptr;
	char *ctime(); /* Unix library function that does the work */
	
	ptr = ctime(&bintime);
	return ptr;
}
