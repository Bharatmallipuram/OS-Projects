// main.c
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include "file_manager.c"

sem_t file_semaphore, read_lock;

// Main function to initialize semaphore and start threads
int main() {
    int choice = 0, run = 1;
    // Initialize the semaphore with 1, to allow only one thread at a time
    if (sem_init(&file_semaphore, 0, 1) != 0) {
        printf("Semaphore initialization failed.\n");
        return 1;
    }

    if (sem_init(&read_lock, 0, 5) != 0) {
        printf("Semaphore initialization failed.\n");
        return 1;
    }

    while(run){

        printf("\nMenu: \n");
        printf("1. Concurrent File Reading.\n2. Exclusive File Writing.\n3. File Copying.\n4. File Renaming.\n5. File Deletion.\n6. File Metadata Display.\n7. Compression.\n8. Decompression\n0. Exit\n");

        printf("\nEnter the Choice: ");
        scanf("%d", &choice);
        
        if (choice == 0) {
                printf("\nExiting.....Bye Bye\n");  
                run = 0;  
                break;
        }
        else if (choice > -1 && choice < 9){
                pthread_t threads[5];

            for (int i = 0; i < 5; i++) {
                if (pthread_create(&threads[i], NULL, perform_operations, &choice) != 0) {
                    printf("Failed to create thread.\n");
                    return 1;
                }
            }

            for (int i = 0; i < 5; i++) {
                pthread_join(threads[i], NULL);
            }
        }
        else{
            printf("Please Enter the Valid Choice.\n");
        }
        
    }
}
    
    
    

