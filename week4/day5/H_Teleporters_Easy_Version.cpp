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
        int n;
        cin>>n;
        ll lim;
        cin>>lim;
        vector<ll> v(n+1);
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(int i=1;i<=n;i++){
            cin>>v[i];
            pq.push(v[i]+i);
        }
        ll cnt=0;
        while(!pq.empty()){
            ll p=pq.top();
            pq.pop();
            
            if(lim>=p){
                cnt++;
                lim-=p;
            }
            else break;
        }
        
        cout<<cnt<<endl;
    }
    
    return 0;
}