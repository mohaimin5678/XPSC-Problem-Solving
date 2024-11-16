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
        int mx,a,n;
        cin>>mx>>a>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        ll ans=0;
        ans+=(a-1);
        a=1;
        for(int i=0;i<n;i++){
            a+=v[i];
            a=min(mx,a);
            ans+=(a-1);
            a=1;
        }
        ans+=a;
        cout<<ans<<endl;
    }
    return 0;
}