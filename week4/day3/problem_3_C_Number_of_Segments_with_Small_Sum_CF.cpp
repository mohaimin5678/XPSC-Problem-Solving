#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll k;
    cin>>k;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    ll l=0,r=0,sum=0,ans=0;
    while(r<n){
        sum+=v[r];
        if(sum<=k){
            ans+=(r-l+1);
        }
        else{
            while(sum>k){
                sum-=v[l];
                l++;
            }
            if(sum<=k){
                ans+=(r-l+1);
            }
        }
        r++;
    }
    cout<<ans<<endl;
    return 0;
}