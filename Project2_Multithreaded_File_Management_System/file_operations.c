// file_operations.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <pthread.h>
#include "log_operations.c"

// Write data to a file
void write_file(const char* filename) {
    FILE* file = fopen(filename, "a");

    char buffer[100];
    printf("\nEnter the Text: ");
    getchar();
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    if (file) {
        fprintf(file, "%s", buffer);
        fclose(file);
        printf("Wrote to %s: %s ->Thread_id: %ld.\n", filename, buffer, pthread_self());
    } else {
        printf("Failed to write to %s\n", filename);
    }

    log_operation("Write", filename);
}

// Read data from a file
void read_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file) {
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), file)) {
            printf("Read from %s: %s by -> Thread_id: %ld.\n", filename, buffer, pthread_self());
        }
        fclose(file);
    } else {
        printf("%s does not exist or cannot be read.\n", filename);
    }
    log_operation("Read", filename);
}

// Rename a file
void rename_file() {

    char old_name[250], new_name[250];
    printf("Enter the Source file name: ");
    scanf("%s", old_name);

    printf("Enter the new_file name: ");
    scanf("%s", new_name);

    if (rename(old_name, new_name) == 0) {
        printf("Renamed %s to %s\n", old_name, new_name);
    } else {
        printf("Failed to rename %s\n", old_name);
    }

    log_operation("Rename", old_name);
}

// Display metadata of a file
void display_metadata(const char* filename) {
    struct stat st;
    if (stat(filename, &st) == 0) {
        printf("Metadata for %s:\n", filename);
        printf("Size: %ld bytes\n", st.st_size);
        printf("Created: %s", ctime(&st.st_ctime));
        printf("Modified: %s", ctime(&st.st_mtime));
    } else {
        printf("%s does not exist.\n", filename);
    }
}

// Copy a file
void copy_file(const char* src) {
    char dest[256];

    FILE *source, *destination;
    char buffer[256];

    printf("Enter the destination File name: ");
    scanf("%s",dest);

    source = fopen(src, "r");
    if (!source) {
        printf("%s does not exist.\n", src);
        return;
    }
    
    destination = fopen(dest, "w");
    if (!destination) {
        printf("Failed to open destination file: %s\n", dest);
        fclose(source);
        return;
    }
    
    while (fgets(buffer, sizeof(buffer), source)) {
        fputs(buffer, destination);
    }
    
    log_operation("Copy", src);
    fclose(source);
    fclose(destination);
    printf("Copied from %s to %s\n", src, dest);
}

// Delete a file
void delete_file() {
    char filename[256];
    printf("Enter the the file name to be Deleted: ");
    scanf("%s", filename);

    if (remove(filename) == 0) {
        printf("Deleted %s\n", filename);
    } else {
        printf("Failed to delete %s\n", filename);
    }
    log_operation("Delete", filename);
}
