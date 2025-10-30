class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long res=0;
        int n=nums.size();
        int curr=0;
        int prev=0;
        for(int i=0;i<n;i++){
            curr=target[i]-nums[i];
            if((curr>0 && prev<0) || (curr<0 && prev>0)){
                res+=abs(curr);
            }
            else if(abs(curr)>abs(prev)){
                res+=abs(curr-prev);
            }
            prev=curr;
        }
        return res;
    }
};