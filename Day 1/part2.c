//
// Created by kendricks on 12/20/25.
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

constexpr int UNDER_OVER_FLOW_FIX = 100;

int main(const int argc, char** argv){
    int position = 50;
    int number_of_zeroes = 0;

    printf("%10s %10s %10s %10s\n", "index", "command", "position", "number of zeroes");
    printf("%10d %10s %10d %10d\n", 0, "n/a", position, number_of_zeroes);
    for(int i = 1; i < argc; i++){
        const char* current = argv[i];
        const int ticks = atoi(current + 1);
        const char direction = current[0];
        const int delta = (direction == 'R') ? 1 : -1;

        for (int t = 0; t < ticks; t++) {
            position = (position + delta + UNDER_OVER_FLOW_FIX) % UNDER_OVER_FLOW_FIX;
            if (position == 0) {
                number_of_zeroes++;
            }
        }
        printf("%10d %10s %10d %10d\n", i, current, position, number_of_zeroes);
    }
    printf("Answer: %10d\n", number_of_zeroes);
    return 0;
}
