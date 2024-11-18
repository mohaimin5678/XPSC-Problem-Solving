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
    ll ans=0,sum=0;
    ll l=0,r=0;
    while(r<n){
        sum+=v[r];
        if(sum<=k){
            ans=max(ans,r-l+1);
        }
        else{
            sum-=v[l];
            l++;
        }
        r++;
    }
    cout<<ans<<endl;
    return 0;
}