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
    ll sum=0;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    if((2LL*sum)%n!=0){
        cout<<0<<ln;
        return;
    }
    ll target=(2LL*sum)/n;
    // cout<<target<<ln;
    map<ll,ll> mp;
    ll cnt=0;
    for(int i=0;i<n;i++){
        ll check=target-v[i];
        // cout<<check<<ln;
        cnt+=mp[check];
        mp[v[i]]++;
    }
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
/*
if k==sum/n;
then we look for the target=(2*sum)/n;
why? suppose: 
5
1 4 7 3 5
here sum=20 & k=(20/5)=4
so target is 2*k OR 8 (for some big values 2*k isn't working)
so we can set target=(2*20)/5=40/5=8 (and its working for all)
then we'll check if target-v[i] exists on map or not. 
if it is then count its frequency. 
*/