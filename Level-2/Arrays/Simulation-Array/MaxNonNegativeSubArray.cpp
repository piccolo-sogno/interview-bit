// Max Non Negative SubArray : InterviewBit

// Problem : Find out the maximum sub-array of non negative numbers from an array.
//           The sub-array should be continuous. That is, a sub-array created by choosing the second and 
//           fourth element and skipping the third element is invalid.
//           
//           Maximum sub-array is defined in terms of the sum of the elements in the sub-array. 
//           Sub-array A is greater than sub-array B if sum(A) > sum(B).
//           
//  NOTE 1 : If there is a tie, then compare with segment's length and return segment which has maximum length.
//  NOTE 2 : If there is still a tie, then return the segment with minimum starting index

void maxVector(vector<int>& v1, vector<int>& v2)
{
  unsigned long long sum1 = 0, sum2 = 0, i = 0;
	for(i=0; i<v1.size() && i<v2.size(); i++){
		sum1 += v1[i];
		sum2 += v2[i];
	}
	while(i < v1.size()){
		sum1 += v1[i];
		i++;
	}
	while(i < v2.size()){
		sum2 += v2[i];
		i++;
	}
	if( (sum1 < sum2) || ((sum2==0 && sum1==0) && (v2.size() > v1.size()) )  ) {//copy v2 into v1
	  v1.clear();
		copy(v2.begin(), v2.end(), back_inserter(v1));
	}
}

vector<int> Solution::maxset(vector<int> &A) {
  vector<int> vecT;
	vector<int> vecS;
	for(auto i : A){
		if(i >= 0)
			vecT.push_back(i);
		else{
			if (vecT.size() > 0){
				maxVector(vecS, vecT);
				vecT.clear();
			}
		}
	}
  
	if (vecT.size() > 0){
		maxVector(vecS, vecT);
		vecT.clear();
  }
	return vecS;   
}
