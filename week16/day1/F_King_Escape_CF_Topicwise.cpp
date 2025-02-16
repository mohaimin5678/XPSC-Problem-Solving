#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
const int maxN=1005;
int n;
vector<pair<int,int>> d={{0,1},{0,-1},{-1,0},{1,0},{-1,-1},{1,1},{-1,1},{1,-1}};
bool vis[maxN][maxN];
bool valid(int i,int j){
    if(i<1 || i>n || j<1 || j>n){
        return false;
    }
    else return true;
}
void bfs(int si, int sj){
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj]=true;
    while(!q.empty()){
        pair<int,int> par=q.front();
        int a=par.first, b=par.second;
        q.pop();
        for(int i=0;i<8;i++){
            int ci=a+d[i].first;
            int cj=b+d[i].second;
            if(valid(ci,cj)==true && !vis[ci][cj]){
                vis[ci][cj]=true;
                q.push({ci,cj});
            }
        }
    }
}
void mohaimin(){
    cin>>n;
    int qx,qy,kx,ky,dx,dy;
    cin>>qx>>qy>>kx>>ky>>dx>>dy;
    memset(vis,false,sizeof(vis));
    for(int i=0;i<8;i++){
        int tx=d[i].first+qx;
        int ty=d[i].second+qy;
        while(valid(tx,ty)){
            vis[tx][ty]=true;
            tx+=d[i].first;
            ty+=d[i].second;
        }
    }
    bfs(kx,ky);
    if(vis[dx][dy]) cyes;
    else cno;
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