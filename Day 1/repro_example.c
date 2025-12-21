#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char* example_args[] = {"L68", "L30", "R48", "L5", "R60", "L55", "L1", "L99", "R14", "L82"};
    char command[1000] = "./cmake-build-debug/part2";
    for (int i = 0; i < 10; i++) {
        strcat(command, " ");
        strcat(command, example_args[i]);
    }
    printf("Running: %s\n", command);
    system(command);
    return 0;
}
