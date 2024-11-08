#include <stdio.h>
#include <pthread.h>
#include "file_ops.h"
#include "metadata.h"
#include "logger.h"
#include "sync.h"
#include "compression.h"
#include "utils.h"

#define THREAD_COUNT 7

int main()
{
    pthread_t threads[THREAD_COUNT];
    const char *filename = "testfile.txt";

    init_sync();

    pthread_create(&threads[0], NULL, file_read, (void *)filename);
    pthread_create(&threads[1], NULL, file_write, (void *)filename);
    pthread_create(&threads[2], NULL, file_delete, (void *)filename);
    pthread_create(&threads[3], NULL, display_metadata, (void *)filename);
    pthread_create(&threads[4], NULL, compress_file, (void *)filename);
    pthread_create(&threads[5], NULL, decompress_file, (void *)filename);
    pthread_create(&threads[6], NULL, file_rename, (void *)filename);

    for (int i = 0; i < THREAD_COUNT; i++)
    {
        pthread_join(threads[i], NULL);
    }

    cleanup_sync();
    return 0;
}
