#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include "shm_defs.h"

int main() {
    int fd = shm_open(SHM_NAME, O_RDWR, 0666);
    shared_data_t *data = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    pthread_mutex_lock(&data->lock);
    printf("Received: %s\n", data->buffer);
    pthread_mutex_unlock(&data->lock);

    return 0;
}
