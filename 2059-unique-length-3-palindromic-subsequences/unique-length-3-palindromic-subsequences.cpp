class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.length();
        vector<pair<int,int>>indices(26,{-1,-1});
        for(int i=0;i<n;i++){
            char ch=s[i];
            int idx=ch-'a';
            if(indices[idx].first==-1){
                indices[idx].first=i;
            }
            indices[idx].second=i;
        }
        int res=0;
        for(int i=0;i<26;i++){
            int left_idx=indices[i].first;
            int right_idx=indices[i].second;
            if(left_idx==-1) continue;
            unordered_set<char>st;
            for(int middle_idx=left_idx+1;middle_idx<=right_idx-1;middle_idx++){
                st.insert(s[middle_idx]);
            }
            res+=st.size();
        }
        return res;
    }
};