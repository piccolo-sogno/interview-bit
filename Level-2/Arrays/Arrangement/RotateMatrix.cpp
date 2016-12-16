
// Problem: Rotate Matrix - interviewBit
// Solved by: piccolo-sogno

// Problem Definition: 
//                You are given an n x n 2D matrix representing an image.
//                Rotate the image by 90 degrees (clockwise).
//                You need to do this in place.
//                Note that if you end up using an additional array, you will only receive partial score.
// Example:
// 
//          If the array is
//          [
//             [1, 2],
//             [3, 4]
//          ]
// Then the rotated array becomes:
//          [
//             [3, 1],
//             [4, 2]
//          ]

// Solutin Approach: Think that matrix is as follows:
//                   [  1,  2,  3,  4 ]
//                   [  5,  6,  7,  8 ]
//                   [  9, 10, 11, 12 ]
//                   [ 13, 14, 15, 16 ]
//
// 1. swap -->  0,0 - 3,0 - 3,3 - 0,3
// 2. swap -->  0,1 - 3,1 - 3,2 - 0,2
// 3. swap -->  1,0 - 2,0 - 2,3 - 1,3
// 4. swap -->  1,1 - 2,1 - 2,2 - 1,2

// assign b to a, c to b, d to c, a to d
void rotateSwap(int& a, int& b, int& c, int& d){
    int temp = a;
    a = b; b = c; c = d; d = temp; 
}

void Solution::rotate(vector<vector<int> > &A) {
    // if input size is zero, just return
    if(A.size() == 0)
        return;
        
    int n = A.size();
   
    for(int i = 0; i < n/2; i++){
        for(int j = 0; j < (n+1)/2; j++)
            rotateSwap(A[i][j], A[n-1-j][i], A[n-1-i][n-1-j], A[j][n-1-i]);
    }
}
