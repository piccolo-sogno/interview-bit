//     Problem: Largest Number - (piccolo-sogno)
//              Given a list of non negative integers, arrange them such that they form the largest number.
//
// For example: Given [3, 30, 34, 5, 9], the largest formed number is 9534330.
//
//        Note: The result may be very large, so you need to return a string instead of an integer.

bool sortDesc(string s1, string s2){
    // compares two string, returns true if first+second is bigger than second+first.
    // for example, if s1="9" and s2="12"
    // append s1 and s2. append s2 and s1. compare both.
    // "912" is bigger than "129", then return true.
    
    string temp1;
    string temp2;
    
    // append second string to first string
    temp1.append(s1);
    temp1.append(s2);
    
    // append first string to second string
    temp2.append(s2);
    temp2.append(s1);
    
    return temp1 > temp2;
}

string Solution::largestNumber(const vector<int> &vec) {
	
  // if no data in input, return ""
	if(vec.size() == 0)
	    return "";
  
  // if all the data in input is zero, just return zero.
	for(int i=0; i<vec.size(); i++)    
	{
	    if(vec[i] != 0)
	        break;
	    return "0";
	}
	
	string res;
	vector<string> strvec;
  
  // get integer data from input, put it into string vector.
	for(int i=0; i<vec.size(); i++){
		stringstream ss;
		ss << vec[i];
		strvec.push_back(ss.str());
	}
  
  // sort string vector as defined in sortDesc function.
	sort(strvec.begin(), strvec.end(), sortDesc);
  
  // append all elements in string vector into single string.
	for(int i = 0; i < strvec.size(); i++)
		res.append(strvec[i]);
	
	return res;
}
