class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        long long sum=0;
        int negcnt=0;
        int absum=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=abs(matrix[i][j]);
                if(matrix[i][j]<0) negcnt++;
                absum=min(absum,abs(matrix[i][j]));
            }
        }
        if(negcnt%2==0){
            return sum;
        }
        return sum-2*absum;
    }
};