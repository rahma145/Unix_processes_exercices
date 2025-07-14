#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include "shm_defs.h"

int main() {
    int fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, SHM_SIZE);

    shared_data_t *data = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&data->lock, &attr);

    pthread_mutex_lock(&data->lock);
    strcpy(data->buffer, "Data from producer");
    pthread_mutex_unlock(&data->lock);

    return 0;
}
