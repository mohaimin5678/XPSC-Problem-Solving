//https://codeforces.com/contest/1800
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n);
        multiset<ll> ml;
        for(ll i=0;i<n;i++){
            cin>>v[i];
        }
        ll sum=0;
        for(ll i=0;i<n;i++){
            if(v[i]!=0) ml.insert(v[i]);
            else{
                if(!ml.empty()){
                    auto it=ml.rbegin();
                    sum+=*it;
                    ml.erase(--it.base());
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}