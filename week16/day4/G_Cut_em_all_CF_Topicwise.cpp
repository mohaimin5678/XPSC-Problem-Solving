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
void mohaimin(){
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        g[i].clear();
        vis[i]=false;
    }
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