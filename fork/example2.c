#include <unistd.h>
#include <stdio.h>

int main()
{
    int id = fork(); 
    printf("current ID : %d, parent ID : %d \n", getpid(), getppid()); 
    return 0; 
}