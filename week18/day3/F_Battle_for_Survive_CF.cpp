#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    } 
    ll sum=0;
    for(ll i=0;i<n-2;i++){
        sum+=v[i];
    }
    v[n-2]-=sum;
    v[n-1]-=v[n-2];
    cout<<v[n-1]<<ln;
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
/*
target is to find maximum rating the last remaining fighter 
so we have to maximize the last index's value after the final
operation.
since nth value will be decrease based on it's previous value
we can sum all the value before that "previous value". 
then remove the sum from that previous value. 
then remove that previous value from last value & it will 
always provide us the maximum last index. why?
example with testcase:
5
3 2 4 5 4
 
last index's value=4
it's previous value=5
lets sum all values before the "previous value" 
3+2+4=9
now remove this sum from "previous value"
new previous value = 5-9 = -4
now lets remove this from last index's value
latest last index's value = 4-(-4) = 8 (ans). 
*/