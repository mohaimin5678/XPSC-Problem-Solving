#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,m;
    cin>>n>>m;
    map<int,set<int>> g;    //easily find korar jonno adjacency list
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].insert(v);
        g[v].insert(u);
    }
    int leaf=-1,parent1=-1;
    for(int i=1;i<=n;i++){
        if(g[i].size()==1){
            leaf=i;
            break;
        }
    }
    // for(auto [x,y]:g){
    //     cout<<x<<" -> ";
    //     for(auto val:y){
    //         cout<<val<<" ";
    //     }
    //     cout<<ln;
    // }
    int x,y;
    //finding leaf node's parent, so we're searching which node has
    //the leaf node into it's adjacency list. When we got leaf's
    //parent then calculated Y & saved the parent.
    for(int i=1;i<=n;i++){
        if(g[i].find(leaf)!=g[i].end()){
            y=g[i].size()-1;
            parent1=i;
            break;
        }
    }
    //then we're searching parent node's parent so we're searching 
    //the same way we did for leaf node but there is one more condition.
    //Since the parent node can also be on it's leaf node's adjacency
    //list so we need to avoid all 1 size adjacency list. When we 
    //got parent's parent then we calculated X.
    for(int i=1;i<=n;i++){
        if(g[i].find(parent1)!=g[i].end() && g[i].size()>1){
            x=g[i].size();
            break;
        }
    }
    cout<<x<<" "<<y<<ln;
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
we need to select a leaf node & find it's parent node p1. That p1's 
adjacency list's size-1 is Y. 
Now we need to find the parent node of p1 which is p2. Now p2's
adjacency list's size is X. 
*/