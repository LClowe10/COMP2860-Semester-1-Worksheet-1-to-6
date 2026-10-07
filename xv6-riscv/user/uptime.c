#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    if (argc != 1) {
        printf("Error: Number of arguments should be 1\n");
        exit(1);
    }

    printf("uptime: %d ticks\n", uptime());
    exit(0);
}
