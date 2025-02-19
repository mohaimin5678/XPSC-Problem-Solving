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
vector<int> cnt(maxN);      //subtree counting
int ans=0;
void dfs(int u,int par){
    cnt[u]=1;
    for(auto v:g[u]){
        if(v==par) continue;    //parent checking
        dfs(v,u);
        if(cnt[v]%2==0){    //if the subtree is already even then
            ans++;          //it'll contribute in the ans
            cnt[v]=0;    //then separate the subtree by making it 0
        }
        cnt[u]+=cnt[v]; //count the total existing node under itself
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
    if(n%2==1){
        cout<<-1<<ln;
        return;
    }
    if(n==2){
        cout<<0<<ln;
        return;
    }
    dfs(1,-1);  //suppose 1 is root so it has no parent
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
since they want to seperate subtrees where they can stay with even
nodes. We can start from 1(lets think this is a root) & it has no
parent so -1. 

inside dfs:- 
we'll count u first & make u's nodes=1
then we'll traverse it's children & for each child we'll call dfs
with child & the parent. 
when it will done it's operation it will comeback with it's own
node count. then if the count is even then make the count=0 &
contribute in the answer Else leave it as it is. 
then add the child's node count with it's parent's node count. 

this is how the whole dfs will go through & when all node are done
it'll automatically return as its a void function. And print the ans. 
*/
