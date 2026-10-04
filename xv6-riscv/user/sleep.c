#include "kernel/types.h"
#include "user/user.h"


int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error: Number of arguments should be 2");
        exit(1);
    }
    pause(argv[1].atoi())
    exit(0);
}
