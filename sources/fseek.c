#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 128

/**
 * @brief write hardcoded data
 * 
*/
#define FWRITE_HCSTR(x, file) fwrite(x, 1, sizeof(x)-1, file);

int main(void) {
    
    FILE *file = fopen("fseek.c", "r");
    char buffer[BUFFER_SIZE] = "";

    if (!file) {
        perror("fseek.c");
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < 2; i++) {
        while (fread(buffer, 1, sizeof(buffer)-1, file) != 0) {
            fputs(buffer, stdout);
            memset(buffer, 0, sizeof(buffer)-1);
        }

        FWRITE_HCSTR("\n", stdout);
        
        if(fseek(file, 0, SEEK_SET) < 0) {
            perror("fseek");
            break;
        }
    }

    fclose(file);

    return EXIT_SUCCESS;
}
