#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    fork();
    printf("Process ID: %d\n", getpid());
    return 0;
}