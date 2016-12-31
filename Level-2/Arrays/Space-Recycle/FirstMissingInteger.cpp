// First Missing Integer - InterviewBit - piccolosogno
//
// Problem: Given an unsorted integer array, find the first missing positive integer.
// Example: Given [1,2,0] return 3,
//          [3,4,-1,1] return 2,
//          [-8, -7, -6] returns 1
//          Your algorithm should run in O(n) time and use constant space.


int Solution::firstMissingPositive(vector<int> &vec) {

  // Traverse the array one pass to swap the array elements with indices.
  // for example: 
  // [3,4,-1,1]: first swap 3 and -1
  // array becomes [-1, 4, 3, 1]
  // swap 4 and 1, array becomes [-1, 1, 3, 4]
  // swap 1 and -1, array becomes [1, -1, 3, 4].
  for(int i = 0; i < vec.size(); i++){
    if(vec[i] > 0 && vec[i] <= vec.size())
    {
      if(vec[vec[i]-1] != vec[i]){
        int temp = vec[vec[i]-1];
        vec[vec[i]-1] = vec[i];
        vec[i] = temp;
        i--;
      }
    }
  }
  
  // traverse the array again to find the array element does not match the index. In this case, -1 does not match 2
  // return 2.
  for(int i=0; i<vec.size(); i++){
    if(vec[i] != (i+1))
      return i+1;
	}
  
  return vec.size()+1;
}
