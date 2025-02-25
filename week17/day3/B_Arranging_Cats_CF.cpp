#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n;
    string s,f;
    cin>>n>>s>>f;
    int x=0,y=0;
    for(int i=0;i<n;i++){
        if(s[i]==f[i]) continue;
        else if(s[i]=='1') x++;
        else if(f[i]=='1') y++;
    }
    cout<<max(x,y)<<ln;
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