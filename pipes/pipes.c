#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fd[2]; // fd[0] - read end, fd[1] - write end
    pid_t pid;
    char buffer[100];

    if (pipe(fd) == -1) {
        perror("An error occurred when opening the pipe \n");
        return 1;
    }

    pid = fork();
    if (pid < 0) {
        perror("An error occurred with fork() \n");
        return 1;
    }

    if (pid > 0) {
        // Parent process
        int x; 
        close(fd[0]); // Close unused read end
        printf("Input a number : "); 
        scanf("%d", &x); 
        if(write(fd[1], &x, sizeof(int)) == -1)
        {
            printf("An error occurred when writting in the pipe \n"); 
            return 1; 
        }
        close(fd[1]); // Close write end after writing
        wait(NULL);   // Wait for child to finish
    } else {
        // Child process
        int y; 
        close(fd[1]); // Close unused write end
        if (read(fd[0], &y, sizeof(int)) == -1)
        {
            printf("An error occurred when reading from the pipe \n"); 
            return 1;
        }
        printf("Child received: %d\n", y);
        close(fd[0]); // Close read end after reading
    }

    return 0;
}
