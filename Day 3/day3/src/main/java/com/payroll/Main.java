package com.payroll;

import java.util.Arrays;
import java.util.function.Function;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {

    static int findTheLargestNumberInStringPart1(String str){   // 54321
        if(str.isEmpty()) throw new IllegalArgumentException("String cannot be empty");
        if(str.length() <= 2) return Integer.parseInt(str);
        var charArray = str.toCharArray();  // [5,4,3,2,1]
        Arrays.sort(charArray); // [1,2,3,4,5]
        var largestNumber = charArray[charArray.length - 1]; // 5
        var strIndex = str.indexOf(largestNumber); // 0
        if(strIndex == str.length()-1) {
            var end = largestNumber;
            largestNumber = charArray[charArray.length - 2];
            return Integer.parseInt(largestNumber + "" + end);
        }
        var largestCharIndex = str.indexOf(largestNumber);
        var nextLargestSubstring = str.substring(largestCharIndex + 1);
        var nextLargestCharArray = nextLargestSubstring.toCharArray();
        Arrays.sort(nextLargestCharArray);
        var nextLargestCharacter = nextLargestCharArray[nextLargestCharArray.length - 1];
        return Integer.parseInt(largestNumber + "" + nextLargestCharacter);
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

    static void findTheLargestNumberInStringPart1(String[] args){
        var sum = 0;
        for (String arg : args) {
            int theLargestNumberInStringPart1 = findTheLargestNumberInStringPart1(arg);
            sum = sum + theLargestNumberInStringPart1;
        }
        IO.println("Sum of largest numbers: " + sum);
    }

    static void findTheLargestNumberInStringPart2(String[] args){
        long acc = 0;
        for (String a : args) {
            var part2Helper = Part2Helper2(a);
            acc = acc + part2Helper;
        }
        IO.println("Sum of largest numbers: " + acc);
    }

    static void sumAll(String[] args, Function<String, Long> function){
        var sum = Arrays.stream(args).map(function).reduce(Long::sum);
        IO.println("Sum: " + sum);
    }

    static void main(String[] args) {
        findTheLargestNumberInStringPart1(args);
        findTheLargestNumberInStringPart2(args);
    }
}
