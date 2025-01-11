#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void mohaimin(){
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    auto check=[&](ll dis){
        ll cows=0;
        ll place=v[0];
        for(int i=0;i<n;i++){
            if(place<=v[i]){
                cows++;
                place=v[i]+dis;
            }
        }
        return cows>=k;
    };
    ll l=0,r=1e9,mid,ans;
    while(l<=r){
        mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    mohaimin();
    return 0;
}
/*
initially placed a cow in v[0] so the next place=v[0]+distance
when that place will get matched, we'll do place=v[i]+distance
repeatedly. So by binary searh we'll pass the distance, which 
distance successfully placed all cows will return true & then
we'll try to increase the distance & check if it still placed
all the cows. 
*/