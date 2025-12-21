#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

/*
--- Day 2: Gift Shop ---
You get inside and take the elevator to its only other stop: the gift shop. "Thank you for visiting the North Pole!" gleefully exclaims a nearby sign. You aren't sure who is even allowed to visit the North Pole, but you know you can access the lobby through here, and from there you can access the rest of the North Pole base.

As you make your way through the surprisingly extensive selection, one of the clerks recognizes you and asks for your help.

As it turns out, one of the younger Elves was playing on a gift shop computer and managed to add a whole bunch of invalid product IDs to their gift shop database! Surely, it would be no trouble for you to identify the invalid product IDs for them, right?

They've even checked most of the product ID ranges already; they only have a few product ID ranges (your puzzle input) that you'll need to check. For example:

11-22,95-115,998-1012,1188511880-1188511890,222220-222224,
1698522-1698528,446443-446449,38593856-38593862,565653-565659,
824824821-824824827,2121212118-2121212124
(The ID ranges are wrapped here for legibility; in your input, they appear on a single long line.)

The ranges are separated by commas (,); each range gives its first ID and last ID separated by a dash (-).

Since the young Elf was just doing silly patterns, you can find the invalid IDs by looking for any ID which is made only of some sequence of digits repeated twice. So, 55 (5 twice), 6464 (64 twice), and 123123 (123 twice) would all be invalid IDs.

None of the numbers have leading zeroes; 0101 isn't an ID at all. (101 is a valid ID that you would ignore.)

Your job is to find all of the invalid IDs that appear in the given ranges. In the above example:

11-22 has two invalid IDs, 11 and 22.
95-115 has one invalid ID, 99.
998-1012 has one invalid ID, 1010.
1188511880-1188511890 has one invalid ID, 1188511885.
222220-222224 has one invalid ID, 222222.
1698522-1698528 contains no invalid IDs.
446443-446449 has one invalid ID, 446446.
38593856-38593862 has one invalid ID, 38593859.
The rest of the ranges contain no invalid IDs.
Adding up all the invalid IDs in this example produces 1227775554.

What do you get if you add up all of the invalid IDs?
 */

constexpr bool value_has_duplicate(const size_t value) // example: 1010
{
    const auto length = static_cast<size_t>(std::floor(std::log10(value))) + 1; // always off by one since the power is one less than the length | 1.010 * 10^3 -> len = 3 + 1 = 4
    if (length % 2 != 0) return false; // 4 % 2 == 0
    const auto half = length / 2; // 2
    const auto shifter = static_cast<size_t>(std::pow(10, half)); // 100
    const auto top = value / shifter; // 1010 / 100 -> 10
    const auto bottom = value % shifter; // 1010 % 100 -> 10
    return top == bottom; // 10 == 10 is true
}

constexpr void check_string_for_duplicate_value(const std::string& value, auto& invalid_ids)
{
    const auto index = value.find('-');
    const auto str_left = std::string_view{value.data(), index};
    const auto str_right = std::string_view{value.data() + index};

    const auto i_left = std::stoul(std::string{str_left});
    const auto i_right = std::stoul(std::string{str_right});
    for (auto i = i_left; i <= i_right; i++)
    {
        if (value_has_duplicate(i))
        {
            invalid_ids.push_back(i);
        }
    }
}

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main(int argc, char** argv)
{
    auto invalid_ids = std::vector<size_t>{};
    for (auto i = 0; i < argc; i++)
    {
        auto str = std::string{argv[i]};
        check_string_for_duplicate_value(str, invalid_ids);
    }

    const auto sum = std::accumulate(invalid_ids.begin(), invalid_ids.end(), 0uz);
    std::printf("Sum is %zu", sum);
}
