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
    int t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;
        if(2*x>y) cout<<-1<<" "<<-1<<endl;
        else {
            // cout<<LCM(x,2*x)<<endl;
            cout<<x<<" "<<2*x<<endl;
        }
    }
    return 0;
}
/*
we need to keep the lcm(x,y) in between them.
so lets take x as a, then we must need b which should be <y & at the
same time their lcm should be in that range too. 
so if we take b=2*x then their lcm(x,2*x) will always be 2*x which is <y
But we have to keep in mind that 2*x>y can also happen. So if that 
occurs we can print that there is no answer. 
*/ 
