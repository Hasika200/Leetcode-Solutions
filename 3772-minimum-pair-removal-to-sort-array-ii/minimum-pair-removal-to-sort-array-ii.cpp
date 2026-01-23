class Solution {
public:
    typedef long long ll;
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        vector<ll> temp(n);
        for(int i=0;i<n;i++)
            temp[i]=nums[i];
        set<pair<ll,int>> minPairSet;
        vector<int> nextIndex(n);
        vector<int> prevIndex(n);
        for(int i=0;i<n;i++){
            nextIndex[i]=i+1;
            prevIndex[i]=i-1;
        }
        int badPairs=0;
        for(int i=0;i<n-1;i++){
            if(temp[i]>temp[i+1]){
                badPairs++;
            }
            minPairSet.insert({temp[i]+temp[i+1],i});
        }
        int op=0;
        while(badPairs>0){
            int first=minPairSet.begin()->second;
            int sec=nextIndex[first];
            int first_left=prevIndex[first];
            int sec_right=nextIndex[sec];
            minPairSet.erase(begin(minPairSet));
            if(temp[first]>temp[sec]){
                badPairs--;
            }

            if(first_left>=0){
                if(temp[first_left]>temp[first] && temp[first_left]<=temp[first]+temp[sec]){
                    badPairs--;
                } 
                else if(temp[first_left]<=temp[first] && temp[first_left]>temp[first]+temp[sec]){
                    badPairs++;
                }
            }
            if(sec_right<n){
                if(temp[sec_right]>=temp[sec] && temp[sec_right]<temp[first]+temp[sec]){
                    badPairs++;
                }
                else if(temp[sec_right]<temp[sec] && temp[sec_right]>=temp[first]+temp[sec]){
                    badPairs--;
                }
            }
            if(first_left>=0){
                minPairSet.erase({temp[first_left]+temp[first],first_left});
                minPairSet.insert({temp[first_left]+temp[first]+temp[sec],first_left});
            }
            if(sec_right<n){
                minPairSet.erase({temp[sec]+temp[sec_right],sec});
                minPairSet.insert({temp[first]+temp[sec]+temp[sec_right],first});
                prevIndex[sec_right]=first;
            }
            nextIndex[first]=sec_right;
            temp[first]+=temp[sec];
            op++;
        }
        return op;
    }
};
