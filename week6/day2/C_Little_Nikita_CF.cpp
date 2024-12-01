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
        int n,m;
        cin>>n>>m;
        if(n==m) cout<<"YES"<<endl;
        else if(n<m) cout<<"NO"<<endl;
        else if(n>m){
            if(n%2!=m%2) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    return 0;
}