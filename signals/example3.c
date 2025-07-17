#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int x; 

void handle_sigusr1(int sig)
{
    if (x==0)
        printf("\n (HINT) Remember ... \n"); 
}

int main()
{
    int pid = fork(); 

    if (pid == -1)
    {
        return 1; 
    }

    if (pid == 0)
    {
        sleep(5); 
        kill(getppid(), SIGUSR1); 
    }
    else
    {
        struct sigaction sa;
        sa.sa_flags = SA_RESTART; 
        sa.sa_handler = &handle_sigusr1; 

        sigaction(SIGUSR1, &sa, NULL); 

        printf("3*5 = ? : \n"); 
        scanf("%d", &x); 
        if (x == 15)
        {
            printf("Right \n"); 
        }
        else{
            printf("Wrong \n"); 
        }

        wait(NULL); 
    }

    return 0 ; 
}