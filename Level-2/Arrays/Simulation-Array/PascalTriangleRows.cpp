
// Pascal Triangle Rows : interviewBit : piccolo-sogno
//
// Problem: Given numRows, generate the first numRows of Pascal’s triangle.
//          Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.
// Input:   Given numRows = 5,
// Output:  [1],
//          [1,1],
//          [1,2,1],
//          [1,3,3,1],
//          [1,4,6,4,1]

vector<vector<int> > Solution::generate(int rownum) {
    vector<vector<int>> mm;
    if(rownum == 0)
        return mm;
        
    int b = 0, a = 0;
    // five row of vectors initialization.
    vector<vector<int>> m(rownum);
    
    // initialize first row with one columns, second row with two columns, nth row with n columns.
    for(int t=0; t<m.size(); t++){
        m[t].resize(t+1);
    }
    
    // the value of first column of first row should be 1.
    m[0][0] = 1;
    
    // starting from second row
    for(int i = 1; i  <m.size(); i++){
        // starting from first column to the number of columns in each column.
        for(int j = 0; j <= i; j++) {
            // get upper left value if exits
            if( (j >= 1) && (j < m[i-1].size()+1) )
                b = m[i-1][j-1];
            else
                b = 0;
            
            // get upper value if exists
            if(j < m[i-1].size())
                a = m[i-1][j];
            else
                a  = 0;
            
            // sum both of them
            m[i][j] = a + b;
        }
    }
    return m;
}
