#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>

// WARNING: i didn't read the doc

int main(void) {
    
    struct netent *net = getnetbyname("link-local");

    if (net == NULL) {
        if (errno != 0)
            perror("getnetbyname");
        else
            fputs("\"link-local\" not found!\n", stderr);
        
        return EXIT_FAILURE;
    }
    
    net->n_net = ntohl(net->n_net);

    printf(
        "name: %s\n"
        "address: %s\n",
        net->n_name,
        inet_ntoa(((struct in_addr *)&net->n_net)[0])
    );

    if (net->n_aliases[0])
        puts("aliases:");

    for (size_t i = 0; net->n_aliases[i]; i++)
        puts(net->n_aliases[i]);

    return EXIT_SUCCESS;
}
