#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    int ans=-1;
    int i=1;
    while(c<=b){
        c*=i;
        if(a<=c && c<=b){
            ans=c;
            break;
        }
        i++;
    }
    cout<<ans<<'\n';
    return 0;
}