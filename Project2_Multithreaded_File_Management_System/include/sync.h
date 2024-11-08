#ifndef SYNC_H
#define SYNC_H

#include <pthread.h>

extern pthread_mutex_t file_write_mutex;

void init_sync();
void cleanup_sync();

#endif
