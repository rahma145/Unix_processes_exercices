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
        sleep(1); 
        // send a signal to the child process
        kill(pid, SIGKILL); 
        wait(NULL); 
    }
    return 0; 
}