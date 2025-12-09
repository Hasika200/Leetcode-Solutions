class Solution {
public:
    static const long long M=1e9+7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<long long,long long>valid_i;
        unordered_map<long long,long long>valid_j;
        long long res=0;
        for(long long num:nums){
            if(num%2==0){
                res=(res+valid_j[num/2])%M;
            }
            (valid_j[num]+=valid_i[num*2])%M;
            valid_i[num]++;
        }
        return res;
    }
};