#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n;
    cin>>n;
    // multiset<ll> ml;
    map<ll,int> mp;
    ll sum=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x]++;
        sum+=x;
        // ml.insert(x);
    }
    if(n==1){
        cyes;
        return;
    }
    // cout<<sum<<ln;
    // ll x=floorl((sum*1.0)/2);
    // ll y=ceill((sum*1.0)/2);
    // multiset<ll> make;
    priority_queue<ll> pq;
    pq.push(sum);
    // make.insert(sum);
    // make.insert(y);
    while(!pq.empty()){
        ll x=pq.top();
        pq.pop();
        ll a=floorl((x*1.0)/2);
        ll b=ceill((x*1.0)/2);
        if(mp[a]>0){
            mp[a]--;
        }
        else if(mp[a]==0 && a>1){
            pq.push(a);
        }

        if(mp[b]>0){
            mp[b]--;
        }
        else if(mp[b]==0 && b>1) pq.push(b);

        if(pq.size()>n) break;
    }
    for(auto [x,y]:mp){
        if(y!=0){
            cno;
            return;
        }
    }
    cyes;
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