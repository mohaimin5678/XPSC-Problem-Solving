#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    ll ans=LLONG_MAX,sum=0;
    ll l=0,r=0;
    while(r<n){
        sum+=v[r];
        while(sum>=k){
            // cout<<sum<<" ";
            ans=min(ans,r-l+1);
            sum-=v[l];
            l++;
        }
        r++;
    }
    // cout<<endl;
    if(ans==LLONG_MAX) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}