class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> person;
        for(int i=0;i<names.size();i++){
            person.push_back({heights[i],names[i]});
        }
        sort(person.begin(),person.end(),[](pair<int,string>&a,pair<int,string>&b){
            return a.first>b.first;
        });
        vector<string> ans;
        for(auto &p:person){
            ans.push_back(p.second);
        }
        return ans;
    }
};