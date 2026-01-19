class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int row=mat.size();
        int col=mat[0].size();
        vector<vector<int>> prefix(row, vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                prefix[i][j]=mat[i][j]+(i>0?prefix[i-1][j]:0)+(j>0?prefix[i][j-1]:0)-(i>0 && j>0 ? prefix[i-1][j-1]:0);
            }
        }
        auto sumSquare=[&](int r1,int c1, int r2, int c2){
            int sum=prefix[r2][c2];
            if(r1>0) sum-=prefix[r1-1][c2];
            if(c1>0) sum-=prefix[r2][c1-1];
            if(r1>0 && c1>0) sum+=prefix[r1-1][c1-1];
            return sum;
        };
        auto check=[&](int side){
            for(int i=0;i+side-1<row;i++){
                for(int j=0;j+side-1<col;j++){
                    if(sumSquare(i,j,i+side-1,j+side-1)<=threshold){
                        return true;
                    }
                }
            }
            return false;
        };
        int l=1,h=min(row,col);
        int res=0;
        while(l<=h){
            int m=l+(h-l)/2;
            if(check(m)){
                res=m;
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return res;
    }
};