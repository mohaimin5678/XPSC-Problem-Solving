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
        int n;
        cin>>n;
        vector<ll> v(n);
        ll sum=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            sum+=v[i];
        }
        string s;
        cin>>s;
        int l=0,r=n-1;
        ll ans=0;
        while(l<r){
            if(s[l]=='L' && s[r]=='R'){
                ans+=sum;
                sum-=v[l];
                sum-=v[r];
                l++;
                r--;
            }
            else if(s[l]=='R' && s[r]=='R'){
                sum-=v[l];
                l++;
            }
            else if(s[l]=='L' && s[r]=='L'){
                sum-=v[r];
                r--;
            }
            else if(s[l]=='R' && s[r]=='L'){
                sum-=v[l];
                sum-=v[r];
                l++;
                r--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}