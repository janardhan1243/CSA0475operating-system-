#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    const char *filename = "example.txt"; // Replace with the path to your file
    struct stat file_stat;

    // Check if the file exists
    if (access(filename, F_OK) != -1) {
        printf("File '%s' exists.\n", filename);

        // Get the current file permissions
        if (stat(filename, &file_stat) == 0) {
            printf("Current file permissions: %o\n", file_stat.st_mode & 0777);
            
            // Demonstrate user types
            printf("Owner: %s\n", (file_stat.st_mode & S_IRUSR) ? "Can read" : "Cannot read");
            printf("Group: %s\n", (file_stat.st_mode & S_IRGRP) ? "Can read" : "Cannot read");
            printf("Others: %s\n", (file_stat.st_mode & S_IROTH) ? "Can read" : "Cannot read");
            
            // Modify file permissions (for demonstration purposes)
            printf("Changing file permissions...\n");
            chmod(filename, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
            
            // Get the updated file permissions
            if (stat(filename, &file_stat) == 0) {
                printf("Updated file permissions: %o\n", file_stat.st_mode & 0777);
            } else {
                perror("Error getting file permissions");
            }
        } else {
            perror("Error getting file permissions");
        }
    } else {
        printf("File '%s' does not exist.\n", filename);
    }

    return 0;
}
