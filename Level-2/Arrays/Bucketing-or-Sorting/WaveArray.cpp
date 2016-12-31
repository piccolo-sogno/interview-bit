// Wave Array - InterviewBit - piccolosogno
//
// Problem Statement: Given an array of integers, sort the array into a wave like array and return it, 
//                    In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....
//
// Solution Approach: Sort the array
//                    Swap array elements in indices 0 and 1, 2 and 3, ...

void swap(int& a, int& b)
{
  int t = a;
  a = b;
  b = t;
}

vector<int> Solution::wave(vector<int> &A) {

  // sort in ascending order
  sort(A.begin(), A.end());
  
  // swap elements in indices 0 and 1, 2 and 3.
  for(int i = 0; i < A.size() - 1; i += 2) {
    swap(A[i], A[i+1]);
  }
  
  return A;
}
