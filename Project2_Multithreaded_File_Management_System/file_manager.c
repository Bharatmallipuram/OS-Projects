// file_manager.c
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include "file_operations.c"
#include <unistd.h>
#include <wait.h>

sem_t file_semaphore;
sem_t read_lock;

int read_count = 0;

void* perform_operations(void* args) {

    int choice = (*(int*)args);

    const char* filename = "example.txt";

    if (choice == 2){
        // Writing to the file
        sem_wait(&file_semaphore);  // Enter critical section
        write_file(filename);
        sleep(1);
        sem_post(&file_semaphore);  // Leave critical section
    }
    
    else if (choice == 1){
        // Reading from the file
        sem_wait(&read_lock);
        read_count++;
        if (read_count == 1){
            sem_wait(&file_semaphore);
        }
        sem_post(&read_lock);
        
        read_file(filename);

        read_count--;
        if (read_count == 0){
            sem_post(&file_semaphore);
        }
        sem_post(&read_lock);
    }

    else if (choice == 4){
        // Renaming the file
        sem_wait(&file_semaphore);
        rename_file();
        sem_post(&file_semaphore);
    }
    
    else if (choice == 6){
        display_metadata(renamed_filename);
    }
    
    else if (choice == 3){
        // Copying the file
        sem_wait(&file_semaphore);
        copy_file(filename);
        sem_post(&file_semaphore);
    }
    
    else if (choice == 5){
        // Deleting the copied file
        sem_wait(&file_semaphore);
        delete_file(copy_filename);
        sem_post(&file_semaphore);
    }

    return NULL;
}
