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
    ll n,a,b,p,q;
    cin>>n>>a>>b>>p>>q;
    
    ll red=n/a;
    ll blue=n/b;
    ll combined=n/LCM(a,b);

    red-=combined;
    blue-=combined;

    ll ans=(red*p)+(blue*q);

    ll mx=max(p,q);
    ans+=(combined*mx);

    cout<<ans<<endl;
    return 0;
}
/*
numbers are divisible by a in the range from 1 to N is:(N/a); //red
numbers are divisible by b in the range from 1 to N is:(N/b); //blue
but to find the numbers are divisible by both a & b,
first we need to find the lcm(a,b). now if we do N/lcm(a,b)
we'll find the numbers that are divisible by both a & b. //common
now we have to remove this common from red & blue.
then intially we'll calculate red*p + blue*q
then to maximize the answer we'll check who is the maximum 
between p & q. then that mx will be multiply with common value 
and then added to the answer. 

*/