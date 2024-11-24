// log_operations.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Log the file operation
void log_operation(const char* operation, const char* filename) {
    FILE* log_file = fopen("file_operations.log", "a");
    if (log_file) {
        time_t now = time(NULL);
        fprintf(log_file, "%s on %s at %s", operation, filename, ctime(&now));
        fclose(log_file);
    } else {
        printf("Failed to open log file.\n");
    }
}
