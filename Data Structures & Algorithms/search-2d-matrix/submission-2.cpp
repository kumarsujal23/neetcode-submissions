class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int row=matrix.size(),col=matrix[0].size();
       int l=0,r=row*col-1;
       while(l<=r)
       {
        int m=(l+r)/2;
        int i=m/col,j=m%col;
        if(matrix[i][j]==target)
        return true;
        else if(matrix[i][j]>target)
        r=m-1;
        else
        l=m+1;
       } 
       return false;

    }
};
