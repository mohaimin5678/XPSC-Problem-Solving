#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
const int MOD=1e9+7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll ans=1;
        for(int i=1;i<=n;i++){
            ans=(1LL* ans%MOD * i%MOD)%MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}