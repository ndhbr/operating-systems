#include <stdio.h>
#include <signal.h>

void test(int a) {
    printf("Test\n");
}

int main(int argc, char* argv[]) {
    //signal(SIGINT, test);
    signal(SIGINT, SIG_DFL);

    while(1);

    return 0;
}
