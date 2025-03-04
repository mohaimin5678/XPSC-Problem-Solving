#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    ll x,y,k;
    cin>>x>>y>>k;
    int first,second;
    if(x%k==0){
        first=x/k;
    }
    else first=(x/k)+1;

    if(y%k==0) second=y/k;
    else second=(y/k)+1;

    int mn=min(first,second);
    int mx=max(first,second);
    int ans=mx+mn+(mx-mn);
    if(first>second) ans--;
    cout<<ans<<ln;
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
}