#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b;
    cin>>a>>b;
    if(a>b){
        cout<<0<<'\n';
    }
    else{
        int ans=0;
        for(int i=a;i<=b;i++){
            ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}