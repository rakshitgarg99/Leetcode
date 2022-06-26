class Solution {
public:
    
    
    void solve(vector<vector<int>>& image, int sr, int sc,int val, int color){
        
        if(sr<0 or sc<0 or sr>=image.size() or sc>=image[0].size() or image[sr][sc]==color or image[sr][sc]!=val){
            return;
        }
        
        
        image[sr][sc]=color;
        solve(image,sr,sc-1,val,color);
        solve(image,sr,sc+1,val,color);
        solve(image,sr-1,sc,val,color);
        solve(image,sr+1,sc,val,color);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // if(image[sr][sc]==color) return image;
        
        solve(image,sr,sc,image[sr][sc],color);
        return image;
    }
};