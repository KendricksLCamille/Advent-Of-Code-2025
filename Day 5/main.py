import sys
import interval


def merge_intervals(intervals: list[interval.Interval]) -> list[interval.Interval]:
    sorted_intervals = sorted(intervals, key=lambda i: i.lower_bound, reverse=False)
    output = [sorted_intervals.pop()]
    for interval1 in sorted_intervals:
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
        output = merge_intervals(output)
    return output

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
            else:
                del array
                is_checking = True
                is_fresh = merge_intervals(is_fresh)
        else:
            value = int(arg)
            for interval1 in is_fresh:
                left = interval1.lower_bound
                right = interval1.upper_bound
                if left <= value <= right:
                    fresh += 1
                    break
    print(f'Fresh number: {fresh}')


part_one(sys.argv[1:])

#781 is to low