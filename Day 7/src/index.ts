let test_input = `.......S.......
...............
.......^.......
...............
......^.^......
...............
.....^.^.^.....
...............
....^.^...^....
...............
...^.^...^.^...
...............
..^...^.....^..
...............
.^.^.^.^.^...^.
...............
`

function part1(rows: string[]) {
    let finding_s:boolean = true;
    let indexToCheck = new Set<number>()
    let splits = 0;
    for (let row of rows) {
        if (!finding_s) {
            let newIndexToCheck = new Set<number>();
            let lineLength = row.length;
            for (const indexToCheckKey of indexToCheck) {
                if (row.charAt(indexToCheckKey) !== '^') continue;
                indexToCheck.delete(indexToCheckKey);
                let before = indexToCheckKey - 1;
                let after = indexToCheckKey + 1;
                if (before >= 0) newIndexToCheck.add(before);
                if (after < lineLength) newIndexToCheck.add(after);
                console.log(newIndexToCheck + " Splits: " + splits);
            }
            let potentialNewSize = newIndexToCheck.size;
            if (potentialNewSize == 0) continue;
            splits += newIndexToCheck.size;
            indexToCheck = newIndexToCheck;
        } else {
            let sIndex = row.indexOf('S')
            if (sIndex <= -1) continue;
            finding_s = false
            indexToCheck.add(sIndex)
        }
    }

    return splits;
}

function run_test(){
    console.log("Running test...");
    let array = test_input.split("\n");
    console.log("Number of splits: " + part1(array));
}


console.log('Happy developing ✨')
run_test();
