#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
ll GCD(ll a,ll b) {
   return __gcd(a, b); 
}
ll LCM(ll a,ll b) {
   return (a/__gcd(a, b))*b;
}
void mohaimin(){
    ll n; cin>>n;
    vector<ll> v(n);
    map<ll,ll> mp;
    for(ll i=0; i<n; i++){
        cin>>v[i];
        mp[v[i]]++;
    }
    sort(v.begin(),v.end());
    if(n==1){
        cout<<1<<ln;
        return;
    }
    vector<ll> g;
    for(ll i=0; i<n-1; i++){
        g.push_back(abs(v[i]-v[i+1]));
    }
    ll x=g[0];
    for(ll i=1; i<g.size(); i++){
        x=GCD(x,g[i]);
    }
    ll op=0;
    bool check = false;
    for(ll i=0; i<n-1; i++){
            ll p = abs(v[n-1]-v[i]);
            if(p%x){
                check = true;
                break;
            }
            op+=(p/x);
    }
    if(check){
        ll op1=0;
        for(ll i=0; i<n; i++){
            op1+=abs(v[n-1]-v[i]);
        }
        ll k=0;
        ll s=v[n-1];
        bool flag = false;
        while(k<v.size()-1){
            s-=1;
            if(mp.find(s)==mp.end()){
                flag = true;
                break;
            }
            k++;
            if(k>v.size()-1){
                break;
            }
        }
 
        if(flag){
            op1+=v[n-1]-s;
            cout<<op1<<ln;
        }
        else{
            cout<<op1+v.size()<<ln;
        }
    }
    else{
        ll k=0;
        ll s=v[n-1];
        bool flag = false;
        while(k<v.size()-1){
            s-=x;
            if(mp.find(s)==mp.end()){
                flag = true;
                break;
            }
            k++;
            if(k>v.size()-1){
                break;
            }
        }
        if(flag){
            ll p = v[n-1]-s;
            op+=(p/x);
            cout<<op<<ln;
        }
        else{
            op+=v.size();
            cout<<op<<ln;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; 
    cin>>t;
    while(t--){
        mohaimin();
    }
}