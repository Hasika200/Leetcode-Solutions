class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int ans=r;
        while(l<=r){
            int m=(l+r)/2;
            if(finish(piles,h,m)){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
    bool finish(vector<int>& piles, int h, int k){
        int hrs=0;
        for(int pile:piles){
            hrs+=pile/k;
            if(pile%k!=0) hrs++;
            if(hrs>h) return false;
        }
        return hrs<=h;
    }
};