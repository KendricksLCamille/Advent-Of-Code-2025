#include <assert.h>
#include <stdio.h>

#include "stdlib.h"
constexpr int UNDER_OVER_FLOW_FIX = 100;

int move_within_0_and_100(const int input){
    if(input >= UNDER_OVER_FLOW_FIX) return input % UNDER_OVER_FLOW_FIX;
    auto output = input;
    while (output < 0)
    {
        output += UNDER_OVER_FLOW_FIX;
    }
    return output;
}

int main(const int argc, char** argv){
    int position = 50;
    int number_of_zeroes = 0;

    // printf("%10s %10s %10s %10s\n", "index", "position", "command", "number of zeroes");
    for(int i = 1; i < argc; i++){
        const char* current = argv[i];
        // printf("%10d %10s %10d %10d\n", i - 1, current, position, number_of_zeroes);
        const int ticks = atoi((current + 1));
        const char direction = current[0];
        position += direction == 'L'  ? -ticks : ticks;
        position = move_within_0_and_100(position);
        assert(position >= 0 && position < 100);
        if(position == 0) number_of_zeroes++;
    }
    printf("Answer: %10d\n", number_of_zeroes);
    return 0;
}