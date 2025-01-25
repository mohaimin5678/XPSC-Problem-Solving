#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    ll a,b;
    cin>>a>>b;
    while(__gcd(a,b)>1){
        b/=__gcd(a,b);
    }
    if(b>1) cno;
    else cyes;
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
all prime count kore rakha possible na since constraint is 10^18
so gcd ber kore kore b/=gcd(a,b) korte korte check korbo
cause always amader gcd(a,b) eta dibe greatest common divisors. 
so oita diye b re divide kore kore b er value decrease korte thakbo
jokhon dekhbo gcd(a,b)==1 ashtese tokhon loop break korbo cause
tokhon b er value te kono change ashbe na. 
b>1 thakle b er aro divisors baki jegula a te nai so NO. 
else b er shob divisors a te ache so YES. 
*/