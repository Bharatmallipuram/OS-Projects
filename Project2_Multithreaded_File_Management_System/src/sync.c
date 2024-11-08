#include <pthread.h>
#include "sync.h"

pthread_mutex_t file_write_mutex;

void init_sync()
{
    pthread_mutex_init(&file_write_mutex, NULL);
}

void cleanup_sync()
{
    pthread_mutex_destroy(&file_write_mutex);
}
