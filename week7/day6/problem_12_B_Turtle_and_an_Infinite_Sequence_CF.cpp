#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int turn_on_kth_bit(int n, int k) {
   return (n | (1 << k));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll f=n-m;
        ll s=n+m;
        if(f<0) f=0;
        // vector<ll> first(33,0),second(33,0);
        ll ans=0;
        for (int i = 31; i>=0; --i) {
            if ((f & (1LL << i)) || (s & (1LL << i)) || (f >> (i + 1)) != (s >> (i + 1))) {
                ans |= (1LL << i);
            }
        }
        // reverse(first.begin(),first.end());
        // reverse(second.begin(),second.end());
        
        // for(ll i=32;i>=0;i--){
        //     if(first[i]==1 && second[i]==1){
        //         ans|=(1LL<<i);
        //     }
        //     else if(first[i]==0 && second[i]==1){
        //         ans|=(1LL<<i);
        //     }
        //     else if(first[i]==1 && second[i]==0){
        //         ans|=(1LL<<i);
        //     }
        //     else{
        //         if(i<32 && ((first[i+1]==1 && second[i+1]==0)||(first[i+1]==0 && second[i+1]==1))){
        //             ans|=(1LL<<i);
        //         }
        //     }
        // }
        cout<<ans<<endl;
    }
    return 0;
}
/*
n-m
n+m 
1
1
thake answer e contribution 1
1
0
thake answer e contribution 1
0
1
thake answer e contribution 1
0
0
thakle shamner (msb) er dike konotay 1,0/0,1 thakle contribution 1


n-m jodi negative hoy tahole start korbo 0 theke
*/