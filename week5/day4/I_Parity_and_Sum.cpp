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
        ll n;
        cin>>n;
        vector<ll> v(n);
        ll even=0,odd=0;
        ll maxOdd=LLONG_MIN;
        for(ll i=0;i<n;i++){
            cin>>v[i];
            if(v[i]%2==0) even++;
            else{
                odd++;
                maxOdd=max(maxOdd,v[i]);
            }
        }
        if(even==n || odd==n) cout<<0<<endl;
        else{
            vector<int> e;
            for(ll i=0;i<n;i++){
                if(v[i]%2==0) e.push_back(v[i]);
            }
            ll cnt=e.size();
            sort(e.begin(),e.end());
            for(ll x:e){
                if(x<maxOdd){
                    maxOdd+=x;
                }
                else{
                    cnt++;
                    break;
                }
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}