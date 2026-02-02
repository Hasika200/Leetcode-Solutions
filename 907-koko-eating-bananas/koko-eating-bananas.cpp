class Solution {
public:
    long long calculate(vector<int>& piles, int hour){
        long long th=0;
        for(int i=0;i<piles.size();i++){
             th+=(long long)ceil((double)piles[i]/hour); 
        }
        return th;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=*max_element(piles.begin(),piles.end());
        while(l<=r){
            int mid=l+(r-l)/2;
            long long totalHours=calculate(piles,mid);
            if(totalHours<=h){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};