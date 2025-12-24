// See https://aka.ms/new-console-template for more information


Console.WriteLine("Hello, World!");
PartOne(args);
PartTwo(args);
return;

void PartOne(string[] args)
{
    int maxX = args[0].Length;
    int maxY = args.Length;

    int accessible = 0;

    for (var y = 0; y < maxY; y++)
    {
        for (var x = 0; x < maxX; x++)
        {
            if(args[y][x] == '@' && IsSurroundedByLessThanFour(x, y))
            {
                accessible++;
            }
        }
    }
    Console.WriteLine("Accessible by forklift: {0}",accessible);

    return;

    bool IsSurroundedByLessThanFour(int x, int y)
    {

        var matches = 0;

        for (var col = x - 1; col < x + 2; col++)
        {
            if(col < 0 || col >= maxX) continue;
            for (var row = y - 1; row < y + 2; row++)
            {
                if(row < 0 || row >= maxY) continue;
                if(x == col && y == row) continue;
                if(args[row][col] == '@') matches++;
            }
        }
        return matches < 4;
    }
}

void PartTwo(string[] args)
{
    var dualCharArray = args.Select(x => x.ToCharArray()).ToArray();
    var maxX = dualCharArray[0].Length;
    var maxY = dualCharArray.Length;

    var accessible = 0;
    var previousAccessible = 0;
    do
    {
        previousAccessible = accessible;
        for (var y = 0; y < maxY; y++)
        {
            for (var x = 0; x < maxX; x++)
            {
                if (dualCharArray[y][x] != '@' || !IsSurroundedByLessThanFour(x, y)) continue;
                accessible++;
                dualCharArray[y][x] = 'x';
            }
        }
    }while(accessible != previousAccessible);
    Console.WriteLine("Accessible by forklift: {0}",accessible);

    return;

    bool IsSurroundedByLessThanFour(int x, int y)
    {

        var matches = 0;

        for (var col = x - 1; col < x + 2; col++)
        {
            if(col < 0 || col >= maxX) continue;
            for (var row = y - 1; row < y + 2; row++)
            {
                if(row < 0 || row >= maxY) continue;
                if(x == col && y == row) continue;
                if(dualCharArray[row][col] == '@') matches++;
            }
        }
        return matches < 4;
    }
}