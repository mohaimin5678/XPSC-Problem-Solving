#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
ll findMEX(vector<ll>& arr) {
    set<ll> elements(arr.begin(), arr.end());
    ll mex = 0;
    while (elements.count(mex)) {
        mex++;
    }
    return mex;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> v(n);
        for(ll i=0;i<n;i++) cin>>v[i];
        ll mex=findMEX(v);
        v.push_back(mex);
        n=v.size();
        ll lim=k%n;
        for(ll i=(n-lim);i<n;i++){
            cout<<v[i]<<" ";
        }
        for(ll i=0;i<(n-lim-1);i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
lets pushback the whole array's mex value at the end.
then we have to find out from where to start the printing
& where to end it. 
for testcase: 
5 5
1 2 3 4 5
mex=0
so new array=1 2 3 4 5 0
             0 1 2 3 4 5 -->idx
now n=6 & k=5
lim=k%n==5%6=5
for(ll i=(n-lim);i<n;i++){
    cout<<v[i]<<" ";
}
i=6-5=1 & so from 1 to <6 array=[2 3 4 5 0]

again for testcase: 
3 1
0 1 3
mex=2
so new array= 0 1 3 2
              0 1 2 3 --> idx
now n=4 & k=1
so lim=k%n==1%4==1
for(ll i=(n-lim);i<n;i++){
    cout<<v[i]<<" ";
}
i=4-1=3 & so from 3 to <4 array=[2 ]
for(ll i=0;i<(n-lim-1);i++){
    cout<<v[i]<<" ";
}
i=0, so from 0 to <(4-1-1)== <2 so array=[2 0 1]

*/
