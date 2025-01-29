#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,k;
    cin>>n>>k;
    vector<vector<char>> v(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    int x=n/k;
    vector<vector<char>> ans(x,vector<char>(x));
    for(int i=0;i<n;i+=k){
        for(int j=0;j<n;j+=k){
            ans[i/k][j/k]=v[i][j];
        }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            cout<<ans[i][j];
        }
        cout<<ln;
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