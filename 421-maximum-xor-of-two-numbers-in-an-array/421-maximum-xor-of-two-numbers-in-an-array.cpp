class Solution {
public:
    
    
    class trie{
    public:
        trie* children[2];
        
    
        trie(){
            children[0]=NULL;
            children[1]=NULL;
        }
        
    };
    
    trie* root;
    
    void buildTrie(vector<int> &nums){
        for(int x:nums){
            trie* curnode = root;
            for(int i=31;i>=0;i--){
                int curBit = (x>>i)&1;
                if(curnode->children[curBit]==NULL){
                    curnode->children[curBit]=new trie();
                }
                curnode = curnode->children[curBit];
            }
        }
    }
    
    int findXor(int num){
        trie* curnode = root;
        int target = 0;
        for(int i=31;i>=0;i--){
            int curbit = (num>>i) & 1;
            int targetbit = curbit == 0?1:0;
            if(curnode->children[targetbit]!=NULL){
                target = target*2 + targetbit;
                curnode = curnode->children[targetbit];
            }
            else{
                target = target*2 + curbit;
                curnode = curnode->children[curbit];
            }
        }
        return target;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        
        
        if(nums.size()==0) return 0;
        
        root = new trie();
        buildTrie(nums);
        
        int maxi = INT_MIN;
        for(int num:nums){
            int maxXor = findXor(num);
            maxi = max(maxi, maxXor^num); 
        }
        return maxi;
    }
};