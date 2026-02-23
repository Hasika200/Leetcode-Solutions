class Solution {
public:
    string removeOuterParentheses(string s) {
        int dep=0;
        string res="";
        for(char c:s){
            if(c=='('){
                if(dep>0) res+=c;
                dep++;
            }
            else{
                dep--;
                if(dep>0) res+=c;
            }
        }
        return res;
    }
};