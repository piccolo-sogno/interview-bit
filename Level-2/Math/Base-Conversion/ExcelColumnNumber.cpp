
// Excel Column Number - piccolo-sogno - InterviewBit
//
// Problem Statement: Given a column title as appears in an Excel sheet, return its corresponding column number.
//           Example: A -> 1, B -> 2, ..., Z -> 26, AA -> 27, AB -> 28


int Solution::titleToNumber(string A) {
  if (A.size() == 0)
    return 0;

  int res = 0, num = 1;

  for(int i = A.size() - 1; i >= 0; i--){
    res += (A[i] - 64) * num;
    num *= 26;
  }

  return res;
}
