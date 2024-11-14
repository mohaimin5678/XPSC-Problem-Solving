#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int l=0,r=0;
        int ans=INT_MAX,cnt=0;
        vector<int> v(2,0);
        while(r<n){
            if(s[r]=='B') v[0]++;
            else v[1]++;
            if(r-l+1==k){
                cnt+=v[1];
                ans=min(ans,cnt);
                if(s[l]=='B') v[0]--;
                else v[1]--;
                l++;
                r++;
                cnt=0;
            }
            else r++;
        }
        cout<<ans<<endl;
    }
    return 0;
}