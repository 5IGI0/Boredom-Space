#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char const *argv[], char const *env[]) {
    
    int binary = open("/usr/bin/uname", O_RDONLY);

    if (binary < 0) {
        perror("open");
        return EXIT_FAILURE;
    }
    
    fexecve(binary, (char * const*)argv, (char * const*)env);

    perror("fexecve");
    close(binary);

    return EXIT_FAILURE;
}
