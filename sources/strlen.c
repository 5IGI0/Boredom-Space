#include <stdio.h>
#include <string.h>

#define LINE_BUFFER_SIZE 2048

int main() {
    
    char buffer[LINE_BUFFER_SIZE] = "";
    while (fgets(buffer, sizeof(buffer), stdin)) {
        size_t size = strlen(buffer);
        if(buffer[size-1] == '\n') {
            buffer[size-1] = '\x00';
            size--;
        }
        printf("% 4ld: %s\n", size, buffer);
    }

    return 0;
}
