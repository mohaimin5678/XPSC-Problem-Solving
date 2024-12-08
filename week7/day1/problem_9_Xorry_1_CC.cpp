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
        ll n;
        cin>>n;
        
        // for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        // cout<<endl;
        ll x=0;
        for(ll i=32;i>=0;i--){
            if((n>>i)&1){
                x=(1<<i);
                break;
            }
        }
        ll y=n-x;
        if(x<y) cout<<x<<" "<<y<<endl;
        else cout<<y<<" "<<x<<endl;
    }
    return 0;
}
/*
initially we are taking LSB to MSB loop
now we are getting v = 0 1 1
for x = 0 1 0
for y = 0 0 1
*/