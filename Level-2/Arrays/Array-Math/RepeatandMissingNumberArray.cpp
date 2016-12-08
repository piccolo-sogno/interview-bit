// Repeat and Missing Number Array : InterviewBit

// Problem: You are given a read only array of n integers from 1 to n.
//          Each integer appears exactly once except A which appears twice and B which is missing.
//          Return A and B.

// Solution Approach: Let's say that the numbers are: 1, 2, 3, ..., a, a, ..., n.
//                    The sum of of the first n natural number is         [n * (n + 1) / 2] = W
//                    The sum of squares of the first n natural number is [n * (n + 1) * (2n + 1) / 6] = Z
//                    Let's say the total sum of given set is X
//                    Let's say the total sum of squares of given set is Y
//                    X - a + b = W     -->  W - X = b - a;
//                    Y - a^2 + b^2 = Z -->  Z - Y = b^2 - a^2
//                    The new equation  --> (Z - Y) / (W - X) = b + a
//                    b = { [(Z - Y) / (W - X)] + (W - X) } / 2
//                    a = X - W + b

vector<int> Solution::repeatedNumber(const vector<int> &A) {
  typedef long long LONG;
  LONG n = A.size(); LONG existingSumOfSquares = 0; LONG existingSum = 0;
  
  for(LONG i=0; i<A.size(); i++) {
    existingSumOfSquares += (LONG)A[i] * (LONG)A[i];
    existingSum += A[i];
  }
    
  LONG Aa = ( ((2*n*n*n) + (3*n*n) + n) / 6) - existingSumOfSquares; // k*k - j*j
  LONG B = (n*(n+1)/2) - existingSum;//k-j
  LONG C = Aa / B; // k+j
  LONG temp = (B+C) / 2;
  int k =  temp;
  temp = C - k;
  int j = temp;
  
  vector<int> result;
  result.push_back(j); result.push_back(k);
  return result;
}
