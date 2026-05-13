class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> vis;
        while(vis.find(n)==vis.end()){
            vis.insert(n);
            n=getnext(n);
            if(n==1){
                return true;
            }
        }
        return false;
    }
private:
    int getnext(int n){
        int res=0;
        while(n>0){
            int dig=n%10;
            res+=dig*dig;
            n=n/10;
        }
        return res;
    }
};