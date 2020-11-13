#include <stdio.h>
#include <stdint.h>
#include <uuid/uuid.h>

void print_uuid(const uuid_t uuid) {
    for (uint8_t i = 0; i < 16; i++) {
        printf("%02x", uuid[i]);
    }
    fputc('\n', stdout);
}

int main(void) {
    
    uuid_t uuid = {0};

    uuid_generate(uuid);
    print_uuid(uuid);

    return 0;
}
