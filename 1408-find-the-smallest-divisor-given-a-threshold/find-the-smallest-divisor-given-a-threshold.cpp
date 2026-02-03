class Solution {
public:
    long long possible(vector<int>& nums, int div){
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(long long)ceil((double)nums[i]/div);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        if(nums.size()>threshold) return -1;
        int l=1,h=*max_element(nums.begin(),nums.end());
        while(l<=h){
            int mid=l+(h-l)/2;
            if(possible(nums,mid)<=threshold){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};