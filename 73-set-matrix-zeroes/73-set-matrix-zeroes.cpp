class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        // vector<pair<int,int>> d;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(matrix[i][j]==0){
        //             d.push_back({i,j});
        //         }
        //     }
        // }
        // for(int x=0;x<d.size();x++){
        //     // cout<<d[x].first<<" "<<d[x].second<<endl;
        //     for(int i=0;i<m;i++){
        //         matrix[i][d[x].second]=0;
        //     }
        //     for(int j=0;j<n;j++){
        //         matrix[d[x].first][j]=0;
        //     }
        // }
        
        int col0=1;
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0) col0=0;
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=matrix[0][j]=0;
                }
            }
        }
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=1;j--){
                if(matrix[i][0]==0||matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
            if(col0==0) matrix[i][0]=0;
        }
    }
};