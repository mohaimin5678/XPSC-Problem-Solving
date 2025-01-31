#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<ll> v(n+2);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        // v[i]=0;
    }
    vector<pair<pair<int,int>,ll>> store(m+2);
    for(int i=1;i<=m;i++){
        int l,r;
        ll d;
        cin>>l>>r>>d;
        // v[l]+=d;
        // v[r+1]-=d;
        store[i]={{l,r},d};
        // store.push_back({{l,r},d});
    }
    // for(int i=1;i<=n;i++){
    //     v[i]=v[i-1]+v[i];
    // }
    // for(int i=1;i<=n;i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<ln;
    vector<ll> s(m+2);
    while(k--){
        int x,y;
        cin>>x>>y;
        s[x]++;
        s[y+1]--;
    }
    for(int i=1;i<=m;i++){
        s[i]=s[i-1]+s[i];
    }
    for(int i=1;i<=m;i++){
        (store[i].second)*=s[i];
    }

    vector<ll> ans(n+2);
    for(int i=1;i<=m;i++){
        // v[i]=v[i-1]+v[i];
        // cout<<v[i]<<" ";
        ans[store[i].first.first]+=store[i].second;
        ans[store[i].first.second+1]-=store[i].second;
    }
    for(int i=1;i<ans.size();i++){
        ans[i]=ans[i-1]+ans[i];
    }

    for(int i=1;i<=n;i++){
        v[i]+=ans[i];
    }
    for(int i=1;i<=n;i++){
        cout<<v[i]<<" ";
    }
    cout<<ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    mohaimin();
    
}
/*
0 1  2  3  4
  1    -1
  1       -1
     1    -1
--------------
0 2  3  2 0        prefix sum

operations contribution
*/