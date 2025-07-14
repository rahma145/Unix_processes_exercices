#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    const char *name = "/my_shm";
    const int SIZE = 4096;

    int shm_fd = shm_open(name, O_RDONLY, 0666);
    void *ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

    printf("Received: %s\n", (char *)ptr);
    return 0;
}
