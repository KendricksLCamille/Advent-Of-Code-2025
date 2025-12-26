import sys
from functools import reduce

import interval


def merge_intervals(intervals: list[interval.Interval]) -> list[interval.Interval]:
    output = [intervals[0]]
    for interval1 in intervals[1:]:
        joined = False
        for i in range(0, len(output)):
            try:
                output_interval = output[i]
                joined_interval = interval1.join(output_interval)
                output[i] = joined_interval
                joined = True
                break
            except ArithmeticError:
                continue
        if not joined:
            output.append(interval1)
    if len(output) != len(intervals):
        return merge_intervals(output)
    return sorted(intervals, key=lambda j: j.lower_bound, reverse=False)

def part_one(args: list[str]):
    is_fresh: list[interval.Interval] = []
    is_checking = False
    fresh: int = 0
    for arg in args:
        if not is_checking:
            if '-' in arg:
                array = arg.split('-')
                array = map(int, array)
                left, right = array
                is_fresh.append(interval.Interval(left, right))
                continue
            else:
                del array
                is_checking = True
                is_fresh = merge_intervals(sorted(is_fresh, key=lambda i: i.lower_bound, reverse=False))
        value = int(arg)
        for interval1 in is_fresh:
            left = interval1.lower_bound
            right = interval1.upper_bound
            if left <= value <= right:
                fresh += 1
                break
    print(f'Fresh numbers: {fresh}')

def part_two(args: list[str]):
    is_fresh: list[interval.Interval] = []
    for arg in [arg for arg in args if '-' in arg]:
        array = arg.split('-')
        array = map(int, array)
        left, right = array
        is_fresh.append(interval.Interval(left, right))
    is_fresh = merge_intervals(sorted(is_fresh, key=lambda i: i.lower_bound, reverse=False))
    _sum = reduce(lambda j,i: j + i.upper_bound - i.lower_bound + 1, is_fresh, 0)
    print(f'Sum: {_sum}')

part_one(sys.argv[1:])
part_two(sys.argv[1:])

#781 is to low
# answer is 782 by modifying "https://github.com/RichRat/pyxercise/blob/master/advent/2025/adv05.py"