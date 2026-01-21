class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        for(int &num:nums){
            if(num==2){
                res.push_back(-1);
                continue;
            }
            bool found=false;
            for(int j=1;j<32;j++){
                if((num & (1<<j))>0){
                    continue;
                }
                int prev=j-1;
                int x=(num^(1<<(j-1)));
                res.push_back(x);
                found=true;
                break;
            }
            if(found==false){
                res.push_back(-1);
            }
        }
        return res;
    }
};