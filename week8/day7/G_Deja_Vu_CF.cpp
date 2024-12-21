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
        vector<ll> v(n),p(m);
        for(int i=0;i<n;i++) cin>>v[i];
        for(int i=0;i<m;i++) cin>>p[i];
        map<ll,bool> mp;
        for(int i=0;i<m;i++){
            ll x=(1LL<<p[i]);
            if(mp[x]==true) continue;
            mp[x]=true;
            for(int j=0;j<n;j++){
                if(v[j]%x==0){
                    v[j]+=(1LL<<(p[i]-1));
                }
            }
        }
        for(int x:v) cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
/*
suppose we have done v[i]%2^2==0 so we'll do v[i]+=2^1
after that this modified value won't get divisible by 2^2 again. 
so to avoid the repeating same power value, if we already found
a specific power value, we'll add it to the map. this will reduce
our inner loop operation from 10^5 to almost 30!
*/