class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size()-2;
        int XOR=0;
        for(int &num:nums){
            XOR^=num;
        }
        for(int num=0;num<=n-1;num++){
            XOR^=num;
        }
        int trailZero=__builtin_ctz(XOR);
        int mask=1<<trailZero;
        int G1=0;
        int G2=0;
        for(int &num:nums){
            if(num & mask){
                G1^=num;
            }
            else{
                G2^=num;
            }
        }
        for(int num=0;num<=n-1;num++){
            if(num & mask){
                G1^=num;
            }else{
                G2^=num;
            }
        }
        return {G1,G2};
    }
};