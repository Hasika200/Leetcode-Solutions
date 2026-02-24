class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i=0,j=0;
        int oddcnt=0,prevcnt=0,res=0;
        while(j<nums.size()){
            if(nums[j]%2!=0){
                oddcnt++;
                prevcnt=0;
            }
            while(oddcnt==k){
                prevcnt++;
                if(i<nums.size() && nums[i]%2==1){
                    oddcnt--;
                }
                i++;
            }
            res+=prevcnt;
            j++;
        }
        return res;
    }
};