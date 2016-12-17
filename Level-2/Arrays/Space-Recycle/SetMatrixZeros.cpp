
// Problem: Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.
//          Do it in place.
//
// Example: Given array A as
//              1 0 1
//              1 1 1 
//              1 1 1
//          On returning, the array A should be :
//              0 0 0
//              1 0 1
//              1 0 1

// Solution Approach: 
//                    If there is one zero exists in first column, assign all first column to zero at the end.
//                    Because, if you do it at the beginning, entire matrix will be all zeros.
//                    If there is one zero exists in first row, assign all first row to zero at the end. Same reason above.
//                    
void Solution::setZeroes(vector<vector<int> > &A) {
    int rownum = A.size();
    if (rownum == 0)  return;
    int colnum = A[0].size();
    if (colnum == 0)  return;
            
    bool firstColZero = false, firstRowZero = false;
    
    // reminder of there is at least one zero in first column.
    for(int i=0; i<A.size(); i++){
        if(A[i][0] == 0){
            firstColZero = true;
            break;
        }
    }
    
    // reminder of there is at least one zero in first row.
    for(int i=0; i<A[0].size(); i++){
        if(A[0][i] == 0){
            firstRowZero = true;
            break;
        }
    }
    
    // look at the interior part of the matrix (ignore first row and first column, look the rest)
    // if any zero found, put zero to corresponding two cells in first row and first column.
    for(int i=1; i<A.size(); i++){
        for(int j=1; j<A[0].size(); j++){
            if(A[i][j] == 0){
                A[i][0] = 0;
                A[0][j] = 0;
            }
        }
    }
    
    // look at the interior part of the matrix (ignore first row and first column, look the rest)
    // if a zero found in any corresponding two cells of first row and first column. put zero in current cell. 
    for(int i=1; i<A.size(); i++){
        for(int j=1; j<A[0].size(); j++){
            if( (A[i][0] == 0) || (A[0][j] == 0) ){
                A[i][j] = 0;
            }
        }
    }
    
    // put zero to all first column if there is only one zero in first column.
    if(firstColZero){
        for(int i=0; i<A.size(); i++)
            A[i][0] = 0;
    }
    
    // put zero to all first row if there is only one zero in first row.
    if(firstRowZero){
        for(int t=0; t<A[0].size(); t++)
            A[0][t] = 0;
    }   
}
