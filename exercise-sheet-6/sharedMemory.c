#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid; /* variable to record process id of child */
    char *shared_memory; /* shared memory base address */
    char *shared_switch;
    int i_parent, i_child; /* index variables */
    int value; /* value read by child */
    
    shared_memory = mmap(0, sizeof(int), PROT_READ | PROT_WRITE,
        MAP_ANONYMOUS | MAP_SHARED, -1, 0);
    shared_switch = mmap(0, sizeof(int), PROT_READ | PROT_WRITE,
        MAP_ANONYMOUS | MAP_SHARED, -1, 0);

    if (shared_memory == (char *)-1) {
        fprintf(stderr, "%s\n", strerror(errno)); 
        return errno;
    }

    if ((pid = fork()) < 0) { /* apply fork and check for error */
        fprintf(stderr, "%s\n", strerror(errno));
        return errno;
    }

    *shared_switch = 1;

    if (0 == pid) { /* child process */
        printf ("The␣child␣process␣begins.\n");
        
        for (i_child = 0; i_child < 10; i_child++) {
            while (*shared_switch == 1)
                sleep(1);

            *shared_switch = 0;
            value = *shared_memory;
            
            printf("Child’s␣report:␣current␣value␣=␣%2d\n", value);
            *shared_switch = 1;
        } 
        
        printf("The␣child␣is␣done\n");
    } else { /* parent process */
        int childExitStatus;
        printf("The␣parent␣process␣begins.\n");
        
        for (i_parent = 0; i_parent < 10; i_parent++) {
            while (*shared_switch == 0)
                sleep(1);

            *shared_switch = 1;
            /* write into shared memory */
            *shared_memory = i_parent * i_parent;
            printf("Parent’s␣report:␣current␣index␣=␣%2d\n", i_parent );
            
            *shared_switch = 0;
        }

        wait(&childExitStatus);        
        printf("The␣parent␣is␣done\n");
    } 

    return 0;
}