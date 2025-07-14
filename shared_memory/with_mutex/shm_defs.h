#ifndef SHM_DEFS_H
#define SHM_DEFS_H

#include <pthread.h>

typedef struct {
    pthread_mutex_t lock;
    char buffer[256];
} shared_data_t;

#define SHM_NAME "/my_shared_mem"
#define SHM_SIZE sizeof(shared_data_t)

#endif // SHM_DEFS_H
