#include <unistd.h>
#include <stdio.h>

int main()
{
    int id = fork(); 
    if (id == 0)
    {
        printf("Hello from the child process, ID = %d \n", id); 
    }
    else
    {
        printf("Hello from the main process, ID = %d \n", id); 
    }

    return 0; 
}