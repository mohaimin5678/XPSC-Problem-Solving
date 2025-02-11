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
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    map<int,ll> mp;
    ll cnt=0;
    for(int i=0;i<n;i++){
        cnt+=mp[v[i]-i];
        mp[v[i]-i]++;
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
they want us to check V[j]-V[i]== j-i
                now:  V[j]-j   == V[i]-i
so lets count V[i]-i for each turn & update that. Now we can
solve this in O(N) complexity. 
*/