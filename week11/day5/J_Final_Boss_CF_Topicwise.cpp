#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void mohaimin(){
    int h,n;
    cin>>h>>n;
    vector<ll> a(n),c(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>c[i];

    auto check=[&](ll turns){
        ll dam=0;
        for(int i=0;i<n && dam<h;i++){
            ll cnt=(turns-1)/c[i];
            cnt++;
            if(cnt>=h) return true;
            dam+=(cnt*a[i]);
        }
        
        return dam>=h;
    };

    ll l=1,r=4e10,mid,ans;
    while(l<=r){
        mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        mohaimin();
    }
    return 0;
}