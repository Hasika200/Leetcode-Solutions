class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        vector<bool>res(n);
        int rem=0;
        for(int i=0;i<n;i++){
            rem=(rem*2+nums[i])%5;
            res[i]=(rem==0);
        }
        return res;
    }
};