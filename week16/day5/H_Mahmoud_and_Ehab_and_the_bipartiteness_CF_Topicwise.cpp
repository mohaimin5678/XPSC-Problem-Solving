#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
const int maxN=1e5+5;
vector<int> g[maxN];
vector<bool> vis(maxN);
vector<ll> sets(2);
void dfs(int u,int v,int mark){
    vis[u]=true;
    sets[mark]++;
    for(auto x:g[u]){
        if(!vis[x]){
            dfs(x,u,!mark);
        }
    }
}
void mohaimin(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0,0);
    ll total =sets[0]*sets[1];
    total-=(n-1);
    cout<<total<<ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    // cin>>t;
    t=1;
    while(t--){
        mohaimin();
    }
}