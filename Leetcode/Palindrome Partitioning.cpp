class Solution {
public:
    bool palindrome(string s,int start,int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;end--;
        }
        return true;
    }
    void partition(int idx,vector<vector<string>>&ans,vector<string>&ds,string &s){
        if(idx==s.length()){
            ans.push_back(ds);
            return;
        }
        for(int i=idx;i<s.length();i++){
            if(palindrome(s,idx,i)){
                ds.push_back(s.substr(idx,i-idx+1));
                partition(i+1,ans,ds,s);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        partition(0,ans,ds,s);
        return ans;
    }
};
