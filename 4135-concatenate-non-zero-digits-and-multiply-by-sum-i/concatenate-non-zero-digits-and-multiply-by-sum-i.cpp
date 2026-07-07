class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long prod=1;
        long long x=0;
        while(n>0){
            int dig=n%10;
            if(dig!=0){
                x=dig*prod+x;
                prod*=10; 
                sum+=dig;    
            }
            n=n/10;
        }
        return x*sum;
    }
};