#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin>>n>>k;
    vector<ll> divisors;
    for(ll i=1;i<=sqrt(n);i++){      //O(sqrt(N))
        if(n%i==0){
            divisors.push_back(i);
            if(n/i!=i) divisors.push_back(n/i);
        }
    }
    sort(divisors.begin(),divisors.end());
    if(divisors.size()<k) cout<<-1<<endl;
    else cout<<divisors[k-1]<<endl;
    return 0;
}