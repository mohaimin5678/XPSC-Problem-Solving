#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void mohaimin(){
    int n;
    ll k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    auto check=[&](ll height){
        ll cnt=0;
        for(int i=0;i<n;i++){
            if(v[i]<height) cnt+=(height-v[i]);
        }
        return cnt<=k;
    };
    ll l=1,r=2e9,mid,ans;
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
    int t;
    cin>>t;
    while(t--){
        mohaimin();
    }
    return 0;
}
/*
sorted the array & according to height just added height-v[i]
to cnt & checked if its <=k or not. 

l=1 but if they provide v[i]=10^9 & also want k=10^9 then we have
to go till 2*10^9 height to check 
*/