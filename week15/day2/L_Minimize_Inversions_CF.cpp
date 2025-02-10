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
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[a[i]]=b[i];
    }
    for(auto [x,y]:mp){
        cout<<x<<" ";
    }
    cout<<ln;
    for(auto [x,y]:mp){
        cout<<y<<" ";
    }
    cout<<ln;
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
if we can make one vector's inversion count 0 then the only second
vector will add count into the answer. which will be the minimum. 
so making one vector on ascending order will be enough & this is 
what we did. 
*/