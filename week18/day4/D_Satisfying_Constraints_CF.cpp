#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n;
    cin>>n;
    map<int,int> mp;
    int mx=INT_MAX,mn=INT_MIN;
    while(n--){
        int x,y;
        cin>>x>>y;
        if(x==1){
            mn=max(mn,y);
        }
        else if(x==2){
            mx=min(mx,y);
        }
        else mp[y]++;
    }
    ll cnt=mx-mn+1;
    int range=0;
    for(auto [a,b]:mp){
        if(mn<=a && a<=mx) range++;
    }
    if(cnt<=range) cnt=0;
    else cnt-=range;
    cout<<cnt<<ln;
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