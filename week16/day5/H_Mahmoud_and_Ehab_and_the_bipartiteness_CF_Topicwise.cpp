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
/*
since we need to make 2 sets of nodes where none of the node from
same set needs to get connected. Only nodes from different set needs
to get connected. So we'll take the adjacency list, visited track
& a 2 size vector to make set 1, set 2. 
We'll take input & then call the dfs on 1. 
the parameters are (child, parent, set number). 
so for 1, we are sending dfs(1,0,0) as child=1,parent=0 & set=0
so set0=[1 ] set1=[ ]
then making it true & checking for 1's child which is 2. 

so for 2, we are sending dfs(2,1,1) as child=2,parent=1 & set=1
so set0=[1 ] set1=[2 ]
then making it true & checking for 2's child which is 3.

so for 3, we are sending dfs(3,2,0) as child=3,parent=2 & set=0
so set0=[1 3] set1=[2 ]
then making it true & checking for 3's child which is 4.

so for 4, we are sending dfs(4,3,1) as child=4,parent=3 & set=1
so set0=[1 3] set1=[2 4]
then making it true & checking for 4's child which is 5.

so for 5, we are sending dfs(5,4,0) as child=5,parent=4 & set=0
so set0=[1 3 5] set1=[2 4]
then making it true & checking for 5's child but since there is no
child/node left, so this is where the dfs is finished. 

now total edges can be possible is set0 size * set1 size=3*2=6
we already have 5-1=4 edges so needed edges are=6-4=2 (final answer)
*/
