class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& v, int k) {
        int n = v.size();
        long long int sum = 0; 
        int ans = 0;
        map<long long, int> mp;

        int r=0;
        while(r<n){
            sum+=v[r];
            if(sum==k) {
                ans=max(ans,r+1);
            }
            if (mp.find(sum-k)!=mp.end()) {
                ans = max(ans,r-mp[sum-k]);
            }
            if (mp.find(sum)==mp.end()) {
                mp[sum]=r;
            }
            r++;
        }
        return ans;
    }
};