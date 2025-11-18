class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        int cnt1=0;
        for(int i=n-2;i>=0 && bits[i]==1;i--){
            cnt1++;
        }
        if(cnt1%2==0) return true;
        else return false;
    }
};