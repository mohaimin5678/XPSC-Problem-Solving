#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b;
    cin>>a>>b;
    int ans=0;
    int turn=2;
    while(turn--){
        int mx=max(a,b);
        ans+=mx;
        if(mx==a) a--;
        else b--;
    }
    cout<<ans<<'\n';
    return 0;
}