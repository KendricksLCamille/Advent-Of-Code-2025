#include <assert.h>
#include <stdio.h>

#include "stdlib.h"
constexpr int UNDER_OVER_FLOW_FIX = 100;
#define PART_2
int move_within_0_and_100_part_1(const int input){
    if(input >= UNDER_OVER_FLOW_FIX) return input % UNDER_OVER_FLOW_FIX;
    auto output = input;
    while (output < 0)
    {
        output += UNDER_OVER_FLOW_FIX;
    }
    return output;
}

typedef struct {int position; int number_of_zeroes;} output_t;
void number_of_times_count_past_zero_part_2(int* _input, int* _number_of_zeroes)
{
    auto input = *_input;

    auto abs_input = abs(input);
    auto mod = abs_input % UNDER_OVER_FLOW_FIX;
    auto change_in_zero = abs_input / UNDER_OVER_FLOW_FIX;
    auto new_input = mod;
    if (input < 0)
    {
        new_input = UNDER_OVER_FLOW_FIX - mod;
        change_in_zero++;
    }

    *_input = new_input;
     *_number_of_zeroes += change_in_zero;
}

int main(const int argc, char** argv){
    int position = 50;
    int number_of_zeroes = 0;

    printf("%10s %10s %10s %10s\n", "index", "command", "position", "number of zeroes");
    printf("%10d %10s %10d %10d\n", 0, "n/a", position, number_of_zeroes);
    for(int i = 1; i < argc; i++){
        const char* current = argv[i];
        const int ticks = atoi((current + 1));
        const char direction = current[0];
        position += direction == 'L'  ? -ticks : ticks;

#ifdef PART_1
        position = move_within_0_and_100_part_1(position);
        assert(position >= 0 && position < 100);
        if(position == 0) number_of_zeroes++;
#elifdef PART_2
        number_of_times_count_past_zero_part_2(&position, &number_of_zeroes);
#endif
        printf("%10d %10s %10d %10d\n", i, current, position, number_of_zeroes);
    }
    printf("Answer: %10d\n", number_of_zeroes);
    return 0;
}