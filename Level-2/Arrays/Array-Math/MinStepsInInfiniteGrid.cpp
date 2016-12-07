
// You are in an infinite 2D grid where you can move in any of the 8 directions :
// (x, y) to (x + 1, y)
//           (x    , y + 1)
//           (x + 1, y + 1)
//           (x - 1, y - 1)
//           (x - 1, y + 1)
//           (x - 1, y)
//           (x    , y - 1)
//           (x + 1, y - 1)

// You are given a sequence of points and the order in which you need to cover the points.
// Give the minimum number of steps in which you can achieve it. You start from the first point.

// Input:  [(0,0), (1,1), (1,2)]
// Output: 2

// (0,0) --> (1,1) : 1 step
// (1,1) --> (1,2) : 1 step
// Total: 2 steps.

// Solution approach: Since one step covers all 8 directions. Minimum steps required moving from
//                    one cell to another cell is the maximum of absolute difference on steps on X-axis and
//                    absolute difference on steps on Y-axis.

int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
    int res = 0;
    
    if( (X.size() != Y.size()) || (X.size() == 1) )
        return 0;
    
    for(int i=1; i<X.size(); i++){
        res += max(abs(X[i]-X[i-1]), abs(Y[i]-Y[i-1]));    
    }
    return res;
}
