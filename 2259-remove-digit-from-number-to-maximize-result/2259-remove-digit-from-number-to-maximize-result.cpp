class Solution {
public:
    string removeDigit(string number, char digit) {
        for(int i=1;i<number.size();i++){
            if(number[i-1]==digit and number[i]>number[i-1]){
                // string temp=number;
                number.erase(i-1,1);
                return number;
            }
        }
        
        for(int i=number.size()-1;i>=0;i--){
            if(number[i]==digit){
                number.erase(i,1);
                break;
            }
        }
        return number;
    }
};