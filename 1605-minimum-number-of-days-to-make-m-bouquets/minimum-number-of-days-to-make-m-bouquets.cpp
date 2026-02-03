class Solution {
public:
    bool poss(vector<int>& bloomDay,int day, int m, int k){
        int cnt=0;
        int noofB=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                cnt++;
            }
            else{
                noofB+=cnt/k;
                cnt=0;
            }
        }
        noofB+=cnt/k;
        return noofB>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int val=1LL*1LL*m*k;
        if(val>bloomDay.size()) return -1;
        int l=*min_element(bloomDay.begin(),bloomDay.end());
        int h=*max_element(bloomDay.begin(),bloomDay.end());
        while(l<=h){
            int mid=l+(h-l)/2;
            if(poss(bloomDay,mid,m,k)){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};