class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,maxlength=0;
        unordered_map<char,int>mpp;

        int n=s.length();
        while(r<n){
            if(mpp.find(s[r])!=mpp.end() && mpp[s[r]]>=l){
                l=mpp[s[r]]+1;
            }
            int len=r-l+1;
            maxlength=max(maxlength,len);
            mpp[s[r]]=r;
            r++;
        }
        return maxlength;
    }
};