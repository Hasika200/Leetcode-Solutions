class Solution {
public:
    int capacity(vector<int>& weights, int cap){
        int load=0,days=1;
        for(int i=0;i<weights.size();i++){
            if(weights[i]+load>cap){
                days++;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int r=accumulate(weights.begin(),weights.end(),0);
        while(l<=r){
            int mid=l+(r-l)/2;
            int noOfDays=capacity(weights,mid);
            if(noOfDays<=days){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};