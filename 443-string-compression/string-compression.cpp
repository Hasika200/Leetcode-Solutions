class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int idx=0;
        int i=0;
        while(i<n){
            int cnt=0;
            int curr_char=chars[i];
            while(i<n && chars[i]==curr_char){
                cnt++;
                i++;
            }
            chars[idx]=curr_char;
            idx++;
            if(cnt>1){
                string cnt_str=to_string(cnt);
                for(char &ch:cnt_str){
                    chars[idx]=ch;
                    idx++;
                }
            }
        }
        return idx;
    }
};