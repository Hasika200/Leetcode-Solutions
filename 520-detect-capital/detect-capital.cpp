class Solution {
public:
    bool detectCapitalUse(string word) {
        int cntCap=0;
        for(char &ch: word){
            if(isupper(ch))
                cntCap++;
        }
        if(cntCap==0 || cntCap==word.length() || (cntCap==1 && isupper(word[0]))){
            return true;
        }
        return false;
    }
};