// Kth Row of Pascal's Triangle : InterviewBit
// Developed by: piccolosogno

// Problem: Given an index k, return the kth row of the Pascal’s triangle.
//          Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.
//   Input: k = 3
//  Output: [1, 3, 3, 1]
//
// Solution Approach: Create a vector size of k + 1
//                    Each time, add each element with previous element until k is achieved
//                      first loop: 2 to k (inclusive)
//                        second loop: 1 to first-loop-index
//                          add current element with previous element and set it to current element.
//                          set current element to previous element.

vector<int> Solution::getRow(int A) {
  vector<int> v(A + 1, 1);
  int temp, prev;
    
  if (A == 0 || A == 1) {
    return v;
  }
  
  for (int j = 2; j < A + 1; j++) {
    prev = 1;
    for (int i = 1; i < j; i++) {
      temp = v[i];
      v[i] = v[i] + prev;
      prev = temp;
    }
  }
  return v;
}
