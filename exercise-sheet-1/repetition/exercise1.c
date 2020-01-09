#include <stdio.h>
#include <signal.h>

typedef void (*sig_t) (int);

int main(int argc, char **argv)
{
	signal(SIGINT, SIG_IGN);

	while(1);

	return 1;
}

void dontStop()
{
	printf("I won't stop haha!");
}
