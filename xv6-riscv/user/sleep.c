#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error: Number of arguments should be 2\n");
        exit(1);
    }

    pause(atoi(argv[1]));
    exit(0);
}
