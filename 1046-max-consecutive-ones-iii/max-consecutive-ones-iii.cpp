class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,zerocnt=0,maxlength=0;
        int n=nums.size();
        for(int r=0;r<n;r++){
            if(nums[r]==0){
                zerocnt++;
            }
            while(zerocnt>k){
                if(nums[l]==0){
                    zerocnt--;
                }
                l++;
            }
            maxlength=max(maxlength,r-l+1);
        }
        return maxlength;
    }
};