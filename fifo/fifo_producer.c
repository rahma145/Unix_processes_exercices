#include <stdlib.h>
#include <stdio.h>
#include <errno.h> 
#include <sys/fcntl.h>
#include <sys/stat.h>		
#include <unistd.h>

int main()
{
    if (mkfifo("fifo_file", 0777) == -1)
    {
        if(errno != EEXIST)  
        {
            perror("Could not create fifo file");  
            return 1; 
        }
    }

    printf("Opening...\n"); 
    int fd = open("fifo_file", O_WRONLY); // The code will hangs here if there is no reading processor
    printf("Opened \n"); // Once the a reading processor opens the file, this line will be executed

    int x = 'Z'; 
    if (write(fd, &x, sizeof(x)) == -1)
    {
        perror("Write failed");
        return 2; 
    }

    printf("Written \n"); 
    close(fd); 
    printf("Closed \n"); 

    return 0; 
}
