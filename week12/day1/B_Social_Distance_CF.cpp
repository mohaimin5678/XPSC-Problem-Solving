#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void mohaimin(){
    int n;
    ll m;
    cin>>n>>m;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    if(n>m) cout<<"NO"<<endl;
    else{
        ll seats=0;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            seats++;
            if(i==n-1){
                seats+=v[i];
            }
            else seats+=max(v[i],v[i+1]);
        }
        if(seats<=m) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) mohaimin();
    return 0;
}