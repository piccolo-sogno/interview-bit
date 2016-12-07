
// Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
// Input: (1, 3, 4, -5, 2, -10, 3, 8, 11, -1, 2, -3)
// Maximum contiguous subarray --> (3, 8, 11, -1, 2)
// Output: 23

// Solution Approach: Cadene Algorithm
// This function does not work when all the number in the vector is negative.
// In this case, the value of maximum negative number in vector should be returned.

int Solution::maxSubArray(const vector<int> &A) {
  int temp = A[0], sum = A[0];
    
  for(int i=1; i<A.size(); i++){
    temp = max(A[i], temp+A[i]);
    sum = max(sum, temp);
  }
  return sum;
}
