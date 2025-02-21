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
vector<ll> cnt(maxN);
void dfs(int v,int par){
    if(adj[v].size()==1 && adj[v][0]==par){
        cnt[v]=1;
        return;
    }
    for(auto x:adj[v]){
        if(x!=par){
            dfs(x,v);
            cnt[v]+=cnt[x];
        }
    }
}
void mohaimin(){
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        adj[i].clear();
        cnt[i]=0;
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        ll total=cnt[x]*cnt[y];
        cout<<total<<ln;
    }
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
since its going down to final leaf node & root is 1 so we can always
check for the child nodes then moves to child's child nodes & so on
until we finally reach the leaf node. And while reaching the leaf node,
we'll keep the count. Cause we are checking how many ways the apples
will fall. 
so we'll pre-calculate the counts from each node. Using the dfs we can
easily do that. We'll start from 1 since it is the root. And we'll
check if current node is leaf or not. If leaf, then that node's count
is 1 & we'll return from that (consider this as a base case). Else we
will go through node's children & count full subtree under it. All
these count will be saved in a vector. 
After saving the count, the queries will start. Each query will give
x,y vertex & from there we can check how many ways both will reach 
the leaf. SO we'll just multiply cnt[x] (the amount of nodes under x)
with cnt[y] (the amount of nodes under y) And that will be our answer. 
Cause these are the combinations we can make. 
*/
