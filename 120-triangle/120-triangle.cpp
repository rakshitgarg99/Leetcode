class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        // int ans=triangle[0][0];
//         int j=0;
//         for(int i=1;i<triangle.size();i++){
//             if(triangle[i][j] < triangle[i][j+1]){
//                 ans+=triangle[i][j];
//                 j=j;
//             }
//             else{
//                 ans+=triangle[i][j+1];
//                 j=j+1;
//             }
//         }
        
        // return ans;
        
        
        for(int level=triangle.size()-2;level>=0;level--){
            for(int i=0;i<=level;i++){
                triangle[level][i] += min(triangle[level+1][i], triangle[level+1][i+1]);
            }
        }
        
        return triangle[0][0];
    }
};