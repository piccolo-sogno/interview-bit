
// Given a non-negative number represented as an array of digits,
// add 1 to the number ( increment the number represented by the digits ).
// The digits are stored such that the most significant digit is at the head of the list.

// Input : [1, 2, 3]
// Output: [1, 2, 4]

// Assumptions: 1) Input can have leading zeros before most-significant digit.
//              2) Output should have not leading zeros before most-significant digit.

vector<int> Solution::plusOne(vector<int> &vec) {
  int numofLeadingZeros = 0;
	
  // erase leading zeros in input vector.
  for(int t=0; t<vec.size(); t++) {
    if(vec[t] != 0)
      break;
    numofLeadingZeros++;
  }
  vec.erase(vec.begin(), vec.begin()+numofLeadingZeros);

  vector<int> v(vec.size()+1);
  copy(vec.begin(), vec.end(), v.begin()+1);
  v[0] = 0;
  int i = vec.size()-1;
  
  while(i>=0 && vec[i] == 9)
  {
    v[i+1] = 0;
    i--;
  }
  
  if(i >= 0) {
    v[i+1]++;
    v.erase(v.begin(), v.begin()+1);
  }
  else //i = -1
    v[0] = 1;
    
  return v;
}
