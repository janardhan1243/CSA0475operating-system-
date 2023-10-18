#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;  
    char filename[] = "example.txt"; 
    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening the file");
        return 1;
    }
    fprintf(file, "Hello, World!\n");
    fprintf(file, "This is a simple file management example.\n");
    fclose(file);
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening the file");
        return 1;
    }
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);

    return 0;
}

