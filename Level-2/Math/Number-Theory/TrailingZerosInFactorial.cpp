// Trailing Zeros in Factorial - piccolosogno - Interviewbit
//
// Problem Statement: Given an integer n, return the number of trailing zeroes in n!.
//                    Note: Your solution should be in logarithmic time complexity.
//
// Solution Approach: Count the number 5s, 25s, 125s, ... until that number.
//                    For example if the number is 5, the result 1.
//                    If the number is 15, how many 5 in 15? (3) The result is 3.
//                    If the number is 25, how many 5 in 25? (5) plus how many 25 in 25? (1) total the result is 6.
//                    If the number is 50, how many 5 in 50? (10) plus how many 25 in 50? (2) total the result is 12.
//                    If the number is 75, how many 5 in 75? (15) plus how many 25 in 75? (3) total the result is 18.


int Solution::trailingZeroes(int A) {
  int res = 0;
  
  for(int i = 5; (A / i) >= 1; i *= 5)
    res += A / i;
    
  return res;
}
