#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a,b,c;
        cin>>a>>b>>c;
        int ok=0;
        for(int i=0;i<n;i++){
            if(c[i]!=a[i] && c[i]!=b[i]) ok++;
        }
        if(ok==0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}