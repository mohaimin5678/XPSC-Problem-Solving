#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
const int maxN=4002;
vector<int> g[maxN];
// vector<pair<int,int>> cnt(maxN);
int n;
string s;
vector<int> black(maxN+1);
vector<int> white(maxN+1);

void dfs(int u){
    if(s[u-1]=='W') white[u]++;
    else black[u]++;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        dfs(v);
        black[u]+=black[v];
        white[u]+=white[v];
    }
}
void mohaimin(){
    cin>>n;
    for(int i=0;i<=n;i++){
        g[i].clear();
        black[i]=0;
        white[i]=0;
    }
    for(int i=2;i<=n;i++){
        int u;
        cin>>u;
        g[u].push_back(i);
    }
    cin>>s;
    ll ans=0;
    dfs(1);
    for(int i=1;i<=n;i++){
        if(black[i]==white[i] && black[i]!=0) ans++;
    }
    cout<<ans<<ln;
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