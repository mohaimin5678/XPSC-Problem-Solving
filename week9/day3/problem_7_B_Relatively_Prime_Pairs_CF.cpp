#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll l,r;
    cin>>l>>r;
    vector<ll> odd;
    vector<ll> even;
    for(ll i=l;i<=r;i++){
        if(i%2==0) even.push_back(i);
        else odd.push_back(i);
    }
    cout<<"YES"<<endl;
    ll n=(r-l+1)/2;
    for(ll i=0;i<n;i++){
        cout<<even[i]<<" "<<odd[i]<<endl;
    }
    return 0;
}