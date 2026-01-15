class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(begin(hBars),end(hBars));
        sort(begin(vBars),end(vBars));

        int maxConsecutivehBars=1;
        int maxConsecutivevBars=1;

        int currConsecutivehBars=1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]-hBars[i-1]==1){
                currConsecutivehBars++;
            }
            else{
                currConsecutivehBars=1;
            }
            maxConsecutivehBars=max(maxConsecutivehBars,currConsecutivehBars);
        }

        int currConsecutivevBars=1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i]-vBars[i-1]==1){
                currConsecutivevBars++;
            }
            else{
                currConsecutivevBars=1;
            }
            maxConsecutivevBars=max(maxConsecutivevBars,currConsecutivevBars);
        }
        int side=min(maxConsecutivehBars,maxConsecutivevBars)+1;
        return side*side;
    }
};