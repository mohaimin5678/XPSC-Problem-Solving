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
        int n,k,q;
        cin>>n>>k>>q;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(x<=q) v[i]=1;
            else v[i]=0;
        }
        
        ll ans=0,cnt=0;
        for(int i=0;i<n;i++){
            if(v[i]==1){
                cnt++;
            }
            else{
                if(cnt>=k){
                    int val=(cnt-k+1);
                    ll total=(val*(val+1LL))/2LL;
                    ans+=total;
                }
                cnt=0;
            }
        }
        if(cnt>=k){
            int val=(cnt-k+1);
            ll total=(val*(val+1LL))/2LL;
            ans+=total;
        }
        cout<<ans<<endl;
    }
    return 0;
}