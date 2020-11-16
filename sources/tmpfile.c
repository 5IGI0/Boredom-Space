#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TO_GEN 2000

#define TO_STR(x) #x
#define STR(x) TO_STR(x)

/**
 * @brief write hardcoded data
 * 
*/
#define FWRITE_HCSTR(x, file) fwrite(x, 1, sizeof(x)-1, file);

int main(void) {
    
    FILE *file = tmpfile();

    if (file == NULL) {
        perror("tmpfile");
        return EXIT_FAILURE;
    }
    
    srand(time(NULL));

    puts("generating "STR(NUM_TO_GEN)" numbers...");

    for (size_t i = 0; i < NUM_TO_GEN; i++) {
        unsigned int tmp = rand();
        fwrite(&tmp, sizeof(tmp), 1, file);
    }
    
    fseek(file, 0, SEEK_SET);

    for (size_t i = 0; i < NUM_TO_GEN; i++) {
        unsigned int tmp;
        fread(&tmp, sizeof(tmp), 1, file);
        printf("%d, ", tmp);
    }
    FWRITE_HCSTR("\n", stdout);

    return EXIT_SUCCESS;
}
