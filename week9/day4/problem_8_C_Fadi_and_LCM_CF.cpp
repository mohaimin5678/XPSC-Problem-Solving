#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
ll LCM(ll a,ll b){
    return ((a/__gcd(a,b))*b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    set<pair<ll,ll>> s;
    for(ll i=1;i<=sqrt(n);i++){
        if(n%i==0){
            ll j=n/i;
            if(i<j) s.insert({i,j});
            else s.insert({j,i});
        }
    }
    ll l=LLONG_MAX,r=LLONG_MAX;
    for(auto p:s){
        ll x=p.first;
        ll y=p.second;
        if(y<r && LCM(x,y)==n){
            l=x;
            r=y;
        }
    }
    cout<<l<<" "<<r;
    return 0;
}
/*
first observation is the constraint that are given which is 10^12
means in 1 sec we can highest loop through 10^6 so answer is related
to sqrt(N). 

now they want max(a,b) to be minimum where it's lcm value is equal to N. 
since its about lcm, which is related to gcd also. Now gcd is based on
divisors. So it has to do something with the divisors. 

since here we'll be needed to make pairs, so we can save all the 
divisors. Or we can simply pair them in a vector. here set is saving
our memory spaces. Bcause it will only save unique pairs. 

after that we need to find the minimum of max(a,b). Now it doesn't
matter who is the max here because the function will return whoever
is the max. So let b is the max amoung these two for all the time & 
check if there is any smaller value of b exists & their lcm is equal 
to N.  If yes, then that will be the new pair. 
*/