#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll k;
    cin>>n>>k;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    map<ll,ll> mp;
    
    ll sum=0;
    mp[0]=1;
    ll ans=0;
    int r=0;
    while(r<n){
        sum+=v[r];
        // cout<<sum<<" -->";
        
        ans+=mp[sum-k];
        // cout<<sum-k<<" ";
        
        // cout<<endl;
        mp[sum]++;
        r++;
    }
    cout<<ans<<endl;
    return 0;
}