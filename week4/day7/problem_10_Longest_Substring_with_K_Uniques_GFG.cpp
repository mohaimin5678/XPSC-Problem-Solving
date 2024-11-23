class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n=s.size();
        map<char,int> mp;
        int ans=-1;
        int l=0,r=0;
        while(r<n){
            mp[s[r]]++;
            if(mp.size()==k){
                ans=max(ans,r-l+1);
            }
            else{
                while(mp.size()>k && l<=r){
                    mp[s[l]]--;
                    if(mp[s[l]]==0){
                        mp.erase(s[l]);
                    }
                    l++;
                }
            }
            r++;
        }
        return ans;
    }
};