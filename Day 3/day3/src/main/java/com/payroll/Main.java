package com.payroll;

import java.util.Arrays;
import java.util.function.Function;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {

    static long findTheLargestNumberInStringPart1(String str){   // 54321
        if(str.isEmpty()) throw new IllegalArgumentException("String cannot be empty");
        if(str.length() <= 2) return Long.parseLong(str);
        var charArray = str.toCharArray();  // [5,4,3,2,1]
        Arrays.sort(charArray); // [1,2,3,4,5]
        var largestNumber = charArray[charArray.length - 1]; // 5
        var strIndex = str.indexOf(largestNumber); // 0
        if(strIndex == str.length()-1) {
            var end = largestNumber;
            largestNumber = charArray[charArray.length - 2];
            return Long.parseLong(largestNumber + "" + end);
        }
        var largestCharIndex = str.indexOf(largestNumber);
        var nextLargestSubstring = str.substring(largestCharIndex + 1);
        var nextLargestCharArray = nextLargestSubstring.toCharArray();
        Arrays.sort(nextLargestCharArray);
        var nextLargestCharacter = nextLargestCharArray[nextLargestCharArray.length - 1];
        return Long.parseLong(largestNumber + "" + nextLargestCharacter);
    }

    static long Part2Helper2(String source){
        if(source.isEmpty()) throw new IllegalArgumentException("Source cannot be empty");
        var sourceLen = source.length();
        if(sourceLen == 12) return Integer.parseInt(source);

        var sb  = new StringBuilder();
        for(int len = 12; len > 0; len--){
            for(int chrToAdd = 9; chrToAdd > 0; chrToAdd--){
                char ch = (char) (chrToAdd + '0');
                var indexOf =  source.indexOf(ch);
                if(indexOf == -1) continue;
                var diff = source.length() - indexOf;
                if(diff < len) continue;
                sb.append(ch);
                source = source.substring(indexOf + 1);
                break;
            }
        }
        return Long.parseLong(sb.toString());
    }

    static void sumAll(String[] args, Function<String, Long> function){
        var sum = Arrays.stream(args).map(function).reduce(Long::sum).orElse(0L);
        IO.println("Sum: " + sum);
    }

    static void main(String[] args) {
        // part 1
        sumAll(args, Main::findTheLargestNumberInStringPart1);
        // part2
        sumAll(args, Main::Part2Helper2);
    }
}
