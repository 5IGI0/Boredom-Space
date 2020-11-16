#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

int main(int argc, char const *argv[]) {
    
    if (argc != 2) {
        printf("usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    char *path = strdup(argv[1]);

    if (path == NULL) {
        perror("strdup");
        return EXIT_FAILURE;
    }
    

    puts(dirname(path));

    free(path);

    return EXIT_SUCCESS;
}
