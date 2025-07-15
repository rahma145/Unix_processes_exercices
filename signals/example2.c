#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main()
{
    int pid = fork(); 

    if (pid == -1)
    {
        return 1 ; 
    }

    if (pid == 0)
    {
        while(1)
        {
            printf ("some text from child process \n"); 
            usleep(50000);
        }   
    }
    else 
    {
        kill(pid, SIGSTOP); 
        sleep(1); 
        kill(pid, SIGCONT); 
        sleep(1); 
        kill(pid, SIGKILL); 
        wait(NULL); 
    }
    return 0; 
}