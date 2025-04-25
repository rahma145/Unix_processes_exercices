#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        // Parent process
        wait(NULL);  // Wait for the child process to terminate
        printf("Parent: Child process has finished.\n");
    } else if (pid == 0) {
        // Child process
        printf("Child: Running and now exiting.\n");
    } else {
        // Fork failed
        perror("fork failed");
        return 1;
    }

    return 0;
}