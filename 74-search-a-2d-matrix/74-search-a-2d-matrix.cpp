class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // int rows=matrix.size();
        // int cols=matrix[0].size();
        
//         int i=0,j=cols-1;

        
//         while(i<rows and j>-1){
//             if(target==matrix[i][j]) return true;
//             else if(target>matrix[i][j]) i++;
//             else j--;
//         }
        
//         return false;
        
        if(!matrix.size()) return false;
        int n=matrix.size();
        int m=matrix[0].size();
        
        int lo=0, hi=(n*m)-1;
        while(lo<=hi){
            int mid= lo+(hi-lo)/2;
            
            if(matrix[mid/m][mid%m]==target) return true;
            if(matrix[mid/m][mid%m]<target) lo=mid+1;
            else hi=mid-1;
        }
        
        return false;
        
    }
};