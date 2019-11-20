/* A simple readers/writers program using a one-word shared memory. */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#define SIZE sizeof(int)		/* size of [int] integer */
#define run_length 10			/* number of iterations in test run */



int main(void) {
	pid_t pid;			/* variable to record process id of child */
	caddr_t shared_memory;		/* shared memory base address */
	caddr_t shared_switch;		/* shared switch base address -> 0 = child, 1 = parent*/
	int i_parent, i_child;		/* index variables */
	int value;			/* value read by child */
	
	/* set up shared memory segments */
	shared_memory=mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
	shared_switch=mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
	*shared_switch=1; /* parent begins */
	
	if ((shared_memory == (caddr_t) -1)||(shared_switch == (caddr_t) -1)) {
		perror ("error in mmap while allocating shared memory\n"); exit (1);
	}
	
	if ((pid = fork()) < 0) { /* apply fork and check for error */
		perror ("error in fork");
		exit (1);
	}
	
	if (pid == 0) { /* child process */
		printf ("The child process begins.\n");
		
		for (i_child = 0; i_child < run_length; i_child++) {
			while (*shared_switch==1)
			{
				sleep(1); /* wait for memory to be updated */
			}
			*shared_switch=0; /* child runs */
			value = *shared_memory;
			printf ("Children's report: current value = %2d\n", value);
			*shared_switch=1; /* child finished */
		}
	
		printf ("The child is done\n"); }
	else { /* parent process */
		printf ("The parent process begins.\n");
		for (i_parent = 0; i_parent < run_length; i_parent++) {
			while (*shared_switch==0)
			{
				sleep(1); /* wait for memory to be updated */		
			}
			*shared_switch=1; /* parent runs */
			*shared_memory = i_parent * i_parent;/* square into shared memory */
			printf ("Parent's report: current index = %2d\n", i_parent );
			*shared_switch=0; /* parent finished */
		}
		wait(pid);
		printf ("The parent is done\n");
	}
	exit (0);
}