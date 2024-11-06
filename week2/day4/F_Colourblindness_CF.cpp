//https://codeforces.com/contest/1722
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        string a,b;
        cin>>n>>a>>b;
        bool flag=true;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                if((a[i]=='G' && b[i]=='B') || (a[i]=='B' && b[i]=='G')) continue;
                else flag=false;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}