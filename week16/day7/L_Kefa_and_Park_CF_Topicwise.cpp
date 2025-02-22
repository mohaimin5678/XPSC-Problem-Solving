#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
const int maxN=2e5+5;
vector<int> adj[maxN];
vector<int> v(maxN);
// vector<ll> cnt(maxN);
int lim,ans;
void dfs(int u,int par,int cnt){
    if(v[u]==1){
        cnt++;
        if(cnt>lim) return;
    }
    else cnt=0;

    if(adj[u].size()==1 && adj[u][0]==par){
        if(cnt>lim) return;
        else{
            ans++;
            return;
        }
    }
    for(auto x:adj[u]){
        if(x!=par){
            dfs(x,u,cnt);
        }
    }
}
void mohaimin(){
    int n;
    cin>>n>>lim;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans=0;
    dfs(1,0,0);
    cout<<ans<<ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    t=1;
    while(t--){
        mohaimin();
    }
}
/*
here we checked the consecutive count of cat's existence for each
path from 1(since it is the root). 
if we find any consecutive count greater than limitation then direct
return or else we'll go further.
once we reach the leaf we'll check if the count is > limitation or
not. if it is then no contribution to the answer or else ans++. 
then after finishing the dfs just print the answer. 
*/