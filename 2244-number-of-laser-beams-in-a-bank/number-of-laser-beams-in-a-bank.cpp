class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int prevDeviceCount=0;
        int res=0;
        for(int i=0;i<n;i++){
            int currDeviceCount=0;
            for(char &ch:bank[i]){
                if(ch=='1'){
                    currDeviceCount++;
                }
            }
            res+=(prevDeviceCount*currDeviceCount);
            if(currDeviceCount!=0){
                prevDeviceCount=currDeviceCount;
            }
        }
        return res;
    }
};