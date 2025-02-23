#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
const int maxN=1e5+5;
vector<int> adj[maxN];
vector<bool> vis(maxN);
vector<int> ans(maxN);
map<pair<int,int>,int> mp;
void dfs(int u,int val){
    vis[u]=true;
    for(auto x:adj[u]){
        if(!vis[x]){
            if(val==2){
                // cout<<val<<" ";
                ans[mp[{x,u}]]=val;
                dfs(x,val+1);
            }
            else{
                ans[mp[{x,u}]]=val;
                dfs(x,val-1);
            }
        }
    }
}
void mohaimin(){
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        adj[i].clear();
        vis[i]=false;
    }
    mp.clear();
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[{u,v}]=i;
        mp[{v,u}]=i;
    }
    for(int i=1;i<=n;i++){
        if(adj[i].size()>2){
            cout<<-1<<ln;
            return;
        }
    }
    for(int i=1;i<=n;i++){
        if(adj[i].size()==1){
            // cout<<i<<ln;
            dfs(i,2);
            break;
        }
    }
    for(int i=1;i<n;i++){
        cout<<ans[i]<<" ";
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
since amader only pashapashi connected 2ta edge er sum check korte 
hobe jate eder sum always prime thakte hobe. Since 2 & 3 prime 
also 2+3=5 so we'll put 2 & 3 on all edges based on parent & child
connection. 
We have to show the answers based on the given edges. So we need
to save those edge's serial too. Thats why beside adj list, visited
vector, we also take a map to save the edges. 
We'll look for a leaf node & start the dfs from it & pass 2 then,
when we get it's child we'll pass 3 for it. This is how we'll pass
2/3 serial wise. And that passing value will be on answer. 
How?
map inside main(), we'll put edge on the first & index on the 2nd
map inside dfs(), we'll find edge's corresponding index & put 2/3
in answer vector. 
after finishing the dfs, we'll simply print values for all edges. 
*/