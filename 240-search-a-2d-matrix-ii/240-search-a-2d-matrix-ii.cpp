class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i, j=matrix[0].size()-1;
        i=0;
        while(i<matrix.size() and j>=0){
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j]>target){
                j--;
            }
            else{
                i++;
            }
        }
        
        return false;
    }
};