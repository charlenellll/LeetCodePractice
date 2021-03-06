// 112 ms 理论上O(m + log n)但是比下面的解法慢
class Solution {
public:
    bool searchMatrix(vector<vector<int> >& array, int target) {
        int m = array.size();
        if( m == 0 ) return false;
        int n = array[0].size();
        if( n == 0 ) return false;
        if( target < array[0][0] || target > array[m-1][n-1] ) return false;
        
        for(int row = 0; row < m; row++){
            if( target == array[row][n-1] ) return true;
            else if( target > array[row][n-1] || target < array[row][0] ) continue;
            else{// 可能在这一行存在，进行二分查找
                int colMin = 0, colMax = n-1;
                while( colMin <= colMax ){
                    int colMid = colMin + (colMax - colMin)/2;
                    if( target == array[row][colMid] ) return true;
                    else if( target > array[row][colMid] ) colMin = colMid + 1;
                    else colMax = colMid - 1;
                }
            }
        }
        return false;
    }
};

// 56 ms, faster than 97.74%, O(m + n)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if( m == 0 ) return false;
        int n = matrix[0].size();
        if( n == 0 ) return false;
        if( target < matrix[0][0] || target > matrix[m-1][n-1] ) return false;
        
        int row = 0, col = n-1; // 从右上角开始扫
        while( row <= m-1 && col >= 0 ){
            int cur = matrix[row][col];
            if( target == cur )
                return true;
            else if( target > cur )
                row++;
            else
                col--;
        }
        return false;
    }
};