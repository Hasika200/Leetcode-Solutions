class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l=0,r=0,maxsum=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
            l+=cardPoints[i];
        }
        maxsum=l;
        for(int i=0;i<k;i++){
            l-=cardPoints[k-1-i];
            r+=cardPoints[n-1-i];
            maxsum=max(maxsum,l+r);
        }
        return maxsum;
    }
};