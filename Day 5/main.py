from enum import Enum
import sys

def part_one(args: list[str]):
    is_fresh: dict[int, bool] = {}
    is_checking = False
    fresh: int = 0
    for arg in args:
        if not is_checking:
            if '-' in arg:
                array = arg.split('-')
                array = map(int, array)
                left, right = array
                for i in range(left, right + 1):
                    is_fresh[i] = True
            else:
                is_checking = True
        else:
            value = int(arg)
            if is_fresh.get(value):
                fresh += 1
    print(f'Fresh number: {fresh}')


part_one(sys.argv[1:])