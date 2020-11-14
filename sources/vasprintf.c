#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>

int my_asprintf(char **out, char const *format, ...) {
    va_list args;
    va_start(args, format);
    int returner = vasprintf(out, format, args);
    va_end(args);
    return returner;
}

int main(void) {
    char *tmp = NULL;

    if (my_asprintf(&tmp, "timestamp: %d", time(NULL)) >= 0) {
        puts(tmp);
        free(tmp);
    } else {
        perror("my_asprintf");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
